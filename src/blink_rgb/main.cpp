#include <Arduino.h>

constexpr uint8_t RGB_PIN = 48;
constexpr uint8_t MAX_BRIGHTNESS = 50;
constexpr uint16_t CHANGE_DELAY_MS = 1000;

uint8_t curR = 0, curG = 0, curB = 0;

void randomColorBlink();

void setup() {
    Serial.begin(115200);
}

void loop() {
    randomColorBlink();

    delay(CHANGE_DELAY_MS);
}

void randomColorBlink() {
    curR = random(0, MAX_BRIGHTNESS + 1);   // 0..MAX_BRIGHTNESS
    curG = random(0, MAX_BRIGHTNESS + 1);
    curB = random(0, MAX_BRIGHTNESS + 1);

    neopixelWrite(RGB_PIN, curR, curG, curB);
    Serial.printf("R=%d G=%d B=%d\n", curR, curG, curB);
}