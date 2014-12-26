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

#include <PPS.h>

#include <stdint.h>          /* For uint32_t definition */
#include <stdbool.h>         /* For true/false definition */

#include "user.h"            /* variables/params used by user.c */

#include "LedMatrixDisplay.h"
#include "char_lcd_hd44780.h"
#define USE_AND_OR
#include <spi.h>
#include <adc.h>

/******************************************************************************/
/* User Functions                                                             */

/******************************************************************************/
void spi1Init(unsigned int prescale)
{
	OpenSPI1(0x0520 | prescale, 0x0000, 0x8000);
}

void initPWM()
{
	uint32_t clock = 48e6;
	//RPOR3bits.RP7R = 0b10010;
	PPSOutput(PPS_RP21, PPS_OC1);
	TRISGbits.TRISG6 = 0;

	T3CONbits.TCKPS = 0b01; // 1:8 Prescale
	T3CONbits.TON = 1;

	uint32_t clockPWM = (clock/2)/8;

	/* Reset PWM */
	OC1CON1 = 0x0000;
	OC1CON2 = 0x0000;

	/* set PWM for servo mid position (1.5ms high, 20ms period) */
	OC1R = clock/(1000 / 1.5); /* set the duty cycle */
	OC1RS = clockPWM/(1000 / 20);  /* set the period */

	/* configure PWM */
	OC1CON2 = 0x001f; /* 0x001F = Sync with This OC module                               */
	OC1CON1 = 0x0400 /* 0x0400 => src=Timer3 */;

	/* enable the PWM */
	OC1CON1 |= 0x0006; /* Mode 6, Edge-aligned PWM Mode */
}

void initADC()
{
	AD1CON1bits.SSRC = 0b111; // SSRC<3:0> = 111 implies internal
	// counter ends sampling and starts
	// converting.
	AD1CON3 = 0x1F00 | ADC_CONV_CLK_64Tcy; // Sample time = 31Tad

	AD1CON1bits.ADON = 1; // turn ADC on
}

/* <Initialize variables in user.h and insert code for user algorithms.> */

/* TODO Initialize User Ports/Peripherals/Project here */

void InitApp(void)
{
	/* Setup analog functionality and port direction */
	(PPSUnLock);

	TRISFbits.TRISF3 = 0;
	PORTFbits.RF3 = 1;
	PPSOutput(PPS_RP9, PPS_SCK1OUT);
	PPSOutput(PPS_RP8, PPS_SDO1);

	AD1PCFG = 0xFFFF; // Default all pins to digital

	AD1PCFGLbits.PCFG11 = 0; //Disable digital input on AN11

	/* Initialize peripherals */
	InitMatrixDisplay();

	spi1Init(PRI_PRESCAL_1_1);

	initHD44780LCD();

	initPWM();

	initADC();
}