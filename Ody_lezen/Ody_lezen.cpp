/*
  Ody_lezen.cpp - Library Odyschrift. A system to select an item in a collection of items with a penstroke or an Arcade joystick.
  Created by A. van Meeteren, 2019.
  Released into the public domain.
*/
#include "Arduino.h"
#include "Ody_lezen.h"
#include <SoftwareSerial.h>
	const int txPin = 9;
	const int rxPin = 10;
	SoftwareSerial mySerial(rxPin, txPin); // RX, TX*/
	char _receivedChar;
	bool _newData; 

Ody_lezen::Ody_lezen(int rxPin, int txPin)
{
}

void Ody_lezen::begin()
{
	pinMode(rxPin, INPUT);
	pinMode(txPin, OUTPUT);
	mySerial.begin (9600);
	Serial.begin (9600);
	
}

char Ody_lezen::lezen()
{
	char Odyteken; 
	if (mySerial.available()) 
	{
		Ody_lezen::_recvOneChar();
		Odyteken = Ody_lezen::_showNewData();
		Serial.print (Odyteken);
	}
	return Odyteken;
}
void Ody_lezen::_recvOneChar() 
{
    if (mySerial.available() > 0) 
	{
		_receivedChar = mySerial.read();
		_newData = true;
       	}
}

