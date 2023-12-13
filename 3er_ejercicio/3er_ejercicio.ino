const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Pines de los LEDs (ejercicio #3)
const int numLeds = 8;
const int delayTime = 1000; // 1 segundo

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  secuenciaNormal();
  delay(1000); // Espera 1 segundo entre secuencias

  secuenciaReversa();
  delay(1000);

  parpadeoConjunto(3);
  delay(1000);

  secuenciaSalto();
  delay(1000);
}

void secuenciaNormal() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}

void secuenciaReversa() {
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}

void parpadeoConjunto(int veces) {
  for (int j = 0; j < veces; j++) {
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
    delay(delayTime);
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    delay(delayTime);
  }
}

void secuenciaSalto() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = 1; i < numLeds; i += 2) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}