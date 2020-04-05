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
// initialize the library by associating any needed LCD interface pin
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
#include <Ody_lezen.h>
// Make sure these are corrected in the right order! Taking some time to do it properly might save you a lot of work later.
//The pins for the joystick are:
int dirLeft = 47; // A
int dirRight = 49; // E
int dirUp = 53; // O
int dirDown = 51; //I

int led_red = 12;                   //rood
int led_green = 13;           //groen

boolean Firstgroup = true;    // This Boolean is used for zooming in on the group DRMF, or the group AOEI
String Odywoord;              // This is the Odywoord which is a composition of one or more Odytekens
int OdyNummer;              // This is the number of the Odywoord
String Odyteken;                    // This is the Odyteken which constructs the Odywoord as selected at first
String OdytekenNOW;                 // This is the Odyteken which is currently selected
int cursorOdy;		//waar op de regel start de tekst
String strModule;		//variable to contain the name of the active application
int intModule = 1;			//variable containing the number of a module
Ody_lezen myOdy(9,10);

//de module waarin de joystick start
/*int odyModule = 3;
String strActie = "dobbelsteen 1-3";*/
/*int odyModule = 4;
String strActie = "dobbelsteen 4-6";*/
/*int odyModule = 5;
String strActie = "mens_erger_je_niet";
int odyModule = 6;
String strActie = "ganzenbord";*/
/*int odyModule = 7;//inclusief 8 en 9
String strActie = "mastermind";*/
/*int odyModule = 11;
String strActie = "tangram";*/
/*int odyModule = 49;
String strActie = "instelling_1";*/
/*int odyModule = 64;
String strActie = "schakel";*/

/*int odyModule = 2;			//variable containing the number of a module
String strActie = "schrijven  ";*/
int odyModule = 1;			//variable containing the number of a module
String strActie = "4 op 1 ry";


int cursorTekst = 0;	
//uitzoeken functie/verschil 4 variabelen Jurre hieronder
boolean laatstaan;                  //waar als de tekst niet wordt weggepoetst na de pauze

boolean afrollen;                   // waar als de tekst afgerold moet worden
boolean FirstLetterDefined = false; // Variable distinguishing between first loop when looking for a first word, or second loop looking for second word

//en variabelen Alle
//int wachten;  			//als 1 neerzetten tekst in eerste loop, wordt 2 in de eerste loop. Als 3 wordt de tekst in elke loop aangepast. 
int delayTime1 = 50; // Delay between shifts
int delayTime2 = 250; // Delay between shifts
//einde variabelen Alle

int eerste_schrijf_loop = false;  			//schakelaar om te zetten in eerste loop. 
//variabelen om de input te timen
int holdtime = 500;          // This sets how long the user have to hold the stick in a direction before selection is confirmed

