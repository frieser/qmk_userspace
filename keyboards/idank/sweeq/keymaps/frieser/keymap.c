#include QMK_KEYBOARD_H
#include "macros.h"
#include "combos.h"

enum layers {
    BASE,      // Base layer with letters
    NAV,       // Navigation and mouse controls
    SYM,       // Primary symbols
    MACRO,     // Macros and commands
    NUM,       // Numbers and numpad
    GRAPHITE     // Graphite layout
};

enum {
    TD_1_F1,
    TD_2_F2,
    TD_3_F3,
    TD_4_F4,
    TD_5_F5,
    TD_6_F6,
    TD_7_F7,
    TD_8_F8,
    TD_9_F9,
    TD_0_F10,
    TD_MINS_F11,
    TD_EQL_F12,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_1_F1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
    [TD_2_F2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
    [TD_3_F3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
    [TD_4_F4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
    [TD_5_F5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
    [TD_6_F6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
    [TD_7_F7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
    [TD_8_F8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
    [TD_9_F9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
    [TD_0_F10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
    [TD_MINS_F11] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_F11),
    [TD_EQL_F12] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_F12),
};
const key_override_t apostrophe_override =
    ko_make_basic(MOD_MASK_SHIFT, RGUI_T(KC_QUOT), KC_COLN);  // Shift ' → :
const key_override_t dot_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COMM);   // Shift . → ,
const key_override_t comma_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_MINUS, KC_PIPE);  // Shift - → |

const key_override_t* key_overrides[] = {
    &apostrophe_override,
    &dot_override,
    &comma_override,
    NULL  // End
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layer
    [BASE] = LAYOUT_split_3x5_2(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,         RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_QUOT),
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,         KC_M,         KC_MINUS,      KC_DOT,       KC_SLSH,
                                                  LT(MACRO,KC_BSPC),LT(NAV,KC_SPC), LT(SYM,KC_ENT), LT(NUM,KC_ESC)
    ),
    // Graphite Layer
    [GRAPHITE] = LAYOUT_split_3x5_2(
        KC_B,         KC_L,         KC_D,         KC_W,         KC_Z,         KC_QUOT,      KC_F,         KC_O,         KC_U,         KC_J,
        LGUI_T(KC_N), LALT_T(KC_R), LCTL_T(KC_T), LSFT_T(KC_S), KC_G,         KC_Y,         RSFT_T(KC_H), RCTL_T(KC_A), RALT_T(KC_E), RGUI_T(KC_I),
        KC_Q,         KC_X,         KC_M,         KC_C,         KC_V,         KC_K,         KC_P,         KC_COMM,       KC_DOT,       KC_SLSH,
                                                  LT(MACRO,KC_BSPC),LT(NAV,KC_SPC), LT(SYM,KC_ENT), LT(NUM,KC_ESC)
),
    // Navigation Layer
    [NAV] = LAYOUT_split_3x5_2(
        KC_TRNS,      KC_MPRV,      KC_VOLU,      KC_MNXT,      KC_ACL0,      KC_TRNS,      KC_BTN1,      KC_WH_U,      KC_BTN2,      KC_TRNS,
        KC_TRNS,      KC_BTN2,      KC_MUTE,      KC_BTN1,      KC_ACL1,      KC_MS_L,      KC_MS_D,      KC_MS_U,      KC_MS_R,      KC_TRNS,
        KC_TRNS,      KC_BTN3,      KC_VOLD,      KC_MPLY,      KC_ACL2,      KC_TRNS,      KC_WH_L,      KC_WH_D,      KC_WH_R,      KC_TRNS,
                                                  KC_BTN3,      KC_TRNS,      KC_BTN1,      KC_BTN2
    ),
    // Symbols Layer
    [SYM] = LAYOUT_split_3x5_2(
        KC_GRV,      KC_ASTR,      KC_EQL,       KC_EXLM,      KC_CIRC,      KC_QUOT,      KC_DQUO,      KC_PERC,      KC_BSLS,      KC_TILD,
        KC_0,     KC_LBRC,       KC_LCBR,      KC_LPRN,      KC_UNDS,      KC_MINUS,      KC_RPRN,      KC_RCBR,      KC_RBRC,      KC_DLR,
        KC_HASH,     KC_AMPR,      KC_AT,        KC_LT,        ALGR(KC_SLSH),KC_EQL,       KC_GT,        KC_COMM,      KC_DOT,      KC_SCLN,
                                                 KC_LSFT,      KC_TAB,       KC_TRNS,      KC_TRNS
    ),
    // Macros Layer
    [MACRO] = LAYOUT_split_3x5_2(
        VIM_QUIT,     KC_C,         LCTL(KC_U),   VIM_START,    MACRO_PASS,   VIM_REDO,     VIM_LSP_REN,  VIM_COMMENT,  VIM_LSP_DOC,  KC_TRNS,
        KC_0,         KC_B,         KC_W,         KC_E,         KC_DLR,       LSFT(KC_N),   VIM_LSP_DEF,  VIM_CHANGE_WORD, VIM_LSP_REF, KC_TRNS,
        MACRO_EMAIL,  KC_D,         LCTL(KC_D),   LSFT(KC_G),   MACRO_EPASS,  KC_N,         KC_TRNS,      LSFT(KC_COMM),LSFT(KC_DOT), MACRO_ENUMBER,
                                                  KC_TRNS,      KC_TRNS,       KC_ESC,      KC_X
    ),
    // Numpad Layer
    [NUM] = LAYOUT_split_3x5_2(
        TD(TD_EQL_F12), TD(TD_7_F7),  TD(TD_8_F8),  TD(TD_9_F9),  KC_PPLS,      KC_TRNS,      KC_HOME,      KC_PGUP,      KC_INS,       KC_TRNS,
        TD(TD_MINS_F11),TD(TD_4_F4),  TD(TD_5_F5),  TD(TD_6_F6),  KC_PMNS,      KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,      KC_TRNS,
        TD(TD_0_F10),   TD(TD_1_F1),  TD(TD_2_F2),  TD(TD_3_F3),  KC_PEQL,      KC_TRNS,      KC_END,       KC_PGDN,      KC_TRNS,      QK_BOOT,
                                                    KC_DEL,       KC_0,         KC_TRNS,      KC_TRNS
    ),
};
