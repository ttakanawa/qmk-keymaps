# Project Overview

Custom keymap (`tknw`) for the Corne Keyboard (crkbd rev4_1/standard).
Forked from QMK Firmware.

## Relevant Files

Only edit files under this directory. Do not touch any other files.

```
keyboards/crkbd/keymaps/tknw/
├── keymap.c    # Keymap definitions, custom keycodes, Tap Dance
├── config.h    # RGB Matrix settings
└── rules.mk    # Build options (OLED, Tap Dance)
```

## Build

Unit tests are not required and do not need to be implemented. To verify changes,
AI agents only need to confirm that the following command succeeds:

  ```sh
  qmk compile -kb crkbd/rev4_1/standard -km tknw
  ```

When suggesting a build command to a human, this `make` shortcut is also available:

  ```sh
  make compile-tknw
  ```
