#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // 10 Arduino RX verbonden met bluetooth TX, 11 Arduino TX verbonden met Bluetooth RX

void setup() {

Serial.begin(9600);

pinMode(9,OUTPUT); digitalWrite(9,HIGH);

Serial.println("Enter AT commands:");

mySerial.begin(38400);

}

void loop()

{

if (mySerial.available())

Serial.write(mySerial.read());

if (Serial.available())

mySerial.write(Serial.read());

}
