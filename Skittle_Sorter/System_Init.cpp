#include "System_Init.h"

void System_Init() {
  Wire.begin();                 // Initialize I2C bus and join as master
  COLOR_SENSOR_INITIALIZE();    // Initialize the color sensor
  
  
  
  Serial.begin(9600);
  if (COLOR_SENSOR_INITIALIZE()) {
    Serial.println("Sensor initalized successfully");
  } else {
    Serial.println("bruh");
    while (1);
  }
}
