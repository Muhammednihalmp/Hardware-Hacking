// ESP32 IR Sensor Toggle Mode
// Raise hand once  -> LED ON
// Raise hand again -> LED OFF

const int ledPin    = 2;   // LED pin D4
const int sensorPin = 4;   // IR sensor output pin D2

bool ledState = false;     // Current LED state (OFF initially)
bool lastSensorState = HIGH;  // For reversed logic sensor
unsigned long debounceDelay = 150; 
unsigned long lastTriggerTime = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(115200);
  delay(10);

  digitalWrite(ledPin, ledState);  // initialize LED
}

void loop() {
  int sensorValue = digitalRead(sensorPin);

  // Detect transition: HIGH → LOW (hand detected)
  if (sensorValue == LOW && lastSensorState == HIGH) {
    if (millis() - lastTriggerTime > debounceDelay) {
      
      // Toggle LED
      ledState = !ledState;
      digitalWrite(ledPin, ledState);

      Serial.print("Hand detected → LED ");
      Serial.println(ledState ? "ON" : "OFF");

      lastTriggerTime = millis();
    }
  }

  lastSensorState = sensorValue;
}
