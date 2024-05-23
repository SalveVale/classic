#include QMK_KEYBOARD_H

enum custom_keycodes {
  LABEL = SAFE_RANGE,
  CYCLE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // debugging
  //   // If console is enabled, it will print the matrix position and status of each key pressed
  // #ifdef CONSOLE_ENABLE
  //     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
  // #endif 

  switch (keycode) {
  case LABEL:
    if (record->event.pressed) {
      SEND_STRING("fafafa" SS_LSFT("a") SS_DELAY(90) "fff");
    } else {
    }
    break;
  case CYCLE:
    if (record->event.pressed) {
      SEND_STRING("ccccc");
    } else {
    }
    break;
  }
  return true;
};

enum layer_names {
  MN,
  WK,
  W2,
  WL,
  GM,
  GI,
  MI,
  NV,
  FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* MAIN
      * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │            │ 6 │ 7 │ 8 │ 9 │ 0 │ - │
      * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
      * │Tab│ Q │ W │ F │ P │ B │            │ J │ L │ U │ Y │ " │ = │
      * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
      * │NV │ A │ S │ R │ T │ G │   │    │   │ M │ N │ E │ I │ O │ ; │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ D │ V │   │    │   │ K │ H │ , │ . │ Up│ / │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │Ctl│ ` │ SD│Gui│Alt│Spc│FN │    │NV │Ent│Bsp│Del│Lft│Dwn│Rit│
      * └───┴───┴───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┴───┴───┘
      */
    [MN] = LAYOUT_split_5x7( // MAIN
        KC_ESC,  KC_1,    KC_2,       KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,       KC_F,    KC_P,    KC_B,                           KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_EQL,
        OSL(NV), KC_A,    KC_S,       KC_R,    KC_T,    KC_G,   QK_BOOT,        KC_SPC,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
        KC_LSFT, KC_Z,    KC_X,       KC_C,    KC_D,    KC_V,   KC_SPC,        KC_SPC,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
        KC_LCTL, KC_GRV,  LGUI(KC_S), KC_LGUI, KC_LALT, KC_SPC, OSL(FN),       OSL(NV), SC_SENT, KC_BSPC, KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
  
     /* WORK
      * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ 1 │ 2 │ 3 │ M │ Y │            │ 6 │ 7 │ 8 │ 9 │ 0 │ - │
      * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
      * │Tab│ Q │ W │ D │ R │ T │            │ J │ L │ U │ Y │ " │ = │
      * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
      * │W2 │ ST│ S │ E │ F │ G │   │    │   │ M │ N │ E │ I │ O │ ; │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │CYC│ CZ│ X │ C │ V │ SA│ P │    │   │ K │ H │ , │ . │ Up│ / │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │Del│ Z │ SD│Gui│Alt│MID│FN │    │NV │Ent│Bsp│Del│Lft│Dwn│Rit│
      * └───┴───┴───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┴───┴───┘
      */
    [WK] = LAYOUT_split_5x7( // WORK
        KC_ESC,  KC_1,       KC_2,               KC_3,               KC_M,               KC_Y,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,       KC_W,               KC_D,               KC_R,               KC_T,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_EQL,
        OSL(W2), LSFT(KC_T), MT(MOD_LCTL, KC_S), MT(MOD_LSFT, KC_E), MT(MOD_LSFT, KC_F), KC_G,       KC_SPC,        KC_SPC,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
        CYCLE,   LCTL(KC_Z), KC_X,               KC_C,               KC_V,               LSFT(KC_A), KC_P,          KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH, KC_SPC,
        KC_DEL,  KC_Z,       LGUI(KC_S),         KC_LGUI,            KC_LALT,            KC_BTN3,    OSL(FN),       OSL(NV), SC_SENT, KC_BSPC, KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
  
     /* WORK SECONDARY
      * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │            │ 6 │ 7 │ 8 │ 9 │ 0 │ - │
      * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │            │ J │ L │ U │ Y │ " │ = │
      * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
      * │   │ SA│ J │   │ L │ P │ P │    │   │ M │ N │ E │ I │ O │ ; │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │F11│   │   │   │ B │ N │ M │    │   │ K │ H │ , │ . │ UP│ / │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │   │WL │   │   │Del│   │   │    │NV │Ent│Bsp│Del│Lft│Dwn│Rit│
      * └───┴───┴───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┴───┴───┘
      */
    [W2] = LAYOUT_split_5x7( // WORK SECONDARY
        _______,  _______,    _______, _______, _______, _______,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        _______,  _______,    _______, _______, _______, _______,                           KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_EQL,
        _______,  LSFT(KC_A), KC_J,    _______, KC_L,    KC_P,    KC_P,            KC_SPC,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
        KC_F11,   _______,    _______, _______, KC_B,    KC_N,    KC_M,            KC_SPC,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
        _______,  DF(WL),     _______, _______, KC_DEL,  _______, _______,         OSL(NV), SC_SENT, KC_BSPC, KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
  
     /* WORK LABELLING
      * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
      * │WK │   │ E │ T │ R │   │            │ 6 │ 7 │ 8 │ 9 │ 0 │ - │
      * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
      * │   │ V │WHD│ G │WHU│   │            │ J │ L │ U │ Y │ " │ = │
      * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
      * │   │   │ A │ D │ F │   │   │    │   │ M │ N │ E │ I │ O │ ; │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │   │BT1│ E │LAB│ R │   │   │    │   │ K │ H │ , │ . │ UP│ / │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │   │   │ SX│ X │ SA│   │FN │    │NV │Ent│Bsp│Del│Lft│Dwn│Rit│
      * └───┴───┴───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┴───┴───┘
      */
    [WL] = LAYOUT_split_5x7( // WORK LABELLING
        DF(WK),  _______,       KC_E,       KC_T,  KC_R,       _______,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        _______, KC_V,          KC_WH_D,    KC_G,  KC_WH_U,    _______,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_EQL,
        _______, _______,       KC_A,       KC_D,  KC_F,       _______, _______,      KC_SPC,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
        _______, LCTL(KC_BTN1), KC_E,       LABEL, KC_R,       _______, _______,      KC_SPC,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
        _______, _______,       LSFT(KC_X), KC_X,  LSFT(KC_A), KC_SPC,  OSL(FN),      OSL(NV), SC_SENT, KC_BSPC, KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
  
     /* GAME
      * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
      * │ 5 │ESC│ 1 │ 2 │ 3 │ 4 │            │ 6 │ 7 │ 8 │ 9 │ 0 │ - │
      * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
      * │ T │Tab│ Q │ W │ E │ R │            │ Y │ I │ U │ P │ " │ = │
      * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
      * │ G │GI │ A │ S │ D │ F │   │    │   │ H │ J │ K │ L │ ; │ ; │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │ B │SFT│ Z │ X │ C │ V │   │    │   │ M │ N │ , │ . │ Up│ / │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │Ent│Ctl│ SD│Gui│Alt│Spc│FN │    │NV │Ent│Bsp│Del│Lft│Dwn│Rit│
      * └───┴───┴───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┴───┴───┘
      */
    [GM] = LAYOUT_split_5x7( // GAME
        KC_5,    KC_ESC,  KC_1,       KC_2,    KC_3,    KC_4,                           KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_T,    KC_TAB,  KC_Q,       KC_W,    KC_E,    KC_R,                           KC_Y,   KC_I,    KC_U,    KC_P,    KC_QUOT, KC_EQL,
        KC_G,    OSL(GI), KC_A,       KC_S,    KC_D,    KC_F,   KC_SPC,        KC_SPC,  KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_SCLN,
        KC_B,    KC_LSFT, KC_Z,       KC_X,    KC_C,    KC_V,   KC_SPC,        KC_SPC,  KC_M,   KC_N,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
        SC_SENT, KC_LCTL, LGUI(KC_S), KC_LGUI, KC_LALT, KC_SPC, OSL(FN),       OSL(NV), KC_ENT, KC_BSPC, KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
  
     /* GAME MIRROR
      * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
      * │ F5│Esc│ F1│ F2│ F3│ F4│            │ 6 │ 7 │ 8 │ 9 │ 0 │ - │
      * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
      * │ T │Tab│ Y │ I │ U │ P │            │ Y │ I │ U │ P │ " │ = │
      * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
      * │ G │GI │ H │ J │ K │ L │   │    │   │ H │ J │ K │ L │ ; │ ; │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │ B │Sft│ M │ N │ , │ . │   │    │   │ M │ N │ , │ . │ Up│ / │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │Ent│Ctl│ SD│Gui│Alt│LCK│FN │    │NV │Ent│Bsp│Del│Lft│Dwn│Rit│
      * └───┴───┴───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┴───┴───┘
      */
    [GI] = LAYOUT_split_5x7( // GAME MIRROR
        KC_F5,   KC_ESC,  KC_F1,      KC_F2,   KC_F3,   KC_F4,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_T,    KC_TAB,  KC_Y,       KC_I,    KC_U,    KC_P,                           KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_EQL,
        KC_G,    _______, KC_H,       KC_J,    KC_K,    KC_L,    KC_SPC,        KC_SPC,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
        KC_B,    KC_LSFT, KC_M,       KC_N,    KC_COMM, KC_DOT,  KC_SPC,        KC_SPC,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
        SC_SENT, KC_LCTL, LGUI(KC_S), KC_LGUI, KC_LALT, QK_LOCK, OSL(FN),       OSL(NV), SC_SENT, KC_BSPC, KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
  
     /* MAIN MIRROR
      * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ 6 │ 7 │ 8 │ 9 │ 0 │            │ 6 │ 7 │ 8 │ 9 │ 0 │ - │
      * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
      * │ = │ J │ L │ U │ Y │ ' │            │ J │ L │ U │ Y │ " │ = │
      * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
      * │ ; │ M │ N │ E │ I │ O │   │    │   │ M │ N │ E │ I │ O │ ; │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │ / │ K │ H │ , │ . │ Up│   │    │   │ K │ H │ , │ . │ Up│ / │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │F11│F12│   │    │NV │Ent│Bsp│Del│Lft│Dwn│Rit│
      * └───┴───┴───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┴───┴───┘
      */
    [MI] = LAYOUT_split_5x7( // MAIN MIRROR
        KC_ESC,  KC_6,    KC_7,       KC_8,    KC_9,    KC_0,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_EQL,  KC_J,    KC_L,       KC_U,    KC_Y,    KC_QUOT,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_EQL,
        KC_SCLN, KC_M,    KC_N,       KC_E,    KC_I,    KC_O,    KC_SPC,        KC_SPC,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
        KC_SLSH, KC_K,    KC_H,       KC_COMM, KC_DOT,  KC_UP,   KC_SPC,        KC_SPC,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
        _______, _______,  _______, _______,   KC_F11,  KC_F12,  _______,       OSL(NV), SC_SENT, KC_BSPC, KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
  
     /* NAVIGATION
      * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ F1│ F2│ F3│ F4│ F5│            │ F6│ F7│ F8│ F9│F10│F11│
      * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
      * │Cap│ / │ 7 │ 8 │ 9 │ * │            │ CL│ PD│ PU│ CR│ " │F12│
      * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
      * │MN │Hom│ 4 │ 5 │ 6 │END│   │    │   │Lft│Dwn│ Up│Rit│ O │   │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │ ` │ - │ 1 │ 2 │ 3 │ + │   │    │ LC│MsL│MsD│MsU│MsR│ RC│   │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │   │MN │GM │WL │WK │ 0 │MI │    │   │Ent│Bsp│Del│Lft│Dwn│Rit│
      * └───┴───┴───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┴───┴───┘
      */
    [NV] = LAYOUT_split_5x7( // NAVIGATION
        KC_ESC,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,                           KC_F6,         KC_F7,   KC_F8,   KC_F9,          KC_F10,  KC_F11,
        KC_CAPS, KC_PSLS, KC_P7,  KC_P8,  KC_P9,  KC_PAST,                         LCTL(KC_LEFT), KC_PGDN, KC_PGUP, LCTL(KC_RIGHT), KC_QUOT, KC_F12,
        TO(MN),  KC_HOME, KC_P4,  KC_P5,  KC_P6,  KC_END,  KC_SPC,        KC_SPC,  KC_LEFT,       KC_DOWN, KC_UP,   KC_RIGHT,       KC_O,    KC_SPC,
        KC_GRV,  KC_PMNS, KC_P1,  KC_P2,  KC_P3,  KC_PPLS, KC_SPC,        KC_BTN1, KC_MS_L,       KC_MS_D, KC_MS_U, KC_MS_R,        KC_BTN2, KC_SPC,
        _______, _______, DF(GM), DF(WL), DF(WK), KC_P0,   OSL(MI),       _______, SC_SENT,       KC_BSPC, KC_DEL,  KC_LEFT,        KC_DOWN, KC_RIGHT
    ),
  
