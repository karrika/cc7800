#include "stdlib.h"
#include "string.h"
#include "prosystem.h"
#define BIDIR_VERTICAL_SCROLLING
#define _MS_TOP_SCROLLING_ZONE 1
#include "multisprite.h"
#include "joystick.h"

holeydma reversed scattered(16,2) char bb_char1[32] = {
	0x01, 0x00, 0x01, 0x40, 0x0a, 0x94, 0x2a, 0x90, 0x3b, 0xa0, 0xc8, 0xe5, 0xc8, 0xe4, 0xc8, 0xd0,
	0xc8, 0xe5, 0xbb, 0x84, 0x0c, 0x20, 0x2a, 0x90, 0x0e, 0x50, 0x3f, 0x94, 0x3d, 0x68, 0x5d, 0x6a
};
// Generated by sprites7800 based on tiles.yaml
reversed scattered(16,12) char tiles[192] = {
	0x50, 0x50, 0x00, 0x00, 0xaa, 0xbf, 0xfe, 0xfe, 0xab, 0xea, 0xcf, 0xcf, 0x50, 0x50, 0x13, 0xc4,
	0xd6, 0xff, 0xee, 0xee, 0xaf, 0xfa, 0x3c, 0x3c, 0x50, 0x50, 0x14, 0xc4, 0xff, 0xff, 0xde, 0xde,
	0xaa, 0xfa, 0xf3, 0xf3, 0x50, 0x50, 0x12, 0x30, 0x3f, 0xfc, 0xde, 0xde, 0xa6, 0xfe, 0xc3, 0xc3,
	0x05, 0x05, 0x12, 0x3c, 0x2f, 0xfc, 0xee, 0xee, 0x96, 0xbe, 0x3c, 0x3c, 0x05, 0x05, 0x12, 0x3c,
	0x1e, 0xfc, 0xfe, 0xfe, 0x97, 0xfe, 0x33, 0x33, 0x05, 0x05, 0x0c, 0x4c, 0x1e, 0xfc, 0xaa, 0xaa,
	0x98, 0x3e, 0xcc, 0xcc, 0x05, 0x05, 0x3c, 0x4c, 0x1e, 0xfc, 0xaa, 0xaa, 0x94, 0x1e, 0x3c, 0x3c,
	0x50, 0x50, 0x0c, 0x40, 0x1e, 0xfc, 0xfe, 0xfe, 0xa4, 0x2e, 0xcf, 0xcf, 0x50, 0x50, 0x21, 0x28,
	0x1e, 0xec, 0xee, 0xee, 0xa9, 0x7e, 0x3c, 0x3c, 0x50, 0x50, 0x28, 0xa0, 0x1e, 0xec, 0xde, 0xde,
	0xba, 0xbe, 0xf3, 0xf3, 0x50, 0x50, 0x28, 0x84, 0x1e, 0xec, 0xde, 0xde, 0xbe, 0xfa, 0xc3, 0xc3,
	0x05, 0x05, 0x21, 0x04, 0x1e, 0xec, 0xee, 0xee, 0xaf, 0xfa, 0x3c, 0x3c, 0x05, 0x05, 0x05, 0x30,
	0x2e, 0xec, 0xfe, 0xfe, 0xab, 0xea, 0x33, 0x33, 0x05, 0x05, 0x04, 0xf0, 0x3f, 0xfc, 0xaa, 0xaa,
	0xaa, 0xaa, 0xcc, 0xcc, 0x05, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#define DIGITS_INDEX 12 
reversed scattered(16,20) char digits[320] = {
	0x15, 0x40, 0x05, 0x00, 0x15, 0x40, 0x15, 0x40, 0x01, 0x40, 0x55, 0x50, 0x15, 0x40, 0x55, 0x50, 0x15, 0x40, 0x15, 0x40,
	0x15, 0x40, 0x05, 0x00, 0x15, 0x40, 0x15, 0x40, 0x01, 0x40, 0x55, 0x50, 0x15, 0x40, 0x55, 0x50, 0x15, 0x40, 0x15, 0x40,
	0x5a, 0x70, 0x0d, 0x00, 0x7a, 0xd0, 0x7a, 0x50, 0x07, 0x40, 0xda, 0xa0, 0x5a, 0xd0, 0x7a, 0xd0, 0x7a, 0x50, 0xda, 0x70,
	0x70, 0xd0, 0x05, 0x00, 0x50, 0x50, 0x50, 0xd0, 0x05, 0x40, 0x50, 0x00, 0xd0, 0x70, 0x50, 0x50, 0x50, 0xd0, 0x70, 0x50,
	0x51, 0x70, 0x1d, 0x00, 0xa0, 0xd0, 0xa0, 0xd0, 0x37, 0x40, 0xd7, 0x40, 0xd0, 0xa0, 0xa1, 0xe0, 0x70, 0xd0, 0x70, 0x50,
	0xd3, 0x50, 0x37, 0x00, 0x00, 0x70, 0x00, 0x70, 0x1d, 0xc0, 0x75, 0xc0, 0x70, 0x00, 0x03, 0x40, 0xd0, 0x70, 0x50, 0xd0,
	0x76, 0xd0, 0x27, 0x00, 0x03, 0x60, 0x07, 0x60, 0x6b, 0x40, 0xaa, 0x70, 0x77, 0x40, 0x07, 0x80, 0xb7, 0x60, 0xb7, 0x70,
	0xdc, 0x70, 0x07, 0x00, 0x03, 0x40, 0x07, 0x40, 0x43, 0x40, 0x00, 0x70, 0x77, 0x40, 0x07, 0x00, 0x37, 0x40, 0x37, 0x70,
	0xd8, 0xf0, 0x0d, 0x00, 0x36, 0x80, 0x0a, 0x70, 0xf7, 0xf0, 0x00, 0x70, 0x7a, 0xf0, 0x07, 0x00, 0x7a, 0x70, 0x2a, 0xf0,
	0xf0, 0x70, 0x0f, 0x00, 0x1c, 0x00, 0x00, 0xd0, 0x7d, 0xd0, 0x00, 0xf0, 0xd0, 0x70, 0x0f, 0x00, 0xf0, 0xd0, 0x00, 0xd0,
	0xf0, 0xd0, 0x0f, 0x00, 0xf8, 0x00, 0xf0, 0xf0, 0xab, 0xe0, 0xf0, 0xf0, 0xf0, 0x70, 0x0f, 0x00, 0xf0, 0xf0, 0x70, 0xf0,
	0xd0, 0xf0, 0x0f, 0x00, 0xd0, 0x00, 0xf0, 0x70, 0x03, 0xc0, 0xd0, 0x70, 0x70, 0xf0, 0x0d, 0x00, 0x70, 0x70, 0xf0, 0xd0,
	0xbd, 0xe0, 0xff, 0xf0, 0xff, 0xf0, 0xbf, 0xe0, 0x03, 0xc0, 0xbf, 0xe0, 0xbf, 0xe0, 0x0f, 0x00, 0xbf, 0xe0, 0xbf, 0xe0,
	0x3f, 0xc0, 0xff, 0xf0, 0xff, 0xf0, 0x3f, 0xc0, 0x03, 0xc0, 0x3f, 0xc0, 0x3f, 0xc0, 0x0f, 0x00, 0x3f, 0xc0, 0x3f, 0xc0,
	0x2a, 0x80, 0xaa, 0xa0, 0xaa, 0xa0, 0x2a, 0x80, 0x02, 0x80, 0x2a, 0x80, 0x2a, 0x80, 0x0a, 0x00, 0x2a, 0x80, 0x2a, 0x80,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Edited with tiled, and generated with tiles7800
const char tilemap[1057] = {
	0xff, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4,
	0xff, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4,
	0xff, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4,
	0xff, 4, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 4,
	0xff, 4, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
	0xff, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
	0xff, 4, 4, 4, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4,
	0xff, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 2, 2, 2, 2, 2, 0, 2, 0, 2, 0, 0, 0, 2, 2, 2, 0, 2, 2, 2, 0, 0, 0, 8, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 2, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 2, 0, 0, 0, 2, 0, 2, 2, 2, 0, 2, 2, 2, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 6, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 2, 2, 0, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 8, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0,
	0xff, 0, 0, 4, 0, 0, 8, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 4, 0, 0,
	0xff, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4,
	0xff, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 4,
	0xff, 4, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4,
	0xff, 4, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 4,
	0xff, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4,
	0xff, 4, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 4,
	0xff, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4,
	0xff};

#define TILEMAP_WIDTH 32
#define TILEMAP_HEIGHT 32

char i;
char *ptr;

ramchip char *top_tiles, *bottom_tiles;
ramchip int score;
ramchip char display_score_str[5];
ramchip char display_score_ascii[6];

void display_score_update()
{
    itoa(score, display_score_ascii, 10);
    Y = strlen(display_score_ascii); 
    for (X = 0; X != 5 - Y; X++) {
        display_score_str[X] = DIGITS_INDEX; // '0'
    }
    X = 4;
    do {
        display_score_str[X--] = DIGITS_INDEX + ((display_score_ascii[--Y] - '0') << 1);
    } while (Y);
}

void main()
{
    score = 0;

    multisprite_init();
    multisprite_set_charbase(tiles);
    joystick_init();
   
    // Set up a full background 
    top_tiles = tilemap + 1;
    for (ptr = top_tiles, i = 1; i != _MS_DLL_ARRAY_SIZE; i++) {
        multisprite_display_tiles(0, i, ptr, 20, 1);
        ptr += TILEMAP_WIDTH + 1;
    }
    bottom_tiles = ptr;

    // Score display
    display_score_update();
    multisprite_display_tiles(0, 0, display_score_str, 5, 0);
    multisprite_save();

    *P0C1 = multisprite_color(0x1c); // Setup Palette 0: Yellow
    *P0C2 = multisprite_color(0xc5); // Green
    *P0C3 = multisprite_color(0xcd); // Light green
   
    *P1C1 = 0x0f; // White
    *P1C2 = multisprite_color(0x9D);
    *P1C3 = multisprite_color(0x97);

    // Main loop
    do {
        if (multisprite_vscroll_buffers_refill_status()) {
            switch (multisprite_vscroll_buffers_refill_status()) {
            case MS_SCROLL_UP:
                top_tiles -= TILEMAP_WIDTH + 1;
                bottom_tiles -= TILEMAP_WIDTH + 1;
                break;
            case MS_SCROLL_DOWN:
                top_tiles += TILEMAP_WIDTH + 1;
                bottom_tiles += TILEMAP_WIDTH + 1;
            }
            ptr = tilemap + (TILEMAP_WIDTH + 1) * TILEMAP_HEIGHT;
            if (top_tiles > tilemap && top_tiles < ptr) {
                multisprite_top_vscroll_buffer_tiles(0, top_tiles, 20, 1);
            }
            if (bottom_tiles > tilemap && bottom_tiles < ptr) {
                multisprite_bottom_vscroll_buffer_tiles(0, bottom_tiles, 20, 1);
            }

            multisprite_vscroll_buffers_refilled();
        }    
        
        *BACKGRND = 0;
        multisprite_flip();
        
        multisprite_display_sprite(76, 100, bb_char1, 2, 0);
        
        joystick_update();
        if (joystick[0] & JOYSTICK_UP) {
            multisprite_vertical_scrolling(1);
        } else if (joystick[0] & JOYSTICK_DOWN) {
            multisprite_vertical_scrolling(-1);
        }

        score++;
        display_score_update();
    } while(1);
}
