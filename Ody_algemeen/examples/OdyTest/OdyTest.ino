#include <Ody.h>
#include <LiquidCrystal.h>
//#include <SoftwareSerial.h>
//SoftwareSerial naarAnder(10, 11); // RX, TX

const int rs = 8, en = 7, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//pin left, right, up, down, wait time, pin red, pin green
Ody myOdy(2,3,4,5,2000,12,13);
String Odytijdelijk;


//---------------------------------------------------------------------------

void setup()
{
 	Serial.begin(9600);
	lcd.begin(16, 2);
	Serial.begin(9600); //this begins the serial monitor to be able to get feedback from the sketch.
  	//naarAnder.println("Send 1 to turn on the LED. Send 0 to turn Off");
	//naarAnder.begin (38400);
}

void loop()
{
	Odytijdelijk = myOdy.werk();
//	Odytijdelijk =" myOdy.werk()";
	lcd.setCursor(0, 0);
        Serial.println (Odytijdelijk);
        lcd.print (Odytijdelijk);
        lcd.print ("Odytijdelijk");
delay (1000);
     /*   naarAnder.println (Odytijdelijk);
	delay (100);*/
        lcd.setCursor(0, 1);
        lcd.print ("Odytijdelijk");
        Serial.println ("Odytijdelijk");
   //    lcd.print(myOdy.OdyWoord);
}
