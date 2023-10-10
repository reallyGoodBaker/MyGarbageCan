#ifdef _WIN32
    #include "win.c"
    Palette_Constructor createPalette = win_createPalette;
    ShowMessage showMessage = win_showMessage;
    Rgb rgb = es_rgb;
    SetColor setColor = es_setColor;
#else
    #include "default.c"
    Palette_Constructor createPalette = es_createPalette;
    ShowMessage showMessage = es_showMessage;
    Rgb rgb = es_rgb;
    SetColor setColor = es_setColor;
#endif
