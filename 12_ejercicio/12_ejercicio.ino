int zumbadorPin = 10; // Pin al que está conectado el zumbador (salida analógica)
int notas[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956}; // Valores de frecuencia para las notas
int timNota = 100; // Tiempo de duración de cada nota en milisegundos
int pausa = 100; // Tiempo de pausa entre notas en milisegundos

void setup() {
  pinMode(zumbadorPin, OUTPUT);
}

void loop() {
  for (int n = 0; n < 8; n++) {
    // Generar la nota actual
    tone(zumbadorPin, notas[n]);

    // Mantener la nota durante el tiempo especificado (tnota)
    for (int m = 0; m <= timNota; m++) {
      delay(1); // Pequeña pausa para mantener la nota
    }

    // Apagar el zumbador
    noTone(zumbadorPin);

    // Hacer una pausa entre notas
    delay(pausa);
  }
}