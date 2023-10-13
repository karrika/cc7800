#include "prosystem.h"
#define _MS_TOP_SCROLLING_ZONE 1
#define VERTICAL_SCROLLING
#define INIT_BANK bank7
#include "multisprite.h"
#include "joystick.h"
#include "string.h"
#ifdef POKEY_MUSIC 
#include "rmtplayer.h"
#include "example_shmup_music.asm"
#endif
#include "sfx.h"

// Generated by sprites7800 shmup_tiles.png
#include "example_shmup_tiles.c"

// Generated by tiles7800 --sparse shmup_tiles.yaml shump.tmx
#include "example_shmup_tilesets.c"

// Generated by sprites7800 shmup.yaml
#include "example_shmup_sprites.c"

const signed short dx[48] = {300, 289, 259, 212, 149, 77, 0, -77, -150, -212, -259, -289, -300, -289, -259, -212, -149, -77, 0, 77, 149, 212, 259, 289, 450, 434, 389, 318, 224, 116, 0, -116, -225, -318, -389, -434, -450, -434, -389, -318, -224, -116, 0, 116, 224, 318, 389, 434};
const signed short dy[48] = {0, 124, 240, 339, 415, 463, 480, 463, 415, 339, 240, 124, 0, -124, -239, -339, -415, -463, -480, -463, -415, -339, -240, -124, 0, 186, 360, 509, 623, 695, 720, 695, 623, 509, 360, 186, 0, -186, -359, -509, -623, -695, -720, -695, -623, -509, -360, -186};

const char sfx_pewpew[66] = {
	0x10, 0, 0x00, 0x1c, 0x04, 0x0f, 0x1c, 0x04, 0x0f, 0x09, 0x04, 0x0b, 0x03, 0x0c, 0x0a, 0x04,
	0x0c, 0x0e, 0x12, 0x04, 0x0c, 0x19, 0x04, 0x0f, 0x1c, 0x04, 0x0f, 0x07, 0x04, 0x05, 0x09, 0x04,
	0x05, 0x0d, 0x04, 0x06, 0x0c, 0x04, 0x05, 0x18, 0x04, 0x06, 0x1c, 0x04, 0x05, 0x1e, 0x04, 0x03,
	0x07, 0x04, 0x03, 0x09, 0x04, 0x03, 0x0c, 0x04, 0x02, 0x04, 0x0c, 0x02, 0x06, 0x0c, 0x01, 0x00,
	0x00, 0x00
};

