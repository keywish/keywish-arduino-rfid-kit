#include "DS1302.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include <Wire.h> 
// Init the DS1302
DS1302 rtc(2, 3, 4);
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the I2C bus address for an unmodified backpack 
void setup() 
{
  rtc.halt(false);
  rtc.writeProtect(false);
  rtc.setTime(14, 34, 50);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(11, 3,2019);   // Set the date to August 6th, 2010   
  lcd.begin(16,2);
  lcd.setBacklightPin(3,POSITIVE); 
  lcd.setBacklight(HIGH); 
  // Start the I2C interface
    Wire.begin();        
 // Start the serial interface
   Serial.begin(9600);
}

void loop()
{  
    lcd.clear();                                // clean
    lcd.setCursor(4,0);                         // line0 display 
    lcd.print(rtc.getTimeStr());
    delay(10);    
    lcd.setCursor(3, 1);
    lcd.print(rtc.getDateStr());
    delay(1000);
}
