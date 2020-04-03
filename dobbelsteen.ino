
void dobbelsteen(int groep)
	
{
	int Odynummer;
	Odynummer = myOdy.CharNaarNummer(Odywoord);
	switch (Odynummer)
	{
		case 64:
				tekst = module();  eerste_schrijf_loop = false; cursorKolom = 2; cursorRij = 3;
				lcd_print();
				FirstLetterDefined = false;
				Odywoord = ""; //Odywoord geleegd voor volgende
		break;
		default:
			worp(Odynummer,groep);
	}
}
//---------------------------------------------------------------------------
void worp(int Odynummer, int groep)
{
	int cursorBasis;
	int oog;
	long lngWorp = 0;
	if (groep == 9 || (groep == 0 && Odynummer == 3) )
	{
	/*	belijning (7,0,0);belijning (7,0,1); belijning (7,0,2);
		belijning (6,2,0);belijning (6,2,1); belijning (6,2,2);*/
		belijning (7,3,0);belijning (7,3,1); belijning (7,3,2);
		belijning (6,5,0);belijning (6,5,1); belijning (6,5,2);
	/*	belijning (7,6,0);belijning (7,6,1); belijning (7,6,2);
		belijning (6,8,0);belijning (6,8,1); belijning (6,8,2);*/
		oog = 4;
		cursorBasis = 0;
		lngWorp = random(1,7);
		plaatsen(lngWorp,oog,cursorBasis); 
		oog = 5;
		cursorBasis = 3;
		lngWorp = random(1,7);
		plaatsen(lngWorp,oog,cursorBasis); 
		oog = 4;
		cursorBasis = 6;
		lngWorp = random(1,7);
		plaatsen(lngWorp,oog,cursorBasis); 
	}
	switch (Odynummer)
	{
		case 1:
			if (groep == 9)
			{
				belijning (7,0 + groep,0);belijning (7,0 + groep,1); belijning (7,0 + groep,2);
				belijning (6,2 + groep,0);belijning (6,2 + groep,1); belijning (6,2 + groep,2);
				oog = 5;
			}
			else
			{
			/*	belijning (7,0,0);belijning (7,0,1); belijning (7,0,2);
				belijning (6,2,0);belijning (6,2,1); belijning (6,2,2);*/
				oog = 4;
			}
			cursorBasis = groep;
			lngWorp = random(1,7);
			plaatsen(lngWorp,oog,cursorBasis); 
		break;
		case 2:
			if (groep == 9)
			{
				belijning (7,groep,0);belijning (7,groep,1); belijning (7,groep ,2);
				belijning (6,2 + groep,0);belijning (6,2 + groep,1); belijning (6,2 + groep,2);
				oog = 5;
			}
			else
			{
				belijning (7,3,0);belijning (7,3,1); belijning (7,3,2);
				belijning (6,5,0);belijning (6,5,1); belijning (6,5,2);
				oog = 4;
			}
			cursorBasis = 0 + groep;
			lngWorp = random(1,7);
			plaatsen(lngWorp,oog,cursorBasis); 
			if (groep == 9)
			{
				/*belijning (7,3 + groep,0);belijning (7,3 + groep,1); belijning (7,3 + groep ,2);
				belijning (6,5 + groep,0);belijning (6,5 + groep,1); belijning (6,5 + groep,2);*/
				oog = 4;
			}
			else
			{
				oog = 5;
			}
			cursorBasis = 3 + groep;
			lngWorp = random(1,7);
			plaatsen(lngWorp,oog,cursorBasis); 
		break;
		case 3:
			if (groep == 9)
			{
				belijning (7,groep,0);belijning (7,groep,1); belijning (7,groep ,2);
				belijning (6,2 + groep,0);belijning (6,2 + groep,1); belijning (6,2 + groep,2);
			/*	belijning (7,3 + groep,0);belijning (7,3 + groep,1); belijning (7,3 + groep ,2);
				belijning (6,5 + groep,0);belijning (6,5 + groep,1); belijning (6,5 + groep,2);*/
				belijning (7,6 + groep,0);belijning (7,6 + groep,1); belijning (7,6 + groep,2);
				belijning (6,8 + groep,0);belijning (6,8 + groep,1); belijning (6,8 + groep,2);
				oog = 5;
				cursorBasis =0 + groep;
				lngWorp = random(1,7);
				plaatsen(lngWorp,oog,cursorBasis);
				oog = 4;
				cursorBasis = 3 + groep;
				lngWorp = random(1,7);
				plaatsen(lngWorp,oog,cursorBasis); 
				oog = 5;
				cursorBasis = 6 + groep;
				lngWorp = random(1,7);
				plaatsen(lngWorp,oog,cursorBasis); 
			}	
		break;

	}
}

void plaatsen(long lngWorp,int oog, int cursorBasis)
{
	delay (random(100,1500));


	if (lngWorp == 1)
	{
		lcd.setCursor(1 + cursorBasis,1);
		lcd.write (oog);
	}
	if (lngWorp == 2)
	{
		lcd.setCursor(0 + cursorBasis,0);
		lcd.write (oog);
		lcd.setCursor(2 + cursorBasis,2);
		lcd.write (oog);
	}
	if (lngWorp == 3)
	{
		lcd.setCursor(0 + cursorBasis,0);
		lcd.write (oog);
		lcd.setCursor(1 + cursorBasis,1);
		lcd.write (oog);
		lcd.setCursor(2 + cursorBasis,2);
		lcd.write (oog);
	}
	if (lngWorp == 4)
	{
		lcd.setCursor(0 + cursorBasis,0);
		lcd.write (oog);
		lcd.setCursor(2 + cursorBasis,0);
		lcd.write (oog);
		lcd.setCursor(2 + cursorBasis,2);
		lcd.write (oog);
		lcd.setCursor(0 + cursorBasis,2);
		lcd.write (oog);
	}
	if (lngWorp == 5)
	{
		lcd.setCursor(0 + cursorBasis,0);
		lcd.write (oog);
		lcd.setCursor(2 + cursorBasis,0);
		lcd.write (oog);
		lcd.setCursor(1 + cursorBasis,1);
		lcd.write (oog);
		lcd.setCursor(2 + cursorBasis,2);
		lcd.write (oog);
		lcd.setCursor(0 + cursorBasis,2);
		lcd.write (oog);
	}
	if (lngWorp == 6)
	{
		lcd.setCursor(0 + cursorBasis,0);
		lcd.write (oog);
		lcd.setCursor(2 + cursorBasis,0);
		lcd.write (oog);
		lcd.setCursor(0 + cursorBasis,1);
		lcd.write (oog);
		lcd.setCursor(2 + cursorBasis,1);
		lcd.write (oog);
		lcd.setCursor(0 + cursorBasis,2);
		lcd.write (oog);
		lcd.setCursor(2 + cursorBasis,2);
		lcd.write (oog);
	}
}

void belijning (int teken, int kolom, int rij)
{
		lcd.setCursor(kolom,rij);
		lcd.write (teken);
}

