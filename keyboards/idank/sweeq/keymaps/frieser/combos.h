#pragma once
#include QMK_KEYBOARD_H

// Combo definitions
enum combos {
    SDF_TAB,    // SDF combo for TAB
    JK_TAB      // JK combo for Enter
};

// Key combinations for each combo
const uint16_t PROGMEM sdf_combo[] = {LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), COMBO_END};

// Combo actions mapping
combo_t key_combos[] = {
    [SDF_TAB] = COMBO(sdf_combo, KC_TAB),  
    [JK_TAB] = COMBO(jkl_combo, KC_ENT),
};
