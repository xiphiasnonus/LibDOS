#include <dos.h>
#include <conio.h>

#define WIDTH 16
#define HEIGHT 16

int main()
{
    textmode(C40);
    setscreensize(WIDTH + 1, HEIGHT + 1);
    setscale(3);
    setcursor(CURSOR_NONE);
    setname("ascii.c");

    initdos();

    textcolor(WHITE);
    for ( int i = 0; i < 16; i++ ) {
        gotoxy(i + 2, 1);
        cprintf("%X", i);
        gotoxy(1, i + 2);
        cprintf("%X", i);
    }
    
    textcolor(LIGHTGRAY);
    for ( int ch = 0; ch <= 255; ch++ ) {
        gotoxy((ch % WIDTH) + 2, ch / WIDTH + 2);
        putch(ch);
    }
        
    while ( 1 ) {
        refresh();
    }
}
