/* 
preambule
//---------------------------------------------------------------------------

If we need to add a third letter to Odyschrift, we will need to add a third category here (with "firstletterdefined" changing to a three option INTEGER instead of a two option BOOLEAN).
void setup() 
{
/* 
put your setup code here, to run once. Below, the joystick related pins are defined as 
digital inputs (reading on or off)
*/
	pinMode( dirUp , INPUT);
	pinMode( dirRight , INPUT);
	pinMode( dirDown , INPUT);
	pinMode( dirLeft , INPUT);
	digitalWrite(led_green, LOW);
	digitalWrite(led_red, LOW);
	strModule = "Vier op een rij";  //module waarmee gestart wordt 
	intModule = 1; // het nummer van de module
 	Serial.begin(9600);     //turning on of the serial monitor to inspect the result.
  	lcd.init();
  	lcd.backlight();
	startModus = true;
  	 tekst = 	"LATEN WE"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
 	 tekst = "SPEL(L)EN"; cursorKolom = 9 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print();    
 	 tekst = "NU:"; cursorKolom = 0 ; cursorRij = 2;  afrollen = false; wachten = 1; laatstaan = true; lcd_print();    
 	 tekst = "Vier op een rij"; cursorKolom = 0 ; cursorRij =3; afrollen = false; wachten = 6; laatstaan = false; lcd_print();    
	tekst = strActie; cursorKolom = 2 ; cursorRij = 3;  eerste_schrijf_loop = false; lcd_print();    
	lcd.createChar(0, harten);
	lcd.createChar(1, ruiten);
	lcd.createChar(2, schoppen);

	lcd.createChar(4, oog_dicht);
	lcd.createChar(5, oog_open);
	lcd.createChar(6, grens);
	lcd.createChar(7, grens_2);
	randomSeed(analogRead(0)); 
}
//---------------------------------------------------------------------------
void loop() {
/*
      	LoadBar();
  }
//---------------------------------------------------------------------------
void LoadBar(){ 
} 
//---------------------------------------------------------------------------
void wisselgroep(){
      	while ( digitalRead( dirUp ) == LOW || digitalRead( dirRight ) == LOW || digitalRead( dirDown ) == LOW || digitalRead( dirLeft ) == LOW ){
      		delay(pausetime);
	}
      	if ( digitalRead( dirUp ) == HIGH && digitalRead( dirRight ) == HIGH && digitalRead( dirDown ) == HIGH && digitalRead( dirLeft ) == HIGH ){
		if (FirstLetterDefined == false){ // This if statement checks if the logic has to go into the first or second letter selection scenario. 
			FirstLetterDefined = true;
		}
		else { // Dit gaan we doen als er een letter bijkomt TWEEDE LETTER SCENARIO
			FirstLetterDefined = false;
		}
	}
}
//---------------------------------------------------------------------------
void Odyletterswitch()
      	regeltModule(); // goes to the  function that scans if there are enough Odyletters for an action in the active module. Acts if that is the case, else waits for the mext Odyletter
}
//---------------------------------------------------------------------------
void regeltModule()
{
	switch (Odywoord.length())
	{
	case 1:
		switch (odyModule)
		{ 
			case 3: //dom
				//dobbelsteenWerpen 1 tot en met 3
			//	dobbelsteen(0);
				zet_voltooid();
			break;
			case 4: //dof
				//dobbelsteenWerpen 4 tot en met 6
			//	dobbelsteen(9);
				zet_voltooid();
			break;
			case 5: //ded
				//mens erger
					if (wacht_op_input == false && Odywoord == "D")
					{
						wacht_op_input = true;
					//	lcd_leeg();
						//worp(1,0);
					}
					else if (wacht_op_input == false && Odywoord == "F")
					{
						schakel();
					}
					else if (wacht_op_input == true)
					{
						wacht_op_input = false;
						//plaatsen4(5,0);
					}
				zet_voltooid();
			break;
			case 6: //der
				//ganzenbord
					if (wacht_op_input == false && Odywoord == "R")
					{
						wacht_op_input = true;
					//	lcd_leeg();
						//worp(2,0);
					}
					else if (wacht_op_input == false && Odywoord == "F")
					{
						schakel();
					}
					else if (wacht_op_input == true)
					{
						wacht_op_input = false;
						//plaatsen4(9,0);
					}
				zet_voltooid();
			break;
			case 8: //uitslag raden mastermind
				ronde++;
			//	uitslag(ronde);
			//	zet_voltooid();
			break;
			case 49: //fod
			break;
		}
	break; 
	case 2:
		if (Odywoord == "FA")
		{
			schakel();
		}
		else
		{
			switch (odyModule)
			{ 
				case 1:
					strActie = "Vier op een rij"; 
					Serial.print (Odywoord);
					/*Serial1.print (Odywoord);
					Serial2.print (Odywoord); */
					tekst = strActie ; cursorKolom = 0 ;  eerste_schrijf_loop = false;  cursorRij =2;  lcd_print();    
					tekst = "chip " + Odywoord + " valt"; cursorKolom = 0 ;  eerste_schrijf_loop = false;  cursorRij =3;  lcd_print(); 
					vierOpRij(); 
					zet_voltooid();
				break;
			case 7://dem
				// mastermind opzetten
				if (ronde<20)
				{
				//	mastermind(ronde);
					ronde = ronde + 5;
					if (ronde ==20)	
					{
						ronde=0;
					/*	if (lcd_ver==true)
						{
							lcd_ver= false;
						}*/
						odyModule = 8;
					}
				}
				zet_voltooid();
			break;	
			case 10://dem
			//	tekst = orientatie_richting();
				zet_voltooid();
			break;	
			case 11://dem
			//	tekst = tangram();
			//	tangram_plaats(tekst);
			//	zet_voltooid();
			break;	
			}
		}
	break;
	case 3:
		switch (odyModule)
		{ 
			case 2:
		//schrijven
				if (Odywoord == "FAD") //verwijder laatste letter
				{
					cursorTekst = cursorTekst - 1;
					cursorKolom = cursorTekst;
					tekst = " "; lcd_print();
				} 
				else if (Odywoord == "FAR")
				{
				} 
				else if (Odywoord == "FAM") //maak scherm leeg
				{
					lcd.clear();
					cursorTekst = 0;
					cursorRij = 0;
				}
				else if (Odywoord == "FAF")
				{
					schakel();
				}
				else 
				{
					if (cursorTekst == 0)
					{
					//	lcd_regel_leeg(0); //maak de regel leeg 
					}	
					if (cursorRij == 3) //eerste letter na modulewissel
					{
						cursorRij= 0;
						cursorTekst = 0;
					}
					tekst = schrijven();  eerste_schrijf_loop = false;  cursorKolom = cursorTekst;  
					cursorTekst = cursorTekst + tekst.length(); //zet de positie van de cursor klaar voor de volgende letter(groep)
					if (cursorTekst > 19)
					{
						if (cursorRij == 0)
						{
							cursorRij= 1;
							cursorTekst = 0;
						}
						else if (cursorRij == 1)
						{
							cursorRij= 2;
							cursorTekst = 0;
						}
						else if (cursorRij == 2)
						{
							cursorRij= 0;
							cursorTekst = 0;
						}
					}
					lcd_print();
				//	lcd_Ody_leeg(); //maakt de rij voor Odytekens leeg
					zet_voltooid();
				}
			break;
			case 64:
				tekst = module();  eerste_schrijf_loop = false;  cursorKolom = 2; cursorRij = 3;
				lcd_print();
				lcd.setCursor (0,0); 
				zet_voltooid();
			break;
		}
	break; 
	case 5:
	break;
	case 4:
	break;
	}
}
//---------------------------------------------------------------------------
void zet_voltooid()
{
	FirstLetzaterDefined = false;
	Odywoord = ""; //Odywoord geleegd voor volgende
}
//---------------------------------------------------------------------------
{
	odyModule = 64; 
	lcd.clear();
	strActie = "schakel";
	tekst = strActie; cursorKolom = 2 ; cursorRij = 3;  eerste_schrijf_loop = false; lcd_print();    
	zet_voltooid();
}
//---------------------------------------------------------------------------
void Odytekencheck()
{
}
//---------------------------------------------------------------------------
void checkcontact(String dit)
{ // dit is een aparte functie, It's a tool to check the contacts
 	Serial.println ("***start check contacts laag");
  	if (digitalRead( dirUp ) == LOW){Serial.println ("low dirUp/");}
 	if (digitalRead( dirRight ) == LOW){Serial.println ("low dirRight/");}
  	if (digitalRead( dirDown ) == LOW){Serial.println ("low dirDown/");}
  	if (digitalRead( dirLeft ) == LOW){Serial.println ("low dirLeft/");}
  	Serial.println (dit + "start check contacts hoog");
  	if (digitalRead( dirUp ) == HIGH){Serial.println ("HIGH dirUp/");}
  	if (digitalRead( dirRight ) == HIGH){Serial.println ("HIGH dirRight/");}
  	if (digitalRead( dirDown ) == HIGH){Serial.println ("HIGH dirDown/");}
  	if (digitalRead( dirLeft ) == HIGH){Serial.println ("HIGH dirLeft/");}
  	Serial.println (dit + "eind check contacts***");
}
