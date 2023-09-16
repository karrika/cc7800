#include "prosystem.h"
#define VERTICAL_SCROLLING
#define MULTISPRITE_USE_VIDEO_MEMORY
#include "multisprite.h"

// Generated by sprites7800 schmup_tiles.png
reversed scattered(16,32) char blue_objects1[512] = {
	0x00, 0x50, 0x74, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00, 0x55, 0x55, 0x55,
	0x40, 0x00, 0x74, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x54, 0xf8, 0x00, 0x00, 0xa5,
	0x55, 0x55, 0x55, 0x15, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x15, 0x55, 0x55,
	0x10, 0x28, 0xef, 0xd9, 0x6a, 0xa9, 0xa0, 0x00, 0x00, 0x44, 0x55, 0x00, 0xfe, 0xab, 0xea, 0xa0,
	0x45, 0x14, 0x59, 0x95, 0x55, 0x54, 0x55, 0x55, 0x55, 0x55, 0x40, 0x00, 0x00, 0x05, 0x55, 0x55,
	0x00, 0xb8, 0xae, 0x8a, 0xa5, 0x55, 0xa8, 0x01, 0x00, 0x15, 0x55, 0x51, 0xff, 0xea, 0xaa, 0x90,
	0x55, 0x55, 0x55, 0x94, 0x55, 0x55, 0x45, 0x55, 0x15, 0x55, 0x00, 0x00, 0x00, 0x51, 0x45, 0x55,
	0x00, 0xf0, 0xb5, 0x65, 0x00, 0x00, 0x16, 0x00, 0x04, 0x54, 0x55, 0x54, 0xf5, 0xa5, 0x59, 0x40,
	0x55, 0x55, 0x55, 0x95, 0x55, 0x54, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x00, 0x04, 0x55, 0x55,
	0x42, 0xd0, 0x74, 0x21, 0x00, 0x00, 0x06, 0x44, 0x00, 0x55, 0x15, 0x41, 0xf9, 0x95, 0x65, 0x40,
	0x55, 0x16, 0x55, 0x95, 0x55, 0x55, 0x55, 0x55, 0x15, 0x54, 0x00, 0x00, 0x01, 0x00, 0x15, 0x55,
	0x03, 0xc0, 0x23, 0x24, 0x00, 0x01, 0x01, 0x41, 0x00, 0x59, 0x56, 0x55, 0x35, 0x65, 0x95, 0x40,
	0x55, 0x59, 0x95, 0x54, 0x55, 0x65, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00, 0x00, 0x44, 0x15, 0x55,
	0x03, 0x80, 0x23, 0x24, 0x00, 0x01, 0x01, 0xc0, 0x05, 0x55, 0x56, 0x55, 0x24, 0x41, 0x56, 0x40,
	0x55, 0x55, 0x65, 0x55, 0x55, 0x45, 0x05, 0x55, 0x15, 0x40, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55,
	0x09, 0x00, 0x20, 0x34, 0x00, 0x01, 0x00, 0x40, 0x01, 0x50, 0x02, 0x55, 0x14, 0x16, 0x55, 0x40,
	0x55, 0x25, 0x65, 0x69, 0x54, 0x90, 0x55, 0x55, 0x55, 0x40, 0x00, 0x00, 0x00, 0x01, 0x11, 0x55,
	0x48, 0x00, 0x20, 0x34, 0x00, 0x01, 0x00, 0x61, 0x01, 0x5a, 0xaa, 0x55, 0x39, 0x56, 0x59, 0x40,
	0x55, 0x65, 0x55, 0x54, 0x55, 0x85, 0x05, 0x55, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55,
	0x18, 0x01, 0xe4, 0xb7, 0x00, 0x01, 0x00, 0x10, 0x11, 0x55, 0x55, 0x55, 0x14, 0x4a, 0x9a, 0x80,
	0x55, 0x99, 0x55, 0x55, 0x55, 0x55, 0x51, 0x51, 0x55, 0x00, 0x00, 0x00, 0x04, 0x04, 0x41, 0x45,
	0x34, 0x01, 0xaa, 0xd5, 0x00, 0x01, 0x00, 0x10, 0x14, 0x30, 0xf0, 0xc3, 0x39, 0xb5, 0x59, 0x44,
	0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x01, 0x55, 0x54, 0x00, 0x00, 0x00, 0x01, 0x00, 0x15, 0x55,
	0x30, 0x01, 0x8a, 0x91, 0x15, 0x55, 0x00, 0x14, 0x10, 0x3c, 0x30, 0xf0, 0x25, 0x46, 0x5f, 0x84,
	0x56, 0x56, 0x95, 0x59, 0xa5, 0x55, 0x14, 0x55, 0x14, 0x00, 0x00, 0x00, 0x04, 0x04, 0x50, 0x55,
	0x20, 0x02, 0x61, 0x55, 0x25, 0x55, 0x00, 0x04, 0x07, 0x1c, 0x3c, 0x70, 0x35, 0xa9, 0xad, 0x40,
	0x56, 0x56, 0x55, 0x68, 0x65, 0x40, 0x00, 0x55, 0x54, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x15,
	0x20, 0x05, 0x54, 0x05, 0x15, 0x55, 0x00, 0x04, 0x03, 0x4f, 0x0d, 0x3c, 0x28, 0x57, 0x5a, 0x40,
	0x55, 0x55, 0x65, 0x65, 0x24, 0x15, 0x55, 0x15, 0x50, 0x00, 0x00, 0x00, 0x00, 0x40, 0x55, 0x55,
	0x00, 0x1a, 0x54, 0x15, 0x00, 0x01, 0x24, 0x04, 0x03, 0xd6, 0x5f, 0x5d, 0x14, 0x9e, 0xad, 0x40,
	0x59, 0x65, 0xa5, 0x5b, 0x95, 0x41, 0x55, 0x05, 0x10, 0x00, 0x00, 0x00, 0x04, 0x01, 0x00, 0x01
};
reversed scattered(16,32) char blue_objects1_1[512] = {
	0xbf, 0xff, 0x00, 0x00, 0x00, 0x02, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x39, 0x55, 0x5e, 0x40,
	0x59, 0x55, 0xd5, 0xa5, 0x55, 0x54, 0x10, 0x15, 0x50, 0x00, 0x00, 0x00, 0x01, 0x00, 0x11, 0x55,
	0xaa, 0xaa, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x2b, 0xff, 0xff, 0xff, 0x35, 0x66, 0x5d, 0x40,
	0x55, 0x55, 0x69, 0xa5, 0x55, 0x50, 0x54, 0x05, 0x40, 0x00, 0x00, 0x00, 0x00, 0x04, 0x55, 0x55,
	0x55, 0x95, 0x61, 0x28, 0x60, 0xab, 0x51, 0x55, 0x16, 0xfa, 0xeb, 0xeb, 0x25, 0x96, 0x9e, 0x48,
	0x65, 0x96, 0x5b, 0x54, 0x45, 0x40, 0x00, 0x05, 0x40, 0x00, 0x00, 0x00, 0x00, 0x14, 0x05, 0x55,
	0x04, 0x04, 0xa0, 0xb8, 0xa8, 0xa7, 0x50, 0x05, 0x14, 0x30, 0xf1, 0xc3, 0x39, 0x56, 0x59, 0x40,
	0x55, 0x45, 0x5d, 0x55, 0x55, 0x55, 0x50, 0x45, 0x40, 0x00, 0x00, 0x00, 0x00, 0x51, 0x00, 0x15,
	0x04, 0x34, 0x00, 0xf0, 0x1a, 0x03, 0x40, 0x55, 0x04, 0x3c, 0x30, 0xf0, 0x24, 0x6a, 0xbe, 0x80,
	0x55, 0x55, 0x59, 0x55, 0x55, 0x40, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x14, 0x55, 0x55,
	0x06, 0x90, 0x02, 0xd0, 0x05, 0x01, 0x50, 0x04, 0x07, 0x1c, 0x3c, 0x30, 0x29, 0xab, 0xed, 0x40,
	0x55, 0x55, 0x75, 0x15, 0x55, 0x51, 0x41, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x54, 0x55,
	0x01, 0xd0, 0x03, 0xc0, 0x02, 0x42, 0x40, 0x05, 0x03, 0x0f, 0x0c, 0x3c, 0x3a, 0xaf, 0xfd, 0x40,
	0x55, 0x56, 0x65, 0x55, 0x55, 0x50, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55, 0x15,
	0x02, 0x40, 0x03, 0x80, 0x00, 0xc1, 0x42, 0x15, 0x01, 0x59, 0x55, 0x55, 0x25, 0xaa, 0x95, 0x40,
	0x55, 0x55, 0x55, 0x55, 0x55, 0x50, 0x41, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x04, 0x45, 0x41,
	0x03, 0x40, 0x09, 0x00, 0x00, 0x41, 0x40, 0x01, 0x01, 0x50, 0x01, 0x55, 0xfa, 0xa9, 0x65, 0x80,
	0x95, 0x55, 0x95, 0x15, 0x55, 0x54, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x16,
	0x09, 0x00, 0x08, 0x00, 0x00, 0xa1, 0x42, 0x05, 0x01, 0x5e, 0xaa, 0x55, 0xb5, 0x55, 0x6a, 0x40,
	0x95, 0x55, 0x55, 0x55, 0x55, 0x54, 0x04, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x45, 0x56,
	0x0d, 0x10, 0x18, 0x01, 0x00, 0x21, 0x51, 0x01, 0x01, 0x59, 0x56, 0x55, 0xe5, 0x55, 0x45, 0x40,
	0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x56,
	0x04, 0x14, 0x34, 0x01, 0x00, 0x11, 0x50, 0x05, 0x00, 0x55, 0x05, 0x54, 0x80, 0x00, 0x00, 0x00,
	0x55, 0x55, 0x55, 0x55, 0x55, 0x14, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x15, 0x56,
	0x34, 0x04, 0x30, 0x01, 0x00, 0x16, 0x54, 0x54, 0x00, 0x55, 0x51, 0x01, 0x90, 0x10, 0x00, 0x00,
	0x55, 0x56, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x56,
	0xbf, 0xff, 0x20, 0x02, 0x00, 0x04, 0x51, 0x54, 0x00, 0x04, 0x05, 0x54, 0x00, 0x00, 0x00, 0x00,
	0x55, 0x5a, 0x45, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x56,
	0xaa, 0xaa, 0x20, 0x01, 0x00, 0x00, 0x55, 0x15, 0x04, 0x05, 0x55, 0x55, 0x40, 0x10, 0x00, 0x01,
	0x55, 0x12, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x56,
	0x95, 0x65, 0x00, 0x16, 0x24, 0x04, 0x55, 0x55, 0x2a, 0xaa, 0xaa, 0xa6, 0x00, 0x00, 0x00, 0x00,
	0x65, 0x56, 0x50, 0x00, 0x15, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x56
};
reversed scattered(16,32) char blue_objects1_2[512] = {
	0x95, 0x5d, 0x00, 0x1a, 0x14, 0x04, 0x20, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00,
	0x51, 0x56, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x56,
	0x80, 0x0a, 0x20, 0x01, 0x00, 0x04, 0x10, 0x00, 0x00, 0x3f, 0xbf, 0xff, 0xff, 0xff, 0xf4, 0x00,
	0x51, 0x46, 0x55, 0x55, 0x15, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x56,
	0x90, 0x0d, 0x20, 0x01, 0x00, 0x04, 0x75, 0x55, 0x10, 0x3a, 0xa2, 0xaa, 0xaa, 0xb8, 0x64, 0x09,
	0x40, 0x01, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x56,
	0x80, 0x0e, 0x30, 0x02, 0x00, 0x10, 0x20, 0x04, 0x00, 0xe9, 0x41, 0xaa, 0xaa, 0xa4, 0x29, 0x08,
	0x10, 0x00, 0x55, 0x55, 0x15, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x56,
	0x90, 0x39, 0x34, 0x01, 0x00, 0x10, 0x10, 0x04, 0x00, 0xa9, 0x40, 0x96, 0x65, 0x64, 0x58, 0x09,
	0x04, 0x00, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x55, 0x55,
	0x94, 0x9e, 0x14, 0x01, 0x00, 0x10, 0x10, 0x04, 0x03, 0xa9, 0x40, 0x14, 0x55, 0x64, 0x59, 0x0d,
	0x04, 0x00, 0x15, 0x55, 0x15, 0x54, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x55, 0x56,
	0x88, 0xd9, 0x08, 0x00, 0x00, 0x90, 0x10, 0x08, 0x52, 0xa8, 0x00, 0x00, 0x00, 0x10, 0x05, 0x2d,
	0x00, 0x00, 0x15, 0x55, 0x55, 0x50, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x55, 0x56,
	0x86, 0x4e, 0x0a, 0x00, 0x00, 0x40, 0x10, 0x04, 0x40, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x41, 0x1e,
	0x01, 0x00, 0x15, 0x55, 0x55, 0x50, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x56,
	0x83, 0x5d, 0x03, 0x40, 0x01, 0xc0, 0x10, 0x04, 0x51, 0xa9, 0x00, 0x00, 0x00, 0x31, 0x41, 0x2d,
	0x40, 0x00, 0x05, 0x55, 0x15, 0x50, 0x00, 0x01, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0e, 0x55, 0x55,
	0x89, 0x0a, 0x03, 0xc0, 0x02, 0x40, 0x10, 0x04, 0x00, 0x28, 0x08, 0x00, 0x00, 0xf4, 0x00, 0x1e,
	0x40, 0x00, 0x05, 0x55, 0x55, 0x40, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0d, 0x55, 0x59,
	0x8d, 0x0d, 0x01, 0xd0, 0x05, 0x00, 0x10, 0x04, 0x40, 0x29, 0x06, 0x50, 0x03, 0xd4, 0x50, 0x0d,
	0x40, 0x00, 0x05, 0x55, 0x55, 0x40, 0x00, 0x01, 0x00, 0x00, 0x50, 0x00, 0x00, 0x05, 0x51, 0x55,
	0x84, 0x19, 0x00, 0xf0, 0x1a, 0x00, 0x10, 0x04, 0x00, 0x04, 0x01, 0x94, 0x0f, 0xc0, 0x15, 0x59,
	0x40, 0x00, 0x00, 0x55, 0x15, 0x40, 0x00, 0x05, 0x40, 0x14, 0x00, 0x00, 0x00, 0x35, 0x59, 0x59,
	0x94, 0x6a, 0x14, 0x78, 0xa8, 0x02, 0x10, 0x04, 0x00, 0x44, 0x00, 0x55, 0x3f, 0x50, 0xd3, 0xd8,
	0x40, 0x00, 0x00, 0x55, 0x54, 0x00, 0x00, 0x05, 0x40, 0x00, 0x54, 0x00, 0x00, 0xd5, 0x97, 0x55,
	0x90, 0x1d, 0x15, 0x18, 0xa0, 0x01, 0x10, 0x08, 0x01, 0x00, 0x00, 0x14, 0xfd, 0x40, 0xc7, 0xe5,
	0x50, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x05, 0x40, 0x00, 0x51, 0x00, 0x00, 0xa5, 0x55, 0x59,
	0x80, 0x0d, 0x15, 0x40, 0x00, 0x05, 0x10, 0x04, 0x00, 0x00, 0x00, 0x03, 0xf5, 0x00, 0x51, 0x94,
	0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x40, 0x50, 0x14, 0x00, 0x03, 0x56, 0x55, 0x65,
	0x90, 0x0e, 0x74, 0x25, 0x55, 0x55, 0x11, 0x55, 0x00, 0x00, 0x00, 0x0f, 0xd4, 0x00, 0x41, 0x45,
	0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x50, 0x00, 0x14, 0x50, 0x09, 0x59, 0x15, 0x75
};
reversed scattered(16,32) char blue_objects1_3[512] = {
	0x00, 0x16, 0x74, 0x29, 0x55, 0x55, 0x14, 0x00, 0x26, 0xaa, 0x00, 0x3f, 0x51, 0x00, 0x10, 0x08,
	0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x50, 0x40, 0x55, 0x55, 0x95, 0x55, 0x45, 0x75,
	0x20, 0x01, 0xe0, 0xd9, 0x55, 0x55, 0x00, 0x04, 0x55, 0x55, 0x00, 0xfd, 0x45, 0x00, 0x40, 0x04,
	0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x50, 0x00, 0x51, 0x55, 0x55, 0x56, 0x65, 0x95,
	0x20, 0x02, 0x6c, 0x86, 0x55, 0x15, 0x00, 0x04, 0x5a, 0xa9, 0x03, 0xf5, 0x02, 0x40, 0x10, 0x04,
	0x54, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x01, 0x51, 0x55, 0xa5, 0x59, 0x55, 0xd5,
	0x30, 0x01, 0xb4, 0x65, 0x55, 0x15, 0x00, 0x14, 0x6a, 0xa4, 0x0f, 0xd4, 0x01, 0x80, 0x40, 0x10,
	0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x54, 0x01, 0x55, 0x55, 0xa5, 0x55, 0x95, 0xd5,
	0x34, 0x01, 0x74, 0x01, 0x55, 0x55, 0x00, 0x10, 0x65, 0x68, 0x4d, 0x50, 0x00, 0x61, 0x20, 0x04,
	0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x54, 0x55, 0x41, 0x55, 0x55, 0x55, 0x56, 0x55,
	0x24, 0x01, 0x20, 0x00, 0x54, 0x15, 0x00, 0x10, 0x55, 0x54, 0x54, 0x40, 0x00, 0x1d, 0x5a, 0x00,
	0x55, 0x40, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x55, 0x05, 0x40, 0x55, 0x55, 0x65, 0x57, 0x55,
	0x48, 0x00, 0x20, 0x00, 0x55, 0x65, 0x00, 0xa0, 0x56, 0x64, 0x51, 0x00, 0x00, 0x05, 0x49, 0x00,
	0x55, 0x40, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55, 0x55, 0x55, 0x05, 0x55, 0x5a, 0x55, 0x65, 0x55,
	0x0a, 0x00, 0x10, 0x24, 0x55, 0x25, 0x00, 0x41, 0x19, 0x50, 0x40, 0x00, 0x00, 0x25, 0x05, 0x00,
	0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x05, 0x55, 0x55, 0x45, 0x05, 0x55, 0x69, 0x59, 0x59, 0x55,
	0x03, 0x80, 0x20, 0x34, 0x55, 0x15, 0x01, 0xc0, 0x6a, 0x60, 0x53, 0xff, 0xff, 0xd5, 0x41, 0x00,
	0x55, 0x50, 0x00, 0x00, 0x00, 0x00, 0x15, 0x55, 0x55, 0x41, 0x55, 0x55, 0xa6, 0xa5, 0x65, 0x55,
	0x43, 0xc0, 0x00, 0x37, 0x54, 0x55, 0x02, 0x40, 0x56, 0x80, 0x51, 0xff, 0xff, 0xd5, 0x40, 0x00,
	0x55, 0x54, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x55, 0x55, 0x01, 0x55, 0x59, 0x55, 0xa5, 0x51,
	0x11, 0xd0, 0x00, 0xd5, 0x55, 0x55, 0x15, 0x00, 0x69, 0x40, 0x50, 0xaa, 0xaa, 0x91, 0x00, 0x00,
	0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x59, 0x55, 0x95, 0x57,
	0x04, 0xf0, 0x80, 0x91, 0x55, 0x55, 0x1a, 0x00, 0x65, 0x40, 0x00, 0x6a, 0xaa, 0x90, 0x00, 0x04,
	0x55, 0x55, 0x40, 0x00, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x51, 0x55, 0x59, 0x57, 0x55, 0x55,
	0x00, 0xb8, 0x41, 0x55, 0x55, 0x55, 0xa8, 0x04, 0x54, 0x00, 0x00, 0x15, 0x55, 0x40, 0x00, 0x04,
	0x55, 0x55, 0x40, 0x00, 0x00, 0x05, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x59, 0x55, 0x55,
	0x00, 0x18, 0x54, 0x05, 0x55, 0x55, 0xa0, 0x01, 0x64, 0x00, 0x00, 0x15, 0x55, 0x50, 0x00, 0x00,
	0x55, 0x55, 0x54, 0x00, 0x00, 0x15, 0x15, 0x55, 0x55, 0x54, 0x55, 0x55, 0x55, 0x65, 0x15, 0x55,
	0x00, 0x40, 0x54, 0x15, 0x54, 0x45, 0x00, 0x44, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x55, 0x55, 0x55, 0x00, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x51, 0x55, 0x55, 0x95, 0x55, 0x55,
	0x00, 0x00, 0x04, 0x01, 0x49, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x55, 0x55, 0x55, 0x50, 0x15, 0x55, 0x15, 0x55, 0x55, 0x55, 0x55, 0x9a, 0x6a, 0x55, 0x15, 0x55
};
reversed scattered(16,32) char blue_objects1_4[512] = {
	0x12, 0x55, 0x01, 0x54, 0x6a, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xa9, 0x9b,
	0x55, 0x55, 0x55, 0xbf, 0xfd, 0x55, 0x55, 0x55, 0x00, 0x00, 0x00, 0x69, 0xa8, 0x00, 0x00, 0x00,
	0x10, 0x40, 0x41, 0x51, 0xaa, 0x96, 0x9a, 0x5a, 0x56, 0x99, 0x9a, 0x9a, 0xaa, 0xa9, 0x55, 0x56,
	0x55, 0x54, 0x5a, 0x69, 0xaa, 0x55, 0x45, 0x55, 0x00, 0x00, 0x0a, 0x55, 0x45, 0x40, 0x00, 0x00,
	0x00, 0x02, 0x41, 0x55, 0x95, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x56,
	0x45, 0x55, 0x6a, 0xa9, 0xaa, 0xa5, 0x55, 0x55, 0x00, 0x00, 0x29, 0x95, 0x55, 0x50, 0x00, 0x00,
	0x14, 0x40, 0x42, 0x49, 0x55, 0x55, 0x51, 0x65, 0x55, 0x55, 0x55, 0x51, 0x55, 0x51, 0x55, 0x46,
	0x55, 0x15, 0xaa, 0xa9, 0xaa, 0xa9, 0x45, 0x55, 0x00, 0x00, 0xa5, 0x55, 0x55, 0x54, 0x00, 0x00,
	0x00, 0x86, 0x52, 0x85, 0x95, 0x55, 0x54, 0x55, 0x55, 0x55, 0x54, 0x10, 0x55, 0x5d, 0x95, 0x56,
	0x55, 0x55, 0xea, 0xe8, 0xaa, 0xa5, 0x55, 0x55, 0x00, 0x00, 0x95, 0x95, 0x55, 0x55, 0x00, 0x00,
	0x00, 0x86, 0x40, 0x81, 0x95, 0x51, 0x44, 0x90, 0x50, 0x00, 0x51, 0x51, 0x54, 0x11, 0x55, 0x56,
	0x55, 0x57, 0xaa, 0xa9, 0xaa, 0xa9, 0x55, 0x55, 0x00, 0x03, 0x95, 0x54, 0x55, 0x55, 0x00, 0x00,
	0x01, 0x82, 0x40, 0x01, 0x56, 0x9a, 0x94, 0x9a, 0xaa, 0xaa, 0xa0, 0x00, 0xaa, 0x95, 0x55, 0x56,
	0x55, 0x1b, 0xea, 0x99, 0xa9, 0xb5, 0x55, 0x55, 0x00, 0x09, 0x55, 0x45, 0x55, 0xa5, 0x40, 0x00,
	0x03, 0x02, 0x68, 0x01, 0x95, 0x55, 0x54, 0x55, 0x55, 0x55, 0x54, 0x50, 0x55, 0x55, 0x55, 0x67,
	0x55, 0x5e, 0xfa, 0x85, 0xa9, 0x99, 0x45, 0x55, 0x00, 0x0d, 0x65, 0x51, 0x54, 0x51, 0x50, 0x00,
	0x0e, 0x82, 0x00, 0x05, 0x95, 0x55, 0x50, 0x55, 0x55, 0x55, 0x54, 0x02, 0x55, 0x45, 0x55, 0x56,
	0x55, 0x3e, 0xaa, 0x79, 0xa9, 0xa6, 0x55, 0x55, 0x00, 0x35, 0x65, 0x58, 0x55, 0x54, 0x10, 0x00,
	0x0e, 0x82, 0x00, 0x01, 0x95, 0x55, 0x50, 0x51, 0x55, 0x55, 0x55, 0x02, 0x55, 0x55, 0x55, 0x56,
	0x55, 0x7f, 0xea, 0xe9, 0xa9, 0xaa, 0x41, 0x55, 0x00, 0x35, 0x55, 0x95, 0x55, 0x81, 0x44, 0x00,
	0x39, 0x52, 0x00, 0x05, 0x95, 0x55, 0x40, 0x05, 0x55, 0x55, 0x55, 0x01, 0x55, 0x54, 0x55, 0x55,
	0x55, 0xef, 0xee, 0xa9, 0xa9, 0xe9, 0x55, 0x55, 0x00, 0xd5, 0x55, 0x54, 0x54, 0x94, 0x54, 0x00,
	0x36, 0xa2, 0x06, 0x05, 0x55, 0x55, 0x50, 0x95, 0x55, 0x55, 0x55, 0x01, 0x55, 0x45, 0x56, 0x56,
	0x55, 0xbf, 0xea, 0xa9, 0xa9, 0x69, 0x81, 0x55, 0x00, 0xd9, 0x55, 0x55, 0x55, 0x51, 0x15, 0x00,
	0xe5, 0x66, 0x84, 0x81, 0x95, 0x55, 0x5a, 0x51, 0x55, 0x55, 0x55, 0x49, 0x55, 0x55, 0x56, 0x56,
	0x56, 0xfb, 0xaa, 0xaa, 0xf9, 0x95, 0x14, 0x55, 0x02, 0x56, 0x95, 0x5a, 0x95, 0x55, 0x00, 0x00,
	0xea, 0xa4, 0x04, 0x40, 0x80, 0x11, 0x58, 0x51, 0x55, 0x55, 0x55, 0x49, 0x00, 0x55, 0x55, 0x56,
	0x57, 0xaf, 0x9a, 0xbf, 0x69, 0x51, 0x54, 0x55, 0x02, 0x56, 0x55, 0x59, 0x65, 0x44, 0x00, 0x00,
	0xe5, 0x44, 0x04, 0x85, 0x90, 0x00, 0x50, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x05, 0x56, 0x56,
	0x57, 0xf9, 0xee, 0xbf, 0x79, 0x54, 0x11, 0x15, 0x01, 0x55, 0x65, 0x65, 0x65, 0x51, 0x54, 0x00,
	0xd0, 0x50, 0x40, 0x45, 0xa7, 0x0c, 0xa7, 0x0c, 0x9d, 0x74, 0x1d, 0x74, 0x31, 0xd5, 0x56, 0x16,
	0x5e, 0xa7, 0xea, 0xfe, 0xa9, 0x54, 0x05, 0x05, 0x09, 0x61, 0xa5, 0x5b, 0x65, 0x54, 0x41, 0x00
};
reversed scattered(16,32) char blue_objects1_5[512] = {
	0xe4, 0x00, 0x05, 0x50, 0xa7, 0x4d, 0xa7, 0x4d, 0x9d, 0x74, 0x1d, 0x74, 0x31, 0xd4, 0x16, 0xa7,
	0x5e, 0x96, 0xf7, 0xfe, 0xaa, 0x40, 0x00, 0x15, 0x09, 0x55, 0xd5, 0xa5, 0x55, 0x45, 0x50, 0x40,
	0xe4, 0x00, 0x05, 0x50, 0xa5, 0x45, 0xa5, 0x45, 0x95, 0x54, 0x15, 0x54, 0x15, 0x45, 0x55, 0x56,
	0x56, 0xa7, 0x7b, 0xaa, 0x56, 0x50, 0x04, 0x05, 0x05, 0x55, 0x69, 0xa5, 0x55, 0x55, 0x54, 0x00,
	0xc0, 0x00, 0x04, 0x00, 0x95, 0x55, 0x55, 0x51, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x56,
	0x6a, 0xaa, 0xef, 0x69, 0x56, 0x80, 0x10, 0x05, 0x25, 0x96, 0x5b, 0x55, 0x55, 0x55, 0x01, 0x00,
	0xe0, 0x00, 0x05, 0x50, 0x95, 0x55, 0x55, 0x51, 0x55, 0x55, 0x55, 0x45, 0x55, 0x55, 0x55, 0x56,
	0x6a, 0x99, 0xbe, 0x59, 0x59, 0x54, 0x00, 0x05, 0x25, 0x55, 0x5d, 0x55, 0x45, 0x50, 0x00, 0x00,
	0xe0, 0x10, 0x04, 0x50, 0x95, 0x55, 0x55, 0x40, 0x55, 0x55, 0x55, 0x51, 0x55, 0x55, 0x55, 0x56,
	0x6a, 0x6e, 0xae, 0x6a, 0x99, 0x41, 0x40, 0x01, 0x15, 0x55, 0x59, 0x55, 0x55, 0x00, 0x00, 0x00,
	0xc0, 0x10, 0x0d, 0x00, 0x95, 0x55, 0x54, 0x40, 0x55, 0x55, 0x51, 0x55, 0x55, 0x45, 0x15, 0x56,
	0xaa, 0xaa, 0xba, 0x55, 0xa5, 0x51, 0x00, 0x01, 0x55, 0x55, 0x75, 0x15, 0x55, 0x51, 0x40, 0x00,
	0xd0, 0x40, 0x2c, 0x40, 0x95, 0x55, 0x51, 0x45, 0x55, 0x55, 0x50, 0x15, 0x55, 0x54, 0x55, 0x56,
	0xaa, 0xa6, 0xb6, 0x66, 0x96, 0x50, 0x40, 0x01, 0x55, 0x55, 0x65, 0x55, 0x55, 0x50, 0x10, 0x00,
	0xe0, 0x20, 0x34, 0xc0, 0x95, 0x55, 0x55, 0x45, 0x55, 0x55, 0x50, 0x85, 0x55, 0x55, 0x55, 0x56,
	0xaa, 0xab, 0xe6, 0x5a, 0x59, 0xa0, 0x10, 0x01, 0x95, 0x55, 0x55, 0x55, 0x55, 0x51, 0x00, 0x00,
	0xe0, 0x24, 0x38, 0xc0, 0x94, 0x01, 0x50, 0x20, 0x00, 0x00, 0x50, 0x95, 0x55, 0x55, 0x55, 0x56,
	0xaa, 0xaa, 0xea, 0x66, 0xaa, 0x90, 0x41, 0x01, 0x95, 0x55, 0x95, 0x15, 0x55, 0x54, 0x40, 0x00,
	0xe8, 0x14, 0x34, 0xe0, 0xa5, 0x99, 0xa0, 0x95, 0xaa, 0xaa, 0xa8, 0xaa, 0xaa, 0xa4, 0x15, 0x56,
	0xaa, 0xab, 0xe9, 0x6a, 0x65, 0x94, 0x00, 0x01, 0x95, 0x55, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00,
	0xe4, 0x14, 0xb4, 0xe0, 0x95, 0x55, 0x50, 0x51, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x5b,
	0xaa, 0xab, 0xea, 0x59, 0x59, 0x54, 0x00, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50, 0x00, 0x00,
	0xe4, 0x08, 0xf4, 0xe4, 0x95, 0x55, 0x50, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50, 0x55, 0x56,
	0xaa, 0xab, 0xa5, 0xa9, 0x6a, 0x64, 0x00, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x10, 0x00,
	0xe4, 0x09, 0xe0, 0xe8, 0x55, 0x55, 0x52, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x50, 0x15, 0x56,
	0xea, 0xab, 0x56, 0x5a, 0x56, 0x59, 0x00, 0x00, 0x55, 0x56, 0x55, 0x55, 0x55, 0x55, 0x00, 0x00,
	0xe4, 0x04, 0xd0, 0xe4, 0x95, 0x15, 0x40, 0x14, 0x50, 0x55, 0x44, 0x55, 0x55, 0x50, 0x55, 0x56,
	0x6a, 0x9f, 0x9a, 0x99, 0x56, 0x55, 0x40, 0x00, 0x55, 0x59, 0x45, 0x55, 0x55, 0x55, 0x00, 0x00,
	0xe4, 0x06, 0xd0, 0xe4, 0x94, 0x45, 0x00, 0x01, 0x40, 0x00, 0x01, 0x00, 0x00, 0x00, 0x55, 0x56,
	0x69, 0x5b, 0x65, 0x56, 0x5a, 0xa9, 0x00, 0x00, 0x55, 0x56, 0x55, 0x55, 0x55, 0x54, 0x00, 0x00,
	0xe4, 0x07, 0xd0, 0xe4, 0xd0, 0x00, 0x04, 0x00, 0x00, 0x55, 0x50, 0x00, 0x00, 0x05, 0x15, 0x56,
	0x7a, 0xae, 0x54, 0x55, 0x5a, 0x54, 0x00, 0x00, 0x65, 0x56, 0x55, 0x55, 0x15, 0x55, 0x00, 0x00
};
reversed scattered(16,20) char blue_objects2[320] = {
	0xe8, 0x03, 0x80, 0xe4, 0x11, 0x50, 0x01, 0x40, 0x00, 0x54, 0xaa, 0xa8, 0xaa, 0xaa, 0xef, 0xab,
	0x45, 0x16, 0xaa, 0xaa, 0xe4, 0x03, 0x40, 0xe4, 0x01, 0x40, 0x01, 0x44, 0x05, 0x54, 0x99, 0x59,
	0x65, 0x68, 0x9a, 0xae, 0x55, 0x56, 0x65, 0x56, 0xe8, 0x0b, 0x40, 0xe4, 0x29, 0x48, 0x81, 0x41,
	0x01, 0x54, 0x55, 0x69, 0x55, 0x58, 0x9a, 0xab, 0x40, 0x02, 0x6a, 0xa9, 0xe4, 0x0f, 0x40, 0xe4,
	0x05, 0x44, 0x51, 0x51, 0x15, 0x54, 0x66, 0x59, 0x62, 0x58, 0x9a, 0x5e, 0x04, 0x40, 0x66, 0x55,
	0xe4, 0x0e, 0x00, 0xe8, 0x55, 0x41, 0x55, 0x15, 0x00, 0x55, 0xaa, 0x6a, 0xa6, 0x5a, 0x8a, 0x6f,
	0x00, 0x00, 0x55, 0x69, 0xe4, 0x0d, 0x10, 0xe4, 0x55, 0x40, 0x55, 0x15, 0x04, 0x55, 0x66, 0x55,
	0x62, 0x55, 0xaa, 0xae, 0x01, 0x40, 0x59, 0x5a, 0xe4, 0x2d, 0x10, 0xe4, 0x55, 0x45, 0x55, 0x55,
	0x59, 0x55, 0x66, 0x6a, 0x66, 0x55, 0xaa, 0xab, 0x00, 0x00, 0x15, 0x56, 0xe4, 0x3d, 0x60, 0xe4,
	0x45, 0x44, 0x55, 0x55, 0x14, 0x55, 0xaa, 0x55, 0x62, 0x45, 0xaa, 0xff, 0x04, 0x00, 0x15, 0x59,
	0xe4, 0x38, 0x24, 0xe4, 0x55, 0x40, 0x55, 0x55, 0x00, 0x55, 0x6a, 0x6a, 0xaa, 0x52, 0xaa, 0xaf,
	0x00, 0x00, 0x19, 0x6a, 0xe4, 0x34, 0x14, 0xe4, 0x55, 0x55, 0x55, 0x55, 0x00, 0x55, 0x6a, 0x65,
	0x66, 0x59, 0xaa, 0xaf, 0x00, 0x00, 0x05, 0xa5, 0xe4, 0xb4, 0x10, 0xe4, 0x55, 0x55, 0x54, 0x55,
	0x59, 0x15, 0xaa, 0x5a, 0xaa, 0x55, 0xa9, 0x56, 0x00, 0x00, 0x05, 0x56, 0xf9, 0xd0, 0x08, 0x90,
	0x55, 0x55, 0x50, 0x55, 0x04, 0x55, 0xa5, 0x59, 0x96, 0x41, 0xab, 0x56, 0x00, 0x00, 0x01, 0xaa,
	0xe4, 0x60, 0x0b, 0x50, 0x55, 0x55, 0x52, 0x55, 0x55, 0x55, 0x6a, 0xa5, 0x59, 0x42, 0xaa, 0x57,
	0x00, 0x00, 0x00, 0x15, 0xe4, 0x10, 0x01, 0x10, 0x55, 0x55, 0x51, 0x55, 0x50, 0x55, 0x99, 0x55,
	0x65, 0x41, 0xab, 0x5a, 0x00, 0x00, 0x00, 0x15, 0xf5, 0x00, 0x09, 0x50, 0x55, 0x55, 0x55, 0x55,
	0x44, 0x55, 0x55, 0xaa, 0x55, 0x6a, 0xaa, 0x56, 0x00, 0x00, 0x00, 0x0a, 0xc0, 0x40, 0x05, 0x50,
	0x55, 0x54, 0x05, 0x40, 0x40, 0x01, 0x51, 0x55, 0x15, 0x55, 0x6a, 0x57, 0x00, 0x00, 0x00, 0x05
};
reversed scattered(16,16) char blue_objects3[256] = {
	0xe0, 0x40, 0x01, 0x40, 0x55, 0x55, 0x9a, 0x9a, 0xaa, 0x95, 0xda, 0xa9, 0xba, 0xa9, 0x6b, 0xaf,
	0xd4, 0x5d, 0x01, 0x40, 0x55, 0x55, 0x55, 0x55, 0x51, 0x95, 0xaa, 0xa9, 0x55, 0xa9, 0x6a, 0xae,
	0xe0, 0x04, 0x00, 0x00, 0x55, 0x54, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0x59, 0xa9, 0x6a, 0xaf,
	0xe4, 0x14, 0x09, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55, 0x95, 0xaa, 0xa9, 0xaa, 0xe9, 0x6a, 0xae,
	0xa8, 0x10, 0x09, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55, 0x95, 0xaa, 0xaa, 0x55, 0xea, 0x6a, 0xaf,
	0x19, 0x04, 0x02, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xa9, 0x56, 0xe9, 0x6a, 0xae,
	0x1a, 0x49, 0x02, 0x40, 0x55, 0x54, 0x55, 0x55, 0x51, 0x55, 0xaa, 0xa9, 0x55, 0x6a, 0x6a, 0xab,
	0x01, 0x4d, 0x01, 0x40, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xa9, 0xaa, 0xa9, 0x6a, 0xaf,
	0x05, 0x0d, 0x01, 0x00, 0x40, 0x15, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xa9, 0xaa, 0xa9, 0x6a, 0xaf,
	0x00, 0x0e, 0x00, 0x00, 0x54, 0x15, 0x55, 0x55, 0xa6, 0x55, 0xaa, 0xaa, 0xae, 0xa9, 0x6a, 0xa6,
	0x00, 0xcd, 0x04, 0x00, 0x44, 0x14, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xa9, 0xaa, 0xaa, 0x6a, 0xaf,
	0x01, 0x85, 0x01, 0x00, 0x44, 0x15, 0x55, 0x55, 0x55, 0x55, 0xaa, 0xaa, 0xaa, 0xa9, 0x6a, 0xae,
	0x3f, 0xff, 0xfa, 0xac, 0x40, 0x14, 0x55, 0x55, 0x55, 0x56, 0xaa, 0xa9, 0xa9, 0xa7, 0x6a, 0xaf,
	0x1b, 0xf9, 0x80, 0x04, 0x55, 0x55, 0x55, 0x55, 0x54, 0x55, 0xff, 0xfe, 0xf5, 0xf6, 0x6a, 0xae,
	0x1a, 0xa5, 0x81, 0x00, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0xff, 0xff, 0xff, 0xf6, 0x6a, 0xaf,
	0x15, 0x95, 0x40, 0x00, 0x55, 0x54, 0xaa, 0x5a, 0xaa, 0x96, 0xff, 0xfd, 0xff, 0xff, 0x6a, 0xae
};
reversed scattered(16,12) char grey_objects1[192] = {
	0x55, 0x55, 0x57, 0xf5, 0x0d, 0x20, 0x00, 0x00, 0x10, 0x04, 0x00, 0x00, 0x91, 0x45, 0x03, 0xf0,
	0x0e, 0x40, 0x0f, 0x50, 0x0f, 0x54, 0x00, 0x00, 0xa6, 0x64, 0x1f, 0xf1, 0x0d, 0xc0, 0x0a, 0x10,
	0x0a, 0x10, 0x00, 0x00, 0x75, 0x50, 0x0f, 0xe4, 0x06, 0x00, 0x09, 0x10, 0x09, 0x20, 0x00, 0x00,
	0x10, 0x00, 0x2e, 0xb8, 0x01, 0x62, 0x1e, 0x10, 0x0a, 0x10, 0x00, 0x00, 0x1f, 0x50, 0xff, 0xe6,
	0x02, 0xb7, 0xeb, 0x9a, 0xe9, 0x10, 0xa0, 0x00, 0x9e, 0x41, 0xff, 0xf7, 0x01, 0x85, 0xfb, 0xdf,
	0xf8, 0x00, 0xf8, 0x00, 0x5c, 0x50, 0xef, 0xf5, 0x00, 0xc5, 0xe7, 0x4a, 0xef, 0x50, 0x73, 0x00,
	0x55, 0x50, 0x9b, 0xf5, 0x00, 0xc4, 0x92, 0x45, 0x9a, 0x10, 0x53, 0x00, 0x55, 0x50, 0x45, 0x00,
	0x00, 0x25, 0x41, 0x00, 0x49, 0x20, 0x11, 0x40, 0x15, 0x40, 0x84, 0x01, 0x00, 0x09, 0x92, 0x45,
	0x99, 0x10, 0x5c, 0x40, 0x15, 0x40, 0x44, 0x41, 0x00, 0x05, 0x55, 0x46, 0x54, 0x00, 0x45, 0x00,
	0x95, 0xa0, 0x02, 0x91, 0x00, 0x00, 0x10, 0x04, 0x0f, 0x50, 0x00, 0xa0, 0x50, 0x00, 0x46, 0xa0,
	0x00, 0x00, 0x10, 0x04, 0x09, 0x20, 0x13, 0x10, 0x51, 0x10, 0x06, 0xa0, 0x00, 0x00, 0x00, 0x00,
	0x0a, 0x10, 0x01, 0x20, 0x50, 0x00, 0x01, 0x51, 0x00, 0x00, 0x00, 0x00, 0x09, 0x10, 0x1e, 0x20
};
reversed scattered(16,16) char grey_objects2[256] = {
	0x00, 0x00, 0x1e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
	0x00, 0x00, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x50, 0x0f, 0x50,
	0x00, 0x00, 0x13, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x10, 0x09, 0x10,
	0x00, 0x05, 0x00, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x20, 0x0d, 0x10,
	0x00, 0x41, 0x45, 0x00, 0x00, 0x14, 0x15, 0x64, 0x14, 0x00, 0x15, 0x64, 0x0a, 0x10, 0x0a, 0x10,
	0x00, 0x0a, 0x5c, 0x40, 0x00, 0x1a, 0xeb, 0x9a, 0xa4, 0x00, 0xeb, 0x9a, 0x09, 0x1b, 0x09, 0x10,
	0x00, 0x6f, 0x11, 0x40, 0x00, 0xcf, 0xfb, 0xcf, 0xf3, 0x00, 0xfb, 0xcf, 0x08, 0x0f, 0x00, 0x00,
	0x00, 0xde, 0x53, 0x00, 0x00, 0x5a, 0xe7, 0x4a, 0xa5, 0x00, 0xe7, 0x4a, 0x0f, 0x5b, 0x0f, 0x50,
	0x04, 0xc5, 0x73, 0x00, 0x00, 0x45, 0x92, 0x45, 0x51, 0x00, 0x92, 0x45, 0x0a, 0x16, 0x0a, 0x10,
	0x03, 0xc4, 0xf8, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00, 0x41, 0x00, 0x09, 0x21, 0x0d, 0x10,
	0x02, 0xb4, 0xa0, 0x00, 0x00, 0x45, 0x92, 0x45, 0x51, 0x00, 0x92, 0x45, 0x09, 0x16, 0x09, 0x10,
	0x00, 0x50, 0x00, 0x00, 0x00, 0x45, 0x55, 0x46, 0x51, 0x00, 0x55, 0x46, 0x04, 0x05, 0x08, 0x00,
	0x0e, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x50, 0x0f, 0x50, 0x0f, 0x50,
	0x0e, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x10, 0x09, 0x20, 0x09, 0x20,
	0x0d, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x10, 0x0a, 0x10, 0x0a, 0x10,
	0x0e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x10, 0x09, 0x10, 0x09, 0x20
};

