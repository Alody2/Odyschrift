
void wachttijd()
{
	int Odynummer;
	Odynummer = myOdy.CharNaarNummer(Odywoord);
		lcd.setCursor(0,0);
	switch (Odynummer)
	{
		case 1:
			holdtime = holdtime - 100;
		break;
		case 2:
			holdtime = holdtime + 100;
		break;
		case 3:
			holdtime = 500;

		break;

	}
		lcd.print ("wachttijd is " + holdtime );
}

