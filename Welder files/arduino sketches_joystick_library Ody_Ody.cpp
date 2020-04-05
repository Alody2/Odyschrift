/*
  Ody.cpp - Library for Odyschrift.
  Created by A. van Meeteren, February, 2019.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Ody.h"

Ody::Ody(int givenLeft,int givenRight,int givenUp,int givenDown, int givenTime, int givenRed, int givenGreen)
{
	dirLeft = givenLeft ; 
	dirRight = givenRight; 
	dirUp =  givenUp; 
	dirDown = givenDown ; 
	holdtime = givenTime;
	led_red = givenRed;
	led_green = givenGreen;
    	pinMode( dirUp , INPUT);
    	pinMode( dirRight , INPUT);
    	pinMode( dirDown , INPUT);
    	pinMode( dirLeft , INPUT);
	_inkt = true;
	_Firstgroup = true;
    	digitalWrite(led_green, LOW);
    	digitalWrite(led_red, LOW);
 //turning on of the serial monitor to inspect the result. 
 Serial.begin(9600);
}


void Ody::werk()
{
if ( digitalRead( dirUp ) == HIGH && digitalRead( dirRight ) == HIGH && digitalRead( dirDown ) == HIGH && digitalRead( dirLeft ) == HIGH ){
      	digitalWrite(led_green, LOW);//clock passes the set time 
      	digitalWrite(led_red, LOW);
     	_endholdtime = 0;
	_startholdtime = 0;
	if (_gereed==true){
		_inkt = true;
		_gereed = false;
	}
}
if (_inkt==true){
  	if (_Firstgroup == true ){//what is the active group?
       		if ( digitalRead( dirUp ) == LOW && digitalRead( dirLeft ) == LOW ){
             		_Odyteken = 'D';
		_gekozen();
        	}
       		else if ( digitalRead( dirUp ) == LOW && digitalRead( dirRight ) == LOW ){
              		_Odyteken = 'R';
		_gekozen();
        	}
	        else if ( digitalRead( dirDown ) == LOW && digitalRead( dirRight ) == LOW ){
        	   	_Odyteken = 'M';
		_gekozen();
	        }
        	else if ( digitalRead( dirDown ) == LOW && digitalRead( dirLeft ) == LOW ){
              		_Odyteken = 'F';
		_gekozen();
	        }
  	}
  	else{ //which contact(s) is/are activated?  Express the result in a letter
	   	if( digitalRead( dirUp ) == LOW ) {
        	        _Odyteken = 'O';
		_gekozen();
	        }
        	else if( digitalRead( dirRight ) == LOW ) {
             		_Odyteken = 'E';
		_gekozen();
	        }
        	else if( digitalRead( dirDown ) == LOW ){
             		_Odyteken = 'I';
		_gekozen();
	        }
        	else if( digitalRead( dirLeft ) == LOW ){
             		_Odyteken = 'A';
		_gekozen();
	        }
  	}
	}
}
void Ody::_gekozen()
{
		if (_Odyteken != '\0' && _gereed ==false){
 			_startholdtime = millis();//the clock starts
     			_endholdtime = _startholdtime;
	     		digitalWrite(led_red, HIGH);
    			OdyWoord = OdyWoord + _Odyteken;//the character related with the chosen direction is added to the word 
	    		Serial.println ("daar" + OdyWoord);//the word is printed
			_Odyteken = '\0';
			_inkt = false;
			_verschil = _endholdtime - _startholdtime;
			while ((_endholdtime - _startholdtime) < holdtime){
     				_endholdtime = millis();
delay(100);
//checkcontact(OdyWoord);
				if ( digitalRead( dirUp ) == HIGH && digitalRead( dirRight ) == HIGH && digitalRead( dirDown ) == HIGH && digitalRead( dirLeft ) == HIGH ){
					digitalWrite(led_green, LOW);//clock passes the set time 
				      	digitalWrite(led_red, LOW);
					_inkt = true;
            				unsigned int lengthOdyWoord = OdyWoord.length()- 1;
				        OdyWoord = OdyWoord.substring(0, lengthOdyWoord);
					_wisselgroep();
					break;
				}
			}
	      		digitalWrite(led_green, HIGH);//clock passes the set time 
      			digitalWrite(led_red, LOW);
			_wisselgroep();
    			_gereed = true;
		}
}

void Ody::_wisselgroep()
{
	if (_Firstgroup == true){
        	_Firstgroup = false;
	}
        else {
        	_Firstgroup = true;
        }
}
void Ody::checkcontact(String dit)
{
 Serial.println ("***start check contacts laag");
   if (digitalRead( dirUp ) == LOW){Serial.println ("low dirUp/");}
  if (digitalRead( dirRight ) == LOW){Serial.println ("low dirRight/");}
  if (digitalRead( dirDown ) == LOW){Serial.println ("low dirDown/");}
  if (digitalRead( dirLeft ) == LOW){Serial.println ("low dirLeft/");}
  Serial.println (dit + "start check contacts hoog");
  if (digitalRead( dirUp ) == HIGH){Serial.println ("HIGH dirUp/");}
  if (digitalRead( dirRight ) == HIGH){Serial.println ("HIGH dirRight/");}
  if (digitalRead( dirDown ) == HIGH){Serial.println ("HIGH dirDown/");}
  if (digitalRead( dirLeft ) == HIGH){Serial.println ("HIGH dirLeft/");}
  Serial.println (dit + "eind check contacts***");
}
