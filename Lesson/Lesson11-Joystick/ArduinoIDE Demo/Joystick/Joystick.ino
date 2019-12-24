/***********************************************************************
 *       __                                                          _
 *      / /        _____  __    __  _          _   (_)   ________   | |
 *     / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
 *    / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
 *   / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
 *  / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
 * /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|
 *
 *
 * KeyWay Tech firmware
 *
 * Copyright (C) 2015-2020
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, in version 3.
 * learn more you can see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * [Title] JoyStick led
 * [Diagram]
 *         Arduino PIN 0   ===================  Joystick Pin3 (X)
 *         Arduino PIN 1   ===================  Joystick Pin4 (Y)
 *         Arduino PIN 2   ===================  Joystick Pin5 (Z)
 *         Arduino PIN 8   ===================  led1 (enter)
 *         Arduino PIN 9   ===================  led2 (left)
 *         Arduino PIN 10  ===================  led3 (up)
 *         Arduino PIN 11  ===================  led4 (right)
 *         Arduino PIN 12  ===================  led5 (down)
*/

#define JOYSTICK_X    A0
#define JOYSTICK_Y    A1
#define JOYSTICK_SW   A2

#define LED_ENTER    8   //enter
#define LED_LEFT     9   //left
#define LED_UP      10  //up
#define LED_RIGHT   11  //right
#define LED_DOWN    12  //down

int value_x,value_y,value_sw;
void setup()
{
    pinMode(JOYSTICK_X, INPUT);
    pinMode(JOYSTICK_Y, INPUT);
    pinMode(JOYSTICK_SW, INPUT_PULLUP);
    pinMode(LED_ENTER,OUTPUT); 
    pinMode(LED_LEFT,OUTPUT);
    pinMode(LED_UP,OUTPUT);
    pinMode(LED_RIGHT,OUTPUT);
    pinMode(LED_DOWN,OUTPUT);
    Serial.begin(9600); 
}

void loop() 
{
    value_x=analogRead(JOYSTICK_X);  
    value_y=analogRead(JOYSTICK_Y);  
    value_sw=digitalRead(JOYSTICK_SW);
    if(value_x==0)
    {
        digitalWrite(LED_RIGHT,LOW);
        digitalWrite(LED_LEFT,HIGH);
        Serial.print("left");

    }else if(value_x==1023)
    {
        digitalWrite(LED_LEFT,LOW);
        digitalWrite(LED_RIGHT,HIGH);
         Serial.print("right");
    }else
    {
        digitalWrite(LED_LEFT,LOW);
        digitalWrite(LED_RIGHT,LOW);
    }
    if(value_y==0)
    {
        digitalWrite(LED_DOWN,LOW);
        digitalWrite(LED_UP,HIGH);
        Serial.print("up");
    }
    else if(value_y==1023)
    {
        digitalWrite(LED_UP,LOW);
        digitalWrite(LED_DOWN,HIGH);
        Serial.print("down");
    }else
    {
        digitalWrite(LED_UP,LOW);
        digitalWrite(LED_DOWN,LOW);
    }
    if(value_sw == 0 )
    {
        digitalWrite(LED_ENTER,HIGH);
        Serial.print("enter");
    }
    else
    {
        digitalWrite(LED_ENTER,LOW);
    }
    delay(100);
}
