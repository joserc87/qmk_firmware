#include "dactyl-manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN   1
#define _WM   2

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP_5x6(
  // left hand
   KC_ESC,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5, 
   KC_GRV,    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,
   KC_TAB,    KC_A,    KC_S,    KC_D,   KC_F,   KC_G,
   KC_LSHIFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
                       KC_TAB,  KC_BSLS,
                               LT(_FN, KC_ENTER), KC_LSFT, 
                               KC_SPC,   KC_RGUI,
                               KC_DEL, KC_LALT,
        // right hand
                     KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
                     KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_EQL,
                     KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
                     KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSHIFT,
                                      KC_LBRC, KC_RBRC,
        KC_SPC, CTL_T(KC_BSPC), 
        ALT_T(KC_ESC), GUI_T(KC_ESC),
        KC_LALT, KC_LGUI),
[_FN] = KEYMAP_5x6(
  // left hand
   _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5, 
   _______,  _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,
   _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDN,
   RESET,    _______,  _______,  _______,  _______,  _______,
                       _______,  _______, 
                               LT(_FN, KC_DEL), KC_LSFT, 
                               KC_SPC,   KC_LCTRL,
                               KC_ENTER, KC_LALT,
        // right hand
                     KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,  KC_F11,
                     KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   _______,  KC_F12,
                     KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______, _______,
                     KC_CALC,  KC_MAIL,  KC_MYCM,  KC_WHOM,  _______,   RESET,
                                         _______,  _______,
        KC_SPC, LT(_FN, KC_BSPC), 
        CTL_T(KC_PGUP), KC_PGDN,
        KC_LALT, KC_LGUI),
[_WM] = KEYMAP_5x6(
  // left hand
   KC_ESC,    LGUI(KC_1),    LGUI(KC_2),    LGUI(KC_3),   LGUI(KC_4),   LGUI(KC_5), 
   KC_GRV,    LGUI(KC_Q),    LGUI(KC_W),    LGUI(KC_E),   LGUI(KC_R),   LGUI(KC_T),
   KC_TAB,    LGUI(KC_A),    LGUI(KC_S),    LGUI(KC_D),   LGUI(KC_F),   LGUI(KC_G),
   KC_LSHIFT, LGUI(KC_Z),    LGUI(KC_X),    LGUI(KC_C),   LGUI(KC_V),   LGUI(KC_B),
                       KC_TAB,  KC_BSLS,
                               LGUI(KC_ENTER), KC_LSFT, 
                               KC_SPC,   KC_RGUI,
                               KC_DEL, KC_LALT,
        // right hand
                     LGUI(KC_6),    LGUI(KC_7),   LGUI(KC_8),    LGUI(KC_9),    LGUI(KC_0),    LGUI(KC_MINS),
                     LGUI(KC_Y),    LGUI(KC_U),   LGUI(KC_I),    LGUI(KC_O),    LGUI(KC_P),    LGUI(KC_EQL),
                     LGUI(KC_H),    LGUI(KC_J),   LGUI(KC_K),    LGUI(KC_L),    LGUI(KC_SCLN), LGUI(KC_QUOT), 
                     LGUI(KC_N),    LGUI(KC_M),   LGUI(KC_COMM), LGUI(KC_DOT),  LGUI(KC_SLSH), KC_RSHIFT,
                                      KC_LBRC, KC_RBRC,
        CTL_T(KC_SPC), LT(_WM, KC_BSPC), 
        ALT_T(KC_ESC), GUI_T(KC_ESC),
        KC_LALT, KC_LGUI),
};



void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
