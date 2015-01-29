static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // layer 0 : default
        // left hand
        ESC,  1,   2,   3,   4,   5,   BSLS,
        TAB,  Q,   W,   E,   R,   T,   FN2, // to l2
        EQL,  A,   S,   D,   F,   G,
        LSFT, Z,   X,   C,   V,   B,   FN1, // to l1
        FN5,FN6,FN7,FN8,FN9,
                                      FN10,FN11,
                                           FN12,
                                 BSPC,DEL, FN13,
        // right hand
             FN3, 6,   7,   8,   9,   0,   MINS,
             LBRC,Y,   U,   I,   O,   P,   RBRC,
                  H,   J,   K,   L,   SCLN,QUOT,
   /*to l1*/ FN1, N,   M,   COMM,DOT, SLSH,RSFT,
                       LEFT,DOWN,UP,  RGHT,GRAVE,
        LGUI,APP,
        PSCR,
        INS,ENT, SPC
    ),

    KEYMAP(  // layer 1 : command layer
        // left hand
        FN6, F1,  F2,  F3,  F4,  F5,  F11,
        TRNS,TRNS,TRNS,TRNS,FN3,FN1, TRNS,
        TRNS,TRNS,TRNS,FN4, TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN0, // to l0
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12, F6,  F7,  F8,  F9,  F10, TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,LEFT,DOWN,UP,  RGHT,TRNS,
   /*to l0*/ FN0,TRNS,FN5,TRNS,TRNS, FN2,TRNS,
                      TRNS,TRNS,TRNS,TRNS,TRNS,
          TRNS,TRNS,
          TRNS,
          TRNS,TRNS,TRNS
    ),

    KEYMAP(  // layer 2 : mouse + media keys
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, FN2, // to l0
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,WH_L,WH_D,WH_U,WH_R,TRNS,
                  TRNS,MS_L,MS_D,MS_U,MS_R,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       MPRV,VOLU,VOLD,MNXT,MUTE,
        TRNS,TRNS,
        TRNS,
        BTN3,BTN1,BTN2
    ),

    KEYMAP(  // layer 3: numpad + keyboard functions
        // left hand
        FN0,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  // teensy key
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
    COMMAND_R,
    COMMAND_D,
    COMMAND_M,
    COMMAND_ESC
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [0] =   ACTION_FUNCTION(TEENSY_KEY),                // FN0 - Teensy key

    [1] =   ACTION_LAYER_TAP_TOGGLE(1),                 // FN1 - switch to Layer1
    [2] =   ACTION_LAYER_TAP_TOGGLE(2),                 // FN2 - push Layer2
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

static const uint16_t PROGMEM fn_actions_1[] = {
    [0]  = ACTION_LAYER_TAP_TOGGLE(1),                   // FN0 - switch to Layer0
    [1]  = ACTION_MODS_KEY(MOD_LCTL, KC_T),              // FN1 - Ctrl+T
    [2]  = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT, KC_SLSH),// FN2 - Ctrl+Alt+/ (Comment with line comment)
    [3]  = ACTION_FUNCTION(COMMAND_R),
    [4]  = ACTION_FUNCTION(COMMAND_D),
    [5]  = ACTION_FUNCTION(COMMAND_M),
    [6]  = ACTION_FUNCTION(COMMAND_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    /*if (record->event.pressed) print("P"); else print("R");
    printf("%d", record->tap.count);
    if (record->tap.interrupted) print("i");
    print("\n");*/

    static bool refactor_started;

    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    } else if (id == COMMAND_R) {
        if (refactor_started) {
            if (record->event.pressed) {
                register_code(KC_R);
            } else {
                unregister_code(KC_R);
                refactor_started = false;
                print("Refactor rename.\n");
            }
        } else {
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTRL));
                register_code(KC_R);
            } else {
                unregister_code(KC_R);
                unregister_mods(MOD_BIT(KC_LCTRL));
                print("Refactor started.\n");
                refactor_started = true;
            }
        }
    } else if (id == COMMAND_D) {
        if (refactor_started) {
            if (record->event.pressed) {
                register_code(KC_D);
            } else {
                unregister_code(KC_D);
                refactor_started = false;
                print("Refactor safe delete.\n");
            }
        } else {
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTRL));
                register_code(KC_D);
            } else {
                unregister_code(KC_D);
                unregister_mods(MOD_BIT(KC_LCTRL));
            }
        }
    } else if (id == COMMAND_M) {
        if (refactor_started) {
            if (record->event.pressed) {
                register_code(KC_M);
            } else {
                unregister_code(KC_M);
                refactor_started = false;
                print("Refactor extract method.\n");
            }
        }
    } else if (id == COMMAND_ESC) {
        if (refactor_started) {
            if (record->event.pressed) {
                refactor_started = false;
                print("Refactor canceled.\n");
            }
        } else {
            if (record->event.pressed) {
                register_code(KC_ESC);
            } else {
                unregister_code(KC_ESC);
            }
        }
    }
}

#define FN_ACTIONS_SIZE     (sizeof(fn_actions)   / sizeof(fn_actions[0]))
#define FN_ACTIONS_1_SIZE   (sizeof(fn_actions_1) / sizeof(fn_actions_1[0]))

/*
 * translates Fn keycode to action
 * for some layers, use different translation table
 */
action_t keymap_fn_to_action(uint8_t keycode)
{
    uint8_t layer = biton32(layer_state);

    action_t action;
    action.code = ACTION_NO;

    if (layer == 1 && FN_INDEX(keycode) < FN_ACTIONS_1_SIZE) {
        action.code = pgm_read_word(&fn_actions_1[FN_INDEX(keycode)]);
    }

    // by default, use fn_actions from default layer 0
    // this is needed to get mapping for same key, that was used switch to some layer,
    // to have possibility to switch layers back
    if (action.code == ACTION_NO && FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    }

    return action;
}
