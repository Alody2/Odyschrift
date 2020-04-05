
void mastermind(int cursor)
	
{
	int Odynummer;
	String strLetter;
	Odynummer = myOdy.CharNaarNummer(Odywoord);
	switch (Odynummer)
	{
		case 1://do
			strLetter = "Zwart";//zwart
		break;
		case 2://de
			strLetter = "Wit  ";//wit
		break;
		case 3://di
			strLetter = "Rood ";//rood
		break;
		case 4://da
			strLetter = "Geel ";//geel
		break;
		case 5://ro
			strLetter = "Groen";//groen
		break;
		case 6://re
			strLetter = "Blauw";//blauw
		break;
		case 7://ri
			strLetter = "Leeg ";//leeg
		break;
	}
	lcd.setCursor (cursor,0);
	lcd.print (strLetter);
/*	if (lcd_ver == true)
	{
		Serial2.print (strLetter);
	}*/
}
//---------------------------------------------------------------------------
void uitslag(int ronde)
{
	int Odynummer;
	Odynummer = myOdy.CharNaarNummer(Odywoord);
	switch (ronde)
	{
		case 1:
			lcd.setCursor(4,1);
		break;
		case 2:
			lcd.setCursor(6,1);
		break;
		case 3:
			lcd.setCursor(4,2);
		break;
		case 4:
			lcd.setCursor(10,2);
			lcd.print ("Dit is het");
			lcd.setCursor(6,2);
		break;
	}
	switch (Odynummer)
	{
		case 1:
			lcd.write (4);
			Serial2.print (4);
		break;
		case 2:
			lcd.write (5);
			Serial2.print (5);
		break;
		case 3:
			//lcd.print ();
		break;
		case 64:
			lcd.setCursor(10,2);
			lcd.print ("Geraden");
			Serial2.print ("Geraden");
		//	lcd_ver = true; //nu zelf raden
			Odynummer = 7;
		break;
	}
	
}
