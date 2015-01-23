/**
 * @brief This file holds the PIC18F specific implementation of the GPIO API.
 *
 * This implementation of the GPIO API is taylored to the Microchip PIC18F line
 * of high performance 8 bit microcontrollers.
 */

// Common header file
#include "arduino_GPIO.h"

// Processor specific includes
#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#define PIN_MODE_OUTPUT (0)
#define PIN_MODE_INPUT (1)

void pinMode(int pin, enum PinModeGPIO mode){
	
	// disable analog input for digital output on analog pins
	if(mode == OUTPUT)
	{
		switch (pin)
		{
			case A0:
				ADCON1bits.PCFG = 0;
				break;
		}		
	}
	
	switch (pin)
	{
	case A0:
		TRISAbits.RA0 = mode;
		break;
	case 0:

		break;
	}
	
}

void digitalWrite(int pin, unsigned direction){
	
}

unsigned digitalRead(int pin){
	return LOW;
}