/* 
This sketch is part of the Odyschrift project. It has been originally created by Alle v Meeteren and modified by Jurre Ongering
This project enables physically handicapped people to play a game of "connect-four". A joystick is used as a controller. 
The joystick has 8 contacts.

 * The joystick can activate a single contact (4 directions)  or 2 contacts (4 directions between the other 4 directions) at a time.
 * In the neutral state none of these is active. In our implementation the joystick has to return to that neutral state, before the next direction can be chosen.
 * We alternate between the 2 groups, so there is a variable to indicate which group is the active group. 


27-6-2019: pinnumbers to connect to the board  , added action for all combinations of 2 Odyletters.
 */
#include <LiquidCrystal_I2C.h> // include the library code
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const byte lcdAddr = 0x27;  // Address of I2C backpack
const byte lcdCols = 20;    // Number of character in a row
const byte lcdRows = 4;     // Number of lines

//const char demoText[]= "ODYSCHRIFT: een schrift om de computer taken voor te schrijven! ";
const unsigned int scrollDelay = 500;   // Miliseconds before scrolling next char
const unsigned int demoDelay = 2000;    // Miliseconds between demo loops
LiquidCrystal_I2C lcd (0x27, 20, 4);
 
// NEVER define any of these pins to attach to the 1 (tx) pin on Arduino because it will totally screw your sketch!! And send you on an hour of debugging
// Make sure these are corrected in the right order! Taking some time to do it properly might save you a lot of work later.
//The pins for the joystick are:
int dirLeft = 4; 
int dirRight = 5; 
int dirUp = 3; 
int dirDown = 2;

//int bt =9;
//int bt = 10;
//int bt = 11;

int mDO = 39;
int mDE = 41;
int mDI = 43;
int mDA = 45;
int mRO = 47;
int mRE = 49;
int mRI = 51;
int mRA = 53;

int led_red = 12;             //rood
int led_green = 13;           //groen

boolean Firstgroup = true;    // This Boolean is used for zooming in on the group DRMF, or the group AOEI
String Odywoord;              // This is the Odyword which is a composition of one or more Odytekens
int OdyNummer;              // This is the Odyword which is a composition of one or more Odytekens
String Odyteken;              // This is the Odyteken which constructs the Odywoord
String strModule;		//variable to contain the name of the active application
int intModule = 1;			//variable containing the number of a module

//variabelen om het printen van de tekst op het lcd-scherm te regelen
String tekst;			//catches the text to print to the lcd-screen
byte textLen;                           // Number of visible characters in the text
int cursorKolom;		//waar op de regel start de tekst
int cursorRij;			//op welke regel start de tekst
int wachten;  			//als 1 neerzetten tekst in eerste loop, wordt 2 in de eerste loop. Als 3 wordt de tekst in elke loop aangepast. 
int wachten2 = false;  			//schakelaar om te zetten in eerste loop. 
int keuzestand = 0;			//zet een listener aan na de eerste loop in een keuze stand
boolean startModus;		//waar zolang een welkomst tekst wordt getoond
boolean FirstLetterDefined = false; // Variable distinguishing between first loop when looking for a first word, or second loop looking for second word
int delayTime1 = 50; // Delay between shifts
int delayTime2 = 250; // Delay between shifts

//variabelen om de input te timen
int holdtime = 500;          // This sets how long the user have to hold the stick in a direction before selection is confirmed

int startholdtime;            // This is a variable needed for keeping track of selection time
int endholdtime;              // This is a variable needed for keeping track of selection time
int pausetime = 100;         // Sets the time sketch pauzes after confirmation of letters
int turntime = 500;           // Wait for a moment after selecting a motor 
//---------------------------------------------------------------------------

void setup() {

/* 
put your setup code here, to run once. Below, the joystick related pins are defined as 
digital inputs (reading on or off)
*/

pinMode( dirUp , INPUT);
pinMode( dirRight , INPUT);
pinMode( dirDown , INPUT);
pinMode( dirLeft , INPUT);
pinMode(mDO , OUTPUT); 
pinMode(mDE , OUTPUT); 
pinMode(mDI , OUTPUT); 
pinMode(mDA , OUTPUT); 
pinMode(mRO , OUTPUT); 
pinMode(mRE , OUTPUT); 
pinMode(mRI , OUTPUT); 
pinMode(mRA , OUTPUT); 

digitalWrite(led_green, LOW);
digitalWrite(led_red, LOW);
strModule = "Vier op een rij";  
strModule = 1;
 
Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
  lcd.init();
  lcd.backlight();
startModus = true;
  
//tekst = "NU:"; cursorKolom = 0 ; cursorRij = 2;   wachten = 1; lcd_print();    
//tekst = strModule; cursorKolom = 0 ; cursorRij =3; wachten = 2; lcd_print();  

}

//---------------------------------------------------------------------------

