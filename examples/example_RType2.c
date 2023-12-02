#include "string.h"
#define _MS_DL_SIZE 80 
#define HORIZONTAL_SCROLLING
#define _MS_BOTTOM_SCROLLING_ZONE 1
#define MULTISPRITE_USE_VIDEO_MEMORY
#include "sparse_tiling.h"
#include "joystick.h"
#ifdef POKEY_MUSIC
bank7 {
#define POKEY_AT_450
#include "rmtplayer.h"
#include "RMT_RType.asm"
}
#endif

// Generated from sprites7800 RType_tiles.yaml
#include "example_RType_tiles_mirror.c"

// Generated from sprites7800 RType_sprites.yaml
#include "example_RType_sprites.c"

// Generated from tiles7800 --sparse RType_tiles.yaml --varname tilemap_level1 RType_level1.tmx 
#include "example_RType_level1_mirror.c"

// Generated from sprites7800 RType_font.yaml
// bank7 {
#include "example_RType_font.c"
//}

// Put the dobkeratops code in Bank 1 & gfx in Bank 2
#include "example_dobkeratops_banked.c"

// Game state management
#define MISSILES_SPEED 4 
#define MISSILES_NB_MAX 5
ramchip char missile_xpos[MISSILES_NB_MAX], missile_ypos[MISSILES_NB_MAX], missile_type[MISSILES_NB_MAX];
ramchip char missile_first, missile_last;

#define CIRCLES_NB_MAX 5
ramchip char circle_xpos[MISSILES_NB_MAX], circle_ypos[MISSILES_NB_MAX], circle_state[MISSILES_NB_MAX];
ramchip char circle_first, circle_last;

ramchip char button_pressed;
ramchip char R9_xpos, R9_ypos, R9_state, R9_state_counter; 
ramchip char R9_satellite_counter, R9_satellite_state;
ramchip char R9_charging_counter, R9_charging_counter2;
const char *R9_satellite_sequence[] = {satellite1, satellite2, satellite3, satellite4};
const char *R9_charging_sequence[] = {beam1, beam2, beam3};

#define R9_CIRCLE_FIRE  4
#define R9_CHARGING     8

ramchip unsigned int score, high_score;
ramchip char update_score;
ramchip char display_score_str[5];
ramchip char display_high_score_str[5];
ramchip char level_progress_low, level_progress_high;
ramchip char counter_tail;

void game_init()
{
    score = 0;
    high_score = 0;
    update_score = 1;
    level_progress_high = 0;
    level_progress_low = 0;

    // Init game state variables
    missile_first = 0;
    missile_last = 0;
    circle_first = 0;
    circle_last = 0;

    // Initialize spaceship state
    R9_xpos = 20;
    R9_ypos = 80;
    R9_state = R9_CIRCLE_FIRE; // 1
    R9_state_counter = 100;
    R9_satellite_counter = 0;
    R9_satellite_state = 0;
    R9_charging_counter = 0;
    R9_charging_counter2 = 0;

    // Initialize boss
    counter_tail = 0;
}

