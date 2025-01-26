#pragma once
#include QMK_KEYBOARD_H

// Custom keycodes for macros and VIM commands
enum custom_keycodes {
    VIM_QUIT = SAFE_RANGE,     // :q
    VIM_REDO,                  // ctrl+r
    VIM_UNDO,                  // u
    VIM_YANK_LINE,            // yy
    VIM_DEL_LINE,             // dd
    VIM_START,                // 0
    VIM_CHANGE_WORD,          // cw
    VIM_CHANGE_EOL,           // c$
    VIM_CHANGE_SOL,           // c0
    MACRO_EMAIL,              // Email address
    MACRO_PASS,               // Password
    MACRO_ENUMBER,            // Employee number
    MACRO_EPASS               // Employee password
};

// Process custom keycodes and macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VIM_QUIT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) ":q");
            }
            return false;
        case VIM_START:
            if (record->event.pressed) {
                SEND_STRING("gg");
            }
            return false;
        case VIM_DEL_LINE:
            if (record->event.pressed) {
                SEND_STRING("dd");
            }
            return false;
        case VIM_YANK_LINE:
            if (record->event.pressed) {
                SEND_STRING("yy");
            }
            return false;
        case VIM_REDO:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("r"));
            }
            return false;
        case VIM_CHANGE_WORD:
            if (record->event.pressed) {
                SEND_STRING("cw");
            }
            return false;
        case VIM_CHANGE_EOL:
            if (record->event.pressed) {
                SEND_STRING("c$");
            }
            return false;
        case VIM_CHANGE_SOL:
            if (record->event.pressed) {
                SEND_STRING("c0");
            }
            return false;
        case MACRO_EMAIL:
            if (record->event.pressed) {
                SEND_STRING("email");
            }
            return false;
        case MACRO_PASS:
            if (record->event.pressed) {
                SEND_STRING("password");
            }
            return false;
        case MACRO_ENUMBER:
            if (record->event.pressed) {
                SEND_STRING("enumber");
            }
            return false;
        case MACRO_EPASS:
            if (record->event.pressed) {
                SEND_STRING("epassword");
            }
            return false;
        default:
            return true;
    }
}
