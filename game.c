// Copyright (c) 2019 Jacob Bonner All rights reserved.
//
// Created by: Jacob Bonner
// Created on: October 2019
// This program can scroll a background on the GameBoy


#include <stdio.h>
#include <gb/gb.h>
#include <gb/font.h>

#include "background.c"
#include "backgroundtiles.c"
#include "windowmap.c"

void main() {
    // This function can scroll a background on the GameBoy

    font_t min_font;

    font_init();
    min_font = font_load(font_min);
    font_set(min_font);

    set_bkg_data(37, 7, backgroundtiles);
    set_bkg_tiles(0, 0, 40, 18, backgroundmap);

    set_win_tiles(0, 0, 5, 1, windowmap);
    move_win(7,120);

    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    while (1) {
        scroll_bkg(1, 0);
        delay(100);
    }
}
