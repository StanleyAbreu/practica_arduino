// Umbrales
const int umbral1 = 100;
const int umbral2 = 200;
const int umbral3 = 300;

// Variables locales
int lectura = 0;

void setup() {
  // Inicializa los pines digitales como salidas
  for (int i = 6; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // Lee la entrada analógica
  lectura = analogRead(A1);
  // Enciende el LED correspondiente al umbral
  if (lectura < umbral1) {
    levelIndicator(HIGH, LOW, LOW);

  } else if (lectura < umbral2) {
    levelIndicator(HIGH, HIGH, LOW);
    
  } else {
   levelIndicator(HIGH, HIGH, HIGH);
  }
}

void levelIndicator(int minor, int medium, int high) {
  digitalWrite(6, minor);
  digitalWrite(7, medium);
  digitalWrite(8, high);
}