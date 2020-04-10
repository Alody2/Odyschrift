/*
  Ody_algemeen.cpp - Library Odyschrift. A system to select an item in a collection of items with a penstroke or an Arcade joystick.
  Created by A. van Meeteren, 2019.
  Released into the public domain.
*/
#include "Arduino.h"
#include "Ody_algemeen.h"
#include <vierOpRij.h>// the library voor vier op een rij

Ody_algemeen::Ody_algemeen()
{
}

void Ody_algemeen::regeltModule(String Odywoord, int odyModule)
       	\\opvolger van Odyletterswitch, brengt naar module, sluit af met zet_voltooid, regelt met functie schakel overstap naar andere module  
{
	switch (Odywoord.length())
	{
	case 1:
		switch (odyModule)
		{ 
			case 3: //dom
				//dobbelsteenWerpen 1 tot en met 3
			//	dobbelsteen(0);
				zet_voltooid();
			break;
			case 4: //dof
				//dobbelsteenWerpen 4 tot en met 6
			//	dobbelsteen(9);
				zet_voltooid();
			break;
			case 5: //ded
				//mens erger
					if (wacht_op_input == false && _Odywoord == "D")
					{
						wacht_op_input = true;
					//	lcd_leeg();
						//worp(1,0);
					}
					else if (wacht_op_input == false && _Odywoord == "F")
					{
						schakel();
					}
					else if (wacht_op_input == true)
					{
						wacht_op_input = false;
						//plaatsen4(5,0);
					}
				zet_voltooid();
			break;
			case 6: //der
				//ganzenbord
					if (wacht_op_input == false && _Odywoord == "R")
					{
						wacht_op_input = true;
					//	lcd_leeg();
						//worp(2,0);
					}
					else if (wacht_op_input == false && _Odywoord == "F")
					{
						schakel();
					}
					else if (wacht_op_input == true)
					{
						wacht_op_input = false;
						//plaatsen4(9,0);
					}
				zet_voltooid();
			break;
			case 8: //uitslag raden mastermind
				ronde++;
			//	uitslag(ronde);
			//	zet_voltooid();
			break;
			case 49: //fod
			break;
		}
	break; 
	case 2:
		if (_Odywoord == "FA")
		{
			schakel();
		}
		else
		{
			switch (odyModule)
			{ 
				case 1:
					vierOpRij:action(Odywoord);
					zet_voltooid();
				break;
				case 7://dem
				// mastermind opzetten
				if (ronde<20)
				{
				//mastermind(ronde);
					ronde = ronde + 5;
					if (ronde ==20)	
					{
						ronde=0;
					/*	if (lcd_ver==true)
						{
							lcd_ver= false;
						}*/
						odyModule = 8;
					}
				}
				zet_voltooid();
				break;	
				case 10://dem
				//tekst = orientatie_richting();
				zet_voltooid();
				break;	
				case 11://dem
				//tekst = tangram();
				//tangram_plaats(tekst);
				//zet_voltooid();
				break;	
			}
		}
	break;
	case 3:
		switch (odyModule)
		{ 
			case 2:
		//schrijven
				if (_Odywoord == "FAD") //verwijder laatste letter
				{
					cursorTekst = cursorTekst - 1;
					cursorKolom = cursorTekst;
					tekst = " "; lcd_print();
				} 
				else if (_Odywoord == "FAR")
				{
				} 
				else if (_Odywoord == "FAM") //maak scherm leeg
				{
					lcd.clear();
					cursorTekst = 0;
					cursorRij = 0;
				}
				else if (_Odywoord == "FAF")
				{
					schakel();
				}
				else 
				{
					if (cursorTekst == 0)
					{
					//	lcd_regel_leeg(0); //maak de regel leeg 
					}	
					if (cursorRij == 3) //eerste letter na modulewissel
					{
						cursorRij= 0;
						cursorTekst = 0;
					}
					tekst = schrijven();  eerste_schrijf_loop = false;  cursorKolom = cursorTekst;  
					cursorTekst = cursorTekst + tekst.length(); //zet de positie van de cursor klaar voor de volgende letter(groep)
					if (cursorTekst > 19)
					{
						if (cursorRij == 0)
						{
							cursorRij= 1;
							cursorTekst = 0;
						}
						else if (cursorRij == 1)
						{
							cursorRij= 2;
							cursorTekst = 0;
						}
						else if (cursorRij == 2)
						{
							cursorRij= 0;
							cursorTekst = 0;
						}
					}
					lcd_print();
				//	lcd_Ody_leeg(); //maakt de rij voor Odytekens leeg
					zet_voltooid();
				}
			break;
			case 64:
				tekst = module();  eerste_schrijf_loop = false;  cursorKolom = 2; cursorRij = 3;
				lcd_print();
				lcd.setCursor (0,0); 
				zet_voltooid();
			break;
		}
	break; 
	case 5:
	break;
	case 4:
	break;
	}
}

