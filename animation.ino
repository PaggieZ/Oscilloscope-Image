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

void draw_tri() {
  int i = 0;
  for(i = 0; i <=10; i++){
    SetXY(i,i);
    delayMicroseconds(10);
  }

  for(i = 10; i >= 0; i--){
      SetXY(i, 10);
      delayMicroseconds(10);
  }

  for(i = 10; i >= 0; i--){
      SetXY(0, i);
      delayMicroseconds(10);
  }
}

void draw_square(){
  int i = 0;
  for(i = 0; i <=10; i++){
    SetXY(i,0);
    delayMicroseconds(10);
  }

  for(i = 0; i <=10; i++){
    SetXY(10,i);
    delayMicroseconds(10);  
  }

  for(i = 10; i >=0; i--){
    SetXY(i,10);
    delayMicroseconds(10);
  }

  for(i = 10; i >=0; i--){
    SetXY(0,i);
    delayMicroseconds(10);
  }
}


// the loop function runs over and over again forever
void loop() {
  
  int count = 0;
  while(count <= 1000){
    draw_tri();
    count += 1;
  }

  while(count >= 0){
    draw_square();
    count -= 1;
  }
/*
  for(i = 0; i <=10; i++){
    SetXY(i,0);
    delayMicroseconds(100);
  }

  for(i = 10; i >=10; i--){
    SetXY(i,1);
    delayMicroseconds(100);
  }
*/
  
  

}
