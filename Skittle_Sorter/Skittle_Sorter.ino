#include "Color_Sensor.h"
#include "FEEDER_MOTOR.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (COLOR_SENSOR_INITALIZE()) {
    Serial.println("Sensor initalized successfully");
  }
  else {
    Serial.println("bruh");
    while (1);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t RED, GREEN, BLUE, CLEAR;
  COLOR_SENSOR_READ_COLOR_DATA(&RED, &GREEN, &BLUE, &CLEAR);
  Serial.print("R: "); Serial.print(RED, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(GREEN, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(BLUE, DEC); Serial.print(" ");
  Serial.println(" ");
  delay(500);
}
