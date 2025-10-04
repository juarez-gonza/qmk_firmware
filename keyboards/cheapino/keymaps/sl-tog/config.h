#pragma once

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 2000  /* Time (in ms) before the one shot key is released */

// Forbid a key-up to happen on a different layer
// (allows one to hold a key, change layer, and the
// original key is still the one being held instead
// of the one in its place). This is the default
// behavior as of:
// https://github.com/qmk/qmk_firmware/issues/2518
// #define PREVENT_STUCK_MODIFIERS
