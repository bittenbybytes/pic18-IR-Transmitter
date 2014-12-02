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
#include "delays.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

#define LED_TRIS TRISCbits.RC2
#define LED_PIN PORTCbits.RC2

const int clk = 48000000;

#define DELAY_NS(ns) (_delay(ns/83))

#define T0H 400
#define T1H 1100
#define T0L 2000
#define T1L 1300

//#define T0H 000
//#define T1H 100
//#define T0L 100
//#define T1L 000

#define DELAY_H(x) ((x)? _delay(7) : _delay(1))
#define DELAY_L(x) ((x)? _delay(1) : _delay(7))

sendbyte(uint8_t in)
{
	LED_PIN = 1;
	DELAY_H(in & 1 << 7);
	LED_PIN = 0;
	DELAY_L(in & 1 << 7);

	LED_PIN = 1;
	DELAY_H(in & 1 << 6);
	LED_PIN = 0;
	DELAY_L(in & 1 << 6);

	LED_PIN = 1;
	DELAY_H(in & 1 << 5);
	LED_PIN = 0;
	DELAY_L(in & 1 << 5);

	LED_PIN = 1;
	DELAY_H(in & 1 << 4);
	LED_PIN = 0;
	DELAY_L(in & 1 << 4);


	LED_PIN = 1;
	DELAY_H(in & 1 << 3);
	LED_PIN = 0;
	DELAY_L(in & 1 << 3);

	LED_PIN = 1;
	DELAY_H(in & 1 << 2);
	LED_PIN = 0;
	DELAY_L(in & 1 << 2);

	LED_PIN = 1;
	DELAY_H(in & 1 << 1);
	LED_PIN = 0;
	DELAY_L(in & 1 << 1);

	LED_PIN = 1;
	DELAY_H(in & 1 << 0);
	LED_PIN = 0;
	DELAY_L(in & 1 << 0);


}

void sendRGB(uint8_t r, uint8_t g, uint8_t b)
{
	LED_TRIS = 0;
	sendbyte(g);
	sendbyte(r);
	sendbyte(b);
}

uint8_t stripr[60];
uint8_t stripg[60];
uint8_t stripb[60];

void delay_ms(uint32_t delay)
{
	for(uint32_t i = 0; i < delay; i++)
		Delay100TCYx((clk/4)/100000);
}

#define floatToQ15(f) ((int)(f*65536.0))

uint16_t start[4] = { floatToQ15(1-0.1),
					floatToQ15(1-0.3),
					floatToQ15(1-0.5),
					floatToQ15(1-0.2)};

void main(void)
{
	/* Configure the oscillator for the device */
	ConfigureOscillator();

	/* Initialize I/O and Peripherals for application */
	InitApp();

	/* TODO <INSERT
	 * USER APPLICATION CODE HERE> */

	TRISBbits.TRISB4 = 0;
	ADCON1bits.PCFG = 0x0;

	LED_TRIS = 0;
	LED_PIN = 0;
	unsigned led = 0;
	//LED Show
	LED_PIN = 0;
	Delay10KTCYx(200);

//	for (int i = 0; i < 30; i++)
//	{
//		strip[i * 3] = (i * 4);
//		strip[i * 3 +1] = (i * 16);
//		strip[i * 3 +2] = ((30 - i)*8);
//	}
//
//	for (int i = 0; i < 30; i++)
//	{
//		strip[(i+30)*3] = ((i + 30)*4);
//		strip[(i+30)*3 +1] = (i * 16);
//		strip[(i+30)*3 +2] = (i * 8);
//	}

	for (int i = 0; i < 60; i++)
	{
		uint16_t val = (i/3)*4;
		val *= val;
		stripr[i] = val >> 8;
		stripg[i] = val >> 8;
		stripb[i] = val >> 8;
	}
		

//	for(int i = 0; i < 3; i++)
//	{
//		strip[i*3+0] = (255*i/3);
//		strip[i*3+1] = (255*i/3);
//		strip[i*3+2] = (255*i/3);
//
//		strip[i*3+0+3] = (255*(3-i)/3);
//		strip[i*3+1+3] = (255*(3-i)/3);
//		strip[i*3+2+3] = (255*(3-i)/3);
//	}
	uint16_t pos = UINT16_MAX;
	while (1)
	{
		const uint16_t scale = (uint16_t)( 60.0);
		uint16_t scaledPos = ((uint32_t)(pos) * (uint32_t)(scale)) >> 8;
		uint16_t fPos = scaledPos & 0xff;
		uint16_t iPos = scaledPos >> 8;

		for(int i = 0; i < 60; i++)
		{
			uint16_t pixel = 0;

			if(i == iPos)
				pixel = (0x00FF * (0x00FF - fPos)) >> 8;

			if(i == iPos+1)
				pixel = (0x00FF * fPos) >> 8;

			uint8_t pixelCorr = pixel; //(pixel * pixel) >> 8;
			pixelCorr /= 4;

			stripr[i] = pixelCorr;
			stripg[i] = pixelCorr;
			stripb[i] = pixelCorr;
		}

		for(int i = 0; i < 60; i++)
		{
			sendRGB(stripr[i], stripg[i], stripb[i]);
		}

		//LED Show
		LED_PIN = 0;
		
		delay_ms(1);
		pos -= 30;
		static uint8_t x = 0;
		if(pos<=(30))
			pos = start[x++%4];

	}

}

