#include <Wire.h> // Include the I2C communication library
#include <Adafruit_GFX.h>  // Include graphics/text functions
#include <Adafruit_SH110X.h> // Include SH1106 OLED library
#define SCREEN_WIDTH 128 // OLED width = 128 pixels
#define SCREEN_HEIGHT 64 // OLED height = 64 pixels

// OLED reset pin
// -1 means no reset pin is connected
#define OLED_RESET -1
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // Create the OLED display object

void setup() {
  // Start I2C communication
  // D2 = SDA
  // D1 = SCL
  Wire.begin(4, 5);
  // Start the OLED
  // 0x3C = OLED I2C address
  display.begin(0x3C, true);
  display.clearDisplay(); // Clear the OLED screen
  display.setTextColor(SH110X_WHITE); // Set text color to white
  display.setTextSize(3); // Set text size
  // Set text position
  // X = 25
  // Y = 20
  display.setCursor(25, 20);
  display.println("Nihal"); // Print "NIhal" on OLED
  display.display(); // Show the information on OLED
}
void loop() {

  // Nothing is required here
}