     /* FUNCTION
      * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │            │ 6 │ 7 │ 8 │ 9 │ 0 │ - │
      * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
      * │Tab│ Q │ W │ F │ P │ B │            │ J │ L │ U │ Y │ " │ = │
      * ├───┼───┼───┼───┼───┼───┼───┐    ┌───┼───┼───┼───┼───┼───┼───┤
      * │Mut│VlD│VlU│Prv│Ply│Nxt│   │    │   │ M │ N │ E │ I │ O │ ; │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │ ` │Lft│Dwn│ Up│Rit│ V │   │    │   │ K │ H │ , │ . │ Up│ / │
      * ├───┼───┼───┼───┼───┼───┼───┤    ├───┼───┼───┼───┼───┼───┼───┤
      * │   │MN │GM │WL │WK │Ent│   │    │NV │Ent│Bsp│Del│Lft│Dwn│Rit│
      * └───┴───┴───┴───┴───┴───┴───┘    └───┴───┴───┴───┴───┴───┴───┘
      */
    [FN] = LAYOUT_split_5x7( // FUNCTION
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,     KC_B,                           KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_EQL,
        KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY,  KC_MNXT, QK_BOOT,        KC_SPC,  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_SCLN,
        KC_GRV,  KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, KC_V,    KC_SPC,        KC_SPC,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
        _______, DF(MN),  DF(GM),  DF(WL),  DF(WK),   SC_SENT, _______,       OSL(NV), SC_SENT, KC_BSPC, KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT
    )
};
