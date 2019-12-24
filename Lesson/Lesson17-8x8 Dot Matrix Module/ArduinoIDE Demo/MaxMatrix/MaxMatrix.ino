#include "MAX7219_MaxMatrix.h"

//define Max7219 pins 
#define PIN_DIN    7   //max 7219
#define PIN_CS     6
#define PIN_CLK    5

MaxMatrix ledmatrix(PIN_DIN,PIN_CS,PIN_CLK, 1);  // init Max7219 LED Matrix, 1 module

void setup(){
  Serial.begin(9600);
  ledmatrix.init();
  ledmatrix.setIntensity(1);
  ledmatrix.clearMatrix();
  Serial.println("zero:0\none:1\ntwo:2\nthree:3\nfour:4\nfive:5\nsix:6\nseven:7\neight:8\nnine:9\nsmile:10\nhappyOpen:11\nhappyClosed:12\nheart:13\nbigSurprise:14\nsmallSurprise:15\ntongueOut:16\nvamp1:17\nvamp2:18\nlineMouth:19\nconfused:20\ndiagonal:21\nsad:22\nsadOpen:23\nsadClosed:24\nokMouth:25\nxMouth:26\ninterrogation:27\nthunder:28\nculito:29\nangry:30");
}

void loop() {
  while(Serial.available()) {
    int val = Serial.parseInt();
    if (val >= 0 && val <= 30) {
      ledmatrix.writeFull(ledmatrix.getMouthShape(val));
    }
    delay(2000);
  }
}
