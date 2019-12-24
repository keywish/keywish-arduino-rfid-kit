#include "MsTimer2.h"

void flash()
{                       
   static boolean output = 1;
   digitalWrite(11,output);
   delay(10);
   output = !output;
}
void setup()
{
   pinMode(13, OUTPUT); 
   
   MsTimer2::set(1000, flash);
 
   MsTimer2::start(); 
}
   
void loop(){} 
