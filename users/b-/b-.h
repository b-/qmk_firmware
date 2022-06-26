#pragma once
#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#define COMBO_COUNT 1
enum custom_keycodes {
    LR_SHIFT = SAFE_RANGE,
    KC_MAKE,
    NEW_SAFE_RANGE
};


#define COMBO_TERM_PER_COMBO
#define MUST_HOLD_PER_COMBO
#define MUST_TAP_PER_COMBO
#define MUST_PRESS_IN_ORDER_PER_COMBO


#endif

