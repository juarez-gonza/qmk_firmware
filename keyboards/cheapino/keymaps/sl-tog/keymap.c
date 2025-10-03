#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum layers {
  BASE,
  NAV,
  FUN,
  SYM,
  NUM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5_3(
    KC_QUOT, KC_COMM, KC_DOT, KC_P,    KC_Y,     /* ===== */ KC_F,     KC_G,   KC_C, KC_R, KC_L,
    KC_A,    KC_O,    KC_E,   KC_U,    KC_I,     /* ===== */ KC_D,     KC_H,   KC_T, KC_N, KC_S,
    KC_SCLN, KC_Q,    KC_J,   KC_K,    KC_X,     /* ===== */ KC_B,     KC_M,   KC_W, KC_V, KC_Z,
                      KC_NO,  KC_BSPC, OSL(SYM), /* ===== */ OSL(NAV), KC_SPC, KC_NO
  ),
  [NAV] = LAYOUT_split_3x5_3(
    KC_NO, KC_PGUP,  KC_UP,   KC_PGDN, KC_HOME,  /* ===== */ KC_NO,    KC_CAPS,  KC_TAB,  KC_DEL,  KC_NO,
    KC_NO, KC_LEFT,  KC_DOWN, KC_RGHT, KC_END,   /* ===== */ KC_NO,    OS_RSFT,  OS_RCTL, OS_RALT, OS_RGUI,
    KC_NO, OSL(NAV), KC_ESC,  KC_ENT,  KC_NO,    /* ===== */ KC_NO,    OSL(FUN), KC_NO,   KC_NO,   KC_NO,
                     KC_NO,   KC_TRNS, OSL(SYM), /* ===== */ OSL(NAV), KC_TRNS,  KC_NO
        ),
  [FUN] = LAYOUT_split_3x5_3(
    KC_NO, KC_F1,    KC_F2,   KC_F3,   KC_F4,    /* ===== */ KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9,
    KC_NO, KC_MUTE,  KC_VOLD, KC_VOLU, KC_PSCR,  /* ===== */ KC_NO,    OS_RSFT,  OS_RCTL, OS_RALT, OS_RGUI,
    KC_NO, OSL(FUN), KC_BRID, KC_BRIU, KC_NO,    /* ===== */ KC_NO,    OSL(FUN), KC_NO,   KC_NO,   KC_NO,
                     KC_NO,   KC_TRNS, OSL(SYM), /* ===== */ OSL(FUN), KC_TRNS,  KC_NO
  ),
  [SYM] = LAYOUT_split_3x5_3(
    KC_NO,   KC_TILD,   KC_QUES, KC_UNDS,  KC_NO,    /* ===== */   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_NO,
    OS_LGUI, OS_LALT,   OS_LCTL, OSL(NUM), KC_NO,    /* ===== */   KC_RCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_RPRN,
    KC_NO,   OSL(SYM),  KC_PIPE, KC_PLUS,  KC_NO,    /* ===== */   KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_NO,
                        KC_NO,   KC_TRNS,  OSL(SYM), /* ===== */   KC_ENT,  KC_TRNS, KC_NO
  ),
  [NUM] = LAYOUT_split_3x5_3(
    KC_NO,   KC_GRV,   KC_SLSH, KC_MINS, KC_NO,    /* ===== */ KC_LBRC, KC_7,    KC_8, KC_9, KC_NO,
    OS_LGUI, OS_LALT,  OS_LCTL, OS_LSFT, KC_NO,    /* ===== */ KC_RBRC, KC_4,    KC_5, KC_6, KC_0,
    KC_NO,   OSL(NUM), KC_BSLS, KC_EQL,  KC_NO,    /* ===== */ KC_NO,   KC_1,    KC_2, KC_3, KC_NO,
                       KC_NO,   KC_TRNS, OSL(NUM), /* ===== */ KC_ENT,  KC_TRNS, KC_NO
  )
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  // From https://github.com/qmk/qmk_firmware/issues/22566
  // Makes one shot layer to get deactivated when a modifier is pressed
  // (which does not happen in QMK by default after PR https://github.com/qmk/qmk_firmware/issues/22566)
  if (IS_QK_ONE_SHOT_MOD(keycode) && is_oneshot_layer_active() && record->event.pressed) {
    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
  }
  return;
}

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

