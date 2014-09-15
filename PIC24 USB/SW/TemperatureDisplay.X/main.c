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

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

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

    // fill display with a pattern
    uint32_t i;
    for (i = 0; i < LED_MATRIX_NUM_OF_ROWS; i++)
    {
            display[i] = 1 << (i%5);
    }

    for (i = 0; i < 0xffff; i++);

   AD1PCFGLbits.PCFG11 = 0;  //Disable digital input on AN11

   AD1CON1bits.SSRC  = 0b111;     // SSRC<3:0> = 111 implies internal
                                   // counter ends sampling and starts
                                   // converting.
   AD1CON3 = 0x1F02;              // Sample time = 31Tad,
                                   // Tad = 2 Tcy
   AD1CHS = 11;

   AD1CON1bits.ADON =1;           // turn ADC on

    // clear display
    for (i = 0; i < LED_MATRIX_NUM_OF_ROWS; i++)
    {
        display[i] = 0;
    }

    uint8_t num = 0;

    while(1)
    {
        AD1CON1bits.DONE=0;         //resets DONE bit
        AD1CON1bits.SAMP=1;         //start sample
        while(!AD1CON1bits.DONE);
        uint16_t result = ADC1BUF0;
        uint16_t voltage = ((uint32_t)(result) * 3300) / 1023;
        uint8_t temp = (((voltage - 500) / 5) + 1) / 2;
        Display2Digit5x3Num(temp);
        //Display2Digit5x3Num(num++);
        for (i = 0; i < 0xffff; i++);
    }
}
