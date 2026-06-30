#include "keycodes.h"
#include QMK_KEYBOARD_H

// Define NA for unused keys
#define NA XXXXXXX

// LOPT_TAB tap time threshold (ms)
#define LOPT_TAB_TAP_TERM 400
#define LOPT_TAB_DEFER_TERM 10
#define ENT_SFT_TAP_TERM 400

// Layers
enum layers {
    BASE,
    NAV,
    NUM,
    FUN,
    MOUSE
};

// Custom keycodes
enum custom_keycodes {
    ENT_SFT = SAFE_RANGE,
    LOPT_TAB,
    SLSH_SFT,
    SCLN_FUN
};

// Tap Dance declarations
enum {
    TD_Q_ESC,
    TD_NUM_SHENT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      NA, TD(TD_Q_ESC),    KC_W,    KC_E,    KC_R,    KC_T,      NA,         NA,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           NA,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      NA,         NA,    KC_H,    KC_J,    KC_K,    KC_L,SCLN_FUN,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA,LSFT_T(KC_Z),KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,SLSH_SFT,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                    LOPT_TAB,LCTL_T(KC_LNG2),KC_LCMD,    ENT_SFT,KC_SPC,TD(TD_NUM_SHENT)
                                      //`--------------------------'  `--------------------------'
  ),

  // Cursor navigation and window controls
  [NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA, _______, G(KC_LCBR), KC_UP,G(KC_RCBR),KC_PGUP,      NA,       NA,      NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, LT(MOUSE, KC_VOLU),KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN,NA,       NA,      NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_VOLD,      NA,  KC_SPC,  KC_ENT,G(KC_GRV),                          NA,      NA,      NA,      NA, KC_RSFT,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // Number and Symbols
  [NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      NA,         NA,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_LPRN,      NA,      NA,      NA, KC_RPRN,      NA,         NA, KC_BSPC, KC_MINS,  KC_EQL,  KC_GRV, KC_QUOT,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_LSFT,      NA,      NA,      NA,      NA,                      KC_LBRC, KC_RBRC, KC_CIRC, KC_DLR,RSFT_T(KC_BSLS),NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // Function keys
  [FUN] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      NA,         NA,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA,      NA,      NA,      NA,      NA,      NA,      NA,         NA, KC_VOLD, KC_VOLU,  KC_F11,  KC_F12, _______,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_LSFT,      NA,      NA,      NA,      NA,                      RM_TOGG,      NA,      NA,      NA, QK_BOOT,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // Mouse keys
  [MOUSE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA, _______,      NA,   MS_UP,      NA, MS_WHLD,      NA,         NA,      NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           NA, _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLU,      NA,         NA, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, QK_BOOT, MS_WHLR,      NA, MS_WHLL,      NA,                           NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                               NA, MS_BTN2, MS_BTN1,    MS_BTN1, MS_BTN2, _______
                                      //`--------------------------'  `--------------------------'
  )
};

// Tap Dance definitions
void q_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            layer_on(NAV);  // Hold: enable NAV
        } else {
            tap_code(KC_Q);  // Single tap: Q
        }
    } else if (state->count >= 2) {
        tap_code(KC_ESC);  // Double tap: ESC
    }
}

void q_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_off(NAV);  // Release: disable NAV
    }
}

void num_each_tap(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_on(NUM);
    } else {
        layer_off(NUM);
    }
}

void num_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && !state->pressed) {
        layer_off(NUM);
        tap_code(KC_LNG1);
    } else if (state->count >= 2) {
        register_code(KC_LSFT);
        tap_code(KC_ENT);
        unregister_code(KC_LSFT);
    }
}

void num_reset(tap_dance_state_t *state, void *user_data) {
    layer_off(NUM);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_finished, q_reset),
    [TD_NUM_SHENT] = ACTION_TAP_DANCE_FN_ADVANCED(num_each_tap, num_finished, num_reset)
};

// Custom Enter/Shift key state tracking
static bool custom_ent_shift_pressed = false;
static bool custom_ent_shift_shift_used = false;
static uint16_t custom_ent_shift_timer = 0;

