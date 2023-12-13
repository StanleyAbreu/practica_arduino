// Velocidad de la llama
const int velocidad = 100;

// Variables locales
int brillo = 0;
int tiempo = 0;

void setup() {
  // Inicializa el pin analógico como salida
  pinMode(A0, OUTPUT);
}

void loop() {
  // Genera un número aleatorio para el brillo
  brillo = random(0, 255);

  // Genera un número aleatorio para el tiempo de espera
  tiempo = random(0, velocidad);

  // Escribe el brillo en la salida analógica
  analogWrite(A0, brillo);

  // Retrasa la ejecución
  delay(tiempo);
}