const char sfx_bigboom[261] = {
	0x10, 1, 0x00, 0x1d, 0x07, 0x0f, 0x1e, 0x06, 0x0f, 0x00, 0x06, 0x0f, 0x14, 0x07, 0x0f, 0x13,
	0x0f, 0x0f, 0x1b, 0x07, 0x0f, 0x0e, 0x07, 0x0f, 0x1b, 0x07, 0x0f, 0x0f, 0x07, 0x0f, 0x10, 0x07,
	0x0f, 0x10, 0x06, 0x0f, 0x16, 0x07, 0x0f, 0x0d, 0x0f, 0x0f, 0x1e, 0x0c, 0x0f, 0x16, 0x01, 0x0f,
	0x17, 0x01, 0x0f, 0x10, 0x07, 0x0f, 0x10, 0x0f, 0x0f, 0x15, 0x07, 0x0d, 0x1a, 0x07, 0x0f, 0x1a,
	0x01, 0x0f, 0x1a, 0x07, 0x0f, 0x14, 0x0f, 0x0f, 0x16, 0x07, 0x0f, 0x16, 0x07, 0x0f, 0x15, 0x07,
	0x0f, 0x17, 0x07, 0x0f, 0x13, 0x0f, 0x0f, 0x13, 0x0f, 0x0f, 0x19, 0x0f, 0x0f, 0x18, 0x07, 0x0c,
	0x0b, 0x06, 0x0c, 0x1e, 0x01, 0x0d, 0x10, 0x01, 0x0d, 0x14, 0x07, 0x0f, 0x16, 0x06, 0x0c, 0x17,
	0x07, 0x0c, 0x1a, 0x01, 0x0c, 0x12, 0x06, 0x0d, 0x17, 0x07, 0x0c, 0x0b, 0x0f, 0x0c, 0x19, 0x07,
	0x09, 0x19, 0x07, 0x0b, 0x0b, 0x0f, 0x09, 0x0d, 0x0e, 0x0b, 0x0d, 0x0e, 0x0b, 0x19, 0x0f, 0x09,
	0x0e, 0x0f, 0x06, 0x1b, 0x0c, 0x08, 0x18, 0x0f, 0x08, 0x13, 0x07, 0x05, 0x1a, 0x01, 0x05, 0x17,
	0x0f, 0x08, 0x16, 0x06, 0x08, 0x0c, 0x06, 0x05, 0x1c, 0x0f, 0x06, 0x16, 0x06, 0x08, 0x0b, 0x06,
	0x06, 0x12, 0x06, 0x04, 0x0f, 0x0f, 0x05, 0x11, 0x07, 0x06, 0x09, 0x06, 0x05, 0x10, 0x06, 0x05,
	0x10, 0x06, 0x05, 0x10, 0x06, 0x05, 0x11, 0x0f, 0x04, 0x15, 0x0f, 0x04, 0x1e, 0x07, 0x05, 0x16,
	0x01, 0x04, 0x16, 0x01, 0x04, 0x1a, 0x0f, 0x04, 0x19, 0x0f, 0x02, 0x1e, 0x0f, 0x02, 0x1b, 0x0f,
	0x02, 0x1e, 0x0f, 0x02, 0x1c, 0x0f, 0x02, 0x0d, 0x0f, 0x01, 0x0f, 0x06, 0x02, 0x0e, 0x06, 0x01,
	0x18, 0x0f, 0x01, 0x0b, 0x06, 0x02, 0x16, 0x0f, 0x01, 0x17, 0x0f, 0x01, 0x13, 0x06, 0x01, 0x0f,
	0x0e, 0x01, 0x00, 0x00, 0x00
};

#define ENEMY_NB_MAX 10
#define ENEMY_BIG 128
#define ENEMY_HIT 128
const char enemy_width[1] = { 24 };
const char enemy_height[1] = { 48 };
ramchip char enemy_xpos[ENEMY_NB_MAX], enemy_ypos[ENEMY_NB_MAX], enemy_type[ENEMY_NB_MAX], enemy_state[ENEMY_NB_MAX], enemy_lives[ENEMY_NB_MAX], enemy_counter1[ENEMY_NB_MAX], enemy_counter2[ENEMY_NB_MAX];
ramchip char enemy_first, enemy_last;

#define BULLETS_NB_MAX 32 
ramchip short bullet_xpos[BULLETS_NB_MAX], bullet_ypos[BULLETS_NB_MAX];
ramchip char bullet_direction[BULLETS_NB_MAX];
ramchip char bullet_first, bullet_last;

#define EXPLOSIONS_NB_MAX 16 
ramchip short explosion_xpos[EXPLOSIONS_NB_MAX], explosion_ypos[EXPLOSIONS_NB_MAX];
ramchip char explosion_direction[EXPLOSIONS_NB_MAX];
ramchip char explosion_counter[EXPLOSIONS_NB_MAX];
ramchip char explosion_first, explosion_last;

#define BIG_EXPLOSIONS_NB_MAX 4
ramchip char big_explosion_xpos[BIG_EXPLOSIONS_NB_MAX], big_explosion_ypos[BIG_EXPLOSIONS_NB_MAX];
ramchip char big_explosion_counter[BIG_EXPLOSIONS_NB_MAX];
ramchip char big_explosion_first, big_explosion_last;

#define MISSILES_SPEED 16 
#define MISSILES_NB_MAX 5
ramchip char missile_xpos[MISSILES_NB_MAX], missile_ypos[MISSILES_NB_MAX];
ramchip char missile_first, missile_last;

ramchip char button_pressed;
ramchip char exhaust_state;
ramchip char spaceship_xpos, spaceship_ypos, spaceship_state, spaceship_state_counter; 
ramchip char scrolling_counter, scrolling_done;

ramchip char game_state;
#define STATE_RUNNING  0
#define STATE_GAMEOVER 1
ramchip char music_on;
ramchip char nb_lives;
ramchip int score;
ramchip char update_score;
ramchip char display_score_str[5];

