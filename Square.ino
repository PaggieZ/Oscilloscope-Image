/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}

void SetX(uint8_t value)
{
  digitalWrite(0, (value>>0)&0x01));  // turn the LED on (HIGH is the voltage level)
  digitalWrite(1, (value>>1)&0x01));  // turn the LED on (HIGH is the voltage level)
  digitalWrite(2, (value>>2)&0x01));  // turn the LED on (HIGH is the voltage level)
  digitalWrite(3, (value>>3)&0x01));  // turn the LED on (HIGH is the voltage level)
}

// the loop function runs over and over again forever
void loop() {
  SetX(0);
  SetY(0);
  delay(1000);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  delay(1000); 
  digitalWrite(0, LOW);  // turn the LED on (LOW is the voltage level)
  digitalWrite(1, LOW); 
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(1000);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(1000);

}
