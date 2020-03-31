/* 
This sketch is part of the Odyschrift project. It has been originally created by Alle v Meeteren and modified by Jurre Ongering
This project enables physically handicapped people to play a game of "connect-four". A joystick is used as a controller. 
The joystick has 8 contacts.

 * The joystick can activate a single contact (4 directions)  or 2 contacts (4 directions between the other 4 directions) at a time.
 * In the neutral state none of these is active. In our implementation the joystick has to return to that neutral state, before the next direction can be chosen.
 * We alternate between the 2 groups, so there is a variable to indicate which group is the active group. 

The project also includes the LiquidCrystal Library Library originally added 18 Apr 2008 by David A. Mellis // library modified 5 Jul 2009 by Limor Fried (http://www.ladyada.net) // 
example added 9 Jul 2009 by Tom Igoe // modified 22 Nov 2010 by Tom Igoe // modified 7 Nov 2016 by Arturo Guadalupi/ More info:
http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld 

27-6-2019: pinnumbers to connect to the board  , added action for all combinations of 2 Odyletters.
 */
#include <LiquidCrystal.h> // include the library code
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = A5, d5 = A4, d6 = A3, d7 = A2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
// NEVER define any of these pins to attach to the 1 (tx) pin on Arduino because it will totally screw your sketch!! And send you on an hour of debugging
// Make sure these are corrected in the right order! Taking some time to do it properly might save you a lot of work later.
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
String Odyteken;              // This is the Odyteken which constructs the Odywoord
boolean FirstLetterDefined = false; // Variable distinguishing between first loop when looking for a first word, or second loop looking for second word
int holdtime = 1000;          // This sets how long the user have to hold the stick in a direction before selection is confirmed
int startholdtime;            // This is a variable needed for keeping track of selection time
int endholdtime;              // This is a variable needed for keeping track of selection time
int pausetime = 3000;         // Sets the time sketch pauzes after confirmation of letters
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
 
Serial.begin(9600);     //turning on of the serial monitor to inspect the result.

lcd.begin(16, 2);       // set up the LCD's number of columns and rows:
  
lcd.print("LETS!!");      // Print a message to the LCD.
lcd.setCursor(0, 1);    // position for next print --> (0,1) column 0 (is first column) and row 1 (is second row). 
lcd.print("PLAY");      // Print a message to the LCD.
delay(1000);            // wait one sec
lcd.clear();            // clear
lcd.print("NOW");       // Print a message to the LCD.
delay(1000);            // wait two sec
lcd.clear();            // clear
}

//---------------------------------------------------------------------------

void loop(){

digitalWrite(led_green, LOW); //switch green LED to low
digitalWrite(led_red, LOW); //switch red LED to low
delay(30); // This tiny delay is nice to not flicker the LCD that will otherwise get a LOT of input from the final "else" statements.

if (FirstLetterDefined == false){
  if ( digitalRead( dirUp ) == LOW && digitalRead( dirLeft ) == LOW ){
  Odyteken = 'D';
  gekozen();
  }
  else if ( digitalRead( dirUp ) == LOW && digitalRead( dirRight ) == LOW ){
  Odyteken = 'R';
  gekozen();
  }       
  else if ( digitalRead( dirDown ) == LOW && digitalRead( dirRight ) == LOW ){
  Odyteken = 'M';
  gekozen();
  }
  else if ( digitalRead( dirDown ) == LOW && digitalRead( dirLeft ) == LOW ){
  Odyteken = 'F';
  gekozen();
  }
  else { // this else statement makes sure the user gets some instruction on the LED
  lcd.clear(); // clear
  lcd.print("Kies teken 1");   // Print a message to the LCD.
  }
}
    
else{ // If the first grout is not false, then we are already looking for the second letter,
  if( digitalRead( dirUp ) == LOW ) {
  Odyteken = 'O';
  gekozen();
  }
  else if( digitalRead( dirRight ) == LOW ) {
  Odyteken = 'E';
  gekozen();
  }
  else if( digitalRead( dirDown ) == LOW ){
  Odyteken = 'I';
  gekozen();
  }
  else if( digitalRead( dirLeft ) == LOW ){
  Odyteken = 'A';
  gekozen();
  }
  else{ // this else statement makes sure the user gets some instruction on the LED
  lcd.clear(); // clear
  lcd.print("Kies teken 2");   // Print a message to the LCD.
  }
}
}

//---------------------------------------------------------------------------

