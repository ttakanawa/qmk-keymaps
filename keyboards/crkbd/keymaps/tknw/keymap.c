#include QMK_KEYBOARD_H

// Define NA for unused keys
#define NA XXXXXXX

// Layers
enum layers { BASE, NAV, NUM, MOUSE, FUN };

// Tap-hold aliases
#define LCBR_FUN LT(FUN, KC_LBRC)
#define HYPR_G1 HYPR_T(KC_1)

// Tap Dance declarations
enum { Q_NAV_ESC };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      NA, TD(Q_NAV_ESC),   KC_W,    KC_E,    KC_R,    KC_T,  KC_TAB,         NA,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           NA,    KC_A,    KC_S,    KC_D,   KC_F,     KC_G,SFT_T(KC_ESC),    NA,    KC_H,    KC_J,    KC_K,   KC_L,LT(FUN,KC_SCLN),NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT,SFT_T(KC_SLSH),NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                               OPT_T(KC_TAB),LCTL_T(KC_LNG2),KC_LCMD,SFT_T(KC_ENT),KC_SPC,LT(NUM, KC_LNG1)
                                      //`--------------------------'  `--------------------------'
  ),

  // Cursor navigation and window controls
  [NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA, MO(NAV), LCBR_FUN,  KC_UP,G(KC_RCBR),KC_PGUP,_______,         NA,      NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
     NA,LT(MOUSE, KC_VOLU),KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN,_______,         NA,      NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_VOLD,      NA,  KC_SPC,  KC_ENT,G(KC_GRV),                          NA,      NA,      NA,      NA,      NA,      NA,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // Number and Symbols
  [NUM] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
           NA, KC_EXLM,   KC_AT, KC_HASH,      NA,  KC_GRV, _______,         NA, KC_COMM,    KC_7,    KC_8,    KC_9, KC_MINS,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_LPRN, KC_CIRC, KC_QUOT,  KC_DLR, KC_RPRN, _______,         NA, KC_BSPC,    KC_4,    KC_5,    KC_6,  KC_EQL,      NA,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
           NA, KC_LBRC, KC_RBRC, KC_BSLS, KC_LCBR, KC_RCBR,                       KC_DOT,    KC_1,    KC_2,    KC_3, SFT_T(KC_0),  NA,
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

  // Function
  [FUN] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------. 
           NA, MO(NAV),LCBR_FUN, HYPR_G1,  G(KC_9),      NA,HYPR(KC_5),       NA,      NA,   KC_F7,   KC_F8,   KC_F9,  KC_F10,      NA,
  //|--------+--------+--------+--------+--------+--------+--------|  `--------+--------+--------+--------+--------+--------+--------| 
           NA,      NA,      NA,HYPR(KC_8),HYPR(KC_7),HYPR(KC_6),HYPR(KC_4), NA, QK_BOOT,   KC_F4,   KC_F5,   KC_F6,  KC_F11,      NA, 
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------| 
           NA,      NA,      NA,LSG(KC_4),LSG(KC_5),LCSG(KC_4),                  RM_TOGG,   KC_F1,   KC_F2,   KC_F3,  KC_F12,      NA, 
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------| 
                                   HYPR(KC_3),HYPR(KC_2),HYPR(KC_1),    _______, _______, _______                                      
                                      //`--------------------------'  `--------------------------'                                     
  )
};

// Tap Dance definitions
static void q_nav_finished(tap_dance_state_t *state, void *user_data) {
    (void)user_data;

    if (state->count == 1 && state->pressed) {
        layer_on(NAV);  // Hold: enable NAV
    } else if (state->count == 1) {
        tap_code(KC_Q);  // Single tap: Q
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    (void)record;

    switch (keycode) {
        case TD(Q_NAV_ESC):
            return 200;
        case LT(MOUSE, KC_VOLU):
            return 400;
        default:
            return TAPPING_TERM;
    }
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Resolve Tap Dance layers before QMK classifies the next tap-hold key.
    if (preprocess_tap_dance(keycode, record)) {
        get_record_keycode(record, true);
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // LT/MT accept only basic tap keycodes, so send the modified taps here.
    if (record->tap.count && (keycode == LCBR_FUN || keycode == HYPR_G1)) {
        if (record->event.pressed) {
            tap_code16(keycode == LCBR_FUN ? G(KC_LCBR) : G(KC_1));
        }
        return false;
    }

    return true;
}
