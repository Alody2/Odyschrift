#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); 
// 10 is Arduino RX en wordt verbonden met TX van de Bluetooth module,11 is TX van de Arduino en wordt verbonden met RX van de Bluetooth module
char Data;
void setup() {

Serial.begin(9600);

//NIET IN ATMODUS
//pinMode(9,OUTPUT); digitalWrite(9,HIGH);

Serial.println("HALLO IK BEN JOYSTICK");

mySerial.begin(38400);

}

void loop()

{
  

Data = 'D';
mySerial.println(Data);
delay(500);
}
