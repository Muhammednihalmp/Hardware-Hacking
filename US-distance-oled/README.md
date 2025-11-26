# 🌊 Ultrasonic Distance Meter with ESP32

A feature-rich ultrasonic distance measurement system with beautiful OLED animations and real-time visualization. This project transforms the ESP32 and HC-SR04 sensor into a professional-looking distance meter with smooth animations and intuitive visual feedback.

![Distance Range: 2-400cm](https://img.shields.io/badge/Range-2--400cm-blue)
![Platform: ESP32](https://img.shields.io/badge/Platform-ESP32-green)
![Display: SH1106](https://img.shields.io/badge/Display-SH1106-orange)

---

## ✨ Features

### 🎨 Visual Enhancements
- **Animated Boot Sequence** - Radar sweep animation on startup
- **Real-time Wave Header** - Pulsing wave effect at the top
- **Signal Strength Bars** - Animated indicators showing measurement quality
- **Range Indicator Bar** - Visual progress bar showing distance from 0-4 meters
- **Smooth Transitions** - Distance values smoothly interpolate between readings
- **Scanning Dots Animation** - Animated dots showing active measurement

### 📊 Display Information
- **Large 3x Font Distance** - Easy-to-read main measurement
- **Decimal Precision** - Shows tenths of centimeters
- **Out of Range Detection** - Clear warning when object is too close/far
- **Dynamic Updates** - Refreshes 10 times per second

### 🔧 Technical Features
- Low-pass filtering for stable readings
- 2-400cm measurement range
- I²C communication with OLED
- Optimized refresh rate
- Error handling for invalid readings

---

## 🛠️ Components Required

| Component | Quantity | Notes |
|-----------|----------|-------|
| ESP32 Development Board | 1 | Any ESP32 variant works |
| SH1106 OLED Display (128×64) | 1 | I²C interface |
| HC-SR04 Ultrasonic Sensor | 1 | Standard 5V version |
| Jumper Wires | Several | Male-to-female recommended |
| Breadboard | 1 | Optional but helpful |
| Voltage Divider Resistors | Optional | 10kΩ + 15kΩ for ECHO protection |

### 💡 Optional Components
- **Resistor Voltage Divider** (10kΩ + 15kΩ) - Protects ESP32 from 5V ECHO signal
- **Capacitor** (10µF) - Stabilizes power to HC-SR04
- **Case/Enclosure** - For a professional finish

---

## 🔌 Wiring Diagram

### SH1106 OLED → ESP32 (I²C)
```
OLED Pin  →  ESP32 Pin
━━━━━━━━━━━━━━━━━━━━
VCC       →  3.3V
GND       →  GND
SDA       →  GPIO 21
SCL       →  GPIO 22
```

### HC-SR04 → ESP32
```
HC-SR04   →  ESP32 Pin
━━━━━━━━━━━━━━━━━━━━━
VCC       →  5V
GND       →  GND
TRIG      →  GPIO 5
ECHO      →  GPIO 18 (use voltage divider)
```

### ⚠️ Important: ECHO Pin Protection
The HC-SR04 outputs 5V on ECHO, but ESP32 GPIO pins are 3.3V tolerant. Use a voltage divider:

```
HC-SR04 ECHO → 10kΩ resistor → GPIO 18
                               ↓
                         15kΩ resistor → GND
```

This reduces 5V to ~3V, protecting your ESP32.

---

## 📥 Installation & Setup

### 1. Install Arduino IDE
Download from [arduino.cc](https://www.arduino.cc/en/software)

### 2. Install ESP32 Board Support
1. Open Arduino IDE
2. Go to **File → Preferences**
3. Add to "Additional Board Manager URLs":
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Go to **Tools → Board → Boards Manager**
5. Search "ESP32" and install **esp32 by Espressif Systems**

### 3. Install Required Libraries
Go to **Sketch → Include Library → Manage Libraries** and install:

- **Adafruit GFX Library** by Adafruit
- **Adafruit SH110X** by Adafruit
- **Adafruit BusIO** (dependency, may auto-install)

### 4. Configure Board Settings
- **Board**: "ESP32 Dev Module"
- **Upload Speed**: 921600
- **Flash Frequency**: 80MHz
- **Port**: Select your ESP32's COM port

### 5. Upload the Code
1. Connect ESP32 via USB
2. Copy the code into Arduino IDE
3. Click **Upload** (→ button)
4. Wait for "Done uploading" message

---

## 🎬 What to Expect

### Boot Sequence (3 seconds)
1. **Radar Animation** - Expanding circles
2. **Splash Screen** - "ULTRASONIC Distance Meter"
3. **Loading Bar** - Initialization progress

### Normal Operation
- **Large Distance Display** - Main reading in cm
- **Animated Header** - Pulsing wave effect
- **Signal Bars** - Show measurement activity
- **Range Bar** - Visual distance indicator (0-4m)
- **Decimal Display** - Precise measurement below

### Out of Range
When object is <2cm or >400cm, displays "OUT OF RANGE"

---

## 🎛️ Customization Options

### Change Measurement Units
Modify the display section to show inches instead of cm:
```cpp
float inches = distance / 2.54;
display.print((int)inches);
display.print(F("in"));
```

### Adjust Update Speed
Change measurement frequency (line 33):
```cpp
if(currentTime - lastMeasure >= 100) {  // 100ms = 10Hz
```

### Modify Animation Speed
Change animation frame rate (line 39):
```cpp
if(currentTime - lastAnim >= 150) {  // 150ms
```

### Change Pin Assignments
Update pin definitions at the top:
```cpp
#define TRIG_PIN 5   // Change to your preferred pin
#define ECHO_PIN 18  // Change to your preferred pin
```

---

## 🐛 Troubleshooting

### Display Not Working
- ✅ Check I²C address (try 0x3C or 0x3D)
- ✅ Verify SDA/SCL connections
- ✅ Ensure 3.3V power (not 5V)
- ✅ Run I²C scanner to find address

### No Distance Readings
- ✅ Verify TRIG/ECHO connections
- ✅ Check HC-SR04 has 5V power
- ✅ Test with multimeter if ECHO signal is present
- ✅ Ensure object is between 2-400cm away

### Erratic/Jumpy Readings
- ✅ Add smoothing (already implemented in code)
- ✅ Use voltage divider on ECHO pin
- ✅ Add 10µF capacitor near HC-SR04 power pins
- ✅ Keep wires short and away from noise sources

### Display Shows "SH1106 allocation failed"
- ✅ Check if display is SH1106 (not SSD1306)
- ✅ Try address 0x3D instead of 0x3C
- ✅ Verify I²C wiring

---

## 📊 Performance Specifications

| Parameter | Value |
|-----------|-------|
| Measurement Range | 2 - 400 cm |
| Accuracy | ±3mm (at 20cm) |
| Update Rate | 10 Hz |
| Display Refresh | ~7 Hz |
| Resolution | 0.1 cm |
| Operating Voltage | 3.3V / 5V |
| Current Draw | ~80mA typical |

---

## 🔮 Future Enhancements

Possible upgrades for this project:
- 📡 **WiFi Data Logging** - Send measurements to cloud
- 📈 **Graph Display** - Show distance over time
- 🔊 **Audio Feedback** - Beep at specific distances
- 🎯 **Multiple Sensors** - 3D position tracking
- 🔋 **Battery Operation** - Deep sleep for portable use
- 📱 **Bluetooth App** - Mobile monitoring
- 🎨 **Color OLED** - Use SSD1351 for color display

---

## 📝 License

This project is open source and available for personal and educational use.

---

## 🙏 Credits

- **Libraries**: Adafruit GFX & SH110X
- **Hardware**: Espressif ESP32, HC-SR04 sensor
- **Community**: Arduino & ESP32 forums

---

## 📧 Support

Having issues? Check:
1. Wiring diagram above
2. Troubleshooting section
3. Serial monitor for debug messages
4. ESP32 and sensor datasheets

---

**Happy Making! 🚀**
