#include "stdlib.h"
#include "string.h"
#include "prosystem.h"
#include "joystick.h"

#define MODE_320BD

// Generated from tiles7800 --sparse 320BD_tiles.yaml 320BD_sparse.tmx
const char tilemap_0_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 8, 7, smallstones2 + 0, 0xc0, smallstones2 + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 9, 9, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 10, 10, smallstones2 + 4, 0xc0, smallstones2 + 4 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 24, 24, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 28, 27, bigstone_top + 0, 0xc0, bigstone_top + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_1_2[4] = {80, 82, 76, 78};
const char tilemap_1_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 8, 7, tilemap_1_2, 0xe0, tilemap_1_2 >> 8, (0 << 5) | ((-4) & 0x1f), 24, 9, 9, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 10, 10, smallstones2 + 0, 0xc0, smallstones2 + 0 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 24, 24, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 28, 27, bigstone_bottom + 0, 0xc0, bigstone_bottom + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_2_4[18] = {80, 82, 68, 70, 72, 74, 68, 70, 72, 74, 68, 70, 72, 74, 68, 70, 72, 74};
const char tilemap_2_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 8, 7, smallstones2 + 0, 0xc0, smallstones2 + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 9, 9, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 18, 10, tilemap_2_4, 0xe0, tilemap_2_4 >> 8, (0 << 5) | ((-18) & 0x1f), 87, 24, 24, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_3_3[7] = {28, 28, 28, 28, 28, 28, 28};
const char tilemap_3_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 9, 8, falling_water + 2, 0x40, falling_water + 2 >> 8, (5 << 5) | ((-4) & 0x1f), 11, 17, 11, tilemap_3_3, 0x60, tilemap_3_3 >> 8, (4 << 5) | ((-7) & 0x1f), 38, 19, 19, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 24, 24, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_4_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 9, 8, falling_water + 2, 0x40, falling_water + 2 >> 8, (5 << 5) | ((-4) & 0x1f), 11, 19, 19, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 24, 24, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_5_3[4] = {76, 78, 68, 70};
const char tilemap_5_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 9, 8, falling_water + 2, 0x40, falling_water + 2 >> 8, (5 << 5) | ((-4) & 0x1f), 11, 20, 19, tilemap_5_3, 0xe0, tilemap_5_3 >> 8, (0 << 5) | ((-4) & 0x1f), 24, 24, 24, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_6_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 5, 4, bigstone_top + 0, 0xc0, bigstone_top + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 9, 8, falling_water + 2, 0x40, falling_water + 2 >> 8, (5 << 5) | ((-4) & 0x1f), 11, 15, 15, white_objects + 0, 0x40, white_objects + 0 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 21, 21, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 24, 24, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_7_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 5, 4, bigstone_bottom + 0, 0xc0, bigstone_bottom + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 9, 8, white_objects + 6, 0x40, white_objects + 6 >> 8, (4 << 5) | ((-4) & 0x1f), 11, 21, 21, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 24, 24, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_8_2[8] = {46, 48, 50, 48, 50, 48, 48, 50};
const char tilemap_8_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 11, 4, tilemap_8_2, 0x60, tilemap_8_2 >> 8, (0 << 5) | ((-8) & 0x1f), 42, 12, 12, smallstones2 + 0, 0xc0, smallstones2 + 0 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 21, 21, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 24, 24, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_9_3[3] = {16, 12, 8};
const char tilemap_9_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 12, 12, smallstones2 + 4, 0xc0, smallstones2 + 4 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 17, 15, tilemap_9_3, 0x60, tilemap_9_3 >> 8, (4 << 5) | ((-3) & 0x1f), 20, 21, 21, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 24, 24, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_10_2[10] = {76, 78, 92, 94, 96, 98, 92, 94, 96, 98};
const char tilemap_10_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 16, 12, tilemap_10_2, 0xe0, tilemap_10_2 >> 8, (0 << 5) | ((-10) & 0x1f), 51, 17, 17, white_tubes + 0, 0x40, white_tubes + 0 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 19, 19, white_objects + 10, 0x40, white_objects + 10 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 21, 21, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 24, 24, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_11_4[8] = {76, 78, 68, 70, 72, 74, 80, 82};
const char tilemap_11_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 17, 17, white_tubes + 0, 0x40, white_tubes + 0 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 19, 19, colored_cube + 0, 0xc0, colored_cube + 0 >> 8, (4 << 5) | ((-4) & 0x1f), 11, 24, 21, tilemap_11_4, 0xe0, tilemap_11_4 >> 8, (0 << 5) | ((-8) & 0x1f), 42, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_12_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 17, 17, white_tubes + 0, 0x40, white_tubes + 0 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_13_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 17, 17, white_tubes + 0, 0x40, white_tubes + 0 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 19, 19, white_objects + 10, 0x40, white_objects + 10 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_14_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 17, 17, white_tubes + 0, 0x40, white_tubes + 0 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 19, 19, colored_cube + 0, 0xc0, colored_cube + 0 >> 8, (4 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_15_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 17, 17, white_tubes + 2, 0x40, white_tubes + 2 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_16_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 17, 17, white_tubes + 0, 0x40, white_tubes + 0 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 19, 19, white_objects + 10, 0x40, white_objects + 10 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_17_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 10, 8, fire + 0, 0x40, fire + 0 >> 8, (0 << 5) | ((-6) & 0x1f), 14, 12, 11, bigstone_top + 0, 0xc0, bigstone_top + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 17, 17, white_tubes + 0, 0x40, white_tubes + 0 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 19, 19, colored_cube + 0, 0xc0, colored_cube + 0 >> 8, (4 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_18_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 12, 11, bigstone_bottom + 0, 0xc0, bigstone_bottom + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 17, 17, white_tubes + 0, 0x40, white_tubes + 0 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_19_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 12, 12, smallstones2 + 0, 0xc0, smallstones2 + 0 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 17, 17, white_tubes + 0, 0x40, white_tubes + 0 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_20_2[3] = {4, 12, 18};
const char tilemap_20_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 19, 17, tilemap_20_2, 0x60, tilemap_20_2 >> 8, (4 << 5) | ((-3) & 0x1f), 20, 22, 22, white_objects + 2, 0x40, white_objects + 2 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 25, 25, white_objects + 2, 0x40, white_objects + 2 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 28, 28, white_objects + 2, 0x40, white_objects + 2 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_21_2[9] = {46, 48, 50, 48, 50, 48, 50, 48, 50};
const char tilemap_21_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 16, 8, tilemap_21_2, 0x60, tilemap_21_2 >> 8, (0 << 5) | ((-9) & 0x1f), 47, 18, 17, bigstone_top + 0, 0xc0, bigstone_top + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_22_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 6, 4, fire + 0, 0x40, fire + 0 >> 8, (0 << 5) | ((-6) & 0x1f), 14, 8, 7, bigstone_top + 0, 0xc0, bigstone_top + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 18, 17, bigstone_bottom + 0, 0xc0, bigstone_bottom + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_23_3[14] = {76, 78, 92, 94, 96, 98, 92, 94, 96, 98, 92, 94, 80, 82};
const char tilemap_23_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 8, 7, bigstone_bottom + 0, 0xc0, bigstone_bottom + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 24, 18, tilemap_23_3, 0xe0, tilemap_23_3 >> 8, (0 << 5) | ((-14) & 0x1f), 69, 30, 25, tilemap_8_2, 0x60, tilemap_8_2 >> 8, (0 << 5) | ((-6) & 0x1f), 33, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_24_2[6] = {40, 40, 40, 40, 40, 40};
const char tilemap_24_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 1, 1, white_objects + 8, 0x40, white_objects + 8 >> 8, (4 << 5) | ((-2) & 0x1f), 8, 7, 2, tilemap_24_2, 0x60, tilemap_24_2 >> 8, (5 << 5) | ((-6) & 0x1f), 33, 8, 8, smallstones2 + 0, 0xc0, smallstones2 + 0 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 24, 24, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_25_0[14] = {100, 102, 92, 94, 96, 98, 92, 94, 96, 98, 76, 78, 80, 82};
const char tilemap_25_data[] = {6, 0, tilemap_25_0, 0xe0, tilemap_25_0 >> 8, (0 << 5) | ((-14) & 0x1f), 69, 7, 7, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 24, 24, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_26_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 6, 5, tilemap_1_2, 0xe0, tilemap_1_2 >> 8, (0 << 5) | ((-4) & 0x1f), 24, 7, 7, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 24, 24, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_27_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 6, 5, smallstones2 + 0, 0xc0, smallstones2 + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 7, 7, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 15, 14, bigstone_top + 0, 0xc0, bigstone_top + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 24, 24, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_28_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 6, 5, tilemap_1_2, 0xe0, tilemap_1_2 >> 8, (0 << 5) | ((-4) & 0x1f), 24, 7, 7, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 15, 14, bigstone_bottom + 0, 0xc0, bigstone_bottom + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 24, 24, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_29_3[20] = {92, 94, 96, 98, 92, 94, 96, 98, 92, 94, 96, 98, 96, 98, 92, 94, 96, 98, 76, 78};
const char tilemap_29_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 6, 5, smallstones2 + 0, 0xc0, smallstones2 + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 7, 7, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 24, 15, tilemap_29_3, 0xe0, tilemap_29_3 >> 8, (0 << 5) | ((-20) & 0x1f), 96, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_30_data[] = {0, 0, smallstones2 + 8, 0xc0, smallstones2 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 6, 5, tilemap_1_2, 0xe0, tilemap_1_2 >> 8, (0 << 5) | ((-4) & 0x1f), 24, 7, 7, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 31, 31, smallstones2 + 12, 0xc0, smallstones2 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};
const char tilemap_31_data[] = {0, 0, smallstones3 + 8, 0xc0, smallstones3 + 8 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 6, 5, smallstones2 + 0, 0xc0, smallstones2 + 0 >> 8, (0 << 5) | ((-8) & 0x1f), 17, 7, 7, falling_water + 4, 0x40, falling_water + 4 >> 8, (5 << 5) | ((-2) & 0x1f), 8, 31, 31, smallstones3 + 12, 0xc0, smallstones3 + 12 >> 8, (0 << 5) | ((-4) & 0x1f), 11, 96, 0xff};

const char tilemap_data_ptrs_high[32] = {tilemap_0_data >> 8, tilemap_1_data >> 8, tilemap_2_data >> 8, tilemap_3_data >> 8, tilemap_4_data >> 8, tilemap_5_data >> 8, tilemap_6_data >> 8, tilemap_7_data >> 8, tilemap_8_data >> 8, tilemap_9_data >> 8, tilemap_10_data >> 8, tilemap_11_data >> 8, tilemap_12_data >> 8, tilemap_13_data >> 8, tilemap_14_data >> 8, tilemap_15_data >> 8, tilemap_16_data >> 8, tilemap_17_data >> 8, tilemap_18_data >> 8, tilemap_19_data >> 8, tilemap_20_data >> 8, tilemap_21_data >> 8, tilemap_22_data >> 8, tilemap_23_data >> 8, tilemap_24_data >> 8, tilemap_25_data >> 8, tilemap_26_data >> 8, tilemap_27_data >> 8, tilemap_28_data >> 8, tilemap_29_data >> 8, tilemap_30_data >> 8, tilemap_31_data >> 8};

const char tilemap_data_ptrs_low[32] = {tilemap_0_data & 0xff, tilemap_1_data & 0xff, tilemap_2_data & 0xff, tilemap_3_data & 0xff, tilemap_4_data & 0xff, tilemap_5_data & 0xff, tilemap_6_data & 0xff, tilemap_7_data & 0xff, tilemap_8_data & 0xff, tilemap_9_data & 0xff, tilemap_10_data & 0xff, tilemap_11_data & 0xff, tilemap_12_data & 0xff, tilemap_13_data & 0xff, tilemap_14_data & 0xff, tilemap_15_data & 0xff, tilemap_16_data & 0xff, tilemap_17_data & 0xff, tilemap_18_data & 0xff, tilemap_19_data & 0xff, tilemap_20_data & 0xff, tilemap_21_data & 0xff, tilemap_22_data & 0xff, tilemap_23_data & 0xff, tilemap_24_data & 0xff, tilemap_25_data & 0xff, tilemap_26_data & 0xff, tilemap_27_data & 0xff, tilemap_28_data & 0xff, tilemap_29_data & 0xff, tilemap_30_data & 0xff, tilemap_31_data & 0xff};

const char *tilemap_data_ptrs[2] = {tilemap_data_ptrs_high, tilemap_data_ptrs_low};

#define TILING_HEIGHT 32
#define TILING_WIDTH 32
#include "sparse_tiling.h"

// Generated from sprites7800 320BD_tiles.yaml
reversed scattered(16,24) char white_tubes[384] = {
	0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc,
	0x30, 0x00, 0x00, 0x18, 0x7f, 0xfe, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x00, 0xc0,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0xb6, 0x00, 0x00, 0xda, 0x7f, 0xfe, 0x3f, 0xfc,
	0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfb, 0xfe, 0xdf, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xdf, 0xfc,
	0xb6, 0xff, 0xfe, 0xda, 0x05, 0xa0, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xff, 0xf2, 0xff,
	0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x37, 0xff, 0xff, 0xd8, 0x3f, 0xfc, 0x3f, 0xfc,
	0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xff, 0xfa, 0xdf, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xfc,
	0x36, 0xff, 0xfe, 0xd8, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x15, 0x54, 0x3f, 0xff, 0xfe, 0xff,
	0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x37, 0xff, 0xff, 0xd8, 0x3f, 0xfc, 0x3f, 0xfc,
	0x3f, 0xfc, 0x2a, 0xa8, 0x3f, 0xff, 0xfe, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xfc,
	0xb7, 0xff, 0xff, 0xda, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xfe, 0xff,
	0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xb7, 0xff, 0xff, 0xda, 0x3f, 0xfc, 0x3f, 0xfc,
	0x3f, 0xfc, 0x7f, 0xfe, 0x3f, 0xff, 0xfe, 0xff, 0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xfc,
	0xb7, 0xff, 0xff, 0xda, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x7f, 0xfe, 0x1f, 0xff, 0xfe, 0xff,
	0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xb7, 0xff, 0xff, 0xda, 0x3f, 0xfc, 0x3f, 0xfc,
	0x3f, 0xfc, 0x17, 0xe8, 0x15, 0x55, 0x54, 0xd5, 0x7f, 0xfc, 0x3f, 0xfd, 0x55, 0x55, 0x55, 0x58,
	0x36, 0xaa, 0xaa, 0xd8, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x0f, 0xff, 0xfe, 0xff,
	0xff, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x37, 0xff, 0xff, 0xd8, 0x3f, 0xfc, 0x3f, 0xfc,
	0x3f, 0xfc, 0x3f, 0xfc, 0x05, 0x55, 0x54, 0xd5, 0x7f, 0xfc, 0x3f, 0xfd, 0x55, 0x55, 0x55, 0x40,
	0x36, 0xaa, 0xaa, 0xd8, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x3f, 0xfc, 0x00, 0x55, 0x54, 0xd5,
	0x5f, 0xfc, 0x3f, 0xf9, 0x55, 0x55, 0x55, 0x00, 0xb6, 0xaa, 0xaa, 0xda, 0x3f, 0xfc, 0x05, 0xa0,
	0x3f, 0xfc, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0xfc, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00,
	0xb6, 0x00, 0x00, 0xda, 0x3f, 0xfc, 0x7f, 0xfe, 0x3f, 0xfc, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0xc0,
	0x3f, 0xfc, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x18, 0x3f, 0xfc, 0x7f, 0xfe
};
reversed scattered(16,12) char white_objects[192] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xcf, 0xf3, 0x80, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc,
	0x7f, 0x7f, 0x03, 0xf6, 0x6f, 0xc0, 0x00, 0x00, 0x07, 0xe8, 0x5f, 0xfa, 0x00, 0x00, 0x43, 0xf9,
	0x9f, 0xc2, 0x00, 0x00, 0x0e, 0x74, 0x6f, 0xf6, 0x7f, 0x7f, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00,
	0x0c, 0x34, 0x70, 0x0e, 0x7f, 0x7f, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x0e, 0x74, 0x77, 0xee,
	0x7e, 0x7e, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xe8, 0x77, 0xee, 0x3e, 0x3e, 0x0b, 0xff,
	0xff, 0xd0, 0x00, 0x00, 0x00, 0x00, 0x77, 0xee, 0x3e, 0x3e, 0xc1, 0xff, 0xff, 0x83, 0x00, 0x00,
	0x01, 0xa0, 0x77, 0xee, 0x3e, 0x3e, 0x3f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x01, 0x80, 0x77, 0xee,
	0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x01, 0x80, 0x77, 0xee, 0x1c, 0x1c, 0xff, 0xff,
	0xff, 0xff, 0x00, 0x00, 0x01, 0x60, 0x70, 0x0e, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0x80, 0x02,
	0x01, 0x80, 0x6f, 0xf6, 0x18, 0x18, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x01, 0x60, 0x5f, 0xfa,
	0x08, 0x08, 0x7f, 0xff, 0xff, 0xfe, 0x03, 0x80, 0x01, 0x80, 0x3f, 0xfc, 0x08, 0x08, 0xbf, 0xff,
	0xff, 0xfd, 0x17, 0xe8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcf, 0xff, 0xff, 0xf3, 0x3f, 0xfc
};
reversed scattered(16,4) char colored_cube[64] = {
	0x00, 0x00, 0x00, 0x00, 0x30, 0xf0, 0xf0, 0xc0, 0x50, 0xf0, 0xf0, 0xa2, 0x60, 0xf0, 0xf0, 0x66,
	0x70, 0x00, 0x00, 0xee, 0x70, 0x77, 0xee, 0xee, 0x70, 0x77, 0xee, 0xee, 0x70, 0x77, 0xee, 0xee,
	0x70, 0x77, 0xee, 0xee, 0x70, 0x77, 0xee, 0xee, 0x70, 0x77, 0xee, 0xee, 0x70, 0x00, 0x00, 0xee,
	0x60, 0xff, 0xff, 0x66, 0x51, 0xff, 0xff, 0xaa, 0x33, 0xff, 0xff, 0xcc, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(16,6) char falling_water[96] = {
	0x0a, 0x00, 0x2a, 0xaa, 0xaa, 0xa8, 0xa0, 0xa0, 0x2a, 0xaa, 0xaa, 0xa8, 0x0a, 0x0a, 0x2a, 0xaa,
	0xaa, 0xa8, 0xaa, 0xa0, 0x2a, 0xaa, 0xaa, 0xa8, 0xaa, 0xaa, 0x2a, 0xaa, 0xaa, 0xa8, 0xaa, 0xaa,
	0x2a, 0xaa, 0xaa, 0xa8, 0xaa, 0xaa, 0x2a, 0xaa, 0xaa, 0xa8, 0xaa, 0xaa, 0x2a, 0xaa, 0xaa, 0xa8,
	0xaa, 0xaa, 0x0a, 0xaa, 0xaa, 0xa0, 0xaa, 0xaa, 0x0a, 0xaa, 0xaa, 0xa0, 0xaa, 0xaa, 0x0a, 0xaa,
	0xaa, 0xa0, 0xaa, 0xaa, 0x0a, 0xaa, 0xaa, 0xa0, 0xaa, 0xaa, 0x0a, 0xaa, 0xaa, 0xa0, 0xaa, 0xaa,
	0x0a, 0xaa, 0xaa, 0xa0, 0xaa, 0xaa, 0x0a, 0xaa, 0xaa, 0xa0, 0xaa, 0xaa, 0x0a, 0xaa, 0xaa, 0xa0
};
reversed scattered(16,6) char fire[96] = {
	0x09, 0x44, 0x14, 0x28, 0x14, 0x44, 0x0e, 0x0d, 0x56, 0x3c, 0x75, 0x16, 0x04, 0x56, 0xd6, 0x98,
	0x3f, 0x5e, 0x00, 0xf4, 0xf6, 0xc3, 0x9f, 0x7e, 0x00, 0x7e, 0x7e, 0xd7, 0xa6, 0x3c, 0x00, 0x1c,
	0x3d, 0xf6, 0x70, 0x83, 0x00, 0x00, 0x00, 0xe0, 0x3f, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(16,8) char bigstone_top[128] = {
	0x57, 0x5f, 0xcc, 0x57, 0x11, 0x44, 0x5f, 0x88, 0x5f, 0xff, 0xee, 0x4c, 0xaa, 0x11, 0xff, 0x44,
	0xff, 0x88, 0x22, 0x44, 0x00, 0xcc, 0x00, 0x22, 0x66, 0x00, 0x00, 0x00, 0x5f, 0x5d, 0x00, 0x22,
	0x33, 0x00, 0x11, 0x5f, 0x5f, 0x5d, 0x88, 0x00, 0x44, 0x11, 0x5f, 0x5f, 0x5f, 0xbb, 0xcc, 0x4c,
	0x6e, 0x57, 0x5f, 0x5f, 0x5f, 0xbb, 0xee, 0x00, 0xcc, 0x9b, 0x5f, 0x5f, 0x5f, 0xbb, 0xff, 0x00,
	0x88, 0x5d, 0x5f, 0x5f, 0x5f, 0x77, 0xff, 0x88, 0x88, 0x6e, 0x5f, 0x5f, 0x5f, 0x77, 0xff, 0xcc,
	0x44, 0x5f, 0x57, 0x5f, 0x6e, 0x77, 0xff, 0xcc, 0x11, 0x5f, 0x9b, 0x6e, 0x11, 0xbb, 0xff, 0x00,
	0x99, 0x5f, 0x5d, 0x11, 0xff, 0xdd, 0xee, 0x22, 0x55, 0x5f, 0x6e, 0xff, 0xff, 0xee, 0x88, 0x22,
	0x11, 0x5f, 0x6e, 0xff, 0xff, 0xff, 0x00, 0x22, 0x11, 0x5f, 0x6e, 0xff, 0xff, 0xff, 0x88, 0x22
};
reversed scattered(16,8) char bigstone_bottom[128] = {
	0x55, 0x5f, 0x5d, 0xff, 0xff, 0xff, 0x88, 0x22, 0x13, 0x5f, 0x5d, 0xff, 0xff, 0xff, 0x88, 0x22,
	0x13, 0x5f, 0x5d, 0xff, 0xff, 0xff, 0x88, 0x22, 0x13, 0x5f, 0x99, 0xff, 0xff, 0xff, 0x88, 0x22,
	0x13, 0x4c, 0x66, 0xff, 0xff, 0xee, 0x66, 0x22, 0x00, 0x33, 0xff, 0x77, 0xff, 0x88, 0x11, 0xaa,
	0x44, 0xff, 0xff, 0xbb, 0xee, 0x00, 0x00, 0x66, 0x88, 0x77, 0xff, 0xdd, 0x88, 0x00, 0x00, 0x00,
	0x88, 0x33, 0xff, 0xee, 0x00, 0x00, 0x11, 0x88, 0x13, 0x99, 0xff, 0xee, 0x00, 0x00, 0x66, 0x00,
	0x57, 0xcc, 0xff, 0xee, 0x00, 0x11, 0x88, 0x00, 0x7f, 0x66, 0x77, 0xcc, 0x00, 0x66, 0x00, 0x00,
	0x6e, 0x11, 0x33, 0xcc, 0x11, 0x88, 0x00, 0x00, 0xcc, 0x00, 0x00, 0xcc, 0x66, 0x00, 0x13, 0x00,
	0x77, 0x44, 0x66, 0x11, 0x88, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(16,8) char smallstones1[128] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x00, 0x88, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x00, 0x88, 0x00, 0x88, 0x00,
	0x88, 0x00, 0xaa, 0xaa, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xee, 0x5d, 0x55, 0x00, 0x00,
	0x88, 0x00, 0x57, 0x4c, 0x77, 0xff, 0x55, 0x66, 0xaa, 0xaa, 0x00, 0x22, 0x13, 0x6e, 0x7f, 0xcc,
	0x7f, 0xcc, 0x9b, 0xee, 0x88, 0x00, 0x57, 0x88, 0x57, 0x99, 0x99, 0x4c, 0x77, 0x00, 0x00, 0x22
};
reversed scattered(16,16) char smallstones2[256] = {
	0x66, 0x66, 0x99, 0x4c, 0x13, 0x6e, 0x77, 0x88, 0x00, 0x00, 0x00, 0xcc, 0x33, 0x00, 0x00, 0x00,
	0x5d, 0x00, 0x13, 0xee, 0x57, 0x5f, 0x33, 0xcc, 0x00, 0x00, 0x45, 0xae, 0x57, 0x2a, 0x00, 0x00,
	0x88, 0x57, 0x88, 0x22, 0x5f, 0xff, 0x99, 0x66, 0x00, 0x00, 0xdd, 0x22, 0x44, 0xbb, 0x00, 0x00,
	0x44, 0x5f, 0x6e, 0x22, 0x7f, 0xff, 0x88, 0x22, 0x00, 0x00, 0x88, 0xaa, 0x55, 0x11, 0x00, 0x00,
	0x11, 0x5f, 0x5f, 0x00, 0xff, 0xee, 0xaa, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x22, 0x00, 0x00,
	0x13, 0x7f, 0xff, 0x88, 0xaa, 0x88, 0x88, 0x4c, 0x00, 0x00, 0x01, 0xcc, 0x33, 0x08, 0x00, 0x00,
	0x13, 0x5f, 0x7f, 0x88, 0x88, 0x11, 0x13, 0x6e, 0x00, 0x00, 0x23, 0xae, 0x57, 0x4c, 0x00, 0x00,
	0x99, 0x7f, 0xff, 0xcc, 0x44, 0x66, 0x57, 0x6e, 0x00, 0x00, 0x37, 0xee, 0x77, 0xce, 0x00, 0x00,
	0xdd, 0xff, 0xff, 0x44, 0x33, 0x88, 0x5f, 0xee, 0x00, 0x00, 0x66, 0xaa, 0x55, 0x66, 0x00, 0x00,
	0x00, 0xaa, 0xaa, 0x44, 0x00, 0x11, 0x7f, 0xee, 0x00, 0x00, 0x44, 0x22, 0x44, 0x22, 0x00, 0x00,
	0x22, 0x44, 0x00, 0x88, 0x33, 0x11, 0xff, 0xaa, 0x00, 0x00, 0x22, 0x22, 0x44, 0x44, 0x00, 0x00,
	0x57, 0x22, 0x33, 0x00, 0x66, 0x22, 0xaa, 0xaa, 0x00, 0x00, 0x11, 0xcc, 0x33, 0x88, 0x00, 0x00,
	0x6e, 0x11, 0xcc, 0x22, 0x44, 0xaa, 0x00, 0x22, 0x00, 0x00, 0x44, 0x00, 0x00, 0x22, 0x00, 0x00,
	0x88, 0x00, 0x00, 0x44, 0x33, 0x11, 0x00, 0x44, 0x00, 0x00, 0x22, 0xaa, 0x55, 0x44, 0x00, 0x00,
	0x66, 0x88, 0x55, 0x00, 0x88, 0x00, 0xff, 0x88, 0x00, 0x00, 0x00, 0x66, 0x66, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(16,16) char smallstones3[256] = {
	0x57, 0x88, 0x5f, 0x44, 0x13, 0x88, 0x00, 0x4c, 0x00, 0x22, 0x13, 0x4c, 0x23, 0x8c, 0x44, 0x00,
	0x7f, 0x55, 0x7f, 0xaa, 0x77, 0xdd, 0x5d, 0xee, 0x00, 0x00, 0x5f, 0x6e, 0x67, 0xaf, 0x00, 0x00,
	0xee, 0x13, 0x5f, 0xaa, 0x6e, 0xaa, 0xee, 0xaa, 0x00, 0x11, 0x7f, 0xee, 0x77, 0xef, 0x88, 0x00,
	0xaa, 0x13, 0xff, 0x88, 0xcc, 0x22, 0xee, 0x22, 0x00, 0x11, 0xaa, 0xaa, 0x55, 0x55, 0x88, 0x00,
	0x00, 0x77, 0x44, 0x00, 0x44, 0x00, 0xbb, 0x22, 0x00, 0x11, 0x00, 0x22, 0x44, 0x00, 0x88, 0x00,
	0x33, 0x55, 0x11, 0x44, 0x22, 0x88, 0x11, 0x22, 0x00, 0x00, 0x88, 0x44, 0x22, 0x11, 0x00, 0x00,
	0x66, 0x00, 0x11, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x88, 0x11, 0xee, 0x00, 0x00,
	0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x22, 0x44, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x44, 0x22, 0x00, 0x44, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0x55, 0x55, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0xcc, 0x33, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4e, 0x00, 0x00, 0x27, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x7f, 0xcc, 0x33, 0xef, 0x88, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0xaa, 0xaa, 0x55, 0x55, 0x88, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcc, 0x22, 0x44, 0x33, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0xcc, 0x33, 0xcc, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

ramchip int x, y;

void main()
{
    x = 0; y = 0;

    multisprite_init();
    multisprite_set_charbase(white_tubes);
    sparse_tiling_init(tilemap_data_ptrs);
    joystick_init();
    
    sparse_tiling_goto(x, y);
    *P0C1 = multisprite_color(0xbc); // Light turquoie
    *P0C2 = multisprite_color(0x33); // Red
    *P0C3 = multisprite_color(0xa5); // Dark turquoise
    *P4C1 = multisprite_color(0x83); // Dark Blue
    *P4C2 = 0x0f; // White
    *P4C3 = multisprite_color(0x29); // Orange 

    // Main loop
    do {
        multisprite_flip();
        joystick_update();
        if (joystick[0] & JOYSTICK_LEFT) x--; 
        else if (joystick[0] & JOYSTICK_RIGHT) x++;
        if (joystick[0] & JOYSTICK_UP) y--; 
        else if (joystick[0] & JOYSTICK_DOWN) y++;
        sparse_tiling_goto(x, y);
    } while(1);
}
