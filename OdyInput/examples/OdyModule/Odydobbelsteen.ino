void dom_begin()
{
  	tekst = "LATEN WE DOBBELEN"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
	tekst = "D: 1 dobbelsteen"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  	tekst = "R: 2 dobbelstenen"; cursorKolom = 0 ; cursorRij = 2;  afrollen = false; wachten = 0; laatstaan = true; lcd_print();    
	tekst = "M: zet "; cursorKolom = 0 ; cursorRij =3; afrollen = false; wachten = 0; laatstaan = true; lcd_print(); 
//	tekst = "F:schakel"; cursorKolom = 11 ; cursorRij =3; afrollen = false; wachten = 0; laatstaan = true; lcd_print(); 
       	leds[6] = CRGB::Black; //     
       	leds[7] = CRGB::Black; //     
       	leds[8] = CRGB::Black; //     
       	leds[9] = CRGB(50,5,0); //     
  	leds[10] = CRGB(50,5,0); // 
  	leds[11] = CRGB(0,0,50); //
	FastLED.show();
}
void dom_actie()
{
	odyinput.overgang = false;
	while (wachtActie == false)
	{
		odyinput.selectieDRMF();
		if (odyinput.Odyteken == 'D' ||odyinput.Odyteken == 'R' )
		{
			dom_lichtaan();
			wachtActie = true;
		}
		else if (odyinput.Odyteken == 'N')
		{
		}
		else if (odyinput.Odyteken == 'M')
		{
			while (odyinput.Odyteken == 'M')
			{
				odyinput.selectieOEIA();
				lcd.setCursor(0, 0);
		  		lcd.print ("pion ?");
				wachtActie = true;
			}
			while (odyinput.Odyteken == 'N')
			{
				odyinput.selectieOEIA();
			}
			if (odyinput.Odyteken == 'O')
			{
				tekst = "MO"; 
				while (odyinput.Odyteken == 'O')
				{
					teller = 1;
					wissel();
				}
			}
			else if (odyinput.Odyteken == 'E')
			{
				tekst = "ME"; 
				while (odyinput.Odyteken == 'E')
				{
					teller = 1;
					wissel();
				}
			}
			else if (odyinput.Odyteken == 'I')
			{
				tekst = "MI"; 
				while (odyinput.Odyteken == 'I')
				{
					teller = 1;
					wissel();
				}
			}
			else if (odyinput.Odyteken == 'A')
			{
				tekst = "MA"; 
				while (odyinput.Odyteken == 'A')
				{
					teller = 1;
					wissel();
				}
			}
			while (odyinput.Odyteken == 'N')
			{
				delay(holdtime);
				odyinput.selectieDRMF();
			}
		
		}
		else if (odyinput.Odyteken == 'F')
		{
			instellenmodule();
		}
		else
		{
		}
	}
	wachtActie = false;
	odyinput.Odyteken = ' ';	
}
//---------------------------------------------------------------------------
void wissel()
{
	odyinput.selectieOEIA();
	if (teller == 1)
	{
		if (firstGroup == true)
		{
			firstGroup = false;
			cursorKolom = 0;
			cursorRij = 0;
			tekst = "zet 1: " + tekst; 
		  	afrollen = true; wachten = 0; laatstaan = true;     
			lcd_print();    
			teller = 2;
		}
		else
		{	firstGroup = true;
			cursorKolom = 14;
			cursorRij = 0;
			tekst = "zet 2: " + tekst; 
		  	afrollen = true; wachten = 0; laatstaan = true;     
			lcd_print();    
			teller = 2;
		}
	}
}
//---------------------------------------------------------------------------
void dom_lichtaan()
{
	if (odyinput.Odyteken == 'D')
	{
		lngWorp = 0;
		lcd.clear(); 
		plaats = -2;
		lngHerhaal = random(1,10);
		bedenktijd = random(500,3000);
		while (lngHerhaal > 0)
		{
			lngWorp = random(1,7);
			rood = random(1,200);
			groen = random(1,200);
			blauw = random(1,200);
			plaats += 2;
			if (lngHerhaal > 0)
			{
				delay (bedenktijd); 
				for (int i = 0;i <= 6; i++)
				{
					leds[i] = CRGB::Black;  
						
				}
			}
  		//	tekst = lngHerhaal; cursorKolom = plaats  ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  			tekst = lngWorp; cursorKolom = plaats  ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
			delay(holdtime);
			while (lngWorp > 0)
			{
				leds[lngWorp - 1] = CRGB(rood,groen,blauw);  
				lngWorp -= 1;
			}
			FastLED.show();
			lngHerhaal -= 1;
		}
	}
	if (odyinput.Odyteken == 'R')
	{
		lngWorp = 0;
		lcd.clear(); 
		FastLED.clear();
		plaats = -2;
		lngHerhaal = random(1,10);
		bedenktijd = random(500,4000);
		while (lngHerhaal > 0)
		{
			lngWorp = random(1,7);
			rood = random(1,200);
			groen = random(1,200);
			blauw = random(1,200);
			plaats += 2;
			if (lngHerhaal > 1)
			{
				delay (bedenktijd); 
				for (int i = 0;i <= 6; i++)
				{
					leds[i] = CRGB::Black;  
						
				}
  				tekst = lngWorp; cursorKolom = plaats  ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
				while (lngWorp > 0)
				{
					leds[lngWorp - 1] = CRGB(rood,groen,blauw);  
					lngWorp -= 1;
				}
			}
  		//	tekst = lngHerhaal; cursorKolom = plaats  ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
			FastLED.show();
			lngHerhaal -= 1;
		}
		plaats = -2;
		lngHerhaal = random(1,10);
		while (lngHerhaal > 0)
		{
			lngWorp = random(1,7);
			rood = random(1,200);
			groen = random(1,200);
			blauw = random(1,200);
			plaats += 2;
			if (lngHerhaal > 1)
			{
				delay (bedenktijd); 
				for (int i = 6;i <= 11; i++)
				{
					leds[i] = CRGB::Black;  
						
				}
  				tekst = lngWorp; cursorKolom = plaats  ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
				while (lngWorp > 0)
				{
					leds[lngWorp + 5] = CRGB(rood,groen,blauw);  
					lngWorp -= 1;
				}
			}
  		//	tekst = lngHerhaal; cursorKolom = plaats  ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
			FastLED.show();
			lngHerhaal -= 1;
		}
	}
	FastLED.show();
	delay(holdtime);
}
//---------------------------------------------------------------------------

