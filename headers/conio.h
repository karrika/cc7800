/*
    conio.h : a console I/O display for the Atari 7800
    Copyleft 2023 Bruno STEUX 

    This file is distributed as a companion file to cc7800 - a subset of C compiler for the Atari 7800
*/

#ifndef __CONIO_H__
#define __CONIO_H__

// Conio shares the memory with multisprite DLLs, as well as PAL/NTSC auto detection
#include "multisprite.h"

#define CONIO_NB_LINES 25 
ramchip char _conio_screen[CONIO_NB_LINES * 40]; 

const char *_ms_conio_dls[CONIO_NB_LINES] = {
    _ms_b0_dl0, _ms_b0_dl1, _ms_b0_dl2, _ms_b0_dl3, _ms_b0_dl4, _ms_b0_dl5, _ms_b0_dl6, _ms_b0_dl7, _ms_b0_dl8, _ms_b0_dl9, _ms_b0_dl10, _ms_b0_dl11, _ms_b0_dl12, _ms_b0_dl13, _ms_b0_dl14, _ms_b0_dl15, 
    _ms_b1_dl0, _ms_b1_dl1, _ms_b1_dl2, _ms_b1_dl3, _ms_b1_dl4, _ms_b1_dl5, _ms_b1_dl6, _ms_b1_dl7, _ms_b1_dl8
};

