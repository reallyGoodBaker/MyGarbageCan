#include "palette.h"

typedef enum ANSIColors {
    black = 0, red, green, yellow, blue,
    magenta, cyan, white, 
} ANSIColors;

void es_setColor(Palette p, int foreColor, int backColor) {
    p->background = backColor;
    p->foreground = foreColor;
}

int es_rgb(int r, int g, int b) {
    int res = 1 << 31;
    res = res | (b & 0xFF)
              | ((g & 0xFF) << 8)
              | ((r & 0xFF) << 16);
    return res;
}

void decodeRgb(int rgb, char* str) {
    int r, g, b;
    r = (rgb & 0xFF0000) >> 16;
    g = (rgb & 0xFF00) >> 8;
    b = (rgb & 0xFF);
    sprintf(str, ";2;%d;%d;%d", r, g, b);
}

char *ChEscape = "\x1B[0";
char *Reset = "\x1B[0m";

void buildStyle(Palette p, char* str) {
    int fore = p->foreground,
        back = p->background;

    char color1[30] = {0},
         color2[30] = {0};

    if (fore < 0) {
        char buf[30] = {0};
        decodeRgb(fore, buf);
        sprintf(color1, ";38%s", buf);
    } else {
        sprintf(color1, ";38;5;%d", fore);
    }

    if (back < 0) {
        char buf[30] = {0};
        decodeRgb(back, buf);
        sprintf(color2, ";48%s", buf);
    } else {
        sprintf(color2, ";48;5;%d", back);
    }

    sprintf(str, "%s%s%sm", ChEscape, color1, color2);
}

void es_showMessage(char *msg, Palette p) {
    char style[50] = {0};
    buildStyle(p, style);
    printf("%s%s%s", style, msg, Reset);
}


Palette es_createPalette(int _) {
    return (Palette)malloc(sizeof(IPalette));
}
