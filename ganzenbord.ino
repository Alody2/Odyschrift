
void ganzenbord_worp()
	
{
	long geworpen;
	worp(2,0);
}
//---------------------------------------------------------------------------

void ganzenbord_plaatsen()
{
	int Odynummer;
	Odynummer = myOdy.CharNaarNummer(Odywoord);
	lcd.setCursor(9,0);
	lcd.print ("Ik zet");
	lcd.setCursor(9,1);

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
