/* 
This sketch is part of the Odyschrift project. It has been originally created by Alle v Meeteren and modified by Jurre Ongering

In this part a lcd-screen translates Odywords in text. 

 */
 

//variabelen om het printen van de tekst op het lcd-scherm te regelen
//---------------------------------------------------------------------------
void lcd_print() {// function to regulate printing to the lcd-screen   
	switch (wachten){
		case 1:	
			if (wachten2 == false){
				lcd.setCursor(0,cursorRij);
				lcd.print ("                    ");
				lcd.setCursor(cursorKolom,cursorRij);
				lcd.print (tekst);
			}
		break;
		case 2:	
				lcd.setCursor(0,cursorRij);
				lcd.print ("                    ");
		break;
		case 3:		
			scrollWords();
			lcd.clear();
		break;
	}
}

//---------------------------------------------------------------------------


void scrollWords(){
	String deelTekst1;
	String deelTekst2;
int i = 0;			//teller tekst helemaal
int j = 0;			//pointer in tekst
int k = 0;
	j = tekst.length();
	for (i; i< j ; i++) {
		deelTekst1 = tekst.substring (i, i +21);
		k = 21;
			while (deelTekst1.charAt(k)!= ' '||deelTekst1.charAt(k)=='-'){
				if (deelTekst1.charAt(k)=='-'){
					k++;
					i--;
					break;
				}
				k--;
			}
				deelTekst1 = deelTekst1.substring (0,k); 
				lcd.setCursor(0, cursorRij);
				lcd.print("                    ");
				lcd.setCursor(0, cursorRij);
				lcd.print(deelTekst1);
				i = i + deelTekst1.length() ; 
				delay(delayTime2 * 6);
  		if ( digitalRead( dirUp ) == LOW || digitalRead( dirLeft ) == LOW ||  digitalRead( dirDown) == LOW ||  digitalRead( dirRight) == LOW){
		break;
	}
}
}

//---------------------------------------------------------------------------



