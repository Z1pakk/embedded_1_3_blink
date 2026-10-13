#include <Arduino.h>

// Визначаємо цифровий пін, до якого підключимо зовнішній світлодіод.
// Суфікс _OUT одразу підказує, що цей пін працює на вихід.
// #define LED_OUT 15
constexpr uint8_t LED_RED_OUT = 15;
constexpr uint8_t LED_BLUE_OUT = 16;

void setup() {
    // Налаштовуємо пін як вихід (OUTPUT), щоб контролер міг подавати на нього напругу
    pinMode(LED_RED_OUT, OUTPUT);
    pinMode(LED_BLUE_OUT, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    digitalWrite(LED_RED_OUT, HIGH); // Вмикаємо світлодіод (подаємо 3.3 В)
    Serial.println("Red On");
    digitalWrite(LED_BLUE_OUT, LOW); // Вмикаємо світлодіод (подаємо 3.3 В)
    Serial.println("Blue Off");
    delay(1000);                 // Чекаємо 1 секунду (1000 мілісекунд)
    
    Serial.println();

    digitalWrite(LED_RED_OUT, LOW);  // Вимикаємо світлодіод (подаємо 0 В)
    Serial.println("Red Off");
    digitalWrite(LED_BLUE_OUT, HIGH);  // Вимикаємо світлодіод (подаємо 0 В)
    Serial.println("Blue On");

    delay(1000);                 // Чекаємо 1 секунду
}