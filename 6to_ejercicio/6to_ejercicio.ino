const int pulsadorPin = 4;
const int ledPins[] = {5, 6, 7, 8};
const int numLeds = 4;
const int delayTime = 200; // 200 milisegundos

bool pulsadorPresionado = false;

void setup() {
  pinMode(pulsadorPin, INPUT_PULLUP);
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  pulsadorPresionado = digitalRead(pulsadorPin) == LOW;

  if (pulsadorPresionado) {
    secuenciaLEDs();
  }
}

void secuenciaLEDs() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}