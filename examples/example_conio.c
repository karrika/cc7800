#include "conio.h"

char i;

void main()
{
    clrscr();
    for (i = 0; i != 8; i++) {
        textcolor(i);
        gotoxy(0, i);
        cputs("Hello World!");
    }
    while(1);
}
