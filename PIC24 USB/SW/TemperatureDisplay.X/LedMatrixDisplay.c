/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__PIC24E__)
    	#include <p24Exxxx.h>
    #elif defined (__PIC24F__)||defined (__PIC24FK__)
	#include <p24Fxxxx.h>
    #elif defined(__PIC24H__)
	#include <p24Hxxxx.h>
    #endif
#endif

#include <stdint.h>          /* For uint32_t definition */
#include <stdbool.h>         /* For true/false definition */

#include "LedMatrixDisplay.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

// display frame buffer
volatile uint8_t display[LED_MATRIX_NUM_OF_ROWS] = {0};

#define MATRIXPORT PORTD
#define MATRIXTRIS TRISD

static const uint8_t Timer1InterruptPriority = 7;

void InitMatrixDisplay()
{
	MATRIXTRIS = 0xf000; // set D0 .. D11 to output (D0..6 connected to row, D7..11 to column)
	
	// setup timer 1 and interrupt
	T1CONbits.TGATE = 0; // select clock source

	T1CONbits.TCKPS0 = 0; // prescaler
	T1CONbits.TCKPS1 = 0;

	PR1 = 0xfff; // set period

	IPC0bits.T1IP0 = Timer1InterruptPriority & 0x01;
	IPC0bits.T1IP1 = (Timer1InterruptPriority >> 1) & 0x01;
	IPC0bits.T1IP2 = (Timer1InterruptPriority >> 2) & 0x01;
	IFS0bits.T1IF = 0; // clear flag
	IEC0bits.T1IE = 1; // enable interrupt
	
	T1CONbits.TON = 1; // enable Timer
}

// call this method regularly within a 10ms period to get a multiplexed display
inline void MatrixDisplayMultiplexingTask()
{
	static uint8_t row = 0; // row counter to be incremented within calls to scan across the matrix

	// select the current row and light it up according to the correspondin row in the display buffer
	MATRIXPORT = ((~display[row] & 0x1F) << 7) + (1 << row);

	// proceed to the next row or go back to the first one in the next call
	if (++row >= LED_MATRIX_NUM_OF_ROWS)
		row = 0;
}

// character set for 4x3 pixel numbers
static uint8_t charset4x3[][3] = {
	{ // zero
		0b00011111,
		0b00010001,
		0b00011111
	},{ // one
		0b00000000,
		0b00000010,
		0b00011111
	},{ // two
		0b00011101,
		0b00010101,
		0b00010111
	},{	 // three
		0b00010001,
		0b00010101,
		0b00011111
	},{	 // four
		0b00000111,
		0b00000100,
		0b00011111
	},{	 // five
		0b00010111,
		0b00010101,
		0b00011101
	},{	 // six
		0b00011111,
		0b00010101,
		0b00011101
	},{	 // seven
		0b00000001,
		0b00011101,
		0b00000011
	},{	 // eight
		0b00011111,
		0b00010101,
		0b00011111
	},{	 // nine
		0b00010111,
		0b00010101,
		0b00011111
	},{	 // A
		0b00011111,
		0b00000101,
		0b00011111
	},{	 // B
		0b00011111,
		0b00010100,
		0b00011100
	},{	 // C
		0b00011111,
		0b00010001,
		0b00010001
	},{	 // D
		0b00011100,
		0b00010100,
		0b00011111
	},{	 // E
		0b00011111,
		0b00010101,
		0b00010001
	},{	 // F
		0b00011111,
		0b00000101,
		0b00000001
	}
};

void Display2Digit5x3Num(uint8_t num)
{
	// clamp to 99 (overflow protection)
	if (num > 99)
		num = 99;

	int row;
	for (row = 0; row < 3; row++)
	{
		display[row+4] = charset4x3[(num/10)][2 - row];
		display[row] = charset4x3[(num % 10)][2 - row];
	}
}

void Display2Digit5x3Hex(uint8_t num)
{
	int row;
	for (row = 0; row < 3; row++)
	{
		display[row+4] = charset4x3[(num>>4)][2 - row];
		display[row] = charset4x3[(num & 0x0f)][2 - row];
	}
}