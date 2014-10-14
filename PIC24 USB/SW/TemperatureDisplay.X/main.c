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

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

unsigned short spi1Write( unsigned short i );

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int16_t main(void)
{

    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();

    /* TODO <INSERT USER APPLICATION CODE HERE> */
    CLKDIVbits.RCDIV0=0;     //clock divider to 0
    AD1PCFG = 0xFFFF;        // Default all pins to digital
    OSCCONbits.SOSCEN=0;     //Disables the secondary oscilator


	AD1PCFGLbits.PCFG11 = 0;  //Disable digital input on AN11

	AD1CON1bits.SSRC  = 0b111;     // SSRC<3:0> = 111 implies internal
								   // counter ends sampling and starts
								   // converting.
	AD1CON3 = 0x1F02;              // Sample time = 31Tad,
								   // Tad = 2 Tcy
	AD1CHS = 11;

	AD1CON1bits.ADON = 1;           // turn ADC on

	volatile uint16_t num = 0;

	lcdPrint("Start");
	
	while(1)
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

		PORTFbits.RF3 = 0;
		spi1Write(cmd.raw);
//		spi1Write(cmd.hiByte);
//		spi1Write(cmd.loByte);
		PORTFbits.RF3 = 1;

		cmd.notA_B = true;
		cmd.data = 0xfff - cmd.data;

		PORTFbits.RF3 = 0;
		spi1Write(cmd.raw);
//		spi1Write(cmd.hiByte);
//		spi1Write(cmd.loByte);
		PORTFbits.RF3 = 1;

		AD1CON1bits.DONE=0;         //resets DONE bit
		AD1CON1bits.SAMP=1;         //start sample
		while(!AD1CON1bits.DONE);
		uint16_t result = ADC1BUF0;
		uint16_t voltage = ((uint32_t)(result) * 3300) / 1023;
		uint8_t temp = (((voltage - 500) / 5) + 1) / 2;
		Display2Digit5x3Num(temp);
		
		//lcdClear();
		lcdResetCursorPosition();
		
		char tmpStr[] = {'T','e','m','p',' ', 0x30+((temp/10)%10), 0x30+temp%10,
		' ', ' ', /*0x30+(num/10000)%10, 0x30+(num/1000)%10,*/ 0x30+(num/100)%10, 0x30+(num/10)%10, 0x30+num%10, '\0'};
		lcdPrint(tmpStr);
		//Display2Digit5x3Num(num++);
		volatile uint16_t i = 0;
		for (i = 0; i < 0xffff; i++);
	}
}



// send one byte of data and receive one back at the same time
unsigned short spi1Write( unsigned short i )
{
    // write to buffer for TX, wait for transfer, read
    SPI1BUF = i;
    while(!SPI1STATbits.SPIRBF);
    return SPI1BUF;
}//spiWrite2