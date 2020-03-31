/* 
This sketch is part of the Odyschrift project. It has been originally created by Alle v Meeteren and modified by Jurre Ongering

In this part a lcd-screen translates Odywords in text. 

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
 

//variabelen om het printen van de tekst op het lcd-scherm te regelen
String tekst;			//catches the text to print to the lcd-screen
byte textLen;                           // Number of visible characters in the text
int cursorKolom;		//waar op de regel start de tekst
int cursorRij;			//op welke regel start de tekst
int wachten;  			//als 1 neerzetten tekst in eerste loop, wordt 2 in de eerste loop. Als 3 wordt de tekst in elke loop aangepast. 
int wachten2 = false;  			//schakelaar om te zetten in eerste loop. 
int keuzestand = 0;			//zet een listener aan na de eerste loop in een keuze stand
boolean startModus;		//waar zolang een welkomst tekst wordt getoond
//---------------------------------------------------------------------------

void setup() {

 
Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
  lcd.init();
  lcd.backlight();
startModus = true;
}

//---------------------------------------------------------------------------

void loop() {

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



