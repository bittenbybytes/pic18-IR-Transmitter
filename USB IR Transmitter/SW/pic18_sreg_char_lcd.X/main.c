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
//#include "../../../Drivers/sreg74HC595N_driver.h"
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

void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

	initHD44780LCD();
	lcdClear();
	lcdPrint("Hello World!!!");

    /* TODO <INSERT USER APPLICATION CODE HERE> */

	pinMode(LED_PIN, OUTPUT);

	initSregIO();

    while(1)
    {
//		PORTBbits.RB4 = 1;
		digitalWrite(LED_PIN, HIGH);
		wait();
		digitalWrite(LED_PIN, LOW);
		wait();
		
		//lcdClear();
		//lcdPrint("Hello World!!!");
    }

}

