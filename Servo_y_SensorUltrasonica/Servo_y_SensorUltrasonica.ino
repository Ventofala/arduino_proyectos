#include <Servo.h>
Servo mi_servo;

const int trigPin = 3;
const int echoPin = 4;

void setup() {
  Serial.begin(9600);

  mi_servo.attach(5);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  checkAndActivateServo(trigPin, echoPin, mi_servo);  
  delay(1000);
}

void checkAndActivateServo(int trigPin, int echoPin, Servo &servo) {
  float distance = getDistance(trigPin, echoPin);

  if (distance < 15 && distance > 1) {
    Serial.println("Abierto");
    servo.write(360);  
  }
  else {
      servo.write(90);
    }
}

float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds (2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds (10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * 0.034 / 2.0;
}