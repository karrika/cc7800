#include "prosystem.h"
#include "gfx.h"
#define VERTICAL_SCROLLING
#define _MS_DL_SIZE 64
#define _MS_DL_MALLOC(y) ((y == 6 || y == 7 || y == 8)?_MS_DL_SIZE * 2:_MS_DL_SIZE)
#include "multisprite.h"

char i, j, xpos, ypos;
char *ptr;

#define NB_SPRITES 32 
ramchip short sp_xpos[NB_SPRITES], sp_ypos[NB_SPRITES];
ramchip char sp_direction[NB_SPRITES];

const signed short dx[24] = {300, 289, 259, 212, 149, 77, 0, -77, -150, -212, -259, -289, -300, -289, -259, -212, -149, -77, 0, 77, 149, 212, 259, 289};
const signed short dy[24] = {0, 124, 240, 339, 415, 463, 480, 463, 415, 339, 240, 124, 0, -124, -239, -339, -415, -463, -480, -463, -415, -339, -240, -124};
const char horizontal_pingpong[24] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13 };
const char vertical_pingpong[24] = { 0, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

const char background[22] = { 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0 };
#define LTR(x) (((x) - ' ') * 2)
const char hello_world[] = { LTR('H'), LTR('E'), LTR('L'), LTR('L'), LTR('O'), LTR(' '), LTR('W'), LTR('O'), LTR('R'), LTR('L'), LTR('D') };

void main()
{
    multisprite_init();
    multisprite_set_charbase(tiles);
    
    multisprite_display_tiles(0, 0, background, 20, 1);
    multisprite_display_tiles(0, 1, background, 20, 1);
    multisprite_display_tiles(0, 2, background + 2, 20, 1);
    multisprite_display_tiles(0, 3, background + 2, 20, 1);
    for (xpos = 0, i = 4; i < _MS_DLL_ARRAY_SIZE; xpos += 8, i++) {
        multisprite_display_tiles(xpos, i, background, 6, 1);
    }
    multisprite_save();

    *P0C1 = multisprite_color(0x1c); // Setup Palette 0
    *P0C2 = multisprite_color(0xc5); // Green
    *P0C3 = 0x0f; // White
   
    *P1C1 = multisprite_color(0x55); // Dark pink
    *P1C2 = multisprite_color(0x5B); // Light pink

    // Initialize sprites
    for (ypos = 0, xpos = 0, i = 0, X = 0; X != NB_SPRITES; xpos++, ypos++, X++) {
        sp_xpos[X] = xpos << 8;
        sp_ypos[X] = ypos << 8;
        sp_direction[X] = i++;
        if (i == 24) i = 0;
    }

    // Main loop
    do {
        multisprite_flip();
        multisprite_vertical_scrolling(1);
        multisprite_reserve_dma(104, sizeof(hello_world), 2);

        for (i = 0; i != NB_SPRITES; i++) {
            X = i;
            Y = sp_direction[X];
            sp_xpos[X] += dx[Y];
            sp_ypos[X] += dy[Y];
            xpos = sp_xpos[X] >> 8;
            ypos = sp_ypos[X] >> 8;
            if ((xpos < 5 && (dx[Y] >> 8) < 0) || 
                (xpos >= 150 && (dx[Y] >> 8) >= 0)) {
                sp_direction[X] = horizontal_pingpong[Y];
            }
            if ((ypos < 5 && (dy[Y] >> 8) < 0) || 
                (ypos >= MS_YMAX - 20 && (dy[Y] >> 8) >= 0)) {
                sp_direction[X] = vertical_pingpong[Y];
            }
            multisprite_display_sprite(xpos, ypos, bb_char1, 2, 0); 
        }
        for (xpos = 40, i = 0; i != sizeof(hello_world); xpos += 8, i++) {
            ptr = chars0 + hello_world[X = i];
            multisprite_display_sprite_fast(xpos, 104, ptr, 2, 0);
        }
    } while(1);
}
