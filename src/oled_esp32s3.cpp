#include "oled_esp32s3.h"


#define I2C_SDA 17 
#define I2C_SCK 18 

#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 64     // OLED display height, in pixels
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  // Change if required
#define ROTATION 0           // Rotates text on OLED 1=90 degrees, 2=180 degrees


// Define display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);// Initialize OLED display object

void oled_init() {
  Wire.begin(I2C_SDA, I2C_SCK); // Initialize I2C

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); // Initialize OLED

  display.clearDisplay(); // Clear the buffer
  display.setRotation(ROTATION); // Set rotation
  display.setTextColor(SSD1306_WHITE); // Set text color

}