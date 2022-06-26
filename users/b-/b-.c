#include "b-.h"

const uint16_t PROGMEM lrshift_combo[] = {KC_LSHIFT, KC_RSHIFT, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    //COMBO(lrshift_combo, KC_CAPS),
    COMBO(lrshift_combo, LR_SHIFT),
};

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
            if (!record->event.pressed) {
            uint8_t temp_mod = get_mods();
            uint8_t temp_osm = get_oneshot_mods();
            clear_mods(); clear_oneshot_mods();
            SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP);
    #ifndef FLASH_BOOTLOADER
            if ((temp_mod | temp_osm) & MOD_MASK_SHIFT)
    #endif
            {
                SEND_STRING(":flash");
            }
            if ((temp_mod | temp_osm) & MOD_MASK_CTRL) {
                SEND_STRING(" -j8 --output-sync");
            }
            tap_code(KC_ENT);
            set_mods(temp_mod);
        }
        break;
    case LR_SHIFT:
        if (record->event.pressed) {
            // when keycode LR_SHIFT is pressed
            tap_code(KC_CAPS);
        } else {
            // when keycode LR_SHIFT is released
        }
        break;

  }
  return process_record_keymap(keycode, record);
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case LR_SHIFT:
            return 2000;
    }
    return COMBO_TERM;
}

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
    switch (index) {
        case LR_SHIFT:
            return true;
    }

    return false;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    // return true

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    uint16_t key;
    uint8_t idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;

}

bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        /* List combos here that you want to only activate if their keys
         * are pressed in the same order as they are defined in the combo's key
         * array. */
        case LR_SHIFT:
            return false;
        default:
            return false;
    }
}
