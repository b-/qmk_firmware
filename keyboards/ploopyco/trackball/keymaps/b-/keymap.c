/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#ifdef REMAPPER
#define DRAG_BTN KC_BTN6
#else
#define DRAG_BTN DRAG_SCROLL
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_BTN1, KC_BTN3, KC_BTN4,
          KC_BTN2, DRAG_BTN
    ),
    [1] = LAYOUT(
        DPI_CONFIG, _______, KC_BTN5,
          LT(2, KC_TRNS), _______
    ),
    [2] = LAYOUT(
        RESET, _______, _______, _______, _______
    )
};
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    #ifdef REMAPPER
      // for use with https://github.com/jfedor2/hid_remapper for hires drag_scroll
    case KC_BTN5:
      if (record->event.pressed) {
        layer_on(1);
      } else {
        layer_off(1);
      }
      return true; // still send the HID report
    #endif
    default:
      return true; // Process all other keycodes normally
  }
}
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
//  debug_mouse=true;
}