int startholdtime;            // This is a variable needed for keeping track of selection time
int endholdtime;              // This is a variable needed for keeping track of selection time
int pausetime = 100;         // Sets the time sketch pauzes after confirmation of letters
int turntime = 500;           // Wait for a moment after selecting a motor 
int readtime = 3000;                // Sets the time the info will be on the screen for Elinde's written messages
int count = 10;                     // Sets the time the info will be on the screen for Elinde's written messages
int announcetime = 1000;            // Time anouncing fal chip action
boolean wacht_op_input = false; //een pauze waarin gewacht wordt op input
int ronde; //ronde teller
//ogen van dobbelsteen
byte oog_open[] =
{
	B11111,
	B10001,
	B10001,
	B10001,
	B10001,
	B10001,
	B10001,
	B11111
};
byte oog_dicht[] =
{
B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
//symbolen van kaartspel
byte harten[8] = {
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
}; 

byte ruiten[8] = {
  B00100,
  B01110,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
}; 

byte schoppen[8] = {
  B00100,
  B01110,
  B11111,
  B11111,
  B00100,
  B01110,
  B00000,
  B00000,
}; 

byte klaver[8] = {
  B01110,
  B01110,
  B11111,
  B11111,
  B00100,
  B01110,
  B00000,
  B00000,
};
byte grens[8] = {
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001
};
byte grens_2[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};
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

digitalWrite(led_green, LOW);
digitalWrite(led_red, LOW);
strModule = "Vier op een rij";  //module waarmee gestart wordt 
intModule = 1; // het nummer van de module
 
Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
  lcd.init();
  lcd.backlight();
startModus = true;
  
  tekst = "LATEN WE"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  tekst = "SPEL(L)EN"; cursorKolom = 9 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  tekst = "NU:"; cursorKolom = 0 ; cursorRij = 2;  afrollen = false; wachten = 1; laatstaan = true; lcd_print();    
  tekst = "Vier op een rij"; cursorKolom = 0 ; cursorRij =3; afrollen = false; wachten = 6; laatstaan = false; lcd_print();    
	tekst = strActie; cursorKolom = 2 ; cursorRij = 3;  eerste_schrijf_loop = false; lcd_print();    
	lcd.createChar(0, harten);
	lcd.createChar(1, ruiten);
	lcd.createChar(2, schoppen);

	lcd.createChar(4, oog_dicht);
	lcd.createChar(5, oog_open);
	lcd.createChar(6, grens);
	lcd.createChar(7, grens_2);
	randomSeed(analogRead(0)); 
}

//---------------------------------------------------------------------------

void loop() {
/*
This is the general part of the sketch. It is ALWAYS part of the sketch because it is the central loop 
It waits for input on diagonal, or hori-vertical choices on the joystick
If waits for specific kind of input based on the value of "FirstLetterDefined".
If we need to add a third letter to Odyschrift, we will need to add a third category here (with "firstletterdefined" changing to a three option INTEGER instead of a two option BOOLEAN).
*/

digitalWrite(led_green, LOW); //switch green LED to low
digitalWrite(led_red, LOW); //switch red LED to low

delay(100); // This tiny delay is nice to not flicker the LCD that will otherwise get a LOT of input from the final "else" statements.
  
		lcd.setCursor(0,0);
  if (FirstLetterDefined == false){  // in dit eerste deel wordt alleen gekeken of er een medeklinker geselecteerd is. Dit wordt gedaan als de eerste letter nog niet gekozen is.

    if ( digitalRead( dirUp ) == LOW && digitalRead( dirLeft ) == LOW ){
      Odyteken = 'R';
      OdytekenNOW = Odyteken;
      Serial.println (Odyteken + " <-- Joystick input");
      LoadBar();
      }
    else if ( digitalRead( dirUp ) == LOW && digitalRead( dirRight ) == LOW ){
      Odyteken = 'D';
      OdytekenNOW = Odyteken;
      Serial.println (Odyteken + " <-- Joystick input");
      LoadBar();
      }       
    else if ( digitalRead( dirDown ) == LOW && digitalRead( dirRight ) == LOW ){
      Odyteken = 'F';
      OdytekenNOW = Odyteken;
      Serial.println (Odyteken + " <-- Joystick input");
      LoadBar();
      }
    else if ( digitalRead( dirDown ) == LOW && digitalRead( dirLeft ) == LOW ){
      Odyteken = 'M';
      OdytekenNOW = Odyteken;
      Serial.println (Odyteken + " <-- Joystick input");
      LoadBar();
      }
    else { // this else statement makes sure the user gets some instruction on the LED
      lcd.clear(); // clear
      tekst = "Kies medeklinker"; cursorKolom = 0 ; cursorRij =0;  afrollen = false; wachten = 1; laatstaan = true; lcd_print();   
      Serial.println ("Wachtend op medeklinker"); 
      }
    }
       
  else{ // If the first group is not false, then we are already looking for the second letter,
  
    if( digitalRead( dirUp ) == LOW ) {
      Odyteken = 'O';
      OdytekenNOW = Odyteken;
      Serial.println (Odyteken + " <-- Joystick input");
      //  checkcontact (Odyteken);
      LoadBar();
      }
    
    else if( digitalRead( dirRight ) == LOW ) {
      Odyteken = 'A';
      OdytekenNOW = Odyteken;
      Serial.println (Odyteken + " <-- Joystick input");
      // checkcontact (Odyteken);
      LoadBar();
      }
   
    else if( digitalRead( dirDown ) == LOW ){
      Odyteken = 'I';
      OdytekenNOW = Odyteken;
      Serial.println (Odyteken + " <-- Joystick input");
      //  checkcontact (Odyteken);      
      LoadBar();
      }
    else if( digitalRead( dirLeft ) == LOW ){
      Odyteken = 'E';
      OdytekenNOW = Odyteken;
      Serial.println (Odyteken + " <-- Joystick input");
      // checkcontact (Odyteken);      
      LoadBar();
      }
    else { // this else statement makes sure the user gets some instruction on the LED
      lcd.clear(); // clear
      tekst = "Kies klinker"; cursorKolom = 0 ; cursorRij = 0;  wachten = 1; laatstaan = true; lcd_print();    
      Serial.println ("Wachtend op klinker");
      }
    } 
  }

