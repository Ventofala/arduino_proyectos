#include <Wire.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define VENTILADOR_PIN 13
#define SERVO_PIN 6
#define TRANSISTOR_PIN 10
#define LDR_PIN A3

Servo myServo;

// Dirección I2C de la pantalla LCD
#define LCD_I2C_ADDR 0x27
LiquidCrystal_I2C lcd(LCD_I2C_ADDR, 16, 2);

// Variables
const int NUM_LECTURAS_TEMP = 5;
float sumaTemperatura = 0;
int humedad;
float temperatura;
int valresist;

void setup() 
{
  lcd.begin(16, 2);
  lcd.backlight();
  
  myServo.attach(SERVO_PIN);
  
  pinMode(VENTILADOR_PIN, OUTPUT);
  pinMode(TRANSISTOR_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
  sumaTemperatura = obtenerTemperaturaPromedio();

  humedad = analogRead(POTENCIOMETRO_PIN) / 10;
  valresist = analogRead(LDR_PIN);

  controlarVentiladorYServo(sumaTemperatura);
  controlarTransistor(humedad);
  
  actualizarLCD(sumaTemperatura, humedad, valresist);
}

float obtenerTemperaturaPromedio() 
{
  float suma = 0;
  
  for (int i = 0; i < NUM_LECTURAS_TEMP; i++)
  {
    int sensor = analogRead(A0);
    float temperatura = (sensor * 500.0) / 1024.0;
    suma += temperatura;
    delay(100);
  }

  return suma / NUM_LECTURAS_TEMP;
}

void controlarVentiladorYServo(float tempPromedio) 
{
  if (tempPromedio < 25)
  {
    digitalWrite(VENTILADOR_PIN, LOW); // Apagar el ventilador (motor DC)
    myServo.write(0);
    delay(3000);
  }
  else
  {
    digitalWrite(VENTILADOR_PIN, HIGH); // Encender el ventilador (motor DC)
    myServo.write(90);
    delay(2000);
  }
}

void controlarTransistor(int humedadActual) 
{
  if (humedadActual < 80)
  {
    digitalWrite(TRANSISTOR_PIN, HIGH);  // Encender el motor DC
  }
  else
  {
    digitalWrite(TRANSISTOR_PIN, LOW);  // Apagar el motor DC
  }
}

void actualizarLCD(float tempPromedio, int humedadActual, int resistenciaLDR) 
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempPromedio, 1);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Luz: ");
  lcd.print(resistenciaLDR);
  lcd.print(" H: ");
  lcd.print(humedadActual);
  delay(1000);  // Puedes ajustar el tiempo de visualización en el LCD según tus necesidades
}