void step()
{
    char x, y, i, c, state;
    char *gfx;
    char draw_R9;
    
    // Draw circles
    for (i = circle_first; i != circle_last; i++) {
        if (i == CIRCLES_NB_MAX) {
            i = 0;
            if (circle_last == 0) break;
        }
        if (circle_xpos[X = i] != -1) {
            y = circle_ypos[X = i];
            x = circle_xpos[X];
            state = circle_state[X];
            if (x >= 160) { // || sparse_tiling_collision(y + 8, x, x + 27) || sparse_tiling_collision(y + 23, x, x + 27) != -1 ) {
                // Out of screen or collided with background
                circle_xpos[X = i] = -1; // Removed
                do {
                    X++;
                    if (X == MISSILES_NB_MAX) X = 0;
                } while (X != circle_last && circle_xpos[X] == -1);
                circle_first = X;
            } else {
                char w, xp, yp;
                // Draw circle
                if (state < 11) {
                    for (c = 0; c != 2; c++) {
                        if (c == 0) {
                            gfx = big_circle_top;
                            yp = y - 8;
                        } else {
                            gfx = big_circle_bottom;
                            yp = y + 24;
                        }
                        if (state < 6) {
                            w = state + 1;
                        } else {
                            w = state - 5;
                            gfx += w;
                            w = 11 - state;
                        }
                        multisprite_display_sprite_ex(x, yp, gfx, w, 1, 0);
                    }   
                }
                if (state >= 5) {
                    c = state - 5;
                    if (c < 6) w = c + 1;
                    else w = 7;
                    if (state < 11) {
                        gfx = circles_top;
                        xp = x + 20 - (c << 2);
                    } else {
                        c = state - 10;
                        gfx = circles_top + c; 
                        xp = x;
                    }
                    multisprite_display_sprite_ex(xp, y, gfx, w, 1, 0);
                    if (state < 11) {
                        gfx = circles_bottom;
                    } else {
                        gfx = circles_bottom + c;
                        if (state >= 17) state -= 7;
                    }
                    yp = y + 16;
                    multisprite_display_sprite_ex(xp, yp, gfx, w, 1, 0);
                }
                if (state >= 5) {
                    x += 4;
                    circle_xpos[X = i] = x;
                    if (state == 10) x += 20;
                }
                state++;
                circle_state[X = i] = state;
            }
        }
    }

    // Draw missiles
    for (i = missile_first; i != missile_last; i++) {
        if (i == MISSILES_NB_MAX) {
            i = 0;
            if (missile_last == 0) break;
        }
        if (missile_xpos[X = i] != -1) {
            y = missile_ypos[X = i];
            x = missile_xpos[X] + MISSILES_SPEED;
            if (x >= 160 || sparse_tiling_collision(y + 1, x, x + 7) != -1 ) {
                // Out of screen or collided with background
                missile_xpos[X = i] = -1; // Removed
                do {
                    X++;
                    if (X == MISSILES_NB_MAX) X = 0;
                } while (X != missile_last && missile_xpos[X] == -1);
                missile_first = X;
            } else {
                missile_xpos[X = i] = x;
                // Draw missile
                if (missile_type[X = i] == 1) {
                    multisprite_display_sprite_ex(x, y, bigfire, 8, 1, 0);
                } else {
                    multisprite_display_small_sprite_ex(x, y, missile, 2, 0, 12, 0);
                }
            }
        }
    }
    
    if ((R9_state & 1) == 0) {
        draw_R9 = 1;
        // Check collision with background
        char c = sparse_tiling_collision(R9_ypos + 6, R9_xpos, R9_xpos + 15);
        if (c != -1) {
            R9_state = 1;
            R9_state_counter = 50;
            score = c;
            update_score = 1;
        }
    } else if (R9_state == 1) {
        // Blinking returning R9
        draw_R9 = R9_state_counter & 8;
        R9_state_counter--;
        if (R9_state_counter == 0) {
            R9_state = 0;
        }
    } else if (R9_state == 2) {
        draw_R9 = 0;
    }

    if (draw_R9) {
        multisprite_display_small_sprite_ex(R9_xpos, R9_ypos, R9, 8, 0, 4, 1);
        if (R9_state & R9_CIRCLE_FIRE) {
            R9_satellite_counter++;
            if (R9_satellite_counter == 5) {
                R9_satellite_counter = 0;
                R9_satellite_state++;
                if (R9_satellite_state == 4) R9_satellite_state = 0;
            }
            gfx = R9_satellite_sequence[X = R9_satellite_state];
            x = R9_xpos + 17;
            y = R9_ypos - 1;
            multisprite_display_sprite_ex(x, y, gfx, 4, 0, 1);
        }
        if ((R9_state & R9_CHARGING) && R9_charging_counter >= 5) {
            gfx = R9_charging_sequence[X = (R9_charging_counter2 >> 2)];
            if (R9_state & R9_CIRCLE_FIRE) {
                x = R9_xpos + 17 + 8;
            } else {
                x = R9_xpos + 16;
            }
            y = R9_ypos + 1;
            multisprite_display_small_sprite_ex(x, y, gfx, 2, 0, 5, 0);
            R9_charging_counter2++;
            if (R9_charging_counter2 == 12) {
                R9_charging_counter2 = 0;
            }
        }
    }
}

