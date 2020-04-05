
/* 
This sketch is part of the Odyschrift project. 
This project enables physically handicapped people to play a game of "connect-four" 
A joystick is used as a controller. 

modified 9 Oktober 2018
by Jurre Ongering

modified 11 Oktober 2018 
by Alle van Meeteren
added are the Ody names for directions, 2 groups of 4 directions

modified 13/14 Oktober 2018 
by Alle van Meeteren
now the 16 availeble instructions by an input of 2 directions in a cycle are used
(8 instructions to start the motors, 8 other instructions)
A module for writing is added

modified on 20 Oktober 2018
by Alle van Meeteren and Jurre Ongering
adjustment of the joystick

The statements below create variables which can be called in the later sketch. 
They refer to the pin number to which the joystick is connected.
*/
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

const int rs = 6, en = 7, d4 = A0, d5 = A1, d6 = A2, d7 = A3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int dirLeft = 2; 
int dirRight = 3; 
int dirUp = 4; 
int dirDown = 5; 
String Data;

int led = 12; //rood
int led2 = 13; //groen

/* The joystick has a neutral state. It has to return to that neutral state, before the next direction can be chosen
 * In 4 directions 2 contacts are relevant, each of them on its own stands for one of the four other directions. These contacts have to be neutralized during the act to return to the neutral state 
a variable to split between commands that start one of the motors and other commands
 * 
 */



boolean Firstgroup = true;



/*These are the variables that regulate the Ody organisation. 
 */

//variable to collect the chosen directions during an Odycycle
String Odyteken = "";



//variable to collect the translated Odytekens in words or sentences
String OdyWoord;

//variable which contains the length of the OdyCycle in the actual implementation
int OdyCycle = 2;

/*variable which indicates the actual implementaton
 * 1 = connect 4
 * 2 = numbers and letters
 * 3 = words and sentences
 */ 
boolean keuzeVerwerkt = false; 
int loopTeller = 0; 
int OdyModule = 1;

int holdtime = 1000;
int startholdtime = 0;
int endholdtime;
int verschil;
boolean gereed = false;
boolean KlokAan = false;

//unsigned int lastStringLength = txtMsg.length(); 
unsigned int lengthOdyteken = Odyteken.length();
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
 // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600); //this begins the serial monitor to be able to get feedback from the sketch.
  
  mySerial.println("Send 1 to turn on the LED. Send 0 to turn Off");
  pinMode(led, OUTPUT);
 digitalWrite(led, LOW);
 loopTeller = 0;
 Serial.println("HALLO IK BEN joystick");
 check_contacten("setup");
 mySerial.begin (38400);
}

