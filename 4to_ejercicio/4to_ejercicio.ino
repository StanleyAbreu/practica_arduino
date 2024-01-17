// separacion de las secuencias y configuraciones por funciones
const int semaforo1RojoPin = 3;
const int semaforo1AmbarPin = 4;
const int semaforo1VerdePin = 5;
const int semaforo2RojoPin = 6;
const int semaforo2AmbarPin = 7;
const int semaforo2VerdePin = 8;

const int tiempoRojoVerde = 3000; // 3 segundos
const int tiempoAmbarParpadeo = 500; // 500 milisegundos

void setup() {
  configurarPines();
}

void loop() {
  secuenciaSemaforo1Rojo_Semaforo2Verde();
  secuenciaSemaforo1Rojo_Semaforo2AmbarParpadeo();
  secuenciaSemaforo1Verde_Semaforo2Rojo();
  secuenciaSemaforo1AmbarParpadeo_Semaforo2Rojo();
}

void configurarPines() {
  pinMode(semaforo1RojoPin, OUTPUT);
  pinMode(semaforo1AmbarPin, OUTPUT);
  pinMode(semaforo1VerdePin, OUTPUT);
  pinMode(semaforo2RojoPin, OUTPUT);
  pinMode(semaforo2AmbarPin, OUTPUT);
  pinMode(semaforo2VerdePin, OUTPUT);
}

void secuenciaSemaforo1Rojo_Semaforo2Verde() {
  digitalWrite(semaforo1RojoPin, HIGH);
  digitalWrite(semaforo2VerdePin, HIGH);
  delay(tiempoRojoVerde);
}

void secuenciaSemaforo1Rojo_Semaforo2AmbarParpadeo() {
  digitalWrite(semaforo1RojoPin, HIGH);
  digitalWrite(semaforo2VerdePin, LOW);
  parpadeo(semaforo2AmbarPin);
}

void secuenciaSemaforo1Verde_Semaforo2Rojo() {
  digitalWrite(semaforo1RojoPin, LOW);
  digitalWrite(semaforo1VerdePin, HIGH);
  digitalWrite(semaforo2RojoPin, HIGH);
  delay(tiempoRojoVerde);
}

void secuenciaSemaforo1AmbarParpadeo_Semaforo2Rojo() {
  parpadeo(semaforo1AmbarPin);
  digitalWrite(semaforo1VerdePin, LOW);
}

void parpadeo(int pin) {
  for (int i = 0; i < 5; i++) { // Parpadeo durante 2.5 segundos
    digitalWrite(pin, HIGH);
    delay(tiempoAmbarParpadeo);
    digitalWrite(pin, LOW);
    delay(tiempoAmbarParpadeo);
  }
}
