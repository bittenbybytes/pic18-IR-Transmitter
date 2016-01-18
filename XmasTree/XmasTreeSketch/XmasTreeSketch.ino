/*
 * Charlieplexing LED Christmas tree
 * 
 * Creates a soft blink (fade on, fade off)
 * light pattern using 6 LEDs connected to
 * three digital IOs in a Charlieplexing
 * configuration
 */


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

  void off()
  {
    on(-1);
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

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the Charlieplexing IOs
  cpLeds.begin(0, 1, 2);
}

const byte period = 8;
void pulse(byte numLed, byte duty)
{
  if(duty < period)
  {
    cpLeds.on(numLed);
    delay(duty);
    cpLeds.off();
    delay(period - duty);
  }
}

void ledSoftBlink(int ledNum)
{
    for(int i = 0; i < period; i++)
    pulse(ledNum, i);
  
  for(int i = period*2; i > 0; --i)
    pulse(ledNum, i/2);
}


#define PATTERN_LENGTH 16

char pattern[PATTERN_LENGTH] =
{
  0,
  2,
  4,
  -1,
  
  5,
  3,
  1,
  2,

  -1,
  0,
  3,
  5,

  4,
  1,
  -1,
  5
};

unsigned short index = 0;

// the loop routine runs over and over again forever:
void loop() {

  ledSoftBlink(pattern[index]);
  
  index++;
  
  if(index == PATTERN_LENGTH)
    index = 0;

  delay(200);
}
