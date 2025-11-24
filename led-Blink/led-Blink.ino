// Simple LED Blink on ESP32 (Pin 2)

const int ledPin = 2;  // Built-in LED on many ESP32 boards

void setup() {
  pinMode(ledPin, OUTPUT);  // Set pin as output
}

void loop() {
  digitalWrite(ledPin, HIGH);  // Turn LED ON
  delay(1000);                 // Wait 1 second
  digitalWrite(ledPin, LOW);   // Turn LED OFF
  delay(1000);                 // Wait 1 second
}
