/***********************************************************************
         __                                                          _
        / /        _____  __    __  _          _   (_)   ________   | |
       / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
      / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
     / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
    / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
   /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|


   Keywish Tech firmware

   Copyright (C) 2015-2020

   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation, in version 3.
   learn more you can see <http://www.gnu.org/licenses/>.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.


   [Title]
   [Diagram]
*/
#include "ProtocolParser.h"
#include <SoftwareSerial.h>

#define Software_TX 2
#define Software_RX 3
SoftwareSerial BLE_JDY_16(Software_RX, Software_TX);

#define RGB_RED    10
#define RGB_GREEN  11
#define RGB_BLUE   9

long color;
ProtocolParser *mProtocol = new ProtocolParser();

void setup() {
    Serial.begin(9600);
    BLE_JDY_16.begin(9600);
    pinMode(RGB_RED,OUTPUT);
    pinMode(RGB_GREEN,OUTPUT);
    pinMode(RGB_BLUE,OUTPUT);
    delay(100);
}

void setColor(int red,int green,int blue)
{
    analogWrite(RGB_RED,red);
    analogWrite(RGB_GREEN,green);
    analogWrite(RGB_BLUE,blue);
}

void loop() {
    static bool recv_flag;
    mProtocol->RecevData();
    recv_flag = mProtocol->ParserPackage();
    if (recv_flag) {
      switch (mProtocol->GetRobotControlFun()) {
        case E_LED:
          color = mProtocol->GetRgbValue();
          setColor( color>>16, (color>>8)&0xFF, color&0xFF);
          break;
        }
     }
     return;
}
