/* A Swedish XMonad layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H
#include "keymap_us_international.h"

enum dactyl_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
};

#define RAISE  MO(_RAISE)
#define LOWER  MO(_LOWER)
#define RENTER LT(_RAISE,KC_ENTER)
#define LTAB   LT(_LOWER, KC_TAB)
#define CORSP  CTL_T(KC_BSPC)
#define ALTESC ALT_T(KC_ESC)
#define TERM   LGUI(LSFT(KC_ENT))
#define ALTTAB LGUI(KC_TAB)
#define KILL   LGUI(LSFT(KC_C))
#define OPEN   LGUI(KC_P)
#define CTAB   LCTL(KC_TAB)
#define CSTAB  LCTL(LSFT(KC_TAB))
#define CTRLA  LCTL(KC_A)
#define CTRLW  LCTL(KC_W)
#define CTRLS  LCTL(KC_S)
#define CTRLZ  LCTL(KC_Z)
#define CTRLX  LCTL(KC_X)
#define CTRLC  LCTL(KC_C)
#define CTRLV  LCTL(KC_V)
#define CTRLR  LCTL(KC_R)
#define CTRLT  LCTL(KC_T)
#define CBSPC  LCTL(KC_BSPC)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// TODO: TAB can be another mode when hold!
// TODO: TAB in the lower part of left kb useless!
// TODO: + and - moved to left?

/* QWERTY
 * ,-----------------------------------------,                             ,-----------------------------------------,
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                             |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |   `  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |   =  |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | LTAB |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |   '  |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHIFT|   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |SHIFT |
 * `------+------+------+------+-------------'                             `-------------+------+------+------+------'
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
     KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS  ,
     KC_GRV , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_EQL   ,
     LTAB   , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT  ,
     KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                        KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSHIFT,
                       KC_TAB , KC_BSLS ,                                                           KC_LBRC, KC_RBRC ,
                                                  RENTER , KC_LSFT,      KC_SPC , CORSP  ,
                                                  KC_SPC , KC_RGUI,      ALTESC , KC_RGUI,
                                                  KC_DEL , KC_LALT,      KC_LALT, KC_LGUI
  ),

/* LOWER:
 * ,-----------------------------------------,                             ,-----------------------------------------,
 * |      |      |      |      |      |      |                             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |      |  !   |   @  |   #  |   $  |   %  |                             |   ^  |   &  |   *  |   (  |   )  |   _  |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |      |  1   |   2  |   3  |   4  |   5  |                             |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                             |      |      |      |      |      | RESET|
 * `------+------+------+------+-------------'                             `-------------+------+------+------+------'
 *               |      |      |                                                         |   ,  |   .  |
 *               '------+------'-------------'                             '-------------'------+------'
 *                             | ENTER| SHFIT|                             | SPACE| C-BS |
 *                             |   +  |      |                             |      |      |
 *                             |  FN  |      |                             |      |      |
 *                             '------+------'                             '------+------'
 *                                           '______+------' '------+______'
 *                                           | GUI  | ALT  | | ALT  |M-ESC |
 *                                           |______+------' '------+______|
 *                                           | SPACE| DEL  | | GUI  | GUI  |
 *                                           |______+------' '------+______|
 */

  [_LOWER] = LAYOUT_5x6(
     _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
     _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                        S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_MINS,
     _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
     _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, RESET  ,
                       _______, _______,                                                            _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______

  ),

/* RAISE:
 * ,-----------------------------------------,                             ,-----------------------------------------,
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |                             |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | CSTAB| C-W  | HOME |  UP  |  END | PGUP |                             |  PU  |   7  |   8  |   9  |      |   _  |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | CTAB | C-A  | LEFT | DOWN |RIGHT | PGDN |                             |   -  |   4  |   5  |   6  |   0  |   +  |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | CSTAB| C-Z  | C-X  | C-C  | C-V  |      |                             |   =  |   1  |   2  |   3  |      |Lower |
 * `------+------+------+------+-------------'                             `-------------+------+------+------+------'
 *               |      |      |                                                         |   ,  |   .  |
 *               '------+------'-------------'                             '-------------'------+------'
 *                             | ENTER| SHFIT|                             | SPACE| C-BS |
 *                             |   +  |      |                             |      |      |
 *                             |  FN  |      |                             |      |      |
 *                             '------+------'                             '------+------'
 *                                           '______+------' '------+______'
 *                                           | GUI  | ALT  | | ALT  |M-ESC |
 *                                           |______+------' '------+______|
 *                                           | SPACE| DEL  | | GUI  | GUI  |
 *                                           |______+------' '------+______|
 */

  [_RAISE] = LAYOUT_5x6(
     KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
     CSTAB  , _______, CTRLW  , KC_UP  , CTRLR  , CTRLT  ,                        KC_PGUP, KC_7   , KC_8   , KC_9   ,        , S(KC_MINS),
     CTAB   , CTRLA  , KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGUP,                        KC_MINS, KC_4   , KC_5   , KC_6   , KC_0   , _______,
     CSTAB  , CTRLZ  , CTRLX  , CTRLC  , CTRLV  , KC_PGDN,                        KC_EQL , KC_1   , KC_2   , KC_3   , _______, _______  ,
                       KC_HOME, KC_END,                                                             KC_0   , KC_DOT ,
                                                  KC_ENTER, KC_LSFT,      LOWER  , CBSPC  ,
                                                  KC_SPC , KC_RGUI,      _______, _______,
                                                  KC_DEL , KC_LALT,      _______, _______
  ),
};