void display_score_update()
{
    char display_score_ascii[6];
    itoa(score, display_score_ascii, 10);
    Y = strlen(display_score_ascii); 
    for (X = 0; X != 5 - Y; X++) {
        display_score_str[X] = 0; // '0'
    }
    X = 4;
    do {
        display_score_str[X--] = ((display_score_ascii[--Y] - '0') << 1);
    } while (Y);
}

ramchip char save_acc, save_x, save_y;

void interrupt dli()
{
    store(save_acc);
    save_x = X;
    save_y = Y;
#ifdef MULTISPRITE_USE_VIDEO_MEMORY
    multisprite_set_charbase(digits);
#else
    multisprite_set_charbase(blue_objects1);
#endif
#ifdef POKEY_MUSIC 
    if (music_on) asm("JSR rmt_play", 3);
#endif
    sfx_play();
    if (multisprite_pal_frame_skip())
        sfx_play(); // Advance twice every 5 frames (to cope with 60Hz instead of 50Hz)
    X = save_x;
    Y = save_y;
    load(save_acc);
}

INIT_BANK new_game()
{
    // Init game state variables
    missile_first = 0;
    missile_last = 0;
    exhaust_state = 0;
    scrolling_done = 0;
    scrolling_counter = 255;

    // Initialize bullets
    bullet_first = 0;
    bullet_last = 0;

    // Initialize enemy 
    enemy_first = 0;
    enemy_last = 0;

    // Initialize explosions
    explosion_first = 0;
    explosion_last = 0;
    big_explosion_first = 0;
    big_explosion_last = 0;

    // Initialize spaceship state
    spaceship_xpos = 80 - 6;
    spaceship_ypos = 180;
    exhaust_state = 0;
    spaceship_state = 0;
     
    nb_lives = 3;
    score = 0;
    update_score = 1;

    game_state = STATE_RUNNING;
    
    // Screen clear
    multisprite_clear();
    // Score display
    display_score_update();
    multisprite_display_tiles(0, 0, display_score_str, 5, 2);
    multisprite_save();
}

INIT_BANK void init()
{
    sfx_init();

    multisprite_init();
#ifndef MULTISPRITE_USE_VIDEO_MEMORY
    multisprite_set_charbase(blue_objects1);
#endif
    joystick_init();
    button_pressed = 0;

    // Grey palette
    *P0C1 = 0x04;
    *P0C2 = 0x08;
    *P0C3 = 0x0b;

    // Blue palette
    *P1C1 = multisprite_color(0x84); // Dark blue 
    *P1C2 = multisprite_color(0x87); // Light blue
    *P1C3 = multisprite_color(0xac); // Turquoise 

    // Green palette
    *P2C1 = multisprite_color(0xd4); // Dark green 
    *P2C2 = multisprite_color(0xd8); // Light green
    *P2C3 = 0x0e; 
    
    // Fire palette
    *P3C1 = multisprite_color(0x43); // Red
    *P3C2 = multisprite_color(0x37); // Orange
    *P3C3 = multisprite_color(0x1c); // Yellow 

    // Yellow palette (bright)
    *P4C1 = multisprite_color(0x19); // Yellow (dark)
    *P4C2 = multisprite_color(0x1c); // Yellow
    *P4C3 = multisprite_color(0x1f); // Yellow (bright) 

    // Blue palette
    *P5C1 = multisprite_color(0x54); // Dark purple 
    *P5C2 = multisprite_color(0x57); // Light purple
    *P5C3 = multisprite_color(0x5c); // Rose 

    // Green palette
    *P6C1 = multisprite_color(0xda); // Light green 
    *P6C2 = multisprite_color(0xdd); // Very light green
    *P6C3 = 0x0f; 
    
    // Fire palette (with white)
    *P7C1 = multisprite_color(0x44); // Red
    *P7C2 = multisprite_color(0x38); // Orange
    *P7C3 = 0x0f; // White 

    new_game();
}

void enemy_destroyed(char i)
{
    X = i;
    enemy_state[X] = -1; // Removed
    do {
        X++;
        if (X == ENEMY_NB_MAX) X = 0;
    } while (X != enemy_last && enemy_state[X] == -1);
    enemy_first = X;
}

