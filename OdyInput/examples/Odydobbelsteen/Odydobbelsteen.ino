#include "OdyInput.h"

#include <LiquidCrystal_I2C.h> // include the library code
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal_I2C lcd (0x27, 20, 4);
// Connect the I2C LCD to the SDA en SCL pin on the Arduino Mega!
#include "FastLED.h"
#define NUM_LEDS 12  // # of LEDS in the strip
CRGB leds[NUM_LEDS];
//schakelaars
int bedenktijd = 500;
int teller; 
int holdtime = 50;
int _turntime = 50;

int aantal_odytekens = 1;
int odyleft = 47;
int odyright= 49;
int odyup = 53;
int odydown = 51;
OdyInput odyinput(odyleft, odyright, odyup,odydown, bedenktijd, holdtime); //contacten van de joystick
boolean afrollen;                   // waar als de tekst afgerold moet worden
String tekst;                       //catches the text to print to the lcd-screen
int lengteTekst;                    //lengte van tekst, om de tekst af te kunnen rollen
int cursorKolom;                    //waar op de regel start de tekst
int cursorRij;                      //op welke regel start de tekst
boolean laatstaan;                  //waar als de tekst niet wordt weggepoetst na de pauze
int wachten;                        //bepaalt of en hoe lang gewacht wordt op de volgende tekst
boolean firstGroup = true;          // This Boolean is used for zooming in on the group DRMF, or the group AOEI
int readtime = 3000;                // Sets the time the info will be on the screen for Elinde's written messages
#define PIN 12 // ZIt op pin 12
#define COLOR_ORDER GRB  // I had to change this for my strip if your color is off then you know.
int fadeAmount = 25;  // Set the amount to fade I usually do 5, 10, 15, 20, 25 etc even up to 255.
int brightness = 0; 

int i = 6;		
String _Odyteken;
String _Odywoord;
char letter;
String woord;
int _Odynummer;
int _Odyled;
int cursorBasis;
int oog;
long lngWorp = 0;
long lngHerhaal= 0;
int plaats;
int rood;
int groen;
int blauw;
//---------------------------------------------------------------------------

void setup()
{
  	Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
	FastLED.addLeds<WS2812B, PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); //setup voor de LED strip
	lcd.init();
	lcd.backlight();
	randomSeed (analogRead(4));
  	tekst = "LATEN WE DOBBELEN"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
	tekst = "D: 1 dobbelsteen"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  	tekst = "R: 2 dobbelstenen"; cursorKolom = 0 ; cursorRij = 2;  afrollen = false; wachten = 0; laatstaan = true; lcd_print();    
	tekst = "M: zet "; cursorKolom = 0 ; cursorRij =3; afrollen = false; wachten = 0; laatstaan = true; lcd_print(); 
//	tekst = "F:schakel"; cursorKolom = 11 ; cursorRij =3; afrollen = false; wachten = 0; laatstaan = true; lcd_print(); 
       	leds[9] = CRGB(50,5,0); //     
  	leds[10] = CRGB(50,5,0); // 
  	leds[11] = CRGB(0,0,50); //
	cursorRij = 0; 
	FastLED.show();
	delay(3000);
	FastLED.clear();
	lcd.clear();
}

