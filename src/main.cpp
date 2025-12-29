
#include "oled_esp32s3.h"



void setup() {

  oled_init();
  
  display.setTextSize(2);      // Normal 1:1 pixel scale
  display.setCursor(0, 0);     // Start at top-left corner

  // ---- First message ----
  display.println("ourahhhh!");
  display.display();

  Serial.println("Setup done.");
}

void loop() {
}