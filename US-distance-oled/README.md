Ultrasonic Distance Meter using ESP32 

This project uses an ESP32, an HC-SR04 ultrasonic sensor, and an SH1106 128x64 OLED display to measure and display distance in centimeters.

The measured distance is shown on the OLED screen in real-time with large, clear numbers.

📌 Features

-> Real-time distance measurement

-> Clean OLED UI using Adafruit GFX + SH1106 library

-> Simple wiring

-> Works with any ESP32 board

🛠 Components Required

-> ESP32 Development Board

-> SH1106 OLED Display (I²C 128×64)

-> HC-SR04 Ultrasonic Sensor

-> Jumper wires

-> (Recommended) 10kΩ + 15kΩ resistors (ECHO voltage divider)

🔌 Wiring Diagram
SH1106 OLED → ESP32 (I²C)
OLED Pin	ESP32 Pin
VCC	      3.3V
GND	      GND
SDA	      GPIO 21
SCL	      GPIO 22

HC-SR04 → ESP32
HC-SR04 Pin	ESP32 Pin
VCC	        5V
GND	        GND
TRIG	      GPIO 5
ECHO	      GPIO 18

▶️ How to Use

1. Install required libraries in Arduino IDE:

  -> Adafruit GFX Library
  
  -> Adafruit SH110X Library

2. Select ESP32 Dev Module from Tools → Board.

3. Upload the code.

4. Distance will display live on the OLED.
