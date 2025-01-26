#include QMK_KEYBOARD_H
#include "macros.h"
#include "combos.h"

// Layer definitions
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layer
    [0] = LAYOUT_split_3x5_2(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,         RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                                                  LT(6,KC_BSPC),LT(1,KC_SPC), LT(2,KC_ENT), LT(3,KC_ESC)
    ),
    // Mouse Layer
    [1] = LAYOUT_split_3x5_2(
        KC_TRNS,      KC_MPRV,      KC_VOLU,      KC_MNXT,      KC_ACL0,      KC_TRNS,      KC_BTN1,      KC_WH_U,      KC_BTN2,      KC_TRNS,
        KC_TRNS,      KC_BTN2,      KC_MUTE,      KC_BTN1,      KC_ACL1,      KC_MS_L,      KC_MS_D,      KC_MS_U,      KC_MS_R,      KC_TRNS,
        KC_TRNS,      KC_BTN3,      KC_VOLD,      KC_MPLY,      KC_ACL2,      KC_TRNS,      KC_WH_L,      KC_WH_D,      KC_WH_R,      KC_TRNS,
                                                  KC_BTN3,      KC_TRNS,      KC_BTN1,      KC_BTN2
    ),
    // Symbols Layer
    [2] = LAYOUT_split_3x5_2(
        KC_HASH,      KC_PERC,      KC_GRV,       KC_UNDS,      KC_TRNS,      KC_MINS,      KC_BSLS,      KC_LBRC,      KC_RBRC,      KC_SLSH,
        KC_AMPR,      KC_DLR,       KC_EXLM,      KC_DQUO,      KC_TRNS,      KC_QUOT,      KC_LPRN,      KC_RPRN,      KC_LCBR,      KC_RCBR,
        KC_EQL,       KC_ASTR,      KC_AT,        KC_LT,        KC_TRNS,      KC_TRNS,      KC_GT,        KC_QUES,      KC_CIRC,      KC_TRNS,
                                                  KC_LSFT,      KC_TAB,       KC_TRNS,      KC_TRNS
    ),
    // Macros Layer
    [3] = LAYOUT_split_3x5_2(
        VIM_QUIT,       KC_C,           LCTL(KC_U),      VIM_START,      MACRO_PASS,      VIM_REDO,       VIM_YANK_LINE,  VIM_DEL_LINE,   KC_TRNS,      KC_TRNS,
        KC_0,           KC_B,           KC_W,            KC_E,           KC_DLR,         LSFT(KC_N),     VIM_CHANGE_SOL, VIM_CHANGE_WORD,VIM_CHANGE_EOL, KC_TRNS,
        MACRO_EMAIL,      KC_D,           LCTL(KC_D),      LSFT(KC_G),     MACRO_EPASS,        KC_N,           KC_TRNS,        LSFT(KC_COMM),  LSFT(KC_DOT),   MACRO_ENUMBER,
                                                        KC_X,           KC_ESC,         KC_TRNS,        KC_TRNS
    ),
    // Extra Symbols Layer
    [4] = LAYOUT_split_3x5_2(
        KC_TRNS,      KC_COLN,      KC_LT,        KC_GT,        KC_SCLN,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
        KC_LCBR,      KC_RCBR,      KC_LPRN,      KC_RPRN,      KC_AT,        KC_TRNS,      KC_NO,        KC_EQL,       KC_PLUS,      KC_PERC,
        KC_TRNS,      KC_EXLM,      KC_LBRC,      KC_RBRC,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS
    ),
    // Layer 5 (Empty/Reserved)
    [5] = LAYOUT_split_3x5_2(
        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
                                                  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS
    ),
    // Numpad Layer
    [6] = LAYOUT_split_3x5_2(
        KC_PSLS,      KC_1,         KC_2,         KC_3,         KC_PPLS,      KC_TRNS,      KC_HOME,      KC_PGUP,      KC_INS,       KC_TRNS,
        KC_0,         KC_4,         KC_5,         KC_6,         KC_PMNS,      KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,      KC_TRNS,
        KC_PAST,      KC_7,         KC_8,         KC_9,         KC_PEQL,      KC_TRNS,      KC_END,       KC_PGDN,      KC_TRNS,      QK_BOOT,
                                                  KC_TRNS,      KC_TRNS,      KC_DEL,       KC_TRNS
    ),
    // Layer 7 (Function/System)
    [7] = LAYOUT_split_3x5_2(
        KC_TRNS,      KC_TRNS,      KC_COLN,      KC_ESC,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_DEL,
        KC_TRNS,      KC_PERC,      KC_SLSH,      KC_ENT,       KC_TRNS,      DF(1),        KC_LGUI,      KC_TRNS,      KC_TRNS,      KC_TRNS,
        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_EXLM,      KC_TRNS,      DF(0),        KC_TRNS,      RALT_T(KC_COMM),RCTL_T(KC_DOT),QK_BOOT,
                                                  KC_TRNS,      KC_TAB,       KC_NO,        KC_TRNS
    )
};