reversed scattered(8,1) char font[1024]={
	// ................................
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 
	0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
	0xcc, 0xcc, 0x33, 0x33, 0xcc, 0xcc, 0x33, 0x33, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
	0x00, 0x00, 0x00, 0x00, 0xcc, 0xcc, 0x33, 0x33, 0xcc, 0x99, 0x33, 0x66, 0xcc, 0x99, 0x33, 0x66, 
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x18, 0x18, 0x18, 
	0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xf8, 0xf8, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 
	0x00, 0x00, 0x00, 0x1f, 0x1f, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff, 0xff, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xf8, 0xf8, 0x18, 0x18, 0x18, 
	0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
	0x01, 0x03, 0x06, 0x6c, 0x78, 0x70, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 
	0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0xf8, 0xf8, 0x00, 0x00, 0x00, 
	0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0x0f, 0x0f, 0x0f, 0x0f, 
	//  !"#$%&'()*+,-./0123456789:;<=>?
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x18, 0x00, 
	0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x66, 0xff, 0x66, 0xff, 0x66, 0x66, 0x00, 
	0x18, 0x3e, 0x60, 0x3c, 0x06, 0x7c, 0x18, 0x00, 0x62, 0x66, 0x0c, 0x18, 0x30, 0x66, 0x46, 0x00, 
	0x3c, 0x66, 0x3c, 0x38, 0x67, 0x66, 0x3f, 0x00, 0x06, 0x0c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x0c, 0x18, 0x30, 0x30, 0x30, 0x18, 0x0c, 0x00, 0x30, 0x18, 0x0c, 0x0c, 0x0c, 0x18, 0x30, 0x00, 
	0x00, 0x66, 0x3c, 0xff, 0x3c, 0x66, 0x00, 0x00, 0x00, 0x18, 0x18, 0x7e, 0x18, 0x18, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x30, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x03, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x00, 
	0x3c, 0x66, 0x6e, 0x76, 0x66, 0x66, 0x3c, 0x00, 0x18, 0x18, 0x38, 0x18, 0x18, 0x18, 0x7e, 0x00, 
	0x3c, 0x66, 0x06, 0x0c, 0x30, 0x60, 0x7e, 0x00, 0x3c, 0x66, 0x06, 0x1c, 0x06, 0x66, 0x3c, 0x00, 
	0x06, 0x0e, 0x1e, 0x66, 0x7f, 0x06, 0x06, 0x00, 0x7e, 0x60, 0x7c, 0x06, 0x06, 0x66, 0x3c, 0x00, 
	0x3c, 0x66, 0x60, 0x7c, 0x66, 0x66, 0x3c, 0x00, 0x7e, 0x66, 0x0c, 0x18, 0x18, 0x18, 0x18, 0x00, 
	0x3c, 0x66, 0x66, 0x3c, 0x66, 0x66, 0x3c, 0x00, 0x3c, 0x66, 0x66, 0x3e, 0x06, 0x66, 0x3c, 0x00, 
	0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x18, 0x30, 
	0x0e, 0x18, 0x30, 0x60, 0x30, 0x18, 0x0e, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x7e, 0x00, 0x00, 0x00, 
	0x70, 0x18, 0x0c, 0x06, 0x0c, 0x18, 0x70, 0x00, 0x3c, 0x66, 0x06, 0x0c, 0x18, 0x00, 0x18, 0x00, 
	// @ABCDEFGHIJKLMNOPQRSTUVWXYZ[£]^<
        0x3c, 0x66, 0x6e, 0x6e, 0x60, 0x62, 0x3c, 0x00, 0x18, 0x3c, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x00, 
	0x7c, 0x66, 0x66, 0x7c, 0x66, 0x66, 0x7c, 0x00, 0x3c, 0x66, 0x60, 0x60, 0x60, 0x66, 0x3c, 0x00, 
	0x78, 0x6c, 0x66, 0x66, 0x66, 0x6c, 0x78, 0x00, 0x7e, 0x60, 0x60, 0x78, 0x60, 0x60, 0x7e, 0x00, 
	0x7e, 0x60, 0x60, 0x78, 0x60, 0x60, 0x60, 0x00, 0x3c, 0x66, 0x60, 0x6e, 0x66, 0x66, 0x3c, 0x00, 
	0x66, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x00, 0x3c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 
	0x1e, 0x0c, 0x0c, 0x0c, 0x0c, 0x6c, 0x38, 0x00, 0x66, 0x6c, 0x78, 0x70, 0x78, 0x6c, 0x66, 0x00, 
	0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7e, 0x00, 0x63, 0x77, 0x7f, 0x6b, 0x63, 0x63, 0x63, 0x00, 
	0x66, 0x76, 0x7e, 0x7e, 0x6e, 0x66, 0x66, 0x00, 0x3c, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00, 
	0x7c, 0x66, 0x66, 0x7c, 0x60, 0x60, 0x60, 0x00, 0x3c, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x0e, 0x00, 
	0x7c, 0x66, 0x66, 0x7c, 0x78, 0x6c, 0x66, 0x00, 0x3c, 0x66, 0x60, 0x3c, 0x06, 0x66, 0x3c, 0x00, 
	0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00, 
	0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x00, 0x63, 0x63, 0x63, 0x6b, 0x7f, 0x77, 0x63, 0x00, 
	0x66, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0x66, 0x00, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x18, 0x18, 0x00, 
	0x7e, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x7e, 0x00, 0x3c, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3c, 0x00, 
	0x0c, 0x12, 0x30, 0x7c, 0x30, 0x62, 0xfc, 0x00, 0x3c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x3c, 0x00, 
	0x00, 0x18, 0x3c, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x00, 0x10, 0x30, 0x7f, 0x7f, 0x30, 0x10, 0x00,
	// -abcdefghijklmnopqrstuvwxyz.....
        0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x06, 0x3e, 0x66, 0x3e, 0x00, 
	0x00, 0x60, 0x60, 0x7c, 0x66, 0x66, 0x7c, 0x00, 0x00, 0x00, 0x3c, 0x60, 0x60, 0x60, 0x3c, 0x00, 
	0x00, 0x06, 0x06, 0x3e, 0x66, 0x66, 0x3e, 0x00, 0x00, 0x00, 0x3c, 0x66, 0x7e, 0x60, 0x3c, 0x00, 
	0x00, 0x0e, 0x18, 0x3e, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x3e, 0x66, 0x66, 0x3e, 0x06, 0x7c, 
	0x00, 0x60, 0x60, 0x7c, 0x66, 0x66, 0x66, 0x00, 0x00, 0x18, 0x00, 0x38, 0x18, 0x18, 0x3c, 0x00, 
	0x00, 0x06, 0x00, 0x06, 0x06, 0x06, 0x06, 0x3c, 0x00, 0x60, 0x60, 0x6c, 0x78, 0x6c, 0x66, 0x00, 
	0x00, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00, 0x66, 0x7f, 0x7f, 0x6b, 0x63, 0x00, 
	0x00, 0x00, 0x7c, 0x66, 0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x3c, 0x66, 0x66, 0x66, 0x3c, 0x00, 
	0x00, 0x00, 0x7c, 0x66, 0x66, 0x7c, 0x60, 0x60, 0x00, 0x00, 0x3e, 0x66, 0x66, 0x3e, 0x06, 0x06, 
	0x00, 0x00, 0x7c, 0x66, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x3e, 0x60, 0x3c, 0x06, 0x7c, 0x00, 
	0x00, 0x18, 0x7e, 0x18, 0x18, 0x18, 0x0e, 0x00, 0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x3e, 0x00, 
	0x00, 0x00, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x63, 0x6b, 0x7f, 0x3e, 0x36, 0x00, 
	0x00, 0x00, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0x00, 0x00, 0x00, 0x66, 0x66, 0x66, 0x3e, 0x0c, 0x78, 
	0x00, 0x00, 0x7e, 0x0c, 0x18, 0x30, 0x7e, 0x00, 0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18, 
	0xc0, 0xc0, 0x30, 0x30, 0xc0, 0xc0, 0x30, 0x30, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
	0x33, 0x33, 0xcc, 0xcc, 0x33, 0x33, 0xcc, 0xcc, 0x33, 0x99, 0xcc, 0x66, 0x33, 0x99, 0xcc, 0x66
};

