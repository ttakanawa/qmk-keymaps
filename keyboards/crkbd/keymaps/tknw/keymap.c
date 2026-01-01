#include QMK_KEYBOARD_H

// Define NA for unused keys
#define NA XXXXXXX

// ENT_SFT tap time threshold (ms)
#define ENT_SFT_TAP_TERM 400

// Custom keycodes
enum custom_keycodes {
    ENT_SFT = SAFE_RANGE
};

// Tap Dance declarations
enum {
    TD_Q_ESC,
    TD_MO1_SHENT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       NA,TD(TD_Q_ESC),    KC_W,    KC_E,    KC_R,    KC_T,  KC_TAB,    RM_TOGG,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           NA,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LSFT,         NA,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          KC_LOPT, KC_LCTL, KC_LCMD,    ENT_SFT,  KC_SPC,TD(TD_MO1_SHENT)
                                      //`--------------------------'  `--------------------------'
  ),

  // inspired by https://shop.keyboard.io/pages/the-atreus-layout
  [1] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA, KC_QUOT, KC_BSLS,      NA,      NA,      NA,      NA,    QK_BOOT,      NA,    KC_7,    KC_8,    KC_9, KC_MINS,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           NA, KC_LPRN, KC_RPRN,      NA,      NA,      NA, _______, C(G(KC_Q)), KC_LSFT,    KC_4,    KC_5,    KC_6,  KC_EQL,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_LBRC, KC_RBRC,      NA,      NA,      NA,                      KC_BSPC,    KC_1,    KC_2,    KC_3,    KC_0,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // inspired by https://shop.keyboard.io/pages/the-atreus-layout
  [2] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA, _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP,      NA,         NA,      NA,   KC_F7,   KC_F8,   KC_F9,  KC_F10,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           NA, KC_VOLU, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN,      NA,         NA,      NA,   KC_F4,   KC_F5,   KC_F6,  KC_F11,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_VOLD, QK_BOOT,  KC_SPC,  KC_ENT,  KC_GRV,                           NA,   KC_F1,   KC_F2,   KC_F3,  KC_F12,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

// Tap Dance definitions
void q_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            layer_on(2);  // Hold: Layer 2
        } else {
            tap_code(KC_Q);  // Single tap: Q
        }
    } else if (state->count >= 2) {
        tap_code(KC_ESC);  // Double tap: ESC
    }
}

void q_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_off(2);  // Release Layer 2
    }
}

void mo1_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            layer_on(1);  // Hold: Layer 1
        }
        // Single tap: do nothing special (just momentary layer)
    } else if (state->count >= 2) {
        // Double tap: Shift+Enter
        register_code(KC_LSFT);
        tap_code(KC_ENT);
        unregister_code(KC_LSFT);
    }
}

void mo1_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_off(1);  // Release Layer 1
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_finished, q_reset),
    [TD_MO1_SHENT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mo1_finished, mo1_reset)
};

// Custom Enter/Shift key state tracking
static bool custom_ent_shift_pressed = false;      // Is ENT_SFT currently held?
static bool custom_ent_shift_shift_used = false;   // Was Shift used while ENT_SFT held?
static uint16_t custom_ent_shift_timer = 0;        // Timer to track hold duration

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENT_SFT:
            if (record->event.pressed) {
                // Key pressed down
                custom_ent_shift_pressed = true;
                custom_ent_shift_shift_used = false;
                custom_ent_shift_timer = timer_read();  // Record press time
                register_code(KC_RSFT);  // Immediately activate Shift
            } else {
                // Key released
                custom_ent_shift_pressed = false;
                unregister_code(KC_RSFT);  // Deactivate Shift

                // If no other key was pressed AND it was a short tap, send Enter
                if (!custom_ent_shift_shift_used && timer_elapsed(custom_ent_shift_timer) < ENT_SFT_TAP_TERM) {
                    tap_code(KC_ENT);
                }
            }
            return false;  // Skip further processing

        default:
            // Any other key pressed while ENT_SFT is held
            if (custom_ent_shift_pressed && record->event.pressed) {
                custom_ent_shift_shift_used = true;
            }
            break;
    }

    return true;  // Continue normal processing for other keys
}
