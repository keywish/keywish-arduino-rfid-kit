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
 */
#include <Wire.h>
#include "LiquidCrystal_I2C.h"
float i=0;
float j=0;
int analogPin = A0;
LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 is the I2C bus address for an unmodified backpack
void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}

void loop() {
    float data=analogRead(analogPin);
    Serial.println(data);
    i=data/1023;
    j=(1-i)*100;
    lcd.setCursor(0, 0);
    lcd.print("The hum is: ");
    lcd.setCursor(0, 1);
    lcd.print((float)j, 2);
    lcd.print("%");
    delay(200);
}
