# MNT Reform USB Keyboard (Standalone)

![MNT Reform USB Keyboard (Standalone)](https://i.imgur.com/pXDDan6h.jpeg)

A compact and slim mechanical keyboard designed for comfort and portability.

* Keyboard QMK port Maintainer: [cdc-mkb](https://github.com/cdc-mkb)
* Hardware Supported: MNT Reform USB Keyboard (Standalone)
* Hardware Availability: https://shop.mntre.com/products/mnt-reform-keyboard-30

Make example for this keyboard (after setting up your build environment):

    make mntre_v3:default

Flashing example for this keyboard:

    make mntre_v3:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the "Esc" key and plug in the keyboard
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available (default: "Circle" + "R")
* **Physical reset button**: Remove the keyboard’s frame and toggle the programming DIP switch SW84 on the keyboard to “ON”.  Then press the reset button SW83.