void enemy_shoot(char x, char y, char direction)
{
    X = bullet_last++;
    if (bullet_last == BULLETS_NB_MAX) bullet_last = 0;
    if (bullet_last != bullet_first) {
        bullet_xpos[X] = x << 8;
        bullet_ypos[X] = y << 8;
        bullet_direction[X] = direction;
    } else bullet_last = X;
}

void explosion(char x, char y, char dir)
{
    X = explosion_last++;
    if (explosion_last == EXPLOSIONS_NB_MAX) explosion_last = 0;
    if (explosion_last != explosion_first) {
        explosion_xpos[X] = x << 8;
        explosion_ypos[X] = y << 8;
        explosion_direction[X] = dir;
        explosion_counter[X] = 0;
    } else explosion_last = X;
}

void big_explosion(char x, char y)
{
    sfx_schedule(sfx_bigboom);
    char i, xp = x - 4, yp = y - 8;
    for (i = 25; i < 48; i += 3) {
        explosion(xp, yp, i);
    }
    xp = x - 12;
    yp = y - 24;
    if (yp < 0) yp = 0; else if (yp >= 224 - 16 - 49) yp = 224 - 16 - 50;
    X = big_explosion_last++;
    if (big_explosion_last == BIG_EXPLOSIONS_NB_MAX) big_explosion_last = 0;
    if (big_explosion_last != big_explosion_first) {
        big_explosion_xpos[X] = xp;
        big_explosion_ypos[X] = yp;
        big_explosion_counter[X] = 20;
    } else big_explosion_last = X;
}

bank1 void spawn_boss()
{
    X = enemy_last++;
    if (enemy_last == ENEMY_NB_MAX) enemy_last = 0;
    if (enemy_last != enemy_first) {
        enemy_xpos[X] = -24;
        enemy_ypos[X] = 10;
        enemy_type[X] = ENEMY_BIG;
        enemy_state[X] = 0;
        enemy_lives[X] = 10;
        enemy_counter1[X] = 0;
        enemy_counter2[X] = 0;
    } else enemy_last = X;
}

bank1 void start_level1()
{
    // Init level 1 music (in bank1)
#ifdef POKEY_MUSIC
    // Init RMT music
    asm("LDX #<RMTSTART", 2); // Give pointer to RMT music
    asm("LDY #>RMTSTART", 2);
    load(0); // Song line in A register 
    asm("JSR rmt_init", 3);
#endif
#ifdef MULTISPRITE_USE_VIDEO_MEMORY
    multisprite_vscroll_init_sparse_tiles_vmem(tilemap_data_ptrs, blue_objects1);
#else
    multisprite_vscroll_init_sparse_tiles(tilemap_data_ptrs);
#endif
    spawn_boss();
    music_on = 1;
}

void display_boss(char x, char y, char palette)
{
    multisprite_display_big_sprite(x, y, boss, 12, palette, 3, 1);
}

bank1 void draw_enemies()
{
    int i, x, y, palette;
    for (i = enemy_first; i != enemy_last; i++) {
        if (i == ENEMY_NB_MAX) {
            i = 0; if (enemy_last == 0) break;
        }
        X = i;
        if (enemy_type[X] != -1) {
            if (enemy_type[X] & ENEMY_BIG) {
                // This is our big ship
                palette = 0;
                if (enemy_state[X] & ENEMY_HIT) {
                    // Hit
                    palette = 4;
                    enemy_state[X] &= ~ENEMY_HIT;
                    enemy_lives[X]--;
                    score += 10;
                    update_score = 1;
                    if (enemy_lives[X] == 0) {
                        // Destruction
                        score += 1000;
                        big_explosion(enemy_xpos[X] + 12, enemy_ypos[X] + 24);
                        enemy_destroyed(i);
                        spawn_boss();
                        continue;
                    }
                }
                if (enemy_state[X] == 0) {
                    enemy_xpos[X] += 2;
                    if (enemy_xpos[X] >= 100 && enemy_xpos[X] < 160) {
                        enemy_state[X] = 1;
                    }
                } else if (enemy_state[X] == 1) {
                    enemy_xpos[X]--;
                    if (enemy_xpos[X] < 160 - 124) {
                        enemy_state[X] = 2;
                    }
                } else if (enemy_state[X] == 2) {
                    enemy_xpos[X]++;
                    if (enemy_xpos[X] > 100) {
                        enemy_state[X] = 1;
                    }
                }
                x = enemy_xpos[X];
                y = enemy_ypos[X];
                // Shoot
                enemy_counter1[X]++;
                if (enemy_counter1[X] == 5) { // Shoots 12 times par second
                    enemy_counter1[X] = 0;
                    enemy_counter2[X]++;
                    if (enemy_counter2[X] == 8) enemy_counter2[X] = 0;
                    char direction;
                    if (enemy_counter2[X] < 5) direction = 4 + enemy_counter2[X];
                    else direction = 12 - enemy_counter2[X];
                    //sfx_schedule(sfx_plainlaser);
                    enemy_shoot(x + 10, y + 40, direction);
                }
                display_boss(x, y, palette);
            }
        }
    }
}