// Custom LOPT/Tab key state tracking
static bool lopt_tab_pressed = false;              // Is LOPT_TAB currently held?
static bool lopt_tab_used = false;                 // Was LOPT used while LOPT_TAB held?
static uint16_t lopt_tab_timer = 0;                // Timer to track hold duration
static bool lopt_tab_tap_pending = false;
static bool lopt_tab_tap_sent = false;
static uint16_t lopt_tab_tap_timer = 0;

// Custom Slash/Shift key state tracking
static bool slsh_sft_pressed = false;
static bool slsh_sft_used = false;
static bool slsh_sft_tap_sent = false;
static bool slsh_sft_shift_registered = false;
static uint16_t slsh_sft_timer = 0;

// Custom Semicolon/Function layer key state tracking
static bool scln_fun_pressed = false;
static bool scln_fun_used = false;
static bool scln_fun_tap_sent = false;
static bool scln_fun_layer_enabled = false;
static uint16_t scln_fun_timer = 0;

static void mark_ent_sft_used_by(uint16_t keycode) {
    if (custom_ent_shift_pressed && keycode != ENT_SFT) {
        custom_ent_shift_shift_used = true;
    }
}

static void mark_key_used_by(uint16_t keycode, bool pressed, uint16_t self_keycode, bool *used) {
    if (pressed && keycode != self_keycode && !IS_MODIFIER_KEYCODE(keycode)) {
        *used = true;
    }
}

static void register_slsh_sft_shift(void) {
    if (!slsh_sft_shift_registered) {
        register_code(KC_RSFT);
        slsh_sft_shift_registered = true;
    }
}

static void mark_slsh_sft_used_by(uint16_t keycode) {
    if (!slsh_sft_pressed || keycode == SLSH_SFT) {
        return;
    }

    slsh_sft_used = true;
    if (keycode == ENT_SFT) {
        if (slsh_sft_shift_registered) {
            unregister_code(KC_RSFT);
            slsh_sft_shift_registered = false;
        }
    } else if (!slsh_sft_tap_sent && !IS_MODIFIER_KEYCODE(keycode)) {
        register_slsh_sft_shift();
    }
}

static void enable_scln_fun_layer(void) {
    if (!scln_fun_layer_enabled) {
        layer_on(FUN);
        scln_fun_layer_enabled = true;
    }
}

static void disable_scln_fun_layer(void) {
    if (scln_fun_layer_enabled) {
        layer_off(FUN);
        scln_fun_layer_enabled = false;
    }
}

static bool is_modifier_release_key(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        return false;
    }

    if (IS_MODIFIER_KEYCODE(keycode)) {
        return true;
    }

    return IS_QK_MOD_TAP(keycode) && record->tap.count == 0;
}

static bool is_tap_uninterrupted(bool used, bool tap_sent, uint16_t timer, uint16_t term) {
    return !used && !tap_sent && timer_elapsed(timer) < term;
}

static bool tap_shifted_if_needed(uint16_t keycode, bool *used, bool *tap_sent) {
    if (!(custom_ent_shift_pressed || (get_mods() & MOD_MASK_SHIFT))) {
        return false;
    }

    tap_code16(keycode);
    *used = true;
    *tap_sent = true;
    if (custom_ent_shift_pressed) {
        custom_ent_shift_shift_used = true;
    }
    return true;
}

