#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define TRIG 13    // D7
#define ECHO 12    // D6

Adafruit_SH1106G display(128, 64, &Wire, -1);

void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Wire.begin(4, 5);    // SDA = D2, SCk = D1

  display.begin(0x3C, true);
  display.clearDisplay();
  display.display();
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG, LOW);

  // Read echo
  long duration = pulseIn(ECHO, HIGH);

  // Calculate distance
  float distance = duration * 0.034 / 2;

  // Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance, 1);
  Serial.println(" cm");

  // OLED
  display.clearDisplay();

  display.setTextColor(SH110X_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Distance:");

  display.setTextSize(3);
  display.setCursor(0, 20);
  display.print(distance, 1);
  display.println("cm");

  display.display();

  delay(150);
}
