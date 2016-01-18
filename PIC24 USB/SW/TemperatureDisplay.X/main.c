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
#include "i2c2Master.h"

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

unsigned short spi1Write(unsigned short i);

unsigned short readADC(unsigned short ch);

void writeDAC(DacCommand cmd);

void writeReg(uint8_t address, uint8_t data);

const uint8_t IODIRA = 0x00;
const uint8_t IODIRB = 0x01;

const uint8_t IOCON = 0x0A;

const uint8_t GPIOA = 0x12;
const uint8_t GPIOB = 0x13;

const uint8_t GPPUA = 0x0C;
const uint8_t GPPUB = 0x0D;

char numberPattern[] = {
  0x3F, // 0
  0x06, // 1
  0x5B, // 2
  0x4F, // 3
  0x66, // 4
  0x6D, // 5
  0x7D, // 6
  0x07, // 7
  0x7F, // 8
  0x6F, // 9
  0x77, // A
  0x7C, // b
  0x39, // C
  0x5E, // d
  0x79, // E
  0x71 // F
};

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
    
    initI2C2Master();

    writeReg(IODIRA, 0x00);      
    writeReg(IODIRB, 0x00);
    
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
        
 
        writeReg(GPIOA, 0x0F);
        
        writeReg(GPIOB, ~(numberPattern[(num%4)]));  
        
        writeReg(GPIOA, 0x0F & (~(1 << (num%4))));
            
	}
}


void writeReg(uint8_t address, uint8_t data)
{
    I2Cwrite((0x20 + 0x07) << 1, address, data);
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