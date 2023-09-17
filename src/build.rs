/*
    cc7800 - a subset of C compiler for the Atari 7800
    Copyright (C) 2023 Bruno STEUX 

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    Contact info: bruno.steux@gmail.com
*/

use std::io::Write;
use log::debug;
use std::collections::{HashSet, HashMap};

use cc6502::error::Error;
use cc6502::compile::*;
use cc6502::assemble::AssemblyCode;
use cc6502::generate::*;
use cc6502::Args;

struct MemoryMap<'a> {
    bank: u32,
    set: HashSet<&'a String>,
    remaining_functions: u32,
    remaining_scattered: u32,
    remaining_variables: u32,
    startup_code: bool,
}

impl<'a> MemoryMap<'a> {
    fn new(compiler_state: &'a CompilerState, bank: u32) -> MemoryMap<'a> {
        let mut remaining_functions = 0;
        for f in compiler_state.sorted_functions().iter() {
            if f.1.bank == bank && f.1.code.is_some() && !f.1.inline {
                remaining_functions += 1;
            }
        }
        let mut remaining_scattered = 0;
        let mut remaining_variables = 0;
        for v in compiler_state.sorted_variables().iter() {
            debug!("Variable: {}, {:?}", v.0, v.1.memory);
            if let VariableMemory::ROM(b) = v.1.memory {
                if b == bank {
                    if let Some(_) = v.1.scattered {
                        remaining_scattered += 1;
                    } else {
                        remaining_variables += 1;
                    }
                }
            }
        }

        debug!("Remaining: {}, {}, {}", remaining_variables, remaining_functions, remaining_scattered);
        MemoryMap {
            bank,
            set: HashSet::new(),
            remaining_functions,
            remaining_scattered,
            remaining_variables,
            startup_code: false,
        }
    }

    fn fill_memory(&mut self, org: u32, rorg: u32, size: u32, compiler_state: &'a CompilerState, gstate: &mut GeneratorState, args: &Args, allow_scattered: bool, v: bool) -> Result<(), Error> {
        
        if args.verbose && v && (self.remaining_functions > 0 || self.remaining_scattered > 0 || self.remaining_variables > 0) {
            println!("Bank #{}: Filling memory at ${:04x} (RORG=${:04x})", self.bank, org, rorg);
        }

        // Is there any scattered memory remaining ?
        if allow_scattered && self.remaining_scattered > 0 {
            // Yes. So let's try to fit some.
            // Are we in a zone where 16 lines of scattered data can be stored ?
            if size >= 0x1000 {
                let holeydma_enabled_zone = rorg > 0x8000 && rorg & 0x1fff == 0;
                
                // Yes. Let's see if there is any remaining 16 lines scattered data to be stored
                let mut scattered_16 = false; 
                for v in compiler_state.sorted_variables().iter() {
                    if let VariableMemory::ROM(b) = v.1.memory {
                        if b == self.bank {
                            if let Some((l, _)) = v.1.scattered {
                                if l == 16 {
                                    if !self.set.contains(v.0) {
                                        // OK. We have found a 16 lines scattered data zone that was not
                                        // allocated to any zone.
                                        // Is it a holey DMA one ?
                                        if holeydma_enabled_zone || !v.1.holeydma {
                                            // In holdeydma enabled zone, it's OK to put anything
                                            scattered_16 = true;
                                            break;
                                        } // In non enabled zone, there should be at least one non holeydma scattered data
                                    }
                                }
                            }
                        }
                    }
                }
                if scattered_16 {
                    // Great. Let's fill this 4Kb of memory with 16 lines scattered data
                    let mut sv = Vec::<(String, u32)>::new();
                    let mut fill = 0;
        
                    // Let's select all the variables that will fit into this scattered data
                    if holeydma_enabled_zone {
                        // First pass to select in priority the ones that require holey DMA
                        for v in compiler_state.sorted_variables().iter() {
                            if let VariableMemory::ROM(b) = v.1.memory {
                                if b == self.bank {
                                    if let Some((l, _)) = v.1.scattered {
                                        if l == 16 {
                                            if !self.set.contains(v.0) && v.1.holeydma {
                                                // OK. We have found a 16 lines scattered data zone that was not
                                                // allocated to any zone. Let's set if it can fit into this area
                                                if let VariableDefinition::Array(a) = &v.1.def {
                                                    let width = a.len() as u32 / 16;
                                                    if fill + width <= 256 {
                                                        fill += width;
                                                        sv.push((v.0.clone(), width));
                                                        self.set.insert(v.0);
                                                        self.remaining_scattered -= 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    for v in compiler_state.sorted_variables().iter() {
                        if let VariableMemory::ROM(b) = v.1.memory {
                            if b == self.bank {
                                if let Some((l, _)) = v.1.scattered {
                                    if l == 16 {
                                        if !self.set.contains(v.0) && !v.1.holeydma {
                                            // OK. We have found a 16 lines scattered data zone that was not
                                            // allocated to any zone. Let's set if it can fit into this area
                                            if let VariableDefinition::Array(a) = &v.1.def {
                                                let width = a.len() as u32 / 16;
                                                if fill + width <= 256 {
                                                    fill += width;
                                                    sv.push((v.0.clone(), width));
                                                    self.set.insert(v.0);
                                                    self.remaining_scattered -= 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    if fill > 0 {
                        // Write the effective scattered data
                        if args.verbose {
                            println!("Bank #{} : Putting 16 lines scattered data at ${:04x}{}. Zone filling is {}/256", self.bank, rorg, if holeydma_enabled_zone {" (Holey DMA)"} else {""}, fill);
                        }
                        gstate.write("\n; Scattered data\n\tSEG SCATTERED")?;
                        gstate.write(&format!("\n\n\tORG ${:04x}\n\tRORG ${:04x}", org, rorg))?;
                        let mut counter;
                        for i in &sv {
                            gstate.write(&format!("\n{}", i.0))?;
                            if args.verbose {
                                println!(" - {}", i.0);
                            }
                            counter = 0;
                            let v = compiler_state.variables.get(&i.0).unwrap();
                            if let Some((_, w)) = v.scattered {
                                if let VariableDefinition::Array(a) = &v.def {
                                    for j in 0..i.1 {
                                        let xx = if v.reversed {
                                            &a[((j % w) + 15 * w + (j / w) * 16) as usize]
                                        } else {
                                            &a[((j % w) + (j / w) * 16) as usize]
                                        };
                                        if let VariableValue::Int(x) = xx {
                                            if counter == 0 {
                                                gstate.write("\n\thex ")?;
                                            }
                                            counter += 1;
                                            if counter == 16 { counter = 0; }
                                            gstate.write(&format!("{:02x}", x & 0xff))?;
                                        }
                                    }
                                }
                            }
                        }
                        for l in 1..16 {
                            gstate.write(&format!("\n\n\tORG ${:04x}\n\tRORG ${:04x}", org + 256 * l, rorg + 256 * l))?;
                            let mut counter = 0;
                            for i in &sv {
                                let v = compiler_state.variables.get(&i.0).unwrap();
                                if let Some((_, w)) = v.scattered {
                                    if let VariableDefinition::Array(a) = &v.def {
                                        for j in 0..i.1 {
                                            let xx = if v.reversed {
                                                &a[((j % w) + (15 - l) * w + (j / w) * 16) as usize]
                                            } else {
                                                &a[((j % w) + l * w + (j / w) * 16) as usize]
                                            };
                                            if let VariableValue::Int(x) = xx {
                                                if counter == 0 {
                                                    gstate.write("\n\thex ")?;
                                                }
                                                counter += 1;
                                                if counter == 16 { counter = 0; }
                                                gstate.write(&format!("{:02x}", x & 0xff))?;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        gstate.write("\n")?;
                    }

                    // Go on with filling the memory
                    return self.fill_memory(org + 0x1000, rorg + 0x1000, size - 0x1000, compiler_state, gstate, args, true, true); 
                }
            }
            
            // Are we in a zone where 8 lines of scattered data can be stored ?
            if size >= 0x800 {
                let holeydma_enabled_zone = rorg > 0x8000 && rorg & 0xfff == 0;
                
                // Yes. Let's see if there is any remaining 8 lines scattered data to be stored
                let mut scattered_8 = false;
                for v in compiler_state.sorted_variables().iter() {
                    if let VariableMemory::ROM(b) = v.1.memory {
                        if b == self.bank {
                            if let Some((l, _)) = v.1.scattered {
                                if l == 8 {
                                    if !self.set.contains(v.0) {
                                        // OK. We have found a 8 lines scattered data zone that was not
                                        // allocated to any zone. Let's create a new 8 lines scattered data zone
                                        if holeydma_enabled_zone || !v.1.holeydma {
                                            scattered_8 = true;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if scattered_8 {
                    // Great. Let's fill this 4Kb of memory with 8 lines scattered data
        
                    // Let's select all the variables that will fit into this scattered data
                    let mut sv = Vec::<(String, u32)>::new();
                    let mut fill = 0;
                    
                    // Let's select all the variables that will fit into this scattered data
                    if holeydma_enabled_zone {
                        // First pass to select in priority the ones that require holey DMA
                        for v in compiler_state.sorted_variables().iter() {
                            if let VariableMemory::ROM(b) = v.1.memory {
                                if b == self.bank {
                                    if let Some((l, _)) = v.1.scattered {
                                        if l == 8 {
                                            if !self.set.contains(v.0) && v.1.holeydma {
                                                // OK. We have found a 8 lines scattered data zone that was not
                                                // allocated to any zone. Let's set if it can fit into this area
                                                if let VariableDefinition::Array(a) = &v.1.def {
                                                    let width = a.len() as u32 / 8;
                                                    if fill + width <= 256 {
                                                        fill += width;
                                                        sv.push((v.0.clone(), width));
                                                        self.set.insert(v.0);
                                                        self.remaining_scattered -= 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    for v in compiler_state.sorted_variables().iter() {
                        if let VariableMemory::ROM(b) = v.1.memory {
                            if b == self.bank {
                                if let Some((l, _)) = v.1.scattered {
                                    if l == 8 {
                                        if !self.set.contains(v.0) && !v.1.holeydma {
                                            // OK. We have found a 8 lines scattered data zone that was not
                                            // allocated to any zone. Let's set if it can fit into this area
                                            if let VariableDefinition::Array(a) = &v.1.def {
                                                let width = a.len() as u32 / 8;
                                                if fill + width <= 256 {
                                                    fill += width;
                                                    sv.push((v.0.clone(), width));
                                                    self.set.insert(v.0);
                                                    self.remaining_scattered -= 1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    
                    if fill > 0 {
                        // Write the effective scattered data
                        if args.verbose {
                            println!("Bank #{} : Putting 8 lines scattered data at ${:04x}{}. Zone filling is {}/256", self.bank, rorg, if holeydma_enabled_zone {" (Holey DMA)"} else {""}, fill);
                        }
                        gstate.write("\n; Scattered data\n\tSEG SCATTERED")?;
                        gstate.write(&format!("\n\n\tORG ${:04x}\n\tRORG ${:04x}", org, rorg))?;
                        let mut counter;
                        for i in &sv {
                            gstate.write(&format!("\n{}", i.0))?;
                            if args.verbose {
                                println!(" - {}", i.0);
                            }
                            counter = 0;
                            let v = compiler_state.variables.get(&i.0).unwrap();
                            if let Some((_, w)) = v.scattered {
                                if let VariableDefinition::Array(a) = &v.def {
                                    for j in 0..i.1 {
                                        let xx = if v.reversed {
                                            &a[((j % w) + 7 * w + (j / w) * 8) as usize]
                                        } else {
                                            &a[((j % w) + (j / w) * 8) as usize]
                                        };
                                        if let VariableValue::Int(x) = xx {
                                            if counter == 0 {
                                                gstate.write("\n\thex ")?;
                                            }
                                            counter += 1;
                                            if counter == 16 { counter = 0; }
                                            gstate.write(&format!("{:02x}", x & 0xff))?;
                                        }
                                    }
                                }
                            }
                        }
                        for l in 1..8 {
                            gstate.write(&format!("\n\n\tORG ${:04x}\n\tRORG ${:04x}", org + 256 * l, rorg + 256 * l))?;
                            let mut counter = 0;
                            for i in &sv {
                                let v = compiler_state.variables.get(&i.0).unwrap();
                                if let Some((_, w)) = v.scattered {
                                    if let VariableDefinition::Array(a) = &v.def {
                                        for j in 0..i.1 {
                                            let xx = if v.reversed {
                                                &a[((j % w) + (7 - l) * w + (j / w) * 8) as usize]
                                            } else {
                                                &a[((j % w) + l * w + (j / w) * 8) as usize]
                                            };
                                            if let VariableValue::Int(x) = xx {
                                                if counter == 0 {
                                                    gstate.write("\n\thex ")?;
                                                }
                                                counter += 1;
                                                if counter == 16 { counter = 0; }
                                                gstate.write(&format!("{:02x}", x & 0xff))?;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        gstate.write("\n")?;
                    }

                    // Go on with filling the memory
                    return self.fill_memory(org + 0x800, rorg + 0x800, size - 0x800, compiler_state, gstate, args, true, true); 
                }
            }
            if self.remaining_scattered > 0 {
                // Well, we have scattered data, so let's try to find a place for them
                self.fill_memory(org, rorg, 0x800, compiler_state, gstate, args, false, false)?;
                if size > 0x800 {
                    return self.fill_memory(org + 0x800, rorg + 0x800, size - 0x800, compiler_state, gstate, args, true, true);
                } else {
                    return Ok(());
                }
            }
        }
       
        let mut filled = 0;
        
        if self.remaining_functions > 0 {

            // Generate functions code
            gstate.write("\n\n; Functions definitions\n\tSEG CODE\n")?;

            // Prelude code for each bank
            if args.verbose {
                println!("Bank #{}: Generating code at ${:04x}", self.bank, rorg);
            }
            gstate.current_bank = self.bank;
            gstate.write(&format!("\n\tORG ${:04x}\n\tRORG ${:04x}\n", org, rorg))?;

            if self.bank == 0 && !self.startup_code {
                // Generate included assembler
                for asm in &compiler_state.included_assembler {
                    gstate.write(&asm.0)?;
                    let name;
                    if let Some(n) = &asm.1 {
                        name = n.as_str();
                    } else {
                        name = "Unknown";
                    }
                    if let Some(size) = asm.2 {
                        filled += size as u32;
                        if args.verbose {
                            println!(" - Assembler {} code (filled {}/{})", name, filled, size);
                        }
                    } else {
                        let nl = asm.0.lines().count() as u32; 
                        filled += nl * 3; // 3 bytes default per line estimate.
                        if args.verbose {
                            println!(" - Assembler {} code (filled {}/{} - estimated)", name, filled, size);
                        }
                    }
                }

                self.startup_code = true;
                filled += 0x62; // Size of startup code
                if args.verbose {
                    println!(" - Startup code (filled {}/{})", filled, size);
                }
                // Generate startup code
                gstate.write("
START
    sei                     ; Disable interrupts
    cld                     ; Clear decimal mode

;******** Atari recommended startup procedure

    lda     #$07
    sta     $01        ; Lock into 7800 mode
    lda     #$7F
    sta     $3C        ; Disable DMA
    lda     #$00            
    sta     $38 
    sta     $01
    ldx     #$FF       ; Reset stack pointer
    txs

;************** Clear zero page and hardware ******

    ldx     #$40
    lda     #$00
crloop1    
    sta     $00,x      ; Clear zero page
    sta	    $100,x		 ; Clear page 1
    inx
    bne     crloop1

;************* Clear RAM **************************

    ldy     #$00            ; Clear Ram
    lda     #$18            ; Start at $1800
    sta     $81             
    lda     #$00
    sta     $80
crloop3
    lda     #$00
    sta     ($80),y         ; Store data
    iny                     ; Next byte
    bne     crloop3         ; Branch if not done page
    inc     $81             ; Next page
    lda     $81
    cmp     #$20            ; End at $1FFF
    bne     crloop3         ; Branch if not

    ldy     #$00            ; Clear Ram
    lda     #$22            ; Start at $2200
    sta     $81             
    lda     #$00
    sta     $80
crloop4
    lda     #$00
    sta     ($80),y         ; Store data
    iny                     ; Next byte
    bne     crloop4         ; Branch if not done page
    inc     $81             ; Next page
    lda     $81
    cmp     #$27            ; End at $27FF
    bne     crloop4         ; Branch if not

    ldx     #$00
    lda     #$00
crloop5                     ; Clear 2100-213F
    sta     $2100,x
    inx
    cpx     #$40
    bne     crloop5
    jmp     main 

NMI
    RTI

IRQ
    RTI
                ")?;

            }

            // Generate functions code
            for f in compiler_state.sorted_functions().iter() {
                if f.1.code.is_some() && !f.1.inline && f.1.bank == self.bank {
                    if !self.set.contains(f.0) {
                        // Check if this one needs to be generated
                        if gstate.functions_actually_in_use.get(f.0).is_none() {
                            // Skip this one
                            debug!("Skipped function {}", f.0);
                            self.set.insert(f.0);
                            self.remaining_functions -= 1;
                        } else {
                            let s = gstate.functions_code.get(f.0).unwrap().size_bytes();
                            if filled + s + 1 <= size {

                                gstate.write(&format!("\n{}\tSUBROUTINE\n", f.0))?;
                                gstate.write_function(f.0)?;
                                if f.1.interrupt {
                                    gstate.write("\tRTI\n")?;
                                } else {
                                    gstate.write("\tRTS\n")?;
                                }
                                self.set.insert(f.0);
                                self.remaining_functions -= 1;
                                filled += s + 1;

                                if args.verbose {
                                    println!(" - {} function (filled {}/{})", f.0, filled, size);
                                }
                            }
                        }
                    }
                }
            }
        } else {
            gstate.write(&format!("\n\tORG ${:04x}\n\tRORG ${:04x}\n", org, rorg))?;
        }

        if self.remaining_variables > 0 {
            // Generate ROM tables
            gstate.write("\n; Tables in ROM\n")?;
            if args.verbose {
                println!("Bank #{}: Inserting ROM tables", self.bank);
            }
            
            for v in compiler_state.sorted_variables().iter() {
                if let VariableMemory::ROM(rom_bank) = v.1.memory {
                    if rom_bank == self.bank && v.1.scattered.is_none() {
                        if !self.set.contains(v.0) {
                            // OK, we have a ROM table to insert.
                            // Let's see if it fits
                            let s = if filled > 0 {
                                (((filled - 1) / v.1.alignment as u32) + 1) * v.1.alignment as u32
                            } else { 0 };
                            let s2 = match &v.1.def {
                                VariableDefinition::Array(arr) => {
                                    if v.1.var_type == VariableType::ShortPtr {
                                        arr.len() * 2
                                    } else {
                                        arr.len()
                                    }
                                },
                                VariableDefinition::ArrayOfPointers(arr) => {
                                    arr.len() * 2 
                                },
                                _ => unreachable!()
                            } as u32;  
                            if s + s2 <= size {
                                // OK. It fits. Let's insert it
                                self.set.insert(v.0);
                                self.remaining_variables -= 1;
                                filled = s + s2;
                                if args.verbose {
                                    println!(" - {} array (filled {}/{})", v.0, filled, size);
                                }
                                match &v.1.def {
                                    VariableDefinition::Array(arr) => {
                                        if v.1.alignment != 1 {
                                            gstate.write(&format!("\n\talign {}\n", v.1.alignment))?;
                                        }
                                        gstate.write(v.0)?;
                                        let mut counter = 0;
                                        for vx in arr {
                                            match vx {
                                                VariableValue::Int(i) => {
                                                    if counter == 0 {
                                                        gstate.write("\n\thex ")?;
                                                    }
                                                    counter += 1;
                                                    if counter == 16 { counter = 0; }
                                                    gstate.write(&format!("{:02x}", i & 0xff))
                                                },
                                                VariableValue::LowPtr((s, offset)) => {
                                                    counter = 0;
                                                    if *offset != 0 {
                                                        gstate.write(&format!("\n\t.byte <({} + {})", s, offset))
                                                    } else {
                                                        gstate.write(&format!("\n\t.byte <{}", s))
                                                    }
                                                },
                                                VariableValue::HiPtr((s, offset)) => {
                                                    counter = 0;
                                                    if *offset != 0 {
                                                        gstate.write(&format!("\n\t.byte >({} + {})", s, offset))
                                                    } else {
                                                        gstate.write(&format!("\n\t.byte >{}", s))
                                                    }
                                                },
                                            }?;
                                        } 
                                        if v.1.var_type == VariableType::ShortPtr {
                                            for vx in arr {
                                                if counter == 0 {
                                                    gstate.write("\n\thex ")?;
                                                }
                                                counter += 1;
                                                if counter == 16 { counter = 0; }
                                                if let VariableValue::Int(i) = vx {
                                                    gstate.write(&format!("{:02x}", (i >> 8) & 0xff))?;
                                                }
                                            } 
                                        }
                                        gstate.write("\n")?;
                                    },
                                    VariableDefinition::ArrayOfPointers(arr) => {
                                        if v.1.alignment != 1 {
                                            gstate.write(&format!("\n\talign {}\n", v.1.alignment))?;
                                        }
                                        gstate.write(v.0)?;

                                        let mut counter = 0;
                                        for i in arr {
                                            if counter % 8 == 0 {
                                                gstate.write("\n\t.byte ")?;
                                            }
                                            counter += 1;
                                            if i.1 != 0 {
                                                gstate.write(&format!("<({} + {})", i.0, i.1))?;
                                            } else {
                                                gstate.write(&format!("<{}", i.0))?;
                                            }
                                            if counter % 8 != 0 {
                                                gstate.write(", ")?;
                                            } 
                                        } 
                                        for i in arr {
                                            if counter % 8 == 0 {
                                                gstate.write("\n\t.byte ")?;
                                            }
                                            counter += 1;
                                            if i.1 != 0 {
                                                gstate.write(&format!(">({} + {})", i.0, i.1))?;
                                            } else {
                                                gstate.write(&format!(">{}", i.0))?;
                                            }
                                            if counter % 8 != 0 && counter < 2 * arr.len() {
                                                gstate.write(", ")?;
                                            } 
                                        } 
                                        gstate.write("\n")?;
                                    },
                                    _ => ()
                                };
                            }
                        }
                    }
                }
            }
        }
        debug!("*** Remaining: {}, {}, {}", self.remaining_variables, self.remaining_functions, self.remaining_scattered);
        
        Ok(())
    }
}

fn write_a78_header(compiler_state: &CompilerState, gstate: &mut GeneratorState, bankswitching_scheme: &str, output: &str, memoryonchip: bool) -> Result<(), Error>
{
    let romsize;
    let mut cartb;
    let mapper;
    let mut mapper_options = 0;
    let mut audio = 0;
    match bankswitching_scheme {
        "32K" => {
            romsize = 32 * 1024;
            cartb = 0; 
            mapper = 0;
        },
        "SuperGame" => {
            romsize = 128 * 1024;
            cartb = 2; // SuperGame
            mapper = 1;
        },
        _ => return Err(Error::Unimplemented { feature: "Unknown bankswtiching scheme" })
    };
    if memoryonchip {
        cartb |= 4;
        mapper_options |= 1;
    }
    if compiler_state.variables.get("POKEY").is_some() {
        if memoryonchip {
            cartb |= 64;
            audio = 2;
        } else {
            cartb |= 1;
            audio = 5;
        }
    }
    gstate.write(&format!("
    ORG $7F80

 ; A78 Header v4.0

.ROMSIZE = ${:x}

.HEADER = .

    DC.B    4                  ; 0          header major version
    DC.B    \"ATARI7800\"        ; 1..16      header magic string - zero pad

    ORG .HEADER+$11,0
    DC.B    \"{}\"   ; 17..48     cartridge title string - zero pad

    ORG .HEADER+$31,0
    DC.B    (.ROMSIZE>>24)     ; 49..52     cartridge ROM size
    DC.B    (.ROMSIZE>>16&$FF)
    DC.B    (.ROMSIZE>>8&$FF)
    DC.B    (.ROMSIZE&$FF)

    ; The following 2 cartridge type bytes are deprecated as of header v4.0.
    ; It's recommended that you still populate these bytes for support with
    ; platforms that don't yet support v4.

    DC.B    %00000000          ; 53         cartridge type A
    DC.B    ${:02x}          ; 54           cartridge type B
    ; _Cartridge Type A_
    ;    bit 7 ; POKEY @ $0800 - $080F
    ;    bit 6 ; EXRAM/M2                   (halt banked RAM)
    ;    bit 5 ; BANKSET
    ;    bit 4 ; SOUPER
    ;    bit 3 ; YM2151 @ $0461 - $0462 
    ;    bit 2 ; POKEY @ $0440 - $044F 
    ;    bit 1 ; ABSOLUTE
    ;    bit 0 ; ACTIVISION
    ; _Cartridge Type B_
    ;    bit 7 ; EXRAM/A8                   (mirror RAM)
    ;    bit 6 ; POKEY @ $0450 - $045F 
    ;    bit 5 ; EXRAM/X2                   (hotspot banked RAM)
    ;    bit 4 ; EXFIX                      (2nd last bank @ $4000)
    ;    bit 3 ; EXROM                      (ROM @ $4000)
    ;    bit 2 ; EXRAM                      (RAM @ $4000)
    ;    bit 1 ; SUPERGAME
    ;    bit 0 ; POKEY @ $4000 - $7FFF

    DC.B    1                  ; 55         controller 1 device type
    DC.B    1                  ; 56         controller 2 device type
    ;    0 = none
    ;    1 = 7800 joystick
    ;    2 = lightgun
    ;    3 = paddle
    ;    4 = trakball
    ;    5 = 2600 joystick
    ;    6 = 2600 driving
    ;    7 = 2600 keypad
    ;    8 = ST mouse
    ;    9 = Amiga mouse
    ;   10 = AtariVox
    ;   11 = SNES2Atari

    DC.B    %00000000          ; 57         tv type
    ;    bits 7..2 ; reserved
    ;    bit  1    ; 0:component,1:composite
    ;    bit  0    ; 0:NTSC,1:PAL

    DC.B    %00000000          ; 58         save peripheral
    ;    bits 7..2 ; reserved
    ;    bit  1    ; SaveKey/AtariVox
    ;    bit  0    ; High Score Cart (HSC)

    ; The following irq source byte is deprecated as of header v4.0.
    ; It's recommended that you still populate this byte for support with
    ; platforms that don't yet support v4.

    ORG     .HEADER+62,0
    DC.B    $0          ; 62         external irq source
    ;    bits 7..5 ; reserved
    ;    bit  4    ; POKEY  @ $0800 - $080F
    ;    bit  3    ; YM2151 @ $0461 - $0462
    ;    bit  2    ; POKEY  @ $0440 - $044F
    ;    bit  1    ; POKEY  @ $0450 - $045F
    ;    bit  0    ; POKEY  @ $4000 - $7FFF

    DC.B    %00000000          ; 63         slot passthrough device
    ;    bits 7..1 ; reserved
    ;    bit  0    ; XM module

    ; The following 6 bytes are v4 header specific. You should populate
    ; them with valid info if you're not using V3ONLY, because they will
    ; take precedence over v3 headers.

    DC.B    {mapper}                  ; 64         mapper
    ;    0 = linear
    ;    1 = supergame
    ;    2 = activision
    ;    3 = absolute
    ;    4 = souper


    DC.B    {mapper_options}           ; 65         mapper options
    ; linear_
    ;    bit  7      ; bankset rom
    ;    bits 0-1    ; option @4000...
    ;       0 = none
    ;       1 = 16K EXRAM
    ;       2 = 8K  EXRAM/A8
    ;       3 = 32K EXRAM/M2
    ; supergame_
    ;    bit  7      ; bankset rom
    ;    bits 0-2    ; option @4000...
    ;       0 = none
    ;       1 = 16K EXRAM
    ;       2 = 8K  EXRAM/A8
    ;       3 = 32K EXRAM/M2
    ;       4 = 16K EXROM
    ;       5 = EXFIX
    ;       6 = 32K EXRAM/X2

    DC.B    %00000000          ; 66         audio hi
    DC.B    {audio}          ; 67         audio lo
    ;    bit  4      ; covox@430
    ;    bit  3      ; ym2151@460
    ;    bits 0-2    ; pokey...
    ;       0 = none
    ;       1 = pokey@440
    ;       2 = pokey@450
    ;       3 = dual pokey @440+@450
    ;       4 = pokey@800
    ;       5 = pokey@4000

    DC.B    %00000000          ; 68         interrupt hi
    DC.B    $0            ; 69         interrupt lo
    ;    bit  2    ; YM2151
    ;    bit  1    ; pokey 2 (@440)
    ;    bit  0    ; pokey 1 (@4000, @450, or @800)


    ORG     .HEADER+100,0       ; 100..127  footer magic string
    DC.B    \"ACTUAL CART DATA STARTS HERE\"

        ", romsize, output, cartb))?;
    Ok(())
}

pub fn build_cartridge(compiler_state: &CompilerState, writer: &mut dyn Write, args: &Args) -> Result<(), Error> 
{
    let mut bankswitching_scheme = "32K";
    let mut nmi_interrupt = "NMI";

    // Try to figure out what is the bankswitching method

    let mut maxbank = 0;
    for f in compiler_state.sorted_functions().iter() {
        if f.1.bank > maxbank { maxbank = f.1.bank; }
    }
    for v in compiler_state.sorted_variables().iter() {
        if let VariableMemory::ROM(rombank) = v.1.memory {
            if rombank > maxbank {maxbank = rombank;
            }
        }
    }
    if maxbank != 0 {
        bankswitching_scheme = "SuperGame";
        if maxbank > 7 {
            return Err(Error::Configuration { error: "Atari 7800 Super Game bankswitching scheme is limited to 8 banks (0 to 7)".to_string() });
        }
        maxbank = 7;
    }

    // Start generation
    let mut gstate = GeneratorState::new(compiler_state, writer, args.insert_code, args.warnings.clone(), bankswitching_scheme);
    gstate.write("\tPROCESSOR 6502\n\n")?;
    
    for v in compiler_state.sorted_variables().iter() {
        if v.1.var_const  {
            if let VariableDefinition::Value(vx) = &v.1.def  {
                match vx {
                    VariableValue::Int(val) => gstate.write(&format!("{:23}\tEQU ${:x}\n", v.0, val)),
                    VariableValue::LowPtr((s, offset)) => if *offset != 0 {
                        gstate.write(&format!("{:23}\tEQU <({} + {})\n", v.0, s, offset))
                    } else {
                        gstate.write(&format!("{:23}\tEQU <{}\n", v.0, s))
                    },
                    VariableValue::HiPtr((s, offset)) => if *offset != 0 {
                        gstate.write(&format!("{:23}\tEQU >({} + {})\n", v.0, s, offset))
                    } else {
                        gstate.write(&format!("{:23}\tEQU >{}\n", v.0, s))
                    },
                }?;
            }
        }
    }

    let mut memoryonchip = false;
    for v in compiler_state.sorted_variables().iter() {
        if let VariableMemory::MemoryOnChip(_) = v.1.memory {
            memoryonchip = true;
            break;
        }
    }
    
    for f in compiler_state.sorted_functions().iter() {
        if f.1.code.is_some() {
            gstate.local_label_counter_for = 0;
            gstate.local_label_counter_if = 0;

            gstate.functions_code.insert(f.0.clone(), AssemblyCode::new());
            gstate.current_function = Some(f.0.clone());
            gstate.generate_statement(f.1.code.as_ref().unwrap())?;
            gstate.current_function = None;

            if args.optimization_level > 0 {
                gstate.optimize_function(f.0);
            }
            gstate.check_branches(f.0);
        }
        if f.1.interrupt{
            nmi_interrupt = f.0;
        }
    }

    gstate.compute_functions_actually_in_use()?;

    write_a78_header(compiler_state, &mut gstate, bankswitching_scheme, &args.output, memoryonchip)?;

    gstate.write("\n\tSEG.U ZEROPAGE\n\tORG $40\n\n")?;
   
    let mut zeropage_bytes = 1;

    // Generate variables code
    gstate.write("cctmp                  \tds 1\n")?; 
    for v in compiler_state.sorted_variables().iter() {
        if v.1.memory == VariableMemory::Zeropage && v.1.def == VariableDefinition::None && v.1.global {
            if v.1.size > 1 {
                let s = match v.1.var_type {
                    VariableType::CharPtr => 1,
                    VariableType::CharPtrPtr => 2,
                    VariableType::ShortPtr => 2,
                    _ => unreachable!()
                };
                gstate.write(&format!("{:23}\tds {}\n", v.0, v.1.size * s))?; 
                zeropage_bytes += v.1.size * s;
            } else {
                let s = match v.1.var_type {
                    VariableType::Char => 1,
                    VariableType::Short => 2,
                    VariableType::CharPtr => 2,
                    VariableType::CharPtrPtr => 2,
                    VariableType::ShortPtr => 2,
                };
                gstate.write(&format!("{:23}\tds {}\n", v.0, s))?; 
                zeropage_bytes += s;
            }
        }
    }

    // Compute in the call tree the level of each function
    let mut function_levels: Vec<Vec<String>> = Vec::new();
    for f in compiler_state.sorted_functions().iter() {
        let lev = if f.0 == "main" { Some(0) } else {
            compute_function_level(f.0, "main", 1, &gstate.functions_call_tree, 0)
        };
        if let Some(level) = lev {
            let l = function_levels.get_mut(level);
            if let Some(a) = l {
                a.push(f.0.clone())
            } else {
                function_levels.resize(level + 1, Vec::new());
                function_levels[level].push(f.0.clone());
            }
        }
    }
    
    let mut level = 0;
    for l in function_levels {
        gstate.write(&format!("\nLOCAL_VARIABLES_{}\n\n", level))?;
        let mut maxbsize = 0;
        let mut bsize = 0;
        for fx in l {
            if let Some(f) = compiler_state.functions.get(&fx) {
                if gstate.functions_actually_in_use.get(&fx).is_some() && f.local_variables.len() != 0 {
                    bsize = 0;
                    gstate.write(&format!("\tORG LOCAL_VARIABLES_{}\n", level))?;
                    for vx in &f.local_variables {
                        if let Some(v) = compiler_state.variables.get(vx) {
                            if v.memory == VariableMemory::Zeropage && v.def == VariableDefinition::None {
                                if v.size > 1 {
                                    let s = match v.var_type {
                                        VariableType::CharPtr => 1,
                                        VariableType::CharPtrPtr => 2,
                                        VariableType::ShortPtr => 2,
                                        _ => unreachable!()
                                    };
                                    gstate.write(&format!("{:23}\tds {}\n", vx, v.size * s))?; 
                                    bsize += v.size * 2;
                                } else {
                                    let s = match v.var_type {
                                        VariableType::Char => 1,
                                        VariableType::Short => 2,
                                        VariableType::CharPtr => 2,
                                        VariableType::CharPtrPtr => 2,
                                        VariableType::ShortPtr => 2,
                                    };
                                    gstate.write(&format!("{:23}\tds {}\n", vx, s))?; 
                                    bsize += s;
                                }
                            }
                        }
                    }
                    if bsize > maxbsize {
                        maxbsize = bsize;
                    }
                }
            }
        }
        if maxbsize != bsize {
            gstate.write(&format!("\tORG LOCAL_VARIABLES_{} + {}\n", level, maxbsize))?;
        }
        zeropage_bytes += maxbsize;
        level += 1;
    }
    if args.verbose {
        println!("Atari 7800 zeropage RAM usage: {}/192", zeropage_bytes);
    }

    gstate.write("\n\tSEG.U RAM1\n\tORG $1800\n\tRORG $1800\n")?;
    // main RAM variables 
    let mut filled = 0;
    let mut ram1_filled = false;
    //let mut ram2_filled = false;
    if args.verbose {
        println!("Atari 7800 internal RAM : 0x1800 onwards");
    }
    for v in compiler_state.sorted_variables().iter() {
        if v.1.memory == VariableMemory::Ramchip && v.1.def == VariableDefinition::None {
            let sx = if v.1.size > 1 {
                let s = match v.1.var_type {
                    VariableType::CharPtr => 1,
                    VariableType::CharPtrPtr => 2,
                    VariableType::ShortPtr => 2,
                    _ => unreachable!()
                };
                v.1.size * s 
            } else {
                match v.1.var_type {
                    VariableType::Char => 1,
                    VariableType::Short => 2,
                    VariableType::CharPtr => 2,
                    VariableType::CharPtrPtr => 2,
                    VariableType::ShortPtr => 2,
                }
            };
            filled += sx;
            if filled > 0x840 && !ram1_filled {
                // Skip the zeropage shadow 
                ram1_filled = true;
/*
                gstate.write("\n\tSEG.U RAM2\n\tORG $2100\n\tRORG $2200\n")?;
                filled = 0x900 + sx;
                if args.verbose {
                    println!("Atari 7800 internal RAM : 0x2100 onwards (in between zeropage & stack shadows)");
                }
            } 
            if filled > 0x940 && !ram2_filled {
                // Skip the stack shadow
                ram2_filled = true;
*/
                gstate.write("\n\tSEG.U RAM3\n\tORG $2200\n\tRORG $2200\n")?;
                filled = 0xa00 + sx;
                if args.verbose {
                    println!("Atari 7800 internal RAM : 0x2200 onwards");
                }
            } 
            if filled > 4096 {
                return Err(Error::Configuration { error: "Memory full. Internal Atari 7800 RAM is limited to 4KB".to_string() });
            }
            gstate.write(&format!("{:23}\tds {}\n", v.0, sx))?;
            if args.verbose {
                println!(" - {} ({} byte{})", v.0, sx, if sx > 1 {"s"} else {""});
            }
        }
    }
    if args.verbose {
        println!("Atari 7800 internal RAM : {} bytes left", 4096 - filled);
    }

    // Generate veriables stored in RAM on cart (memory on chip)
    if memoryonchip {
        if args.verbose {
            println!("Cart RAM : 0x4000 onwards");
        }
        let mut filled = 0;
        gstate.write("\n\tSEG.U MEMORY_ON_CHIP\n\tORG $4000\n")?;
        for v in compiler_state.sorted_variables().iter() {
            if let VariableMemory::MemoryOnChip(_) = v.1.memory {
                let sx = if v.1.size > 1 {
                    let s = match v.1.var_type {
                        VariableType::CharPtr => 1,
                        VariableType::CharPtrPtr => 2,
                        VariableType::ShortPtr => 2,
                        _ => unreachable!()
                    };
                    v.1.size * s 
                } else {
                    match v.1.var_type {
                        VariableType::Char => 1,
                        VariableType::Short => 2,
                        VariableType::CharPtr => 2,
                        VariableType::CharPtrPtr => 2,
                        VariableType::ShortPtr => 2,
                    }
                };
                filled += sx;
                if filled > 0x4000 {
                    return Err(Error::Configuration { error: "Memory full. Cart RAM is limited to 16KB".to_string() });
                }
                gstate.write(&format!("{:23}\tds {}\n", v.0, sx))?;
                if args.verbose {
                    println!(" - {} ({} byte{})", v.0, sx, if sx > 1 {"s"} else {""});
                }
            }
        }
        if args.verbose {
            println!("Cart RAM : {} bytes left", 0x4000 - filled);
        }
    }

    // Generate code for all banks
    for b in 0..=maxbank {
        
        let (bank, banksize, rorg) = if bankswitching_scheme == "SuperGame" { 
            if b == 7 { (0, 0x4000, 0xc000) } else { (b + 1, 0x4000, 0x8000) }
        } else { (0, 0x8000, 0x8000) };

        let mut map = MemoryMap::new(compiler_state, bank);
        map.fill_memory(0x8000 + b * banksize, rorg, banksize, compiler_state, &mut gstate, args, true, true)?;
        assert!(map.remaining_scattered == 0);
        assert!(map.remaining_functions == 0);
        assert!(map.remaining_variables == 0);

        if b == maxbank {
            // Epilogue code
            gstate.write(&format!("
        ORG ${:04x}
        .byte $FF ; Region verification
        .byte ${:02x} 
        .word #{nmi_interrupt}\t; NMI
        .word #START\t; RESET
        .word #IRQ\t; IRQ
        \n", if maxbank == 0 { 0xfff8 } else { b * banksize + 0xbff8 }, if maxbank == 0 { 0x87 } else { 0xc7 }))?;

        }
    }

    gstate.write("\tEND\n")?;
    
    if args.verbose {
        println!("Generated a {} ATARI 7800 cartridge", bankswitching_scheme);
    }
    Ok(())
}

fn compute_function_level(function_name: &String, node: &str, current_level: usize, tree: &HashMap<String, Vec<String>>, i: u32) -> Option<usize> 
{
    let mut ret = None;
    if i == 1000 { return None; } // In order to avoid recursive tree
    if let Some(calls) = tree.get(node) {
        // Is the function name in current_level tree ?
        if calls.contains(function_name) {
            ret = Some(current_level);
        }
        // Look at the lower levels if it is possible to find it also
        for nodex in calls {
            if let Some(lx) = compute_function_level(function_name, nodex, current_level + 1, tree, i + 1) {
                if let Some(lxx) = ret {
                    if lx > lxx {
                        ret = Some(lx);
                    }
                } else {
                    ret = Some(lx)
                }
            }
        }
    } 
    ret 
}