void loop() {

digitalWrite(led_green, LOW); //switch green LED to low
digitalWrite(led_red, LOW); //switch red LED to low
//delay(30); // This tiny delay is nice to not flicker the LCD that will otherwise get a LOT of input from the final "else" statements.

	
if (FirstLetterDefined == false){
  if ( digitalRead( dirUp ) == LOW && digitalRead( dirLeft ) == LOW ){
  	Odyteken = 'R';
  	gekozen();
  }
  else if ( digitalRead( dirUp ) == LOW && digitalRead( dirRight ) == LOW ){
  	Odyteken = 'D';
  	gekozen();
  }       
  else if ( digitalRead( dirDown ) == LOW && digitalRead( dirRight ) == LOW ){
  	Odyteken = 'F';
  	gekozen();
  }
  else if ( digitalRead( dirDown ) == LOW && digitalRead( dirLeft ) == LOW ){
  	Odyteken = 'M';
  	gekozen();
  }
  else { // this else statement makes sure the user gets some instruction on the LED
	if (startModus == true){
		tekst = "MakeHealth"; cursorKolom = 5 ; cursorRij = 0; wachten = 1; wachten2 = false; lcd_print();    
		tekst = "ODYSCHRIFT"; cursorKolom = 5 ; cursorRij = 1; wachten = 1; wachten2 = false; lcd_print();    
		tekst = "Vier op een rij"; cursorKolom = 3 ; cursorRij = 2; wachten = 1; wachten2 = false; lcd_print();    
		tekst = "Met Odyschrift wordt een computer met en-kel een schrijvende beweging bestuurd. De beweging kan op elk moment in 4 richtingen gaan. Er zijn 2 sets van 4 richtingen. De ori-entatie van deze sets verschilt 45 graden. Daar steeds gewisseld wordt van set, kan verandering van richting geint-erpreteerd worden als bevestiging van de aan de vorige richting verbonden (tussen)opdracht.  De definitieve op-dracht is gegeven na voltooiing van de cyclus van beweging. De letters DO, RE, MI en FA staan voor de tussenopdrachten. Voor Vier op een rij is voor een cyclus van 2 bewegingen gekozen. Fiches vallen bij de opdrachten DO, DE, DI, DA, RO, RE, RI en RA. Via de opdracht FA kan men het spel verlaten en voor andere toepas-singen kiezen. Met MO roept men deze tekst weer op. ";
		cursorKolom = 0 ; cursorRij = 3; wachten = 3; lcd_print();
	}
	else {
		keuzestand = keuzestand + 1;
		if (tekst == "Kies medeklinker"){
		}
		else{  
			tekst = "Kies medeklinker"; cursorKolom = 0 ; cursorRij =0;  wachten = 1; wachten2 = false; lcd_print();
		}    
  	}
  }
}
    
else{ // If the first grout is not false, then we are already looking for the second letter,
  if( digitalRead( dirUp ) == LOW ) {
 	Odyteken = 'O';
  	gekozen();
  }
  else if( digitalRead( dirRight ) == LOW ) {
  	Odyteken = 'A';
	gekozen();
  }
  else if( digitalRead( dirDown ) == LOW ){
	Odyteken = 'I';
	gekozen();
  }
  else if( digitalRead( dirLeft ) == LOW ){
	Odyteken = 'E';
	gekozen();
  }
  else{ // this else statement makes sure the user gets some instruction on the LED
	keuzestand = keuzestand + 1;
		if (tekst == "Kies klinker"){
		}
		else{  
			tekst = "Kies klinker"; cursorKolom = 0 ; cursorRij =0;  wachten = 1; wachten2 = false; lcd_print();
		}    
  }
}
}

//---------------------------------------------------------------------------

