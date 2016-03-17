#include "System_Init.h"
#include "Color_Sensor.h"
#include "FEEDER_MOTOR.h"
#include "LCD_Display.h"

// GLOBAL VARIABLES ----------------------------------------------------------------
uint16_t RED, GREEN, BLUE, CLEAR;

// Connect via i2c, default address #0 (A0-A2 not jumpered)
Adafruit_LiquidCrystal lcd(0);

void setup() {
  System_Init();            // Initialize Arduino
  COLOR_SENSOR_INITIALIZE();
  // set up the LCD's number of rows and columns: 
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  COLOR_SENSOR_READ_COLOR_DATA(&RED, &GREEN, &BLUE, &CLEAR);
  Serial.print("R: "); Serial.print(RED, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(GREEN, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(BLUE, DEC); Serial.print(" ");
  Serial.println(" ");
  delay(500);
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis()/1000);

  lcd.setBacklight(HIGH);
  delay(500);
  lcd.setBacklight(LOW);
  delay(500);
}
