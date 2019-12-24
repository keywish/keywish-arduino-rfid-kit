#include <SoftwareSerial.h>
#define Software_TX 2
#define Software_RX 3

byte read_dat, jdy_dat;
SoftwareSerial BLE_JDY_16(Software_RX, Software_TX);//
void setup()
 {
     Serial.begin(9600);
     BLE_JDY_16.begin(9600);
     Serial.println("Ble Test");
 }

void loop()
 {
     if (BLE_JDY_16.available()) {
        jdy_dat = BLE_JDY_16.read();
        delay(2);
        Serial.write(jdy_dat);
     }
     if (Serial.available() > 0)  
     {
         read_dat = Serial.read();
         delay(2);
         BLE_JDY_16.write(read_dat);
     }
 }
