/*
String orientatie_uitgangspunt()
{
	int Odynummer;
	Odynummer = myOdy.CharNaarNummer(Odywoord);
	String strLetter;
	switch (Odynummer)
	{
		case 1://d
			strLetter = "ik";
		break;
		case 2://r
			strLetter = "jij";
		break;
		case 3://m
			strLetter = "afspraak";
		break;
		case 4://f
			strLetter = "noorden";
		break;
	}
return strLetter;
}
//---------------------------------------------------------------------------

String orientatie_plaats(String tekst)
{

}
//---------------------------------------------------------------------------
String orientatie_richting()
{
	int Odynummer;
	Odynummer = myOdy.CharNaarNummer(Odywoord);
	String strLetter;
	int cursorrij;
	int cursorkolom;
	switch (Odynummer){
		case 1://do
			cursorrij = 0; cursorkolom = 10;
			strLetter = "12";
		break;
		case 2://de
			cursorrij = 0; cursorkolom = 16;
			strLetter = "1";
		break;
				case 3://di
			cursorrij = 0; cursorkolom = 19;
					strLetter = "2";
				break;
				case 4://da
			cursorrij = 1; cursorkolom = 19;
					strLetter = "3";
				break;
				case 5://ro
			cursorrij = 2; cursorkolom = 19;
					strLetter = "4";
				break;
				case 6://re
			cursorrij = 3; cursorkolom = 16;
					strLetter = "5";
				break;
				case 7://ri
			cursorrij = 3; cursorkolom = 10;
					strLetter = "6";
				break;
				case 8://ra
			cursorrij = 3; cursorkolom = 7;
					strLetter = "7";
				break;
				case 9://mo
			cursorrij = 2; cursorkolom = 0;
					strLetter = "8";
				break;
				case 10://me
			cursorrij = 1; cursorkolom = 0;
					strLetter = "9";
				break;
				case 11://mi
			cursorrij = 0; cursorkolom = 0;
					strLetter = "10";
				break;
				case 12://ma
			cursorrij = 0; cursorkolom = 7;
					strLetter = "11";
				break;
				case 13://fo
			cursorrij = 1; cursorkolom = 9;
					strLetter = ")";
				break;
				case 14://fe
			cursorrij = 1; cursorkolom = 12;
					strLetter = ")))";
				break;
				case 15://fi
					strLetter = "o";
				break;
				case 16://fa
					strLetter = "p";
				break;

			}
	lcd.setCursor(cursorkolom,cursorrij);
	lcd.print (strLetter);
return strLetter;
}*/
//---------------------------------------------------------------------------
