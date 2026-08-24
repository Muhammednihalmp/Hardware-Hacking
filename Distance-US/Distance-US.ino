const int trigPin = 5;     // Ultrasonic TRIG - D1
const int echoPin = 14;    // Ultrasonic ECHO - D5
const int buzzerPin = 2;   // LED/Buzzer - D4

long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(115200);
  Serial.println("Ultrasonic Distance Monitor");
  Serial.println("---------------------------");
}

void loop() {

  // Send ultrasonic trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Display distance on Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED/Buzzer control
  if (distance <= 50) {
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Status: OBJECT DETECTED");
  } 
  else {
    digitalWrite(buzzerPin, LOW);
    Serial.println("Status: CLEAR");
  }

  Serial.println("---------------------------");

  delay(100);
}