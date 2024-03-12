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
#include "quantum/keymap_extras/keymap_brazilian_abnt2.h"
#include "quantum/keymap_extras/sendstring_brazilian_abnt2.h"


enum custom_keycodes {
  CAPS_LT = SAFE_RANGE,
  VIM_SEL,
  SFT_ENT,
  TMX_WIN,
  EXCL_FLT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t internal_timer;

  switch (keycode) {

    case TMX_WIN:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DELAY(10) SS_TAP(X_B) SS_UP(X_LCTL) SS_DELAY(10) SS_TAP(X_W));
        return false;
      }
      break;

    case VIM_SEL:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING(SS_TAP(X_ESC));
        SEND_STRING("vap");
        return false;
      }
      break;

    case SFT_ENT:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_ENT) SS_UP(X_LSFT) SS_TAP(X_ESC));
        return false;
      }
      break;

    case EXCL_FLT:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LALT) "s" "f" "1");
        SEND_STRING(SS_DOWN(X_LCTL) "*" SS_UP(X_LCTL));
        SEND_STRING(SS_TAP(X_LALT) "c" "o" "t");
        SEND_STRING(SS_TAP(X_LALT) "k" "s" "r");
        return false;
      }
      break;

    case CAPS_LT:
      if (record->event.pressed) {
        internal_timer = timer_read();
        layer_on(3);
      } else {
        layer_off(3);
        if (timer_elapsed(internal_timer) < TAPPING_TERM) {
          tap_code16(KC_CAPS);
        }
      }
      return false;

  }

    return true;
  };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTL_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, CTL_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CAPS_LT,   MO(1),  KC_ENT,     KC_SPC,   MO(2), ALT_GUI
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTL_ESC, XXXXXXX, XXXXXXX, VIM_SEL, SFT_ENT, TMX_WIN,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  KC_INS, CTL_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,EXCL_FLT,DSK_LEFT, ALT_TAB,DSK_RGHT, C(KC_B),                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_DEL, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_ENT,     KC_SPC, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_LPRN,                      KC_RPRN, KC_AMPR, KC_ASTR, BR_QUES, KC_LCBR, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      CTL_ESC, BR_PERC, BR_BSLS, BR_TILD, KC_UNDS, KC_RBRC,                      KC_BSLS,  KC_EQL, BR_DQUO, BR_SLSH, BR_CIRC, CTL_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, BR_LABK, BR_PIPE, KC_LBRC, KC_MINS, KC_RCBR,                      KC_PIPE, KC_PLUS, BR_QUOT, BR_COLN, BR_RABK, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_ENT,     KC_SPC, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_VOLU, KC_BRIU, XXXXXXX, XXXXXXX, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MUTE, KC_VOLD, KC_BRID, XXXXXXX, XXXXXXX,   MO(4),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_ENT,     KC_SPC, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_ENT,     KC_SPC, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
};
