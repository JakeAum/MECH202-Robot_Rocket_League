#include <Arduino.h>



void autonomous() {
    // Autonomous Function

    // We only get 10 seconds to run an autonomous program
    // What should our strategy look like
}

void analogConverter() {
    // Need to figure out if Arduino extension is more like ArduinoIDE or MATLAB

    // analogRead command output ranges from 0 to 1023 (10-bit ADC converter)
    // analogWrite command output ranges from 0 to 255 (8-bit PWM generator)
}

void motorControl() {
    // H-Bride Motor Controler (L298N)

    // Set the direction of the motor A
    // Set the speed of the motor A

    // Set the direction of the motor B
    // Set the speed of the motor B

    // Slide 
}



////////////////////////////////////////
// Arduino Main Functions
///////////////////////////////////////
void setup() {
    // Define GPIO PIN CONNECTIONS
    const int LED_PIN = 13;

    // Set the LED pin as an output
    pinMode(LED_PIN, OUTPUT);


    // do IRQ Button Presses exist in Arduino?
}

void loop() {
    // Turn on the LED
    digitalWrite(LED_PIN, HIGH);
    delay(1000); // Wait for 1 second

    // Turn off the LED
    digitalWrite(LED_PIN, LOW);
    delay(1000); // Wait for 1 second

    // Call the custom function
    autonomous();
}

