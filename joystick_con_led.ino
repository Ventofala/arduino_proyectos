// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

#define UP_LED 8
#define RIGHT_LED 9 
#define LEFT_LED 10
#define DOWN_LED 11

void setup() {
  pinMode(SW_pin, INPUT_PULLUP); // Configuración de la resistencia pull-up interna
  Serial.begin(115200);
  pinMode(UP_LED, OUTPUT);
  pinMode(RIGHT_LED, OUTPUT);
  pinMode(LEFT_LED, OUTPUT);
  pinMode(DOWN_LED, OUTPUT);
}

void loop() {
  int switchState = digitalRead(SW_pin);
  int xValue = analogRead(X_pin);
  int yValue = analogRead(Y_pin);

  Serial.print("Switch: ");
  Serial.print(switchState);
  Serial.print("\nX-axis: ");
  Serial.print(xValue);
  Serial.print("\nY-axis: ");
  Serial.println(yValue);
  Serial.print("\n\n");

  delay(500);

  // Apagar todos los LEDs antes de encender los necesarios
  digitalWrite(UP_LED, LOW);
  digitalWrite(DOWN_LED, LOW);
  digitalWrite(LEFT_LED, LOW);
  digitalWrite(RIGHT_LED, LOW);

  if (xValue == 1023) {
    digitalWrite(UP_LED, HIGH);
  } else if (xValue == 0) {
    digitalWrite(DOWN_LED, HIGH);
  }

  if (yValue == 1023) {
    digitalWrite(RIGHT_LED, HIGH);
  } else if (yValue == 0) {
    digitalWrite(LEFT_LED, HIGH);
  }

  if (switchState == LOW) { // Switch presionado (considerando pull-up)
    digitalWrite(UP_LED, HIGH);
    digitalWrite(LEFT_LED, HIGH);
    digitalWrite(RIGHT_LED, HIGH);
    digitalWrite(DOWN_LED, HIGH);
  }
}
