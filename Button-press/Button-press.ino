const int ledPin = 2;      // LED pin
const int buttonPin = 4;   // Button pin

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Button to GND
}

void loop() {
  bool button = digitalRead(buttonPin);

  // Button pressed = LOW
  if (button == LOW) {
    digitalWrite(ledPin, HIGH);  // LED ON
  } else {
    digitalWrite(ledPin, LOW);   // LED OFF
  }
}