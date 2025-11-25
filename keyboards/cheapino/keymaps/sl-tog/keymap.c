#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#include "daliusd_oneshot/oneshot.h"

enum layers {
  BASE,
  NAV = 1,
  FUN = 3,
  SYM = 5,
  NUM = 7
};

enum custom_keycodes {
  CPP_NAMESPACE_SEPARATOR = SAFE_RANGE,
  C_ARROW_OPERATOR,
  OS_CTRL,
  OS_ALT,
  OS_GUI,
  OS_SFT,
  OS_NAV,
  OS_FUN,
  OS_SYM,
  OS_NUM,
  OS_CANCEL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x5_3(
    KC_QUOT, KC_COMM, KC_DOT,  KC_P,   KC_Y, /* ===== */ KC_F, KC_G,   KC_C,  KC_R, KC_L,
    KC_A,    KC_O,    KC_E,    KC_U,   KC_I, /* ===== */ KC_D, KC_H,   KC_T,  KC_N, KC_S,
    KC_SCLN, KC_Q,    KC_J,    KC_K,   KC_X, /* ===== */ KC_B, KC_M,   KC_W,  KC_V, KC_Z,
                      KC_BSPC, OS_SYM, KC_S, /* ===== */ KC_L, OS_NAV, KC_SPC
  ),

  // NAV LAYER

  [NAV] = LAYOUT_split_3x5_3(
    KC_NO, KC_PGUP,   KC_UP,   KC_PGDN, KC_HOME, /* ===== */ KC_NO, KC_CAPS,     KC_TAB,  KC_DEL, KC_NO,
    KC_NO, KC_LEFT,   KC_DOWN, KC_RGHT, KC_END,  /* ===== */ KC_NO, OS_SFT,      OS_CTRL, OS_ALT, OS_GUI,
    KC_NO, OS_CANCEL, KC_ESC,  KC_ENT,  KC_NO,   /* ===== */ KC_NO, OS_FUN,      KC_NO,   KC_NO,  KC_NO,
                      KC_TRNS, OS_SYM,  OS_GUI,  /* ===== */ KC_NO, TG(NAV + 1), KC_TRNS
  ),
  [NAV + 1] = LAYOUT_split_3x5_3(
    KC_NO, KC_PGUP,     KC_UP,   KC_PGDN, KC_HOME, /* ===== */ KC_NO, KC_CAPS,     KC_TAB,  KC_DEL, KC_NO,
    KC_NO, KC_LEFT,     KC_DOWN, KC_RGHT, KC_END,  /* ===== */ KC_NO, OS_SFT,      OS_CTRL, OS_ALT, OS_GUI,
    KC_NO, TG(NAV + 1), KC_ESC,  KC_ENT,  KC_NO,   /* ===== */ KC_NO, OS_FUN,      KC_NO,   KC_NO,  KC_NO,
                        KC_TRNS, OS_SYM,  OS_GUI,  /* ===== */ KC_NO, TG(NAV + 1), KC_TRNS
  ),

  // FUN LAYER

  [FUN] = LAYOUT_split_3x5_3(
    KC_NO, KC_F1,     KC_F2,   KC_F3,   KC_F4,   /* ===== */ KC_F5, KC_F6,       KC_F7,   KC_F8,  KC_F9,
    KC_NO, KC_MUTE,   KC_VOLD, KC_VOLU, KC_PSCR, /* ===== */ KC_NO, OS_SFT,      OS_CTRL, OS_ALT, OS_GUI,
    KC_NO, OS_CANCEL, KC_BRID, KC_BRIU, KC_NO,   /* ===== */ KC_NO, TG(FUN + 1), KC_NO,   KC_NO,  KC_NO,
                      KC_TRNS, OS_SYM,  OS_GUI,  /* ===== */ KC_F9, KC_NO,       KC_TRNS
  ),
  [FUN + 1] = LAYOUT_split_3x5_3(
    KC_NO, KC_F1,       KC_F2,   KC_F3,   KC_F4,   /* ===== */ KC_F5, KC_F6,       KC_F7,   KC_F8,  KC_F9,
    KC_NO, KC_MUTE,     KC_VOLD, KC_VOLU, KC_PSCR, /* ===== */ KC_NO, OS_SFT,      OS_CTRL, OS_ALT, OS_GUI,
    KC_NO, TG(FUN + 1), KC_BRID, KC_BRIU, KC_NO,   /* ===== */ KC_NO, TG(FUN + 1), KC_NO,   KC_NO,  KC_NO,
                        KC_TRNS, OS_SYM,  OS_GUI,  /* ===== */ KC_F9, TG(FUN + 1), KC_TRNS
  ),

  // SYM LAYER

