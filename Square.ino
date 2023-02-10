// The setXPin function set up 4 pins for 4-bit X coordinate
void setXPin() {
  pinMode(0, OUTPUT); // LSB
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT); // MSB
}

// The setYPin function set up 4 pins for 4-bit Y coordinate
void setYPin() {
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
  digitalWrite(0, (Xvalue>>0)&0x01);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(1, (Xvalue>>1)&0x01);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, (Xvalue>>2)&0x01);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(3, (Xvalue>>3)&0x01);  // turn the LED on (HIGH is the voltage level)
  delay(1000);
  digitalWrite(4, (Yvalue>>0)&0x01);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(5, (Yvalue>>1)&0x01);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(6, (Yvalue>>2)&0x01);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(7, (Yvalue>>3)&0x01);  // turn the LED on (HIGH is the voltage level)
}

// the loop function runs over and over again forever
void loop() {
  SetXY(0, 0);
  delay(1000);
  SetXY(15, 0);
  delay(1000); 
  SetXY(15, 15);
  delay(1000);
  SetXY(0, 15);
  delay(1000);
}
