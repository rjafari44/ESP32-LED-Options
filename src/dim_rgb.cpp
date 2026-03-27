#include "myheader.h"
#include <Arduino.h>

// global variable declaration, made to only be used within this file
const int pinLED[3]{20, 10, 8};
const int potReadPin[3]{0, 1, 4};
static int potValue[3]{};
static int brightness[3]{};
static char input{};

// function to set the pins to be used, returns nothing
void dimRGB_setup() {

    for (int i = 0; i < 3; i++) {
        pinMode(pinLED[i], OUTPUT);
    }
    Serial.println("\n*** RGB Dimmer Mode ***");
    Serial.println("LEDs are ready to be controlled by the potentiometers. Type 'm' or 'M' + Enter to return to mode menu");
}

// function to perform the dimmer program for the RGB LED, returns nothing
void dimRGB_loop() {
    for (int i = 0; i < 3; i++) {                   // for loop to read from each potentiometer and write to its respective LED output Pin
        potValue[i] = analogRead(potReadPin[i]);    // store the analog value read from the potentiometer between 0 - 4095
        brightness[i] = potValue[i] / 16;           // divide the stored value by 16 to get it within a 0-255 for PWM
        analogWrite(pinLED[i], brightness[i]);      // set the LED brightness to the calculated number
    }

    if (Serial.available() > 0) {        // If a character is waiting in the Serial input buffer, read it
        input = Serial.read();
        
        if (input == '\n' || input == '\r') {    // Serial input includes '\r' and '\n' after the user presses Enter; ignore them
            return;
        }

        switch(input) {        // switch statement for returning to main menu
            case 'm':          // if user chooses lower case 'm', it will waterfall through due to no break to the next case
            case 'M': {        // if user chooses upper case 'M'
                currentMode = MENU;     // set current selected mode to menu
                modeSetup[2] = false;   // mark the current mode's setup as false so it runs again
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