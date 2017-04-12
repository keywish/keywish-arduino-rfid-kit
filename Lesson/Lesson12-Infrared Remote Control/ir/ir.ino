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
 * [Title]     Decoder NEC ir protocol output by Serial port
 * [diagram]
 *         Arduino PIN 11  ===================  ir pin
 */

#include "IRremote.h"
int RECV_PIN = 11;
long int value ;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
    Serial.begin(115200);
    irrecv.enableIRIn(); // init ir recv and enable Ir input
    pinMode(12,1);
}
void loop() {
    if (irrecv.decode(&results)) {
        value = results.value;
        Serial.print(value,HEX);
        Serial.print("\n");
        irrecv.resume(); //  resume and recive next ir decoder
    }
}
