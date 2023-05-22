#include "conio.h"
#include "assert.h"

char i;

void main()
{
    clrscr();
    // Draw a square
    gotoxy(0, 0);
    textcolor(7);
    putch(CONIO_TL_CORNER);
    for (i = 0; i != 20; i++) {
        putch(CONIO_HBAR);
    }
    putch(CONIO_TR_CORNER);
    for (i = 0; i != 8; i++) {
        gotoxy(0, i + 1);
        putch(CONIO_VBAR);
        gotoxy(21, i + 1);
        putch(CONIO_VBAR);
    }
    gotoxy(0, 9);
    putch(CONIO_BL_CORNER);
    for (i = 0; i != 20; i++) {
        putch(CONIO_HBAR);
    }
    putch(CONIO_BR_CORNER);
    // Write some text
    for (i = 0; i != 8; i++) {
        textcolor(i);
        gotoxy(i + 1, i + 1);
        cputs("Hello World!");
    }
    // Long text test
    gotoxy(0, 10);
    cputs("This is a long text, It fits in a line.");
    
    gotoxy(10, 11);
    cputs("World!");
    gotoxy(4, 11);
    cputs("Hello");

    // Unit tests :
    assert(_ms_dlend[X = 0] == 5);
    assert(_ms_dlend[X = 1] == 10);
    assert(_ms_dlend[X = 7] == 10);
    assert(_ms_dlend[X = 8] == 5);
    assert(_ms_dlend[X = 9] == 5);
    assert(_ms_dlend[X = 10] == 10);
    assert(_ms_dlend[X = 11] == 5);
    while(1);
}
