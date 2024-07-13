#define TRIG_PIN 2
#define ECHO_PIN 3
#define BUZZER_PIN 12

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  long duration, distance;

  // Enviar pulso ultrasónico
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Calcular la distancia en centímetros
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration / 2) / 29.1;

  // Imprimir la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Actualizar el buzzer según la distancia
  actualizarBuzzer(distance);

  delay(1000); // Espera 1 segundo entre las mediciones
}

void actualizarBuzzer(long distancia) {
  if (distancia >= 30) {
    // Área segura - No hay sonido
    noTone(BUZZER_PIN);
  } else if (distancia < 30 && distancia >= 10) {
    // Área intermedia - Tono intermedio
    tone(BUZZER_PIN, 5000, 50); // Frecuencia de 1000 Hz durante 500 ms
  } else {
    // Área de peligro - Tono de advertencia
    tone(BUZZER_PIN, 600, 600); // Frecuencia de 2000 Hz durante 200 ms
  }
}