//---------------------------------------------------------------------------
void LoadBar(){ 
  
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
  
  while (count <= 20 && (endholdtime - startholdtime) < holdtime && Odyteken == OdytekenNOW) { // hier moet nog iets bij waardoor start key combi gechecked wordt met de nieuwe status.
    // (digitalRead( dirUp ) == HIGH && digitalRead( dirRight ) == HIGH && digitalRead( dirLeft ) == HIGH && digitalRead( dirDown ) == HIGH )
    endholdtime = millis(); // endholdtime is updated
    Odytekencheck(); // This checks if the odyteken does not change because that would mean it will not be confirmed as a chosen 'teken'
    tekst = "CONFIRMED"; cursorKolom = 0; cursorRij = 3;  wachten = 0; laatstaan = true; lcd_print();
    tekst = "X"; cursorKolom = count; cursorRij = 3;  wachten = 0; laatstaan = true; lcd_print();
    Serial.println (Odyteken + " <-Odyteken " + OdytekenNOW + " <-OdytekenNOW " + Odywoord + " <-Odywoord " + count + " <-COUNT");
    Serial.println (endholdtime - startholdtime);
    // hier moet nog iets tussen waardoor huidige keycombi gedouble checked wordt met keycombi bij start
    delay (holdtime/12);
    
    while (count<15){  // This while sub-loop is currently not in use. It is only placed here as a placeholder to
      Serial.println ("placetexthere");
      break;
      }
    
    while (count==20){ // dit toevoegen als conditie hoor is
      Odywoord = Odywoord + Odyteken; // the character related with the chosen direction is added to the word. When looking for first letter, Odyteken will be "" and one letter is added to Odywoord
      Odyletterswitch();
      break;
      }
    
    count++;  
  } // this bracket ends the bigger "while loop"
} // This bracked ends the function


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
		switch (odyModule)
		{
			case 3:
			break;
			case 4:
			break;
			case 5:
			break;
			case 6:
			break;
			default:	
				tekst = Odywoord; cursorOdy = 17 ;  lcd_print();  
		}	
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

