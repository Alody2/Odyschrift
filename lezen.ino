
char receivedChar;
boolean newData = false;
String lezen()
{

	String Ody; 
	if (mySerial.available()) 
	{
		recvOneChar();
		Ody = showNewData();
	}
	return Ody;
}
void recvOneChar() 
{
    if (mySerial.available() > 0) 
	{
		receivedChar = mySerial.read();
		newData = true;
       	}
}

char showNewData() 
{
	char Ody;
	if (newData == true) 
	{
		Ody = receivedChar;
		newData = false;
	}
	return Ody;
}
