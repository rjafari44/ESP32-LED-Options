#include "myheader.h"
#include <Arduino.h>

// function for setting up the serial monitor
void setup() {
    Serial.begin(115200);
    delay(1000);
}

// main loop for running the program
void loop() {
    switch(currentMode) {                // switch statement for selected mode
        case MENU: {                     // if user selects to display the menu, this is the default case at the beginning
            if (!menuDisplayed) {        // if the menu hasn't been displayed yet
                showMenu();              // display the menu
                menuDisplayed = true;    // mark menu as displayed
            }
            getUserInput();              // get user input
            break;
        }
        case BLINK: {                   // if the user chooses blink mode
            if (!modeSetup[0]) {        // if the blink mode setup hasn't run yet
                blink_setup();          // run the blink setup function
                modeSetup[0] = true;    // mark the setup as complete
            }
            blink_loop();               // perform the LED blink function
            break;
        }
        case DIM_BASIC: {              // if the user chooses basic dimmer mode
            if (!modeSetup[1]) {       // if the basic dimmer mode setup hasn't run yet
                dimLED_setup();        // run the basic dimmer setup function
                modeSetup[1] = true;   // mark the setup as complete
            }
            dimLED_loop();             // perform the LED basic dimmer function
            break;
        }
        case DIM_RGB: {               // if the user chooses RGB dimmer mode
            if (!modeSetup[2]) {      // if the RGB dimmer mode setup hasn't run yet
                dimRGB_setup();       // run the RGB dimmer setup function
                modeSetup[2] = true;  // mark the setup as complete
            }
            dimRGB_loop();            // perform the RGB dimmer function
            break;
        }
        default: {                   // default statement for safety
            currentMode = MENU;         // set the current selected mode back to menu
            menuDisplayed = false;   // mark the menu as not displayed yet to enable redesplay
            break;
        }
    }
}
