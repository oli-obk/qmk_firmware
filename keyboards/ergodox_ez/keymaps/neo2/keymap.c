#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_german.h"

// Layer names
#define BASE 0 // default layer
#define SYMB 1 // symbol layer
#define MOVE 2 // movement keys
#define ACT 3 // advanced movement keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,---------------------------------------------------.           ,---------------------------------------------------.
 * |  ESC   |   Ü  |   Ö  |   Ä  |      |      |CtrlAlt|           |Alt+F4|      |      |      |      | Print |         |
 * |--------+------+------+------+------+--------------|           |------+------+------+------+------+-------+---------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |       |           |      |   Z  |   U  |   I  |   O  |   P   |   ß     |
 * |--------+------+------+------+------+------|       |           |      |------+------+------+------+-------+---------|
 * |  L2    |   A  |   S  |   D  |   F  |   G  |-------|           |------|   H  |   J  |   K  |   L  |   @   |    L2   |
 * |--------+------+------+------+------+------| Paste |           |      |------+------+------+------+-------+---------|
 * | LShift |   Y  |   X  |   C  |   V  |   B  |       |           |      |   N  |   M  |   ,  |   .  |   €   | RShift  |
 * `--------+------+------+------+------+--------------'           `-------------+------+------+------+-------+---------'
 *   | Ctrl | Alt  |  L3  |      |  L4  |                                        |  L4  |      |  L3  |Ctl+Tab| Alt+Tab |
 *   `----------------------------------'                                        `--------------------------------------'
 *                                        ,-------------.        ,---------------.
 *                                        | Cut  | Copy |        | Undo |  Redo  |
 *                                 ,------+------+------|        |------+--------+------.
 *                                 |      |      |      |        |      |        |      |
 *                                 |      |      |------|        |------|        |      |
 *                                 |Space |      |      |        |      |        | Space|
 *                                 `--------------------'        `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,          DE_UE,          DE_OE,    DE_AE,    KC_NO,    KC_NO,   LCTL(KC_LALT),
        KC_TAB,          DE_Q,           DE_W,     DE_E,     DE_R,     DE_T,    KC_NO,
        MO(1),           DE_A,           DE_S,     DE_D,     DE_F,     DE_G,
        KC_LSFT,         DE_Y,           DE_X,     DE_C,     DE_V,     DE_B,    LCTL(KC_V),
        KC_LCTL,         KC_LALT,        MO(3),    KC_NO,    MO(2),
                                               LCTL(DE_X), LCTL(DE_C),
                                                              KC_NO,
                                               KC_SPC, KC_NO, KC_NO,
        // right hand
        LALT(KC_F4),       KC_NO,  KC_NO,   KC_NO,   KC_NO,  KC_PSCR,          KC_NO,
        KC_NO,       DE_Z,   DE_U,    DE_I,    DE_O,   DE_P,             DE_SS,
                     DE_H,   DE_J,    DE_K,    DE_L,   DE_AT,            MO(1),
        KC_NO,       DE_N,   DE_M,    DE_COMM, DE_DOT, DE_EURO,             KC_RSFT,
                             MO(2)  , KC_NO  , MO(3),  LCTL(KC_TAB),          LALT(KC_TAB),
        LCTL(DE_Z), LCTL(DE_Y),
        KC_NO,
        KC_NO, KC_NO, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   _  |   [  |   ]  |   ^  |      |           |      |   !  |   <  |   >  |   =  |   &  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   \  |   /  |   {  |   }  |   *  |------|           |------|   ?  |   (  |   )  |   -  |   :  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   |  |   ~  |      |      |           |      |   +  |   %  |   "  |   '  |   ;  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |  ´   |      |      |       |      |      |   `  |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
       KC_NO,  KC_NO,  DE_UNDS,DE_LBRC,DE_RBRC,DE_CIRC,KC_NO,
       KC_TRNS,DE_BSLS,DE_SLSH,DE_LCBR,DE_RCBR,DE_ASTR,
       KC_NO,  DE_HASH,DE_DLR ,DE_PIPE,DE_TILD,KC_NO,KC_NO,
       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                                       KC_NO,KC_NO,
                                             KC_NO,
                                 KC_FN7,KC_NO,KC_NO,
       // right hand
       KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   DE_EXLM, DE_LESS,DE_MORE, DE_EQL,  DE_AMPR, KC_NO,
                DE_QST,  DE_LPRN,DE_RPRN, DE_MINS, DE_COLN, KC_TRNS,
       KC_NO,   DE_PLUS, DE_PERC,DE_DQOT, DE_QUOT, DE_SCLN, KC_NO,
                         KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO, KC_NO,
       KC_NO,
       KC_NO, KC_NO, KC_FN6
),
/* Keymap 2: Control and Movement
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | PgUp | Back |  Up  | Del  | PgDn |      |           |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home | Left | Down | Rght | End  |------|           |------|      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      | Ret  |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |   0  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MOVE] = LAYOUT_ergodox(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO    , KC_NO  , KC_NO,
       KC_NO  , KC_PGUP, KC_BSPC, KC_UP  , KC_DELETE, KC_PGDN, KC_NO,
       KC_NO  , KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT   , KC_END,
       KC_NO  , KC_NO  , KC_NO  , KC_NO , KC_ENT  , KC_NO  , KC_NO,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS    ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_NO, KC_NO  , KC_NO  ,
    // right hand
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO ,
       KC_NO  , KC_NO  , KC_7   , KC_8   , KC_9   , KC_NO  , KC_NO,
                KC_NO  , KC_4   , KC_5   , KC_6   , KC_NO  , KC_NO,
       KC_NO  , KC_NO  , KC_1   , KC_2   , KC_3   , KC_NO  , KC_NO,
                         KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,
       KC_NO, KC_NO,
       KC_NO,
       KC_NO, KC_NO, KC_0
),
/* Keymap 3: Word/Line Operations
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |  F10 |  F11 |  F12 |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Back | Del  | Del  |      |      |           |      |      |  F7  |  F8  |  F9  |      |        |
 * |        |      | Word | Start| Word |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Page | Skip | Del  | Skip | Page |------|           |------|      |  F4  |  F5  |  F6  |      |        |
 * |        | Home | Left | End  | Rght | End  |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  F1  |  F2  |  F3  |      |        |
 * `--------+------+------+------+------+-------KC_FN4------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ACT] = LAYOUT_ergodox(
       KC_NO  , KC_NO,         KC_NO  ,       KC_NO        , KC_NO          , KC_NO  , KC_NO,
       KC_NO  , KC_NO,         LCTL(KC_BSPC), KC_FN4       , LCTL(KC_DELETE), KC_NO, KC_NO,
       KC_NO  , LCTL(KC_HOME), LCTL(KC_LEFT), KC_FN5       , LCTL(KC_RGHT), LCTL(KC_END),
       KC_NO  , KC_NO  ,       KC_NO  ,       KC_NO        , KC_NO          , KC_NO  , KC_NO,
       KC_NO  , KC_NO  ,       KC_TRNS  ,       KC_NO        , KC_NO          ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_NO, KC_NO  , KC_NO  ,
    // right hand
       KC_NO  , KC_NO  , KC_F10 , KC_F11  , KC_F12 , KC_NO  , KC_NO ,
       KC_NO  , KC_NO  , KC_F7  , KC_F8  , KC_F9  , KC_NO  , KC_NO,
                KC_NO  , KC_F4  , KC_F5  , KC_F6  , KC_NO  , KC_NO,
       KC_NO  , KC_NO  , KC_F1  , KC_F2  , KC_F3  , KC_NO  , KC_NO,
                         KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO,
       KC_NO, KC_NO,
       KC_NO,
       KC_NO, KC_NO, KC_NO
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(SYMB),  // Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_MOMENTARY(MOVE),  // Momentary Layer 2 (Movement)
    [3] = ACTION_LAYER_MOMENTARY(ACT),   // Momentary Layer 3 (Actions)
    [4] = ACTION_MACRO(0),                // Delete to start of line
    [5] = ACTION_MACRO(1),                // delete to end of line
    [6] = ACTION_MACRO(2),                // `
    [7] = ACTION_MACRO(3),                // ´
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case 0:
            return MACRODOWN( D(LSHIFT), T(HOME) , U(LSHIFT), D(LCTL), T(X), U(LCTL), END );
        case 1:
            return MACRODOWN( D(LSHIFT), T(END) , U(LSHIFT), D(LCTL), T(X), U(LCTL), END );
        case 2:
            return MACRODOWN( D(LSHIFT), T(EQL), T(EQL), U(LSHIFT), END);
        case 3:
            return MACRODOWN( T(EQL), T(EQL), END);
        default:
            return MACRO_NONE;
    }
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.action_get_macro
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case MOVE:
            ergodox_right_led_2_on();
            break;
        case ACT:
            ergodox_right_led_3_on();
            break;
        default:
            ergodox_board_led_off();
            break;
    }

};
