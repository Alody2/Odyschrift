/* 
This sketch is part of the Odyschrift project. It has been originally created by Alle v Meeteren and crazy modified and updated by Jurre Ongering on 
untill 20 March 2020.

This project enables physically handicapped people to play a game of "connect-four". A joystick is used as a controller. 
The joystick has 8 contacts. The project is based on Odyschrift
Odyschrift is a concept by Alle van Meeteren that allows for a LOT more then just playing "connect-four".

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
LiquidCrystal_I2C lcd (0x27, 20, 4);
// Connect the I2C LCD to the SDA en SCL pin on the Arduino Mega!
 
// NEVER define any of these pins to attach to the 1 (tx) pin on Arduino because it will totally screw your sketch!! And send you on an hour of debugging
// Make sure these are corrected in the right order! Taking some time to do it properly might save you a lot of work later.
//The pins for the joystick are:
int dirLeft = 47; // A
int dirRight = 49; // E
int dirUp = 53; // O
int dirDown = 51; //I

int mDO = 38;
int mDE = 40;
int mDI = 42;
int mDA = 44;
int mRO = 46;
int mRE = 48;
int mRI = 50;
int mRA = 52;

int led_red = 12;                   //rood
int led_green = 13;                 //groen

boolean Firstgroup = true;          // This Boolean is used for zooming in on the group DRMF, or the group AOEI
String Odywoord;                    // This is the Odyword which is a composition of one or more Odytekens
String Odyteken;                    // This is the Odyteken which constructs the Odywoord as selected at first
String OdytekenNOW;                 // This is the Odyteken which is currently selected
String tekst;                       //catches the text to print to the lcd-screen
int lengteTekst;                    //lengte van tekst, om de tekst af te kunnen rollen
int cursorKolom;                    //waar op de regel start de tekst
int cursorRij;                      //op welke regel start de tekst
boolean laatstaan;                  //waar als de tekst niet wordt weggepoetst na de pauze
int wachten;                        //bepaalt of en hoe lang gewacht wordt op de volgende tekst

boolean afrollen;                   // waar als de tekst afgerold moet worden
boolean FirstLetterDefined = false; // Variable distinguishing between first loop when looking for a first word, or second loop looking for second word
int holdtime = 2000;                // This sets how long the user have to hold the stick in a direction before selection is confirmed

int startholdtime;                  // This is a variable needed for keeping track of selection time
int endholdtime;                    // This is a variable needed for keeping track of selection time
int pausetime = 50;                 // Sets the time sketch pauzes after confirmation of letters
int turntime = 70;                  // Wait for a moment after selecting a motor and motor hold time
int readtime = 3000;                // Sets the time the info will be on the screen for Elinde's written messages
int count = 10;                     // Sets the time the info will be on the screen for Elinde's written messages
int announcetime = 1000;            // Time anouncing fal chip action

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
 
  Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
  lcd.init();
  lcd.backlight();
  
  tekst = "LATEN WE"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  tekst = "SPEL(L)EN"; cursorKolom = 9 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  tekst = "NU:"; cursorKolom = 0 ; cursorRij = 2;  afrollen = false; wachten = 1; laatstaan = true; lcd_print();    
  tekst = "Vier op een rij"; cursorKolom = 0 ; cursorRij =3; afrollen = false; wachten = 6; laatstaan = false; lcd_print();    
  
} // this bracket closes the setup loop. This loop plays only once. Part of it is the opening statement above anouncing gameplay will BEGIN!

//---------------------------------------------------------------------------
 
void loop() {

/*
This is the general part of the sketch. It is ALWAYS part of the sketch because it is the central loop 
It waits for input on diaganol, or hori-vertical choices on the joystick
If waits for specific kind of input based on the valua of "FirstLetterDefined".
If we need to add a third letter to Odyschrift, we eill need to add a third category here (with "firstletterdefined" changing to a three option INTEGER instead of a two option BOOLEAN).

*/

digitalWrite(led_green, LOW); //switch green LED to low
digitalWrite(led_red, LOW); //switch red LED to low
delay(100); // This tiny delay is nice to not flicker the LCD that will otherwise get a LOT of input from the final "else" statements.
  
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

void wisselgroep() {
 
  /* 
  This is a seperate function that simply switches the "first-letter-defined-mode" on and off. It is only used in function: "Odyletterswitch()"
  */
  
  if (FirstLetterDefined == true){
    FirstLetterDefined = false;
    }
  else {
    FirstLetterDefined = true;
    }
  }

//---------------------------------------------------------------------------

void actiontrigger() {

  /* 
  This is a seperate function that ges called when something actually needs to happen.
  It drops chips in the external board, but it also writes funny messages to the screen.
  It will execute depending on the Odywoord that has been set up at that point"
  */
  
    lcd.clear(); // clears the LCD screen first to start of with a blank slate
    
// checkcontact ("action");
  if (Odywoord == "DO"){
    tekst = "Chip DO valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (announcetime);
    digitalWrite (mDO, HIGH);
    delay (turntime);
    digitalWrite (mDO, LOW);
    // blink the red light of any such light event here
     }
  else if (Odywoord == "DE"){
    tekst = "Chip DE valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (announcetime);
    digitalWrite (mDE, HIGH);
    delay (turntime);
    digitalWrite (mDE, LOW);
    }
  else if (Odywoord == "DI"){
    tekst = "Chip DI valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (announcetime);
    digitalWrite (mDI, HIGH);
    delay (turntime);
    digitalWrite (mDI, LOW);
    }
  else if (Odywoord == "DA"){
    tekst = "Chip DA valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (announcetime);
    digitalWrite (mDA, HIGH);
    delay (turntime);
    digitalWrite (mDA, LOW);
    }
  else if (Odywoord == "RO"){
    tekst = "Chip RO valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    delay (announcetime);
    digitalWrite (mRO, HIGH);
    delay (turntime);
    digitalWrite (mRO, LOW);
    }
  else if (Odywoord == "RE"){
    tekst = "Chip RE valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (announcetime);
    digitalWrite (mRE, HIGH);
    delay (turntime);
    digitalWrite (mRE, LOW);
    }
  else if (Odywoord == "RI"){
    tekst = "Chip RI valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop Ihip
    delay (announcetime);
    digitalWrite (mRI, HIGH);
    delay (turntime);
    digitalWrite (mRI, LOW);
     }
  else if (Odywoord == "RA"){
    tekst = "Chip RA valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (announcetime);
    digitalWrite (mRA, HIGH);
    delay (turntime);
    digitalWrite (mRA, LOW);
    }
  else if (Odywoord == "MO"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = false; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = false; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = false; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "ME"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "MI"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "MA"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "FO"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "FE"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "FI"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "FA"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 1; laatstaan = true; lcd_print(); // 20 letters op rij 1
    Serial.println ("BOOM RIGHT HERE"); // Just ignore it. This was just a way of checking this scnario in the serial monitor.
    delay (3000);
    lcd.clear(); // clear
    }
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
