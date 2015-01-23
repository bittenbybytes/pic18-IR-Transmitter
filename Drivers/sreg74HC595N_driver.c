
#include "sreg74HC595N_driver.h"

static char sregData = 0x00; // shadow register for bit manipulation
						// (shift register is read only, so read modify write back not possible)

void initSregIO()
{
	// set shift register communication pins to output
	pinMode(pclk, OUTPUT);
	pinMode(sclk, OUTPUT);
	pinMode(ser, OUTPUT);
	
	// initialize shadow registers
	sregData = 0x00;
}

void writeSregBit(char nbit, char input)
{
  sregData &= ~(1 << nbit); // clear bit
  sregData |= ((input !=0) << nbit); // set if input bit is non zero
  writeSreg(sregData);
}

void  writeSregLowNibble(char nibble)
{
  int reverseNibble = 0;
  for(char i =0; i < 4; i++)
  {
    reverseNibble |= (nibble & 1 << i) ? 1 << (3-i):0;
  }

  sregData &= 0xF0; // clear nibble
  sregData |= reverseNibble & 0x0F; // write input nibble
  writeSreg(sregData);
}

void writeSreg(unsigned char data)
{
	digitalWrite(pclk, LOW);
	digitalWrite(sclk, LOW);
	for (char i = 0; i < 8; i++)
	{
		digitalWrite(ser, (data & (1 << i))!=0);
		digitalWrite(sclk, HIGH);
		digitalWrite(sclk, LOW);
	}
	digitalWrite(pclk, HIGH);
	digitalWrite(pclk, LOW);

	// update shadow register
	sregData = data;
}
