const int ledPins[] = {5, 6, 7, 8, 9}; // Pines de los LEDs
const int buzzerPin = 10; // Pin del zumbador
const int buttonPin = 11; // Pin del pulsador

int currentLED = 0; // Índice del LED actual
int timeInterval = 200; // Intervalo de tiempo inicial en milisegundos
int score = 0; // Puntaje del jugador

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  digitalWrite(ledPins[currentLED], HIGH); // Enciende el LED actual
  delay(timeInterval); // Espera el tiempo actual

  digitalWrite(ledPins[currentLED], LOW); // Apaga el LED actual

  // Verifica si el botón fue presionado en el momento correcto
  if (digitalRead(buttonPin) == LOW && currentLED == 2) {
    // El jugador presionó el botón cuando el LED intermedio se encendió
    tone(buzzerPin, 1000, 500); // Tono "piiiiiiiiiiiiii" en el zumbador durante 500 ms
    score++; // Aumenta el puntaje
    timeInterval -= 20; // Reduce el tiempo entre encendidos
    if (timeInterval < 10) {
      timeInterval = 200; // Restablece el tiempo a 200 ms si es menor de 10 ms
    }
  }

  // Avanza al siguiente LED
  currentLED = (currentLED + 1) % 5;
}