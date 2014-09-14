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