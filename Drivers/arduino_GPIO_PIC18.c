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

// hardware specific pin mode
#define PIN_MODE_OUTPUT (0)
#define PIN_MODE_INPUT (1)

void pinMode(int pin, enum PinModeGPIO mode)
{
	// disable analog input for digital output on analog pins
	if (mode == OUTPUT)
	{
		switch (pin)
		{
		case A0:
			ADCON1bits.PCFG &= 0;
			break;
		case A1:
			ADCON1bits.PCFG &= 0x1;
			break;
		case A2:
			ADCON1bits.PCFG &= 0x2;
			break;
		case A3:
			ADCON1bits.PCFG &= 0x3;
			break;
		case 13:
			ADCON1bits.PCFG &= 0xB;
			break;
		default:
		break;
		}
	}

	// get hardware specific pin mode
	unsigned pinMode = mode == OUTPUT ? PIN_MODE_OUTPUT : PIN_MODE_INPUT;

	switch (pin)
	{
	case A0:
		TRISAbits.RA0 = pinMode;
		break;
	case A1:
		TRISAbits.RA1 = pinMode;
		break;
	case A2:
		TRISAbits.RA2 = pinMode;
		break;
	case A3:
		TRISAbits.RA3 = pinMode;
		break;
	case 0: // RX
		TRISCbits.RC7 = pinMode;
		break;
	case 1: // TX
		TRISCbits.RC6 = pinMode;
		break;
	case 2:
		TRISCbits.RC2 = pinMode;
		break;
	case 3:
		TRISDbits.RD5 = pinMode;
		break;
	case 4:
		TRISDbits.RD6 = pinMode;
		break;
	case 5:
		TRISDbits.RD7 = pinMode;
		break;
	case 13:
		TRISBbits.RB4 = pinMode;
		break;
	case SCL_PIN:
		TRISBbits.RB1 = pinMode;
		break;
	case SDA_PIN:
		TRISBbits.RB0 = pinMode;
		break;
	default:
		break;
	}
}

void digitalWrite(int pin, unsigned level)
{
	switch (pin)
	{
	case A0:
		PORTAbits.RA0 = level;
		break;
	case A1:
		PORTAbits.RA1 = level;
		break;
	case A2:
		PORTAbits.RA2 = level;
		break;
	case A3:
		PORTAbits.RA3 = level;
		break;
	case 0: // RX
		PORTCbits.RC7 = level;
		break;
	case 1: // TX
		PORTCbits.RC6 = level;
		break;
	case 2:
		PORTCbits.RC2 = level;
		break;
	case 3:
		PORTDbits.RD5 = level;
		break;
	case 4:
		PORTDbits.RD6 = level;
		break;
	case 5:
		PORTDbits.RD7 = level;
		break;
	case 13:
		PORTBbits.RB4 = level;
//		break;
	case SCL_PIN:
		PORTBbits.RB1 = level;
		break;
	case SDA_PIN:
		PORTBbits.RB0 = level;
		break;
	default:
		break;
	}
}

unsigned digitalRead(int pin)
{
		switch (pin)
	{
	case A0:
		return PORTAbits.RA0;
	case A1:
		return PORTAbits.RA1;
	case A2:
		return PORTAbits.RA2;
	case A3:
		return PORTAbits.RA3;
	case 0: // RX
		return PORTCbits.RC7;
	case 1: // TX
		return PORTCbits.RC6;
	case 2:
		return PORTCbits.RC2;
	case 3:
		return PORTDbits.RD5;
	case 4:
		return PORTDbits.RD6;
	case 5:
		return PORTDbits.RD7;
	case 13:
		return PORTBbits.RB4;
	case SCL_PIN:
		return PORTBbits.RB1;
	case SDA_PIN:
		return PORTBbits.RB0;
	default:
		return LOW;
	}
}

void analogWrite(int pin, unsigned short value)
{

}

unsigned short analogRead(int pin)
{
	return 0;
}