#pragma once
#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"
#include QMK_KEYBOARD_H

#define COMBO_COUNT 1
enum custom_keycodes {
    #ifdef KEYBOARD_ploopyco_trackball
    LR_SHIFT = PLOOPY_SAFE_RANGE,// free range ploopies
    #else
    LR_SHIFT = SAFE_RANGE,
    #endif
    KC_MAKE,
    NEW_SAFE_RANGE
};


#define COMBO_TERM_PER_COMBO
#define MUST_HOLD_PER_COMBO
#define MUST_TAP_PER_COMBO
#define MUST_PRESS_IN_ORDER_PER_COMBO


#endif

