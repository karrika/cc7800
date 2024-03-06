#include "prosystem.h"
#include "stdlib.h"
#include "string.h"
#include "armyfont.h"
#define MODE_320AC
#define _MS_DL_SIZE 96
#define MULTISPRITE_OVERLAY
#include "multisprite_8lines.h"

unsigned char X, Y;

// Generated from sprites7800 breakout.yaml
holeydma reversed scattered(8,6) char suitcase_even[48] = {
	0x30, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0x60, 0xf5, 0xf5, 0xf5, 0xf5, 0xb4, 0x57, 0xbd, 0xf5, 0xf5,
	0xe5, 0xdd, 0x56, 0xb9, 0x59, 0xd6, 0x65, 0xd9, 0x53, 0xbd, 0x7a, 0xfa, 0x65, 0xdc, 0x30, 0xf0,
	0xf0, 0xf0, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
holeydma reversed scattered(8,6) char suitcase_odd[48] = {
	0x70, 0xf0, 0xf0, 0xf0, 0xf0, 0xc0, 0xd1, 0xf5, 0xf5, 0xf5, 0xf5, 0x60, 0xb7, 0x75, 0xf5, 0xf5,
	0xd7, 0xad, 0xb6, 0x65, 0xb9, 0xa6, 0xd6, 0xa9, 0xb3, 0x65, 0xfa, 0xea, 0xd7, 0xac, 0x70, 0xf0,
	0xf0, 0xf0, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
holeydma reversed scattered(8,2) char ball_even[16] = {
	0x32, 0x88, 0x7a, 0xc8, 0xfa, 0xeb, 0xfa, 0xeb, 0xfa, 0xeb, 0x7e, 0xcc, 0x33, 0x8c, 0x00, 0x00
};
holeydma reversed scattered(8,2) char ball_odd[16] = {
	0x12, 0xc8, 0x32, 0xea, 0x7a, 0xfb, 0x7a, 0xfb, 0x7a, 0xfb, 0x32, 0xeb, 0x13, 0xcc, 0x00, 0x00
};
holeydma reversed scattered(8,2) char brick[16] = {
	0x7f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 0x7f, 0xff, 0x00, 0x00
};
holeydma reversed scattered(8,7) char side_brick[56] = {
	0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf,
	0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfb, 0xfb, 0xfb, 0xfb,
	0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb,
	0xfb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define LEFT_BORDER ((160 - (13 * 8)) / 2)
#define RIGHT_BORDER (160 - LEFT_BORDER) 
#define BALL_SIZE 7
#define BALL_XOFFSET 16
#define PADDLE_YPOS 208
#define PPADDLE_BUFSIZE 4

#define GAME_STATE_READY    0
#define GAME_STATE_RUNNING  1
#define GAME_STATE_GAMEOVER 2

ramchip char nb_lives, game_state, button_pressed;
ramchip char paddle_pos[PPADDLE_BUFSIZE], paddle_pos_idx, paddle_size, paddle_filtered_pos;
ramchip signed char paddle_speed;
ramchip unsigned int xball, yball;
ramchip int sxball, syball; // Ball speed 
ramchip unsigned int score, high_score;
ramchip char update_score;
ramchip char display_score_str[5];
ramchip char display_high_score_str[5];
#ifdef DEBUG
ramchip char paddle_pos_str[4], paddle_speed_str[4];
#endif

ramchip char dli_done;

ramchip char update_wall_line;
ramchip char playfield[16 * 16];

const char playfield_level1[16 * 10] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1,
    1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};
   
const char playfield_level1_offset[10] = {0, 0, 0, 1, 0, 1, 0, 1, 0, 1};

const screencode char score_txt[] = "1UP";
const screencode char highscore_txt[] = "HIGH SCORE";
const screencode char get_ready_txt[] = "GET READY!";
const screencode char game_over_txt[] = "GAME OVER";

void interrupt dli()
{
    if (!dli_done) {
        *BACKGRND = 0x05;
        *VBLANK = 0x00; // Let paddle capacitors charging 
        Y = 200;
        do {
            strobe(WSYNC); // 3 cycles
            if ((*INPT0 & 0x80)) break; // 7 cycles
            Y--;
        } while (Y); // Looping 5 cycles
        // This takes 15 cycles out of 113.5. Maria should have enough cycles left... 
        X = paddle_pos_idx;
        X++;
        if (X == PPADDLE_BUFSIZE) {
            X = 0;
        }
        paddle_pos_idx = X;
        paddle_pos[X] = Y;
        *VBLANK = 0x80; // Dump paddles to ground
        *BACKGRND = 0x00;
        dli_done = ++Y; // To tell the main prog how much lines the DLI took
    }
}

void display_wall_line(char y) {
    char x, x2, y2, tmp, v;
    char *gfx;
    
    X = y << 4;
    x2 = LEFT_BORDER;
    y2 = (y + 2) << 3;
    if (playfield_level1_offset[Y = y]) {
        v = playfield[X];
        if (v) {
            char color = v - 1;
            tmp = X;
            multisprite_display_sprite_aligned_fast(x2, y2, brick + 1, 1, color);
            X = tmp;
        }
        x2 += 4;
        X++;
    }
    for (x = 0; x != 12; X++, x++) {
        v = playfield[X];
        if (v) {
            char color = v - 1;
            tmp = X;
            multisprite_display_sprite_aligned_fast(x2, y2, brick, 2, color);
            X = tmp;
        }
        x2 += 8;
    }
    v = playfield[X];
    if (v) {
        char color = v - 1;
        tmp = (playfield_level1_offset[Y = y])?1:2;
        multisprite_display_sprite_aligned_fast(x2, y2, brick, tmp, color);
    }
}

void display_playfield()
{
    char y;
    for (y = 0; y != 10; y++) {
        display_wall_line(y);
    }
}

void display_lives()
{
    char x, x2;
    x2 = LEFT_BORDER;
    for (x = 0; x != nb_lives; x++) {
        // Display lives on line 27
        multisprite_display_sprite_aligned(x2, 216, ball_odd, 2, 0, 1);
        x2 += 4;
    }
}

void game_over()
{
    game_state = GAME_STATE_GAMEOVER;
    multisprite_display_tiles(80 - (9 * 4) / 2, 14, game_over_txt, 9, 3);
    multisprite_save_overlay_line(14);
}

void lose_one_life()
{
    if (nb_lives) {
        nb_lives--;
        multisprite_restore_line(27);
        if (nb_lives) display_lives();
        multisprite_save_overlay_line(27);
    } else game_over();
}

void display_init()
{
    char x, y;

    *P0C2 = multisprite_color(0x40); // Red brick
    *P1C2 = multisprite_color(0x34); // Red 
    *P2C2 = multisprite_color(0x1c); // Yellow
    *P3C2 = 0x0f;                    // White
    *P4C2 = multisprite_color(0x83); // Blue
    *P5C2 = multisprite_color(0xd3); // Green
    *P6C2 = 0x05;                    // Dark grey
    *P7C2 = 0x0a;                    // Light grey
 
    multisprite_init();
    multisprite_set_charbase(font);
    dli_done = 0;

    // Score display
    multisprite_display_tiles(LEFT_BORDER - 4, 0, score_txt, 3, 2);
    multisprite_display_tiles(LEFT_BORDER + 12, 0, display_score_str, 5, 3);
    multisprite_display_tiles(LEFT_BORDER + 12 + 6 * 4 + 8, 0, highscore_txt, 10, 2);
    multisprite_display_tiles(LEFT_BORDER + 12 + 16 * 4 + 12, 0, display_high_score_str, 5, 3);
#ifdef DEBUG
    multisprite_display_tiles(0, 0, paddle_pos_str, 4, 3);
    multisprite_display_tiles(0, 1, paddle_speed_str, 4, 3);
#endif 
    // Upper wall
    multisprite_display_sprite_aligned(LEFT_BORDER - 4, 8, side_brick, 7, 0, 0);
    x = LEFT_BORDER - 4;
    for (y = 0; y != 3; y++) {
        x += 56 / 2;
        multisprite_display_sprite_aligned_fast(x, 8, side_brick, 7, 0);
    }

    // Left and right walls
    for (y = 2; y != 28; y++) {
        char yy = y << 3;
        multisprite_display_sprite_aligned(LEFT_BORDER - 4, yy, side_brick, 1, 0, 0);
        multisprite_display_sprite_aligned_fast(RIGHT_BORDER, yy, side_brick, 1, 0);
    }

    multisprite_save();

    display_playfield();
    multisprite_display_tiles(80 - (10 * 4) / 2, 14, get_ready_txt, 10, 3);
    display_lives();
    multisprite_save_overlay();
    
    multisprite_enable_dli(0);
}

#ifdef DEBUG
void display_debug_update(int val, char *str)
{
    char display_ascii[5];
    itoa(val, display_ascii, 10);
    X = strlen(display_ascii); 
    for (Y = 0; Y != 4 - X; Y++) {
        str[Y] = ' ';
    }
    Y = 3;
    do {
        str[Y--] = display_ascii[--X];
    } while (X);
}

#endif

void display_score_update(char *score_str)
{
    char display_score_ascii[6];
    itoa(score, display_score_ascii, 10);
    X = strlen(display_score_ascii); 
    Y = 4;
    do {
        score_str[Y--] = display_score_ascii[--X];
    } while (X);
}

void game_init()
{
    xball = 256 * ((13 * 16) / 2 + BALL_XOFFSET - (BALL_SIZE / 2));
    yball = 256 * 100;
    sxball = 200;
    syball = 400;
    paddle_size = 24;
    score = 0;
    for (X = 4; X >= 0; X--) display_score_str[X] = ' ';
    update_score = 1;
    update_wall_line = -1;

    // Clear playfield
    for (Y = 255; Y != 0; Y--) {
        playfield[Y] = 0;
    }
    playfield[Y] = 0;

    // Copy level1
    for (X = 0; X != 16 * 10; X++) {
        playfield[X] = playfield_level1[X];
    }

    game_state = GAME_STATE_READY;
    nb_lives = 2;
}

void compute_paddle()
{
    char x = paddle_pos[X = paddle_pos_idx];
    X++;
    if (X == PPADDLE_BUFSIZE) X = 0;
    paddle_speed = paddle_pos[X] - x;

    // Compute the average of the last PPADDLE_BUFSIZE positions
    unsigned int sum = paddle_pos[X = 0];
    for (X++; X != PPADDLE_BUFSIZE; X++) {
        sum += paddle_pos[X];
    }
    sum >>= 2;
    x = 200 - (sum & 0xff); 
    if (x >= 13 * 16 - paddle_size) x = 13 * 16 - paddle_size;
    paddle_filtered_pos = x;
} 

void display_paddle()
{
    char x2 = LEFT_BORDER + (paddle_filtered_pos >> 1);
    char *gfx;
    if (paddle_filtered_pos & 1) {
        gfx = suitcase_even;
    } else {
        gfx = suitcase_odd;
    }
    multisprite_display_sprite_aligned(x2, PADDLE_YPOS, gfx, 6, 0, 1);
}

void compute_ball()
{
    xball += sxball;
    yball += syball;
    if ((yball >> 8) >= 223) {
        // Reset ball
        xball = 256 * ((13 * 16) / 2 + BALL_XOFFSET - (BALL_SIZE / 2));
        yball = 256 * 100;
        lose_one_life();
        if (game_state != GAME_STATE_GAMEOVER) {
            game_state = GAME_STATE_READY;
            multisprite_display_tiles(80 - (10 * 4) / 2, 14, get_ready_txt, 10, 3);
            multisprite_save_overlay_line(14);
        }
    }
    // Bounces on left and right walls
    if (((sxball >> 8) >= 0 && ((xball >> 8) >= (13 * 16) + BALL_XOFFSET - BALL_SIZE)) || ((sxball >> 8) < 0 && ((xball >> 8) < BALL_XOFFSET ))) {
        sxball = -sxball;
    }
    // Bounces on upper wall
    if ((syball >> 8) < 0 && (yball >> 8) < 16) {
        syball = -syball;
        yball = 256 * 16;
    }
    // Bounces on suitcase
    if ((syball >> 8) >= 0 && ((yball >> 8) >= PADDLE_YPOS - BALL_SIZE) && ((yball >> 8) <= PADDLE_YPOS - (BALL_SIZE / 2))) {
        // Are we above the suitcase ?
        char left_side = paddle_filtered_pos + BALL_XOFFSET - (BALL_SIZE / 2); // Including the 16 pixels offset of the ball - 3 pixels off the ball (round)
        if (((xball >> 8) >= left_side) && ((xball >> 8) < left_side + paddle_size)) {
            signed int speed_offset = paddle_speed;
            speed_offset <<= 3;
            syball = -syball;
            sxball += speed_offset;
        }
    }
}

void display_ball()
{
    char x = xball >> 8;
    char y = yball >> 8;
    char x2 = LEFT_BORDER + (x >> 1) - 8;
    char *gfx;
    if (x & 1) {
        gfx = ball_odd;
    } else {
        gfx = ball_even;
    }
    multisprite_display_sprite_ex(x2, y, gfx, 2, 0, 1);
}

void brick_effect(char x, char y, char idx)
{
    score += 10;
}

void compute_wall_destruction()
{
    // Find out on which line of the playfield the ball touches
    char line = ((yball >> 8) >> 3) - 2;
    char hit = 0;
    if (line < 16) {
        char x = (xball >> 8) - BALL_XOFFSET + 2;
        if ((syball >> 8) < 0) { // The ball is going up
                                 // Let's see if it hits a piece of wall
            if (playfield_level1_offset[Y = line]) x += 8;
            Y = (line << 4) | (x >> 4);
            if (playfield[Y]) {
                // Yes, we have a hit
                brick_effect(x, line, Y);
                playfield[Y] = 0;
                hit = 1;
            }
            char x2 = x + 2; // Right side of the upper part of the ball
                             // Did it hit another brick ?
            if ((x & 0xf0) != (x2 & 0xf0)) {
                Y++;
                if (playfield[Y]) {
                    // Yes, we have a hit
                    brick_effect(x, line, Y);
                    playfield[Y] = 0;
                    hit = 1;
                }
            }
        } else { // The ball is going down
            line++;
            if (playfield_level1_offset[Y = line]) x += 8;
            Y = (line << 4) | (x >> 4);
            if (playfield[Y]) {
                // Yes, we have a hit
                brick_effect(x, line, Y);
                playfield[Y] = 0;
                hit = 1;
            }
            char x2 = x + 2; // Right side of the upper part of the ball
                             // Did it hit another brick ?
            if ((x & 0xf0) != (x2 & 0xf0)) {
                Y++;
                if (playfield[Y]) {
                    // Yes, we have a hit
                    brick_effect(x, line, Y);
                    playfield[Y] = 0;
                    hit = 1;
                }
            }
        }
        if (hit) {
            syball = -syball;
            update_wall_line = line;
            update_score = 1;
        } else {
            // Let's test on sides
            if ((sxball >> 8) < 0) { // The ball is going left
                x = (xball >> 8) - BALL_XOFFSET;
                if (((yball >> 8) & 0x07) >= 4) line++;
                if (playfield_level1_offset[Y = line]) x += 8;
                Y = (line << 4) | (x >> 4);
                if (playfield[Y]) {
                    // Yes, we have a hit
                    brick_effect(x, line, Y);
                    playfield[Y] = 0;
                    hit = 1;
                }
            } else {
                x = (xball >> 8) - BALL_XOFFSET;
                if (((yball >> 8) & 0x07) >= 4) line++;
                if (playfield_level1_offset[Y = line]) x += 8;
                Y = (line << 4) | (x >> 4);
                if (playfield[Y]) {
                    // Yes, we have a hit
                    brick_effect(x, line, Y);
                    playfield[Y] = 0;
                    hit = 1;
                }
            }        
            if (hit) { 
                sxball = -sxball;
                update_wall_line = line;
                update_score = 1;
            } 
        }
    }
}

void display_updated_wall()
{ 
    Y = update_wall_line;
    if (Y != -1) {
        Y++; Y++; // Skip the first two lines (score & lives display)
        char line = Y;
        multisprite_restore_line(Y);
        display_wall_line(update_wall_line);
        multisprite_save_overlay_line(line);

        update_wall_line = -1;
    }
}

void game_reset()
{
    high_score = 0;
    for (X = 4; X >= 0; X--) display_high_score_str[X] = ' ';
    paddle_pos_idx = 0;
    for (X = 4; X >= 0; X--) paddle_pos[X] = 0;
    paddle_speed = 0;
    paddle_filtered_pos = 0;
    button_pressed = 1;
    
    game_init();
    display_init();
}

void main()
{
    game_reset();

    // Main loop
    do {
        while (!dli_done);
        *BACKGRND = 0x0f;
        compute_paddle();
        
        if (game_state == GAME_STATE_RUNNING) {
            compute_ball();
            compute_wall_destruction();
        } else {
            if (!(*SWCHA & 0x80)) {
                if (!button_pressed) {
                    button_pressed = 1;
                    if (game_state == GAME_STATE_GAMEOVER) {
                        game_init();
                        display_init();
                    } else {
                        multisprite_restore_line(14); // Remove get ready message
                        game_state = GAME_STATE_RUNNING;
                    }
                }
            } else button_pressed = 0;
        }

        if (dli_done < 170) {
            if (update_score) {
                display_score_update(display_score_str);
                if (score >= high_score) {
                    high_score = score;
                    display_score_update(display_high_score_str);
                }
                update_score = 0;
            }
        }

#ifdef DEBUG
        display_debug_update(paddle_pos[X = paddle_pos_idx], paddle_pos_str);
        display_debug_update(paddle_speed, paddle_speed_str);
#endif
        dli_done = 0;
        *BACKGRND = 0x00;
        
        while (!(*MSTAT & 0x80)); // Wait for VBLANK
        *BACKGRND = 0x0f;
        // Display paddle position
        multisprite_restore_overlay();
        display_paddle();
        display_ball();
        display_updated_wall();
        *BACKGRND = 0x00;
    } while(1);
}
