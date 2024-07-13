#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>

const int Rc = 10000; // valor de la resistencia
const int Vcc = 5;
const int SensorPIN = A0;
const int ldrPin = A1;

float A = 1.11492089e-3;
float B = 2.372075385e-4;
float C = 6.954079529e-8;

float K = 2.5; // factor de disipación en mW/C

LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección I2C y tamaño del LCD (16x2)

void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temp: LUMEN:");
}

void loop() {
  // Lee el valor analógico del sensor de temperatura
  float raw = analogRead(SensorPIN);
  float V = raw / 1024 * Vcc;  // Invierte la lectura del LDR (valores más altos en la luz, valores más bajos en la oscuridad)
  float R = (Rc * V) / (Vcc - V);
  float logR = log(R);
  float R_th = 1.0 / (A + B * logR + C * logR * logR * logR);
  float kelvin = R_th - V * V / (K * R) * 1000;
  float celsius = kelvin - 273.15;

  // Muestra la temperatura en la pantalla LCD
  lcd.setCursor(0, 1);
  lcd.print(celsius);
  lcd.print("C ");

  // Lee el valor analógico del LDR
  int valorLDR = analogRead(ldrPin);

  // Invierte la lectura del LDR (valores más altos en la luz, valores más bajos en la oscuridad)
  valorLDR = 1023 - valorLDR;

  // Muestra el valor del LDR en la pantalla LCD
  lcd.setCursor(8, 1);
  lcd.print(valorLDR);

  Serial.print("Temp: ");
  Serial.print(celsius);
  Serial.print("C LUMEN: ");
  Serial.println(valorLDR);

  delay(2500); // Actualiza cada 2.5 segundos
}
