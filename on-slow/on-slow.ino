const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int b = 0; b <= 255; ++b) {
    analogWrite(ledPin, b);
    delay(15);
    digitalWrite(ledPin, LOW);   // Turn LED OFF 
  }
}
