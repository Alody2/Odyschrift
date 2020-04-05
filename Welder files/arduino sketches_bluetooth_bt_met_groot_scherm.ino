//Combinatie van bt_lezen en test 20 bij 4 scherm
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
SoftwareSerial mySerial(10, 11); // RX, TX
char Data;
int positie; 
int regel; 

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  positie = 0;
  regel = 0;
  lcd.setCursor(positie,regel);
 
mySerial.begin(38400);
Serial.begin (9600);
}


void loop()
{
  if (mySerial.available()){ //wait for data received
    positie = positie + 1;
    Serial.print (positie);
    if (positie == 20)
      {
        positie = 0;
        regel = regel + 1;
        if (regel == 4)
         { regel = 0;
         lcd.clear(); 
         }
      }
      lcd.setCursor(positie,regel);
    Data=mySerial.read();
    if (Data != "")
    {Serial.print (Data);
    lcd.print(Data);
    }
  }
}
