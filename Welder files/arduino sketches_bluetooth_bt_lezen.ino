#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
char Data;

void setup() {

Serial.begin(9600);

//NIET IN ATMODUS
//pinMode(9,OUTPUT); digitalWrite(9,HIGH);

Serial.println("HALLO IK BEN 4 op een rij");

mySerial.begin(38400);

}

void loop()
{
if (mySerial.available()){ //wait for data received
    Data=mySerial.read();
    Serial.println(Data);
  }
}
