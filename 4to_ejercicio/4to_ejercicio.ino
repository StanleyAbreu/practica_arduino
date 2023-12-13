const int semaforo1RojoPin = 3; //ejercicio4 arreglar 
const int semaforo1AmbarPin = 4;
const int semaforo1VerdePin = 5;
const int semaforo2RojoPin = 6;
const int semaforo2AmbarPin = 7;
const int semaforo2VerdePin = 8;

const int tiempoRojoVerde = 3000; // 3 segundos
const int tiempoAmbarParpadeo = 500; // 500 milisegundos

void setup() {
  pinMode(semaforo1RojoPin, OUTPUT);
  pinMode(semaforo1AmbarPin, OUTPUT);
  pinMode(semaforo1VerdePin, OUTPUT);
  pinMode(semaforo2RojoPin, OUTPUT);
  pinMode(semaforo2AmbarPin, OUTPUT);
  pinMode(semaforo2VerdePin, OUTPUT);
}

void loop() {
  // Secuencia: Rojo 1 - Verde 2
  digitalWrite(semaforo1RojoPin, HIGH);
  digitalWrite(semaforo2VerdePin, HIGH);
  delay(tiempoRojoVerde);

  // Secuencia: Rojo 1 - Ambar 2 (parpadea)
  digitalWrite(semaforo1RojoPin, HIGH);
  digitalWrite(semaforo2VerdePin, LOW);
  for (int i = 0; i < 5; i++) { // Parpadeo durante 2.5 segundos
    digitalWrite(semaforo2AmbarPin, HIGH);
    delay(tiempoAmbarParpadeo);
    digitalWrite(semaforo2AmbarPin, LOW);
    delay(tiempoAmbarParpadeo);
  }

  // Secuencia: Verde 1 - Rojo 2
  digitalWrite(semaforo1RojoPin, LOW);
  digitalWrite(semaforo1VerdePin, HIGH);
  digitalWrite(semaforo2RojoPin, HIGH);
  delay(tiempoRojoVerde);

  // Secuencia: Ambar 1 (parpadea) - Rojo 2
  for (int i = 0; i < 5; i++) { // Parpadeo durante 2.5 segundos
    digitalWrite(semaforo1AmbarPin, HIGH);
    delay(tiempoAmbarParpadeo);
    digitalWrite(semaforo1AmbarPin, LOW);
    delay(tiempoAmbarParpadeo);
  }
  digitalWrite(semaforo1VerdePin, LOW);
}