ramchip char _conio_x, _conio_y, _conio_palette;
ramchip char *_conio_ptr; // Pointer to the screen RAM

#define gotoxy(x, y) _libc_tmp = (x); _libc_tmp2 = (y); _conio_update_ptr()
#define wherex() _conio_x
#define wherey() _conio_y
#define putch(c) _ms_tmp = (c); _conio_putch()
#define cputs(s) _ms_tmpptr2 = (s); _conio_cputs()
#define textcolor(c) _conio_palette = ((c) << 5)

#define CONIO_HBAR 96
#define CONIO_VBAR ('z' + 3)
#define CONIO_TL_CORNER ('P' - '@')
#define CONIO_BL_CORNER ('M' - '@')
#define CONIO_TR_CORNER ('N' - '@')
#define CONIO_BR_CORNER ('Z' + 3 - '@')

void clrscr()
{
    *BACKGRND = 0;

    _conio_x = 0;
    _conio_y = 0;
    _conio_ptr = _conio_screen;
    X = CONIO_NB_LINES; 
    _ms_tmpptr = _conio_screen;
    do {
        Y = 39;
        do {
            _ms_tmpptr[Y--] = ' ';
        } while (Y >= 0);
        _ms_tmpptr += 40;
        X--;
    } while (X != 0);

    _conio_palette = 0;

    *P0C2 = 0x07; // Grey
    *P1C2 = multisprite_color(0x87); // Blue
    *P2C2 = multisprite_color(0xDA); // Green
    *P3C2 = multisprite_color(0x9C); // Cyran
    *P4C2 = multisprite_color(0x32); // Red
    *P5C2 = multisprite_color(0x36); // Brown
    *P6C2 = multisprite_color(0x1D); // Yellow
    *P7C2 = 0x0f; // White

    multisprite_set_charbase(font);
    multisprite_get_tv();
    
    Y = 1;
    for (X = 0; X != CONIO_NB_LINES; X++) {
        _ms_dlend[X] = 0;
        _ms_tmpptr = _ms_conio_dls[X];
        _ms_tmpptr[Y] = 0; // Stops the DL
    }
    
    _ms_tmpptr = _ms_b0_dll;
    // Build DLL
    // 69 blank lines for PAL
    // 19 blank lines for NTSC
    if (_ms_pal_detected) {
        // 16 blank lines
        _ms_tmpptr[Y = 0] = 0x0f;  // 16 lines
        _ms_tmpptr[++Y] = _ms_set_wm_dl >> 8;
        _ms_tmpptr[++Y] = _ms_set_wm_dl;
        // 16 blank lines
        _ms_tmpptr[++Y] = 0x0f;  // 16 lines
        _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
        _ms_tmpptr[++Y] = _ms_blank_dl;
        // 14 blank lines
        _ms_tmpptr[++Y] = 0x0d;  // 14 lines
        _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
        _ms_tmpptr[++Y] = _ms_blank_dl;
    } else {
        _ms_tmpptr[Y = 0] = 0x0f; // 16 lines
        _ms_tmpptr[++Y] = _ms_set_wm_dl >> 8;
        _ms_tmpptr[++Y] = _ms_set_wm_dl;
        // 5 blank lines
        _ms_tmpptr[++Y] = 0x04;  // 5 lines
        _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
        _ms_tmpptr[++Y] = _ms_blank_dl;
    }
    // 8 pixel high regions
    for (X = 0; X != CONIO_NB_LINES; X++) {
        _ms_tmpptr[++Y] = 0x27; // 8 lines, Holey DMA enabled
        _ms_tmpptr[++Y] = _ms_conio_dls[X] >> 8; // High address
        _ms_tmpptr[++Y] = _ms_conio_dls[X]; // Low address
    }
    if (_ms_pal_detected) {
        // 16 blank lines
        _ms_tmpptr[++Y] = 0x0f;  // 16 lines
        _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
        _ms_tmpptr[++Y] = _ms_blank_dl;
        // 16 blank lines
        _ms_tmpptr[++Y] = 0x0f;  // 16 lines
        _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
        _ms_tmpptr[++Y] = _ms_blank_dl;
        // 15 blank lines
        _ms_tmpptr[++Y] = 0x0e;  // 15 lines
        _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
        _ms_tmpptr[++Y] = _ms_blank_dl;
    } else {
        _ms_tmpptr[++Y] = 0x0f; // 16 lines
        _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
        _ms_tmpptr[++Y] = _ms_blank_dl;
        // 6 blank lines
        _ms_tmpptr[++Y] = 0x05;  // 6 lines
        _ms_tmpptr[++Y] = _ms_blank_dl >> 8;
        _ms_tmpptr[++Y] = _ms_blank_dl;
    }
    *DPPH = _ms_b0_dll >> 8; // 1 the current displayed buffer
    *DPPL = _ms_b0_dll;
    *CTRL = 0x43; // DMA on, Black background, 320A mode, 1 byte wide characters mode
}

