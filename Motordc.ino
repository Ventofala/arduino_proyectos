
// Control de encendido/apagado de Motor DC
byte motorDC = 3;
void setup(){
  pinMode(3, OUTPUT);
}
void loop(){
  digitalWrite(motorDC, HIGH);
  delay(2000); 
  digitalWrite(motorDC, LOW);
  delay(2000); 
}
