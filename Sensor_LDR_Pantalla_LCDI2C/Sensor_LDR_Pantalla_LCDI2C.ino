#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin del LDR
const int ldrPin = A1;

// Inicializa la pantalla LCD (ajusta la dirección I2C según tu módulo)
LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección I2C y tamaño del LCD (16x2)

void setup() {
  Serial.begin(9600);
  
  // Configuración de los pines
  pinMode(ldrPin, INPUT);

  // Inicializa la comunicación I2C para la pantalla LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Nivel de luz:");
}

void loop() {
  // Lee el valor analógico del LDR
  int valorLDR = analogRead(ldrPin);

  Serial.print("Valor del LDR: ");
  Serial.println(valorLDR);

  // Muestra el valor en la pantalla LCD
  // Muestra el valor del LDR en la pantalla LCD
  lcd.setCursor(8, 1);
  lcd.print(1023 - valorLDR);

  delay(1000); // Actualiza cada segundo
}
