// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

const int slaveAddress = 0x20 + 7; // base address + address pin setting

const byte IODIRA = 0x00;
const byte IODIRB = 0x01;

const byte IOCON = 0x0A;

const byte GPIOA = 0x12;
const byte GPIOB = 0x13;

const byte GPPUA = 0x0C;
const byte GPPUB = 0x0D;

void write(byte address, byte data)
{
  Wire.beginTransmission(slaveAddress); // transmit to device #4
  Wire.write(address);              // sends reg address
  Wire.write(data);              // sends reg value
  Wire.endTransmission();    // stop transmitting
}

byte read(byte address)
{
  Wire.beginTransmission(slaveAddress); // transmit to device #4
  Wire.write(address);              // sends reg address
  Wire.endTransmission();    // stop transmitting
  
  Wire.requestFrom(slaveAddress,1);              // sends reg value
  
  while(Wire.available())    // slave may send less than requested
  {
     return Wire.read();
  }
}

void writeDigit(int digit, byte pattern)
{
  write(GPIOB, 0xFF); // all segments off (last digit)
  write(GPIOA, ~(1 << digit)); // select digit
  write(GPIOB, ~(pattern)); // write digit
}

char numberPattern[] = {
  0x3F, // 0
  0x06, // 1
  0x5B, // 2
  0x4F, // 3
  0x66, // 4
  0x6D, // 5
  0x7D, // 6
  0x07, // 7
  0x7F, // 8
  0x6F, // 9
  0x77, // A
  0x7C, // b
  0x39, // C
  0x5E, // d
  0x79, // E
  0x71 // F
};

char minusSign = 0x02;

char decimalPoint = 0x80;

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  write(IODIRA, 0x00);
  write(IODIRB, 0x00);
  write(GPPUA, 0xff);
  write(GPPUB, 0xff);
  pinMode(13, OUTPUT);
  write(GPIOA, 0x7);
  write(GPIOB, 0x00);
  while(1);
}

char displayBuffer[4] = {
  numberPattern[0xD],
  numberPattern[0xA],
  numberPattern[0xE],
  numberPattern[0xD]
};

void display(unsigned int val)
{
  if(val > 9999)
  {
    for(int i =0; i<4; i++)
      displayBuffer[i] = numberPattern[0xE];
   
    return;
  }

  char d;
  
  d = val / 1000;
  val -= d * 1000;
  displayBuffer[3] = numberPattern[d];
  
  d = val / 100;
  val -= d * 100;
  displayBuffer[2] = numberPattern[d];
  
  d = val / 10;
  val -= d * 10;
  displayBuffer[1] = numberPattern[d];
  
  d = val;
  displayBuffer[0] = numberPattern[d];
  
}

void display(float val)
{
  if(val > 9999.0)
  {
    for(int i =0; i<4; i++)
      displayBuffer[i] = numberPattern[0xE];
    
    return;
  }
  
  if(val >= 1000)
  {
    display((unsigned int)(val));
    displayBuffer[0] += decimalPoint;
  }
  else if(val >= 100)
  {
    display((unsigned int)(val * 10));
    displayBuffer[1] += decimalPoint;
  }
  else if(val >= 10)
  {
    display((unsigned int)(val * 100));
    displayBuffer[2] += decimalPoint;
  }
  else if(val >= 0.001)
  {
    display((unsigned int)(val * 1000));
    displayBuffer[3] += decimalPoint;
  }
  else if(val >= 0.0)
  {
    display((unsigned int)(0));
    displayBuffer[3] += decimalPoint;
  }
  
}

void displayHex(unsigned short val)
{
  for(int i =0; i<4; i++)
      displayBuffer[i] = numberPattern[(val >> (i*4)) & 0x0f];
}

short x = 0;
void loop()
{
  digitalWrite(13, 1);
  for(int i =0; i<4; i++)
  {
    writeDigit(i, displayBuffer[i]);
    delay(3);
  }
  
  if((x++ % 8) == 0)
    display((analogRead(A0)*4.86f / 1024.0f));
}
