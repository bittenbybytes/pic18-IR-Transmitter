
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

void writeSregBit(int nbit, int input)
{
  sregData &= ~(1 << nbit); // clear bit
  sregData |= ((input !=0) << nbit); // set if input bit is non zero
  writeSreg(sregData);
}

void  writeSregLowNibble(int nibble)
{
  int reverseNibble = 0;
  for(int i =0; i < 4; i++)
  {
    reverseNibble |= (nibble & 1 << i) ? 1 << (3-i):0;
  }

  reg &= 0xF0; // clear nibble
  reg |= reverseNibble & 0x0F; // write input nibble
  writeSreg(reg);
}

void writeSreg(unsigned char data)
{
	digitalWrite(pclk, LOW);
	digitalWrite(sclk, LOW);
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(ser, (data & 1 << i));
		digitalWrite(sclk, HIGH);
		digitalWrite(sclk, LOW);
	}
	digitalWrite(pclk, HIGH);
	digitalWrite(pclk, LOW);

	// update shadow register
	sregData = data;
}
