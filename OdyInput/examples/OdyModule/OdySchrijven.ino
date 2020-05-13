void dor_begin()
{
 	tekst = "LATEN WE"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
	tekst = "SPELLEN"; cursorKolom = 9 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
  	tekst = "NU:"; cursorKolom = 0 ; cursorRij = 2;  afrollen = false; wachten = 0; laatstaan = true; lcd_print();    
  	tekst = "Schrijven"; cursorKolom = 0 ; cursorRij =3; afrollen = false; wachten = 3; laatstaan = false; lcd_print(); 
       	leds[6] = CRGB::Black; //     
       	leds[7] = CRGB::Black; //     
       	leds[8] = CRGB::Black; //     
       	leds[9] = CRGB(50,5,0); //     
  	leds[10] = CRGB(50,5,0); // 
  	leds[11] = CRGB(0,50,0); //
	FastLED.show();
}
void dor_actie()
{
	if (_Odywoord== "DOD")
	{
		Odyletternr = 1;
		letter = "a";
	}
	else if (_Odywoord=="DOR")
	{
		Odyletternr = 2;
		letter = "b";
	}
	else if (_Odywoord=="DOM")
	{
		Odyletternr = 3;
		letter = "c";
	}
	else if (_Odywoord=="DOF")
	{
		Odyletternr = 4;
		letter = "d";
	}
	if (_Odywoord== "DED")
	{
		Odyletternr = 5;
		letter = "e";
	}
	else if (_Odywoord=="DER")
	{
		Odyletternr = 6;
		letter = "f";
	}
	else if (_Odywoord=="DEM")
	{
		Odyletternr = 7;
		letter = "g";
	}
	else if (_Odywoord=="DEF")
	{
		Odyletternr = 8;
		letter = "h";
	}
	if (_Odywoord== "DID")
	{
		Odyletternr = 9;
		letter = "i";
	}
	else if (_Odywoord=="DIR")
	{
		Odyletternr = 10;
		letter = "j";
	}
	else if (_Odywoord=="DIM")
	{
		Odyletternr = 11;
		letter = "k";
	}
	else if (_Odywoord=="DIF")
	{
		Odyletternr = 12;
		letter = "l";
	}
	else if (_Odywoord== "DAD")
	{
		Odyletternr = 13;
		letter = "m";
	}
	else if (_Odywoord=="DAR")
	{
		Odyletternr = 14;
		letter = "n";
	}
	else if (_Odywoord=="DAM")
	{
		Odyletternr = 15;
		letter = "o";
	}
	else if (_Odywoord=="DAF")
	{
		Odyletternr = 16;
		letter = "p";
	}
	else if (_Odywoord== "ROD")
	{
		Odyletternr = 17;
		letter = "q";
	}
	else if (_Odywoord=="ROR")
	{
		Odyletternr = 18;
		letter = "r";
	}
	else if (_Odywoord=="ROM")
	{
		Odyletternr = 19;
		letter = "s";
	}
	else if (_Odywoord=="ROF")
	{
		Odyletternr = 20;
		letter = "t";
	}
	else if (_Odywoord== "RED")
	{
		Odyletternr = 21;
		letter = "u";
	}
	else if (_Odywoord=="RER")
	{
		Odyletternr = 22;
		letter = "v";
	}
	else if (_Odywoord=="REM")
	{
		Odyletternr = 23;
		letter = "w";
	}
	else if (_Odywoord=="REF")
	{
		Odyletternr = 24;
		letter = "x";
	}
	if (_Odywoord== "RID")
	{
		Odyletternr = 25;
		letter = "y";
	}
	else if (_Odywoord=="RIR")
	{
		Odyletternr = 26;
		letter = "z";
	}
	else if (_Odywoord=="RIM")
	{
		Odyletternr = 27;
		letter = "1";
	}
	else if (_Odywoord=="RIF")
	{
		Odyletternr = 28;
		letter = "2";
	}
	else if (_Odywoord== "RAD")
	{
		Odyletternr = 29;
		letter = "3";
	}
	else if (_Odywoord=="RAR")
	{
		Odyletternr = 30;
		letter = "4";
	}
	else if (_Odywoord=="RAM")
	{
		Odyletternr = 31;
		letter = "5";
	}
	else if (_Odywoord=="RAF")
	{
		Odyletternr = 32;
		letter = "6";
	}
	else if (_Odywoord== "MOD")
	{
		Odyletternr = 33;
		letter = "7";
	}
	else if (_Odywoord=="MOR")
	{
		Odyletternr = 34;
		letter = "8";
	}
	else if (_Odywoord=="MOM")
	{
		Odyletternr = 35;
		letter = "9";
	}
	else if (_Odywoord=="MOF")
	{
		Odyletternr = 36;
		letter = "0";
	}
	else if (_Odywoord== "MED")
	{
		Odyletternr = 37;
		letter = "+";
	}
	else if (_Odywoord=="MER")
	{
		Odyletternr = 38;
		letter = "-";
	}
	else if (_Odywoord=="MEM")
	{
		Odyletternr = 39;
		letter = "*";
	}
	else if (_Odywoord=="MEF")
	{
		Odyletternr = 40;
		letter = "/";
	}
	else if (_Odywoord== "MID")
	{
		Odyletternr = 41;
		letter = "=";
	}
	else if (_Odywoord=="MIR")
	{
		Odyletternr = 42;
		letter = ".";
		_Odywoord = _Odywoord + " punt ";
	}
	else if (_Odywoord=="MIM")
	{
		Odyletternr = 43;
		letter = ",";
		_Odywoord = _Odywoord + " komma ";
	}
	else if (_Odywoord=="MIF")
	{
		Odyletternr = 44;
		letter = "?";
	}
	else if (_Odywoord== "MAD")
	{
		Odyletternr = 45;
		letter = ";";
	}
	else if (_Odywoord=="MAR")
	{
		Odyletternr = 46;
		letter = ":";
	}
	else if (_Odywoord=="MAM")
	{
		Odyletternr = 47;
		letter = "au";
	}
	else if (_Odywoord=="MAF")
	{
		Odyletternr = 48;
		letter = "oo";
	}
	else if (_Odywoord== "FOD")
	{
		Odyletternr = 49;
		letter = "oe";
	}
	else if (_Odywoord=="FOR")
	{
		Odyletternr = 50;
		letter = "aa";
	}
	else if (_Odywoord=="FOM")
	{
		Odyletternr = 51;
		letter = "ge";
	}
	else if (_Odywoord=="FOF")
	{
		Odyletternr = 52;
		letter = "ver";
	}
	else if (_Odywoord== "FED")
	{
		Odyletternr = 53;
		letter = "sch";
	}
	else if (_Odywoord=="FER")
	{
		Odyletternr = 54;
		letter = "st";
	}
	else if (_Odywoord=="FEM")
	{
		Odyletternr = 55;
		letter = "ing";
	}
	else if (_Odywoord=="FEF")
	{
		Odyletternr = 56;
		letter = "heid";
	}
	else if (_Odywoord== "FID")
	{
		Odyletternr = 57;
		letter = "zw";
	}
	else if (_Odywoord=="FIR")
	{
		Odyletternr = 58;
		letter = "isch";
	}
	else if (_Odywoord=="FIM")
	{
		Odyletternr = 59;
		letter = "cht";
	}
	else if (_Odywoord=="FIF")
	{
		Odyletternr = 60;
		letter = " ";
		_Odywoord = _Odywoord + " spatie ";
	}
	else if (_Odywoord== "FAD")
	{
		Odyletternr = 61;
		_Odywoord = _Odywoord + " letter weg ";
		letter=  "";
	}
	else if (_Odywoord=="FAR")
	{
		Odyletternr = 62;
		_Odywoord = _Odywoord + " woord weg ";
		letter=  "";
	}
	else if (_Odywoord=="FAM")
	{
		Odyletternr = 63;
		_Odywoord = _Odywoord + " zin weg ";
		letter=  "";
	}
	if (_Odywoord=="FAF")
	{
		instellenmodule();
	}
	else
	{
		switch (Odyletternr)
		{
			case 61:
				lengte = woord.length() - 1;
				woord =woord.substring(0, lengte);
			break;
			case 62:
				lengte = woord.lastIndexOf (" ");
				woord =woord.substring(0, lengte);	
			break;
			case 63:
				lengte = woord.lastIndexOf (".");
				woord =woord.substring(0, lengte);
				if (lengte> 0)
				{	
				}
				else
				{
			  		woord =  ""; 
		
				}
			break;
			default:
				woord = woord + letter;
			break;
		}
		wegSchrijven();
	       leds[6] = CRGB(0,0,0); 
	       leds[7] = CRGB(0,0,0);
	       leds[8] = CRGB(0,0,0);
	       FastLED.show();
	}
} 
//---------------------------------------------------------------------------
void wegSchrijven()
{
	lcd.clear();
	if (woord.length() < 60)
	{
		beginTekst = 0;
	}
	else
	{
		beginTekst = woord.length() - 60;
Serial.print ("A1");
		woord = woord.substring(woord.length() - 60);
	}
	woord1 = woord.substring(beginTekst,20);
	cursorRij = 0;
	tekst =  woord1; cursorKolom = 0 ;  wachten = 1; laatstaan = true; lcd_print();  
	beginTekst = beginTekst +20;
	woord2 = woord.substring (beginTekst,40);
	cursorRij = 1;
	tekst =  woord2 ; cursorKolom = 0 ;  wachten = 1; laatstaan = true; lcd_print();   
	beginTekst = beginTekst +20;
	woord3 = woord.substring (beginTekst,60);
	cursorRij = 2;
	tekst =  woord3 ; cursorKolom = 0 ;  wachten = 1; laatstaan = true; lcd_print();   
	letter2 = letter.substring (0,12);
  	tekst =  _Odywoord + " " + letter2 + " " + Odyletternr + " "; cursorKolom = 0 ; cursorRij = 3; wachten = 1; laatstaan = true; lcd_print();    
       _Odywoord = "";		

}
