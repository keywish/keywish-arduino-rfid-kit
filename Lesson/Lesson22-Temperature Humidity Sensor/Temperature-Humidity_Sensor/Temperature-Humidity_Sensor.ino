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
 * [Title]    Temperature-Humidity Sensor
 * [Diagram]
 *         Arduino PIN 5   ===================  lcd1602 pin 11
 *         Arduino PIN 4   ===================  lcd1602 pin 12
 *         Arduino PIN 3   ===================  lcd1602 pin 13
 *         Arduino PIN 2   ===================  lcd1602 pin 14
 *         Arduino PIN 11  ===================  lcd1602 pin 5
 *         Arduino PIN 12  ===================  lcd1602 pin 6
 *         Arduino PIN 8   ===================  Temperature-Humidity Sensor Dout
 */
#include "dht11.h"
#include <LiquidCrystal.h>

#define    DB4   5   // lcd1602 DB4
#define    DB5   4   // lcd1602 DB5
#define    DB6   3   // lcd1602 DB6
#define    DB7   2   // lcd1602 DB7

#define    LCD1602_RS   12
#define    LCD1602_E    11
#define    DHT11PIN     8
dht11 DHT11;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(LCD1602_RS,LCD1602_E,DB4,DB5,DB6,DB7);  // lcd init

void setup() {
    pinMode(DHT11PIN,OUTPUT);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
}

void loop() {
    int chk = DHT11.read(DHT11PIN);
    lcd.setCursor(0, 0);
    lcd.print("Tep: ");
    lcd.print((float)DHT11.temperature, 2);
    lcd.print("C");
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    lcd.print("Hum: ");
    lcd.print((float)DHT11.humidity, 2);
    lcd.print("%");
    delay(200);
}