void regeltModule()
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
					if (wacht_op_input == false && Odywoord == "D")
					{
						wacht_op_input = true;
					//	lcd_leeg();
						//worp(1,0);
					}
					else if (wacht_op_input == false && Odywoord == "F")
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
					if (wacht_op_input == false && Odywoord == "R")
					{
						wacht_op_input = true;
					//	lcd_leeg();
						//worp(2,0);
					}
					else if (wacht_op_input == false && Odywoord == "F")
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
		if (Odywoord == "FA")
		{
			schakel();
		}
		else
		{
			switch (odyModule)
			{ 
				case 1:
					strActie = "Vier op een rij"; 
					Serial.print (Odywoord);
					/*Serial1.print (Odywoord);
					Serial2.print (Odywoord); */
					tekst = strActie ; cursorKolom = 0 ;  eerste_schrijf_loop = false;  cursorRij =2;  lcd_print();    
					tekst = "chip " + Odywoord + " valt"; cursorKolom = 0 ;  eerste_schrijf_loop = false;  cursorRij =3;  lcd_print(); 
vierOpRij(); 
					zet_voltooid();
				break;
			case 7://dem
				// mastermind opzetten
				if (ronde<20)
				{
				//	mastermind(ronde);
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
			//	tekst = orientatie_richting();
				zet_voltooid();
			break;	
			case 11://dem
			//	tekst = tangram();
			//	tangram_plaats(tekst);
			//	zet_voltooid();
			break;	
			}
		}
	break;
	case 3:
		switch (odyModule)
		{ 
			case 2:
		//schrijven
				if (Odywoord == "FAD") //verwijder laatste letter
				{
					cursorTekst = cursorTekst - 1;
					cursorKolom = cursorTekst;
					tekst = " "; lcd_print();
				} 
				else if (Odywoord == "FAR")
				{
				} 
				else if (Odywoord == "FAM") //maak scherm leeg
				{
					lcd.clear();
					cursorTekst = 0;
					cursorRij = 0;
				}
				else if (Odywoord == "FAF")
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
//---------------------------------------------------------------------------
void zet_voltooid()
{
	FirstLetterDefined = false;
	Odywoord = ""; //Odywoord geleegd voor volgende
}

//---------------------------------------------------------------------------

void Odyletterswitch(){
  
  /* This is a seperate function that simply switches the "first-letter-defined-mode" on and off
  It is an if statement that checks if the logic has to go into the first or second letter selection scenario.
  Whenever the program gets to this function, it means that a letter has been held long enough to be CONFIRMED.
  That means checking if letter has been held long enough is not needed anymore.
  */

 lcd.clear(); // clear
      
    if (FirstLetterDefined == false){  
      wisselgroep();

/*
        // Option 1 for confirmation of choice this block counts down from 3. 
        // Question is if we prefer something like this, or prefer a x second delay.
        
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
  */     
  
      // Option 2 this block simply delays for a couple of seconds
      // Question is if we prefer something like this, or prefer a x second timeout like above.
        delay(4000); 
        
        }


    else if (FirstLetterDefined == true){ // Dit gaan we doen als er een letter bijkomt TWEEDE LETTER SCENARIO
      wisselgroep();
      actiontrigger(); // This is an IMPORTANT trigger to the actions that we connect to the odywords.
      Serial.println (Odywoord + " SUCCESSSSSSS");
      actiontrigger(); // Trigger the right action
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
        
        // delay(4000); 
      
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
//---------------------------------------------------------------------------
void Odytekencheck(){

    if ( digitalRead( dirUp ) == LOW && digitalRead( dirLeft ) == LOW ){
      OdytekenNOW = 'R';
       exit;
      }
      
    else if ( digitalRead( dirUp ) == LOW && digitalRead( dirRight ) == LOW ){
      OdytekenNOW = 'D';
        exit;
      }   
          
    else if ( digitalRead( dirDown ) == LOW && digitalRead( dirRight ) == LOW ){
      OdytekenNOW = 'F';
        exit;
      }
      
    else if ( digitalRead( dirDown ) == LOW && digitalRead( dirLeft ) == LOW ){
      OdytekenNOW = 'M';
        exit;
      }
  
    else if ( digitalRead( dirUp ) == LOW ) {
      OdytekenNOW = 'O';
        exit;
      }
    
    else if ( digitalRead( dirRight ) == LOW ) {
      OdytekenNOW = 'A';
        exit;
      }
   
    else if ( digitalRead( dirDown ) == LOW ){
      OdytekenNOW = 'I';
        exit;
      }
      
    else if( digitalRead( dirLeft ) == LOW ){
      OdytekenNOW = 'E';
        exit;
      }
      
    else { // als er niets geselecteerd is
      OdytekenNOW = ' ';
       exit;
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
void actiontrigger() {
}