void delline()
{
    _ms_tmpptr = _conio_ptr - _conio_x;   
    Y = 39; 
    do {
        _ms_tmpptr[Y--] = ' ';
    } while (Y >= 0);
    _ms_dlend[X = _conio_y] = 0;
    _ms_tmpptr = _ms_conio_dls[X = _conio_y];
    _ms_tmpptr[Y = 1] = 0;
}

void _conio_update_ptr()
{
    _conio_ptr -= _conio_x;
    _conio_ptr += _libc_tmp;
    if (_conio_y == _libc_tmp2) {
         _conio_x = _libc_tmp;
         _conio_y = _libc_tmp2;
         return;
    } else if (_libc_tmp2 >= _conio_y) {
         Y = _libc_tmp2 - _conio_y;
         do {
             _conio_ptr += 40;
             Y--;
         } while (Y != 0);
         _conio_x = _libc_tmp;
         _conio_y = _libc_tmp2;
         return;
    } else {
         Y = _conio_y - _libc_tmp2;
         do {
             _conio_ptr -= 40;
             Y--;
         } while (Y != 0);
         _conio_x = _libc_tmp;
         _conio_y = _libc_tmp2;
    }
}

// _ms_tmp is the size to move right
void _conio_cursor_move_right()
{
    _conio_x += _ms_tmp;
    if (_conio_x >= 40) {
        _conio_x -= 40;
        _conio_y++;
    }
    _conio_ptr += _ms_tmp;
}

