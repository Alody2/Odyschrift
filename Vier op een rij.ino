/* 
This sketch is part of the Odyschrift project. It has been originally created by Alle v Meeteren and modified by Jurre Ongering
This project enables physically handicapped people to play a game of "connect-four". A joystick is used as a controller. 
The joystick has 8 contacts.

 * The joystick can activate a single contact (4 directions)  or 2 contacts (4 directions between the other 4 directions) at a time.
 * In the neutral state none of these is active. In our implementation the joystick has to return to that neutral state, before the next direction can be chosen.
 * We alternate between the 2 groups, so there is a variable to indicate which group is the active group. 


27-6-2019: pinnumbers to connect to the board  , added action for all combinations of 2 Odyletters.
 */
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

//---------------------------------------------------------------------------

void setup() {

/* 
put your setup code here, to run once. Below, the joystick related pins are defined as 
digital inputs (reading on or off)
*/
pinMode(mDO , OUTPUT); 
pinMode(mDE , OUTPUT); 
pinMode(mDI , OUTPUT); 
pinMode(mDA , OUTPUT); 
pinMode(mRO , OUTPUT); 
pinMode(mRE , OUTPUT); 
pinMode(mRI , OUTPUT); 
pinMode(mRA , OUTPUT); 

}

//---------------------------------------------------------------------------

void loop() {
  if (Odywoord == "DO"){
tekst = "Chip DO valt"; cursorKolom = 0 ; cursorRij = 3; wachten2 = false; wachten = 1; lcd_print();    
  //action-->drop chip
    delay (turntime);
  digitalWrite (mDO, HIGH);
  delay (turntime);
  digitalWrite (mDO, LOW);
  }
  else if (Odywoord == "DE"){
tekst = "Chip DE valt"; cursorKolom = 0 ; cursorRij = 3; wachten2 = false; wachten = 1; lcd_print();    
  //action-->drop chip
    delay (turntime);
  digitalWrite (mDE, HIGH);
  delay (turntime);
  digitalWrite (mDE, LOW);
  }
  else if (Odywoord == "DI"){
tekst = "Chip DI valt"; cursorKolom = 0 ; cursorRij = 3; wachten2 = false; wachten = 1; lcd_print();    
  //action-->drop chip
  delay (turntime);
  digitalWrite (mDI, HIGH);
  delay (turntime);
  digitalWrite (mDI, LOW);

  }
  else if (Odywoord == "DA"){
tekst = "Chip DA valt"; cursorKolom = 0 ; cursorRij = 3; wachten2 = false; wachten = 1; lcd_print();    
  //action-->drop chip
   delay (turntime);
  digitalWrite (mDA, HIGH);
  delay (turntime);
  digitalWrite (mDA, LOW);
  }
  else if (Odywoord == "RO"){
tekst = "Chip RO valt"; cursorKolom = 0 ; cursorRij = 3; wachten2 = false; wachten = 1; lcd_print();    
    delay (turntime);
  digitalWrite (mRO, HIGH);
  delay (turntime);
  digitalWrite (mRO, LOW);
  }
  else if (Odywoord == "RE"){
tekst = "Chip RE valt"; cursorKolom = 0 ; cursorRij = 3; wachten2 = false; wachten = 1; lcd_print();    
  //action-->drop chip
    delay (turntime);
  digitalWrite (mRE, HIGH);
  delay (turntime);
  digitalWrite (mRE, LOW);
  }
  else if (Odywoord == "RI"){
tekst = "Chip RI valt"; cursorKolom = 0 ; cursorRij = 3; wachten2 = false; wachten = 1; lcd_print();    
  //action-->drop Ihip
   delay (turntime);
  digitalWrite (mRI, HIGH);
  delay (turntime);
  digitalWrite (mRI, LOW);
  }
  else if (Odywoord == "RA"){
tekst = "Chip RA valt"; cursorKolom = 0 ; cursorRij = 3; wachten2 = false; wachten = 1; lcd_print();    
  //action-->drop chip
    delay (turntime);
  digitalWrite (mRA, HIGH);
  delay (turntime);
  digitalWrite (mRA, LOW);
  }
  else if (Odywoord == "MO"){
//zet de beginstand weer aan
  lcd.clear(); // clear
 startModus = true; 
  delay (1000);
  }
  else if (Odywoord == "ME"){
//verhoogt de reactietijd met een halve seconde
	holdtime = holdtime + 500;	
  }
  else if (Odywoord == "MI"){
//verlaagt de reactietijd met een halve seconde
	if (holdtime > 500){
		holdtime = holdtime - 500;
	}	
  }
  else if (Odywoord == "MA"){
tekst = "gereserveerd"; cursorKolom = 0 ; cursorRij = 3; wachten2 = false; wachten = 1; lcd_print();    
  }
  else if (Odywoord == "FO"){
tekst = "gereserveerd"; cursorKolom = 0 ; cursorRij = 3; wachten2 = false; wachten = 1; lcd_print();    
  }
  else if (Odywoord == "FE"){
tekst = "gereserveerd"; cursorKolom = 0 ; cursorRij = 3; wachten2 = false; wachten = 1; lcd_print();    
  }
  else if (Odywoord == "FI"){
tekst = "gereserveerd"; cursorKolom = 0 ; cursorRij = 3; wachten2 = false; wachten = 1; lcd_print();    
  }
  else if (Odywoord == "FA"){
Serial.print( "FA");
		tekst = "Naar schakelbord" ; cursorKolom = 0 ; cursorRij =0;  wachten2 = false; wachten = 1; lcd_print();    
intModule = 5;
  }
if (Odywoord.length()==2){
	Odywoord= "";
	cursorRij = 1; wachten = 2; lcd_print();    
}

}