void fire()
{
    if (R9_state & R9_CIRCLE_FIRE) {
        X = circle_last++;
        if (circle_last == CIRCLES_NB_MAX) circle_last = 0;
        if (circle_last != circle_first) {
            circle_xpos[X] = R9_xpos + 20;
            circle_ypos[X] = R9_ypos - 10;
            circle_state[X] = 0;
        } else circle_last = X;
    } else {
        X = missile_last++;
        if (missile_last == MISSILES_NB_MAX) missile_last = 0;
        if (missile_last != missile_first) {
            missile_xpos[X] = R9_xpos + 8;
            if (R9_charging_counter >= 16) {
                missile_ypos[X] = R9_ypos;
                missile_type[X] = 1;
            } else {
                missile_ypos[X] = R9_ypos + 6;
                missile_type[X] = 0;
            }
        } else missile_last = X;
    }
}

void beam_meter_update();

void joystick_input()
{
    joystick_update();
    if (joystick[0] & JOYSTICK_LEFT) {
        if (R9_xpos) R9_xpos--;
    } else if (joystick[0] & JOYSTICK_RIGHT) {
        if (R9_xpos < 160 - 16) R9_xpos++;
    }
    if (joystick[0] & JOYSTICK_UP) {
        if (R9_ypos > 2) R9_ypos -= 2;
    } else {
        if (joystick[0] & JOYSTICK_DOWN) {
            if (R9_ypos < 208 - 14) R9_ypos += 2;
        }
    }
    if (joystick[0] & JOYSTICK_BUTTON1) {
        if (button_pressed) {
            if (R9_charging_counter != 32) {
                R9_charging_counter++;
                beam_meter_update();
            }
        } else {
            button_pressed = 1;
            R9_state |= R9_CHARGING;
        }
    } else {
        button_pressed = 0;
        R9_state &= ~R9_CHARGING;
        if (R9_charging_counter != 0 && R9_state != 2) {
            fire();
            R9_charging_counter = 0;
            beam_meter_update();
        }
    }
}

// Background scrolling
ramchip char scroll_background_counter1, scroll_background_counter2;

void scroll_background(char speed)
{
    char c;
    signed char pos1, pos2, pos3, pos4;
    scroll_background_counter1++;
    if (scroll_background_counter1 == speed) {
        scroll_background_counter1 = 0;
        scroll_background_counter2++;
        if (scroll_background_counter2 == 16) scroll_background_counter2 = 0;
    }
    pos1 = -scroll_background_counter2;
    pos2 = pos1 + 80;
    pos3 = pos1 - 8;
    if (pos3 < -16) pos3 += 16;
    pos4 = pos3 + 80;
    if (_ms_buffer) {
        X = _MS_DLL_ARRAY_SIZE + 1;
    } else X = 1;
    
    _ms_tmpptr = _ms_dls[X];
    for (c = 0; c != 3; c++) {
        // Modify bytes 4 and 8 of the DLL entries (x position of background sprites=
        _ms_tmpptr[Y = 4] = pos1;
        _ms_tmpptr[Y = 8] = pos2;
        _ms_tmpptr = _ms_dls[++X];
        _ms_tmpptr[Y = 4] = pos1;
        _ms_tmpptr[Y = 8] = pos2;
        _ms_tmpptr = _ms_dls[++X];
        _ms_tmpptr[Y = 4] = pos3;
        _ms_tmpptr[Y = 8] = pos4;
        _ms_tmpptr = _ms_dls[++X];
        _ms_tmpptr[Y = 4] = pos3;
        _ms_tmpptr[Y = 8] = pos4;
        _ms_tmpptr = _ms_dls[++X];
    }
}

