/*
   Author: Aaron Walker
   Revision: A
   Date: 1/22/2016
   Purpose: define register addresses and values used for reading TCS3472
*/

#ifndef _COLOR_SENSOR_H_
#define _COLOR_SENSOR_H_

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <Wire.h>
#include "Common.h"




//Registers are listed below
//Register bit configurations are also listed, any bits not listed are reserved
#define COLOR_SENSOR_ADDRESS					    0x29	// Used for I2C bus
#define COLOR_SENSOR_COMMAND_BIT				  0x80	// Used for writing commands

#define COLOR_SENSOR_ENABLE_REGISTER			0x00	// R/W Used for power and enabling functions and interrupts
/*
   7: Reserved - Reserved, write as 0.
   6: Reserved - Reserved, write as 0.
   5: Reserved - Reserved, write as 0.
   4: AIEN - RGBC interrupt enable. Active high.
   3: WEN - Wait enable. Active high.
   2: Reserved - Reserved, write as 0.
   1: AEN - RGBC ADC enable. Active high.
   0: PON - Power on. Activates oscillator. Active high.
*/
#define COLOR_SENSOR_ENABLE_AIEN			  	0x10	// R/W Enables interrupts only triggers on clear
#define COLOR_SENSOR_ENABLE_WEN 		  		0x08	// R/W Disables wait timer. 
#define COLOR_SENSOR_ENABLE_AEN 	  			0x02	// R/W Enables the RGBC. 
#define COLOR_SENSOR_ENABLE_PON    				0x01	// R/W Turns on the power. 

#define COLOR_SENSOR_TIMING_REGISTER			0x01	// R/W The RGBC timing register controls the internal integration time in increments of 2.4ms. RGBC count = 256-ATIME*1024 up to 65535
/*
   7: ATIME - Changes integration time
   6: ATIME - Changes integration time
   5: ATIME - Changes integration time
   4: ATIME - Changes integration time
   3: ATIME - Changes integration time
   2: ATIME - Changes integration time
   1: ATIME - Changes integration time
   0: ATIME - Changes integration time
*/
#define COLOR_SENSOR_TIMING_ATIME				  0xFF	// 2.4ms integration time

#define COLOR_SENSOR_WAIT_TIME_REGISTER		0x03	// R/W The wait time set to inccrease in increments of 2.4ms. Wait time = 256 - WTIME * 1024
/*
   7: WTIME - Changes wait time
   6: WTIME - Changes wait time
   5: WTIME - Changes wait time
   4: WTIME - Changes wait time
   3: WTIME - Changes wait time
   2: WTIME - Changes wait time
   1: WTIME - Changes wait time
   0: WTIME - Changes wait time
*/
#define COLOR_SENSOR_TIMING_WTIME       0xFF// Minimum wait time


//*****************This values will be determined experimentally
#define COLOR_SENSOR_REGISTER_AILTL			0x04	// R/W Set low threshold lower byte
#define COLOR_SENSOR_AILTL              0x00  // R/W Low byte low threshold value

#define COLOR_SENSOR_REGISTER_AILTH			0x05	// R/W Set low threshold upper byte
#define COLOR_SENSOR_AILTH              0x00  // R/W Upper byte low threshold value

#define COLOR_SENSOR_REGISTER_AIHTL			0x06	// R/W Set high threshold lower byte
#define COLOR_SENSOR_AIHTL              0x00  // R/W Low byte high threshold value

#define COLOR_SENSOR_REGISTER_AIHTH			0x07	// R/W Set high threshold upper byte
#define COLOR_SENSOR_AIHTH              0x00  // R/W High byte high threshold value


#define COLOR_SENSOR_PERS_REGISTER      0x0C//R/W Filtering for interrupt. See datasheet for more details
/*
   7: PPERS - Reserved, write as 0.
   6: PPERS - Reserved, write as 0.
   5: PPERS - Reserved, write as 0.
   4: PPERS - Reserved, write as 0.
   3: APERS - Changes interrupt cycle threshold.
   2: APERS - Changes interrupt cycle threshold.
   1: APERS - Changes interrupt cycle threshold.
   0: APERS - Changes interrupt cycle threshold.
*/
#define COLOR_SENSOR_PERS_NONE					0x00	//R/W Currently set or every RGBC cycle.