char Ody_lezen::_showNewData() 
{
	char Odyteken;
	if (_newData == true) 
	{
		Odyteken = _receivedChar;
		_newData = false;
	}
	return Odyteken;
}
int Ody_lezen::CharNaarNummer(String Odywoord)
{
	int _Odynummer;
			if (Odywoord== "D")
			{
					_Odynummer = 1;
			}
			else if (Odywoord=="R")
			{
					_Odynummer = 2;
			}
			else if (Odywoord=="M")
			{
					_Odynummer = 3;
			}
			else if (Odywoord=="F")
			{
					_Odynummer = 64;
			}
			else if (Odywoord== "DO")
			{
					_Odynummer = 1;
			}
			else if (Odywoord=="DE")
			{
					_Odynummer = 2;
			}
			else if (Odywoord=="DI")
			{
					_Odynummer = 3;
			}
			else if (Odywoord=="DA")
			{
					_Odynummer = 4;
			}
			else if (Odywoord== "RO")
			{
					_Odynummer = 5;
			}
			else if (Odywoord=="RE")
			{
					_Odynummer = 6;
			}
			else if (Odywoord=="RI")
			{
					_Odynummer = 7;
			}
			else if (Odywoord=="RA")
			{
					_Odynummer = 8;
			}
			else if (Odywoord== "MO")
			{
					_Odynummer = 9;
			}
			else if (Odywoord=="ME")
			{
					_Odynummer = 10;
			}
			else if (Odywoord=="MI")
			{
					_Odynummer = 11;
			}
			else if (Odywoord=="MA")
			{
					_Odynummer = 12;
			}
			else if (Odywoord== "FO")
			{
					_Odynummer = 13;
			}
			else if (Odywoord=="FE")
			{
					_Odynummer = 14;
			}
			else if (Odywoord=="FI")
			{
					_Odynummer = 15;
			}
			else if (Odywoord=="FA")
			{
					_Odynummer = 64;
			}
			 else if (Odywoord== "DOD")
			{
					_Odynummer = 1;
			}
			else if (Odywoord=="DOR")
			{
					_Odynummer = 2;
			}
			else if (Odywoord=="DOM")
			{
					_Odynummer = 3;
			}
			else if (Odywoord=="DOF")
			{
					_Odynummer = 4;
			}
			if (Odywoord== "DED")
			{
					_Odynummer = 5;
			}
			else if (Odywoord=="DER")
			{
					_Odynummer = 6;
			}
			else if (Odywoord=="DEM")
			{
					_Odynummer = 7;
			}
			else if (Odywoord=="DEF")
			{
					_Odynummer = 8;
			}
			if (Odywoord== "DID")
			{
					_Odynummer = 9;
			}
			else if (Odywoord=="DIR")
			{
					_Odynummer = 10;
			}
			else if (Odywoord=="DIM")
			{
					_Odynummer = 11;
			}
			else if (Odywoord=="DIF")
			{
					_Odynummer = 12;
			}
			else if (Odywoord== "DAD")
			{
					_Odynummer = 13;
			}
			else if (Odywoord=="DAR")
			{
					_Odynummer = 14;
			}
			else if (Odywoord=="DAM")
			{
					_Odynummer = 15;
			}
			else if (Odywoord=="DAF")
			{
					_Odynummer = 16;
			}
			else if (Odywoord== "ROD")
			{
					_Odynummer = 17;
			}
			else if (Odywoord=="ROR")
			{
					_Odynummer = 18;
			}
			else if (Odywoord=="ROM")
			{
					_Odynummer = 19;
			}
			else if (Odywoord=="ROF")
			{
					_Odynummer = 20;
			}
			else if (Odywoord== "RED")
			{
					_Odynummer = 21;
			}
			else if (Odywoord=="RER")
			{
					_Odynummer = 22;
			}
			else if (Odywoord=="REM")
			{
					_Odynummer = 23;
			}
			else if (Odywoord=="REF")
			{
					_Odynummer = 24;
			}
			if (Odywoord== "RID")
			{
					_Odynummer = 25;
			}
			else if (Odywoord=="RIR")
			{
					_Odynummer = 26;
			}
			else if (Odywoord=="RIM")
			{
					_Odynummer = 27;
			}
			else if (Odywoord=="RIF")
			{
					_Odynummer = 28;
			}
			else if (Odywoord== "RAD")
			{
					_Odynummer = 29;
			}
			else if (Odywoord=="RAR")
			{
					_Odynummer = 30;
			}
			else if (Odywoord=="RAM")
			{
					_Odynummer = 31;
			}
			else if (Odywoord=="RAF")
			{
					_Odynummer = 32;
			}
			else if (Odywoord== "MOD")
			{
					_Odynummer = 33;
			}
			else if (Odywoord=="MOR")
			{
					_Odynummer = 34;
			}
			else if (Odywoord=="MOM")
			{
					_Odynummer = 35;
			}
			else if (Odywoord=="MOF")
			{
					_Odynummer = 36;
			}
			else if (Odywoord== "MED")
			{
					_Odynummer = 37;
			}
			else if (Odywoord=="MER")
			{
					_Odynummer = 38;
			}
			else if (Odywoord=="MEM")
			{
					_Odynummer = 39;
			}
			else if (Odywoord=="MEF")
			{
					_Odynummer = 40;
			}
			else if (Odywoord== "MID")
			{
					_Odynummer = 41;
			}
			else if (Odywoord=="MIR")
			{
					_Odynummer = 42;
			}
			else if (Odywoord=="MIM")
			{
					_Odynummer = 43;
			}
			else if (Odywoord=="MIF")
			{
					_Odynummer = 44;
			}
			else if (Odywoord== "MAD")
			{
					_Odynummer = 45;
			}
			else if (Odywoord=="MAR")
			{
					_Odynummer = 46;
			}
			else if (Odywoord=="MAM")
			{
					_Odynummer = 47;
			}
			else if (Odywoord=="MAF")
			{
					_Odynummer = 48;
			}
			else if (Odywoord== "FOD")
			{
					_Odynummer = 49;
			}
			else if (Odywoord=="FOR")
			{
					_Odynummer = 50;
			}
			else if (Odywoord=="FOM")
			{
					_Odynummer = 51;
			}
			else if (Odywoord=="FOF")
			{
					_Odynummer = 52;
			}
			else if (Odywoord== "FED")
			{
					_Odynummer = 53;
			}
			else if (Odywoord=="FER")
			{
					_Odynummer = 54;
			}
			else if (Odywoord=="FEM")
			{
					_Odynummer = 55;
			}
			else if (Odywoord=="FEF")
			{
					_Odynummer = 56;
			}
			else if (Odywoord== "FID")
			{
					_Odynummer = 57;
			}
			else if (Odywoord=="FIR")
			{
					_Odynummer = 58;
			}
			else if (Odywoord=="FIM")
			{
					_Odynummer = 59;
			}
			else if (Odywoord=="FIF")
			{
					_Odynummer = 60;
			}
			else if (Odywoord== "FAD")
			{
					_Odynummer = 61;
			}
			else if (Odywoord=="FAR")
			{
					_Odynummer = 62;
			}
			else if (Odywoord=="FAM")
			{
					_Odynummer = 63;
			}
			else if (Odywoord=="FAF")
			{
					_Odynummer = 64;
			}
			
	
	return _Odynummer;
}

