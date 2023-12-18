bank1 char dobkeratops_ram[4096]; // Should be at 0x7000 after VRAM (12kB at 0x4000)

// Generated by sprites7800 dobkeratops.yaml
#include "example_dobkeratops_gfx_banked.c"

bank1 {
#include "example_dobkeratops_tail.c"
// Generated by 
// rustc misc/dobkeratops_tail.rs -o dokeratops_tail
// ./dobkeratops_tail > examples/example_dobkeratops_tail.c
const char dobkeratops_x[] = {0, 0, 6, 6, 37, 35, 37, 37, 40, 25, 0};
const char dobkeratops_y[] = {0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160};
const char dobkeratops_nbbytes[] = {32, 32, 24, 32, 16, 19, 18, 19, 17, 19, 28};
const char *dobkeratops_gfx[] = {dob1, dob2, dob3, dob4, dob5, dob6, dob7, dob8, dob9, dob10, dob11};

char check_dob_collision(char xt, char yt, char hurt)
{
    char i, c, x, y, h = 0; 
    // Check collision with missiles
    for (i = missile_first, c = nb_missiles; c != 0; i++, c--) {
        if (i == MISSILES_NB_MAX) {
            i = 0;
        }
        if (missile_xpos[X = i] != -1) {
            y = missile_ypos[X = i];
            x = missile_xpos[X];
            if (missile_type[X]) { // Big missile
                multisprite_compute_box_collision(xt, yt, 8, 32, x, y, 32, 16);
            } else {
                multisprite_compute_box_collision(xt, yt, 8, 32, x, y, 8, 4);
            }
            if (multisprite_collision_detected) {
                destroy_missile();
                if (hurt) {
                    if (missile_type[X]) { // Big missile
                        h = 5;
                    } else {
                        h = 1;
                    }
                }
            }
        }
    }

    // Check collisions with circles
    for (i = circle_first, c = nb_circles; c != 0; i++, c--) {
        if (i == CIRCLES_NB_MAX) {
            i = 0;
        }
        if (circle_xpos[X = i] != -1) {
            y = circle_ypos[X = i];
            x = circle_xpos[X];
            multisprite_compute_box_collision(xt, yt, 8, 32, x, y, 16, 32);
            if (multisprite_collision_detected) {
                destroy_circle();  
                if (hurt) h = 3;
            }
        }
    }

    // Check collision with R9
    if ((R9_state & 1) == 0) {
        multisprite_compute_box_collision(xt, yt, 8, 32, R9_xpos, R9_ypos, 16, 14);
        if (multisprite_collision_detected) {
            lose_one_life();
            if (hurt) h = 10;
        }
    }
    return h;
}

void draw_dobkeratops(char xpos, char ypos, char anim)
{
    char x, y, c, *gfx, check, draw_body = 1;
    char *tailx = dobkeratops_tail_x[X = anim];
    char *taily = dobkeratops_tail_y[X];
    char margin = 16 - 12;

    if (boss_hurt >= 6) {
        if (boss_hurt == 6) {
            boss_hurt = 12;
            // Launch a new explosion
            x = tailx[Y = boss_lives] + xpos - 46;
            y = taily[Y] + ypos;
            big_explosion(x, y);
            X = boss_lives;
            if (X >= 10) X -= 10;
            x = dobkeratops_x[X] + xpos;
            y = dobkeratops_y[X] + ypos;
            big_explosion(x, y);
            X = boss_lives + 3;
            if (X >= 10) X -= 10;
            x = dobkeratops_x[X] + xpos + 40;
            y = dobkeratops_y[X] + ypos;
            big_explosion(x, y);
            boss_lives--;
            if (boss_lives == 0) {
                boss_lives = 17;
            }
            boss_counter++;
            if (boss_counter == 50) {
                game_state = STATE_LEVEL_FINISHED; 
            }
        }
        check = 0; 
        draw_body = !(boss_hurt & 3);
    } else {
        counter_tail++;
        if (counter_tail == 60) counter_tail = 0;
        check = 1;
    }

    if (draw_body) {
        // Draw tail
        gfx = tail1;
        for (c = 0; c != 17; c++) {
            x = tailx[Y = c] + xpos - 46;
            y = taily[Y] + ypos;
            if (c == 6) {
                gfx = tail2;
                margin = 16 - 10;
            } else if (c == 12) gfx = tail3;
            multisprite_display_small_sprite_ex(x, y, gfx, 2, 4, margin, 0);
            if (!(c & 3) && check) {
                check_dob_collision(x, y, 0);
            }
        }
        x = tailx[Y = c] + xpos - 46;
        y = taily[Y] + ypos;
        multisprite_display_sprite_ex(x, y, tail4, 4, 4, 1);
        check_dob_collision(x, y, 0);
        
        // Draw ugly alien body
        for (c = 0; c != 11; c++) {
            x = dobkeratops_x[X = c] + xpos;
            y = dobkeratops_y[X] + ypos;
            gfx = dobkeratops_gfx[X];
            // Move gfx reference to RAM
            gfx &= 0x0fff; // Keep lower 4kb bits
            gfx |= 0x7000; // dobkeratops_ram
            char nbbytes = dobkeratops_nbbytes[X];
            multisprite_display_sprite_aligned(x, y, gfx, nbbytes, 4, 1);
            if ((c & 1) && check) {
                char h = check_dob_collision(x, y, (c == 5)?1:0);
                if (h) {
                    check = 0;
                    update_score = 1;
                    boss_lives -= h;
                    if (boss_lives < 0) {
                        boss_hurt = 25; // Destruction
                        boss_lives = 17; // Used as a counter
                        boss_counter = 0;
                        score += 1000;
                    } else {
                        sfx_to_play = sfx_eek2;
                        score += h;
                        boss_hurt = 5;
                    }
                }
            }
        }
    }
}
} // bank1

bank2 void copy_dobkeratops_to_ram()
{
    char *dest = dobkeratops_ram, *src = dob1;
    for (X = 15; X >= 0; X--) {
        for (Y = 255; Y != 0; Y--) {
            dest[Y] = src[Y];
        }
        dest[Y] = src[Y];
        dest += 256;
        src += 256;
    }
}
