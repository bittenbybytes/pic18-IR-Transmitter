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

#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */

#include "LedMatrixDisplay.h"
#include <spi.h>

#include "mcp_spi_dac.h"

#include "char_lcd_hd44780.h"

#include <outcompare.h>
#include <PPS.h>

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

unsigned short spi1Write(unsigned short i);

unsigned short readADC(unsigned short ch);

void writeDAC(DacCommand cmd);

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/
#define OC1CON_init 0b0000000000000110

int16_t main(void)
{

	/* Configure the oscillator for the device */
	ConfigureOscillator();

	/* Initialize IO ports and peripherals */
	InitApp();

	/* TODO <INSERT USER APPLICATION CODE HERE> */
	CLKDIVbits.RCDIV0 = 0; //clock divider to 0

	OSCCONbits.SOSCEN = 0; //Disables the secondary oscilator

	volatile uint16_t num = 0;

	TRISFbits.TRISF1 = 0;

	lcdPrint("Start");

	while (1)
	{
		DacCommand cmd;
		cmd.noOutputGain = true;
		cmd.notA_B = false;
		cmd.notShutdown = true;
		cmd.data = num & 0xFFF;
		if (num < 0xFFF)
			num++;
		else
			num = 0;

		//if(num % 2)
		{
			if (OC1R > 1500*4)
				OC1R = 600*4;
			else
				OC1R += 1;
		}

		PORTFbits.RF3 = 0;
		spi1Write(cmd.raw);
		PORTFbits.RF3 = 1;

		cmd.notA_B = true;
		cmd.data = 0xfff - cmd.data;

		PORTFbits.RF3 = 0;
		spi1Write(cmd.raw);
		PORTFbits.RF3 = 1;

		uint16_t result = readADC(11);
		int16_t voltage = ((uint32_t) (result) * 3300) / 1023;
		int8_t temp = (((voltage - 500) / 5) + 1) / 2;
		Display2Digit5x3Num(temp);

		//lcdClear();
		//lcdResetCursorPosition();

		//char tmpStr[] = {'T', 'e', 'm', 'p', ' ', 0x30 + ((temp / 10) % 10), 0x30 + temp % 10, \
			' ', ' ', /*0x30+(num/10000)%10, 0x30+(num/1000)%10,*/ 0x30 + (num / 100) % 10, 0x30 + (num / 10) % 10, 0x30 + num % 10, '\0'};
		//lcdPrint(tmpStr);
		//Display2Digit5x3Num(num++);
		volatile uint16_t i = 0;
		for (i = 0; i < 0x03ff; i++);
		if(!(num % 256))
			PORTFbits.RF1 = !PORTFbits.RF1;
	}
}

// send one byte of data and receive one back at the same time

unsigned short spi1Write(unsigned short i)
{
	// write to buffer for TX, wait for transfer, read
	SPI1BUF = i;
	while (!SPI1STATbits.SPIRBF);
	return SPI1BUF;
}//spiWrite2

unsigned short readADC(unsigned short ch)
{

	// select channel
	AD1CHS = ch;

	AD1CON1bits.DONE = 0; //resets DONE bit
	AD1CON1bits.SAMP = 1; //start sample
	while (!AD1CON1bits.DONE);
	return ADC1BUF0;
}

void writeDAC(DacCommand cmd)
{
	PORTFbits.RF3 = 0;
	spi1Write(cmd.raw);
	PORTFbits.RF3 = 1;
}