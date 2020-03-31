/* 
This sketch executes the signals sent by an Arcade joystick using bluetooth as part of the Odyschrift project.
It has been created by Alle v Meeteren. Its base is an earlier sketch, modified by Jurre Ongering
This project enables physically handicapped people to play a game of "connect-four".

The joystick has 8 contacts.

versie 0.1 : 29-6-2019 strippen van Joystick v1.1. Het ontvangende gedeelte ervan komt in deze sketch.

 
 */
/the pins the Arduino Uno to the 8 motors
int mDO =  4;
int mDE =  5;
int mDI =  6;
int mDA =  7;
int mRO =  8;
int mRE =  9;
int mRI = 10;
int mRA = 11;

/variables related to recieving signals
int btIn = 3;
int btOut = 2;
int btAt = 1;

String Odywoord;              // This is the Odyword which is a composition of one or more Odytekens
String Odyteken;              // This is the Odyteken which constructs the Odywoord
//---------------------------------------------------------------------------

void setup() {

/* 
put your setup code here, to run once.
*/

pinMode(mDO , OUTPUT); 
pinMode(mDE , OUTPUT); 
pinMode(mDI , OUTPUT); 
pinMode(mDA , OUTPUT); 
pinMode(mRO , OUTPUT); 
pinMode(mRE , OUTPUT); 
pinMode(mRI , OUTPUT); 
pinMode(mRA , OUTPUT);
 
pinMode(btIn, INPUT); 
pinMode(btOut,OUTPUT); 
pinMode(btAt, OUTPUT); 

}

//---------------------------------------------------------------------------

void loop(){

Odyteken = '';



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



