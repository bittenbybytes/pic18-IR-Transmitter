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

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT);  
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(A0, OUTPUT);  
  pinMode(A1, OUTPUT); 
}

int muxFrequ = 100;

int tMux = 1000/muxFrequ;

int SEG_DP = 6;
int SEG_g = 5;
int SEG_f = 4;
int SEG_e = 8;
int SEG_d = 9;
int SEG_c = 7;
int SEG_b = 2;
int SEG_a = 3;

class CPLeds
{
  public:
  void begin( int a, int b,  int c)
  {
    A=a;
    B=b;
    C=c;
  }
  
  void on(int ledNum)
  {
    switch(ledNum)
    {
      case 0:
        writeZHiLow(C, B, A);
        break;
      
      case 1:
        writeZHiLow(C, A, B);
        break;
      
      case 2:
        writeZHiLow(A, C, B);
        break;
      
      case 3:
        writeZHiLow(A, B, C);
        break;
        
      case 4:
        writeZHiLow(B, C, A);
        break;
        
      case 5:
        writeZHiLow(B, A, C);
        break;
        
      default:
        pinMode(A, INPUT);
        pinMode(B, INPUT);
        pinMode(C, INPUT);
        break;
    }
  }
  
  private:
  void writeZHiLow(int z, int hi, int low)
  {
    pinMode(z, INPUT);
    digitalWrite(hi, HIGH);
    pinMode(hi, OUTPUT);
    digitalWrite(low, LOW);
    pinMode(low, OUTPUT);
  }

  int A;
  int B;
  int C;
  
}cpLeds;



void outputDigit(char digitPattern)
{
  digitalWrite(SEG_DP, !(digitPattern & (1 << 0)));
  digitalWrite(SEG_g, !(digitPattern & (1 << 1)));
  digitalWrite(SEG_f, !(digitPattern & (1 << 2)));
  digitalWrite(SEG_e, !(digitPattern & (1 << 3)));
  digitalWrite(SEG_d, !(digitPattern & (1 << 4)));
  digitalWrite(SEG_c, !(digitPattern & (1 << 5)));
  digitalWrite(SEG_b, !(digitPattern & (1 << 6)));
  digitalWrite(SEG_a, !(digitPattern & (1 << 7)));
  
  cpLeds.begin(13, 12, 11);
}

char numberPattern[] = {
  0xFC, // 0
  0x60, // 1
  0xDA, // 2
  0xF2, // 3
  0x66, // 4
  0xB6, // 5
  0xBE, // 6
  0xE0, // 7
  0xFE, // 8
  0xF6, // 9
  0xEE, // A
  0x3E, // b
  0x9C, // C
  0x7A, // d
  0x9E, // E
  0x8E // F
};

char minusSign = 0x02;

char decimalPoint = 0x01;

unsigned short cnt = 0;
unsigned short toggle = 0;

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(A1, HIGH);
  outputDigit(numberPattern[(cnt>>4) & 0xf]);
  digitalWrite(A0, LOW); 
  delay(tMux);
  
  digitalWrite(A0, HIGH);
  outputDigit(numberPattern[cnt & 0xf]+ (toggle % 4 == 0));
  digitalWrite(A1, LOW);  
  delay(tMux); 
  
  toggle++;
  if(toggle % 4 == 0)
    cnt++;
    
  if(toggle % 16 == 0)
  {
    cpLeds.on((toggle/16) % 8);
  }
}
