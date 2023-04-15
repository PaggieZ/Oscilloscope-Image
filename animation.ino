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
  Serial.begin(19200);
}

char letter;
static char name[256] = {};
unsigned index = 0;
unsigned index2 = 0;

void loop() {
  //spellName();
  //memset(name, "/0", 256);
  //letter = "/0";
  if(Serial.available() > 0)
  {
    Serial.flush();
    //memset(name, "/0", 256);
    index=0;
    //Serial.flush();
    while(Serial.available())
    {
      name[index++] = Serial.read();
      //Serial.print(name[index]);
    }
  }
  //Serial.print(index);
  for(unsigned i = 0; i < count * 2; i++)
  {
    switch(name[index2])
    {
      case 'A':
      case 'a':
        draw(A_x, A_y, A_direction, A_size);
        break;
      case 'B':
      case 'b':
        draw(B_x, B_y, B_direction, B_size);
        break;
      case 'C':
      case 'c':
        draw(C_x, C_y, C_direction, C_size);
        break;
      case 'D':
      case 'd':
        draw(D_x, D_y, D_direction, D_size);
        break;
      case 'E':
      case 'e':
        draw(E_x, E_y, E_direction, E_size);
        break;
      case 'F':
      case 'f':
        draw(F_x, F_y, F_direction, F_size);
        break;
      case 'G':
      case 'g':
        draw(G_x, G_y, G_direction, G_size);
        break;
      case 'H':
      case 'h':
        draw(H_x, H_y, H_direction, H_size);
        break;
      case 'I':
      case 'i':
        draw(I_x, I_y, I_direction, I_size);
        break;
      case 'J':
      case 'j':
        draw(J_x, I_y, I_direction, I_size);
        break;
      case 'K':
      case 'k':
        draw(K_x, K_y, K_direction, K_size);
        break;
      case 'L':
      case 'l':
        draw(L_x, L_y, L_direction, L_size);
        break;
      case 'M':
      case 'm':
        draw(M_x, M_y, M_direction, M_size);
        break;
      case 'N':
      case 'n':
        draw(N_x, N_y, N_direction, N_size);
        break; 
      case 'O':
      case 'o':
        draw(O_x, O_y, O_direction, O_size);
        break; 
      case 'P':
      case 'p':
        draw(P_x, P_y, P_direction, P_size);
        break;
      case 'Q':
      case 'q':
        draw(Q_x, Q_y, Q_direction, Q_size);
        break; 
      case 'R':
      case 'r':
        draw(R_x, R_y, R_direction, R_size);
        break; 
      case 'S':
      case 's':
        draw(S_x, S_y, S_direction, S_size);
        break; 
      case 'T':
      case 't':
        draw(T_x, T_y, T_direction, T_size);
        break; 
      case 'U':
      case 'u':
        draw(U_x, U_y, U_direction, U_size);
        break; 
      case 'V':
      case 'v':
        draw(V_x, V_y, V_direction, V_size);
        break; 
      case 'W':
      case 'w':
        draw(W_x, W_y, W_direction, W_size);
        break; 
      case 'X':
      case 'x':
        draw(X_x, X_y, X_direction, X_size);
        break; 
      case 'Y':
      case 'y':
        draw(Y_x, Y_y, Y_direction, Y_size);
        break; 
      case 'Z':
      case 'z':
        draw(Z_x, Z_y, Z_direction, Z_size);
        break; 
      default:
        delay(10);
    }
  }
  if(index2<index)
  {
    index2++;
  }
  else
  {
    index2=0;
    
    //drawHeart();
  }

}


void draw(uint8_t x[], uint8_t y[], uint8_t direction[], uint8_t size) {
	//int x[] = {1, 1, 2, 2, 1, 1, 6, 6, 5, 5, 8, 7, 7, 13, 13, 12, 7, 12, 13, 13, 7, 7, 8, 5, 5, 6, 6, 1}; // X-Coordinate, the last index has the first point
	//int y[] = {2, 3, 3, 13, 13, 14, 14, 13, 13, 10, 13, 13, 14, 14, 13, 13, 8, 3, 3, 2, 2, 3, 3, 6, 3, 3, 2, 2}; // Y-Coordinate
	//int direction[] = {UP, RIGHT, UP, LEFT, UP, RIGHT, DOWN, LEFT, DOWN, UP_RIGHT, LEFT, UP, RIGHT, DOWN, LEFT, DOWN_LEFT, DOWN_RIGHT, RIGHT, DOWN, LEFT, UP, RIGHT, UP_LEFT, DOWN, RIGHT, DOWN, LEFT};
	// Set initial a,b coordinate values
	int index = 0;

  while(index < size){    
    switch (direction[index]) {
      case 0: // UP
      case 1: // DOWN
        draw_vertical(direction[index], x[index] - 1, y[index] - 1, y[index + 1] - 1);
        break;
      case 2: // RIGHT
      case 3: // LEFT
        draw_horizontal(direction[index], y[index] - 1, x[index] - 1, x[index + 1] - 1);
      case 4:
      case 5:
      case 6:
      case 7:
        draw_diagonal(direction[index], x[index] - 1, y[index] - 1, x[index + 1] - 1, y[index + 1] - 1);
        break;
    }
    index++;
  }
}
void SetXY(uint8_t Xvalue, uint8_t Yvalue) {
  PORTD = (Xvalue<<4 | (Yvalue&0x0F));
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
