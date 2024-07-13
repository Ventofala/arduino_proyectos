#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin del sensor de humedad
const int SensorPin = A0;

// Valores de calibración
const int MinHum = 800; // Valor en aire (seco)
const int MaxHum = 300; // Valor en agua (mojado)

// Inicializa la pantalla LCD (ajusta la dirección I2C según tu módulo)
LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección I2C y tamaño del LCD (16x2)

unsigned long startTime = 0; // Variable para almacenar el tiempo de inicio

void setup() {
  Serial.begin(9600);
  
  // Configuración del pin del sensor de humedad
  pinMode(SensorPin, INPUT);

  // Inicializa la comunicación I2C para la pantalla LCD
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Lee el valor analógico del sensor de humedad
  int humedad = analogRead(SensorPin);

  // Calibrar el valor de humedad
  int porcentajeHumedad = map(humedad, MinHum, MaxHum, 0, 100);
  
  // Asegúrate de que el porcentaje esté dentro del rango
  porcentajeHumedad = constrain(porcentajeHumedad, 0, 100);

  // Imprime los valores en el monitor serial
  Serial.print("Humedad: ");
  Serial.print(porcentajeHumedad);
  Serial.print("% (");
  Serial.print(humedad);
  Serial.println(")");

  // Si la humedad es 100%, reinicia el tiempo de inicio
  if (porcentajeHumedad >= 100) {
    startTime = millis();
  }

  // Calcular el tiempo transcurrido desde startTime
  unsigned long tiempoTranscurrido = (millis() - startTime) / 1000;

  // Muestra la humedad y el tiempo en segundos en la pantalla LCD
  lcd.setCursor(0, 0);
  lcd.print("Humedad: ");
  lcd.print(porcentajeHumedad);
  lcd.print("%  ");
  
  lcd.setCursor(0, 1);
  lcd.print("Tiempo: ");
  lcd.print(tiempoTranscurrido);
  lcd.print("s ");

  delay(1000); // Actualiza cada segundo
}