//---------------------------------------------------------------------------
void loop(){
  

  // code to switch between modules


//code to reset the contacts when the joystick is neutral (all contacts are high)
 check_contacten("start loop");
if ( digitalRead( dirUp ) == HIGH && digitalRead( dirRight ) == HIGH && digitalRead( dirDown ) == HIGH && digitalRead( dirLeft ) == HIGH ){
        digitalWrite(led, LOW);
        if (loopTeller > 0){    
            KlokAan = false;
            
        //vergelijkt huidige tijd met tijd van contact activeren, actie als meer dan ingestelde margetijd
 	      if (gereed == true) { 
          //zet klaar voor volgende keuze
            digitalWrite(led2, LOW);
                if (Firstgroup == true){
                  Firstgroup = false;
                }
                else {
                  Firstgroup = true;
                } 
           gereed = false;
           keuzeVerwerkt = true;
            loopTeller = 0;
           
          }
         else if (keuzeVerwerkt == false && loopTeller == 2){
           
            unsigned int lengthOdyteken = Odyteken.length()- 1;
           
           Odyteken = Odyteken.substring(0, lengthOdyteken);
           
            lcd.setCursor(0, 0);
            lcd.print ("                ");
            lcd.setCursor(0, 0);
            lcd.print(Odyteken);
             mySerial.println (Odyteken);
             mySerial.println ("bt");
           loopTeller = 0; 
          } //hierboven als er is losgelaten binnen de drempeltijd 
 }
}


  if (Firstgroup == true )
  {
     check_contacten("eerste groep");
             if ( digitalRead( dirUp ) == LOW && digitalRead( dirLeft ) == LOW ){
               
               gekozen("D");
            }
          		else if ( digitalRead( dirUp ) == LOW && digitalRead( dirRight ) == LOW ){
                
               gekozen("R");
            }
             		else if ( digitalRead( dirDown ) == LOW && digitalRead( dirRight ) == LOW ){
                   check_contacten("M");
               gekozen("M");
            }
           		else if ( digitalRead( dirDown ) == LOW && digitalRead( dirLeft ) == LOW ){
                
              gekozen("F");
            }
  }
  else 
  {
     check_contacten("tweede groep");
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

//}

switch (OdyModule){
  case 1:
      if (Odyteken.length()==2){
      
          if (Odyteken == "DO"){
          }
          else if (Odyteken == "DE"){
	        }
          else if (Odyteken == "DI"){
	        }
          else if (Odyteken == "DA"){
	        }
          else if (Odyteken == "RO"){
	        }
          else if (Odyteken == "RE"){
	        }
          else if (Odyteken == "RI"){
	        }
          else if (Odyteken == "RA"){
	        }
          else if (Odyteken == "MO"){ //gewonnen
            Serial.println( Odyteken  + " Vier op een rij 4!"); 
             lcd.setCursor(3, 0);
        lcd.print ("Vier op een rij 4!");
		      }
          else if (Odyteken == "ME"){ //uitnodiging nog een spel, 
            Serial.println( Odyteken  + " | Nog een spelletje?"); 
            lcd.setCursor(3, 0);
        lcd.print ("Nog een spelletje?");
 	      }
        else if (Odyteken == "MI"){ //afsluiten
            Serial.println( Odyteken  + " | Zullen we wat anders gaan doen?"); 
             lcd.setCursor(3, 0);
        lcd.print (" | Zullen we wat anders gaan doen?");
		    }
        else if (Odyteken == "MA"){ //afsluiten
            Serial.println( Odyteken  +" = STOP");
             lcd.setCursor(3, 0);
        lcd.print ("STOP"); 
	      }
        else if (Odyteken == "FO"){
            OdyModule = 2;
           lcd.setCursor (6, 0);
            Odyteken = "";
            lcd.print("schrijven");
        }
        else if (Odyteken == "FE"){
            OdyModule = 3;
	      }
        else if (Odyteken == "FI"){
            Serial.println( Odyteken  + " | Bedankt, ik wil ermee stoppen"); 
             lcd.setCursor(3, 0);
        lcd.print ("Bedankt, ik wil ermee stoppen"); 
		    }
        else if (Odyteken == "FA"){
            Serial.println( Odyteken  + " | Stop"); 
             lcd.setCursor(3, 0);
        lcd.print ("STOP"); 
		    }
     }
    break;
  case 2:
  
 
	Odyschrijven();
   break;
   case 3:

   
     break;  
  }
} //loop end

/* tool to check the contacts
void checkcontact(String dit){
  Serial.println (dit + "start check contacts hoog");
  if (digitalRead( dirUp ) == HIGH){Serial.print ("high dirUp/");}
  if (digitalRead( dirRight ) == HIGH){Serial.print ("high dirRight/");}
  if (digitalRead( dirDown ) == HIGH){Serial.print ("high dirDown/");}
  if (digitalRead( dirLeft ) == HIGH){Serial.print ("high dirLeft/");}

 Serial.println ("start check contacts laag");
   if (digitalRead( dirUp ) == LOW){Serial.println ("low dirUp/");}
  if (digitalRead( dirRight ) == LOW){Serial.print ("low dirRight/");}
  if (digitalRead( dirDown ) == LOW){Serial.print ("low dirDown/");}
  if (digitalRead( dirLeft ) == LOW){Serial.print ("low dirLeft/");}
  
 
  Serial.println (dit + "eind check contacts");
}
*/
void gekozen(String keuze) {
  
    check_contacten(keuze);
  if (loopTeller == 0){
    switch (OdyModule)
{
  case 1:
      if (Odyteken.length()==2)
      {
              Odyteken = "";
      }
      break;
  case 2:

   if (Odyteken.length()==3)
      {
        Odyteken = "";
      }
     break; 
   case 3:

   if (Odyteken.length()==3)
      {
        Odyteken = "";
      }
     break;  
} 
    Odyteken = Odyteken + keuze;
    Serial.print (Odyteken);
    lcd.setCursor(0, 0);
    lcd.print ("                ");
    lcd.setCursor(0, 0);
     lcd.print (Odyteken);
     startholdtime = millis();
     KlokAan = true;
     keuzeVerwerkt = false;
     digitalWrite(led, HIGH);
     loopTeller = 1; 
   }
   else{ 
     endholdtime = millis();
     verschil = endholdtime -startholdtime;
    
   if (verschil > holdtime) { 
     gereed = true;
      digitalWrite(led2, HIGH);
      digitalWrite(led, LOW);
             }
    else {
      loopTeller = 2;
       digitalWrite(led2, LOW);
       digitalWrite(led, HIGH);
      }
   }
}

void Odyschrijven(){
 
//variable wherein translation of Odyteken in a number or letter 
char OdyVertaling;
  if (Odyteken.length()==3)
      {
         Firstgroup = true;
        if (Odyteken == "DOD"){
           OdyVertaling = '1';
        }
        else if (Odyteken == "DOR"){
           OdyVertaling = '2';
        }
        else if (Odyteken == "DOM"){
          OdyVertaling = '3';
        }
    else if (Odyteken == "DOF")
        {
    OdyVertaling = '4';
  }
        else if (Odyteken == "DED")
        {
    OdyVertaling = '5';
  }
        else if (Odyteken == "DER")
        {
    OdyVertaling = '6';
  }
        else if (Odyteken == "DEM")
        {
    OdyVertaling = '7';
  }
        else if (Odyteken == "DEF")
        {
    OdyVertaling = '8';
  }
        else if (Odyteken == "DID")
        {
    OdyVertaling = '9';
  }
        else if (Odyteken == "DIR")
        {
    OdyVertaling = 'a';
  }
        else if (Odyteken == "DIM")
        {
    OdyVertaling = 'b';
  }
        else if (Odyteken == "DIF")
        {
    OdyVertaling = 'c';
  }
        else if (Odyteken == "DAD")
        {
    OdyVertaling = 'd';
  }
        else if (Odyteken == "DAR")
        {
    OdyVertaling = 'e';
  }
        else if (Odyteken == "DAM")
        {
    OdyVertaling = 'f';
  }
        else if (Odyteken == "DAF")
        {
    OdyVertaling = 'g';
  }
        else if (Odyteken == "ROD")
        {
    OdyVertaling = 'h';
  }
        else if (Odyteken == "ROR")
        {
    OdyVertaling = 'i';
  }
        else if (Odyteken == "ROM")
        {
    OdyVertaling = 'j';
  }
        else if (Odyteken == "ROF")
        {
    OdyVertaling = 'k';
  }
        else if (Odyteken == "RED")
        {
    OdyVertaling = 'l';
  }
        else if (Odyteken == "RER")
        {
    OdyVertaling = 'm';
  }
        else if (Odyteken == "REM")
        {
    OdyVertaling = 'n';
  }
        else if (Odyteken == "REF")
        {
    OdyVertaling = 'o';
  }
        else if (Odyteken == "RID")
        {
    OdyVertaling = 'p';
  }
        else if (Odyteken == "RIR")
        {
    OdyVertaling = 'q';
  }
        else if (Odyteken == "RIM")
        {
    OdyVertaling = 'r';
  }
        else if (Odyteken == "RIF")
        {
    OdyVertaling = 's';
  }
        else if (Odyteken == "RAD")
        {
    OdyVertaling = 't';
  }
        else if (Odyteken == "RAR")
        {
    OdyVertaling = 'u';
  }
        else if (Odyteken == "RAM")
        {
    OdyVertaling = 'v';
  }
        else if (Odyteken == "RAF")
        {
    OdyVertaling = 'w';
  }
        else if (Odyteken == "MOD")
        {
    OdyVertaling = 'x';
  }
        else if (Odyteken == "MOR")
        {
    OdyVertaling = 'y';
  }
        else if (Odyteken == "MOM")
        {
    OdyVertaling = 'z';
  }
        else if (Odyteken == "MOF")
        {
    OdyVertaling = ' '; //space
  }
        else if (Odyteken == "MED")
        {
    OdyVertaling = ','; //comma
  }
        else if (Odyteken == "MER")
        {
    OdyVertaling = '.'; //period
  }
        else if (Odyteken == "MEM")
        {
    OdyVertaling = '!'; //exclamation
  }
        else if (Odyteken == "MEF")
        {
    OdyVertaling = '?'; //question mark
  }
        else if (Odyteken == "MID")
        {
    OdyVertaling = '<';
  }
        else if (Odyteken == "MIR")
        {
    OdyVertaling = '>';
  }
        else if (Odyteken == "MIM")
        {
    OdyVertaling = '@';
  }
        else if (Odyteken == "MIF")
        {
    OdyVertaling = '#';
  }
        else if (Odyteken == "MAD")
        {
    OdyVertaling = '%';
  }
        else if (Odyteken == "MAR")
        {
    OdyVertaling = '^';
  }
        else if (Odyteken == "MAM")
        {
    OdyVertaling = '(';
  }
        else if (Odyteken == "MAF")
        {
    OdyVertaling = ')';
  }
        else if (Odyteken == "FOD")
        {
    OdyVertaling = 'Elinde schrijft!';
  }
        else if (Odyteken == "FOR")
        {
    OdyVertaling = ']';
  }
        else if (Odyteken == "FOM")
        {
    OdyVertaling = '{';
  }
        else if (Odyteken == "FOF")
        {
    OdyVertaling = '}';
  }
        else if (Odyteken == "FED")
        {
    OdyVertaling = '-';
  }
        else if (Odyteken == "FER")
        {
    OdyVertaling = '+';
  }
        else if (Odyteken == "FEM")
        {
    OdyVertaling = '*';
  }
        else if (Odyteken == "FEF")
        {
    OdyVertaling = '/';
  }
        else if (Odyteken == "FID")
        {
    OdyVertaling = '=';
  }
        else if (Odyteken == "FIR")
        {
    OdyVertaling = '|';
  }
        else if (Odyteken == "FIM")
        {
    OdyVertaling = '$';
  }
        else if (Odyteken == "FIF")
        {
    OdyVertaling = '0';
  }
        else if (Odyteken == "FAD")
        {
    OdyVertaling = 'Elinde schrijft!';
  }
        else if (Odyteken == "FAR")
        {
    OdyModule = "1";
    lcd.clear();
    OdyVertaling = 'Naar Vier op een rij';
  }
        else if (Odyteken == "FAM")
        {
          lcd.setCursor(0,1);
          lcd.print ("                    ");
    
   
  }
        else if (Odyteken == "FAF")
        {
    OdyVertaling = 'Stop';
  }
   lcd.setCursor(4,0);
    OdyWoord = OdyWoord + OdyVertaling;
    Serial.println(OdyWoord);
    mySerial.print(OdyWoord);
    lcd.setCursor(0,1);
    lcd.print (OdyWoord);
    
  Odyteken = "";
 
      }
}

void check_contacten(String plaats){
  delay (1000);
 Serial.print (plaats + "/begin check");
if (digitalRead (dirUp == HIGH)) {
Serial.print (" 1 op");
}
if (digitalRead (dirRight == HIGH)) {
Serial.print (" 2 rechts");
}
if (digitalRead (dirDown == HIGH)) {
Serial.print (" 3 neer");
}
if (digitalRead (dirLeft == HIGH)) {
Serial.print (" 4 links");
}
 Serial.println ("eind check/");
}
