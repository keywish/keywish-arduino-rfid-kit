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
 *
 * [Title]   voice operated switch
 */

int Voice_pin = A0 ;     // define analog 0 pin for voice-sensor pin  
int LED_PIN=13;
int val = 0;
void setup()
{  
    pinMode(LED_PIN,OUTPUT);   
    pinMode(Voice_pin,INPUT);       
    digitalWrite(LED_PIN,LOW);      
    Serial.begin(9600);
}
void loop()
{
   // val = digitalRead(Voice_pin);    // get voice-sensor analog value
     val = analogRead(Voice_pin); 
    Serial.println(val);
    if( val >48)              
    {
          digitalWrite(LED_PIN,HIGH);  
          delay(3000);
    }
    else
    {
      digitalWrite(LED_PIN,LOW);      
    }  
}
