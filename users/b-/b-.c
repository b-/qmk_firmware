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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LR_SHIFT:
        if (record->event.pressed) {
            // when keycode LR_SHIFT is pressed
            tap_code(KC_C);
        } else {
            // when keycode LR_SHIFT is released
        }
        break;
    }
    return true;
};
