#define RELAY_PIN_1 7
#define RELAY_PIN_2 6

void setup() {
  // initialize digital pins as outputs.
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(RELAY_PIN_1, HIGH);   // turn the first RELAY on 
  digitalWrite(RELAY_PIN_2, HIGH);   // turn the second RELAY on 
  delay(10000);                       // wait for 10 seconds
  
  digitalWrite(RELAY_PIN_1, LOW);    // turn the first RELAY off
  digitalWrite(RELAY_PIN_2, LOW);    // turn the second RELAY off
  delay(5000);                        // wait for 5 seconds
}
