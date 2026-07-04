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

AI agents should run this command when building the keymap:

  ```sh
  qmk compile -kb crkbd/rev4_1/standard -km tknw
  ```

When suggesting a build command to a human, this `make` shortcut is also available:

  ```sh
  make compile-tknw
  ```
