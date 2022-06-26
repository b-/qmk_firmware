#include "b-.h"

// enum combo_events {
//   BOTH_SHIFTS_CAPS,
//   COMBO_LENGTH
// };
// uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

// const uint16_t PROGMEM both_shifts_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};

// combo_t key_combos[] = {
//   [BOTH_SHIFTS_CAPS] = COMBO_ACTION(both_shifts_combo),
// };
// /* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case BOTH_SHIFTS_CAPS:
//       if (pressed) {
//         tap_code16(KC_CAPS);
//       }
//       break;
//   }
// }

const uint16_t PROGMEM lrshift_combo[] = {KC_LSHIFT, KC_RSHIFT, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(lrshift_combo, KC_CAPS),
};

///////////



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
            tap_code(KC_C);
        } else {
            // when keycode LR_SHIFT is released
        }
        break;

  }
  return process_record_keymap(keycode, record);
}

///////////

//  bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//      switch (keycode) {
//      }
//      return true;
//  };
