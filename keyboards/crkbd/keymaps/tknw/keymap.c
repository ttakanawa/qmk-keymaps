#include QMK_KEYBOARD_H

// Define NA for unused keys
#define NA XXXXXXX

// Layers
enum layers {
    BASE,
    NAV,
    NUM,
    FUN,
    MOUSE,
    MISC
};

// Custom keycodes
enum custom_keycodes {
    LCBR_MISC = SAFE_RANGE
};

// Tap Dance declarations
enum {
    Q_NAV_ESC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      NA, TD(Q_NAV_ESC),   KC_W,    KC_E,    KC_R,    KC_T,  KC_TAB,         NA,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           NA,    KC_A,    KC_S,    KC_D,   KC_F,     KC_G, KC_LSFT,         NA,    KC_H,    KC_J,    KC_K,   KC_L,LT(FUN,KC_SCLN),NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, SFT_T(KC_Z),KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,SFT_T(KC_SLSH),NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                               OPT_T(KC_TAB),LCTL_T(KC_LNG2),KC_LCMD,SFT_T(KC_ENT),KC_SPC,LT(NUM, KC_LNG1)
                                      //`--------------------------'  `--------------------------'
  ),

  // Cursor navigation and window controls
  [NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA, _______, LCBR_MISC, KC_UP,G(KC_RCBR),KC_PGUP,_______,         NA,      NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
     NA,LT(MOUSE, KC_VOLU),KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN,_______,         NA,      NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_VOLD,      NA,  KC_SPC,  KC_ENT,G(KC_GRV),                          NA,      NA,      NA,      NA, KC_RSFT,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // Number and Symbols
  [NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,         NA,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_LPRN, KC_CIRC,      NA,  KC_DLR, KC_RPRN, _______,         NA, KC_BSPC, KC_MINS,  KC_EQL,  KC_GRV, KC_QUOT,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_LSFT, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,                      KC_LBRC, KC_RBRC, _______,_______,SFT_T(KC_BSLS), NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // Function keys
  [FUN] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,         NA,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15, _______,         NA,  KC_F16,  KC_F17,  KC_F18,  KC_F19, _______,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA,      NA,      NA,      NA,      NA,      NA,                      RM_TOGG, QK_BOOT,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // Mouse keys
  [MOUSE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA, _______,      NA,   MS_UP,      NA, MS_WHLD, _______,         NA,      NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           NA, _______, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLU, _______,         NA, MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, QK_BOOT, MS_WHLR,      NA, MS_WHLL,      NA,                           NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, MS_BTN2, MS_BTN1,    MS_BTN1, MS_BTN2, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // Miscellaneous
  [MISC] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA,      NA,      NA, G(KC_1), G(KC_2), G(KC_3),HYPR(KC_0),       NA,      NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       NA,LSG(KC_4),LSG(KC_5),LCSG(KC_4), G(KC_8), G(KC_9),HYPR(KC_9),       NA,      NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
 NA,HYPR(KC_8),HYPR(KC_7),HYPR(KC_6),HYPR(KC_5),HYPR(KC_4),                           NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                   HYPR(KC_3),HYPR(KC_2),HYPR(KC_1),    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

// Tap Dance definitions
static void q_nav_finished(tap_dance_state_t *state, void *user_data) {
    (void)user_data;

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

static void q_nav_reset(tap_dance_state_t *state, void *user_data) {
    (void)user_data;

    if (state->count == 1) {
        layer_off(NAV);  // Release: disable NAV
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [Q_NAV_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_nav_finished, q_nav_reset)
};

// Custom Left Brace/Miscellaneous layer key state tracking
static bool lcbr_misc_used = false;
static uint16_t lcbr_misc_timer = 0;

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    (void)record;

    switch (keycode) {
        case SFT_T(KC_ENT):
        case LT(MOUSE, KC_VOLU):
            return 400;
        case TD(Q_NAV_ESC):
        case SFT_T(KC_SLSH):
            return 200;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    (void)record;

    return keycode != SFT_T(KC_Z);
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                      uint16_t other_keycode, keyrecord_t *other_record) {
    (void)other_keycode;

    if (tap_hold_keycode == SFT_T(KC_Z)) {
        return get_chordal_hold_default(tap_hold_record, other_record);
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == LCBR_MISC) {
        if (record->event.pressed) {
            lcbr_misc_used = false;
            lcbr_misc_timer = timer_read();
            layer_on(MISC);
        } else {
            layer_off(MISC);
            if (!lcbr_misc_used && timer_elapsed(lcbr_misc_timer) < TAPPING_TERM) {
                tap_code16(G(KC_LCBR));
            }
        }
        return false;
    }

    if (record->event.pressed && IS_LAYER_ON(MISC) && !IS_MODIFIER_KEYCODE(keycode)) {
        lcbr_misc_used = true;
    }

    return true;
}
