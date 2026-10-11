#include <Arduino.h>

// Function declarations
void alternateLedSlowly(uint8_t pin);
void alternateLedFast(uint8_t pin);
void policeStrobe(uint8_t ledPin);
void speedUp(uint8_t ledPin);

// RED LED PIN
constexpr uint8_t LED_RED_OUT {15};
// BLUE LED PIN
constexpr uint8_t LED_BLUE_OUT {16};
// GREEN LED PIN
constexpr uint8_t LED_GREEN_OUT {17};

// Delay between phases in milliseconds
constexpr uint16_t PHASE_DELAY_MS {1000};

void setup() {
    // setup pins
    pinMode(LED_RED_OUT, OUTPUT);
    pinMode(LED_BLUE_OUT, OUTPUT);
    pinMode(LED_GREEN_OUT, OUTPUT);
}

void loop() {
    alternateLedSlowly(LED_RED_OUT);
    alternateLedSlowly(LED_BLUE_OUT);
    alternateLedSlowly(LED_GREEN_OUT);

    delay(PHASE_DELAY_MS);

    alternateLedFast(LED_RED_OUT);
    alternateLedFast(LED_BLUE_OUT);
    alternateLedFast(LED_GREEN_OUT);

    delay(PHASE_DELAY_MS);

    policeStrobe(LED_RED_OUT);
    policeStrobe(LED_BLUE_OUT);
    policeStrobe(LED_GREEN_OUT);

    delay(PHASE_DELAY_MS);

    speedUp(LED_RED_OUT);
    speedUp(LED_BLUE_OUT);
    speedUp(LED_GREEN_OUT);

    delay(PHASE_DELAY_MS);
}

// Switch lights slowly for a concrete led from the input pi
void alternateLedSlowly(uint8_t ledPin) {
    constexpr uint16_t ALTERNATE_DELAY_MS {1000};

    digitalWrite(ledPin, HIGH);
    delay(ALTERNATE_DELAY_MS);
    digitalWrite(ledPin, LOW);
}

// Switch lights fast for a concrete led from the input pi
void alternateLedFast(uint8_t ledPin) {
    constexpr uint16_t ALTERNATE_DELAY_MS {200};

    digitalWrite(ledPin, HIGH);
    delay(ALTERNATE_DELAY_MS);
    digitalWrite(ledPin, LOW);
}

// Switch lights fast 3 times
void policeStrobe(uint8_t ledPin) {
    constexpr uint16_t POLICE_STROBE_DELAY_MS {100};

    digitalWrite(ledPin, HIGH);
    delay(POLICE_STROBE_DELAY_MS);
    digitalWrite(ledPin, LOW);
    delay(POLICE_STROBE_DELAY_MS);

    digitalWrite(ledPin, HIGH);
    delay(POLICE_STROBE_DELAY_MS);
    digitalWrite(ledPin, LOW);
    delay(POLICE_STROBE_DELAY_MS);

    digitalWrite(ledPin, HIGH);
    delay(POLICE_STROBE_DELAY_MS);
    digitalWrite(ledPin, LOW);
    delay(POLICE_STROBE_DELAY_MS);
}

// Switch lights fast 5 times with decreasing delay
void speedUp(uint8_t ledPin) {
    uint16_t current_delay {1000};

    for (size_t i = 0; i < 5; i++)
    {
        digitalWrite(ledPin, HIGH);
        delay(current_delay);
        digitalWrite(ledPin, LOW);
        delay(current_delay);

        current_delay -= i * 50; 
    }
}