#include "example_shmup_tiles.c"

void main()
{
    char counter = 255;
    char done = 0;

    multisprite_init();
    multisprite_vscroll_init_sparse_tiles_vmem(tilemap_data_ptrs, blue_objects1);

    // Grey palette
    *P0C1 = 0x04;
    *P0C2 = 0x08;
    *P0C3 = 0x0c;

    // Blue palette
    *P1C1 = multisprite_color(0x84); // Dark blue 
    *P1C2 = multisprite_color(0x88); // Light blue
    *P1C3 = multisprite_color(0xac); // Turquoise 

    // Main loop
    do {
        multisprite_vscroll_buffer_sparse_tiles_vmem_step();
        multisprite_vscroll_buffer_sparse_tiles_vmem_step();
        // Prepare scrolling data
        if (multisprite_vscroll_buffer_empty()) {
            if (!done) {
                multisprite_vscroll_buffer_sparse_tiles_vmem(counter);
                if (counter) counter--; else done = 1; 
            } else if (done == 1) {
                multisprite_vscroll_buffer_sparse_tiles_vmem(255);
                done = 2;
            } else done = 3;
        }

        while (*MSTAT & 0x80); 
        multisprite_flip();
        if (done != 3) multisprite_vertical_scrolling(1);

    } while(1);
}