const int ledPin = 2;     // LED pin
const int buttonPin = 4;  // Button pin

bool ledState = false;    // Current LED state
bool lastButton = HIGH;   // Previous button state

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  // Button to GND
}

void loop() {
  bool button = digitalRead(buttonPin);

  // Detect button press (HIGH → LOW)
  if (lastButton == HIGH && button == LOW) {
    ledState = !ledState;           // Toggle LED state
    digitalWrite(ledPin, ledState); // Update LED
    delay(200);                     // Debounce delay
  }

  lastButton = button;
}
