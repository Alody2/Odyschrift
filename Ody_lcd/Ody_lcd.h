/* 

This sketch is the center of the Odyschrift project, when used with a digital joystick. It has been originally created by Alle v Meeteren and crazy modified and updated by Jurre Ongering on 
untill 20 March 2020.

 * The joystick can sense activation on a single contact (allowing 4 directions)  or 2 contacts (allowing for 4 directions between the other 4 directions) at a time.
 * In the neutral state none of these is active. In our implementation the joystick has to return to that neutral state, before the next direction can be chosen.
 * We alternate between the 2 groups, so there is a variable to indicate which group is the active group. 

The project also includes the LiquidCrystal Library Library originally added 18 Apr 2008 by David A. Mellis // library modified 5 Jul 2009 by Limor Fried (http://www.ladyada.net) // 
example added 9 Jul 2009 by Tom Igoe // modified 22 Nov 2010 by Tom Igoe // modified 7 Nov 2016 by Arturo Guadalupi/ More info:
http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld 
 */
#include <LiquidCrystal_I2C.h> // include the library code
//code is in in bibliotheken geplaats. Dit om het overzicht te behouden.
// initialize the LiquidCrystal library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const byte lcdAddr = 0x27;  // Address of I2C backpack
const byte lcdCols = 20;    // Number of character in a row
const byte lcdRows = 4;     // Number of lines
const unsigned int scrollDelay = 500;   // Miliseconds before scrolling next char
const unsigned int demoDelay = 2000;    // Miliseconds between demo loops
LiquidCrystal_I2C lcd (0x27, 20, 4);
//variabelen om het lcd scherm te reguleren
String tekst;			//catches the text to print to the lcd-screen
byte textLen;                           // Number of visible characters in the text
int cursorKolom;		//waar op de regel start de tekst
int cursorRij;			//op welke regel start de tekst
int wachten;  			//als 1 neerzetten tekst in eerste loop, wordt 2 in de eerste loop. Als 3 wordt de tekst in elke loop aangepast. 
int wachten2 = false;  			//schakelaar om te zetten in eerste loop. 
int keuzestand = 0;			//zet een listener aan na de eerste loop in een keuze stand
boolean startModus;		//waar zolang een welkomst tekst wordt getoond
// NEVER define any of these pins to attach to the 1 (tx) pin on Arduino because it will totally screw your sketch!! And send you on an hour of debugging
// Make sure these are corrected in the right order! Taking some time to do it properly might save you a lot of work later.
int cursorTekst = 0;	
//uitzoeken functie/verschil 4 variabelen Jurre hieronder
boolean laatstaan;                  //waar als de tekst niet wordt weggepoetst na de pauze
boolean afrollen;                   // waar als de tekst afgerold moet worden
boolean FirstLetterDefined = false; // Variable distinguishing between first loop when looking for a first word, or second loop looking for second word
//en variabelen Alle
//int wachten;  			//als 1 neerzetten tekst in eerste loop, wordt 2 in de eerste loop. Als 3 wordt de tekst in elke loop aangepast. 
//---------------------------------------------------------------------------

