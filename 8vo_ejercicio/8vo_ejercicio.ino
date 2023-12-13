const int potentiometerPin = A0;  // Pin del potenciómetro conectado a la entrada analógica 0
const int ledPin = 9;  // Pin del LED

void setup() {
  Serial.begin(9600);  // Inicia la comunicación serial para mostrar el valor en el monitor serial
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potentiometerValue = analogRead(potentiometerPin);  // Lee el valor del potenciómetro
  int ledBrightness;

  if (potentiometerValue >= 0 && potentiometerValue <= 512) {
    ledBrightness = 255;
  }

  analogWrite(ledPin, ledBrightness);  // Ajusta el brillo del LED
  delay(100);  // Pequeña pausa para estabilidad
}