/*
  Ody.h - Library Odyschrift. A system to select an item in a collection of items with a penstroke or an Arcade joystick.
  Created by A. van Meeteren, 2019.
  Released into the public domain.
*/
#ifndef Ody_h
#define Ody_h

#include "Arduino.h"

class Ody{
public:
	Ody(int dirLeft, int dirRight, int dirUp, int dirDown,int holdtime, int led_red, int led_green);
int dirLeft; 
int dirRight; 
int dirUp; 
int dirDown; 
int holdtime;
int led_red; //rood
int led_green; //groen
void checkcontact(String dit);
String OdyWoord;
void werk();
private:
void _gekozen();
boolean _Firstgroup ;
char _Odyteken;
boolean _inkt;
int _startholdtime;
int _endholdtime;
int _verschil;
boolean _gereed;
void _wisselgroep();
};

#endif
