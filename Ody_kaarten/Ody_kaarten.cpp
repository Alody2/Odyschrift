
int ronde; //ronde teller
//ogen van dobbelsteen
	lcd.createChar(0, harten);
	lcd.createChar(1, ruiten);
	lcd.createChar(2, schoppen);
	lcd.createChar(4, oog_dicht);
	lcd.createChar(5, oog_open);
	lcd.createChar(6, grens);
	lcd.createChar(7, grens_2);
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
byte harten[8] = 
{
	  B01010,
	  B11111,
	  B11111,
	  B11111,
	  B01110,
	  B00100,
	  B00000,
	  B00000,
}; 

byte ruiten[8] = 
{
  	B00100,
	  B01110,
	  B11111,
	  B11111,
	  B01110,
	  B00100,
	  B00000,
	  B00000,
}; 

byte schoppen[8] = 
{
	  B00100,
	  B01110,
	  B11111,
	  B11111,
	  B00100,
	  B01110,
	  B00000,
	  B00000,
}; 

byte klaver[8] =
{
 	 B01110,
	  B01110,
	  B11111,
	  B11111,
	  B00100,
	  B01110,
	  B00000,
	  B00000,
};
byte grens[8] = 
{
	  B00001,
	  B00001,
	  B00001,
	  B00001,
	  B00001,
	  B00001,
	  B00001,
	  B00001
};
byte grens_2[8] =
{
	  B10000,
	  B10000,
	  B10000,
	  B10000,
	  B10000,
	  B10000,
	  B10000,
	  B10000
};
