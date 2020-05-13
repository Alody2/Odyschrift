#include "OdyInput.h"

//schakelaars
int bedenktijd = 2000;
int holdtime = 50;
int _turntime = 50;

int aantal_odytekens = 1;
int odyleft = 47;
int odyright= 49;
int odyup = 53;
int odydown = 51;
int _mDO = 38;
int _mDE = 40;
int _mDI = 42;
int _mDA = 44;
int _mRO = 46;
int _mRE = 48;
int _mRI = 50;
int _mRA = 52;
OdyInput odyinput(odyleft, odyright, odyup,odydown, bedenktijd, holdtime); //contacten van de joystick
#include "FastLED.h"
#define NUM_LEDS 12  // # of LEDS in the strip
CRGB leds[NUM_LEDS];
#define PIN 12 // ZIt op pin 12
#define COLOR_ORDER GRB  // I had to change this for my strip if your color is off then you know.
int fadeAmount = 25;  // Set the amount to fade I usually do 5, 10, 15, 20, 25 etc even up to 255.
int brightness = 0; 
		
String _Odywoord;
int _Odyled;
//---------------------------------------------------------------------------

void setup()
{
  	Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
	FastLED.addLeds<WS2812B, PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); //setup voor de LED strip
       	leds[9] = CRGB(50,5,0); // this sets a really dim processing light loopon the led strip.    
  	leds[10] = CRGB(50,5,0); // this sets a really dim processing light loopon the led strip.
  	leds[11] = CRGB(50,5,0); // this sets a really dim processing light loopon the led strip.
  pinMode(_mDO , OUTPUT); 
  pinMode(_mDE , OUTPUT); 
  pinMode(_mDI , OUTPUT); 
  pinMode(_mDA , OUTPUT); 
  pinMode(_mRO , OUTPUT); 
  pinMode(_mRE , OUTPUT); 
  pinMode(_mRI , OUTPUT); 
  pinMode(_mRA , OUTPUT); 
}

void loop()
{
	for (int i = 6; i <= 7; i++)
	{
		_Odywoord = odyinput.selectieJoystickDigitaal(aantal_odytekens);
		Serial.print(i);
		if (i == 6)
		{
			lichtaan(i);
		}
		if (i == 7)
		{
			if (_Odywoord == "D")
			{
				_Odywoord = "O";	
			}
			else if (_Odywoord == "R" )		
			{
				_Odywoord = "E";
			}
			else if (_Odywoord == "M")		
			{
				_Odywoord = "I";
			}
			else if (_Odywoord == "F") 
			{
				_Odywoord = "A";
			}
			lichtaan(i);
			actie ();
		}
	}
}
//---------------------------------------------------------------------------
void lichtaan(int lichtaan)
{
	if (_Odywoord == "D" || _Odywoord == "O")		
	{
Serial.print ( "in do");
   		leds[lichtaan] = CRGB(200,5,0); // this sets a really dim processing light loopon the led strip.
	}
	else if (_Odywoord == "R" || _Odywoord == "E")		
	{
   	 	leds[lichtaan] = CRGB(5,200,0); // this sets a really dim processing light loopon the led strip.
	}
	else if (_Odywoord == "M" || _Odywoord == "I")		
	{
   	 	leds[lichtaan] = CRGB(5,0,200); // this sets a really dim processing light loopon the led strip.
	}
	else if (_Odywoord == "F" || _Odywoord == "A")		
	{
   	 	leds[lichtaan] = CRGB(100,200,0); // this sets a really dim processing light loopon the led strip.
	}
            FastLED.show();

}
//---------------------------------------------------------------------------
void actie()
{
	if (_Odywoord == "DO")
	{
    		delay (_turntime);
   		digitalWrite (_mDO, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDO, LOW);
	}
	if (_Odywoord == "DE")
	{
    		delay (_turntime);
   		digitalWrite (_mDE, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDE, LOW);
	}
	if (_Odywoord == "DI")
	{
    		delay (_turntime);
   		digitalWrite (_mDI, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDI, LOW);
	}
	if (_Odywoord == "DA")
	{
    		delay (_turntime);
   		digitalWrite (_mDA, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDA, LOW);
	}
	if (_Odywoord == "RO")
	{
    		delay (_turntime);
   		digitalWrite (_mRO, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRO, LOW);
	}
	if (_Odywoord == "RE")
	{
    		delay (_turntime);
   		digitalWrite (_mRE, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRE, LOW);
	}
	if (_Odywoord == "RI")
	{
    		delay (_turntime);
   		digitalWrite (_mRI, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRI, LOW);
	}
	if (_Odywoord == "RA")
	{
    		delay (_turntime);
   		digitalWrite (_mRA, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRA, LOW);
	}
	if (_Odywoord == "FA")
	{
		//naar switchen van module
	}
	_Odywoord = "";

	
} 