static void send_lopt_tab_tap(void) {
    tap_code(KC_TAB);
    lopt_tab_tap_pending = false;
    lopt_tab_tap_sent = true;
    lopt_tab_used = true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    (void)record;

    return keycode != LSFT_T(KC_Z);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (lopt_tab_pressed && !lopt_tab_used && !lopt_tab_tap_sent && is_modifier_release_key(keycode, record) &&
        timer_elapsed(lopt_tab_timer) < LOPT_TAB_TAP_TERM) {
        unregister_code(KC_LOPT);
        send_lopt_tab_tap();
    }

    if (lopt_tab_tap_pending) {
        if (is_modifier_release_key(keycode, record)) {
            // Send Tab before modifier release is processed, preserving modifier+Tab.
            send_lopt_tab_tap();
        } else if (record->event.pressed && !IS_MODIFIER_KEYCODE(keycode)) {
            send_lopt_tab_tap();
        }
    }

    if (record->event.pressed) {
        mark_ent_sft_used_by(keycode);
        mark_slsh_sft_used_by(keycode);
        mark_key_used_by(keycode, scln_fun_pressed, SCLN_FUN, &scln_fun_used);
        mark_key_used_by(keycode, lopt_tab_pressed, LOPT_TAB, &lopt_tab_used);
    }

    switch (keycode) {
        case ENT_SFT:
            if (record->event.pressed) {
                bool slsh_sft_chord = slsh_sft_pressed && !slsh_sft_tap_sent;

                custom_ent_shift_pressed = true;
                custom_ent_shift_shift_used = slsh_sft_chord;
                custom_ent_shift_timer = timer_read();
                register_code(KC_RSFT);
                if (slsh_sft_chord) {
                    tap_code(KC_ENT);
                }
            } else {
                custom_ent_shift_pressed = false;
                unregister_code(KC_RSFT);
                if (!custom_ent_shift_shift_used && timer_elapsed(custom_ent_shift_timer) < ENT_SFT_TAP_TERM) {
                    tap_code(KC_ENT);
                }
            }
            return false;

        case LOPT_TAB:
            if (record->event.pressed) {
                lopt_tab_pressed = true;
                lopt_tab_used = false;
                lopt_tab_tap_sent = false;
                lopt_tab_timer = timer_read();
                register_code(KC_LOPT);
            } else {
                lopt_tab_pressed = false;
                if (!lopt_tab_tap_sent) {
                    unregister_code(KC_LOPT);
                }
                if (is_tap_uninterrupted(lopt_tab_used, lopt_tab_tap_sent, lopt_tab_timer, LOPT_TAB_TAP_TERM)) {
                    lopt_tab_tap_pending = true;
                    lopt_tab_tap_timer = timer_read();
                }
            }
            return false;

        case SLSH_SFT:
            if (record->event.pressed) {
                slsh_sft_pressed = true;
                slsh_sft_used = false;
                slsh_sft_tap_sent = false;
                slsh_sft_shift_registered = false;
                slsh_sft_timer = timer_read();

                tap_shifted_if_needed(KC_QUES, &slsh_sft_used, &slsh_sft_tap_sent);
            } else {
                if (slsh_sft_shift_registered) {
                    unregister_code(KC_RSFT);
                } else if (is_tap_uninterrupted(slsh_sft_used, slsh_sft_tap_sent, slsh_sft_timer, TAPPING_TERM)) {
                    tap_code(KC_SLSH);
                }
                slsh_sft_pressed = false;
                slsh_sft_used = false;
                slsh_sft_tap_sent = false;
                slsh_sft_shift_registered = false;
            }
            return false;

        case SCLN_FUN:
            if (record->event.pressed) {
                scln_fun_pressed = true;
                scln_fun_used = false;
                scln_fun_tap_sent = false;
                scln_fun_timer = timer_read();

                if (!tap_shifted_if_needed(KC_COLON, &scln_fun_used, &scln_fun_tap_sent)) {
                    enable_scln_fun_layer();
                }
            } else {
                disable_scln_fun_layer();
                if (is_tap_uninterrupted(scln_fun_used, scln_fun_tap_sent, scln_fun_timer, TAPPING_TERM)) {
                    tap_code(KC_SCLN);
                }
                scln_fun_pressed = false;
                scln_fun_used = false;
                scln_fun_tap_sent = false;
            }
            return false;

        default:
            break;
    }

    return true;  // Continue normal processing for other keys
}

void matrix_scan_user(void) {
    if (lopt_tab_tap_pending && timer_elapsed(lopt_tab_tap_timer) >= LOPT_TAB_DEFER_TERM) {
        send_lopt_tab_tap();
    }

    if (slsh_sft_pressed && !slsh_sft_used && !slsh_sft_tap_sent && !slsh_sft_shift_registered && timer_elapsed(slsh_sft_timer) >= TAPPING_TERM) {
        register_slsh_sft_shift();
    }
}
