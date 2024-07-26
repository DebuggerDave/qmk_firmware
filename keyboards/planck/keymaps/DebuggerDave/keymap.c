/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _DVORAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   ;  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   "  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | CAPS |Lower |    Space    |Raise |Insert| Alt  |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_ESC,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,  KC_Y,   KC_F,   KC_G,  KC_C,   KC_R,    KC_L,    KC_BSPC,
    KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,  KC_I,   KC_D,   KC_H,  KC_T,   KC_N,    KC_S,    KC_ENT,
    KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,  KC_X,   KC_B,   KC_M,  KC_W,   KC_V,    KC_Z,    KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_CAPS, LOWER, KC_SPC, KC_SPC, RAISE, KC_INS, KC_RALT, KC_RGUI, KC_RCTL
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | None |Lower |    Space    |Raise | None | Alt  |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, LOWER, KC_SPC, KC_SPC, RAISE, XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | DEL  |   &  |  |   |  `   |  ~   | None | None |   /  |   \  |  {   |  }   | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | None |   ^  |  _   |  $   |  %   | None | None |   =  |   *  |  [   |  ]   | None |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | None |  !   |  ?   |  #   |  @   | None | None |  -   |  +   |  (   |  )   | None |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | None |Print | Prev | Next |      |             |      | Vol- | Vol+ | Play | None |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_DEL, KC_AMPR, KC_PIPE, KC_GRV,  KC_TILD, XXXXXXX, XXXXXXX, KC_SLSH, KC_BSLS, KC_LCBR, KC_RCBR, KC_DEL,
    XXXXXXX, KC_CIRC, KC_UNDS, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_EQL,  KC_ASTR, KC_LBRC, KC_RBRC, XXXXXXX,
    XXXXXXX, KC_QUES, KC_EXLM, KC_HASH, KC_AT,   XXXXXXX, XXXXXXX, KC_MINS, KC_PLUS, KC_LPRN, KC_RPRN, XXXXXXX,
    XXXXXXX, KC_PSCR, KC_MPRV, KC_MNXT, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MPLY, XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | None | Home | Pg-  | Pg+  | End  | DEL  | Bksp | Left | Down |  Up  |Right | None |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |  0   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | None | None | None |      |             |      | None | None | None | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,
    XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,  KC_BSPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,
    KC_LSFT, KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,     KC_RSFT,
    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,  _______, XXXXXXX, XXXXXXX, XXXXXXX,  KC_RCTL
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |Sleep |Power |Mus on|Musoff|Voice-|Voice+|MUSmod| None | None | None | None |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | None | None | None | None | None |Aud on|Audoff| None | None | None | None |Dvorak|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | None | None | None | None | None |MIDIon|MIDIof| None | None | None | None |QWERTY|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | None | None | None | None |      |     None    |      | None | None | None | None |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET,   KC_SLEP, KC_PWR,  MU_ON,   MU_OFF,  AU_PREV, AU_NEXT,  MU_NEXT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AU_ON,   AU_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DVORAK,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MI_ON,   MI_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTY,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
