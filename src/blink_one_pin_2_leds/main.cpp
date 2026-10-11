#include <Arduino.h>

void alternateLedSlowly(uint8_t pin);

constexpr uint8_t LED_OUT {15};

constexpr uint16_t PHASE_DELAY_MS {1000};
constexpr uint8_t LED_RED_STATE = HIGH;
constexpr uint8_t LED_BLUE_STATE = LOW;
constexpr uint8_t OFF_STATE = INPUT;
constexpr uint8_t ON_STATE = OUTPUT;

void setup() {
    // setup pins
    pinMode(LED_OUT, OUTPUT);
}

void loop() {
    alternateLedSlowly(LED_OUT);

    delay(PHASE_DELAY_MS);
}

// Switch lights slowly between 2 leds using one pin from the input pin
void alternateLedSlowly(uint8_t ledPin) {
    constexpr uint16_t ALTERNATE_DELAY_MS {1000};

    pinMode(ledPin, ON_STATE); // switch pin back to output mode to turn on leds

    digitalWrite(ledPin, LED_RED_STATE);
    delay(ALTERNATE_DELAY_MS);

    digitalWrite(ledPin, LED_BLUE_STATE);
    delay(ALTERNATE_DELAY_MS);

    pinMode(ledPin, OFF_STATE); // switch pin to input mode to turn off leds
    delay(ALTERNATE_DELAY_MS);
}