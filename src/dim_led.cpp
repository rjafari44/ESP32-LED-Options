#include "myheader.h"
#include <Arduino.h>

// global variable declaration, made to only be used within this file
const int pinLED{10};
const int potReadPin{4};
static int potValue{};
static int brightness{};
static char input{};

// function to set the pin to be used, returns nothing
void dimLED_setup() {
    pinMode(pinLED, OUTPUT); 
    Serial.println("\n*** Basic Dimmer Mode ***");
    Serial.println("LED is ready to be controlled by potentiometer. Type 'm' or 'M' + Enter to return to mode menu");
}

// function to perform the dimmer program, returns nothing
void dimLED_loop() {
    potValue = analogRead(potReadPin);   // store the analog value read from the potentiometer between 0 - 4095
    brightness = potValue / 16;          // divide the stored value by 16 to get it within a 0-255 for PWM
    analogWrite(pinLED, brightness);     // set the LED brightness to the calculated number

    if (Serial.available() > 0) {        // If a character is waiting in the Serial input buffer, read it
        input = Serial.read();
        
        if (input == '\n' || input == '\r') {    // Serial input includes '\r' and '\n' after the user presses Enter; ignore them
            return;
        }

        switch(input) {        // switch statement for returning to main menu
            case 'm':          // if user chooses lower case 'm', it will waterfall through due to no break to the next case
            case 'M': {        // if user chooses upper case 'M'
                currentMode = MENU;     // set current selected mode to menu
                modeSetup[1] = false;   // mark the current mode's setup as false so it runs again
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