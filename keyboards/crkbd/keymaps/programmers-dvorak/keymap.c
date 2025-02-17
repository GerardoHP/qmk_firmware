/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
    { KC_DLR,       KC_TILD },
    { KC_PLUS,      KC_1 },
    { KC_LBRC,      KC_2 },
    { KC_LCBR,      KC_3 },
    { KC_LPRN,      KC_4 },
    { KC_AMPR,      KC_5 },
    { KC_EQUAL,     KC_6 },
    { KC_RPRN,      KC_7 },
    { KC_RCBR,      KC_8 },
    { KC_RBRC,      KC_9 },
    { KC_ASTR,      KC_0 },
    { KC_EXLM,      KC_PERCENT },
    { KC_PIPE,      KC_GRAVE },
    { KC_AT,        KC_CIRCUMFLEX },
    { KC_BSLS,    KC_HASH },
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys)/sizeof(custom_shift_key_t);

enum crkbd_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NAVIGATION,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define BASE TO(_BASE)
#define NAVIGATION TO(_NAVIGATION)
#define RCTRL MT(MOD_RCTL, KC_CAPS)
#define RSHFT MT(MOD_LSFT, KC_ESC)
#define LSHFT MT(MOD_RSFT, KC_BSPC)
#define MLALT  MT(MOD_RALT, KC_BSPC)
#define SCRC  LGUI(S(KC_3))
#define SCRP  LGUI(S(KC_4))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                   ,-----------------------------------------------------.
      KC_TAB,     KC_SCLN,  KC_COMMA,   KC_DOT,     KC_P,       KC_Y,                              KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       KC_SLASH,
  //|-----------+-----------+-----------+----------+------------+--------|                    |----------+-------------+----------+-----------+----------+--------------|
      RCTRL,      KC_A,     KC_O,      KC_E,       KC_U,     KC_I,                           KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       KC_MINUS,
  //|-----------+-----------+-----------+----------+------------+--------|                    |----------+-------------+----------+-----------+----------+--------------|
      RSHFT,      KC_QUOTE,      KC_Q,      KC_J,       KC_K,     KC_X,                           KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,  LSHFT,
  //|-----------+-----------+-----------+----------+------------+--------+--------|  |--------+----------+-------------+----------+-----------+----------+--------------|
                                          KC_LGUI,    LOWER,      KC_SPACE,                      KC_ENTER,      RAISE,    MLALT
                                      //`-----------------------------------------'  `----------------------------------------------'
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_DLR, KC_PLUS, KC_LBRC, KC_LCBR,  KC_LPRN,  KC_AMPR,                       KC_EQUAL,  KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_ASTR,  KC_EXLM,
  //|--------+--------+------------+---------+---------+---------|                    |----------+---------+---------+-------------+---------+---------|
      _______, _______,    _______,  SCRC,  SCRP,  _______,                       _______,   _______,  _______,    KC_PIPE,      KC_AT, KC_BSLS,
  //|--------+--------+------------+---------+---------+---------|                    |----------+---------+---------+-------------+---------+---------|
      _______, _______,    _______,  _______,  _______,  _______,                         _______, _______,    _______,  _______,  _______,  _______,
  //|--------+--------+------------+---------+---------+---------|                    |----------+---------+---------+-------------+---------+---------|
                                          _______ , _______,  _______,   _______ ,ADJUST, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,       KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_INS, _______,   KC_UP, _______, KC_HOME, KC_PGUP,
  //|--------+------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7,       KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                       KC_DEL, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_END,KC_PGDN,
  //|--------+------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,     KC_RSFT, KC_LALT, _______, _______, KC_VOLD,                      KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
  //|--------+------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
                                          _______,   ADJUST, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,NAVIGATION, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAVIGATION] = LAYOUT_split_3x6_3(
  //|--------+--------+---------+--------+--------+--------|                    |--------+------------+-----------+--------------+-------------+--------|
       KC_TAB, KC_PSLS,    KC_P7,   KC_P8,   KC_P9, KC_PAST,                      XXXXXXX, KC_MS_BTN1,  KC_MS_UP,   KC_MS_BTN2,    KC_MS_ACCEL0,    BASE,
  //|--------+--------+---------+--------+--------+--------|                    |--------+------------+-----------+--------------+-------------+--------|
      KC_RCTL, KC_PMNS,    KC_P4,   KC_P5,   KC_P6, KC_PPLS,                      XXXXXXX, KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,   KC_MS_ACCEL1, XXXXXXX,
  //|--------+--------+---------+--------+--------+--------|                    |--------+------------+-----------+--------------+-------------+--------|
      KC_RSFT,   KC_P0,    KC_P1,   KC_P2,   KC_P3, KC_PDOT,                      XXXXXXX, KC_MS_WH_UP, KC_MS_BTN3, KC_MS_WH_DOWN, KC_MS_ACCEL2, LSHFT,
  //|--------+--------+---------+--------+--------+--------+--------|  |--------|--------+------------+-----------+--------------+-------------+--------|
                                          KC_LGUI,KC_MS_BTN1,KC_SPACE,  KC_PENT, KC_MS_BTN2, MLALT
                                      //`--------------------------'  `--------------------------'
  ),
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // set cursor position
        oled_set_cursor(0, 1);

        // caps lock status
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.caps_lock ? PSTR("Caps Lock On \n") : PSTR("Caps Lock Off \n"), false);

        // switch on current active layer
        switch(get_highest_layer(layer_state)) {
            case _BASE:
                oled_write("Base Layer \n", false);
            break;
            case _LOWER:
                oled_write("Lower Layer \n", false);
            break;
            case _RAISE:
                oled_write("Raise Layer \n", false);
            break;
            case _ADJUST:
                oled_write("Adjust Layer \n", false);
            break;
            case _NAVIGATION:
                oled_write("Navigation Layer \n", false);
            break;
        }

        // set the key log
        oled_render_keylog();
    }else {
        oled_render_logo();
    }

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }

    return true;
}

#endif // OLED_ENABLE
