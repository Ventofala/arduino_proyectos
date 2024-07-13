#include <Wire.h>
#include <math.h>

const int Rc = 10000; // valor de la resistencia
const int Vcc = 5;
const int SensorPIN = A0;
const int ldrPin = A1;
const int pinRelay1 = 7; // Cambia esto al pin al que está conectado tu primer relé
const int pinRelay2 = 6; // Cambia esto al pin al que está conectado tu segundo relé

float A = 1.11492089e-3;
float B = 2.372075385e-4;
float C = 6.954079529e-8;

float K = 2.5; // factor de disipación en mW/C

void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  pinMode(pinRelay1, OUTPUT);
  pinMode(pinRelay2, OUTPUT);
}

void loop() {
  // Lee el valor analógico del sensor de temperatura
  float raw = analogRead(SensorPIN);
  float V = raw / 1024 * Vcc;
  float R = (Rc * V) / (Vcc - V);
  float logR = log(R);
  float R_th = 1.0 / (A + B * logR + C * logR * logR * logR);
  float kelvin = R_th - V * V / (K * R) * 1000;
  float celsius = kelvin - 273.15;

  // Lee el valor analógico del LDR
  int valorLDR = analogRead(ldrPin);

  // Invierte la lectura del LDR (valores más altos en la luz, valores más bajos en la oscuridad)
  valorLDR = 1023 - valorLDR;

  // Activa el relé 1 si la temperatura es mayor a 0 grados
  if (celsius > 24) {
    digitalWrite(pinRelay1, HIGH);
  } else {
    digitalWrite(pinRelay1, LOW);
  }

  // Activa el relé 2 si el valor del LDR es mayor a 300 (ajusta este valor según sea necesario)
  if (valorLDR > 300) {
    digitalWrite(pinRelay2, HIGH);
  } else {
    digitalWrite(pinRelay2, LOW);
  }

  Serial.print("Temp: ");
  Serial.print(celsius);
  Serial.print("C LDR: ");
  Serial.println(valorLDR);

  delay(2500); // Actualiza cada 2.5 segundos
}
