 
/* 
This library is the center of the Ody project.  Ody is an input method. It uses 4 different impulses, in two flavours. It has been originally created by Alle v Meeteren and Jurre Ongering on spring 2020. 

 * The first implementation is a joystick which can can sense activation on a single contact (allowing 4 directions)  or 2 contacts (allowing for 4 directions between the other 4 directions) at a time.
 * In the neutral state none of these is active. In our implementation the joystick has to return to that neutral state, before the next direction can be chosen.
 * We alternate between the 2 groups, so there is a variable to indicate which group is the active group. 

 */

#include "Arduino.h"
#include "OdyInput.h"
#include "FastLED.h"
OdyInput::OdyInput(int dirLeft, int dirRight, int dirUp, int dirDown, int bedenktijd, int holdtime)
{	
  	Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
  	pinMode( dirUp , INPUT);
 	pinMode( dirRight , INPUT);
  	pinMode( dirDown , INPUT);
  	pinMode( dirLeft , INPUT);
	firstLetterDefined = false; 
	overgang = false;
	_dirLeft = dirLeft; // A
	_dirRight = dirRight; // E
	_dirUp = dirUp; // O
	_dirDown = dirDown; //I
	_bedenktijd = bedenktijd;
	_deelBedenktijd = bedenktijd/6;
}
String OdyInput::selectieJoystickDigitaal(int _aantalTekens)
{
	_loopled += 1;

	_Odywoord = "";
	while (_aantalTekens > 0)
	{
		if (firstLetterDefined == false)
		{
	    		if ( digitalRead( _dirUp ) == LOW && digitalRead( _dirRight ) == LOW &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == HIGH )
	    		{
				if (overgang == false)
				{
			    		_Odywoord = _wisselgroep ('D');
					overgang = true; 
					_aantalTekens = _aantalTekens - 1;
				}
	    		}       
	    		else if ( digitalRead( _dirUp ) == LOW && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == LOW )
	    		{
				if (overgang == false)
				{
	    				_Odywoord = _wisselgroep ('R');
					overgang = true; 
					_aantalTekens = _aantalTekens - 1;
				}
	    		}	
	    		else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == LOW && digitalRead( _dirLeft) == LOW )
	    		{
				if (overgang == false)
				{
	    				_Odywoord = _wisselgroep ('M');
					overgang = true; 
					_aantalTekens = _aantalTekens - 1;
				}
	    		}
	    		else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == LOW &&	 digitalRead( _dirDown ) == LOW && digitalRead( _dirLeft) == HIGH)
	    		{
				if (overgang == false)
				{
	    				_Odywoord = _wisselgroep ('F');
					overgang = true; 
					_aantalTekens = _aantalTekens - 1;
				}
	    		}
	    		else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == HIGH)
	    		{
	    			if (overgang == true)
	    			{
					blneutraal = true;
					_neutraal();
	    			}
	       		}
		}
		else	 // If the first group is not false, then we are already looking for the second letter,
	 	{
	       		if ( digitalRead( _dirUp ) == LOW && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == HIGH)
		       	{
				if (overgang == false)
				{
	    				_Odywoord = _wisselgroep ('O');
					overgang = true; 
					_aantalTekens = _aantalTekens - 1;
				}
		       	}
		       	else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == LOW)
		       	{
				if (overgang == false)
				{
	    				_Odywoord = _wisselgroep ('E');
					overgang = true; 
					_aantalTekens = _aantalTekens - 1;
				}
			}
		       else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == LOW && digitalRead( _dirLeft) == HIGH)
		       {
				if (overgang == false)
				{
	    				_Odywoord = _wisselgroep ('I');
					overgang = true; 
					_aantalTekens = _aantalTekens - 1;
				}
		       }
		       else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == LOW &&	 digitalRead( _dirDown ) == HIGH&& digitalRead( _dirLeft) == HIGH)
		       {
				if (overgang == false)
				{
	    				_Odywoord = _wisselgroep ('A');
					overgang = true; 
					_aantalTekens = _aantalTekens - 1;
				}
		       }
		       else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == HIGH)
		       {
		       		if (overgang == true)
		       		{
					blneutraal = true;
					_neutraal();
			       	}
	       		}
		}
	}
	firstLetterDefined = true; //zorgt dat de volgende keer een medeklinker wordt gekozen
	overgang = true; //zet in de actieve stand
	Odytekens = "";  //zorgt dat de tussenfase om het Odywoord samen te stellen weer leeg is
	Odywoord = _Odywoord; //maakt toegankelijk voor later gebruik
	return Odywoord;
}
//---------------------------------------------------------------------------
void OdyInput::selectieDRMF()
{
	delay (holdtime);
	if ( digitalRead( _dirUp ) == LOW && digitalRead( _dirRight ) == LOW &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == HIGH )
	{
		if (overgang == false)
		{
		    	Odyteken = 'D';
			overgang = true;
		}
	}       
	else if ( digitalRead( _dirUp ) == LOW && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == LOW )
	{
		if (overgang == false)
		{
		    	Odyteken = 'R';
			overgang = true;
		}
	}	
	else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == LOW && digitalRead( _dirLeft) == LOW )
	{
		if (overgang == false)
		{
		    	Odyteken = 'M';
			overgang = true;
		}
	}
	else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == LOW &&	 digitalRead( _dirDown ) == LOW && digitalRead( _dirLeft) == HIGH)
	{
		if (overgang == false)
		{
		    	Odyteken = 'F';
			overgang = true;
		}
    		}
	else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == HIGH)
	{
		if (overgang == true)
		{
		    	Odyteken = 'N';
			overgang = false;
		}
	}

}
//---------------------------------------------------------------------------
void OdyInput::selectieOEIA()
{
 	if ( digitalRead( _dirUp ) == LOW && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == HIGH)
  	{
		if (overgang == false)
		{
			_Odywoord = _wisselgroep ('O');
			overgang = true; 
		}
  	}
  	else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == LOW)
  	{
		if (overgang == false)
		{
			_Odywoord = _wisselgroep ('E');
			overgang = true; 
		}
 }
	 else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == LOW && digitalRead( _dirLeft) == HIGH)
	 {
		if (overgang == false)
		{
			_Odywoord = _wisselgroep ('I');
			overgang = true; 
		}
	 }
	 else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == LOW &&	 digitalRead( _dirDown ) == HIGH&& digitalRead( _dirLeft) == HIGH)
	 {
		if (overgang == false)
		{
			_Odywoord = _wisselgroep ('A');
			overgang = true; 
		}
	 }
	 else if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == HIGH)
	 {
		if (overgang == true)
		{
		    	Odyteken = 'N';
			overgang = false;
		}
 	}
}
//---------------------------------------------------------------------------
String OdyInput::_wisselgroep(char _Odyteken) 
{
	delay (holdtime);
	Odyteken = _Odyteken;
	Odytekens = Odytekens + _Odyteken; 
	_loopled = 0;	
	return Odytekens;
}
//---------------------------------------------------------------------------
void OdyInput::_neutraal() 
{
	int fase;
	while (_bedenktijd > 0 && blneutraal == true)
	{
		_bedenktijd -= 1;
		fase = _bedenktijd/_deelBedenktijd;
		if ( digitalRead( _dirUp ) == HIGH && digitalRead( _dirRight ) == HIGH &&	 digitalRead( _dirDown ) == HIGH && digitalRead( _dirLeft) == HIGH)
		{
			while (fase == 5) 
			{
				_loopled = 1;	
				fase = _doorFase(); 
			}
			while (fase == 4 ) 
			{
				_loopled = 2;
				fase = _doorFase(); 
			}
			while (fase == 3) 
			{
				_loopled = 3;	
				fase = _doorFase(); 
			}
			while ( fase == 2) 
			{
				_loopled = 4;	
				fase = _doorFase(); 
			}
			while (fase == 1) 
			{
				_loopled = 5;	
				fase = _doorFase(); 
			}
		}
		else
		{
			blneutraal = false;
		}		
		if (_bedenktijd == 0)
		{	
			overgang = false;
			if (firstLetterDefined == true)
			{
				firstLetterDefined = false;
			}
			else
			{
				firstLetterDefined = true;
			}
		}	
	}
	if  (_bedenktijd > 0)
	{
		_bedenktijd = bedenktijd;	
		blneutraal = false;	
	}	
}
int OdyInput::_doorFase() 
{
	int fase;
	_bedenktijd -= 1;
	fase = _bedenktijd/_deelBedenktijd;
	return fase;
}
//---------------------------------------------------------------------------
/*
void OdyInput::ledKleur()
{
		if (Odyteken == 'D' || Odyteken == 'O')		
		{
           	 leds[_Odyled] = CRGB(200,5,0); // this sets a really dim processing light loopon the led strip.
		}
		else if (Odyteken == 'R' || Odyteken == 'E')		
		{
           	 leds[_Odyled] = CRGB(5,200,0); // this sets a really dim processing light loopon the led strip.
		}
		else if (Odyteken == 'M' || Odyteken == 'I')		
		{
           	 leds[_Odyled] = CRGB(5,0,200); // this sets a really dim processing light loopon the led strip.
		}
		else if (Odyteken == 'F' || Odyteken == 'A')		
		{
           	 leds[_Odyled] = CRGB(100,200,0); // this sets a really dim processing light loopon the led strip.
		}

} */