#define COLOR_SENSOR_CONFIG_REGISTER		0x0D	// R/W
/*
   7: Reserved - Reserved, write as 0.
   6: Reserved - Reserved, write as 0.
   5: Reserved - Reserved, write as 0.
   4: Reserved - Reserved, write as 0.
   3: Reserved - Reserved, write as 0.
   2: Reserved - Reserved, write as 0.
   1: WLONG - Increase wait time by factor of 12. Active high.
   0: Reserved - Reserved, write as 0.
*/
#define COLOR_SENSOR_CONFIG_WLONG       0x00	// R/W Disable wait time multiplier.

#define COLOR_SENSOR_CONTROL_REGISTER		0x0F	// R/W Determine gain for readings
/*
   7: Reserved - Reserved, write as 0.
   6: Reserved - Reserved, write as 0.
   5: Reserved - Reserved, write as 0.
   4: Reserved - Reserved, write as 0.
   3: Reserved - Reserved, write as 0.
   2: Reserved - Reserved, write as 0.
   1: AGAIN - RGBC set gain. See datasheet for more details.
   0: AGAIN - RGBC set gain. See datasheet for more details.
*/
#define COLOR_SENSOR_CONTROL_AGAIN			0x00	// R/W //Set gain to 1

#define COLOR_SENSOR_ID_REGISTER 				0x12	// R Part ID
#define COLOR_SENSOR_STATUS_REGISTER		0x13	// R Provides the internal status of the device. 
/*
   7: Reserved - Reserved, write as 0.
   6: Reserved - Reserved, write as 0.
   5: Reserved - Reserved, write as 0.
   4: AINT - Clear channel interrupt.
   3: Reserved - Reserved, write as 0.
   2: Reserved - Reserved, write as 0.
   1: Reserved - Reserved, write as 0.
   0: AVALID - Indicate if the integration cycle is complete.
*/
#define COLOR_SENSOR_STATUS_AINT			0x10	// R Bit for reading status register
#define COLOR_SENSOR_STATUS_AVALID		0x01	// R But for testing if cycle is complete. 

#define COLOR_SENSOR_CDATAL						0x14	// R For reading clear channel 
#define COLOR_SENSOR_CDATAH						0x15	// R
#define COLOR_SENSOR_RDATAL						0x16	// R For reading red channel
#define COLOR_SENSOR_RDATAH						0x17	// R
#define COLOR_SENSOR_GDATAL						0x18	// R For reading green channel
#define COLOR_SENSOR_GDATAH						0x19	// R
#define COLOR_SENSOR_BDATAL						0x1A	// R For reading blue channel
#define COLOR_SENSOR_BDATAH						0x1B	// R

#define COLOR_SENSOR_LED_RESOLUTION   8 //8 bit PWM for LED
#define COLOR_SENSOR_LED_DUTY_CYCLE           26 //max is 255


boolean COLOR_SENSOR_INITIALIZE (void);
void COLOR_SENSOR_POWER_OFF (void);
void COLOR_SENSOR_SET_INTERRUPT (boolean INTERRUPT_ENABLE);
void COLOR_SENSOR_RESET_INTERRUPT_FLAG (void);
void COLOR_SENSOR_WRITE_BYTE (uint8_t COLOR_SENSOR_REGISTER_ADDRESS, uint8_t COLOR_SENSOR_WRITE_VALUE);
uint16_t COLOR_SENSOR_READ_BYTES (uint8_t COLOR_SENSOR_REGISTER_ADDRESS, uint8_t COLOR_SENSOR_BYTES_TO_READ);
void COLOR_SENSOR_READ_COLOR_DATA (uint16_t *GLB_RED, uint16_t *GBL_GREEN, uint16_t *GBL_BLUE, uint16_t *GBL_CLEAR);


#endif
