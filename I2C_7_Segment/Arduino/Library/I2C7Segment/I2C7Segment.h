#ifndef I2C7Segment_h
#define I2C7Segment_h

#include "Arduino.h"

class I2C7Segment
{
public:
	I2C7Segment(const char addressSetting);
	void begin();
	void display(unsigned int val);
	void display(float val);
	void displayHex(unsigned short val);
	void writeDigit(byte num);
	
private:
	byte read(byte address);
	void write(byte address, byte data);
	int _slaveAddress;
	char _displayBuffer[4];
};

#endif
