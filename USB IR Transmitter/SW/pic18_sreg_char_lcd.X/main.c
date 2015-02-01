/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

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

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

#include "../../../Drivers/arduino_GPIO.h"

// pin out definition
const int pclk = 2;
const int sclk = 3;
const int ser = 4;
#include "../../../Drivers/sregCharLCD.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void wait()
{
	for(uint16_t i = 0; i< 0xffff; i++);
}

const unsigned char hbar1[8] = {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10};
const unsigned char hbar2[8] = {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18};
const unsigned char hbar3[8] = {0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C};
const unsigned char hbar4[8] = {0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E};

const unsigned char vbar1[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F};
const unsigned char vbar2[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F};
const unsigned char vbar3[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F};
const unsigned char vbar4[8] = {0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F};
const unsigned char vbar5[8] = {0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};
const unsigned char vbar6[8] = {0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};
const unsigned char vbar7[8] = {0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F};

void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();
	
	initHD44780LCD();
	lcdClear();	

	lcdSetCustomChar(1,hbar1);
	lcdSetCustomChar(2,hbar2);
	lcdSetCustomChar(3,hbar3);
	lcdSetCustomChar(4,hbar4);

	lcdResetCursorPosition();

	lcdPrintStr("Hell:");
	lcdPrintChar(' ');
	lcdPrintChar(0x01);
	lcdPrintChar(0x02);
	lcdPrintChar(0x03);
	lcdPrintChar(0x04);
	lcdPrintChar(0xff);

    /* TODO <INSERT USER APPLICATION CODE HERE> */
	pinMode(LED_PIN, OUTPUT);
	ADCON1bits.PCFG = 0xF;

    while(1)
    {
//		PORTBbits.RB4 = 1;
		digitalWrite(LED_PIN, HIGH);
		wait();
		digitalWrite(LED_PIN, LOW);
		wait();
		
		//lcdClear();
		static unsigned int i =0;
		char str[4] = {0};
		str[0] = ('0' +((i/10000)%10));
		str[1] = ('0' +((i/1000)%10));
		str[2] = ('0' +((i/100)%10));
		str[3] = ('0' +((i/10)%10));
		str[4] = ('0' +((i)%10));
		i++;
		lcdSetCursorPosition(1,2);
		lcdPrintStr(str);
    }

}

