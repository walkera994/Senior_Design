
#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#include <stdlib.h>
#include "Color_Sensor.h"
#include "Common.h"

void COLOR_SENSOR_LED_DC(uint8_t DC){
  pinMode(COLOR_SENSOR_LED_PIN, OUTPUT);
  analogWrite(COLOR_SENSOR_LED_PIN, DC);
}
boolean COLOR_SENSOR_INITIALIZE(void) {
  uint8_t LOCAL_ID_CHECK = 0;
  pinMode(COLOR_SENSOR_LED_PIN, OUTPUT);      // Power pin for LED
  analogWriteResolution(COLOR_SENSOR_LED_RESOLUTION);       
  analogWrite(COLOR_SENSOR_LED_PIN, COLOR_SENSOR_LED_DUTY_CYCLE);      
  Wire.begin(COLOR_SENSOR_ADDRESS);           // Initialize the color sensor on I2C bus to COLOR_SENSOR_ADDRESS (0x29)
  LOCAL_ID_CHECK = COLOR_SENSOR_READ_BYTES(COLOR_SENSOR_ADDRESS, 1);  
  if (!((LOCAL_ID_CHECK = 0x44) || (LOCAL_ID_CHECK = 0x10))) {
    return false;
  }
  //******Write all of our settings to the sensor
  COLOR_SENSOR_WRITE_BYTE(COLOR_SENSOR_TIMING_REGISTER, COLOR_SENSOR_TIMING_ATIME);
  COLOR_SENSOR_WRITE_BYTE(COLOR_SENSOR_CONTROL_REGISTER, COLOR_SENSOR_CONTROL_AGAIN);
  COLOR_SENSOR_WRITE_BYTE(COLOR_SENSOR_ENABLE_REGISTER, COLOR_SENSOR_ENABLE_PON);
  delay(3);
  COLOR_SENSOR_WRITE_BYTE(COLOR_SENSOR_ENABLE_REGISTER, COLOR_SENSOR_ENABLE_PON | COLOR_SENSOR_ENABLE_AEN);
  COLOR_SENSOR_WRITE_BYTE(COLOR_SENSOR_REGISTER_AILTL, COLOR_SENSOR_AILTL);
  COLOR_SENSOR_WRITE_BYTE(COLOR_SENSOR_REGISTER_AILTH, COLOR_SENSOR_AILTH);
  COLOR_SENSOR_WRITE_BYTE(COLOR_SENSOR_REGISTER_AIHTL, COLOR_SENSOR_AIHTL);
  COLOR_SENSOR_WRITE_BYTE(COLOR_SENSOR_REGISTER_AIHTH, COLOR_SENSOR_AIHTH);
  return true;
}



/**************************************************************************/
/*!
    @brief  Writes a register and an 8 bit value over I2C
*/
/**************************************************************************/
void COLOR_SENSOR_WRITE_BYTE (uint8_t COLOR_SENSOR_REGISTER_ADDRESS, uint8_t COLOR_SENSOR_WRITE_VALUE) {
  Wire.beginTransmission(COLOR_SENSOR_ADDRESS);
  #if ARDUINO >= 100
  Wire.write(COLOR_SENSOR_COMMAND_BIT | COLOR_SENSOR_REGISTER_ADDRESS);
  Wire.write(COLOR_SENSOR_WRITE_VALUE & 0xFF);
  #else
  Wire.send(COLOR_SENSOR_COMMAND_BIT | COLOR_SENSOR_REGISTER_ADDRESS);
  Wire.send(COLOR_SENSOR_WRITE_VALUE & 0xFF);
  #endif
  Wire.endTransmission();
}

/**************************************************************************/
/*!
    @brief  Reads an 8 bit value over I2C
*/
/**************************************************************************/
uint16_t COLOR_SENSOR_READ_BYTES(uint8_t COLOR_SENSOR_ADDRESS_TO_READ, uint8_t COLOR_SENSOR_BYTES_TO_READ) {
  uint16_t LOCAL_BYTE1 = 0; 
  uint16_t LOCAL_BYTE2 = 0;
  uint16_t LOCAL_BYTES_RETURN = 0;
  Wire.beginTransmission(COLOR_SENSOR_ADDRESS);
  #if ARDUINO >= 100
  Wire.write(COLOR_SENSOR_COMMAND_BIT | COLOR_SENSOR_ADDRESS_TO_READ);
  #else
  Wire.send(COLOR_SENSOR_COMMAND_BIT | COLOR_SENSOR_ADDRESS_TO_READ);
  #endif
  Wire.endTransmission();
  if (COLOR_SENSOR_BYTES_TO_READ >= 2) {
      Wire.requestFrom(COLOR_SENSOR_ADDRESS, 2);
      #if ARDUINO >= 100
      LOCAL_BYTE1 = Wire.read();
      LOCAL_BYTE2 = Wire.read();
      #else
      LOCAL_BYTE1 = Wire.receive();
      LOCAL_BYTE2 = Wire.receive();
      #endif
      LOCAL_BYTE2 <<= 8;
      LOCAL_BYTES_RETURN = LOCAL_BYTE2 | LOCAL_BYTE1;
      return (LOCAL_BYTES_RETURN);
  } else {
    Wire.requestFrom(COLOR_SENSOR_ADDRESS, 1);
    #if ARDUINO >= 100
    return Wire.read();
    #else
    return Wire.receive();
    #endif
  }
}


void COLOR_SENSOR_READ_COLOR_DATA(uint16_t *GLB_RED, uint16_t *GBL_GREEN, uint16_t *GBL_BLUE, uint16_t *GBL_CLEAR) {  
  *GLB_RED = COLOR_SENSOR_READ_BYTES(COLOR_SENSOR_RDATAL, 2);
  *GBL_GREEN = COLOR_SENSOR_READ_BYTES(COLOR_SENSOR_GDATAL, 2);
  *GBL_BLUE = COLOR_SENSOR_READ_BYTES(COLOR_SENSOR_BDATAL, 2);
  *GBL_CLEAR = COLOR_SENSOR_READ_BYTES(COLOR_SENSOR_CDATAL, 2);
}



void COLOR_SENSOR_SET_INTERRUPT(boolean INTERRUPT_ENABLE) {
  uint8_t LOCAL_TEMP_REGISTER_VALUE = COLOR_SENSOR_READ_BYTES(COLOR_SENSOR_ENABLE_REGISTER, 1);
  if (INTERRUPT_ENABLE) {
    LOCAL_TEMP_REGISTER_VALUE |= COLOR_SENSOR_ENABLE_AIEN;
  } else {
    LOCAL_TEMP_REGISTER_VALUE &= ~COLOR_SENSOR_ENABLE_AIEN;
  }
  COLOR_SENSOR_WRITE_BYTE(COLOR_SENSOR_ENABLE_REGISTER, LOCAL_TEMP_REGISTER_VALUE);
}

void COLOR_SENSOR_RESET_INTERRUPT_FLAG(void) {
  Wire.beginTransmission(COLOR_SENSOR_ADDRESS);
  #if ARDUINO >= 100
  Wire.write(COLOR_SENSOR_COMMAND_BIT | 0x66);
  #else
  Wire.send(COLOR_SENSOR_COMMAND_BIT | 0x66);
  #endif
  Wire.endTransmission();
}

