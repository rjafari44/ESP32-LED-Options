#include "common.h"

// global variable declaration, made to only be used within this file
constexpr int PIN_LED{4};

// function to set the pins to be used, returns nothing
void blink_setup() {
    pinMode(PIN_LED, OUTPUT);
    Serial.println("\n*** Blink Mode ***");
    Serial.println("LED is blinking. Type 'm' or 'M' + Enter to return to mode menu");
}

// function to perform the blink program, returns nothing
void blink_loop() {
    static char input{};

    digitalWrite(PIN_LED, HIGH);   // set the pin to max value (highest voltage)
    delay(1000);                  // wait one second
    digitalWrite(PIN_LED, LOW);    // set the pin to lowest value (lowest voltage, 0)
    delay(1000);                  // wait one second

    if (Serial.available() > 0) {        // If a character is waiting in the Serial input buffer, read it
        input = Serial.read();
        
        if (input == '\n' || input == '\r') {    // Serial input includes '\r' and '\n' after the user presses Enter; ignore them
            return;
        }

        switch(input) {        // switch statement for returning to main menu
            case 'm':          // if user chooses lower case 'm', it will waterfall through due to no break to the next case
            case 'M': {        // if user chooses upper case 'M'
                currentMode = MENU;     // set current selected mode to menu
                modeSetup[0] = false;   // mark the current mode's setup as false so it runs again
                Serial.println("Returning to mode menu...");
                break;
            }
            default:      // default case to protect against invalid input
            Serial.println("Unknown command. Type 'm' or 'M' to return to main menu.");
            break;
        }

        while (Serial.available() > 0) {
            Serial.read();              // flush the extra characters.
        }
    }
}