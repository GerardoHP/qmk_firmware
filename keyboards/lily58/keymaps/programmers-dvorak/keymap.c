#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
    { KC_DLR,       KC_GRV },
    { KC_PLUS,      KC_1 },
    { KC_LBRACKET,  KC_2 },
    { KC_LCBR,      KC_3 },
    { KC_LPRN,      KC_4 },
    { KC_AMPR,      KC_5 },
    { KC_EQUAL,     KC_6 },
    { KC_RPRN,      KC_7 },
    { KC_RCBR,      KC_8 },
    { KC_RBRACKET,  KC_9 },
    { KC_ASTR,      KC_0 },
    { KC_EXLM,      KC_PERCENT },
    { KC_PIPE,      KC_GRAVE },
    { KC_AT,        KC_CIRCUMFLEX },
    { KC_BSLASH,    KC_HASH },
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys)/sizeof(custom_shift_key_t);

enum layer_number {
  _DVORAK = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   ;  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   '  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP|   \  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_DVORAK] = LAYOUT(
    KC_ESC,     _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
    KC_TAB,     KC_SCOLON,  KC_COMMA,   KC_DOT,     KC_P,       KC_Y,                               KC_F,       KC_G,       KC_C,       KC_R,       KC_L,       KC_SLASH,
    KC_LCTRL,   KC_A,       KC_O,       KC_E,       KC_U,       KC_I,                               KC_D,       KC_H,       KC_T,       KC_N,       KC_S,       KC_MINUS,
    KC_LSHIFT,  KC_QUOTE,   KC_Q,       KC_J,       KC_K,       KC_X,       _______,    _______,    KC_B,       KC_M,       KC_W,       KC_V,       KC_Z,       KC_RSHIFT,
                                        KC_LALT,    KC_LGUI,    MO(_LOWER), KC_SPC,     KC_ENT,     MO(_RAISE), KC_BSPC,    KC_BSLASH
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   $  |  +   |  [   |  {   |   (  |  &   |                    |   =  |   )  |  }   |   ]  |   *  |   !  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |   |  |   @  |   \  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F2  |  F3  |  F4  |  F5  |  F6  |-------|    |-------|  F7  |  F8  |  F9  | F10  | F11  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |  F1  |      |      | /       /       \      \  |      |      | F12  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______,    _______,        _______,    _______,    _______,                            _______,    _______,    _______,    _______,        _______,    _______,
  KC_DLR,  KC_PLUS,    KC_LBRACKET,    KC_LCBR,    KC_LPRN,    KC_AMPR,                            KC_EQUAL,   KC_RPRN,    KC_RCBR,    KC_RBRACKET,    KC_ASTR,    KC_EXLM,
  _______, _______,    _______,        _______,    _______,    _______,                            _______,    _______,    _______,    KC_PIPE,        KC_AT,      KC_BSLASH,
  _______, KC_F2,      KC_F3,          KC_F4,      KC_F5,      KC_F6,      _______,    _______,    KC_F7,      KC_F8,      KC_F9,      KC_F10,         KC_F11,     _______,
                                       KC_F1,      _______,    _______,    _______,    _______,    _______,    _______,    KC_F12
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   1  |   2  |   3  |   0  |                    |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   4  |   5  |   6  |      |-------.    ,-------|      | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|       |    |      |------+------+------+------+------+------|
 * |      |      |   7  |   8  |   9  |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______,    _______,    _______,    _______,    _______,                                    _______,            _______,                _______,                _______,                _______,    _______,
  _______, _______,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_KP_0,                                    _______,            _______,                KC_UP,                  _______,                KC_HOME,    KC_PGUP,
  _______, _______,    KC_KP_4,    KC_KP_5,    KC_KP_6,    _______,                                    _______,            KC_LEFT,                KC_DOWN,                KC_RIGHT,               KC_END,     KC_PGDOWN,
  _______, _______,    KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_AUDIO_VOL_DOWN,  _______,    _______,    KC_AUDIO_VOL_UP,    KC_MEDIA_PREV_TRACK,    KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,    _______,    _______,
                                   _______,    _______,    _______,            _______,    _______,    KC_NO,              _______,                _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RESET,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
    }

    return true;
}