void fire()
{
    sfx_schedule(sfx_pewpew);
    X = missile_last++;
    if (missile_last == MISSILES_NB_MAX) missile_last = 0;
    if (missile_last != missile_first) {
        missile_xpos[X] = spaceship_xpos;
        missile_ypos[X] = spaceship_ypos + 16;
    } else missile_last = X;
}

void joystick_input()
{
    joystick_update();
    if (joystick[0] & JOYSTICK_LEFT) {
        if (spaceship_xpos) spaceship_xpos--;
    } else if (joystick[0] & JOYSTICK_RIGHT) {
        if (spaceship_xpos < 160 - 13) spaceship_xpos++;
    }
    if (joystick[0] & JOYSTICK_UP) {
        if (spaceship_ypos > 2) spaceship_ypos -= 2;
        exhaust_state++;
        if (exhaust_state == 13) exhaust_state = 10; 
    } else {
        exhaust_state = 0;
        if (joystick[0] & JOYSTICK_DOWN) {
            if (spaceship_ypos < 224 - 33 - 16) spaceship_ypos += 2;
        }
    }
    if (joystick[0] & JOYSTICK_BUTTON1) {
        if (!button_pressed) {
            button_pressed = 1;
            if (game_state == STATE_GAMEOVER) {
                music_on = 0; // Shut down pokey before going to bank7
                new_game();
                start_level1();
            } else if (spaceship_state != 2) fire();
        }
    } else button_pressed = 0;
}

char missile_management(char x, char y) {
    char i, exploded = 0;
    multisprite_display_sprite_aligned(x, y, missiles, 3, 3, 0);
    // Check collision with enemies
    for (i = enemy_first; i != enemy_last; i++) {
        if (i == ENEMY_NB_MAX) {
            i = 0; if (enemy_last == 0) break;
        }
        X = i;
        if (enemy_type[X] != -1) {
            char xe, ye;
            xe = enemy_xpos[X];
            ye = enemy_ypos[X];
            if (enemy_type[X] & ENEMY_BIG) {
                Y = enemy_type[X] & 0x7f;
                multisprite_compute_box_collision(xe, ye, enemy_width[Y], enemy_height[Y], x, y, 12, 16);
            } else {
                multisprite_compute_box_collision(xe, ye, 8, 16, xe, ye, 12, 16);
            }
            if (multisprite_collision_detected) {
                exploded = 1;
                enemy_state[X] |= ENEMY_HIT;
            }
        }
    }
    return exploded;
}

void draw_gameover()
{
    char i, x, xx = (spaceship_state_counter << 1), *ptr;
    // Draw the skull in the middle of the screen
    multisprite_display_big_sprite((80 - 16), ((224 - 16 - 48 - 48) / 2), skull, 8, 0, 3, 0);
    x = xx - 36;
    ptr = game;
    for (i = 0; i != 2; i++) {
        multisprite_display_sprite_ex(x, ((224 - 16 - 16) / 2), ptr, 9, 7, 0);
        ptr = over;
        x = 160 - xx;
    }
    spaceship_state_counter++;
    if (spaceship_state_counter == 41) {
        spaceship_state_counter = 40;
        game_state = STATE_GAMEOVER;
    }
}

