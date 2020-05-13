void dod_begin()
{
  	tekst = "LATEN WE"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  	tekst = "SPEL(L)EN"; cursorKolom = 9 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
	tekst = "NU:"; cursorKolom = 0 ; cursorRij = 2;  afrollen = false; wachten = 0; laatstaan = true; lcd_print();    
	tekst = "Vier op een rij"; cursorKolom = 0 ; cursorRij =3; afrollen = false; wachten = 0; laatstaan = false; lcd_print(); 
       	leds[6] = CRGB::Black; //     
       	leds[7] = CRGB::Black; //     
       	leds[8] = CRGB::Black; //     
       	leds[9] = CRGB(50,5,0); //     
  	leds[10] = CRGB(50,5,0); // 
  	leds[11] = CRGB(50,0,0); //
	FastLED.show();
}
void dod_actie()
{
	if (_Odywoord == "DO")
	{
    	tekst = "Chip DO valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mDO, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDO, LOW);
	}
	if (_Odywoord == "DE")
	{
    tekst = "Chip DE valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mDE, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDE, LOW);
	}
	if (_Odywoord == "DI")
	{
    tekst = "Chip DI valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mDI, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDI, LOW);
	}
	if (_Odywoord == "DA")
	{
    tekst = "Chip DA valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mDA, HIGH);
    		delay (_turntime);
   		digitalWrite (_mDA, LOW);
	}
	if (_Odywoord == "RO")
	{
    tekst = "Chip RO valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mRO, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRO, LOW);
	}
	if (_Odywoord == "RE")
	{
    tekst = "Chip RE valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mRE, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRE, LOW);
	}
	if (_Odywoord == "RI")
	{
    tekst = "Chip RI valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mRI, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRI, LOW);
	}
	if (_Odywoord == "RA")
	{
    tekst = "Chip RA valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    		delay (_turntime);
   		digitalWrite (_mRA, HIGH);
    		delay (_turntime);
   		digitalWrite (_mRA, LOW);
	}
	else if (_Odywoord == "ME")
	{
		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
		tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
		delay (readtime);
		lcd.clear(); // clear
	 }
	else if (_Odywoord == "MI")
	{
		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
		tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
		delay (readtime);
		lcd.clear(); // clear
	}
	else if (_Odywoord == "MA")
	{
		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
		tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
		delay (readtime);
		lcd.clear(); // clear
	}
	else if (_Odywoord == "FO")
	{
		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
		tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
		delay (readtime);
		lcd.clear(); // clear
	}
	else if (_Odywoord == "FE")
	{
		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
		tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
		delay (readtime);
		lcd.clear(); // clear
	}
	else if (_Odywoord == "FI")
	{
		tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
		tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
		tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
		tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
		delay (readtime);
		lcd.clear(); // clear
	}
	else if (_Odywoord == "FA")
	{
		instellenmodule();
		Odynummer = 64;
	}
	_Odywoord = "";
	_neutraal = false;
	teller = bedenktijd;
/*	while (teller > 0)
	{
		delay (1);
		teller -= 1;
	}*/
	leds[6] = CRGB(0,0,0); // this sets a really dim processing light loopon the led strip.
	leds[7] = CRGB(0,0,0); // this sets a really dim processing light loopon the led strip.
        FastLED.show();

	
} 
//---------------------------------------------------------------------------

