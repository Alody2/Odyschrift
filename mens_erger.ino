void plaatsen4(int cursor,int rij)
{
	int Odynummer;
	Odynummer = myOdy.CharNaarNummer(Odywoord);
	lcd.setCursor(cursor,rij);
	lcd.print ("Ik zet");
	lcd.setCursor(cursor,rij +1);

	switch (Odynummer)
	{
		case 1:
			lcd.print ("de voorste");
		break;
		case 2:
			lcd.print ("de tweede");
		break;
		case 3:
			lcd.print ("de derde");
		break;
		case 64:
			lcd.print ("de laatste");
		break;
	}


}