void step()
{
    char x, y, i;
    // Draw missiles
    for (i = missile_first; i != missile_last; i++) {
        if (i == MISSILES_NB_MAX) {
            i = 0;
            if (missile_last == 0) break;
        }
        X = i;
        x = missile_xpos[X];
        if (x != -1) {
            y = missile_ypos[X] - MISSILES_SPEED;
            if (y < 0) {
                // Out of screen
                missile_xpos[X] = -1; // Removed
                do {
                    X++;
                    if (X == MISSILES_NB_MAX) X = 0;
                } while (X != missile_last && missile_xpos[X] == -1);
                missile_first = X;
            } else {
                missile_ypos[X] = y;
                if (missile_management(x, y)) {
                    X = i;
                    if (X == missile_first) {
                        missile_xpos[X] = -1; // Removed
                        do {
                            X++;
                            if (X == MISSILES_NB_MAX) X = 0;
                        } while (X != missile_last && missile_xpos[X] == -1);
                        missile_first = X;
                    }
                }
            }
        }
    }

    char draw_spaceship;
    if (spaceship_state == 0) {
        draw_spaceship = 1;
    } else if (spaceship_state == 1) {
        // Blinking returning spaceship
        draw_spaceship = spaceship_state_counter & 8;
        spaceship_state_counter--;
        if (spaceship_state_counter == 0) {
            spaceship_state = 0;
        }
    } else if (spaceship_state == 2) {
        draw_spaceship = 0;
    }

    if (draw_spaceship) {
        multisprite_display_big_sprite(spaceship_xpos, spaceship_ypos, spaceship, 6, 0, 2, 1);
        // Draw exhaust
        if (exhaust_state > 0 && spaceship_ypos < 224 - 25 - 32) {
            char x, y;
            y = spaceship_ypos + 24;
            if (exhaust_state < 10) {
                x = spaceship_xpos + 2;
                multisprite_display_small_sprite_ex(x, y, exhauststart, 2, 3, 0);
            } else {
                char *gfxptr;
                i = exhaust_state - 10;
                gfxptr = exhaust1 + i;
                x = spaceship_xpos + 4;
                multisprite_display_sprite_ex(x, y, gfxptr, 1, 3, 0);
            }
        }
    }

    // Draw evil guys
    draw_enemies();
   
    // Display small explosions
    for (i = explosion_first; i != explosion_last; i++) {
        char xexplosion, yexplosion;
        if (i == EXPLOSIONS_NB_MAX) {
            i = 0;
            if (explosion_last == 0) break;
        }
        X = i;
        Y = explosion_direction[X];
        if (Y != 255) {
            explosion_xpos[X] += dx[Y];
            explosion_ypos[X] += dy[Y];
            xexplosion = explosion_xpos[X] >> 8;
            yexplosion = explosion_ypos[X] >> 8;
            if (explosion_counter[X] >= 120 || xexplosion < 5 || xexplosion >= 156 || yexplosion < 5 || yexplosion >= MS_YMAX - 20 - 16) {
                explosion_direction[X] = 255; // Removed
                if (X == explosion_first) {
                    do {
                        X++;
                        if (X == EXPLOSIONS_NB_MAX) X = 0;
                    } while (X != explosion_last && explosion_direction[X] == 255);
                    explosion_first = X;
                }
            } else {
                char *gfx;
                explosion_counter[X]++;
                if (explosion_counter[X] < 10) gfx = small_explosion1;
                else if (explosion_counter[X] < 20) gfx = small_explosion2;
                else gfx = small_explosion3;
                multisprite_display_sprite_ex(xexplosion, yexplosion, gfx, 2, 3, 0); 
            }
        }
    }

    // Display big explosions
    for (i = big_explosion_first; i != big_explosion_last; i++) {
        char xbig_explosion, ybig_explosion;
        if (i == BIG_EXPLOSIONS_NB_MAX) {
            i = 0;
            if (big_explosion_last == 0) break;
        }
        X = i;
        if (big_explosion_counter[X]) {
            char *gfx;
            xbig_explosion = big_explosion_xpos[X];
            ybig_explosion = big_explosion_ypos[X];
            big_explosion_counter[X]--;
            if (big_explosion_counter[X] >= 16) {
                gfx = explosion1;
            } else if (big_explosion_counter[X] >= 12) {
                gfx = explosion2;
            } else if (big_explosion_counter[X] >= 8) {
                gfx = explosion3;
            } else if (big_explosion_counter[X] >= 4) {
                gfx = explosion4;
            } else gfx = explosion5;
            multisprite_display_big_sprite(xbig_explosion, ybig_explosion, gfx, 6, 3, 3, 0);
        } else {
            if (X == big_explosion_first) {
                do {
                    X++;
                    if (X == EXPLOSIONS_NB_MAX) X = 0;
                } while (X != big_explosion_last && big_explosion_counter[X] == 0);
                big_explosion_first = X;
            }
        }
    }

    if (spaceship_state != 2) {
        // Draw bullets (last, so if there is a DMA issue, it doesn't prevent spaceships to be displayed)
        for (i = bullet_first; i != bullet_last; i++) {
            char xbullet, ybullet;
            if (i == BULLETS_NB_MAX) {
                i = 0;
                if (bullet_last == 0) break;
            }
            X = i;
            Y = bullet_direction[X];
            if (Y != 255) {
                bullet_xpos[X] += dx[Y];
                bullet_ypos[X] += dy[Y];
                xbullet = bullet_xpos[X] >> 8;
                ybullet = bullet_ypos[X] >> 8;
                if (xbullet < 5 || xbullet >= 156 || ybullet < 5 || ybullet >= MS_YMAX - 20 - 16) {
                    bullet_direction[X] = 255; // Removed
                    if (X == bullet_first) {
                        do {
                            X++;
                            if (X == BULLETS_NB_MAX) X = 0;
                        } while (X != bullet_last && bullet_direction[X] == 255);
                        bullet_first = X;
                    }
                } else {
                    multisprite_display_small_sprite_ex(xbullet, ybullet, bullet, 1, 3, 0); 
                    if (spaceship_state == 0) {
                        multisprite_compute_collision(xbullet, ybullet, 4, 8, spaceship_xpos, spaceship_ypos, 12, 24, collision_bullet_spaceship);
                        if (multisprite_collision_detected) {
                            // Explosion
                            nb_lives--;
                            big_explosion(spaceship_xpos + 6, spaceship_ypos + 12);
                            if (nb_lives) {
                                spaceship_state = 1;
                                spaceship_state_counter = 100;
                            } else {
                                spaceship_state = 2;
                            }
                        }
                    } 
                }
            }
        }
    } else draw_gameover();
}

