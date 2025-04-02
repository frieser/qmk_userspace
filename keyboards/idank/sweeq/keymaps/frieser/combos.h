#pragma once
#include QMK_KEYBOARD_H

// Combo definitions
enum combos {
    SDF_TAB,    // SDF combo for TAB
    JKL_ENTER,      // JK combo for Enter
    // for graphite layout
    RTS_TAB,    // RTS combo for TAB
    HAE_ENTER,    // HAL combo for Enter
};

// Key combinations for each combo
const uint16_t PROGMEM sdf_combo[] = {LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM rts_combo[] = {LALT_T(KC_R), LCTL_T(KC_T), LSFT_T(KC_S), COMBO_END};
const uint16_t PROGMEM hae_combo[] = {RSFT_T(KC_H), RCTL_T(KC_A), RALT_T(KC_E), COMBO_END};

// Combo actions mapping
combo_t key_combos[] = {
    [SDF_TAB] = COMBO(sdf_combo, KC_TAB),
    [JKL_ENTER] = COMBO(jkl_combo, KC_ENT),
    [RTS_TAB] = COMBO(rts_combo, KC_TAB),
    [HAE_ENTER] = COMBO(hae_combo, KC_ENT),
};
