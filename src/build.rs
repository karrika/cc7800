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
use std::collections::HashSet;

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
}

impl<'a> MemoryMap<'a> {
    fn new(compiler_state: &'a CompilerState, bank: u32) -> MemoryMap<'a> {
        let mut remaining_functions = 0;
        for f in compiler_state.sorted_functions().iter() {
            if f.1.bank == bank {
                remaining_functions += 1;
            }
        }
        let mut remaining_scattered = 0;
        let mut remaining_variables = 0;
        for v in compiler_state.sorted_variables().iter() {
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

        MemoryMap {
            bank,
            set: HashSet::new(),
            remaining_functions,
            remaining_scattered,
            remaining_variables,
        }
    }

    fn fill_memory(&mut self, org: u32, rorg: u32, size: u32, compiler_state: &'a CompilerState, gstate: &mut GeneratorState, args: &Args) -> Result<(), Error> {
        // Is there any scattered memory remaining ?
        if self.remaining_scattered > 0 {
            // Yes. So let's try to fit some.
            // Are we in a zone where 16 lines of scattered data can be stored ?
            if rorg & 0x1000 == 0 && size >= 0x1000 {
                // Yes. Let's see if there is any remaining 16 lines scattered data to be stored
                let mut scattered_16 = false;
                for v in compiler_state.sorted_variables().iter() {
                    if let VariableMemory::ROM(b) = v.1.memory {
                        if b == self.bank {
                            if let Some((l, _)) = v.1.scattered {
                                if l == 16 {
                                    if !self.set.contains(v.0) {
                                        // OK. We have found a 16 lines scattered data that was not
                                        // allocated to any zone. Let's create a new 16 lines scattered data zone
                                        scattered_16 = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                if scattered_16 {
                    // Great. Let's fill this 4Kb of memory with 16 lines scattered data
                    gstate.write("\n; Scattered data\n\tSEG SCATTERED")?;
        
                    // Let's select all the variables that will fit into this scattered data
                    let mut sv = Vec::<(String, u32)>::new();
                    let mut fill = 0;
                    for v in compiler_state.sorted_variables().iter() {
                        if let VariableMemory::ROM(b) = v.1.memory {
                            if b == self.bank {
                                if let Some((l, _)) = v.1.scattered {
                                    if l == 16 {
                                        if !self.set.contains(v.0) {
                                            // OK. We have found a 16 lines scattered data that was not
                                            // allocated to any zone. Let's set if it can fit into this area
                                            if let VariableDefinition::Array(a) = &v.1.def {
                                                let width = a.len() as u32 / 16;
                                                if fill + width <= 256 {
                                                    fill += width;
                                                    sv.push((v.0.clone(), width));
                                                    self.set.insert(v.0);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    // Write the effective scattered data
                    gstate.write(&format!("\n\n\tORG ${:04x}\n\tRORG ${:04x}\n", org, rorg))?;
                    for i in &sv {
                        gstate.write(&format!("\n{}", i.0))?;
                        let v = compiler_state.variables.get(&i.0).unwrap();
                        gstate.write("\n\thex ")?;
                        if let Some((_, w)) = v.scattered {
                            if let VariableDefinition::Array(a) = &v.def {
                                for j in 0..i.1 {
                                    let x = if v.reversed {
                                        a[((j % w) + 15 * w + (j / w) * 16) as usize]
                                    } else {
                                        a[((j % w) + (j / w) * 16) as usize]
                                    };
                                    gstate.write(&format!("{:02x}", x & 0xff))?;
                                }
                            }
                        }
                    }
                    for l in 1..16 {
                        gstate.write(&format!("\n\n\tORG ${:04x}\n\tRORG ${:04x}\n", org + 256 * l, rorg + 256 * l))?;
                        let mut counter = 0;
                        for i in &sv {
                            let v = compiler_state.variables.get(&i.0).unwrap();
                            if let Some((_, w)) = v.scattered {
                                if let VariableDefinition::Array(a) = &v.def {
                                    for j in 0..i.1 {
                                        let x = if v.reversed {
                                            a[((j % w) + (15 - l) * w + (j / w) * 16) as usize]
                                        } else {
                                            a[((j % w) + l * w + (j / w) * 16) as usize]
                                        };
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

                    // Go on with filling the memory
                    return self.fill_memory(org + 0x1000, rorg + 0x1000, size - 0x1000, compiler_state, gstate, args); 
                }
            }
            // TODO: Implement the same for 8 lines scattered data
        }
        // TODO: Implement partial code generation
        
        // Generate functions code
        gstate.write("\n\n; Functions definitions\n\tSEG CODE\n")?;

        // Prelude code for each bank
        debug!("Generating code for bank #{}", self.bank);
        gstate.current_bank = self.bank;
        gstate.write(&format!("\n\tORG ${:04x}\n\tRORG ${:04x}\n", org, rorg))?;
  
        if self.bank == 0 {
            // Generate startup code
            gstate.write("
START
	  sei                     ;Disable interrupts
 	  cld                     ;Clear decimal mode

;******** Atari recommended startup procedure

	  lda     #$07
	  sta     INPTCTRL        ;Lock into 7800 mode
	  lda     #$7F
	  sta     CTRL            ;Disable DMA
	  lda     #$00            
	  sta     OFFSET
	  sta     INPTCTRL
	  ldx     #$FF            ;Reset stack pointer
	  txs
	
;************** Clear zero page and hardware ******

	  ldx     #$40
	  lda     #$00
crloop1    
	  sta     $00,x           ;Clear zero page
	  sta	$100,x		;Clear page 1
	  inx
	  bne     crloop1

;************* Clear RAM **************************

    ldy     #$00            ;Clear Ram
    lda     #$18            ;Start at $1800
    sta     $81             
    lda     #$00
    sta     $80
crloop3
    lda     #$00
    sta     ($80),y         ;Store data
    iny                     ;Next byte
    bne     crloop3         ;Branch if not done page
    inc     $81             ;Next page
    lda     $81
    cmp     #$20            ;End at $1FFF
    bne     crloop3         ;Branch if not

    ldy     #$00            ;Clear Ram
    lda     #$22            ;Start at $2200
    sta     $81             
    lda     #$00
    sta     $80
crloop4
    lda     #$00
    sta     ($80),y         ;Store data
    iny                     ;Next byte
    bne     crloop4         ;Branch if not done page
    inc     $81             ;Next page
    lda     $81
    cmp     #$27            ;End at $27FF
    bne     crloop4         ;Branch if not

    ldx     #$00
    lda     #$00
crloop5                         ;Clear 2100-213F
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

            // Generate included assembler
            for asm in &compiler_state.included_assembler {
                gstate.write(asm)?;
            }
        }
        
        // Generate functions code
        for f in compiler_state.sorted_functions().iter() {
            if f.1.code.is_some() && !f.1.inline && f.1.bank == self.bank {
                debug!("Generating code for function #{}", f.0);

                gstate.write(&format!("\n{}\tSUBROUTINE\n", f.0))?;
                gstate.write_function(f.0)?;
                gstate.write("\tRTS\n")?;
            }
        }

        // Generate ROM tables
        gstate.write("\n; Tables in ROM\n")?;
        for v in compiler_state.sorted_variables().iter() {
            if let VariableMemory::ROM(rom_bank) = v.1.memory {
                if rom_bank == self.bank && v.1.scattered.is_none() {
                    match &v.1.def {
                        VariableDefinition::Array(arr) => {
                            if v.1.alignment != 1 {
                                gstate.write(&format!("\n\talign {}\n", v.1.alignment))?;
                            }
                            gstate.write(v.0)?;
                            let mut counter = 0;
                            for i in arr {
                                if counter == 0 {
                                    gstate.write("\n\thex ")?;
                                }
                                counter += 1;
                                if counter == 16 { counter = 0; }
                                gstate.write(&format!("{:02x}", i & 0xff))?;
                            } 
                            if v.1.var_type == VariableType::ShortPtr {
                                for i in arr {
                                    if counter == 0 {
                                        gstate.write("\n\thex ")?;
                                    }
                                    counter += 1;
                                    if counter == 16 { counter = 0; }
                                    gstate.write(&format!("{:02x}", (i >> 8) & 0xff))?;
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
                                gstate.write(&format!("<{}", i))?;
                                if counter % 8 != 0 {
                                    gstate.write(", ")?;
                                } 
                            } 
                            for i in arr {
                                if counter % 8 == 0 {
                                    gstate.write("\n\t.byte ")?;
                                }
                                counter += 1;
                                gstate.write(&format!(">{}", i))?;
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
        
        Ok(())
    }
}

pub fn build_cartridge(compiler_state: &CompilerState, writer: &mut dyn Write, args: &Args) -> Result<(), Error> 
{
    let mut bankswitching_scheme = "32K";
    
    // Try to figure out what is the bankswitching method

    let mut maxbank = 0;
    for f in compiler_state.sorted_functions().iter() {
         if f.1.bank > maxbank { maxbank = f.1.bank; }
    }
    if maxbank != 0 {
        bankswitching_scheme = "SuperGame";
        if maxbank > 7 {
            return Err(Error::Configuration { error: "Atari 7800 Super Game bankswitching scheme is limited to 7 banks".to_string() });
        }
        maxbank = 7;
    }

    // Start generation
    let mut gstate = GeneratorState::new(compiler_state, writer, args.insert_code, bankswitching_scheme);
    gstate.write("\tPROCESSOR 6502\n\n")?;
    
    for v in compiler_state.sorted_variables().iter() {
        if v.1.var_const  {
            if let VariableDefinition::Value(val) = &v.1.def  {
                gstate.write(&format!("{:23}\tEQU ${:x}\n", v.0, val))?;
            }
        }
    }

    gstate.write("\n\tSEG.U ZEROPAGE\n\tORG $40\n\n")?;
    
    // Generate variables code
    gstate.write("cctmp                  \tds 1\n")?; 
    for v in compiler_state.sorted_variables().iter() {
        if v.1.memory == VariableMemory::Zeropage && v.1.def == VariableDefinition::None {
            if v.1.size > 1 {
                let s = match v.1.var_type {
                    VariableType::CharPtr => 1,
                    VariableType::CharPtrPtr => 2,
                    VariableType::ShortPtr => 2,
                    _ => unreachable!()
                };
                gstate.write(&format!("{:23}\tds {}\n", v.0, v.1.size * s))?; 
            } else {
                let s = match v.1.var_type {
                    VariableType::Char => 1,
                    VariableType::Short => 2,
                    VariableType::CharPtr => 2,
                    VariableType::CharPtrPtr => 2,
                    VariableType::ShortPtr => 2,
                };
                gstate.write(&format!("{:23}\tds {}\n", v.0, s))?; 
            }
        }
    }

    gstate.write("\n\tSEG.U RAM1\n\tORG $1800\n\tRORG $1800\n")?;
    // main RAM variables 
    for v in compiler_state.sorted_variables().iter() {
        if v.1.memory == VariableMemory::Ramchip && v.1.def == VariableDefinition::None {
            if v.1.size > 1 {
                let s = match v.1.var_type {
                    VariableType::CharPtr => 1,
                    VariableType::CharPtrPtr => 2,
                    VariableType::ShortPtr => 2,
                    _ => unreachable!()
                };
                gstate.write(&format!("{:23}\tds {}\n", v.0, v.1.size * s))?; 
            } else {
                let s = match v.1.var_type {
                    VariableType::Char => 1,
                    VariableType::Short => 2,
                    VariableType::CharPtr => 2,
                    VariableType::CharPtrPtr => 2,
                    VariableType::ShortPtr => 2,
                };
                gstate.write(&format!("{:23}\tds {}\n", v.0, s))?; 
            }
        }
    }

    // TODO: Immplement RAM2 to go over the zeropage and stack shadows at 0x2040 and 0x2140 (i.e. 2K + 40 bytes away)

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
    }

    // Generate code for all banks
    for b in 0..=maxbank {
        
        let (bank, banksize, rorg) = if bankswitching_scheme == "SuperGame" { 
            if b == 7 { (0, 0x4000, 0xc000) } else { (b + 1, 0x4000, 0x8000) }
        } else { (0, 0x8000, 0x8000) };

        let mut map = MemoryMap::new(compiler_state, bank);
        map.fill_memory(b * banksize, rorg, banksize, compiler_state, &mut gstate, args)?;

        if b == maxbank {
            // Epilogue code
            gstate.write(&format!("
        ORG ${:04x}
        .byte $FF ; Region verification
        .byte ${:02x} 
        .word #NMI\t; NMI
        .word #START\t; RESET
        .word #IRQ\t; IRQ
        \n", if maxbank == 0 { 0x7ff8 } else { b * banksize + 0x3ff8 }, if maxbank == 0 { 0x87 } else { 0xc7 }))?;

        }
    }

    gstate.write("\tEND\n")?;
    
    if args.verbose {
        println!("Generated a {} ATARI 7800 cartridge", bankswitching_scheme);
    }
    Ok(())
}
