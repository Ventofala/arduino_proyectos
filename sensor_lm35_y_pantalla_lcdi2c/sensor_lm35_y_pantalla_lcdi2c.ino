#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección del LCD

const int lm35Pin = A0; // Pin analógico donde está conectado el LM35

void setup() {
    lcd.init();
    lcd.backlight();
    pinMode(lm35Pin, INPUT); // Configura el pin del LM35 como entrada
}

void loop() {
    // Lee el valor analógico del LM35
    int lm35Value = analogRead(lm35Pin);

    // Convierte el valor a temperatura en grados Celsius
    float temperatura = (lm35Value * 5.0 / 1023.0) * 100.0;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperatura);
    lcd.print(" C");
    delay(1000);
}
