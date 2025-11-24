// ESP32 IR Sensor 
// LED on pin 2
// Sensor active  = LED ON
// Sensor inactive = LED OFF

const int ledPin    = 2;   // LED pin
const int sensorPin = 4;   // IR sensor OUT pin

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);  // Use INPUT_PULLUP if needed

  Serial.begin(115200);
  delay(10);
}

void loop() {
  int sensorValue = digitalRead(sensorPin);

  // OPPOSITE LOGIC
  if (sensorValue == HIGH) {
    // Sensor NOT triggered → LED OFF
    digitalWrite(ledPin, LOW);
    Serial.println("Sensor inactive → LED OFF");
  } else {
    // Sensor triggered → LED ON
    digitalWrite(ledPin, HIGH);
    Serial.println("Sensor active → LED ON");
  }

  delay(50); // small read delay
}
