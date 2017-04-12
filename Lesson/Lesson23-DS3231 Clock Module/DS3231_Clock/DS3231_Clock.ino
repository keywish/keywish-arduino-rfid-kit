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
 * [Title] DS3231 Clock & lcd1602 display.
 * [Diagram]
 *         Arduino PIN 6   ===================  lcd1602 pin 11(D4)
 *         Arduino PIN 7   ===================  lcd1602 pin 12(D5)
 *         Arduino PIN 8   ===================  lcd1602 pin 13(D6)
 *         Arduino PIN 9   ===================  lcd1602 pin 14(D7)
 *         Arduino PIN 10  ===================  lcd1602 pin 4(RS)
 *         Arduino PIN 11  ===================  lcd1602 pin 5(RW)
 *         Arduino PIN 12  ===================  lcd1602 pin 6(E)
 *         Arduino 5v      ===================  lcd1602 pin 15(A)
 *         Arduino GND     ===================  lcd1602 pin 16(K)
 *         Arduino GND     ===================  lcd1602 pin 1(VSS)
 *         Arduino 5V      ===================  lcd1602 pin 2(VDD)
 *         lcd1602 pin 3(VO)   ===  variable resistor(10k) ===  GND
 *
 *         Arduino A4     ->  DS3231   SDA
 *         Arduino A5     ->  DS3231   SCL
*/

#include "DS3231.h"
#include <Wire.h>
#include<LiquidCrystal.h>

#define    DB4   6   // lcd1602 DB4
#define    DB5   7   // lcd1602 DB5
#define    DB6   8   // lcd1602 DB6
#define    DB7   9   // lcd1602 DB7

#define    LCD1602_RS   10
#define    LCD1602_RW   11
#define    LCD1602_E    12

DS3231 Clock;

bool Century=false;
bool h12;
bool PM;

LiquidCrystal lcd(LCD1602_RS,LCD1602_RW,LCD1602_E,DB4,DB5,DB6,DB7);  // lcd init
char lcd_dis_str[2][16];

void setup() {
    lcd.begin(16,2);
	// Start the I2C interface
	  Wire.begin();
    Clock.setSecond(50);//Set the second
    Clock.setMinute(34);//Set the minute
    Clock.setHour(14);  //Set the hour
    Clock.setDoW(6);    //Set the day of the week
    Clock.setDate(11);  //Set the date of the month
    Clock.setMonth(3);  //Set the month of the year
    Clock.setYear(17);  //Set the year (Last two digits of the year)
	  // Start the serial interface
	 Serial.begin(115200);
}
void ReadDS3231()
{
    int second,minute,hour,date,month,year,temperature;
    second=Clock.getSecond();
    minute=Clock.getMinute();
    hour=Clock.getHour(h12, PM);
    date=Clock.getDate();
    month=Clock.getMonth(Century);
    year=Clock.getYear();

  temperature=Clock.getTemperature();

  sprintf(lcd_dis_str[0],"   20%02d-%02d-%02d",year,month,date);
  sprintf(lcd_dis_str[1],"  %02d:%02d:%02d   %2d'",hour,minute,second,temperature);
}
void loop()
{
    ReadDS3231();
    lcd.clear();                                // clean
    lcd.setCursor(0,0);                         // line0 display
    lcd.print(lcd_dis_str[0]);
    delay(10);
    lcd.setCursor(0,1);
    lcd.print(lcd_dis_str[1]);
    delay(1000);
}