void loop()
{
	odyinput.selectieDRMF();
	if (odyinput.Odyteken == 'N')
	{
	}
	else if (odyinput.Odyteken == 'M')
	{

		while (odyinput.Odyteken == 'M')
		{
			odyinput.selectieOEIA();
			lcd.setCursor(0, 0);
	  		lcd.print ("pion ?");
		}
		while (odyinput.Odyteken == 'N')
		{
			odyinput.selectieOEIA();
		}
		if (odyinput.Odyteken == 'O')
		{
  			tekst = "MO"; 
			while (odyinput.Odyteken == 'O')
			{
				teller = 1;
				wissel();
			}
		}
		else if (odyinput.Odyteken == 'E')
		{
  			tekst = "ME"; 
			while (odyinput.Odyteken == 'E')
			{
				teller = 1;
				wissel();
			}
		}
		else if (odyinput.Odyteken == 'I')
		{
  			tekst = "MI"; 
			while (odyinput.Odyteken == 'I')
			{
				teller = 1;
				wissel();
			}
		}
		else if (odyinput.Odyteken == 'A')
		{
  			tekst = "MA"; 
			while (odyinput.Odyteken == 'A')
			{
				teller = 1;
				wissel();
			}
		}
		while (odyinput.Odyteken == 'N')
		{
			delay(holdtime);
			odyinput.selectieDRMF();
		}
		
	}
	else if (odyinput.Odyteken == 'F')
	{
		
	}
	else
	{
		lichtaan();
	}
}
//---------------------------------------------------------------------------
void wissel()
{
	odyinput.selectieOEIA();
	if (teller == 1)
	{
		if (firstGroup == true)
		{
			firstGroup = false;
			cursorKolom = 0;
			cursorRij = 0;
			tekst = "zet 1: " + tekst; 
		  	afrollen = true; wachten = 0; laatstaan = true;     
			lcd_print();    
			teller = 2;
		}
		else
		{	firstGroup = true;
			cursorKolom = 14;
			cursorRij = 0;
			tekst = "zet 2: " + tekst; 
		  	afrollen = true; wachten = 0; laatstaan = true;     
			lcd_print();    
			teller = 2;
		}
	}
}
//---------------------------------------------------------------------------
void lichtaan()
{
	if (odyinput.Odyteken == 'D')
	{
		lngWorp = 0;
		lcd.clear(); 
		plaats = -2;
		lngHerhaal = random(1,10);
		bedenktijd = random(500,3000);
		while (lngHerhaal > 0)
		{
			lngWorp = random(1,7);
			rood = random(1,200);
			groen = random(1,200);
			blauw = random(1,200);
			plaats += 2;
			if (lngHerhaal > 0)
			{
				delay (bedenktijd); 
				for (int i = 0;i <= 6; i++)
				{
					leds[i] = CRGB::Black;  
						
				}
			}
  		//	tekst = lngHerhaal; cursorKolom = plaats  ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  			tekst = lngWorp; cursorKolom = plaats  ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
			delay(holdtime);
			while (lngWorp > 0)
			{
				leds[lngWorp - 1] = CRGB(rood,groen,blauw);  
				lngWorp -= 1;
			}
			FastLED.show();
			lngHerhaal -= 1;
		}
	}
	if (odyinput.Odyteken == 'R')
	{
		lngWorp = 0;
		lcd.clear(); 
		FastLED.clear();
		plaats = -2;
		lngHerhaal = random(1,10);
		bedenktijd = random(500,4000);
		while (lngHerhaal > 0)
		{
			lngWorp = random(1,7);
			rood = random(1,200);
			groen = random(1,200);
			blauw = random(1,200);
			plaats += 2;
			if (lngHerhaal > 1)
			{
				delay (bedenktijd); 
				for (int i = 0;i <= 6; i++)
				{
					leds[i] = CRGB::Black;  
						
				}
  				tekst = lngWorp; cursorKolom = plaats  ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
				while (lngWorp > 0)
				{
					leds[lngWorp - 1] = CRGB(rood,groen,blauw);  
					lngWorp -= 1;
				}
			}
  		//	tekst = lngHerhaal; cursorKolom = plaats  ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
			FastLED.show();
			lngHerhaal -= 1;
		}
		plaats = -2;
		lngHerhaal = random(1,10);
		while (lngHerhaal > 0)
		{
			lngWorp = random(1,7);
			rood = random(1,200);
			groen = random(1,200);
			blauw = random(1,200);
			plaats += 2;
			if (lngHerhaal > 1)
			{
				delay (bedenktijd); 
				for (int i = 6;i <= 11; i++)
				{
					leds[i] = CRGB::Black;  
						
				}
  				tekst = lngWorp; cursorKolom = plaats  ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
				while (lngWorp > 0)
				{
					leds[lngWorp + 5] = CRGB(rood,groen,blauw);  
					lngWorp -= 1;
				}
			}
  		//	tekst = lngHerhaal; cursorKolom = plaats  ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
			FastLED.show();
			lngHerhaal -= 1;
		}
	}
	FastLED.show();
	delay(holdtime);
}
//---------------------------------------------------------------------------

void lcd_print()
{ 
  
  /* 
  This is function that can be called to regulate printing to the I2C-lcd-screen  
  */            
	lcd.setCursor(cursorKolom, cursorRij);
	lengteTekst = tekst.length();
	
	if (afrollen == true)
	{ // This part executes what needs to happen to have the "afrollen" effect
	
	    	for (int i = 0; i < lengteTekst; i++) 
		{
	      		delay(70); // this sets the time it takes between letter appearing
			lcd.print(tekst.charAt(i));   // Print a message to the LCD.
	    	}
	} 
	 
	else 	
	{
	  	lcd.print (tekst);
	} 
	
	while (wachten > 1) 
	{
	  	delay(500);            // wait X amount of Milli-sec
	  	wachten = wachten - 1;
	}
	
	if (laatstaan == false)
	{
		lcd.clear(); // clear
  	}
}
