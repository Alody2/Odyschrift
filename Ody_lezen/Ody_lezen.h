
/*
  Ody_lezen.h - Library Odyschrift. A system to select an item in a collection of items with a penstroke or an Arcade joystick.
  Created by A. van Meeteren, 2019.
  Released into the public domain.
*/
#ifndef Ody_lezen_h
#define Ody_lezen_h

#include "Arduino.h"

class Ody_lezen
{
  public:
	Ody_lezen(int rxPin, int txPin);
	char lezen();
	void begin();
	//void leeg_maken();
	int CharNaarNummer(String Odywoord);
//	char Odywoord;
  private:
	void _recvOneChar(); 
	char _showNewData(); 
	int _pin;
	int _Odynummer;
};

#endif
