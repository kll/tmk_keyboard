#include <util/delay.h>
#include "action_layer.h"
#include "action_util.h"
#include "bootloader.h"
#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // layer 0 : default
        // left hand
        BSLS,    1,    2,    3,    4,    5,  ESC,
         TAB,    Q,    W,    E,    R,    T,  FN1,
         EQL,    A,    S,    D,    F,    G,
        LSFT,    Z,    X,    C,    V,    B,  FN0,
         FN6,  FN7,  FN8,  FN9, FN10,
                                      HOME,  END,
                                            PGUP,
                                 FN4,  FN5, PGDN,
        // right hand
         FN2,    6,    7,    8,    9,    0, MINS,
        LBRC,    Y,    U,    I,    O,    P, RBRC,
                 H,    J,    K,    L, SCLN, QUOT,
         FN0,    N,    M, COMM,  DOT, SLSH, RSFT,
                    LEFT, DOWN,   UP, RGHT,GRAVE,
        LGUI,  APP,
        PSCR,
         INS,  ENT, SPC
    ),

    KEYMAP(  // layer 1 : function and symbol keys
        // left hand
        TRNS,   F1,   F2,   F3,   F4,   F5,  F11,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  FN3,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        LCTL, LGUI, LALT, RALT, RCTL,
                                      TRNS, TRNS,
                                            TRNS,
                                TRNS, TRNS, TRNS,
        // right hand
             F12, F6,  F7,  F8,  F9,  F10, TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // layer 2 : keyboard functions
        // left hand
        BTLD,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // layer 3: numpad
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,NLCK,PSLS,PAST,PAST,PMNS,BSPC,
             TRNS,NO,  P7,  P8,  P9,  PMNS,BSPC,
                  NO,  P4,  P5,  P6,  PPLS,PENT,
             TRNS,NO,  P1,  P2,  P3,  PPLS,PENT,
                       P0,  PDOT,SLSH,PENT,PENT,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
};
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_TOGGLE(1),                     // FN0  - to Layer1
    [1] = ACTION_LAYER_TAP_TOGGLE(2),                     // FN1  - to Layer2
    [2] = ACTION_LAYER_TOGGLE(3),                         // FN2  - toggle Layer3 aka Numpad layer
    [3] = ACTION_LAYER_SET(0, ON_PRESS),                  // FN3  - set Layer0
    [4] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_BSPC),         // FN4  - left alt or tap backspace
    [5] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_DEL),          // FN5  - left control or tap delete
    [6] = ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_F4),    // FN6  - close current virtual desktop
    [7] = ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_D),     // FN7  - create new virtual desktop
    [8] = ACTION_MODS_KEY(MOD_LGUI, KC_TAB),              // FN8  - enter task view
    [9] = ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_LEFT),  // FN9  - Switch virtual desktop left
    [10] = ACTION_MODS_KEY(MOD_LCTL | MOD_LGUI, KC_RGHT),  // FN10 - Switch virtual desktop right
};