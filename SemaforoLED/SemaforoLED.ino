#include <arduino.h> 

const int V = 2; //LED Verde
const int A = 3; //LED Amarilla
const int R = 4; //LED Roja 

void setup() {
  //Configura los pines de los LEDs como salidas 
  pinMode(V, OUTPUT); 
  pinMode(A, OUTPUT); 
  pinMode(R, OUTPUT); 

}

void loop() {
  //Configuracion LED Verde
  digitalWrite(V, HIGH); //Enciende el LED
  delay(1000); //Espera 1 segundo (1000 milisegundos) 
  digitalWrite(V, LOW); //Apaga el LED 

  delay(500); //Espera medio segundo (500 milisegundos) 

  //Configuracion LED Amarillo 
  digitalWrite(A, HIGH); //Enciende el LED
  delay(1000); //Espera 1 segundo (1000 milisegundos) 
  digitalWrite(A, LOW); //Apaga el LED 

  delay(500); //Espera medio segundo (500 milisegundos) 
  
  //Configuracion LED Rojo
  digitalWrite(R, HIGH); //Enciende el LED
  delay(1000); //Espera 1 segundo (1000 milisegundos) 
  digitalWrite(R, LOW); //Apaga el LED 
  
  delay(500); //Espera medio segundo (500 milisegundos) para reiniciar el bucle

}
