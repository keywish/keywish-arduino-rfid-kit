/***********************************************************************
         __                                                          _
        / /        _____  __    __  _          _   (_)   ________   | |
       / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
      / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
     / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
    / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
   /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|


   KeyWay Tech firmware

   Copyright (C) 2015-2020

   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation, in version 3.
   learn more you can see <http://www.gnu.org/licenses/>.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.


   [Title]    fire sensor control buzzer turn on/off
   [diagram]

*/

int fire_pin = 12 ;     // 定义火灾传感器引脚的控制引脚为A0
int buzzer = 13 ;        // 定义蜂鸣器引脚
int LED_PIN = 11;       //定义LED灯控制引脚
int val = 0;
int count = 0 ;
void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(fire_pin, INPUT);
  Serial.begin(9600);
  digitalWrite(buzzer, LOW);     // 设置蜂鸣器的初始状态为保持安静
}
void loop()
{
  val = digitalRead(fire_pin);    // 读取火焰传感器引脚的电平信号
  Serial.println(val);
  if ( val == 0 )             // 判断火焰传感器信号是否达到阀值
  {
    count++ ;
  }
  else
  {
    count = 0 ;
  }
  if ( count >= 5 )             //判断有火灾信号的次数是否达到5次
  {
    digitalWrite(buzzer , HIGH );
    digitalWrite(LED_PIN , HIGH );
  }
  else
  {
    digitalWrite(buzzer , LOW );   // disable an alarm
    digitalWrite(LED_PIN , LOW );
  }
  delay(500);
}
