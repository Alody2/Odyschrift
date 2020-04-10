
/*
  Ody_algemeen.h - Library Odyschrift. A system to select an item in a collection of items with a penstroke or an Arcade joystick.
  Created by A. van Meeteren, 2019.
  Released into the public domain.
*/
#ifndef Ody_algemeen_h
#define Ody_algemeen_h

#include "Arduino.h"

class Ody_algemeen
{
  public:
	Ody_algemeen();
	int CharNaarNummer(char Odywoord);
	void regeltModule(String Odywoord, int odyModule);
	int Odynummer;
  private:
	int _Odynummer;
	char _Odywoord;
};

#endif
