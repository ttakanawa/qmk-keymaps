#include QMK_KEYBOARD_H

// Define NA for unused keys
#define NA XXXXXXX

// ENT_SFT tap time threshold (ms)
#define ENT_SFT_TAP_TERM 400

// Custom keycodes
enum custom_keycodes {
    ENT_SFT = SAFE_RANGE,
    ZERO_SFT,
    SLSH_SFT
};

// Tap Dance declarations
enum {
    TD_Q_ESC,
    TD_MO1_SHENT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      NA, TD(TD_Q_ESC),    KC_W,    KC_E,    KC_R,    KC_T,  KC_TAB,    RM_TOGG,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           NA,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LSFT,         NA,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, SLSH_SFT,     NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          KC_LOPT, KC_LCTL, KC_LCMD,    ENT_SFT,  KC_SPC,TD(TD_MO1_SHENT)
                                      //`--------------------------'  `--------------------------'
  ),

  // inspired by https://shop.keyboard.io/pages/the-atreus-layout
  [1] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA, KC_EXLM,   KC_AT, KC_HASH,      NA,      NA,      NA,    QK_BOOT,      NA,    KC_7,    KC_8,    KC_9, KC_MINS,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           NA, KC_LPRN, KC_CIRC, KC_BSLS,  KC_DLR, KC_RPRN, _______,         NA, KC_BSPC,    KC_4,    KC_5,    KC_6,  KC_EQL,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_LBRC, KC_RBRC, KC_QUOT, KC_LCBR, KC_RCBR,                       KC_GRV,    KC_1,    KC_2,    KC_3, ZERO_SFT,     NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // inspired by https://shop.keyboard.io/pages/the-atreus-layout
  [2] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA, _______,    MO(3),KC_UP,LSG(KC_RCBR),KC_PGUP,QK_BOOT,         NA,      NA,   KC_F7,   KC_F8,   KC_F9,  KC_F10,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           NA, KC_VOLU, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN, _______,         NA,      NA,   KC_F4,   KC_F5,   KC_F6,  KC_F11,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_VOLD,       NA, KC_SPC,  KC_ENT,G(KC_GRV),                          NA,   KC_F1,   KC_F2,   KC_F3,  KC_F12,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // Window management & mouse keys
  [3] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA, _______,_______,LSG(KC_LBRC),LSG(KC_RCBR),G(KC_9),NA,         NA, MS_WHLR, MS_WHLD, MS_WHLU, MS_WHLL,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           NA,      NA,      NA, G(KC_4), G(KC_5), G(KC_6), _______,         NA, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA,      NA,      NA, G(KC_1), G(KC_2), G(KC_3),                           NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    MS_BTN1, MS_BTN2, MS_ACL2
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

void mo1_each_tap(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_on(1);  // Turn on layer 1 immediately on first tap
    } else {
        layer_off(1);  // Turn off layer on double tap or more
    }
}

void mo1_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && !state->pressed) {
        layer_off(1);  // Turn off layer if released after single tap
    } else if (state->count >= 2) {
        // Double tap: Shift+Enter
        register_code(KC_LSFT);
        tap_code(KC_ENT);
        unregister_code(KC_LSFT);
    }
}

void mo1_reset(tap_dance_state_t *state, void *user_data) {
    layer_off(1);  // Always turn off layer 1
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_finished, q_reset),
    [TD_MO1_SHENT] = ACTION_TAP_DANCE_FN_ADVANCED(mo1_each_tap, mo1_finished, mo1_reset)
};

// Custom Enter/Shift key state tracking
static bool custom_ent_shift_pressed = false;      // Is ENT_SFT currently held?
static bool custom_ent_shift_shift_used = false;   // Was Shift used while ENT_SFT held?
static uint16_t custom_ent_shift_timer = 0;        // Timer to track hold duration

// Custom Zero/Shift key state tracking
static bool zero_sft_pressed = false;              // Is ZERO_SFT currently held?
static bool zero_sft_shift_used = false;           // Was Shift used while ZERO_SFT held?
static uint16_t zero_sft_timer = 0;                // Timer to track hold duration

// Custom Slash/Shift key state tracking
static bool slsh_sft_pressed = false;              // Is SLSH_SFT currently held?
static bool slsh_sft_shift_used = false;           // Was Shift used while SLSH_SFT held?
static bool slsh_sft_shifted_tap = false;          // Should a tap send shifted Slash?
static uint16_t slsh_sft_timer = 0;                // Timer to track hold duration

static void mark_shift_tap_used_by(uint16_t keycode) {
    if (custom_ent_shift_pressed && keycode != ENT_SFT) {
        custom_ent_shift_shift_used = true;
    }
    if (zero_sft_pressed && keycode != ZERO_SFT) {
        zero_sft_shift_used = true;
    }
    if (slsh_sft_pressed && keycode != SLSH_SFT) {
        slsh_sft_shift_used = true;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        mark_shift_tap_used_by(keycode);
    }

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

        case ZERO_SFT:
            if (record->event.pressed) {
                zero_sft_pressed = true;
                zero_sft_shift_used = false;
                zero_sft_timer = timer_read();
                register_code(KC_LSFT);
            } else {
                zero_sft_pressed = false;
                unregister_code(KC_LSFT);
                if (!zero_sft_shift_used && timer_elapsed(zero_sft_timer) < ENT_SFT_TAP_TERM) {
                    tap_code(KC_0);
                }
            }
            return false;

        case SLSH_SFT:
            if (record->event.pressed) {
                slsh_sft_pressed = true;
                slsh_sft_shift_used = false;
                slsh_sft_shifted_tap = custom_ent_shift_pressed || zero_sft_pressed;
                slsh_sft_timer = timer_read();
                register_code(KC_LSFT);
            } else {
                slsh_sft_pressed = false;
                unregister_code(KC_LSFT);
                if (!slsh_sft_shift_used && timer_elapsed(slsh_sft_timer) < ENT_SFT_TAP_TERM) {
                    if (slsh_sft_shifted_tap) {
                        tap_code16(KC_QUES);
                    } else {
                        tap_code(KC_SLSH);
                    }
                }
                slsh_sft_shifted_tap = false;
            }
            return false;

        default:
            break;
    }

    return true;  // Continue normal processing for other keys
}
