#pragma once

// Mouse keys - gentle acceleration
#define MOUSEKEY_MOVE_DELTA 3
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_TIME_TO_MAX 35

// Default tap-hold decision threshold
#define TAPPING_TERM 145

// Tap-hold keys become hold as soon as another key is pressed, except where
// get_hold_on_other_key_press() opts out.
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Allow get_tapping_term() to override the tapping term for specific keys.
#define TAPPING_TERM_PER_KEY

// RGB Matrix - disabled on startup
#define RGB_MATRIX_DEFAULT_ON false
// Default effect (solid color only)
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
// Default hue (white)
#define RGB_MATRIX_DEFAULT_HUE 0
// Default saturation (0 = white)
#define RGB_MATRIX_DEFAULT_SAT 0
// Default brightness (255 = max)
#define RGB_MATRIX_DEFAULT_VAL 255
