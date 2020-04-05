/* 
This is the cpp file in the library vvierOpRij. It is part of the Odyschrift project. It has been originally created by Alle v Meeteren, modified by Jurre Ongering on 
15 March 2020 amd conversed to a library on 4 avril 2020 by Alle
This module of the project enables physically handicapped people to play a game of "connect-four". A joystick is used as a controller. 
The joystick has 8 contacts.

 * The joystick can activate a single contact (4 directions)  or 2 contacts (4 directions between the other 4 directions) at a time.
 * In the neutral state none of these is active. In our implementation the joystick has to return to that neutral state, before the next direction can be chosen.
 * We alternate between the 2 groups, so there is a variable to indicate which group is the active group. 

We use an Arduino Mega */
#include "Arduino.h"
#include "Morse.h"

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
 
  Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
  lcd.init();
  lcd.backlight();
  
  tekst = "LATEN WE"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  tekst = "SPEL(L)EN"; cursorKolom = 9 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  tekst = "NU:"; cursorKolom = 0 ; cursorRij = 2;  afrollen = false; wachten = 1; laatstaan = true; lcd_print();    
  tekst = "Vier op een rij"; cursorKolom = 0 ; cursorRij =3; afrollen = false; wachten = 2; laatstaan = false; lcd_print();    
  
  } // this bracket closes the setup loop. This loop plays only once

//---------------------------------------------------------------------------

void loop(){

digitalWrite(led_green, LOW); //switch green LED to low
digitalWrite(led_red, LOW); //switch red LED to low
delay(100); // This tiny delay is nice to not flicker the LCD that will otherwise get a LOT of input from the final "else" statements.
	
if (FirstLetterDefined == false){  // in dit eerste deel wordt alleen gekeken of er een medeklinker geselecteerd is. Dit wordt gedaan als de eerste letter nog niet gekozen is.

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
    keuzestand = keuzestand + 1;
    lcd.clear(); // clear
    tekst = "Kies medeklinker"; cursorKolom = 0 ; cursorRij =0;  afrollen = false; wachten = 1; laatstaan = true; lcd_print();    
  }
}
    
else{ // If the first grout is not false, then we are already looking for the second letter,
  
    if( digitalRead( dirUp ) == LOW ) {
      Odyteken = 'O';
      //  checkcontact (Odyteken);
      gekozen();
      }
    
    else if( digitalRead( dirRight ) == LOW ) {
      Odyteken = 'A';
      // checkcontact (Odyteken);
      gekozen();
      }
   
    else if( digitalRead( dirDown ) == LOW ){
      Odyteken = 'I';
      //  checkcontact (Odyteken);
      gekozen();
      }
    else if( digitalRead( dirLeft ) == LOW ){
      Odyteken = 'E';
      // checkcontact (Odyteken);
      gekozen();
      }
    else{ // this else statement makes sure the user gets some instruction on the LED
      keuzestand = keuzestand + 1;
      lcd.clear(); // clear
      tekst = "Kies klinker"; cursorKolom = 0 ; cursorRij = 0;  wachten = 1; laatstaan = true; lcd_print();    
      }
    }
  }

//---------------------------------------------------------------------------

void gekozen() {   // This is a seperate fuction that is called based on scenario above.
  lcd.clear(); // clear
  keuzestand = 0;  
  startholdtime = millis();//startholdtime is set to 0
  endholdtime = millis();//endholdtime is set to 0
  digitalWrite(led_red, HIGH); //the red LED is switched on
  Odywoord = Odywoord + Odyteken; //the character related with the chosen direction is added to the word. When looking for first letter, Odyteken will be "" and one letter is added to Odywoord
	tekst = "Je wijst naar " + Odyteken; cursorKolom = 0 ; cursorRij =0;   wachten = 0; laatstaan = true; lcd_print();    
	tekst = "Hou even vast "; cursorKolom = 1 ; cursorRij =2;   wachten = 3; laatstaan = false; lcd_print();  
    
  while ((endholdtime - startholdtime) < holdtime){
    endholdtime = millis(); // endholdtime is updated
    // checkcontact ("op weg" + Odyteken);
    delay(40); 
      
    if ( digitalRead( dirUp ) == HIGH && digitalRead( dirRight ) == HIGH && digitalRead( dirDown ) == HIGH && digitalRead( dirLeft ) == HIGH ){
      digitalWrite(led_green, LOW);
	    digitalWrite(led_red, LOW); //clock passes the set time Als joystock neutraal is... 
		  if (FirstLetterDefined == false){ // This if statement checks if the logic has to go into the first or second letter selection scenario. 
        Odywoord = "";
			  }
  	  else if (FirstLetterDefined == true){ // Dit gaan we doen als er een letter bijkomt TWEEDE LETTER SCENARIO
        Odywoord.remove(1, 1); // This goes to the second position in the Odywoord string (index 1) and deletes one character.
			  }	
      delay(pausetime);
      tekst = Odyteken + " Tekort vastgehouden"; cursorKolom = 0 ; cursorRij = 0; wachten = 1; laatstaan = false; lcd_print();    
	    break; // This kills the loop
      }
      
    if((endholdtime - startholdtime) > holdtime){ //de knop is zolang inhehouden dat de waarde definitief wordt!      
      // checkcontact ("lang genoeg gewacht" + Odyteken);
      digitalWrite(led_green, HIGH);//green led on! 
      digitalWrite(led_red, LOW);
	    // lcd action part that defines what should be displayed on the LCD screen
	    tekst = "Je koos " + Odywoord ; cursorKolom = 0 ; cursorRij =0;  wachten = 1; laatstaan = true; lcd_print(); 
     
      if(FirstLetterDefined == false){ // This part coaches the user by giving time to let go before selecting second odyteken
        tekst = "Kies klinker in: "; cursorKolom = 0 ; cursorRij =2;  wachten = 1; laatstaan = true; lcd_print();  
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
        }

      else if(FirstLetterDefined == true){ // This part coaches the user by giving time to let go before selecting second odyteken
        tekst = "Goed zo!"; cursorKolom = 12 ; cursorRij =0;  wachten = 1; laatstaan = true; lcd_print(); 
        tekst = "Joystick los in: "; cursorKolom = 0 ; cursorRij =2;  wachten = 1; laatstaan = true; lcd_print();  
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
        }
      }  
      
    delay(pausetime); 
    lcd.clear(); // clear
			
    if (FirstLetterDefined == false){ // This if statement checks if the logic has to go into the first or second letter selection scenario. 
	    wisselgroep();
	    }
    else if (FirstLetterDefined == true){ // Dit gaan we doen als er een letter bijkomt TWEEDE LETTER SCENARIO
	    wisselgroep();
      actiontrigger(); // This is an IMPORTANT trigger to the actions that we connect to the odywords.
      // checkcontact ("Firstsier");
      Odywoord = ""; // This resets the odywoord to " " after the action trigger action is executed
		  }
    }
  }