void main()
{
    init();
    
    start_level1();

    multisprite_enable_dli(1);

    // Main loop
    do {
#ifdef MULTISPRITE_USE_VIDEO_MEMORY
        multisprite_vscroll_buffer_sparse_tiles_vmem_step();
        multisprite_vscroll_buffer_sparse_tiles_vmem_step();
#endif
        // Prepare scrolling data
        if (multisprite_vscroll_buffer_empty()) {
            if (!scrolling_done) {
#ifdef MULTISPRITE_USE_VIDEO_MEMORY
                multisprite_vscroll_buffer_sparse_tiles_vmem(scrolling_counter);
#else
                multisprite_vscroll_buffer_sparse_tiles(scrolling_counter);
#endif
                if (scrolling_counter) scrolling_counter--; else scrolling_done = 1; 
            } else if (scrolling_done == 1) {
#ifdef MULTISPRITE_USE_VIDEO_MEMORY
                multisprite_vscroll_buffer_sparse_tiles_vmem(255);
#else
                multisprite_vscroll_buffer_sparse_tiles(255);
#endif
                scrolling_done = 2;
            } else scrolling_done = 3;
        }

        joystick_input();
        step();
        if (update_score) {
            display_score_update();
            update_score = 0;
        }

        {
            char nb_bytes = nb_lives << 2;
            multisprite_display_sprite_top(160 - 24, 0, lives, nb_bytes, 0, 1);
        }
        
        multisprite_flip();
#ifndef MULTISPRITE_USE_VIDEO_MEMORY
        multisprite_set_charbase(digits); // To display the score
#endif
        if (scrolling_done != 3) multisprite_vertical_scrolling(2);
    } while(1);
}
