/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once
#define SPLIT_USB_DETECT
//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS
//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

#undef TAPPING_TERM
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// defining some keycodes for better layout representation
#define ALT_TAB LALT(KC_TAB)
#define ALT_GUI LALT_T(KC_LGUI)
#define GUI_TAB G(KC_TAB)
#define CTL_ESC LCTL_T(KC_ESC)
#define DSK_LEFT G(C(KC_LEFT))
#define DSK_RGHT G(C(KC_RIGHT))
#define CTRL_C C(KC_C)
#define CTRL_V C(KC_V)

// home rows left side
#define HR_GA LGUI_T(KC_A)
#define HR_AS LALT_T(KC_S)
#define HR_CD LCTL_T(KC_D)
#define HR_SF LSFT_T(KC_F)

// home rows right side
#define HR_SJ RSFT_T(KC_J)
#define HR_CK RCTL_T(KC_K)
#define HR_AL LALT_T(KC_L)
#define HR_GSCLN RGUI_T(KC_SCLN)

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
