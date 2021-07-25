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



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT_cst(
        KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY,
        TO(1), KC_BSLS, KC_ASTR, KC_MINS,
        KC_7, KC_8, KC_9, KC_PLUS,
        KC_4, KC_5, KC_6,
        KC_1, KC_2, KC_3, KC_ENT,
        KC_0, KC_DOT),

    [1] = LAYOUT_cst(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TO(0), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_Q, KC_W, KC_E, KC_TRNS,
        KC_A, KC_S, KC_D,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_SPC, MO(2)),

    [2] = LAYOUT_cst(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, RESET,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS)

};
/*
#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void)
{
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state))
    {
    case 0:
        oled_write_P(PSTR("Default\n"), false);
        break;
    case 1:
        oled_write_P(PSTR("FN\n"), false);
        break;
    case 2:
        oled_write_P(PSTR("RESET\n"), false);
        break;
    default:
        // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif */
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_90; }


// WPM-responsive animation stuff here
#define IDLE_FRAMES 2
#define IDLE_SPEED 40 // below this wpm value your animation will idle

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 636 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;



void oled_task_user(void) {
        
        oled_set_cursor(0,6);
        oled_write_P(PSTR("CST\n PAD\n"), false);
    oled_write_P(PSTR("-----\n"), false);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("MODE\n"), false);
    oled_write_P(PSTR("\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("FUNC\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("RESET\n"), false);
            break;
    }
}
#endif