void display_init()
{
    *BACKGRND = 0x0;
    
    multisprite_get_tv();
    multisprite_clear();
    multisprite_save();

    _ms_tmpptr = _ms_b0_dll;
    for (X = 0, _ms_tmp = 0; _ms_tmp <= 1; _ms_tmp++) {
        // Build DLL
        // 69 blank lines for PAL
        // 19 blank lines for NTSC
        if (_ms_pal_detected) {
            // 16 blank lines
            _ms_tmpptr[Y = 0] = 0x0f;  // 16 lines
            _ms_tmpptr[++Y] = _ms_set_wm_dl >> 8;
            _ms_tmpptr[++Y] = _ms_set_wm_dl;
            // 16 blank lines
            _ms_tmpptr[++Y] = 0x0f;  // 16 lines
            _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
            _ms_tmpptr[++Y] = _ms_blank_dl;
        } else {
            _ms_tmpptr[Y = 0] = 0x08; // 9 lines
            _ms_tmpptr[++Y] = _ms_set_wm_dl >> 8;
            _ms_tmpptr[++Y] = _ms_set_wm_dl;
        }
        // 16 pixel high regions (208 pixels = 13 regions)
        for (_ms_tmp2 = 0; _ms_tmp2 != 13; X++, _ms_tmp2++) {
            _ms_tmpptr[++Y] = 0x4f; // 16 lines
            _ms_tmpptr[++Y] = _ms_dls[X] >> 8; // High address
            _ms_tmpptr[++Y] = _ms_dls[X]; // Low address
        }
        // 1 pixel high region to separate from 320A scoreboard. This gives some little room for the DLI to execute
        _ms_tmpptr[++Y] = 0x00; // 1 line
        _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
        _ms_tmpptr[++Y] = _ms_blank_dl;
        // 8 pixel high regions (320A)
        for (_ms_tmp2 = 0; _ms_tmp2 != 2; X++, _ms_tmp2++) {
            _ms_tmpptr[++Y] = 0x07; // 8 lines
            _ms_tmpptr[++Y] = _ms_dls[X] >> 8; // High address
            _ms_tmpptr[++Y] = _ms_dls[X]; // Low address
        }
        X++;
        if (_ms_pal_detected) {
            // 16 blank lines
            _ms_tmpptr[++Y] = 0x0f;  // 16 lines
            _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
            _ms_tmpptr[++Y] = _ms_blank_dl;
            // 16 blank lines
            _ms_tmpptr[++Y] = 0x0f;  // 16 lines
            _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
            _ms_tmpptr[++Y] = _ms_blank_dl;
            // 4 blank lines
            _ms_tmpptr[++Y] = 0x03;  // 4 lines
            _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
            _ms_tmpptr[++Y] = _ms_blank_dl;
        } else {
            _ms_tmpptr[++Y] = 0x08; // 9 lines
            _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
            _ms_tmpptr[++Y] = _ms_blank_dl;
        }
        _ms_tmpptr = _ms_b1_dll;
    }
    multisprite_start();
}

bank1 void rtype_level1_palette()
{
    // Beige palette
    *P4C1 = multisprite_color(0x12); 
    *P4C2 = multisprite_color(0x14); 
    *P4C3 = multisprite_color(0x16); 
    
    // Blue palette
    *P5C1 = multisprite_color(0x84); // Dark blue 
    *P5C2 = multisprite_color(0x87); // Light blue
    *P5C3 = multisprite_color(0xac); // Turquoise 

    // Rose palette
    *P6C1 = multisprite_color(0x34); // Dark Rose
    *P6C2 = multisprite_color(0x38); // Rose 
    *P6C3 = multisprite_color(0x3c); // Light Rose 

    // Grey palette 
    *P7C1 = 0x04; // Dark gray
    *P7C2 = 0x08; // Medium gray
    *P7C3 = 0x0c; // Dark gray
}

// Scoreboard display functions
const char oneup[3] = {27, 'U' - 'A', 'P' - 'A'};
const char high[4] = {'H' - 'A', 'I' - 'A', 'G' - 'A', 'H' - 'A'};
const char beam[4] = {'B' - 'A', 'E' - 'A', 'A' - 'A', 'M' - 'A'};
    
void scoreboard_display()
{
    multisprite_display_sprite_aligned(13 * 4, 13 * 16, beam_meter_in, 1, 1, 0);
    multisprite_display_sprite_aligned(13 * 4, 13 * 16, beam_meter_out, 18, 2, 0);
    multisprite_display_tiles(3 * 4, 14, oneup, 3, 2);
    multisprite_display_tiles(7 * 4, 14, display_score_str, 5, 0);
    multisprite_display_tiles(16 * 4, 14, high, 4, 2);
    multisprite_display_tiles(21 * 4, 14, display_high_score_str, 5, 0);
    multisprite_display_tiles(8 * 4, 13, beam, 4, 2);
}

