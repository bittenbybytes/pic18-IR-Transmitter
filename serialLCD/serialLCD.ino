#include <Wire.h>

/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// give it a name:
int led = 13;

int pclk = 0;
int sclk = 1;
int ser = 2;

void writeSreg(unsigned char data)
{
  digitalWrite(pclk, LOW);
  digitalWrite(sclk, LOW);
  for(int i=0; i<8; i++)
  {
    digitalWrite(ser, (data & 1<<i));
    digitalWrite(sclk, HIGH);
    digitalWrite(sclk, LOW);
  }
  digitalWrite(pclk, HIGH);
  digitalWrite(pclk, LOW);
}

char reg = 0; // shadow copy of shift register content for read modify write
int lcd_backlight = 7;
int lcd_rs = 6;
int lcd_enable = 5;

void writeSregBit(int nbit, int input)
{
  reg &= ~(1 << nbit); // clear bit
  reg |= ((input !=0) << nbit); // set if input bit is non zero
  writeSreg(reg);
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

void toggleLcdEnable()
{
  writeSregBit(lcd_enable, HIGH);
  writeSregBit(lcd_enable, LOW);
}

void writeLcdByte(int lcdDataNotCommand, unsigned char data)
{
  writeSregBit(lcd_rs, lcdDataNotCommand);
  writeSregLowNibble(data >> 4);
  toggleLcdEnable();
  writeSregLowNibble(data);
  toggleLcdEnable();
}

void writeLcdData(unsigned char data)
{
  writeLcdByte(1, data);
}

void writeLcdCmd(unsigned char cmd)
{
  writeLcdByte(0, cmd);
}

char lcd_4bit_if_cmd = 0x20;
char lcd_cursor = 1;
char lcd_cursor_blink = 1;
char lcd_enable_cmd = 0x0A;
char lcd_on_cmd = 0x0C | lcd_cursor << 1 | lcd_cursor_blink;
char lcd_clear_cmd = 0x01;
char lcd_reset_cursor_pos_cmd = 0x02;
char lcd_csr_cmd = 0x06;

void clearLcd()
{
 writeLcdCmd(lcd_clear_cmd);
 delay(10);
}

void initLcd4bit()
{
  reg=0;
  //writeSregBit(lcd_backlight, 1);
  delay(500);
  // reset sequence
  writeSregBit(lcd_rs, 0); // command
  writeSregLowNibble(0x03);
  toggleLcdEnable();
  delay(5);
  writeSregLowNibble(0x03);
  toggleLcdEnable();
  delay(1);
  writeSregLowNibble(0x03);
  toggleLcdEnable();
  delay(1);
  writeSregLowNibble(0x02);
  toggleLcdEnable();
  delay(1);
  writeLcdCmd(lcd_enable_cmd);
  delay(1);
  clearLcd();
  delay(10);
  writeLcdCmd(lcd_csr_cmd);
  delay(1);
  writeLcdCmd(lcd_on_cmd);
  delay(1);
}

void printStringLcd(const char* str)
{
  int i = 0;
  while(str[i] != '\0' && i < 40)
  {
    writeLcdData(str[i]);
    i++;
    delay(1);
  }
}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(pclk, OUTPUT);    
  pinMode(sclk, OUTPUT);    
  pinMode(ser, OUTPUT);
  initLcd4bit();
  delay(50);
  printStringLcd("Hello World!!!");
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);
  Serial.println("Hello World...");
  delay(1000);  // do not print too fast!
}

float getTempTCN75(int address)
{
  float temp = -999;
  char SENSOR_ADDR = 0x48 | (address & 0x07);
  Wire.beginTransmission(SENSOR_ADDR);
  Wire.write((byte)0x00);
  Wire.requestFrom(SENSOR_ADDR, 2);
  if ( Wire.available() ) {
    temp = Wire.read();
  }
   if ( Wire.available() ) {
    if( Wire.read() & 0x80)
      if(temp >= 0.0)
        temp += 0.5;
      else
        temp -= 0.5;
  }
  Wire.endTransmission();
  return temp;
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  //writeSregBit(lcd_backlight, 1);
  delay(10);               // wait for a second
  writeSregBit(lcd_backlight, 0);
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW

  //clearLcd();
  writeLcdCmd(0x80);
  char str[20] = {0};
  float temp = getTempTCN75(7);
  sprintf(str, "Temp: %2.1f C     ", temp);
  printStringLcd(str);
  Serial.println(str);
  delay(10);               // wait for a second
}
