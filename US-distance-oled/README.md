# Ultrasonic Distance Meter - ESP32

Real-time distance measurement with animated OLED display.

## Components
- ESP32 Dev Board
- SH1106 OLED (128×64, I²C)
- HC-SR04 Ultrasonic Sensor
- Jumper wires

## Wiring

**OLED → ESP32**
```
VCC → 3.3V
GND → GND
SDA → GPIO 21
SCL → GPIO 22
```

**HC-SR04 → ESP32**
```
VCC  → 5V
GND  → GND
TRIG → GPIO 5
ECHO → GPIO 18
```

## Setup
1. Install Arduino IDE
2. Add ESP32 board support
3. Install libraries:
   - Adafruit GFX Library
   - Adafruit SH110X
4. Select "ESP32 Dev Module"
5. Upload code

## Features
- Animated boot sequence
- Large distance display (2-400cm)
- Signal strength bars
- Range indicator bar
- Smooth value transitions
- Out of range detection


## Troubleshooting
- **No display**: Check I²C address (0x3C or 0x3D)
- **No readings**: Verify TRIG/ECHO pins and 5V power
- **Jumpy values**: Already smoothed in code

Range: 2-400cm | Update: 10Hz
