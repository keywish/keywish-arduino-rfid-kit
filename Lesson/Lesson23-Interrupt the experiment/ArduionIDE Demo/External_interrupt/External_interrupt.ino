int SensorLED = 11;       
int SensorINPUT = 2;      
volatile int state = LOW;

void setup()
 {
  pinMode(SensorLED, OUTPUT);             
  pinMode(SensorINPUT, INPUT_PULLUP);       
  attachInterrupt(0, blink, FALLING);    
}
void loop() {
  if (state == HIGH) {       
    state = LOW;
    digitalWrite(SensorLED, HIGH); 
    delay(500);          //延时500ms
  }
  else {
    digitalWrite(SensorLED, LOW); 
  }
}
void blink() {               
  state = !state;           
}
