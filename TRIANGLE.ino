// The setXPin function set up 4 pins for 4-bit X coordinate
void setup() {
  pinMode(0, OUTPUT); // LSB
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT); // MSB
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void SetX(uint8_t value)
{
  digitalWrite(0, (value>>0)&0x01);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(1, (value>>1)&0x01);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, (value>>2)&0x01);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(3, (value>>3)&0x01);  // turn the LED on (HIGH is the voltage level)
}

void SetY(uint8_t value)
{
  digitalWrite(4, (value>>0)&0x01);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(5, (value>>1)&0x01);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(6, (value>>2)&0x01);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(7, (value>>3)&0x01);  // turn the LED on (HIGH is the voltage level)
}

void SetXY(uint8_t Xvalue, uint8_t Yvalue) {
  PORTD = (Xvalue<<4 | (Yvalue&0x0F));
}

// the loop function runs over and over again forever
void loop() {

  unsigned int i;
  for(i = 0; i <=8; i++){
    SetXY(i,i);
    delay(1000);
  }

  
/*
  for(i = 8; i >= 0; i--){
      SetXY(8, i);
      delay(1000);
  }

  for(i = 8; i >= 0; i--){
      SetXY(i, 0);
      delay(1000);
  }
  */
}