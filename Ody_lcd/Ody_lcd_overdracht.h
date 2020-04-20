/* 
This library is part of the Odyschrift project. It has been originally created by Alle v Meeteren and modified by Jurre Ongering on 
15 March 2020
This module of the project enables physically handicapped people to play a game of "connect-four". A joystick is used as a controller. 
The joystick has 8 contacts.

 * The joystick can activate a single contact (4 directions)  or 2 contacts (4 directions between the other 4 directions) at a time.
 * In the neutral state none of these is active. In our implementation the joystick has to return to that neutral state, before the next direction can be chosen.
 * We alternate between the 2 groups, so there is a variable to indicate which group is the active group. 

We use an Arduino Mega
*/
#ifndef Ody_lcd_h
#define Ody_lcd_h
#include <Arduino.h>
#include <LiquidCrystal_I2C.h> // include the library code
#include <Ody_algemeen.h> //the library for special tools 

class Ody_lcd
{ 
public:
LiquidCrystal_I2C lcd (0x27, 20, 4);
private:
}
#endif
