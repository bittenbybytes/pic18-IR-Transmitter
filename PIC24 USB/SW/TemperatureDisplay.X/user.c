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
#include <spi.h>


/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/
void spi1Init(unsigned int prescale){
    OpenSPI1(0x0520 | prescale, 0x0000, 0x8000);
}
/* <Initialize variables in user.h and insert code for user algorithms.> */

/* TODO Initialize User Ports/Peripherals/Project here */

void InitApp(void)
{
    /* Setup analog functionality and port direction */
	(PPSUnLock);

	//PPSOutput(PPS_RP16, PPS_SS1OUT);
	TRISFbits.TRISF3 = 0;
	PORTFbits.RF3 = 1;
	PPSOutput(PPS_RP9, PPS_SCK1OUT);
	PPSOutput(PPS_RP8, PPS_SDO1);
	
    /* Initialize peripherals */
	InitMatrixDisplay();

	spi1Init(0);

	initHD44780LCD();
}