void beam_meter_update()
{
    char i = (-((R9_charging_counter >> 1) + 1) & 0x1f) | (1 << 5);
    _ms_b0_dl13[X = 3] = i; // 13th zone
    _ms_b1_dl13[X] = i; // on the second buffer
}

void display_score_update(char *score_str)
{
    char display_score_ascii[6];
    itoa(score, display_score_ascii, 10);
    X = strlen(display_score_ascii); 
    for (Y = 0; Y != 5 - X; Y++) {
        score_str[Y] = 26; // '0'
    }
    Y = 4;
    do {
        score_str[Y--] = 26 + (display_score_ascii[--X] - '0');
    } while (X);
}

void rtype_init()
{
    rtype_level1_palette(); // In bank1, so that everything thet follow is in bank1 also
    sparse_tiling_init_vmem(tilemap_level1_data_ptrs, brown_tiles1);
    multisprite_set_charbase(alphabet);

    // Sprites palette
    // Fire
    *P0C1 = multisprite_color(0x37); // Orange
    *P0C2 = multisprite_color(0x1c); // Yellow 
    *P0C3 = 0x0f; // White
    
    // Blue & Red palette
    *P1C1 = multisprite_color(0x84); // Dark blue 
    *P1C2 = multisprite_color(0x34); // Red
    *P1C3 = multisprite_color(0xac); // Turquoise 

    // Grey palette
    *P2C1 = 0x04; // Dark gray
    *P2C2 = 0x08; // Medium gray
    *P2C3 = 0x0c; // Dark gray

    // Green (background) color 
    *P3C1 = multisprite_color(0xd0); 
    *P3C2 = multisprite_color(0xd2); 
    *P3C3 = multisprite_color(0xd1); 
   
    // Background display
    char c, y = 0;
    for (c = 0; c != 3; c++) {
        y += 16;
        multisprite_display_sprite_ex(0, y, background_level1, 20, 3, 0);
        multisprite_display_sprite_fast(80, y, background_level1, 24, 3);
        y += 16;
        multisprite_display_sprite_ex(0, y, background_level1_1, 20, 3, 0);
        multisprite_display_sprite_fast(80, y, background_level1_1, 24, 3);
        y += 16;
        multisprite_display_sprite_ex(-8, y, background_level1, 20, 3, 0);
        multisprite_display_sprite_fast(72, y, background_level1, 24, 3);
        y += 16;
        multisprite_display_sprite_ex(-8, y, background_level1_1, 20, 3, 0);
        multisprite_display_sprite_fast(72, y, background_level1_1, 24, 3);
    }

    scoreboard_display();
    // Save it
    multisprite_save();

    multisprite_enable_dli(13);
    
    sparse_tiling_display();
    multisprite_flip();
    sparse_tiling_scroll(1); // Offset of 1 compared to previous screen
    sparse_tiling_display();
    multisprite_flip();
}

void background_fade1()
{
    *P3C1 = multisprite_color(0x00); 
    *P3C2 = multisprite_color(0xd1); 
    *P3C3 = multisprite_color(0xd0); 
}

void background_fade2()
{
    *P3C1 = multisprite_color(0x00); 
    *P3C2 = multisprite_color(0xd0); 
    *P3C3 = multisprite_color(0x00); 
}

#define DOBKERATOPS_GETS_IN (((64 * 8) + 160) / 32) 

// DLI management
ramchip char save_acc, save_x, save_y;
ramchip char dli_counter;

