SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include "oled-wing-adafruit.h"
OledWingAdafruit display;

void displaySetup() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.display();
}

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  display.setup();
  display.setTextColor(WHITE);
  displaySetup();
}

void loop()
{
  display.loop();
  if (Serial.available() > 0)
  {
    
    int8_t value = Serial.read();
    Serial.println(value);
    int8_t value1 = Serial1.read();
    if (value == 49) {
      Serial1.write(1);
      displaySetup();
      display.print("LED On signal sent");
      display.display();
      delay(1000);
      displaySetup();
    } else if (value == 48) {
      Serial1.write(0);
      displaySetup();
      display.print("LED Off signal sent");
      display.display();
      delay(1000);
      displaySetup();
    } else if (value == 63) {
      Serial1.write("?");
      
      Serial.println(value1);
      displaySetup();
      if (Serial1.read() == 0) {
        display.print("The button is off");
        display.display();
        delay(1000);
        displaySetup();
      } else {
        display.print("The button is on");
        display.display();
        delay(1000);
        displaySetup();
      }
      
    }
  }
}
