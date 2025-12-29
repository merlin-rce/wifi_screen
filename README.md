# ESP32 SSD1306 Menu UI

Simple menu system for an **SSD1306 OLED display** using an **ESP32** and physical buttons.

This project is mainly about learning how to structure a clean and scalable menu for embedded systems.

---

## What it does
- Displays a menu on an SSD1306 OLED (I2C)
- Navigation with buttons (LEFT / RIGHT / SELECT)
- Home menu works like a **carousel** (pages you scroll through)
- Each screen is handled as a **state** (`switch-case`)
- Screen is redrawn only when something changes

---

## Menu logic (short explanation)
- `LEFT / RIGHT` → change the page shown on the Home screen
- `SELECT` → enter the selected category
- Each screen = one state
- Home uses a `homeIndex` (page index), not a list cursor

---

## Project structure
src/

├── main.ino // State machine & main logic
|
├── oled_esp32s3.* // OLED init
|
├── buttons.* // Button events
|
├── ui.* // Drawing functions
|
└── icons.h // OLED icons (PROGMEM)

---

## Why this project
I wanted to understand:
- how menu systems work internally
- how to avoid messy `if` statements
- how to keep embedded UI code clean and readable

---

## Notes
- Easy to extend with new pages or icons

---

## License
Free to use for learning and personal projects.
