/* 
This sketch is part of the Odyschrift project. It has been originally created by Alle v Meeteren and crazy modified and updated by Jurre Ongering on 
until 20 March 2020.

This part of the project enables physically handicapped people to play a game of "connect-four". 
//---------------------------------------------------------------------------

void setup() {
  /* 
  put your setup code here, to run once. Below, the joystick related pins are defined as 
  digital inputs (reading on or off)
  */

}
//---------------------------------------------------------------------------
 
void loop() {

//---------------------------------------------------------------------------
}
void actiontrigger() {

  /* 
  This is a seperate function that ges called when something actually needs to happen.
  It drops chips in the external board, but it also writes funny messages to the screen.
  It will execute depending on the Odywoord that has been set up at that point"
  */
  
    lcd.clear(); // clears the LCD screen first to start of with a blank slate
    
// checkcontact ("action");
  if (Odywoord == "DO"){
    tekst = "Chip DO valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (announcetime);
    digitalWrite (mDO, HIGH);
    delay (turntime);
    digitalWrite (mDO, LOW);
    // blink the red light of any such light event here
     }
  else if (Odywoord == "DE"){
    tekst = "Chip DE valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (announcetime);
    digitalWrite (mDE, HIGH);
    delay (turntime);
    digitalWrite (mDE, LOW);
    }
  else if (Odywoord == "DI"){
    tekst = "Chip DI valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (announcetime);
    digitalWrite (mDI, HIGH);
    delay (turntime);
    digitalWrite (mDI, LOW);
    }
  else if (Odywoord == "DA"){
    tekst = "Chip DA valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (announcetime);
    digitalWrite (mDA, HIGH);
    delay (turntime);
    digitalWrite (mDA, LOW);
    }
  else if (Odywoord == "RO"){
    tekst = "Chip RO valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    delay (announcetime);
    digitalWrite (mRO, HIGH);
    delay (turntime);
    digitalWrite (mRO, LOW);
    }
  else if (Odywoord == "RE"){
    tekst = "Chip RE valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (announcetime);
    digitalWrite (mRE, HIGH);
    delay (turntime);
    digitalWrite (mRE, LOW);
    }
  else if (Odywoord == "RI"){
    tekst = "Chip RI valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop Ihip
    delay (announcetime);
    digitalWrite (mRI, HIGH);
    delay (turntime);
    digitalWrite (mRI, LOW);
     }
  else if (Odywoord == "RA"){
    tekst = "Chip RA valt"; cursorKolom = 0 ; cursorRij = 1; wachten = 1; laatstaan = true; lcd_print();    
    //action-->drop chip
    delay (announcetime);
    digitalWrite (mRA, HIGH);
    delay (turntime);
    digitalWrite (mRA, LOW);
    }
  else if (Odywoord == "MO"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = false; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = false; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = false; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "ME"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "MI"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "MA"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "FO"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "FE"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "FI"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 1
    tekst = "JAWEL"; cursorKolom = 0 ; cursorRij = 1; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 2
    tekst = "Ik ben een"; cursorKolom = 0 ; cursorRij = 2; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 3
    tekst = "Drakendoder"; cursorKolom = 0 ; cursorRij = 3; afrollen = true; wachten = 0; laatstaan = true; lcd_print(); // 20 letters op rij 4
    delay (readtime);
    lcd.clear(); // clear
    }
  else if (Odywoord == "FA"){
    tekst = "Elinde zegt:"; cursorKolom = 0 ; cursorRij = 0; afrollen = true; wachten = 1; laatstaan = true; lcd_print(); // 20 letters op rij 1
    Serial.println ("BOOM RIGHT HERE"); // Just ignore it. This was just a way of checking this scnario in the serial monitor.
    delay (3000);
    lcd.clear(); // clear
    }
  }

//---------------------------------------------------------------------------

void Odytekencheck(){

    if ( digitalRead( dirUp ) == LOW && digitalRead( dirLeft ) == LOW ){
      OdytekenNOW = 'R';
       exit;
      }
      
    else if ( digitalRead( dirUp ) == LOW && digitalRead( dirRight ) == LOW ){
      OdytekenNOW = 'D';
        exit;
      }   
          
    else if ( digitalRead( dirDown ) == LOW && digitalRead( dirRight ) == LOW ){
      OdytekenNOW = 'F';
        exit;
      }
      
    else if ( digitalRead( dirDown ) == LOW && digitalRead( dirLeft ) == LOW ){
      OdytekenNOW = 'M';
        exit;
      }
  
    else if ( digitalRead( dirUp ) == LOW ) {
      OdytekenNOW = 'O';
        exit;
      }
    
    else if ( digitalRead( dirRight ) == LOW ) {
      OdytekenNOW = 'A';
        exit;
      }
   
    else if ( digitalRead( dirDown ) == LOW ){
      OdytekenNOW = 'I';
        exit;
      }
      
    else if( digitalRead( dirLeft ) == LOW ){
      OdytekenNOW = 'E';
        exit;
      }
      
    else { // als er niets geselecteerd is
      OdytekenNOW = ' ';
       exit;
      }
      
}
