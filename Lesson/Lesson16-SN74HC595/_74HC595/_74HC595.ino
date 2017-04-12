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
 * [Title] 74hc595 driver 4x8bit Nixie tube
 * [Diagram]
 *         Arduino PIN 5   ===================  4x7 Segment nixie tube 12
 *         Arduino PIN 6   ===================  4x7 Segment nixie tube 9
 *         Arduino PIN 7   ===================  4x7 Segment nixie tube 8
 *         Arduino PIN 8   ===================  4x7 Segment nixie tube 6
 *         Arduino PIN 2   ===================   74hc595 pin 12(STCP)
 *         Arduino PIN 3   ===================   74hc595 pin 11(SHCP)
 *         Arduino PIN 4   ===================   74hc595 pin 14(DS)
 *
 *     74hc595 pin 15(Q0)  ===================  4x7 Segment nixie tube 11
 *     74hc595 pin 1(Q1)   ===================  4x7 Segment nixie tube 7
 *     74hc595 pin 2(Q2)   ===================  4x7 Segment nixie tube 5
 *     74hc595 pin 3(Q3)   ===================  4x7 Segment nixie tube 2
 *     74hc595 pin 4(Q4)   ===================  4x7 Segment nixie tube 1
 *     74hc595 pin 5(Q5)   ===================  4x7 Segment nixie tube 10
 *     74hc595 pin 6(Q2)   ===================  4x7 Segment nixie tube 5
 *     74hc595 pin 7(Q3)   ===================  4x7 Segment nixie tube 3
*/

#define BIT_CHOICE_1  5
#define BIT_CHOICE_2  6
#define BIT_CHOICE_3  7
#define BIT_CHOICE_4  8

#define STCP_PIN  2
#define SHCP_PIN  3
#define DATA_PIN  4 //define stcp shcp ds pin

int BIT_CHOICE[4]= {BIT_CHOICE_1 , BIT_CHOICE_2 ,BIT_CHOICE_3,BIT_CHOICE_4};// 4x8bit
unsigned char DisplayNumble[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0X6F};
void setup ()
{
    Serial.begin(115200);
    pinMode(STCP_PIN,OUTPUT);
    pinMode(SHCP_PIN,OUTPUT);
    pinMode(DATA_PIN,OUTPUT); //set stcp shcp ds pin putput mode
    for(int i=0;i<4;i++)
    {
         pinMode(BIT_CHOICE[i],OUTPUT);
         digitalWrite(BIT_CHOICE[i],HIGH);
    }
}

void  nixie_pin_chioce_set(int value)
{
    for(int i=0;i<4;i++)
    {
        digitalWrite(BIT_CHOICE[i],value);
    }
}

void loop()
{
    int i=0;
    for(i = 9; i>=0 ;i-- )  // numble 9 - > 0 down
    {
        nixie_pin_chioce_set(HIGH);
        digitalWrite(STCP_PIN,LOW);
        shiftOut(DATA_PIN,SHCP_PIN,MSBFIRST,DisplayNumble[i]); //serial shift out put display numble
        digitalWrite(STCP_PIN,HIGH);
        nixie_pin_chioce_set(LOW);
        delay(1000);
    }
}
