#define TRIG_PIN 2
#define ECHO_PIN 3
#define LED_VERDE 4
#define LED_AMARILLO 5
#define LED_ROJO 6

void setup() {
 Serial.begin(9600);
 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);
 pinMode(LED_VERDE, OUTPUT);
 pinMode(LED_AMARILLO, OUTPUT);
 pinMode(LED_ROJO, OUTPUT);
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

 // Actualizar LEDs según la distancia
 actualizarLEDs(distance);

 delay(1000); // Espera 1 segundo entre las mediciones
}

void actualizarLEDs(long distancia) {
 if (distancia >= 30) {
 // Área segura
 digitalWrite(LED_VERDE, HIGH);
 digitalWrite(LED_AMARILLO, LOW);
 digitalWrite(LED_ROJO, LOW);
 } else if (distancia < 30 && distancia >= 10) {
 // Área intermedia
 digitalWrite(LED_VERDE, LOW);
 digitalWrite(LED_AMARILLO, HIGH);
 digitalWrite(LED_ROJO, LOW);
 } else {
 // Área de peligro
 digitalWrite(LED_VERDE, LOW);
 digitalWrite(LED_AMARILLO, LOW);
 digitalWrite(LED_ROJO, HIGH);
 }
}
