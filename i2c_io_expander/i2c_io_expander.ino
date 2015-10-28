// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void write(byte address, byte data)
{
  Wire.beginTransmission(32); // transmit to device #4
  Wire.write(address);              // sends reg address
  Wire.write(data);              // sends reg value
  Wire.endTransmission();    // stop transmitting
}

byte read(byte address)
{
  Wire.beginTransmission(32); // transmit to device #4
  Wire.write(address);              // sends reg address
  Wire.endTransmission();    // stop transmitting
  
  Wire.requestFrom(32,1);              // sends reg value
  
  while(Wire.available())    // slave may send less than requested
  {
     return Wire.read();
  }
}


void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  write(0x00, 0xFC);
  write(0x06, 0x80);
}

void loop()
{
  if(read(0x09) & 0x80)
    write(0x09, 0x01); 
  delay(100);
  write(0x09, 0x02);
  delay(100);
}