void gekozen() {   // This is a seperate fuction that is called based on scenario above.
keuzestand = 0;  
startModus = false;
		cursorRij =3;   wachten = 2; lcd_print();    
  	startholdtime = millis();//startholdtime is set to 0
  	endholdtime = millis();//endholdtime is set to 0
  	digitalWrite(led_red, HIGH); //the red LED is switched on
	tekst = "Je wijst naar " + Odyteken; cursorKolom = 0 ; cursorRij =0;   wachten = 1; wachten2 = false; lcd_print();    
    	while ((endholdtime - startholdtime) < holdtime){
		tekst = "Hou even vast "; cursorKolom = 3 ; cursorRij =2;   wachten = 1; lcd_print();  wachten2 = false; 
    		endholdtime = millis(); // endholdtime is updated
    		delay(40); 
      		if ( digitalRead( dirUp ) == HIGH && digitalRead( dirRight ) == HIGH && digitalRead( dirDown ) == HIGH && digitalRead( dirLeft ) == HIGH ){
      			digitalWrite(led_green, LOW);//clock passes the set time Als joystock neutraal is... 
	      		digitalWrite(led_red, LOW);
      			// lcd action part that defines what should be displayed on the LCD screen
			tekst = "Keuze " + Odyteken + " afgebroken. "; cursorKolom = 0 ; cursorRij = 2; wachten2 = false; wachten = 1; lcd_print();    
			tekst = "Kies opnieuw"; cursorKolom = 0 ; cursorRij = 1; wachten2 = false; wachten = 1; lcd_print();    
      			delay(pausetime);
	      		break; // This kills the loop
      		} 
	}
	if (tekst.substring(0,4)!= "Kies"){ 
		cursorRij =1;   wachten = 2; lcd_print();    
		cursorRij =2;   wachten = 2; lcd_print();    
  		digitalWrite(led_green, HIGH);//green led on! 
  		digitalWrite(led_red, LOW);
     		// lcd action part that defines what should be displayed on the LCD screen
  		Odywoord = Odywoord + Odyteken; //the character related with the chosen direction is added to the word. When looking for first letter, Odyteken will be "" and one letter is added to Odywoord
		tekst = "Je koos " + Odyteken ; cursorKolom = 0 ; cursorRij =0;  wachten2 = false; wachten = 1; lcd_print();    
		tekst = "Odywoord is nu " + Odywoord; cursorKolom = 0 ;  wachten2 = false; wachten = 1; cursorRij =1;  lcd_print();    
      		delay(pausetime);
		wisselgroep(); 
      		regeltModule(); // This is an IMPORTANT trigger to the actions that we connect to the odywords.
	} 
}
//---------------------------------------------------------------------------
void wisselgroep(){
      	while ( digitalRead( dirUp ) == LOW || digitalRead( dirRight ) == LOW || digitalRead( dirDown ) == LOW || digitalRead( dirLeft ) == LOW ){
      		delay(pausetime);
	}
      	if ( digitalRead( dirUp ) == HIGH && digitalRead( dirRight ) == HIGH && digitalRead( dirDown ) == HIGH && digitalRead( dirLeft ) == HIGH ){
		if (FirstLetterDefined == false){ // This if statement checks if the logic has to go into the first or second letter selection scenario. 
			FirstLetterDefined = true;
		}
		else { // Dit gaan we doen als er een letter bijkomt TWEEDE LETTER SCENARIO
			FirstLetterDefined = false;
		}
	}
}
//---------------------------------------------------------------------------

void lcd_print() {// function to regulate printing to the lcd-screen   
	switch (wachten){
		case 1:	
			if (wachten2 == false){
				lcd.setCursor(0,cursorRij);
				lcd.print ("                    ");
				lcd.setCursor(cursorKolom,cursorRij);
				lcd.print (tekst);
			}
		break;
		case 2:	
				lcd.setCursor(0,cursorRij);
				lcd.print ("                    ");
		break;
		case 3:		
			scrollWords();
			lcd.clear();
		break;
	}
}

//---------------------------------------------------------------------------

void regeltModule() {

switch (Odywoord.length()) {
	case 1:
		switch (intModule){ 
			case 2:
			//dobbelsteenWerpen();
			break;
		} 
	case 2:
		switch (intModule){ 
			case 1:
			//Vier op een rij
				actiontrigger();
		break; 
		}
	break;
	case 3:
		switch (intModule){ 
			case 3:
		//schrijven
				//schrijven();
		break; 
			case 5:
		//schakel tussen modules
				schakel();
		break; 
		}
	
	case 4:
		switch (intModule){ 
			case 3:
		//schrijven
				//schrijven();
		break; 
		}
	}

}
//---------------------------------------------------------------------------

void scrollWords(){
	String deelTekst1;
	String deelTekst2;
int i = 0;			//teller tekst helemaal
int j = 0;			//pointer in tekst
int k = 0;
	j = tekst.length();
	for (i; i< j ; i++) {
		deelTekst1 = tekst.substring (i, i +21);
		k = 21;
			while (deelTekst1.charAt(k)!= ' '||deelTekst1.charAt(k)=='-'){
				if (deelTekst1.charAt(k)=='-'){
					k++;
					i--;
					break;
				}
				k--;
			}
				deelTekst1 = deelTekst1.substring (0,k); 
				lcd.setCursor(0, cursorRij);
				lcd.print("                    ");
				lcd.setCursor(0, cursorRij);
				lcd.print(deelTekst1);
				i = i + deelTekst1.length() ; 
				delay(delayTime2 * 6);
  		if ( digitalRead( dirUp ) == LOW || digitalRead( dirLeft ) == LOW ||  digitalRead( dirDown) == LOW ||  digitalRead( dirRight) == LOW){
		break;
	}
}
}

//---------------------------------------------------------------------------



void checkcontact(String dit){ // dit is een aparte functie, It's a tool to check the contacts
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
