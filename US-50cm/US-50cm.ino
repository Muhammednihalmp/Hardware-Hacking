const int trigPin = 5;   // Ultrasonic TRIG D1
const int echoPin = 14;  // Ultrasonic ECHO D5
const int buzzerPin  = 2;   // Buzzer output pin D4

long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(115200);
}

void loop() {

  // Trigger the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pulse time
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance (cm)
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED control
  if (distance <= 50) {
    digitalWrite(buzzerPin, HIGH);   // LED ON
  } else {
    digitalWrite(buzzerPin, LOW);    // LED OFF
  }

  delay(100);
}