int Ody_algemeen::CharNaarNummer(char Odywoord)
{
Serial.print ("dit");
	int _Odynummer;
			switch (Odywoord){
				case 'D':
					_Odynummer = 1;
				break;
				case 'R':
					_Odynummer = 2;
				break;
				case 'M':
					_Odynummer = 3;
				break;
				case 'F':
					_Odynummer = 4;
				break;
				case 'DO':
					_Odynummer = 1;
				break;
				case 'DE':
					_Odynummer = 2;
				break;
				case 'DI':
					_Odynummer = 3;
				break;
				case 'DA':
					_Odynummer = 4;
				break;
				case 'RO':
					_Odynummer = 5;
				break;
				case 'RE':
					_Odynummer = 6;
				break;
				case 'RI':
					_Odynummer = 7;
				break;
				case 'RA':
					_Odynummer = 8;
				break;
				case 'MO':
					_Odynummer = 9;
				break;
				case 'ME':
					_Odynummer = 10;
				break;
				case 'MI':
					_Odynummer = 11;
				break;
				case 'MA':
					_Odynummer = 12;
				break;
				case 'FO':
					_Odynummer = 13
				break;
				case 'FE':
					_Odynummer = 14;
				break;
				case 'FI':
					_Odynummer = 15;
				break;
				case 'FA':
					_Odynummer = 16;
				break;
	/*					case 2:
					strModule = "";
				break;
				case 3:
					strModule = "";
				break;
				case 4:
					strModule = "";
				break;
				case 5:
					strModule = "";
				break;
				case 6:
					strModule = "";
				break;
				case 7:
					strModule = "";
				break;
				case 8:
					strModule = "";
				break;
				case 9:
					strModule = "";
				break;
				case 10:
					strModule = "";
				break;
				case 11:
					strModule = "";
				break;
				case 12
					strModule = "";
				break;
				case 13:
					strModule = "";
				break;
				case 14:
					strModule = "";
				break;
				case 15:
					strModule = "";
				break;
				case 16:
					strModule = "";
				break;
				case 17:
					strModule = "";
				break;
				case 18:
					strModule = "";
				break;
				case 19:
					strModule = "";
				break;
				case 20:
					strModule = "";
				break;
				case 21:
					strModule = "";
				break;
				case 22:
					strModule = "";
				break;
				case 23:
					strModule = "";
				break;
				case 24:
					strModule = "";
				break;
				case 25:
					strModule = "";
				break;
				case 26:
					strModule = "";
				break;
				case 27:
					strModule = "";
				break;
				case 28:
					strModule = "";
				break;
				case 29:
					strModule = "";
				break;
				case 30:
					strModule = "";
				break;
				case 31:
					strModule = "";
				break;
				case 32:
					strModule = "";
				break;
				case 33:
					strModule = "";
				break;
				case 34:
					strModule = "";
				break;
				case 35:
					strModule = "";
				break;
				case 36:
					strModule = "";
				break;
				case 37:
					strModule = "";
				break;
				case 38:
					strModule = "";
				break;
				case 39:
					strModule = "";
				break;
				case 40:
					strModule = "";
				break;
				case 41:
					strModule = "";
				break;
				case 42:
					strModule = "";
				break;
				case 44:
					strModule = "";
				break;
				case 45:
					strModule = "";
				break;
				case 46:
					strModule = "";
				break;
				case 47:
					strModule = "";
				break;
				case 48:
					strModule = "";
				break;
				case 49:
					strModule = "";
				break;
				case 50:
					strModule = "";
				break;
				case 51:
					strModule = "";
				break;
				case 52:
					strModule = "";
				break;
				case 53:
					strModule = "";
				break;
				case 54:
					strModule = "";
				break;
				case 55:
					strModule = "";
				break;
				case 56:
					strModule = "";
				break;
				case 57:
					strModule = "";
				break;
				case 58:
					strModule = "";
				break;
				case 59:
					strModule = "";
				break;
				case 60:
					strModule = "";
				break;
				case 61:
					strModule = "";
				break;
				case 62:
					strModule = "";
				break;
				case 63:
					strModule = "";
				break;
				case 64:
					strModule = "schakel";
				break;
			}
		break;
 }*/      	
}
Odynummer = _Odynummer;
	return _Odynummer;
}
