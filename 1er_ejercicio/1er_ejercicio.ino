void setup() { //ejercicio #1
  pinMode(13, OUTPUT);

}

void loop() {
  digitalWrite(13,LOW);
  delay(100);
  digitalWrite(13,HIGH);
  delay(500);
}