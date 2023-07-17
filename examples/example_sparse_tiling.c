#include "stdlib.h"
#include "string.h"
#include "prosystem.h"
#include "joystick.h"
#define _MS_TOP_SCROLLING_ZONE 1

const char tilemap_0_0[6] = {0, 0, 0, 0, 0, 0};
const char tilemap_0_data[] = {5, 0, tilemap_0_0, 0x60, tilemap_0_0 >> 8, (1 << 5) | ((-6) & 0x1f), 33, 0x7f, 0xff};
const char tilemap_1_0[5] = {0, 0, 0, 0, 0};
const char tilemap_1_data[] = {4, 0, tilemap_1_0, 0x60, tilemap_1_0 >> 8, (1 << 5) | ((-5) & 0x1f), 29, 0x7f, 0xff};
const char tilemap_2_0[4] = {0, 0, 0, 0};
const char tilemap_2_data[] = {3, 0, tilemap_2_0, 0x60, tilemap_2_0 >> 8, (1 << 5) | ((-4) & 0x1f), 24, 0x7f, 0xff};
const char tilemap_3_0[3] = {0, 0, 0};
const char tilemap_3_1[1] = {22};
const char tilemap_3_data[] = {2, 0, tilemap_3_0, 0x60, tilemap_3_0 >> 8, (1 << 5) | ((-3) & 0x1f), 20, 14, 14, tilemap_3_1, 0x60, tilemap_3_1 >> 8, (2 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_4_0[2] = {0, 0};
const char tilemap_4_1[20] = {14, 16, 14, 16, 14, 16, 14, 16, 14, 16, 14, 16, 14, 16, 14, 16, 14, 16, 14, 16};
const char tilemap_4_data[] = {1, 0, tilemap_4_0, 0x60, tilemap_4_0 >> 8, (1 << 5) | ((-2) & 0x1f), 15, 19, 10, tilemap_4_1, 0xe0, tilemap_4_1 >> 8, (4 << 5) | ((-20) & 0x1f), 96, 0x7f, 0xff};
const char tilemap_5_0[1] = {0};
const char tilemap_5_1[1] = {12};
const char tilemap_5_data[] = {0, 0, tilemap_5_0, 0x60, tilemap_5_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 11, 11, tilemap_5_1, 0x60, tilemap_5_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_6_0[1] = {12};
const char tilemap_6_data[] = {11, 11, tilemap_6_0, 0x60, tilemap_6_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_7_0[1] = {12};
const char tilemap_7_data[] = {11, 11, tilemap_7_0, 0x60, tilemap_7_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_8_0[1] = {8};
const char tilemap_8_1[1] = {12};
const char tilemap_8_data[] = {8, 8, tilemap_8_0, 0x60, tilemap_8_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 11, 11, tilemap_8_1, 0x60, tilemap_8_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_9_0[11] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
const char tilemap_9_data[] = {18, 8, tilemap_9_0, 0x60, tilemap_9_0 >> 8, (0 << 5) | ((-11) & 0x1f), 56, 0x7f, 0xff};
const char tilemap_10_0[1] = {12};
const char tilemap_10_data[] = {17, 17, tilemap_10_0, 0x60, tilemap_10_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_11_0[1] = {12};
const char tilemap_11_data[] = {17, 17, tilemap_11_0, 0x60, tilemap_11_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_12_0[1] = {12};
const char tilemap_12_data[] = {17, 17, tilemap_12_0, 0x60, tilemap_12_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_13_0[1] = {8};
const char tilemap_13_1[1] = {12};
const char tilemap_13_2[1] = {8};
const char tilemap_13_data[] = {10, 10, tilemap_13_0, 0x60, tilemap_13_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 17, 17, tilemap_13_1, 0x60, tilemap_13_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 22, 22, tilemap_13_2, 0x60, tilemap_13_2 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_14_0[12] = {18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18};
const char tilemap_14_1[1] = {18};
const char tilemap_14_data[] = {21, 10, tilemap_14_0, 0x60, tilemap_14_0 >> 8, (0 << 5) | ((-12) & 0x1f), 60, 22, 22, tilemap_14_1, 0x60, tilemap_14_1 >> 8, (0 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_15_0[1] = {12};
const char tilemap_15_data[] = {11, 11, tilemap_15_0, 0x60, tilemap_15_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_16_0[1] = {12};
const char tilemap_16_data[] = {11, 11, tilemap_16_0, 0x60, tilemap_16_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_17_0[1] = {12};
const char tilemap_17_data[] = {11, 11, tilemap_17_0, 0x60, tilemap_17_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_18_0[2] = {14, 16};
const char tilemap_18_1[1] = {12};
const char tilemap_18_2[3] = {0, 0, 0};
const char tilemap_18_data[] = {6, 6, tilemap_18_0, 0xe0, tilemap_18_0 >> 8, (4 << 5) | ((-2) & 0x1f), 15, 11, 11, tilemap_18_1, 0x60, tilemap_18_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 18, 16, tilemap_18_2, 0x60, tilemap_18_2 >> 8, (1 << 5) | ((-3) & 0x1f), 20, 0x7f, 0xff};
const char tilemap_19_0[7] = {20, 20, 20, 20, 20, 20, 20};
const char tilemap_19_1[1] = {0};
const char tilemap_19_data[] = {12, 6, tilemap_19_0, 0x60, tilemap_19_0 >> 8, (0 << 5) | ((-7) & 0x1f), 38, 15, 15, tilemap_19_1, 0x60, tilemap_19_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_20_0[1] = {12};
const char tilemap_20_1[2] = {0, 0};
const char tilemap_20_data[] = {7, 7, tilemap_20_0, 0x60, tilemap_20_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 17, 16, tilemap_20_1, 0x60, tilemap_20_1 >> 8, (1 << 5) | ((-2) & 0x1f), 15, 0x7f, 0xff};
const char tilemap_21_0[1] = {12};
const char tilemap_21_1[1] = {0};
const char tilemap_21_data[] = {7, 7, tilemap_21_0, 0x60, tilemap_21_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 18, 18, tilemap_21_1, 0x60, tilemap_21_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_22_0[1] = {12};
const char tilemap_22_1[3] = {0, 0, 0};
const char tilemap_22_data[] = {7, 7, tilemap_22_0, 0x60, tilemap_22_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 17, 15, tilemap_22_1, 0x60, tilemap_22_1 >> 8, (1 << 5) | ((-3) & 0x1f), 20, 0x7f, 0xff};
const char tilemap_23_0[1] = {12};
const char tilemap_23_data[] = {7, 7, tilemap_23_0, 0x60, tilemap_23_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_24_0[1] = {12};
const char tilemap_24_1[1] = {8};
const char tilemap_24_data[] = {7, 7, tilemap_24_0, 0x60, tilemap_24_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 14, 14, tilemap_24_1, 0x60, tilemap_24_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_25_0[7] = {20, 20, 20, 20, 20, 20, 20};
const char tilemap_25_1[1] = {12};
const char tilemap_25_2[1] = {20};
const char tilemap_25_data[] = {12, 6, tilemap_25_0, 0x60, tilemap_25_0 >> 8, (0 << 5) | ((-7) & 0x1f), 38, 13, 13, tilemap_25_1, 0x60, tilemap_25_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 14, 14, tilemap_25_2, 0x60, tilemap_25_2 >> 8, (0 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_26_0[1] = {0};
const char tilemap_26_1[1] = {12};
const char tilemap_26_data[] = {0, 0, tilemap_26_0, 0x60, tilemap_26_0 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 13, 13, tilemap_26_1, 0x60, tilemap_26_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_27_0[2] = {0, 0};
const char tilemap_27_1[1] = {12};
const char tilemap_27_data[] = {1, 0, tilemap_27_0, 0x60, tilemap_27_0 >> 8, (1 << 5) | ((-2) & 0x1f), 15, 13, 13, tilemap_27_1, 0x60, tilemap_27_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_28_0[3] = {0, 0, 0};
const char tilemap_28_1[1] = {12};
const char tilemap_28_data[] = {2, 0, tilemap_28_0, 0x60, tilemap_28_0 >> 8, (1 << 5) | ((-3) & 0x1f), 20, 13, 13, tilemap_28_1, 0x60, tilemap_28_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_29_0[4] = {0, 0, 0, 0};
const char tilemap_29_1[1] = {12};
const char tilemap_29_data[] = {3, 0, tilemap_29_0, 0x60, tilemap_29_0 >> 8, (1 << 5) | ((-4) & 0x1f), 24, 13, 13, tilemap_29_1, 0x60, tilemap_29_1 >> 8, (1 << 5) | ((-1) & 0x1f), 11, 0x7f, 0xff};
const char tilemap_30_0[5] = {0, 0, 0, 0, 0};
const char tilemap_30_1[12] = {18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18};
const char tilemap_30_2[3] = {18, 18, 18};
const char tilemap_30_data[] = {4, 0, tilemap_30_0, 0x60, tilemap_30_0 >> 8, (1 << 5) | ((-5) & 0x1f), 29, 24, 13, tilemap_30_1, 0x60, tilemap_30_1 >> 8, (0 << 5) | ((-12) & 0x1f), 60, 27, 25, tilemap_30_2, 0x60, tilemap_30_2 >> 8, (0 << 5) | ((-3) & 0x1f), 20, 0x7f, 0xff};
const char tilemap_31_0[6] = {0, 0, 0, 0, 0, 0};
const char tilemap_31_data[] = {5, 0, tilemap_31_0, 0x60, tilemap_31_0 >> 8, (1 << 5) | ((-6) & 0x1f), 33, 0x7f, 0xff};
const char tilemap_data[64] = {tilemap_0_data & 0xff, tilemap_0_data >> 8, tilemap_1_data & 0xff, tilemap_1_data >> 8, tilemap_2_data & 0xff, tilemap_2_data >> 8, tilemap_3_data & 0xff, tilemap_3_data >> 8, tilemap_4_data & 0xff, tilemap_4_data >> 8, tilemap_5_data & 0xff, tilemap_5_data >> 8, tilemap_6_data & 0xff, tilemap_6_data >> 8, tilemap_7_data & 0xff, tilemap_7_data >> 8, tilemap_8_data & 0xff, tilemap_8_data >> 8, tilemap_9_data & 0xff, tilemap_9_data >> 8, tilemap_10_data & 0xff, tilemap_10_data >> 8, tilemap_11_data & 0xff, tilemap_11_data >> 8, tilemap_12_data & 0xff, tilemap_12_data >> 8, tilemap_13_data & 0xff, tilemap_13_data >> 8, tilemap_14_data & 0xff, tilemap_14_data >> 8, tilemap_15_data & 0xff, tilemap_15_data >> 8, tilemap_16_data & 0xff, tilemap_16_data >> 8, tilemap_17_data & 0xff, tilemap_17_data >> 8, tilemap_18_data & 0xff, tilemap_18_data >> 8, tilemap_19_data & 0xff, tilemap_19_data >> 8, tilemap_20_data & 0xff, tilemap_20_data >> 8, tilemap_21_data & 0xff, tilemap_21_data >> 8, tilemap_22_data & 0xff, tilemap_22_data >> 8, tilemap_23_data & 0xff, tilemap_23_data >> 8, tilemap_24_data & 0xff, tilemap_24_data >> 8, tilemap_25_data & 0xff, tilemap_25_data >> 8, tilemap_26_data & 0xff, tilemap_26_data >> 8, tilemap_27_data & 0xff, tilemap_27_data >> 8, tilemap_28_data & 0xff, tilemap_28_data >> 8, tilemap_29_data & 0xff, tilemap_29_data >> 8, tilemap_30_data & 0xff, tilemap_30_data >> 8, tilemap_31_data & 0xff, tilemap_31_data >> 8};

#define TILING_HEIGHT 32
#define TILING_WIDTH 32
#include "sparse_tiling.h"

reversed scattered(16,14) char tiles[224] = {
	0x50, 0x50, 0x00, 0x00, 0xaa, 0xbf, 0xfe, 0xfe, 0xab, 0xea, 0xcf, 0xcf, 0x2a, 0xa8, 0x50, 0x50,
	0x13, 0xc4, 0xd6, 0xff, 0xee, 0xee, 0xaf, 0xfa, 0x3c, 0x3c, 0x20, 0x08, 0x50, 0x50, 0x14, 0xc4,
	0xff, 0xff, 0xde, 0xde, 0xaa, 0xfa, 0xf3, 0xf3, 0x20, 0x08, 0x50, 0x50, 0x12, 0x30, 0x3f, 0xfc,
	0xde, 0xde, 0xa6, 0xfe, 0xc3, 0xc3, 0x20, 0x08, 0x05, 0x05, 0x12, 0x3c, 0x2f, 0xfc, 0xee, 0xee,
	0x96, 0xbe, 0x3c, 0x3c, 0x2a, 0xa8, 0x05, 0x05, 0x12, 0x3c, 0x1e, 0xfc, 0xfe, 0xfe, 0x97, 0xfe,
	0x33, 0x33, 0x20, 0x08, 0x05, 0x05, 0x0c, 0x4c, 0x1e, 0xfc, 0xaa, 0xaa, 0x98, 0x3e, 0xcc, 0xcc,
	0x20, 0x08, 0x05, 0x05, 0x3c, 0x4c, 0x1e, 0xfc, 0xaa, 0xaa, 0x94, 0x1e, 0x3c, 0x3c, 0x20, 0x08,
	0x50, 0x50, 0x0c, 0x40, 0x1e, 0xfc, 0xfe, 0xfe, 0xa4, 0x2e, 0xcf, 0xcf, 0x2a, 0xa8, 0x50, 0x50,
	0x21, 0x28, 0x1e, 0xec, 0xee, 0xee, 0xa9, 0x7e, 0x3c, 0x3c, 0x20, 0x08, 0x50, 0x50, 0x28, 0xa0,
	0x1e, 0xec, 0xde, 0xde, 0xba, 0xbe, 0xf3, 0xf3, 0x20, 0x08, 0x50, 0x50, 0x28, 0x84, 0x1e, 0xec,
	0xde, 0xde, 0xbe, 0xfa, 0xc3, 0xc3, 0x20, 0x08, 0x05, 0x05, 0x21, 0x04, 0x1e, 0xec, 0xee, 0xee,
	0xaf, 0xfa, 0x3c, 0x3c, 0x2a, 0xa8, 0x05, 0x05, 0x05, 0x30, 0x2e, 0xec, 0xfe, 0xfe, 0xab, 0xea,
	0x33, 0x33, 0x20, 0x08, 0x05, 0x05, 0x04, 0xf0, 0x3f, 0xfc, 0xaa, 0xaa, 0xaa, 0xaa, 0xcc, 0xcc,
	0x20, 0x08, 0x05, 0x05, 0x00, 0x00, 0x00, 0x00, 0xaa, 0xaa, 0xaa, 0xaa, 0xf3, 0xf3, 0x20, 0x08
};
reversed scattered(16,4) char rainbow_tile[64] = {
	0x60, 0xd1, 0xb5, 0x6a, 0x60, 0xd1, 0xb5, 0x6a, 0xb0, 0x65, 0xd6, 0x9a, 0xb0, 0x65, 0xd6, 0x9a,
	0xd1, 0xb5, 0x6a, 0x79, 0xd1, 0xb5, 0x6a, 0x79, 0x65, 0xd6, 0x9a, 0xe5, 0x65, 0xd6, 0x9a, 0xe5,
	0xb5, 0x6a, 0x79, 0x95, 0xb5, 0x6a, 0x79, 0x95, 0xd6, 0x9a, 0xe5, 0x74, 0xd6, 0x9a, 0xe5, 0x74,
	0x6a, 0x79, 0x95, 0xe0, 0x6a, 0x79, 0x95, 0xe0, 0x9a, 0xe5, 0x74, 0x90, 0x9a, 0xe5, 0x74, 0x90
};
reversed scattered(16,4) char pink_tiles[64] = {
	0x5a, 0x5a, 0x95, 0x95, 0x69, 0x69, 0x65, 0x65, 0x69, 0x69, 0x95, 0x95, 0xa5, 0xa5, 0x65, 0x65,
	0xa5, 0xa5, 0xa9, 0xa9, 0x96, 0x96, 0xa6, 0xa6, 0x96, 0x96, 0xa9, 0xa9, 0x5a, 0x5a, 0xa6, 0xa6,
	0x5a, 0x5a, 0x95, 0x95, 0x69, 0x69, 0x65, 0x65, 0x69, 0x69, 0x95, 0x95, 0xa5, 0xa5, 0x65, 0x65,
	0xa5, 0xa5, 0xa9, 0xa9, 0x96, 0x96, 0xa6, 0xa6, 0x96, 0x96, 0xa9, 0xa9, 0x5a, 0x5a, 0xa6, 0xa6
};
reversed scattered(16,2) char chest[32] = {
	0x00, 0x00, 0x05, 0x50, 0x2b, 0xf4, 0x96, 0xfc, 0x69, 0xbd, 0xbe, 0x6a, 0x55, 0x55, 0xaa, 0xbf,
	0xd5, 0xd5, 0xd9, 0xb7, 0xef, 0x9d, 0xef, 0x9d, 0xef, 0x9d, 0xdd, 0x9d, 0xd5, 0xf7, 0xff, 0x95
};
#define DIGITS_INDEX 24 
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

ramchip int score;
ramchip char display_score_str[5];
ramchip char display_score_ascii[6];

ramchip int x, y;

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
    x = 0; y = 0;

    multisprite_init(MODE_160AB);
    multisprite_set_charbase(tiles);
    tiling_init(tilemap_data);
    joystick_init();
    multisprite_display_tiles(0, 0, display_score_str, 5, 0);
    multisprite_save();
    

    *P0C1 = multisprite_color(0x1c); // Setup Palette 0: Yellow
    *P0C2 = multisprite_color(0xc5); // Green
    *P0C3 = multisprite_color(0xcd); // Light green
   
    *P1C1 = 0x0f; // White
    *P1C2 = multisprite_color(0x9D);
    *P1C3 = multisprite_color(0x97);
    
    *P2C1 = multisprite_color(0x92);
    *P2C2 = multisprite_color(0x97);
    *P2C3 = multisprite_color(0x9D);

    // Rainbow
    *P4C1 = multisprite_color(0x4A);
    *P4C2 = multisprite_color(0x5A);
    *P4C3 = multisprite_color(0x8A);

    *P5C1 = multisprite_color(0xDA);
    *P5C2 = multisprite_color(0x1A);
    *P5C3 = multisprite_color(0x2A);
    
    *P6C1 = multisprite_color(0x3A);
    *P6C2 = 0x0f;

    tiling_goto(0, 0);

    // Main loop
    do {
        multisprite_flip();
        joystick_update();
        if (joystick[0] & JOYSTICK_LEFT) x--; 
        else if (joystick[0] & JOYSTICK_RIGHT) x++;
        if (joystick[0] & JOYSTICK_UP) y--; 
        else if (joystick[0] & JOYSTICK_DOWN) y++;
        tiling_goto(x, y);
        score++;
        display_score_update();
    } while(1);
}
