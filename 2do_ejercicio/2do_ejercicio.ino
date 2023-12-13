const int ledPins[] = {5, 6, 7, 8}; //ejercicio #2
const int numLeds = 4;
const int delayTime = 200; // Tiempo en milisegundos

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);  // Enciende el LED
    delay(delayTime);                // Espera el tiempo de encendido
    digitalWrite(ledPins[i], LOW);   // Apaga el LED
    delay(delayTime);                // Espera el tiempo de apagado
  }
}