void setup() 
{
/* 
put your setup code here, to run once. Below, the joystick related pins are defined as 
digital inputs (reading on or off)
*/
  	lcd.init();
  	lcd.backlight();
	startModus = true;
  	 tekst = 	"LATEN WE"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
 	 tekst = "SPEL(L)EN"; cursorKolom = 9 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
 	 tekst = "NU:"; cursorKolom = 0 ; cursorRij = 2;  afrollen = false; wachten = 1; laatstaan = true; lcd_print();    
 	 tekst = "Vier op een rij"; cursorKolom = 0 ; cursorRij =3; afrollen = false; wachten = 6; laatstaan = false; lcd_print();    
	tekst = strActie; cursorKolom = 2 ; cursorRij = 3;  eerste_schrijf_loop = false; lcd_print();    
}
//---------------------------------------------------------------------------
void LoadBar() //brengt naar Odyletterswitch, maakt gebruik van wisselgroep en Odytekencheck
{ 
  /* 
  This part gets called in the earlier loop when a value is selected.
  It only becomes part of the executed code if it gets called in the central loop.
  This function confirms the selection and makes it final
  a chosen selection becomed final (and part of the odyword) when the selection is held for the time set in the variable "holdtime"
  */
   	lcd.clear(); // clear  
  	int count = 10;
  	startholdtime = millis();//startholdtime is set to 0
  	endholdtime = startholdtime;//endholdtime is set to 0
  	delay(pausetime);
  	Serial.println ("RESET HOLDTIMES");
  // digitalWrite(led_red, HIGH); //the red LED is switched on
  	tekst = "Je wijst naar " + Odyteken; cursorKolom = 0 ; cursorRij =0;   wachten = 0; laatstaan = true; lcd_print();    
  	tekst = "Hou even vast "; cursorKolom = 1 ; cursorRij =2;   wachten = 0; laatstaan = true; lcd_print(); 
  	delay(pausetime);
    	while (count <= 20 && (endholdtime - startholdtime) < holdtime && Odyteken == OdytekenNOW) 
	{ // hier moet nog iets bij waardoor start key combi gechecked wordt met de nieuwe status.
    // (digitalRead( dirUp ) == HIGH && digitalRead( dirRight ) == HIGH && digitalRead( dirLeft ) == HIGH && digitalRead( dirDown ) == HIGH )
    		endholdtime = millis(); // endholdtime is updated
    		Odytekencheck(); // This checks if the odyteken does not change because that would mean it will not be confirmed as a chosen 'teken'
    		tekst = "CONFIRMED"; cursorKolom = 0; cursorRij = 3;  wachten = 0; laatstaan = true; lcd_print();
    		tekst = "X"; cursorKolom = count; cursorRij = 3;  wachten = 0; laatstaan = true; lcd_print();
    		Serial.println (Odyteken + " <-Odyteken " + OdytekenNOW + " <-OdytekenNOW " + Odywoord + " <-Odywoord " + count + " <-COUNT");
    		Serial.println (endholdtime - startholdtime);
    // hier moet nog iets tussen waardoor huidige keycombi gedouble checked wordt met keycombi bij start
    		delay (holdtime/12);
    		while (count<15)
		{  // This while sub-loop is currently not in use. It is only placed here as a placeholder to
      			Serial.println ("placetexthere");
      		break;
      		}
    		while (count==20)
		{ // dit toevoegen als conditie hoor is
      			Odywoord = Odywoord + Odyteken; // the character related with the chosen direction is added to the word. When looking for first letter, Odyteken will be "" and one letter is added to Odywoord
      			Odyletterswitch();
      		break;
      		}
   		count++;  
  	} // this bracket ends the bigger "while loop"
} 
//---------------------------------------------------------------------------
void Odyletterswitch()//opvolger van LoadBar, brengt naar regeltmodule
{
  /* This is a seperate function that simply switches the "first-letter-defined-mode" on and off
  It is an if statement that checks if the logic has to go into the vowel or consonant selection scenario.
  Whenever the program gets to this function, it means that a letter has been held long enough to be CONFIRMED.
  That means checking if letter has been held long enough is not needed anymore.
  */
 	lcd.clear(); // clear
   	if (FirstLetterDefined == false) //the start of selection or the last time a vowel is selected
	{  
      		wisselgroep();
/*         Option 1 for confirmation of choice this block counts down from 3. 
         Question is if we prefer something like this, or prefer a x second delay.
*/     
        	tekst = "OK! Kies klinker in: "; cursorKolom = 0 ; cursorRij =2;  wachten = 1; laatstaan = true; lcd_print();  
        	tekst = "Seconden: "; cursorKolom = 10 ; cursorRij =3;  wachten = 1; laatstaan = true; lcd_print(); 
        	tekst = "3"; cursorKolom = 8 ; cursorRij =3;  wachten = 1; laatstaan = true; lcd_print(); 
        	delay(1000);
       		tekst = "2"; cursorKolom = 8 ; cursorRij =3;  wachten = 1; laatstaan = true; lcd_print(); 
        	delay(1000);
       		tekst = "1"; cursorKolom = 8 ; cursorRij =3;  wachten = 1; laatstaan = true; lcd_print(); 
        	delay(1000);
        	tekst = "0"; cursorKolom = 8 ; cursorRij =3;  wachten = 1; laatstaan = true; lcd_print();     
        	delay(1000);     
       		Odyteken = "";
        	delay(pausetime);
      // Option 2 this block simply delays for a couple of seconds
      // Question is if we prefer something like this, or prefer a x second timeout like above.
        	//delay(4000); 
        }
	else if (FirstLetterDefined == true)
	{ // The last time a consonant is selecteid
      		wisselgroep();
      		lcd.clear(); // Empty the LCD screen after the message from the actiontrigger function
      		Odywoord = ""; // This resets the odywoord to " " after the action trigger action is executed
        // Option 1 for confirmation of choice BELOW. This block counts down from 3. 
        // Question is if we prefer something like this, or prefer a x second delay.
        	tekst = "Goed gedaan!"; cursorKolom = 0 ; cursorRij =0;  wachten = 1; laatstaan = true; lcd_print(); 
        	tekst = "Volgende zet in: "; cursorKolom = 0 ; cursorRij =2;  wachten = 1; laatstaan = true; lcd_print(); 
        	tekst = "Seconden: "; cursorKolom = 10 ; cursorRij =3;  wachten = 1; laatstaan = true; lcd_print(); 
       		tekst = "3"; cursorKolom = 8 ; cursorRij =3;  wachten = 1; laatstaan = true; lcd_print(); 
        	delay(1000);
        	tekst = "2"; cursorKolom = 8 ; cursorRij =3;  wachten = 1; laatstaan = true; lcd_print(); 
        	delay(1000);
        	tekst = "1"; cursorKolom = 8 ; cursorRij =3;  wachten = 1; laatstaan = true; lcd_print(); 
        	delay(1000);
       		tekst = "0"; cursorKolom = 8 ; cursorRij =3;  wachten = 1; laatstaan = true; lcd_print();     
        	delay(1000);     
       		Odyteken = "";
        	delay(pausetime);
        // Option 2 this block BELOW simply delays for a couple of seconds
        // Question is if we prefer something like this, or prefer a x second timeout like above.
   	    	//delay(4000); 
   	}
      //	Ody_algemeen:regeltModule(Odywoord, odyModule); // goes to the  function that scans if there are enough Odyletters for an action in the active module. Acts if that is the case, else waits for the mext Odyletter
}
//---------------------------------------------------------------------------
void zet_voltooid()
{
	FirstLetterDefined = false;
	Odywoord = ""; //Odywoord geleegd voor volgende
}
//---------------------------------------------------------------------------
void lcd_print(){ 
  
  /* 
  This is function that can be called to regulate printing to the I2C-lcd-screen  
  */            
  
  lcd.setCursor(cursorKolom, cursorRij);
  lengteTekst = tekst.length();
 
  if (afrollen == true){ // This part executes what needs to happen to have the "afrollen" effect
 
      for (int i = 0; i < lengteTekst; i++) {
        delay(70); // this sets the time it takes between letter appearing
        lcd.print(tekst.charAt(i));   // Print a message to the LCD.
      }
   } 
   
  else {
    lcd.print (tekst);
    } 
 
  while (wachten > 1) {
    delay(500);            // wait X amount of Milli-sec
    wachten = wachten - 1;
    }
  
  if (laatstaan == false){
    lcd.clear(); // clear
  }
}
//---------------------------------------------------------------------------
void schakel()
{
	odyModule = 64; 
	lcd.clear();
	strActie = "schakel";
	tekst = strActie; cursorKolom = 2 ; cursorRij = 3;  eerste_schrijf_loop = false; lcd_print();    
	zet_voltooid();
}
