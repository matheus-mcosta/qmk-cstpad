/* Copyright 2021 cst
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _RESET,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
       KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, 
		TO(1), KC_BSLS, KC_ASTR, KC_MINS, 
		KC_7, KC_8, KC_9, KC_PLUS, 
		KC_4, KC_5, KC_6, 
		KC_1, KC_2, KC_3, KC_ENT, 
		KC_0, KC_DOT
		),
    
    [_FN] = LAYOUT(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		TO(0), KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_Q, KC_W, KC_E, KC_TRNS, 
		KC_A, KC_S, KC_D, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_SPC, MO(2)
		),
    
    [_RESET] = LAYOUT (
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS)
    

};