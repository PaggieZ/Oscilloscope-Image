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

drawdelay = 10;


void draw_tri() {
  int i = 0;
  // Diagnal Line starting at bottom right corner
  for(i = 0; i <=10; i++){
    SetXY(i,i);
    delayMicroseconds(drawdelay);
  }

  for(i = 10; i >= 0; i--){
      SetXY(i, 10);
      delayMicroseconds(drawdelay);
  }

  for(i = 10; i >= 0; i--){
      SetXY(0, i);
      delayMicroseconds(drawdelay);
  }
}

void draw_square(){
  int i = 0;
  
  // Horizontal right moving line
  // Verticle upward line
  for(i = 0; i <=10; i++){
    SetXY(i,0);
    delayMicroseconds(drawdelay);
  }

  // Verticle upward line
  for(i = 0; i <=10; i++){
    SetXY(10,i);
    delayMicroseconds(drawdelay);  
  }

  // Verticle Downwards line
  for(i = 10; i >=0; i--){
    SetXY(i,10);
    delayMicroseconds(drawdelay);
  }

  // Horizontal left moving line
  for(i = 10; i >= 0; i--){
    SetXY(0,i);
    delayMicroseconds(drawdelay);
  }
}

/* LETTERS! */
// A
// B
// C
// D
// E
// F
// G
// H
// I
// J
// K
void draw_K() {
	int a=0; // X-Coordinate
	int b=0; // Y-Coordinate
	
	// Set initial a,b coordinate values
	a = 1;
	b = 2;
	SetXY(a,b);
	delayMicroseconds(drawdelay)
	
	// Up
	for(b < 3){
		b++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
	
	// Right
	for(a < 2){
		a++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
	
	// Up
	for(b < 13){
		b++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}	
	
	// Left
	for(a > 1){
		a--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}	
	
	// Up
	for(b < 14){
		b++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	
	// Right
	for(a < 6){
		a++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}	
	
	// Down 
	for(b > 13){
		b--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}

	// Left
	for(a > 5){
		a--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}	

	// Down 
	for(b > 10){
		b--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
	
	// Diagonal Up-Right
	for(b < 13){
		a++;
		b++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
	// Left
	for(a > 7){
		a--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}		
	// Up
	for(b < 14){
		b++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}		
	// Right
	for(a < 13){
		a++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
	// Down 
	for(b > 13){
		b--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}	
	// Left
	for(a > 12){
		a--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}	
	// Diagonal Down-Left
	for(b > 8){
		a--;
		b--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
	// Diagonal Down-Right
	for(b > 3){
		a++;
		b--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
	// Right
	for(a < 13){
		a++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}	
	// Down 
	for(b > 2){
		b--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
	// Left
	for(a > 7){
		a--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
	// Up
	for(b < 3){
		b++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}	
	// Right
	for(a < 8){
		a++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}		
	// Diagonal Up-Left
	for(b < 6){
		a--;
		b++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
	// Down 
	for(b > 3){
		b--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
	// Right
	for(a < 6){
		a++;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}	
	// Down 
	for(b > 2){
		b--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
	// Left
	for(a > 1){
		a--;
		SetXY(a,b);
		delayMicroseconds(drawdelay);
	}
}
// L
// M
// N
// O
// P
// Q
// R
// S
// T
// U
// V
// W
// X
// Y
// Z
	


// the loop function runs over and over again forever
void loop() {
	
  int count = 0;
  int drawnum = 1000; // The number of times each shape should be drawn
  
  // Draw the triangle 1000 times
  for(count = 0; count <= drawnum; count++){
    draw_tri();
    count += 1;
  }
	// Draw the square 1000 times
  for(count = 0; count <= drawnum; count++){
    draw_square();
    count += 1;
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