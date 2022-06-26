/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
#include "test.h"
#include "b-.h"

enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN,
  L_SHIFT,
  L_BOOT,
};

enum km_custom_keycodes {
    KC_MISSION_CONTROL = NEW_SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[3];
} key_combination_t;

key_combination_t key_comb_list[2] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}}
};

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_98(
                       KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,    KC_DEL,   KC_HOME, KC_END,   KC_MUTE,
//                        esc                 f1        f2        f3        f4         f5        f6       f7        f8        f9        f10        f11       f12             del       home      end       knob

                       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,   KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,
//                        ~`        1         2         3         4         5         6         7         8         9        0          -_         =+        bksp       numl      /         *         -

LT(MAC_FN,KC_TAB),     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS,   KC_P7,    KC_P8,   KC_P9,
          //  tab         q         w         e         r         t        y        u        i         o         p            [          ]         \          7         8         9

  LCTL_T(KC_ESC),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,          KC_ENT,    KC_P4,    KC_P5,   KC_P6,    KC_PPLS,
        // caps       a         s         d         f         g        h         j         k       l         ;         '"                   enter       4         5         6         +

LM(L_SHIFT, MOD_LSFT),  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH, LM(L_SHIFT, MOD_RSFT),  KC_UP,   KC_P1,    KC_P2,   KC_P3,
//        KC_LSHIFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSHIFT,       KC_UP,   KC_P1,    KC_P2,   KC_P3,
        // shift           z         x         c         v         b         n         m         ,<        .>        /?              rshift           up        1         2         3

        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                            KC_RCMMD, KC_RALT,  KC_RCTL,           KC_LEFT,  KC_DOWN,  KC_RGHT,     KC_P0,   KC_PDOT,  KC_PENT),
        // ctrl      opt       cmd                                     space                             cmd         alt      ctrl               left      down      right     0         .         nent

    [MAC_FN] = LAYOUT_ansi_98(//hold tab
        KC_TRNS,            KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,   KC_VOLD,  KC_VOLU,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        //esc                  f1        f2        f3        f4         f5        f6       f7        f8        f9        f10        f11       f12             del       home      end       knob

        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,   KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
//         ~`        1         2         3         4         5         6         7         8         9        0          -_         =+        bksp            numl      /         *         -

        KC_TRNS,  RGB_SPD,  RGB_VAI,  RGB_SPI,  RGB_HUI,  RGB_SAI,  BL_INC,  BL_DEC,  BL_BRTG,  BL_STEP,  KC_PSCR,  KC_SLCK,   KC_PAUS,  KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,
        // tab        q         w         e         r         t        y        u        i         o         p         [          ]         \                 7         8         9

        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_MOD,  RGB_HUD,  RGB_SAD,  KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  KC_TRNS,  KC_TRNS,        KC_TRNS,               KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        // caps       a         s         d         f         g        h         j         k       l         ;         '"              enter                  4         5         6         +

        KC_TRNS,    RGB_TOG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MO(L_BOOT),  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,                   KC_PGUP,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        // shift       z         x         c         v         b            n         m         ,<        .>        /?              rshift                     up          1         2         3

        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                          KC_TRNS,    KC_TRNS, KC_TRNS,           KC_HOME,  KC_PGDN,  KC_END,   KC_TRNS,  KC_TRNS,  KC_TRNS),
        // ctrl      opt       cmd                                     space                             cmd         alt      ctrl               left      down      right     0         .         nent
    [WIN_BASE] = LAYOUT_ansi_98(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,             KC_DEL,   KC_HOME,  KC_END,   KC_MUTE,
        //esc                  f1        f2        f3        f4         f5        f6       f7        f8        f9        f10        f11       f12             del       home      end       knob

        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,            KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,
        // ~`        1         2         3         4         5         6         7         8          9         10       -_         =+        bksp            numl      /         *         -

        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS,            KC_P7,    KC_P8,    KC_P9,
        //  tab       q         w         e         r         t        y        u        i         o         p         [          ]         \                 7         8         9

        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,             KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        // caps       a         s         d         f         g        h         j         k       l         ;         '"              enter                  4         5         6         +

        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,
        // shift       z         x         c         v         b         n         m         ,<        .>        /?              rshift                     up        1         2         3

        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,MO(WIN_FN),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT,  KC_PENT),
        // ctrl      opt       cmd                                     space                             cmd         alt      ctrl               left      down      right     0         .         nent
    [WIN_FN] = LAYOUT_ansi_98(
        KC_TRNS,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        //esc                  f1        f2        f3        f4         f5        f6       f7        f8        f9        f10        f11       f12             del       home      end       knob

        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        // ~`        1         2         3         4         5         6         7         8          9         10       -_         =+        bksp            numl      /         *         -

        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,
        //  tab       q         w         e         r         t        y        u        i         o         p         [          ]         \                 7         8         9

        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        // caps       a         s         d         f         g        h         j         k       l         ;         '"              enter                  4         5         6         +

        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        // shift       z         x         c         v         b         n         m         ,<        .>        /?              rshift                     up        1         2         3

        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
        // ctrl      opt       cmd                                     space                             cmd         alt      ctrl               left      down      right     0         .         nent

    [L_SHIFT] = LAYOUT_ansi_98(
        KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        //esc        f1          f2          f3          f4          f5          f6          f7          f8          f9          f10        f11         f12                  del       home      end       knob

        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
        // ~`        1         2         3         4         5         6         7         8          9         10       -_         =+        bksp          numl      /         *         -

        KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,
        //  tab       q         w         e         r         t        y        u        i         o         p         [          ]         \               7         8         9

        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        // caps       a         s         d         f         g        h         j         k       l         ;         '"              enter                4         5         6         +

        KC_CAPS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_CAPS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        // shift       z         x         c         v         b         n         m         ,<        .>        /?              rshift                     up        1         2         3

        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
        // ctrl      opt       cmd                                     space                             cmd         alt      ctrl               left      down      right     0         .         nent

    [L_BOOT] = LAYOUT_ansi_98(
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        //esc          f1        f2        f3        f4         f5        f6       f7        f8        f9            f10        f11       f12             del       home      end       knob

        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,    RESET,      KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
        // ~`        1         2         3         4         5         6         7         8          9         10       -_         =+        bksp          numl      /         *         -

        KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,
        //  tab       q         w         e         r         t        y        u        i         o         p         [          ]         \               7         8         9

        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        // caps       a         s         d         f         g        h         j         k       l         ;         '"              enter                4         5         6         +

        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        // shift       z         x         c         v         b         n         m         ,<        .>        /?              rshift                     up        1         2         3

        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                          KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
        // ctrl      opt       cmd                                     space                             cmd      alt      ctrl      left      down      right     0         .         nent
        ),
/*
    [BLANK] = LAYOUT_ansi_98(
        KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        //esc                  f1        f2        f3        f4         f5        f6       f7        f8        f9        f10        f11       f12             del       home      end       knob

        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
        // ~`        1         2         3         4         5         6         7         8          9         10       -_         =+        bksp          numl      /         *         -

        KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,
        //  tab       q         w         e         r         t        y        u        i         o         p         [          ]         \               7         8         9

        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        // caps       a         s         d         f         g        h         j         k       l         ;         '"              enter                4         5         6         +

        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        // shift       z         x         c         v         b         n         m         ,<        .>        /?              rshift                     up        1         2         3

        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
        // ctrl      opt       cmd                                     space                             cmd         alt      ctrl               left      down      right     0         .         nent
*/
};

bool dip_switch_update_user(uint8_t index, bool active) {
    /* Send default layer state to host */
    system_switch_state_report(index, active);
    return true;
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (IS_LAYER_ON(L_SHIFT)) {
            if (clockwise) {
                rgb_matrix_increase_speed();
            }
            else {
                rgb_matrix_decrease_speed();
            }
            return false;
        }
        if (IS_LAYER_ON(MAC_FN)) {
            if (clockwise) {
                tap_code_delay(KC_BRIU, TAP_CODE_DELAY);
            } else {
                tap_code_delay(KC_BRID, TAP_CODE_DELAY);
            }
        }
        else // default rotary function
            if (clockwise) {
                tap_code_delay(KC_VOLU, TAP_CODE_DELAY);
            } else {
                tap_code_delay(KC_VOLD, TAP_CODE_DELAY);
            }
        }
    return false; //stop processing further
}
/*
bool encoder_update_user(uint8_t index, bool clockwise) {
if (index == 0) {
  // not _LOWER and not _ASCII so only QWERTY is active
  if (!IS_LAYER_ON(MAC_BASE) && !IS_LAYER_ON(WIN_FN) && !IS_LAYER_ON(WIN_BASE))
  {
    if (clockwise) {
      tap_code(KC_VOLD);
    } else {
      tap_code(KC_VOLU);
    }
  }
  // If _LOWER (only one we really care about here)
  else if (IS_LAYER_ON(MAC_FN)) {
    if (clockwise) {
      tap_code(KC_BRIU);
    } else {
      tap_code(KC_BRID);
    }
  }
  // If _RAISE (only one we really care about here)
  else if (IS_LAYER_ON(_RAISE)) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}
return false;
}
*/
