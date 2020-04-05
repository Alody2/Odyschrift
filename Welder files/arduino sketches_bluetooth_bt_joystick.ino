
/* 
This sketch is part of the Odyschrift project. 
This project enables physically handicapped people to play a game of "connect-four" 
A joystick is used as a controller. 


The statements below create variables which can be called in the later sketch. 
They refer to the pin number to which the joystick is connected.
*/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX



//Variabelen voor de joystick
int dirLeft = 2; 
int dirRight = 3; 
int dirUp = 4; 
int dirDown = 5; 

//Bluetooth variabele
char keuze;

//---------------------------------------------------------------------------



void setup() {

/* 
put your setup code here, to run once. Below, the joystick related pins are defined as 
digital inputs (reading on or off), and the Solenoid pins are set as outputs
*/
    pinMode( dirUp , INPUT);
    pinMode( dirRight , INPUT);
    pinMode( dirDown , INPUT);
    pinMode( dirLeft , INPUT);
 
 //serial monitor gebruikt om er achter te komen welke Arduino actief is
  Serial.begin(9600); //this begins the serial monitor to be able to get feedback from the sketch.
   Serial.println("HALLO IK BEN joystick");
 mySerial.println("Send 1 to turn on the LED. Send 0 to turn Off");
 mySerial.begin (38400);
}

//---------------------------------------------------------------------------
void loop(){
  


             if ( digitalRead( dirUp ) == LOW && digitalRead( dirLeft ) == LOW ){
               gekozen("D");
            }
          		else if ( digitalRead( dirUp ) == LOW && digitalRead( dirRight ) == LOW ){
               gekozen("R");
            }
             		else if ( digitalRead( dirDown ) == LOW && digitalRead( dirRight ) == LOW ){
               gekozen("M");
            }
           		else if ( digitalRead( dirDown ) == LOW && digitalRead( dirLeft ) == LOW ){
              gekozen("F");
            }
   	      	  	  if( digitalRead( dirUp ) == LOW && digitalRead( dirLeft ) == HIGH && digitalRead( dirRight ) == HIGH) {
                gekozen("O");
            }
        	 	  else if( digitalRead( dirRight ) == LOW && digitalRead( dirUp ) == HIGH && digitalRead( dirDown ) == HIGH) {
             gekozen("E");
          }
           	else if( digitalRead( dirDown ) == LOW && digitalRead( dirRight ) == HIGH && digitalRead( dirLeft ) == HIGH){
             gekozen("I" );
          }
        		else if( digitalRead( dirLeft ) == LOW && digitalRead( dirDown ) == HIGH && digitalRead( dirUp ) == HIGH){
             gekozen("A");
          }
}

void gekozen(char keuze) {
  delay(1000); 
 Serial.println (keuze); 
 mySerial.print (keuze);
}
