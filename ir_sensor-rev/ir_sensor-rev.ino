// ESP32 IR Sensor (Reversed Logic)
// LED on pin 2
// Sensor active = LED OFF
// Sensor inactive = LED ON

const int ledPin    = 2;   // LED pin
const int sensorPin = 4;   // IR sensor output pin

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);   // use INPUT_PULLUP if your sensor floats
  Serial.begin(115200);
  delay(10);
}

void loop() {
  int sensorValue = digitalRead(sensorPin);

  // REVERSED LOGIC
  if (sensorValue == HIGH) {
    // Sensor NOT triggered → LED ON
    digitalWrite(ledPin, HIGH);
    Serial.println("Sensor inactive → LED ON");
  } else {
    // Sensor triggered → LED OFF
    digitalWrite(ledPin, LOW);
    Serial.println("Sensor active → LED OFF");
  }
}
