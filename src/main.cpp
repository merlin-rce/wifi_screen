#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Define pins
#define I2C_SDA 17 
#define I2C_SCK 18 

// OLED parameters
#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 64     // OLED display height, in pixels
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  // Change if required
#define ROTATION 0           // Rotates text on OLED 1=90 degrees, 2=180 degrees

// Define display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // ---- Serial (debug) ----
  Serial.begin(115200);
  delay(200);  // petit délai pour laisser le temps au port série de s'ouvrir
  Serial.println();
  Serial.println("Booting...");

  // ---- I2C ----
  Wire.begin(I2C_SDA, I2C_SCK);
  Serial.printf("I2C started (SDA=%d, SCL=%d)\n", I2C_SDA, I2C_SCK);

  // ---- OLED ----
  Serial.printf("Initializing OLED at I2C address 0x%02X...\n", SCREEN_ADDRESS);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("ERROR: SSD1306 init failed (check wiring / address / power).");

    // Option 1: bloquer (classique quand l'écran est indispensable)
    while (true) {
      delay(1000);
    }

    // Option 2 (alternative): ne pas bloquer
    // return;
  }

  Serial.println("OLED init OK");

  // ---- Display config ----
  display.clearDisplay();
  display.setRotation(ROTATION);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);

  // ---- First message ----
  display.println("Hello!");
  display.display();

  Serial.println("Setup done.");
}

void loop() {
}