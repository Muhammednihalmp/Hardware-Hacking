const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int b = 255; b >= 0; --b) {
    analogWrite(ledPin, b);
    delay(15);
  }
}
