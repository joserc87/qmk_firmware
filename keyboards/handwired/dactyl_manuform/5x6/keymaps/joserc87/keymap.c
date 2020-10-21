/* A Swedish XMonad layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum dactyl_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
};

#define RAISE  MO(_RAISE)
#define LOWER  MO(_LOWER)
#define RENTER LT(_RAISE,KC_ENTER)
#define CSPACE CTL_T(KC_BSPC)
#define ALTESC ALT_T(KC_ESC)
#define TERM   LGUI(LSFT(KC_ENT))
#define ALTTAB LGUI(KC_TAB)
#define KILL   LGUI(LSFT(KC_C))
#define OPEN   LGUI(KC_P)
#define KC_QSM LSFT(SE_PLUS)
#define KC_AA  SE_AA
#define KC_AE  SE_AE
#define KC_OE  SE_OSLH

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------,                             ,-----------------------------------------,
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                             |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |   `  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |   =  |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |   '  |
 * |------+------+------+------+------+------|                             |------|------+------+------+------+------|
 * | SHIFT|   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |SHIFT |
 * `------+------+------+------+-------------,                             `-------------+------+------+------+------,
 *               | TAB  |   \  |                                                         |   [  |   ]  |
 *               '------+------'------+------'                             '-------------'------+------'
 *                             | ENTER| SHFIT|                             | SPACE| BSPC |
 *                             |   +  |      |                             |      |   +  |
 *                             | RAISE|      |                             |      | CTRL |
 *                             '------+------'                             '------+------'
 *                                           '______+------' '------+______'
 *                                           | SPACE| GUI  | | ALT  |M-ESC |
 *                                           |______+------' '------+______|
 *                                           | DEL  | ALT  | | GUI  | GUI  |
 *                                           |______+------' '------+______|
 */
  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
     KC_GRV , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_EQL  ,
     KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                        KC_H   , KC_J   , KC_K   , KC_L   , KC_OE  , KC_QUOT  ,
     KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                        KC_N   , KC_M   , KC_COMM, KC_DOT , SE_SLSH, KC_RSHIFT,
                       KC_TAB , KC_BSLS ,                                                           KC_LBRC, KC_RBRC ,
                                                  RENTER , KC_LSFT,      KC_SPC , CSPACE ,
                                                  KC_SPC , KC_RGUI,      ALTESC , KC_RGUI,
                                                  KC_DEL , KC_LALT,      KC_LALT, KC_LGUI
  ),

  [_LOWER] = LAYOUT_5x6(
     SE_TILD, KC_EXLM,  SE_AT , KC_HASH, SE_DLR , KC_PERC,                        SE_CIRC, SE_AMPR, SE_ASTR, SE_SLSH, SE_LPRN, SE_RPRN,
     SE_ACUT, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, SE_LCBR, SE_RCBR,
     _______, _______, _______, _______, _______, _______,                        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, SE_LBRC, SE_RBRC,
     _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, SE_LESS, SE_GRTR,
                       _______, _______,                                                            _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______

  ),

/* RAISE:
 * ,-----------------------------------------,                             ,-----------------------------------------,
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |                             |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      |      | HOME |  UP  |  END | PGUP |                             |      |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      |      | LEFT | DOWN |RIGHT | PGDN |                             |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|                             |------|------+------+------+------+------|
 * | RESET|      |      |      |      |      |                             |      |   1  |   2  |   3  |      |Lower |
 * `------+------+------+------+-------------,                             `-------------+------+------+------+------,
 *               |      |      |                                                         |      |      |
 *               '------+------'-------------'                             '-------------'------+------'
 *                             | ENTER| SHFIT|                             | SPACE| BSPC |
 *                             |   +  |      |                             |      |   +  |
 *                             |  FN  |      |                             |      | CTRL |
 *                             '------+------'                             '------+------'
 *                                           '______+------' '------+______'
 *                                           | GUI  | ALT  | | ALT  |M-ESC |
 *                                           |______+------' '------+______|
 *                                           | SPACE| DEL  | | GUI  | GUI  |
 *                                           |______+------' '------+______|
 */

  [_RAISE] = LAYOUT_5x6(
     KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
     _______, _______, KC_HOME, KC_UP  , KC_END , KC_PGUP,                        KC_PGUP, KC_HOME, KC_UP  , KC_END , _______, KC_F12 ,
     _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN,                        KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______,
     _______, _______, _______, _______, _______, _______,                        KC_CALC, KC_MAIL, KC_MYCM, KC_WHOM, _______, RESET  ,
                       _______, _______,                                                            _______, _______, 
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______
  ),
};
