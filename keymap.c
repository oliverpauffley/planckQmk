/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FN,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  FF7
};

// tap dance codes
enum {
	TD_POUND_HASH,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_POUND_HASH] = ACTION_TAP_DANCE_DOUBLE(KC_HASH, KC_NONUS_HASH),
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCL MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,       KC_I,    KC_O,     KC_P,            KC_BSPC,
    CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,       KC_K,    KC_L,  KC_SCLN,             KC_ENT,
    KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,    LSFT_T(KC_QUOT),
    FUNCL,      KC_LCTL, KC_LALT, KC_LGUI,   LOWER,  KC_SPC,  KC_SPC,   RAISE,    KC_LEFT, KC_DOWN,    KC_UP,            KC_RGHT
),

[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM,   KC_AT, TD(TD_POUND_HASH),  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS,    KC_EQL,  KC_DEL,
    _______, _______, KC_LCBR,           KC_LBRC, KC_LPRN, KC_NUBS, KC_QUOT, KC_RPRN, KC_RBRC, KC_RCBR,S(KC_SCLN), _______,
    _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,   KC_PIPE, _______,
    _______, _______, _______,           _______, _______, KC_BSLS, KC_BSLS, _______, _______, _______,   _______, _______ 
),

[_RAISE] = LAYOUT_planck_grid(
    _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,  KC_DEL,
    _______, _______, _______, _______, _______, _______, _______,    KC_4,    KC_5,    KC_6,   KC_PPLS, _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3,   KC_MINS,  KC_EQL,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_0,   KC_DOT,  _______, _______
),

[_FN] = LAYOUT_planck_grid(
    _______,   KC_F1,   KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,      KC_F8,   KC_F9,  KC_F10,        , 
    _______,  KC_F11,  KC_F12,    _______,     FF7, _______, _______, _______,   _______, _______, _______, _______, 
    _______, _______, _______,KC__VOLDOWN, KC_MPRV, KC_MUTE, KC_MPLY, KC_MNXT, KC__VOLUP, _______, _______, _______, 
    _______, _______, _______,    _______, _______, _______, _______, _______,   _______, _______, _______, _______
 ),

[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP,  QWERTY,  _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
  float victory_song[][2] = SONG(VICTORY);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 10;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

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
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FF7:
      if (record->event.pressed) {
        PLAY_SONG(victory_song);
      } else {
      }
      break;
  }
  return true;
};
