reversed scattered(8,16) char borders[128] = {
	0xf5, 0xf5, 0xfc, 0xfc, 0xf0, 0xf5, 0xf5, 0xff, 0xf5, 0xf5, 0xf0, 0xf5, 0xf5, 0xff, 0x00, 0x00,
	0xf5, 0xf5, 0xfc, 0xfc, 0xf0, 0xf5, 0xf5, 0xff, 0xf5, 0xf5, 0xf3, 0xf5, 0xf5, 0xf3, 0x00, 0x00,
	0xf5, 0xf5, 0xfc, 0xfc, 0xff, 0xf5, 0xf5, 0xf0, 0xf5, 0xf5, 0xff, 0xf5, 0xf5, 0xf0, 0x00, 0x00,
	0xf5, 0xf5, 0xfc, 0xfc, 0xff, 0xf5, 0xf5, 0xf0, 0xf5, 0xf5, 0x7c, 0xf1, 0xf7, 0xec, 0x00, 0x00,
	0xf3, 0xf3, 0xf5, 0xf5, 0xf0, 0xf5, 0xf5, 0xff, 0xf5, 0xf5, 0x70, 0xfc, 0xfc, 0xef, 0x00, 0x00,
	0xf3, 0xf3, 0xf5, 0xf5, 0xf0, 0xf5, 0xf5, 0xff, 0xf5, 0xf5, 0x30, 0xfc, 0xfc, 0xcc, 0x00, 0x00,
	0xf3, 0xf3, 0xf5, 0xf5, 0xff, 0xf5, 0xf5, 0xf0, 0xf5, 0xf5, 0x13, 0xfc, 0xfc, 0x80, 0x00, 0x00,
	0xf3, 0xf3, 0xf5, 0xf5, 0xff, 0xf5, 0xf5, 0xf0, 0xf5, 0xf5, 0x00, 0x7c, 0xec, 0x00, 0x00, 0x00
};
reversed scattered(8,1) char grass[8] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(8,4) char sharp_turn[32] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(8,12) char inner_turn1[96] = {
	0x00, 0x00, 0x00, 0x00, 0x30, 0xfc, 0xfc, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c,
	0xfc, 0xfc, 0xfc, 0xfc, 0xec, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
	0xfc, 0xcc, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x00, 0x00,
	0x00, 0x30, 0xfc, 0xfc, 0xfd, 0xf5, 0xf5, 0xf4, 0xfc, 0xfc, 0xcc, 0x00, 0x00, 0x7f, 0xf3, 0xf1,
	0xf5, 0xf5, 0xf5, 0xf5, 0xf7, 0xf3, 0xe0, 0x00, 0x13, 0xf3, 0xf3, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5,
	0xf5, 0xf3, 0xf3, 0x80, 0x33, 0xfc, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xfc, 0xc0
};
reversed scattered(8,4) char inner_turn2[32] = {
	0x00, 0x00, 0x70, 0xfd, 0x00, 0x00, 0xfc, 0xf1, 0x00, 0x10, 0xff, 0xf5, 0x00, 0x30, 0xf3, 0xf5,
	0x00, 0x7f, 0xf1, 0xf5, 0x00, 0x73, 0xfd, 0xf5, 0x00, 0xf0, 0xf5, 0xf5, 0x00, 0xff, 0xf5, 0xf5
};
reversed scattered(8,4) char inner_turn3[32] = {
	0xf4, 0xef, 0x00, 0x00, 0xf7, 0xfc, 0x00, 0x00, 0xf5, 0xf0, 0x8c, 0x00, 0xf5, 0xf3, 0xcc, 0x00,
	0xf5, 0xf7, 0xe0, 0x00, 0xf5, 0xf4, 0xe3, 0x00, 0xf5, 0xf5, 0xff, 0x00, 0xf5, 0xf5, 0xf0, 0x00
};
reversed scattered(16,2) char inner_turn4[32] = {
	0x10, 0xf3, 0x10, 0xf1, 0x33, 0xfd, 0x33, 0xfd, 0x30, 0xf1, 0x70, 0xf1, 0x7f, 0xf5, 0x7f, 0xf5,
	0x70, 0xf5, 0xf0, 0xf5, 0xff, 0xf5, 0xff, 0xf5, 0xf0, 0xf5, 0xf0, 0xf5, 0xff, 0xf5, 0xff, 0xf5
};
reversed scattered(16,2) char inner_turn4_1[32] = {
	0xf0, 0xf5, 0xf0, 0xf5, 0xff, 0xf5, 0xff, 0xf5, 0xf0, 0xf5, 0xf0, 0xf5, 0xff, 0xf5, 0x7f, 0xf5,
	0x70, 0xf5, 0x70, 0xf5, 0x7f, 0xfd, 0x33, 0xfd, 0x30, 0xf1, 0x30, 0xf1, 0x13, 0xfd, 0x13, 0xfc
};
reversed scattered(16,2) char inner_turn5[32] = {
	0xf3, 0x8c, 0xf7, 0x8c, 0xf4, 0xc0, 0xf4, 0xc0, 0xf7, 0xcc, 0xf7, 0xef, 0xf5, 0xe0, 0xf5, 0xe0,
	0xf5, 0xef, 0xf5, 0xff, 0xf5, 0xf0, 0xf5, 0xf0, 0xf5, 0xff, 0xf5, 0xff, 0xf5, 0xf0, 0xf5, 0xf0
};
reversed scattered(16,2) char inner_turn5_1[32] = {
	0xf5, 0xff, 0xf5, 0xff, 0xf5, 0xf0, 0xf5, 0xf0, 0xf5, 0xff, 0xf5, 0xff, 0xf5, 0xf0, 0xf5, 0xe0,
	0xf5, 0xef, 0xf5, 0xef, 0xf4, 0xe0, 0xf4, 0xc0, 0xf7, 0xcc, 0xf7, 0xcc, 0xf4, 0x80, 0xfc, 0x80
};
reversed scattered(8,4) char inner_turn6[32] = {
	0x00, 0xf0, 0xf5, 0xf5, 0x00, 0xff, 0xf5, 0xf5, 0x00, 0x7c, 0xf1, 0xf5, 0x00, 0x70, 0xfd, 0xf5,
	0x00, 0x33, 0xfc, 0xf5, 0x00, 0x13, 0xf0, 0xf5, 0x00, 0x00, 0xf3, 0xfd, 0x00, 0x00, 0x7f, 0xf1
};
reversed scattered(8,4) char inner_turn7[32] = {
	0xf5, 0xf5, 0xff, 0x00, 0xf5, 0xf5, 0xf0, 0x00, 0xf5, 0xf7, 0xec, 0x00, 0xf5, 0xf4, 0xef, 0x00,
	0xf5, 0xfc, 0xc0, 0x00, 0xf5, 0xff, 0x80, 0x00, 0xf4, 0xf3, 0x00, 0x00, 0xf7, 0xe0, 0x00, 0x00
};
reversed scattered(8,12) char inner_turn8[96] = {
	0x30, 0xf3, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf3, 0xcc, 0x10, 0xfc, 0xfc, 0xf5,
	0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xfc, 0xfc, 0x8c, 0x00, 0x70, 0xfc, 0xfd, 0xf5, 0xf5, 0xf5, 0xf5,
	0xf4, 0xfc, 0xef, 0x00, 0x00, 0x33, 0xf3, 0xf3, 0xf1, 0xf5, 0xf5, 0xf7, 0xf3, 0xf3, 0xc0, 0x00,
	0x00, 0x00, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0x00, 0x00, 0x00, 0x00, 0x33, 0xf3,
	0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0xf3, 0xf3, 0xf3, 0xf3,
	0xe3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0xf3, 0xf3, 0xc0, 0x00, 0x00, 0x00, 0x00
};
reversed scattered(8,8) char outer_turn1[64] = {
	0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5,
	0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5,
	0xf5, 0xf5, 0xf5, 0xf3, 0xf3, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf3, 0xf3, 0xf3, 0xf3, 0xf5, 0xf5,
	0xf5, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf5, 0xf7, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf1
};
reversed scattered(8,12) char outer_turn2[96] = {
	0xf5, 0xf5, 0xf3, 0xf3, 0xf3, 0x00, 0x00, 0xf3, 0xf3, 0xf3, 0xf5, 0xf5, 0xf5, 0xf7, 0xf3, 0xf3,
	0x00, 0x00, 0x00, 0x00, 0xf3, 0xf3, 0xf1, 0xf5, 0xf5, 0xf7, 0xf0, 0x8c, 0x00, 0x00, 0x00, 0x00,
	0x10, 0xff, 0xf1, 0xf5, 0xf5, 0xf3, 0xef, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xf3, 0xf5,
	0xf7, 0xf0, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xff, 0xf1, 0xf7, 0xfc, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xf1, 0xf4, 0xef, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x70, 0xfd, 0xfc, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0xfc
};
reversed scattered(8,4) char outer_turn3[32] = {
	0xf5, 0xf5, 0xff, 0x80, 0xf5, 0xf5, 0xff, 0x00, 0xf5, 0xf5, 0xe3, 0x00, 0xf5, 0xf4, 0xe0, 0x00,
	0xf5, 0xf7, 0xc0, 0x00, 0xf5, 0xf7, 0xcc, 0x00, 0xf5, 0xf4, 0xcc, 0x00, 0xf5, 0xf4, 0x80, 0x00
};
reversed scattered(8,4) char outer_turn4[32] = {
	0x13, 0xf0, 0xf5, 0xf5, 0x00, 0xf0, 0xf5, 0xf5, 0x00, 0x73, 0xf5, 0xf5, 0x00, 0x7f, 0xfd, 0xf5,
	0x00, 0x33, 0xf1, 0xf5, 0x00, 0x30, 0xf1, 0xf5, 0x00, 0x30, 0xfd, 0xf5, 0x00, 0x13, 0xfd, 0xf5
};
reversed scattered(8,4) char outer_turn5[32] = {
	0xf5, 0xf7, 0x8c, 0x00, 0xf5, 0xf7, 0xc0, 0x00, 0xf5, 0xf4, 0xc0, 0x00, 0xf5, 0xf4, 0xcc, 0x00,
	0xf5, 0xf7, 0xef, 0x00, 0xf5, 0xf5, 0xec, 0x00, 0xf5, 0xf5, 0xf0, 0x00, 0xf5, 0xf5, 0xf0, 0x8c
};
reversed scattered(8,4) char outer_turn6[32] = {
	0x00, 0x10, 0xf1, 0xf5, 0x00, 0x33, 0xf1, 0xf5, 0x00, 0x33, 0xfd, 0xf5, 0x00, 0x30, 0xfd, 0xf5,
	0x00, 0x70, 0xf1, 0xf5, 0x00, 0x7c, 0xf5, 0xf5, 0x00, 0xff, 0xf5, 0xf5, 0x10, 0xff, 0xf5, 0xf5
};
reversed scattered(8,12) char outer_turn7[96] = {
	0xf3, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xf3, 0xf7, 0xe0, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf1, 0xf4, 0xf3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xf3, 0xfd, 0xf4, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0xf0, 0xfd,
	0xf5, 0xfc, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfc, 0xf5, 0xf5, 0xf4, 0xff, 0x80,
	0x00, 0x00, 0x00, 0x00, 0x13, 0xf0, 0xfd, 0xf5, 0xf5, 0xf4, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00,
	0xfc, 0xfc, 0xfd, 0xf5, 0xf5, 0xf5, 0xfc, 0xfc, 0xfc, 0x00, 0x00, 0xfc, 0xfc, 0xfc, 0xf5, 0xf5
};
reversed scattered(8,8) char outer_turn8[64] = {
	0xf4, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfd, 0xf5, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf5,
	0xf5, 0xf5, 0xfc, 0xfc, 0xfc, 0xfc, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xfc, 0xfc, 0xf5, 0xf5, 0xf5,
	0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5,
	0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5, 0xf5
};
