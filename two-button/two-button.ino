const int ledPin = 2;      // LED pin
const int buttonOn = 16;   // ON button
const int buttonOff = 4;   // OFF button

void setup() {
  pinMode(ledPin, OUTPUT);

  pinMode(buttonOn, INPUT_PULLUP);   // ON button
  pinMode(buttonOff, INPUT_PULLUP);  // OFF button
}

void loop() {
  // Button ON → pressed = LOW
  if (digitalRead(buttonOn) == LOW) {
    digitalWrite(ledPin, HIGH);  // LED ON
    delay(200);                  // debounce
  }

  // Button OFF → pressed = LOW
  if (digitalRead(buttonOff) == LOW) {
    digitalWrite(ledPin, LOW);   // LED OFF
    delay(200);                  // debounce
  }
}
