#pragma once

// enum type
enum Menu { MENU, BLINK, DIM_BASIC, DIM_RGB };

// external global variables
inline Menu currentMode{MENU};
inline bool menuDisplayed{false};
inline bool modeSetup[3]{false, false, false};

// display and user input functions
void showMenu();
void getUserInput();

// setup and loop functions for the blink mode
void blink_setup();
void blink_loop();

// setup and loop functions for the basic dimmer mode
void dimLED_setup();
void dimLED_loop();

// setup and loop functions for the RGB dimmer mode
void dimRGB_setup();
void dimRGB_loop();