  [SYM] = LAYOUT_split_3x5_3(
    KC_NO,                   KC_TILD,   KC_QUES, KC_UNDS,     KC_NO,   /* ===== */   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_NO,
    OS_GUI,                  OS_ALT,    OS_CTRL, OS_NUM,      KC_NO,   /* ===== */   KC_RCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_RPRN,
    CPP_NAMESPACE_SEPARATOR, OS_CANCEL, KC_PIPE, KC_PLUS,     KC_NO,   /* ===== */   KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_NO,
                                        KC_TRNS, TG(SYM + 1), KC_LPRN, /* ===== */   KC_RPRN, KC_ENT,  KC_TRNS),
  [SYM + 1] = LAYOUT_split_3x5_3(
    KC_NO,                   KC_TILD,     KC_QUES, KC_UNDS,     KC_NO,   /* ===== */   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_NO,
    OS_GUI,                  OS_ALT,      OS_CTRL, OS_NUM,      KC_NO,   /* ===== */   KC_RCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_RPRN,
    CPP_NAMESPACE_SEPARATOR, TG(SYM + 1), KC_PIPE, KC_PLUS,     KC_NO,   /* ===== */   KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_NO,
                                          KC_TRNS, TG(SYM + 1), KC_LPRN, /* ===== */   KC_RPRN, KC_ENT,  KC_TRNS
  ),

  // NUM LAYER

  [NUM] = LAYOUT_split_3x5_3(
    KC_NO,            KC_GRV,    KC_SLSH, KC_MINS,     KC_NO, /* ===== */ KC_LBRC, KC_7,    KC_8,   KC_9, KC_NO,
    OS_GUI,           OS_ALT,    OS_CTRL, TG(NUM + 1), KC_NO, /* ===== */ KC_RBRC, KC_4,    KC_5,   KC_6, KC_0,
    C_ARROW_OPERATOR, OS_CANCEL, KC_BSLS, KC_EQL,      KC_NO, /* ===== */ KC_NO,   KC_1,    KC_2,   KC_3, KC_NO,
                                 KC_TRNS, TG(NUM + 1), KC_9,  /* ===== */ KC_0,    KC_ENT,  KC_TRNS
  ),
  [NUM + 1] = LAYOUT_split_3x5_3(
    KC_NO,            KC_GRV,      KC_SLSH, KC_MINS,     KC_NO, /* ===== */ KC_LBRC, KC_7,    KC_8, KC_9, KC_NO,
    OS_GUI,           OS_ALT,      OS_CTRL, OS_SFT,      KC_NO, /* ===== */ KC_RBRC, KC_4,    KC_5, KC_6, KC_0,
    C_ARROW_OPERATOR, TG(NUM + 1), KC_BSLS, KC_EQL,      KC_NO, /* ===== */ KC_NO,   KC_1,    KC_2, KC_3, KC_NO,
                                   KC_TRNS, TG(NUM + 1), KC_9,  /* ===== */ KC_0,    KC_ENT,  KC_TRNS
  )
};

bool is_oneshot_cancel_key(uint16_t keycode) {
  switch (keycode) {
  case OS_CANCEL:
    return true;
  default:
    return false;
  }
}

bool is_oneshot_layer_cancel_key(uint16_t keycode) {
  switch (keycode) {
  case OS_CANCEL:
    return true;
  default:
    return false;
  }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
  switch (keycode) {
  case OS_CTRL:
  case OS_ALT:
  case OS_GUI:
  case OS_SFT:
  case OS_NAV:
  case OS_FUN:
  case OS_SYM:
  case OS_NUM:
    return true;
  default:
    return false;
  }
}

bool is_oneshot_mod_key(uint16_t keycode) {
  switch (keycode) {
  case OS_CTRL:
  case OS_ALT:
  case OS_GUI:
  case OS_SFT:
    return true;
  default:
    return false;
  }
}

oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
oneshot_state os_sft_state = os_up_unqueued;
oneshot_state os_nav_state = os_up_unqueued;
oneshot_state os_fun_state = os_up_unqueued;
oneshot_state os_sym_state = os_up_unqueued;
oneshot_state os_num_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  update_oneshot(
    &os_ctrl_state, KC_LCTL, OS_CTRL,
    keycode, record
  );
  update_oneshot(
    &os_alt_state, KC_LALT, OS_ALT,
    keycode, record
  );
  update_oneshot(
    &os_cmd_state, KC_LGUI, OS_GUI,
    keycode, record
  );
  update_oneshot(
    &os_sft_state, KC_LSFT, OS_SFT,
    keycode, record
  );

  bool handled = true;
  handled = update_oneshot_layer(
    &os_nav_state, NAV, OS_NAV,
    keycode, record
  ) & handled;

  handled = update_oneshot_layer(
    &os_fun_state, FUN, OS_FUN,
    keycode, record
  ) & handled;

  handled = update_oneshot_layer(
    &os_sym_state, SYM, OS_SYM,
    keycode, record
  ) & handled;

  handled = update_oneshot_layer(
    &os_num_state, NUM, OS_NUM,
    keycode, record
  ) & handled;

  if (!handled) {
    return false;
  }

  switch (keycode) {
  case C_ARROW_OPERATOR:
    if (record->event.pressed) {
      SEND_STRING("->");
    }
    break;
  case CPP_NAMESPACE_SEPARATOR:
    if (record->event.pressed) {
      SEND_STRING("::");
    }
    break;

  }
  return true;
};

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C
