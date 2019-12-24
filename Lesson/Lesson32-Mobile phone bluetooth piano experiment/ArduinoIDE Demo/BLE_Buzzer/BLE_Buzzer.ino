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
#include "Buzzer.h"
#include <SoftwareSerial.h>

#define Software_TX 2
#define Software_RX 3
SoftwareSerial BLE_JDY_16(Software_RX, Software_TX);

#define BUZZER_PIN    11

ProtocolParser *mProtocol = new ProtocolParser();
Buzzer *mBuzzer = new Buzzer(BUZZER_PIN);
void setup() {
    Serial.begin(9600);
    BLE_JDY_16.begin(9600);
    pinMode(BUZZER_PIN, OUTPUT);
    delay(100);
}

void PianoSing(byte b[])
{
    union result
    {
      float d;
      unsigned char data[4];
    }r1,r2;
    r2.data[0]=b[0];
    r2.data[1]=b[1];
    r2.data[2]=b[2];
    r2.data[3]=b[3];
    //mBuzzer->noTone(9);
    mBuzzer->_tone(r2.d,120, 2);
}
void loop() {
    static bool recv_flag;
    mProtocol->RecevData();
    recv_flag = mProtocol->ParserPackage();
    if (recv_flag) {
        if( mProtocol->GetRobotControlFun() == E_BUZZER) {
          PianoSing((byte *)mProtocol->GetPianoSing());
        }
     }
     return;
}
