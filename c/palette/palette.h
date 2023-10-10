#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef PALETTE_HEADER
    #define PALETTE_HEADER
    typedef struct IPalette {
        int foreground;
        int background;
        int forceANSIES;
    } IPalette;

    typedef IPalette* Palette;

    typedef Palette (*Palette_Constructor)(int);
    typedef void (*ShowMessage)(char*, Palette);
    typedef int (*Rgb)(int, int, int);
    typedef void (*SetColor)(Palette, int, int);
#endif