
#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#include <stdlib.h>

#include <DueTimer.h>

#include "Motors.h"
#include "Color_Sensor.h"
#include "Common.h"
#include "LCD_Display.h"
#include "Solenoid_Logic.h"

volatile uint16_t ISR_COUNTER = 0;
volatile uint16_t GREEN = 0;
volatile uint16_t BLUE = 0;
volatile uint16_t RED = 0;
volatile uint16_t CLEAR = 0;
volatile uint32_t MOTOR_BELT_HALL_COUNT = 0;

void MAIN_ISR()
{
  ISR_COUNTER++;

  COLOR_SENSOR_READ_COLOR_DATA(&RED, &GREEN, &BLUE, &CLEAR);
  //MOTOR_SERVO_HALL_DETECT();
  //MOTOR_SERVO_CALCULATE_SPEED();
  MOTOR_BELT_HALL_COUNT += MOTOR_BELT_HALL_DETECT();
  




  
 if (ISR_COUNTER >= (ISR_FREQ)){
    MOTOR_BELT_HALL_COUNT = MOTOR_BELT_HALL_COUNT/ISR_FREQ;
    //Serial.println(MOTOR_BELT_HALL_COUNT);
    /*
     * Measure 1/2 period with the MOTOR_BELT_HALL_DETECT()
     * 12 periods per rotation;
     * 9.7 rotations per gearbox rotation
     * measured in us instead of ms
     * MOTOR_BELT_HALL_COUNT*24*9.7/1000
     * Gives ms / rotation
     */
     //MOTOR_BELT_SPEED = (MOTOR_BELT_HALL_COUNT*24*97)/(10000); 
    MOTOR_BELT_CALCULATE_SPEED(MOTOR_BELT_HALL_COUNT);
    MOTOR_BELT_HALL_COUNT = 0;
    ISR_COUNTER = 0;
  }
}




void setup(void) {
  Serial.begin(115200);
  analogWriteResolution(ANALOG_RESOLUTION); //set to 12-bit
  analogReadResolution(ANALOG_RESOLUTION); 
  MOTORS_INIT();
  COLOR_SENSOR_INITIALIZE();
  Timer6.attachInterrupt(MAIN_ISR).setFrequency(ISR_FREQ).start();


}

void loop(void) {

  
}


