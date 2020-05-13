 
/*
  OdyInput.h - Library for Ody input.
  Created by Alle van Meeteren, 23 april 2020. 
*/
#ifndef OdyInput_h
#define OdyInput_h

#include "Arduino.h"
#include "FastLED.h"

class OdyInput
{
	public:
		OdyInput(	
				int dirLeft, 
				int dirRight, 
				int dirUp, 
				int dirDown,
				int bedenktijd,
			       	int holdtime	
			);
		String selectieJoystickDigitaal(int _aantalTekens);
		void selectieDRMF();
		void selectieOEIA();
		void ledKleur();
		bool firstLetterDefined; // Variable distinguishing between first loop when looking for a first word, or second loop looking for second word
		int holdtime;                // This sets the time needed by the programm
		int bedenktijd;                // This sets a pause in the neutral position to reflect about the choice and correct it eventually.
		bool overgang;                 // This is the Odyteken which is currently selected
		bool blneutraal;                 // This is the Odyteken which is currently selected
		
		String Odywoord;                    // This is the Odyword which is a composition of one or more Odytekens
		char Odyteken;                    // This is the Odyword which is a composition of one or more Odytekens
		String Odytekens;
	private:
		int _dirLeft; // A
		int _dirRight; // E
		int _dirUp; // O
		int _dirDown; //I
		String _wisselgroep(char _Odyteken);
		void _neutraal();
	        int _doorFase();	
		String _Odywoord;
		int _bedenktijd ;
		int _deelBedenktijd;
		int _loopled;
};
#endif

