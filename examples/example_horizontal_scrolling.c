#define HORIZONTAL_SCROLLING
#define _MS_BOTTOM_SCROLLING_ZONE 1
//#define MULTISPRITE_USE_VIDEO_MEMORY
#include "sparse_tiling.h"

#ifdef MULTISPRITE_USE_VIDEO_MEMORY
// Generated from sprites7800 RType_tiles_mirror.yaml
#include "RType/RType_tiles_mirror.c"
// Generated from tiles7800 --sparse RType_tiles_mirror.yaml --force-left-to-right-order --varname tilemap_level1 RType_level1_mirror.tmx -m 16
#include "RType/RType_level1_mirror.c"
#else
// Generated from sprites7800 RType_tiles.yaml
#include "RType/RType_tiles.c"
// Generated from tiles7800 --sparse RType_tiles.yaml  --force-left-to-right-order --forbid-immediate --varname tilemap_level1 RType_level1.tmx -m 16
#include "RType/RType_level1.c"
#endif

char scroll_background_counter1, scroll_background_counter2;

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

void main()
{
    scroll_background_counter1 = 0;
    scroll_background_counter2 = 0;

    multisprite_init();
#ifdef MULTISPRITE_USE_VIDEO_MEMORY
    sparse_tiling_init_vmem(tilemap_level1_data_ptrs, brown_tiles1);
#else
    sparse_tiling_init(tilemap_level1_data_ptrs);
    multisprite_set_charbase(brown_tiles1);
#endif
    
    // Green (background) color 
    *P3C1 = multisprite_color(0xd0); 
    *P3C3 = multisprite_color(0xd1); 
    *P3C2 = multisprite_color(0xd2); 
    
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

    // Save it
    multisprite_save();

    sparse_tiling_display();
    multisprite_flip();
    sparse_tiling_scroll(1); // One pixel offset between the 2 buffers
    sparse_tiling_display();
    multisprite_flip();

    do {
        scroll_background(4);
        sparse_tiling_scroll(1); // Scroll 1 pixels to the right for this buffer (so 0.5 pixel from frame to frame due to double buffering)
        multisprite_flip();
    } while (1);
}
