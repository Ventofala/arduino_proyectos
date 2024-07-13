#include <Servo.h>

Servo servoFrontLeft;
Servo servoFrontRight;
Servo servoRearLeft;
Servo servoRearRight;

const int trigPinFrontLeft = 12;
const int echoPinFrontLeft = 11;
const int trigPinFrontRight = 9;
const int echoPinFrontRight = 10;
const int trigPinRearLeft = 6;
const int echoPinRearLeft = 5;
const int trigPinRearRight = 3;
const int echoPinRearRight = 4;

void setup() {
  Serial.begin(9600);

  servoFrontLeft.attach(8);
  servoFrontRight.attach(7);
  servoRearLeft.attach(13);
  servoRearRight.attach(2);

  pinMode(trigPinFrontLeft, OUTPUT);
  pinMode(echoPinFrontLeft, INPUT);
  pinMode(trigPinFrontRight, OUTPUT);
  pinMode(echoPinFrontRight, INPUT);
  pinMode(trigPinRearLeft, OUTPUT);
  pinMode(echoPinRearLeft, INPUT);
  pinMode(trigPinRearRight, OUTPUT);
  pinMode(echoPinRearRight, INPUT);
}

void loop() {
  checkAndActivateServo(trigPinFrontLeft, echoPinFrontLeft, servoFrontLeft);
  checkAndActivateServo(trigPinFrontRight, echoPinFrontRight, servoFrontRight);
  checkAndActivateServo(trigPinRearLeft, echoPinRearLeft, servoRearLeft);
  checkAndActivateServo(trigPinRearRight, echoPinRearRight, servoRearRight);

  delay(1000); // Ajusta el tiempo según sea necesario para evitar lecturas demasiado frecuentes
}

void checkAndActivateServo(int trigPin, int echoPin, Servo &servo) {
  // Medir la distancia con el sensor ultrasónico
  float distance = getDistance(trigPin, echoPin);

  // Activar el servo si está abierto
  if (distance < 15 && distance > 1) {
    Serial.println("Abierto");
    servo.write(180); // Gira a la posición extrema
  } else {
    servo.write(90); // Apaga el servo (posición neutra)
  }
}

float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * 0.034 / 2.0;
}
