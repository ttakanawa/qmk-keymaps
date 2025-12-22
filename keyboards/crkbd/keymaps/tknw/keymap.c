#include QMK_KEYBOARD_H

// Tap Dance declarations
enum {
    TD_Q_ESC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
  XXXXXXX,TD(TD_Q_ESC),    KC_W,    KC_E,    KC_R,    KC_T,  KC_TAB,      MO(3),   KC_Y,     KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LSFT,     KC_ENT,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, KC_LCTL, KC_LGUI,    KC_RSFT,  KC_SPC,   MO(1)
                                      //`--------------------------'  `--------------------------'
  ),

  // inspired by https://shop.keyboard.io/pages/the-atreus-layout
  [1] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, KC_EXLM,   KC_AT,   KC_UP,  KC_DLR, KC_PERC, KC_CIRC,    KC_AMPR, KC_ASTR,    KC_7,    KC_8,    KC_9, KC_MINS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LPRN, KC_LEFT, KC_DOWN,KC_RIGHT, KC_RPRN, _______,    QK_BOOT, KC_PGUP,    KC_4,    KC_5,    KC_6,  KC_EQL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LBRC,  KC_RBRC,KC_HASH, KC_LCBR, KC_RCBR,                      KC_PGDN,    KC_1,    KC_2,    KC_3,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  // inspired by https://shop.keyboard.io/pages/the-atreus-layout
  [2] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_HOME,   KC_UP,  KC_END, KC_PGUP,  KC_GRV,    XXXXXXX,   KC_UP,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_VOLU, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN, _______,    XXXXXXX, KC_DOWN,   KC_F4,   KC_F5,    KC_F6, KC_F11, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_VOLD, XXXXXXX,  KC_SPC, XXXXXXX, QK_BOOT,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______,   _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX,C(G(KC_Q)),XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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

tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_finished, q_reset)
};