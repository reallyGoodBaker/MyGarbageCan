#include <Windows.h>
#include "palette.h"
#include "default.c"

#define LIGHT FOREGROUND_INTENSITY


typedef enum WinColor {
    win_red    = FOREGROUND_RED,
    win_green  = FOREGROUND_GREEN,
    win_blue   = FOREGROUND_BLUE,
    win_yellow = FOREGROUND_RED | FOREGROUND_GREEN,
    win_purple = FOREGROUND_RED | FOREGROUND_BLUE,
    win_cyan   = FOREGROUND_GREEN | FOREGROUND_BLUE,
    win_white  = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    win_black  = 0,
} WinColor;


Palette win_createPalette(int forceANSIES) {
    Palette palette = (Palette)malloc(sizeof(IPalette));

    palette->forceANSIES = !!forceANSIES;
    if (!forceANSIES){
        es_setColor(palette, win_white, win_black);
    }
    else {
        es_setColor(palette, white, black);
    }
    

    return palette;
}



void setWinConsoleColor(WinColor foreColor, WinColor backColor) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, foreColor | (backColor << 4));
}


void win_showMessage(char *msg, Palette p) {
    if (!p->forceANSIES) {
        setWinConsoleColor(p->foreground, p->background);
        printf("%s", msg);
        setWinConsoleColor(win_white, win_black);
        return;
    }
    
    es_showMessage(msg, p);
}