// _ms_tmp is the size of the string, max 32   
// _ms_tmpptr2 points to the string to display
void _conio_cputs2()
{    
    // Store the string in the screen RAM
    _ms_tmpptr = _conio_ptr;
    for (Y--; Y >= 0; Y--) {
        _ms_tmpptr[Y] = _ms_tmpptr2[Y];
    }
    // Check the display and look for one with the same palette
    _ms_tmpptr = _ms_conio_dls[X = _conio_y];
    for (Y = 3; Y < _ms_dlend[X = _conio_y]; Y += 5) {
        if ((_ms_tmpptr[Y] & 0xe0) == _conio_palette) {
            // Yes ! It has the same palette !
            // Is it possible to add this string in the same dl ?
            X = _ms_tmpptr[++Y] >> 2; // x pos 
            if (X > _conio_x) {
                // The new string is on the left
                // What would be the new width of the string ?
                X -= _conio_x + ((_ms_tmpptr[--Y] & 0x1f) | 0xe0); // The width of this dl
                if (X < _ms_tmp) X = _ms_tmp;
                if (X <= 32) {
                    // It fits ! Yeah !
                    Y--; Y--;
                    _ms_tmpptr[--Y] = _conio_ptr;
                    Y++; Y++;
                    _ms_tmpptr[Y++] = _conio_ptr >> 8;
                    _ms_tmpptr[Y++] = -X & 0x1f | _conio_palette;
                    _ms_tmpptr[Y++] = _conio_x << 2;
                    _conio_cursor_move_right();
                    return;
                }
            } else { 
                // The new string on the right
                X -= (_ms_tmpptr[--Y] & 0x1f) | 0xe0; // The width of this dl
                if (X < _ms_tmp + _conio_x) { // The new string lies on the right
                                              // OK. What would be the new width ?
                    X = -((_ms_tmpptr[Y] & 0x1f) | 0xe0) + _ms_tmp + _conio_x - X;
                    if (X <= 32) {
                        // It fits ! Yeah !
                        _ms_tmpptr[Y] = -X & 0x1f | _conio_palette;
                        _conio_cursor_move_right();
                        return;
                    }
                } else {
                    _conio_cursor_move_right();
                    return; // No need to modify the DL. It's included in the previous one
                }
            }
        }
    }

    // And add this to the display list
    Y = _ms_dlend[X = _conio_y];
    if (Y >= _MS_DL_SIZE - 7) {
        _ms_dmaerror++;
    } else {
        _ms_tmpptr[Y++] = _conio_ptr;
        Y++;
        _ms_tmpptr[Y++] = _conio_ptr >> 8;
        _ms_tmpptr[Y++] = -_ms_tmp & 0x1f | _conio_palette;
        _ms_tmpptr[Y++] = _conio_x << 2;
        _ms_dlend[X] = Y++;
        _ms_tmpptr[Y] = 0;
        Y -= 5;
        _ms_tmpptr[Y] = 0x60;
    }
    _conio_cursor_move_right();
}