void gekozen() {   // This is a seperate fuction that is called based on scenario above.
  if (FirstLetterDefined == false){ // This if statement checks if the logic has to go into the first or second letter selection scenario. 
  Serial.print ("Seems you want to select the FIRST letter: ");
  startholdtime = millis();//startholdtime is set to 0
  endholdtime = millis();//endholdtime is set to 0
  digitalWrite(led_red, HIGH); //the red LED is switched on
  Odywoord = Odywoord + Odyteken; //the character related with the chosen direction is added to the word. When looking for first letter, Odyteken will be "" and one letter is added to Odywoord
  Serial.print (Odywoord); //the word is printed in the serial
  Serial.println (" Hold joystick for selection");

  // lcd action
  lcd.clear(); // clears the LCD
  lcd.print("Houd vast voor:");   // Print a message to the LCD.
  lcd.setCursor(8, 1); // position for next print --> (0,1) column 8 (is 8th column) and row 1 (is second row). 
  lcd.print(Odywoord);   // Print a message to the LCD.

    while ((endholdtime - startholdtime) < holdtime){
    endholdtime = millis(); // endholdtime is updated
    delay(40); 

      if ( digitalRead( dirUp ) == HIGH && digitalRead( dirRight ) == HIGH && digitalRead( dirDown ) == HIGH && digitalRead( dirLeft ) == HIGH ){
      digitalWrite(led_green, LOW);//clock passes the set time Als joystock neutraal is... 
      digitalWrite(led_red, LOW);
      Odywoord = "";
      delay(pausetime);
      Serial.println (" Too short for first letter selection. Choose again");

      // lcd action part that defines what should be displayed on the LCD screen
      lcd.clear(); // clear
      lcd.print("Houd langer vast!");   // Print a message to the LCD.

      break; // This kills the loop
      
      }
              
      if((endholdtime - startholdtime) > holdtime){ //de knop is zolang inhehouden dat de waarde definitief wordt!      
      Serial.print ("SUCCESS!! First letter has been noted (lisa koning) and it is: ");
      Serial.println (Odywoord);//the word is printed
      digitalWrite(led_green, HIGH);//green led on! 
      digitalWrite(led_red, LOW);
      wisselgroep();
      Odyteken = "";
      FirstLetterDefined = true;

      // lcd action part that defines what should be displayed on the LCD screen
      lcd.clear(); // clear
      lcd.print(String("Je kiest:"));   // Print a message to the LCD.
      lcd.setCursor(8, 1); // position for next print --> (0,1) column 0 (is first column) and row 1 (is second row). 
      lcd.print(Odywoord);   // Print a message to the LCD. <-- msut be write or else string will be converted to ASCII

      
      delay(pausetime);
      }  
    }
  }
    
  else if (FirstLetterDefined == true){ // Dit gaan we doen als er een letter bijkomt TWEEDE LETTER SCENARIO
  Serial.print ("Seems you want to select the SECOND letter: ");
  startholdtime = millis();//startholdtime is set to 0
  endholdtime = millis();//endholdtime is set to 0
  digitalWrite(led_red, HIGH);
  Odywoord = Odywoord + Odyteken;//the character related with the chosen direction is added to the word  Eerste keer is odywoord nog niets...
  Serial.print (Odywoord);//the word is printed
  Serial.println (" Hold joystick for selection");

  // lcd action part that defines what should be displayed on the LCD screen
  lcd.clear(); // clear
  lcd.print("Houd vast voor:");   // Print a message to the LCD.
  lcd.setCursor(8, 1); // position for next print --> (0,1) column 8 (is 8th column) and row 1 (is second row). 
  lcd.print(Odywoord);   // Print a message to the LCD. <-- msut be write or else string will be converted to ASCII
  
    while ((endholdtime - startholdtime) < holdtime){
    endholdtime = millis();
    delay(40);
    // Serial.println ("I'm busy looping 2");
    //checkcontact(OdyWoord);
    
      if ( digitalRead( dirUp ) == HIGH && digitalRead( dirRight ) == HIGH && digitalRead( dirDown ) == HIGH && digitalRead( dirLeft ) == HIGH ){
      digitalWrite(led_green, LOW); // Green light on!
      digitalWrite(led_red, LOW);
      Odywoord.remove(1, 1); // This goes to the second position in the Oduwoord string (index 1) and deletes one character.
      delay(pausetime);
      Serial.println ("Too short for second letter selection. Choose again");

      // lcd action part that defines what should be displayed on the LCD screen
      lcd.clear(); // clear
      lcd.print("Houd langer vast!");   // Print a message to the LCD.
      
      break; // This kills the loop
      }
          
      if((endholdtime - startholdtime) > holdtime){  //de knop is zolang inhehouden dat de waarde definitief wordt!
      Serial.print ("SUCCESS!! Second letter has been noted and it is: ");
      Serial.println (Odywoord);//the word is printed
      digitalWrite(led_green, HIGH); //Green Llight on! 
      digitalWrite(led_red, LOW);
      wisselgroep();
 
      
      // lcd action part that defines what should be displayed on the LCD screen
      lcd.clear(); // clear
      lcd.print("Odywoord is:");   // Print a message to the LCD.
      lcd.setCursor(8, 1); // position for next print --> (0,1) column 0 (is first column) and row 1 (is second row). 
      lcd.print(Odywoord);   // Print a message to the LCD. <-- msut be write or else string will be converted to ASCII
      delay(pausetime); 

      actiontrigger(); // This is an IMPORTANT trigger to the actions that we connect to the odywords.
      
      Odywoord = "";
      FirstLetterDefined = false;
      
      }
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

void actiontrigger() {
  if (Odywoord == "DO"){
  lcd.clear(); // clear
  lcd.print("Chip 1 Valt");   // Print a message to the LCD.
  //action-->drop chip
    delay (turntime);
  digitalWrite (mDO, HIGH);
  delay (turntime);
  digitalWrite (mDO, LOW);
  }
  else if (Odywoord == "DE"){
  lcd.clear(); // clear
  lcd.print("Chip 2 Valt");   // Print a message to the LCD.
  //action-->drop chip
    delay (turntime);
  digitalWrite (mDE, HIGH);
  delay (turntime);
  digitalWrite (mDE, LOW);
  }
  else if (Odywoord == "DI"){
  lcd.clear(); //clear
  lcd.print("Chip 3 Valt");   // Print a message to the LCD.
  //action-->drop chip
  delay (turntime);
  digitalWrite (mDI, HIGH);
  delay (turntime);
  digitalWrite (mDI, LOW);

  }
  else if (Odywoord == "DA"){
  lcd.clear(); // clear
  lcd.print("Chip 4 Valt");   // Print a message to the LCD.
  //action-->drop chip
   delay (turntime);
  digitalWrite (mDA, HIGH);
  delay (turntime);
  digitalWrite (mDA, LOW);
  }
  else if (Odywoord == "RO"){
  lcd.clear(); // clear  lcd.print("Chip 5 Valt");   // Print a message to the LCD.
  //action-->drop chip
    delay (turntime);
  digitalWrite (mRO, HIGH);
  delay (turntime);
  digitalWrite (mRO, LOW);
  }
  else if (Odywoord == "RE"){
  lcd.clear(); // clear
  lcd.print("Chip 6 Valt");   // Print a message to the LCD.
  //action-->drop chip
    delay (turntime);
  digitalWrite (mRE, HIGH);
  delay (turntime);
  digitalWrite (mRE, LOW);
  }
  else if (Odywoord == "RI"){
  lcd.clear(); // clear
  lcd.print("Chip 7 Valt");   // Print a message to the LCD.
  //action-->drop chip
   delay (turntime);
  digitalWrite (mRI, HIGH);
  delay (turntime);
  digitalWrite (mRI, LOW);
  }
  else if (Odywoord == "RA"){
  lcd.clear(); // clear
  lcd.print("Chip 8 Valt");   // Print a message to the LCD.
  //action-->drop chip
    delay (turntime);
  digitalWrite (mRA, HIGH);
  delay (turntime);
  digitalWrite (mRA, LOW);
  }
  else if (Odywoord == "MO"){
  lcd.clear(); // clear
  lcd.print("Venus is Crazy");   // Print a message to the LCD.
  delay (1000);
  }
  else if (Odywoord == "ME"){
  lcd.clear(); // clear
  lcd.print("Please dont fart!");   // Print a message to the LCD.
  delay (1000);
  }
  else if (Odywoord == "MI"){
  lcd.clear(); // clear
  lcd.print("Jurre is great");   // Print a message to the LCD.
  delay (1000);
  }
  else if (Odywoord == "MA"){
  lcd.clear(); // clear
  lcd.print("Life is good!");   // Print a message to the LCD.
  delay (1000);
  }
 :q: else if (Odywoord == "FO"){
  lcd.clear(); // clear
  lcd.print("Venus is Crazy");   // Print a message to the LCD.
  delay (1000);
  }
  else if (Odywoord == "FE"){
  lcd.clear(); // clear
  lcd.print("Please dont fart!");   // Print a message to the LCD.
  delay (1000);
  }
  else if (Odywoord == "FI"){
  lcd.clear(); // clear
  lcd.print("Jurre is great");   // Print a message to the LCD.
  delay (1000);
  }
  else if (Odywoord == "FA"){
  lcd.clear(); // clear
  lcd.print("Jurre is great");   // Print a message to the LCD.
  delay (1000);
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


