#include "GLOBAL.h"

void draw_vertical(int, int, int, int);
void draw_horizontal(int, int, int, int);
void draw_diagonal(int, int, int, int, int);

// The setXPin function set up 4 pins for 4-bit X coordinate
void setup() {
  pinMode(0, OUTPUT); // LSB
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT); // MSB
  pinMode(4, OUTPUT); // LSB
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT); // LSB
}

void loop() {
  draw(K_x, K_y, K_direction);
}

void SetXY(uint8_t Xvalue, uint8_t Yvalue) {
  PORTD = (Xvalue<<4 | (Yvalue&0x0F));
}



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

void draw(int x[], int y[], int direction[]) {
	//int x[] = {1, 1, 2, 2, 1, 1, 6, 6, 5, 5, 8, 7, 7, 13, 13, 12, 7, 12, 13, 13, 7, 7, 8, 5, 5, 6, 6, 1}; // X-Coordinate, the last index has the first point
	//int y[] = {2, 3, 3, 13, 13, 14, 14, 13, 13, 10, 13, 13, 14, 14, 13, 13, 8, 3, 3, 2, 2, 3, 3, 6, 3, 3, 2, 2}; // Y-Coordinate
	//int direction[] = {UP, RIGHT, UP, LEFT, UP, RIGHT, DOWN, LEFT, DOWN, UP_RIGHT, LEFT, UP, RIGHT, DOWN, LEFT, DOWN_LEFT, DOWN_RIGHT, RIGHT, DOWN, LEFT, UP, RIGHT, UP_LEFT, DOWN, RIGHT, DOWN, LEFT};
	// Set initial a,b coordinate values
	int index = 0;

  while(index < (sizeof(direction))){    
    switch (direction[index]) {
      case 0: // UP
      case 1: // DOWN
        draw_vertical(direction[index], x[index], y[index], y[index + 1]);
        break;
      case 2: // RIGHT
      case 3: // LEFT
        draw_horizontal(direction[index], y[index], x[index], x[index + 1]);
      case 4:
      case 5:
      case 6:
      case 7:
        draw_diagonal(direction[index], x[index], y[index], x[index + 1], y[index + 1]);
        break;
    }
    index++;
  }
}

void draw_horizontal(int direction, int yval, int x1val, int x2val) {  
  if(direction == RIGHT){
    int curr_x = x1val;
    while(curr_x <= x2val) {
      SetXY(curr_x, yval);
      delayMicroseconds(drawdelay);
      curr_x += 1;
    }
  }
  else if(direction == LEFT){
    int curr_x = x1val;
    while(curr_x >= x2val){
      SetXY(curr_x, yval);
      delayMicroseconds(drawdelay);
      curr_x -= 1;
    }
  }
}

void draw_vertical(int direction, int xval, int y1val, int y2val){
  if(direction == UP){
    int curr_y = y1val;
    while(curr_y <= y2val) {
      SetXY(xval, curr_y);
      delayMicroseconds(drawdelay);
      curr_y += 1;
    }
  }
  else if(direction == DOWN){
    int curr_y = y1val;
    while(curr_y >= y2val){
      SetXY(xval, curr_y);
      delayMicroseconds(drawdelay);
      curr_y -= 1;
    }
  }
}

void draw_diagonal(int direction, int x1val, int y1val, int x2val, int y2val){
  if(direction == DOWN_LEFT) {
    int curr_x = x1val;
    int curr_y = y1val;
    while(curr_x >= x2val) {
      SetXY(curr_x, curr_y);
      delayMicroseconds(drawdelay);
      curr_x -= 1;
      curr_y -= 1;
    }
  }
  else if(direction == DOWN_RIGHT) {
    int curr_x = x1val;
    int curr_y = y1val;
    while(curr_x <= x2val) {
      SetXY(curr_x, curr_y);
      delayMicroseconds(drawdelay);
      curr_x += 1;
      curr_y -= 1;
    }   
  }
  else if(direction == UP_RIGHT) {
    int curr_x = x1val;
    int curr_y = y1val;
    while(curr_x <= x2val) {
      SetXY(curr_x, curr_y);
      delayMicroseconds(drawdelay);
      curr_x += 1;
      curr_y += 1;
    }
  }
  else if(direction == UP_LEFT) {
    int curr_x = x1val;
    int curr_y = y1val;
    while(curr_x >= x2val) {
      SetXY(curr_x, curr_y);
      delayMicroseconds(drawdelay);
      curr_x -= 1;
      curr_y += 1;
    }
  }
}