// _ms_tmpptr2 points to the string to display
void _conio_cputs()
{
    // Compute the length of the string
    Y = 0;
    while (_ms_tmpptr2[Y]) Y++;
    _ms_tmp = Y; // _ms_tmp contains the string length
    while (_ms_tmp > 32) {
        _ms_tmp2 = _ms_tmp - 32;
        _ms_tmp = 32;
        _conio_cputs2();
        _ms_tmpptr2 += 32;
        _ms_tmp = _ms_tmp2;
    }
    _conio_cputs2();
}
 
// _ms_tmp is character to draw at current position   
void _conio_putch()
{    
    // Store the string in the screen RAM
    _ms_tmpptr = _conio_ptr;
    _ms_tmpptr[Y = 0] = _ms_tmp;
    // Check the display and look for one with the same palette
    _ms_tmpptr = _ms_conio_dls[X = _conio_y];
    for (Y = 3; Y < _ms_dlend[X = _conio_y]; Y += 5) {
        if ((_ms_tmpptr[Y] & 0xe0) == _conio_palette) {
            // Yes ! It has the same palette !
            // Is it possible to add this string in the same dl ?
            X = _ms_tmpptr[++Y] >> 2; // x pos 
            if (X > _conio_x) {
                // The new string is on the left
                // What would be the new width of the string ?
                X -= _conio_x + ((_ms_tmpptr[--Y] & 0x1f) | 0xe0); // The width of this dl entry
                if (X <= 32) {
                    Y--; Y--;
                    // It fits ! Yeah !
                    _ms_tmpptr[--Y] = _conio_ptr;
                    Y++; Y++;
                    _ms_tmpptr[Y++] = _conio_ptr >> 8;
                    _ms_tmpptr[Y++] = -X & 0x1f | _conio_palette;
                    _ms_tmpptr[Y] = _conio_x << 2;
                    _ms_tmp = 1;
                    _conio_cursor_move_right();
                    return;
                }
            } else { 
                // The new string is on the right
                X -= (_ms_tmpptr[--Y] & 0x1f) | 0xe0; // Add the width of this dl entry
                if (X < _conio_x + 1) { // The new string lies on the right
                                        // OK. What would be the new width ?
                    X = -((_ms_tmpptr[Y] & 0x1f) | 0xe0) + 1 + _conio_x - X;
                    if (X <= 32) {
                        // It fits ! Yeah !
                        _ms_tmpptr[Y] = -X & 0x1f | _conio_palette;
                        _ms_tmp = 1;
                        _conio_cursor_move_right();
                        return;
                    }
                } else {
                    _ms_tmp = 1;
                    _conio_cursor_move_right();
                    return; // No need to modify the DL. It's included in the previous one
                }
            }
        }
    }

    // And add this to the display list
    Y = _ms_dlend[X = _conio_y];
    if (Y >= _MS_DL_SIZE - 7) {
        _ms_dmaerror++;
    } else {
        _ms_tmpptr[Y++] = _conio_ptr;
        Y++;
        _ms_tmpptr[Y++] = _conio_ptr >> 8;
        _ms_tmpptr[Y++] = 0x1f | _conio_palette;
        _ms_tmpptr[Y++] = _conio_x << 2;
        _ms_dlend[X] = Y++;
        _ms_tmpptr[Y] = 0;
        Y -= 5;
        _ms_tmpptr[Y] = 0x60;
    }
    _ms_tmp = 1;
    _conio_cursor_move_right();
}

inline void conio_restore_dl(char l)
{
    char line = (l << 2) - l + 7; // line = l * 3 + 7
    if (_ms_pal_detected) line += 3;
    X = line;
    _ms_b0_dll[X++] = _ms_conio_dls[Y = l] >> 8;
    _ms_b0_dll[X] = _ms_conio_dls[Y];
}

inline void conio_set_dl(char line, char *dl)
{
    line = (line << 2) - line + 7; // line = line * 3 + 7
    if (_ms_pal_detected) line += 3;
    X = line;
    _ms_b0_dll[X++] = dl >> 8;
    _ms_b0_dll[X] = dl;
}

#endif // __CONIO_H__
