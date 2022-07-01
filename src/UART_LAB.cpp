/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/darwinwang/Documents/IoT/UART_LAB/src/UART_LAB.ino"
void setup();
void loop();
#line 1 "/Users/darwinwang/Documents/IoT/UART_LAB/src/UART_LAB.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include "oled-wing-adafruit.h"
OledWingAdafruit display;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  display.setup();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop()
{
  if (Serial.available() > 0)
  {
    int value = Serial.read();
    Serial.println(value);
    if (value == 49) {
      Serial1.write(1);
    } else if (value == 48) {
      Serial1.write(0);
    } else if (value == 63) {
      Serial1.write("?");
    }
  }
}