void interrupt dli()
{
    store(save_acc);
    save_x = X;
    save_y = Y;
    if (level_progress_high >= DOBKERATOPS_GETS_IN) {
        if (dli_counter == 0) {
            // Switch to dobkeratops palette    
            if (_ms_pal_detected) {
                *P4C1 = 0x4c; 
                *P4C2 = 0x49; 
                *P4C3 = 0x46; 
                *P5C1 = 0x34; 
                *P5C2 = 0x32; 
                *P7C1 = 0xd9; 
                *P7C2 = 0xd6; 
                *P7C3 = 0x53; // Red (unused)
            } else {
                *P4C1 = 0x3c; 
                *P4C2 = 0x39; 
                *P4C3 = 0x36; 
                *P5C1 = 0x24; 
                *P5C2 = 0x22; 
                *P7C1 = 0xc9; 
                *P7C2 = 0xc6; 
                *P7C3 = 0x43; // Red (unused)
            }
            *P5C3 = 0x0e; 
            *P6C1 = 0x0a; 
            *P6C2 = 0x04; 
            *P6C3 = 0x02; 
        } else if (dli_counter == 1) {
            // Switch to level1 palette
            if (_ms_pal_detected) {
                // Beige palette
                *P4C1 = 0x22; 
                *P4C2 = 0x24; 
                *P4C3 = 0x26; 
                // Blue palette
                *P5C1 = 0x94; // Dark blue 
                *P5C2 = 0x97; // Light blue
                *P5C3 = 0xbc; // Turquoise 
                              // Rose palette
                *P6C1 = 0x44; // Dark Rose
                *P6C2 = 0x48; // Rose 
                *P6C3 = 0x4c; // Light Rose 
            } else {
                // Beige palette
                *P4C1 = 0x12; 
                *P4C2 = 0x14; 
                *P4C3 = 0x16; 
                // Blue palette
                *P5C1 = 0x84; // Dark blue 
                *P5C2 = 0x87; // Light blue
                *P5C3 = 0xac; // Turquoise 
                              // Rose palette
                *P6C1 = 0x34; // Dark Rose
                *P6C2 = 0x38; // Rose 
                *P6C3 = 0x3c; // Light Rose 
            }
            // Grey palette 
            *P7C1 = 0x04; // Dark gray
            *P7C2 = 0x08; // Medium gray
            *P7C3 = 0x0c; // Dark gray
        } else {
            *CTRL = 0x43; // DMA on, 320A/C mode, One (1) byte characters mode
        }
    } else {
        *CTRL = 0x43; // DMA on, 320A/C mode, One (1) byte characters mode
    }
    dli_counter++;
    X = save_x;
    Y = save_y;
    load(save_acc);
}

void main()
{
    dli_counter = 0;
    scroll_background_counter1 = 0;
    scroll_background_counter2 = 0;
    button_pressed = 0;

    copy_dobkeratops_to_ram();
    joystick_init();
    display_init();
    rtype_init();
    game_init();

    do {
        if (level_progress_high < DOBKERATOPS_GETS_IN) {
            scroll_background(4);
            sparse_tiling_scroll(1); // Scroll 1 pixels to the right for this buffer (so 0.5 pixel from frame to frame due to double buffering)
            level_progress_low++;
            if (level_progress_low == 32) {
                level_progress_high++;
                if (level_progress_high == DOBKERATOPS_GETS_IN - 4) {
                    background_fade1();
                } else if (level_progress_high == DOBKERATOPS_GETS_IN - 2) {
                    background_fade2();
                }
                level_progress_low = 0;
            }
        } /*else {
            char c = sparse_tiling_collision(208 - 14 + 6, 0, 15);
            if (c != -1) {
                score = 1000 + c;
                update_score = 1;
            }
        } */
        else {
            if (level_progress_low == 0) {
                if (level_progress_high == DOBKERATOPS_GETS_IN) {
                    multisprite_enable_dli(1);
                    multisprite_enable_dli(12);
                    multisprite_clear();
                    scoreboard_display();
                    multisprite_save();
                    sparse_tiling_scroll(1); // Scroll 1 pixels to the right to align this buffer to the next 
                    sparse_tiling_display();
                    multisprite_flip();
                    sparse_tiling_display();
                }
            }
            char x = 180 + DOBKERATOPS_GETS_IN - level_progress_high;
            draw_dobkeratops(x, 16, counter_tail);
            counter_tail++;
            if (counter_tail == 60) counter_tail = 0;
            if (level_progress_high < 114) {
                level_progress_low++;
                if (level_progress_low == 4) {
                    level_progress_high++;
                    level_progress_low = 0;
                }
            }
        }
        joystick_input();
        step();
        if (update_score) {
            display_score_update(display_score_str);
            if (score >= high_score) {
                high_score = score;
                display_score_update(display_high_score_str);
            }
            update_score = 0;
        }
        multisprite_flip();
        dli_counter = 0;
        *CTRL = 0x50; // DMA on, 160A/B mode, Two (2) byte characters mode
    } while (1);
}