//---------------------------------------------------------------------------

void wisselgroep() {// This is a seperate function that simply switches the "first-letter-defined-mode" on and off             
  if (FirstLetterDefined == true){
    FirstLetterDefined = false;
    }
  else {
    FirstLetterDefined = true;
    }
  }

//---------------------------------------------------------------------------
void lcd_print() {// function to regulate printing to the lcd-screen             
  lcd.setCursor(cursorKolom, cursorRij);
	lengteTekst = tekst.length();
 
	if (afrollen == true){ // This part executes what needs to happen to have the "afrollen" effect
	  if (keuzestand < 2) {
		  for (int i = 0; i < lengteTekst; i++) {
    	  delay(70); // this sets the time it takes between letter appearing
  		  lcd.print(tekst.charAt(i));   // Print a message to the LCD.
		    }
      }
    }	
	else {
	  lcd.print (tekst);
    } 
	
	while (wachten > 1) {
	  delay(500);            // wait one sec
		wachten = wachten - 1;
	  }
  
  if (laatstaan == false){
    lcd.clear(); // clear
    }
  }

//---------------------------------------------------------------------------

void actiontrigger() {
// checkcontact ("action");
  if (Odywoord == "DO"){
    tekst = "Chip DO valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (turntime);
    digitalWrite (mDO, HIGH);
    delay (turntime);
    digitalWrite (mDO, LOW);
     }
  else if (Odywoord == "DE"){
    tekst = "Chip DE valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (turntime);
    digitalWrite (mDE, HIGH);
    delay (turntime);
    digitalWrite (mDE, LOW);
    }
  else if (Odywoord == "DI"){
    tekst = "Chip DI valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (turntime);
    digitalWrite (mDI, HIGH);
    delay (turntime);
    digitalWrite (mDI, LOW);
    }
  else if (Odywoord == "DA"){
    tekst = "Chip DA valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (turntime);
    digitalWrite (mDA, HIGH);
    delay (turntime);
    digitalWrite (mDA, LOW);
    }
  else if (Odywoord == "RO"){
    tekst = "Chip RO valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    delay (turntime);
    digitalWrite (mRO, HIGH);
    delay (turntime);
    digitalWrite (mRO, LOW);
    }
  else if (Odywoord == "RE"){
    tekst = "Chip RE valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (turntime);
    digitalWrite (mRE, HIGH);
    delay (turntime);
    digitalWrite (mRE, LOW);
    }
  else if (Odywoord == "RI"){
    tekst = "Chip RI valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop Ihip
    delay (turntime);
    digitalWrite (mRI, HIGH);
    delay (turntime);
    digitalWrite (mRI, LOW);
     }
  else if (Odywoord == "RA"){
    tekst = "Chip RA valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (turntime);
    digitalWrite (mRA, HIGH);
    delay (turntime);
    digitalWrite (mRA, LOW);
    }
  else if (Odywoord == "MO"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (3000);
    lcd.clear(); // clear
    }
  else if (Odywoord == "ME"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (3000);
    lcd.clear(); // clear
    }
  else if (Odywoord == "MI"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (3000);
    lcd.clear(); // clear
    }
  else if (Odywoord == "MA"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (3000);
    lcd.clear(); // clear
    }
  else if (Odywoord == "FO"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (3000);
    lcd.clear(); // clear
    }
  else if (Odywoord == "FE"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (3000);
    lcd.clear(); // clear
    }
  else if (Odywoord == "FI"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (3000);
    lcd.clear(); // clear
    }
  else if (Odywoord == "FA"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (3000);
    lcd.clear(); // clear
    }
  }
//---------------------------------------------------------------------------


/*
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
*/

  
//}
