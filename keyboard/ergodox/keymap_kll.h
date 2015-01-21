static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // layer 0 : default
        // left hand
        BSLS, 1,   2,   3,   4,   5,   ESC,
        TAB,  Q,   W,   E,   R,   T,   FN2,
        EQL,  A,   S,   D,   F,   G,
        LSFT, Z,   X,   C,   V,   B,   FN1,
        FN5,FN6,FN7,FN8,FN9,
                                      FN10,FN11,
                                           FN12,
                                 BSPC,DEL, FN13,
        // right hand
             FN3, 6,   7,   8,   9,   0,   MINS,
             LBRC,Y,   U,   I,   O,   P,   RBRC,
                  H,   J,   K,   L,   SCLN,QUOT,
             FN1, N,   M,   COMM,DOT, SLSH,RSFT,
                       LEFT,DOWN,UP,  RGHT,GRAVE,
        LGUI,APP,
        PSCR,
        INS,ENT, SPC
    ),

    KEYMAP(  // layer 1 : function and symbol keys
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F11,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN4,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
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
        FN0, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
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
             SLCK,NLCK,PSLS,PAST,PAST,PMNS,BSPC,
             TRNS,NO,  P7,  P8,  P9,  PMNS,BSPC,
                  NO,  P4,  P5,  P6,  PPLS,PENT,
             TRNS,NO,  P1,  P2,  P3,  PPLS,PENT,
                       P0,  PDOT,SLSH,PENT,PENT,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [0] =   ACTION_FUNCTION(TEENSY_KEY),                // FN0 - Teensy key

    [1] =   ACTION_LAYER_MOMENTARY(1),                  // FN1 - switch to Layer1
    [2] =   ACTION_LAYER_SET(2, ON_PRESS),              // FN2 - push Layer2
    [3] =   ACTION_LAYER_SET(3, ON_PRESS),              // FN3 - push Layer3
    [4] =   ACTION_LAYER_SET(0, ON_PRESS),              // FN4 - push Layer0

    [5] =   ACTION_MODS_KEY(MOD_LCTL, KC_X),            // FN5 - cut
    [6] =   ACTION_MODS_KEY(MOD_LCTL, KC_C),            // FN6 - copy
    [7] =   ACTION_MODS_KEY(MOD_LCTL, KC_V),            // FN7 - paste
    [8] =   ACTION_MODS_KEY(MOD_LCTL, KC_Z),            // FN8 - undo
    [9] =   ACTION_MODS_KEY(MOD_LCTL, KC_S),            // FN9 - save

    [10] =  ACTION_MODS_TAP_KEY(MOD_LCTL, KC_HOME),     // FN10 = LCtrl with tap Home
    [11] =  ACTION_MODS_TAP_KEY(MOD_LALT, KC_END),      // FN11 = LAlt with tap End
    [12] =  ACTION_MODS_TAP_KEY(MOD_LCTL, KC_PGUP),     // FN12 = LCtrl with tap PageUp
    [13] =  ACTION_MODS_TAP_KEY(MOD_LALT, KC_PGDOWN),   // FN13 = LAlt with tap PageDown
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}
