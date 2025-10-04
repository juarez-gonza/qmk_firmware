#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum layers {
  BASE,
  NAV = 1,
  FUN = 3,
  SYM = 5,
  NUM = 7
};

/* NOTE: I think there is a bug with the implementation of OSM that causes LSFT to become
 * stuck under the sequence OSL(SYM) -> OSL(NUM) -> OS_LSFT (this seems to be the only modifier
 * for which I could trigger this). The solution, albeit a dirty one, is to replicate the NUM layer
 * and depend on toggles rather than the double tapping behavior of OSL. If this issue pops up in other
 * places, I'll do the same replication on every layer. Its lots of duplication, but I don't expect
 * this layout to change a lot so I don't mind it.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5_3(
    KC_QUOT, KC_COMM, KC_DOT,  KC_P,     KC_Y,  /* ===== */ KC_F,  KC_G,     KC_C,  KC_R, KC_L,
    KC_A,    KC_O,    KC_E,    KC_U,     KC_I,  /* ===== */ KC_D,  KC_H,     KC_T,  KC_N, KC_S,
    KC_SCLN, KC_Q,    KC_J,    KC_K,     KC_X,  /* ===== */ KC_B,  KC_M,     KC_W,  KC_V, KC_Z,
                      KC_BSPC, OSL(SYM), KC_NO, /* ===== */ KC_NO, OSL(NAV), KC_SPC
  ),

  // NAV LAYER

  [NAV] = LAYOUT_split_3x5_3(
    KC_NO, KC_PGUP, KC_UP,   KC_PGDN,  KC_HOME, /* ===== */ KC_NO, KC_CAPS,  KC_TAB,  KC_DEL,  KC_NO,
    KC_NO, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,  /* ===== */ KC_NO, OS_RSFT,  OS_RCTL, OS_RALT, OS_RGUI,
    KC_NO, KC_NO,   KC_ESC,  KC_ENT,   KC_NO,   /* ===== */ KC_NO, OSL(FUN), KC_NO,   KC_NO,   KC_NO,
                    KC_TRNS, OSL(SYM), KC_NO,   /* ===== */ KC_NO, TG(NAV + 1), KC_TRNS
  ),
  [NAV + 1] = LAYOUT_split_3x5_3(
    KC_NO, KC_PGUP,     KC_UP,   KC_PGDN,  KC_HOME, /* ===== */ KC_NO, KC_CAPS,     KC_TAB,  KC_DEL,  KC_NO,
    KC_NO, KC_LEFT,     KC_DOWN, KC_RGHT,  KC_END,  /* ===== */ KC_NO, OS_RSFT,     OS_RCTL, OS_RALT, OS_RGUI,
    KC_NO, TG(NAV + 1), KC_ESC,  KC_ENT,   KC_NO,   /* ===== */ KC_NO, OSL(FUN),    KC_NO,   KC_NO,   KC_NO,
                        KC_TRNS, OSL(SYM), KC_NO,   /* ===== */ KC_NO, TG(NAV + 1), KC_TRNS
  ),

  // FUN LAYER

  [FUN] = LAYOUT_split_3x5_3(
    KC_NO, KC_F1,   KC_F2,   KC_F3,    KC_F4,   /* ===== */ KC_F5, KC_F6,    KC_F7,   KC_F8,   KC_F9,
    KC_NO, KC_MUTE, KC_VOLD, KC_VOLU,  KC_PSCR, /* ===== */ KC_NO, OS_RSFT,  OS_RCTL, OS_RALT, OS_RGUI,
    KC_NO, KC_NO,   KC_BRID, KC_BRIU,  KC_NO,   /* ===== */ KC_NO, TG(FUN + 1), KC_NO,   KC_NO,   KC_NO,
                    KC_TRNS, OSL(SYM), KC_NO,   /* ===== */ KC_NO, KC_NO, KC_TRNS
  ),
  [FUN + 1] = LAYOUT_split_3x5_3(
    KC_NO, KC_F1,       KC_F2,   KC_F3,    KC_F4,   /* ===== */ KC_F5, KC_F6,       KC_F7,   KC_F8,   KC_F9,
    KC_NO, KC_MUTE,     KC_VOLD, KC_VOLU,  KC_PSCR, /* ===== */ KC_NO, OS_RSFT,     OS_RCTL, OS_RALT, OS_RGUI,
    KC_NO, TG(FUN + 1), KC_BRID, KC_BRIU,  KC_NO,   /* ===== */ KC_NO, TG(FUN + 1), KC_NO,   KC_NO,   KC_NO,
                        KC_TRNS, OSL(SYM), KC_NO,   /* ===== */ KC_NO, TG(FUN + 1), KC_TRNS
  ),

  // SYM LAYER

  [SYM] = LAYOUT_split_3x5_3(
    KC_NO,   KC_TILD, KC_QUES, KC_UNDS,     KC_NO, /* ===== */   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_NO,
    OS_LGUI, OS_LALT, OS_LCTL, OSL(NUM),    KC_NO, /* ===== */   KC_RCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_RPRN,
    KC_NO,   KC_NO,   KC_PIPE, KC_PLUS,     KC_NO, /* ===== */   KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_NO,
                      KC_TRNS, TG(SYM + 1), KC_NO, /* ===== */   KC_NO,   KC_ENT,  KC_TRNS
  ),
  [SYM + 1] = LAYOUT_split_3x5_3(
    KC_NO,   KC_TILD,     KC_QUES, KC_UNDS,     KC_NO, /* ===== */   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_NO,
    OS_LGUI, OS_LALT,     OS_LCTL, OSL(NUM),    KC_NO, /* ===== */   KC_RCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_RPRN,
    KC_NO,   TG(SYM + 1), KC_PIPE, KC_PLUS,     KC_NO, /* ===== */   KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_NO,
                          KC_TRNS, TG(SYM + 1), KC_NO, /* ===== */   KC_NO,   KC_ENT,  KC_TRNS
  ),

  // NUM LAYER

  [NUM] = LAYOUT_split_3x5_3(
    KC_NO,   KC_GRV,  KC_SLSH, KC_MINS,     KC_NO, /* ===== */ KC_LBRC, KC_7,    KC_8, KC_9, KC_NO,
    OS_LGUI, OS_LALT, OS_LCTL, TG(NUM + 1), KC_NO, /* ===== */ KC_RBRC, KC_4,    KC_5, KC_6, KC_0,
    KC_NO,   KC_NO,   KC_BSLS, KC_EQL,      KC_NO, /* ===== */ KC_NO,   KC_1,    KC_2, KC_3, KC_NO,
                      KC_TRNS, TG(NUM + 1), KC_NO, /* ===== */ KC_NO,   KC_ENT,  KC_TRNS
  ),
  [NUM + 1] = LAYOUT_split_3x5_3(
    KC_NO,   KC_GRV,      KC_SLSH, KC_MINS,     KC_NO, /* ===== */ KC_LBRC, KC_7,    KC_8, KC_9, KC_NO,
    OS_LGUI, OS_LALT,     OS_LCTL, OS_LSFT,     KC_NO, /* ===== */ KC_RBRC, KC_4,    KC_5, KC_6, KC_0,
    KC_NO,   TG(NUM + 1), KC_BSLS, KC_EQL,      KC_NO, /* ===== */ KC_NO,   KC_1,    KC_2, KC_3, KC_NO,
                          KC_TRNS, TG(NUM + 1), KC_NO, /* ===== */ KC_NO,   KC_ENT,  KC_TRNS
  )
};

