const int ledPin2 = 2;
const int ledPin4 = 4;

void setup() {
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
  // Fade pin2 down
  for (int b = 255; b >= 0; --b) {
    analogWrite(ledPin2, b);
    delay(15);
  }
  
  // Fade pin4 up
  for (int b = 0; b <= 255; ++b) {
    analogWrite(ledPin4, b);
    delay(15);
    digitalWrite(ledPin4, LOW);
  }
  
  // Fade pin4 down
  for (int b = 255; b >= 0; --b) {
    analogWrite(ledPin4, b);
    delay(15);
  }
  
  // Fade pin2 up
  for (int b = 0; b <= 255; ++b) {
    analogWrite(ledPin2, b);
    delay(15);
    digitalWrite(ledPin2, LOW);   
  }
}