#ifdef CONSOLE_ENABLE
#ifdef KEYCODE_STRING_ENABLE
void oneshot_locked_mods_changed_user(uint8_t mods) {
  if (mods & MOD_MASK_SHIFT) {
    println("Oneshot locked mods SHIFT");
  }
  if (mods & MOD_MASK_CTRL) {
    println("Oneshot locked mods CTRL");
  }
  if (mods & MOD_MASK_ALT) {
    println("Oneshot locked mods ALT");
  }
  if (mods & MOD_MASK_GUI) {
    println("Oneshot locked mods GUI");
  }
  if (!mods) {
    println("Oneshot locked mods off");
  }
}
#endif // KEYCODE_STRING_ENABLE
#endif // CONSOLE_ENABLE

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef CONSOLE_ENABLE
#ifdef KEYCODE_STRING_ENABLE
  bool o_lsft = get_oneshot_mods() & MOD_BIT(KC_LSFT);
  bool o_lalt = get_oneshot_mods() & MOD_BIT(KC_LALT);
  bool o_lctl = get_oneshot_mods() & MOD_BIT(KC_LCTL);
  bool o_lgui = get_oneshot_mods() & MOD_BIT(KC_LGUI);
  bool o_rsft = get_oneshot_mods() & MOD_BIT(KC_RSFT);
  bool o_ralt = get_oneshot_mods() & MOD_BIT(KC_RALT);
  bool o_rctl = get_oneshot_mods() & MOD_BIT(KC_RCTL);
  bool o_rgui = get_oneshot_mods() & MOD_BIT(KC_RGUI);
  bool lsft = get_mods() & MOD_BIT(KC_LSFT);
  bool lalt = get_mods() & MOD_BIT(KC_LALT);
  bool lctl = get_mods() & MOD_BIT(KC_LCTL);
  bool lgui = get_mods() & MOD_BIT(KC_LGUI);
  bool rsft = get_mods() & MOD_BIT(KC_RSFT);
  bool ralt = get_mods() & MOD_BIT(KC_RALT);
  bool rctl = get_mods() & MOD_BIT(KC_RCTL);
  bool rgui = get_mods() & MOD_BIT(KC_RGUI);
  uprintf("\n#### kc: %s, pressed: %d ####\n"
      "ONESHOT -- lgui: %d, lalt: %d, lctl: %d, lsft: %d\n"
      "ONESHOT -- rgui: %d, ralt: %d, rctl: %d, rsft: %d\n"
      "REGULAR -- lgui: %d, lalt: %d, lctl: %d, lsft: %d\n"
      "REGULAR -- rgui: %d, ralt: %d, rctl: %d, rsft: %d\n",
      get_keycode_string(keycode), record->event.pressed,
      o_lgui, o_lalt, o_lctl, o_lsft,
      o_rgui, o_ralt, o_rctl, o_rsft,
      lgui, lalt, lctl, lsft,
      rgui, ralt, rctl, rsft);
#endif // KEYCODE_STRING_ENABLE
#endif // CONSOLE_ENABLE

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
