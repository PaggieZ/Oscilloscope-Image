int UP = 0;
int DOWN = 1;
int RIGHT = 2;
int LEFT = 3;

int UP_RIGHT = 4;
int DOWN_LEFT = 5;
int DOWN_RIGHT = 6;
int UP_LEFT = 7;

int drawdelay = 10;
int count = 500;

int K_x[] = {1, 1, 2, 2, 1, 1, 6, 6, 5, 5, 8, 7, 7, 13, 13, 12, 7, 12, 13, 13, 7, 7, 8, 5, 5, 6, 6, 1}; // X-Coordinate, the last index has the first point
int K_y[] = {2, 3, 3, 13, 13, 14, 14, 13, 13, 10, 13, 13, 14, 14, 13, 13, 8, 3, 3, 2, 2, 3, 3, 6, 3, 3, 2, 2};
int K_direction[] = {UP, RIGHT, UP, LEFT, UP, RIGHT, DOWN, LEFT, DOWN, UP_RIGHT, LEFT, UP, RIGHT, DOWN, LEFT, DOWN_LEFT, DOWN_RIGHT, RIGHT, DOWN, LEFT, UP, RIGHT, UP_LEFT, DOWN, RIGHT, DOWN, LEFT};
int K_size = 27;

int E_x[] = {1, 1, 2, 2, 1, 1, 13, 13, 11, 11, 5, 5, 9, 9, 11, 11, 9, 9, 5, 5, 11, 11, 13, 13, 1};
int E_y[] = {2, 3, 3, 13, 13, 14, 14, 11, 11, 12, 12, 9, 9, 10, 10, 6, 6, 7, 7, 4, 4, 5, 5, 2, 2};
int E_direction[] = {UP, RIGHT, UP, LEFT, UP, RIGHT, DOWN, LEFT, UP, LEFT, DOWN, RIGHT, UP, RIGHT, DOWN, LEFT, UP, LEFT, DOWN, RIGHT, UP, RIGHT, DOWN, LEFT};
int E_size = 24;

int Y_x[] = {1, 1, 2, 7, 2, 1, 1, 7, 7, 6, 9, 12, 11, 11, 16, 16, 15, 5, 6, 6, 1};
int Y_y[] = {2, 3, 3, 8, 13, 13, 14, 14, 13, 13, 10, 13, 13, 14, 14, 13, 13, 3, 3, 2, 2};
int Y_direction[] = {UP, RIGHT, UP_RIGHT, UP_LEFT, LEFT, UP, RIGHT, DOWN, LEFT, DOWN_RIGHT, UP_RIGHT, LEFT, UP, RIGHT, DOWN, LEFT, DOWN_LEFT, RIGHT, DOWN, LEFT};
int Y_size = 20;

int S_x[] = {2, 2, 5, 5, 9, 9, 2, 2, 12, 12, 10, 10, 5, 5, 12, 12, 2};
int S_y[] = {2, 5, 5, 4, 4, 7, 7, 14, 14, 11, 11, 12, 12, 9, 9, 2, 2};
int S_direction[] = {UP, RIGHT, DOWN, RIGHT, UP, LEFT, UP, RIGHT, DOWN, LEFT, UP, LEFT, DOWN, RIGHT, DOWN, LEFT};
int S_size = 16;

int I_x[] = {5, 5, 7, 7, 5, 5, 12, 12, 10, 10, 12, 12, 5};
int I_y[] = {2, 4, 4, 12, 12, 14, 14, 12, 12, 4, 4, 2, 2};
int I_direction[] = {UP, RIGHT, UP, LEFT, UP, RIGHT, DOWN, LEFT, DOWN, RIGHT, DOWN, LEFT};
int I_size = 12;

int G_x[] = {5, 3, 3, 5, 13, 13, 11, 11, 6, 5, 5, 6, 11, 11, 9, 9, 7, 7, 9, 9, 13, 13, 12, 5};
int G_y[] = {2, 4, 12, 14, 14, 11, 11, 12, 12, 11, 5, 4, 4, 7, 7, 6, 6, 10, 10, 9, 9, 3, 2, 2};
int G_direction[] = {UP_LEFT, UP, UP_RIGHT, RIGHT, DOWN, LEFT, UP, LEFT, DOWN_LEFT, DOWN, DOWN_RIGHT, RIGHT, UP, LEFT, DOWN, LEFT, UP, RIGHT, DOWN, RIGHT, DOWN, DOWN_LEFT, LEFT};
int G_size = 23;

int H_x[] = {3, 3, 4, 4, 3, 3, 7, 7, 6, 6, 10, 10, 9, 9, 13, 13, 12, 12, 13, 13, 9, 9, 10, 10, 6, 6, 7, 7, 3};
int H_y[] = {3, 4, 4, 13, 13, 14, 14, 13, 13, 10, 10, 13, 13, 14, 14, 13, 13, 4, 4, 3, 3, 4, 4, 8, 8, 5, 4, 3, 3};
int H_direction[] = {UP, RIGHT, UP, LEFT, UP, RIGHT, DOWN, LEFT, DOWN, RIGHT, UP, LEFT, UP, RIGHT, DOWN, LEFT, DOWN, RIGHT, DOWN, LEFT, UP, RIGHT, UP, LEFT, DOWN, RIGHT, DOWN, LEFT};
int H_size = 28;

int T_x[] = {7, 7, 3, 3, 13, 13, 9, 9, 7};
int T_y[] = {2, 12, 12, 14, 14, 12, 12, 2, 2};
int T_direction[] = {UP, LEFT, UP, RIGHT, DOWN, LEFT, DOWN, LEFT};
int T_size = 8;

int HB_x[] = {9, 2, 2, 4, 7, 9, 11, 14, 16, 16, 9};
int HB_y[] = {3, 10, 12, 14, 14, 12, 14, 14, 12, 10, 3};
int HB_direction[] = {UP_LEFT, UP, UP_RIGHT, RIGHT, DOWN_RIGHT, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT};
int HB_size = 10;

int HS_x[] = {9, 5, 5, 6, 7, 9, 11, 12, 13, 13, 9};
int HS_y[] = {6, 10, 11, 12, 12, 10, 12, 12, 11, 10, 6};
int HS_direction[] = {UP_LEFT, UP, UP_RIGHT, RIGHT, DOWN_RIGHT, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT};
int HS_size = 10;

// drawing KEY
int key_x[] = {5, 4, 2, 2, 1, 1, 2, 2, 4, 5, 3, 3, 5/* end of K */, 9, 9, 6, 6, 8, 8, 6, 6, 9, 9, 5, 5 /*end of E*/, 10, 10, 9, 9, 10, 10, 11, 11, 12, 12, 11, 11, 10 /*end of Y*/, 5};
int key_y[] = {11, 11, 13, 11, 11, 16, 14, 14, 16, 16, 14, 13, 11/*end of K */, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 11 /*end of E*/, 11, 13, 13, 16, 16, 14, 14, 16, 16, 13, 13, 11, 11 /*end of Y*/, 11};
int key_direction[] = {LEFT, UP_LEFT, DOWN, LEFT, UP, RIGHT, DOWN, UP_RIGHT, RIGHT, DOWN_LEFT, DOWN, DOWN_RIGHT /*K*/, RIGHT, UP, LEFT, UP, RIGHT, UP, LEFT, UP, RIGHT, UP, LEFT, DOWN /*E*/, RIGHT, UP, LEFT, UP, RIGHT, DOWN, RIGHT, UP, RIGHT, DOWN, LEFT, DOWN, LEFT /*Y*/, LEFT};
int key_size = 38;
// Updated KEY
/*
int key_x[] = {5, 4, 3, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 4, 5, 4, 3, 3, 4, 5/* end of K */, 9,  9,  6,  6,  8,  8,  6,  6,  9,  9, 5, 5 /*end of E*/, 10, 10, 9, 9, 10, 10, 11, 11, 12, 12, 11, 11, 10 /*end of Y*/, 5};
int key_y[] = {11, 11, 12, 13, 12, 11, 11, 12, 13, 14, 15, 16, 16, 15, 14, 15, 16, 16, 15, 14, 13, 12, 11/*end of K */, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 11 /*end of E*/, 11, 13, 13, 16, 16, 14, 14, 16, 16, 13, 13, 11, 11 /*end of Y*/, 11};
int key_direction[] = {LEFT, UP_LEFT, UP_LEFT, DOWN, DOWN, LEFT, UP, UP, UP, UP, UP, RIGHT, DOWN, DOWN, UP_RIGHT, UP_RIGHT, RIGHT, DOWN_LEFT, DOWN_LEFT, DOWN, DOWN_RIGHT, DOWN_RIGHT/*K*/, RIGHT, UP, LEFT, UP, RIGHT, UP, LEFT, UP, RIGHT, UP, LEFT, DOWN /*E*/, RIGHT, UP, LEFT, UP, RIGHT, DOWN, RIGHT, UP, RIGHT, DOWN, LEFT, DOWN, LEFT /*Y*/, LEFT};
int key_size = 48;
*/


// drawing SIGHT
int sight_x[] = {3, 1, 1, 2, 2, 1, 1, 3, 3, 2, 2, 3, 3/*end of S*/, 6, 6, 5, 5, 6, 6, 3, 3, 4, 4, 3, 3, 6 /*end of I*/, 9, 9, 7, 7, 8, 8, 10, 10, 9, 9, 6, 6, 9 /*end of G*/, 10, 11, 11, 12, 12, 13, 13, 12, 12, 11, 11, 10, 10, 11, 11, 12, 12, 13 /*end of H*/, 16, 16, 15, 15, 14, 14, 13, 13 };
int sight_y[] = {11, 11, 8, 8, 7, 7, 6, 6, 9, 9, 10, 10, 11 /*end of S*/, 11, 10, 10, 7, 7, 6, 6, 7, 7, 10, 10, 11, 11 /*end of I*/, 11, 10, 10, 7, 7, 9, 9, 8, 8, 6, 6, 11, 11 /*end of G*/, 11, 11, 9, 9, 11, 11, 6, 6, 8, 8, 6, 6, 11, 11, 9, 9, 11, 11 /*end of H*/, 11, 10, 10, 6, 6, 10, 10, 11};
int sight_direction[] = {LEFT, DOWN, RIGHT, DOWN, LEFT, DOWN, RIGHT, UP, LEFT, UP, RIGHT, UP/*S*/, RIGHT, DOWN, LEFT, DOWN, RIGHT, DOWN, LEFT, UP, RIGHT, UP, LEFT, UP, RIGHT/*I*/, RIGHT, DOWN, LEFT, DOWN, RIGHT, UP, RIGHT, DOWN, LEFT, DOWN, LEFT, UP, RIGHT/*G*/, RIGHT, RIGHT, DOWN, RIGHT, UP, RIGHT, DOWN, LEFT, UP, LEFT, DOWN, LEFT, UP, RIGHT, DOWN, RIGHT, UP, RIGHT/*H*/, RIGHT, DOWN, LEFT, DOWN, LEFT, UP, LEFT, UP};
int sight_size = 64;

/*
int logo_x[] = {13, 15, 16, 2, 3, 5, 9, 13};
int logo_y[] = {5, 3, 4, 4, 3, 5, 1, 5};
int logo_direction[] = {DOWN_RIGHT, UP_RIGHT, LEFT, DOWN_RIGHT, UP_RIGHT, DOWN_RIGHT, UP_RIGHT};
int logo_size = 8;
*/
int logo_x[] = {13, 13, 15, 16, 2, 3, 5, 9, 13};
int logo_y[] = {11, 5, 3, 4, 4, 3, 5, 1, 5};
int logo_direction[] = {DOWN, DOWN_RIGHT, UP_RIGHT, LEFT, DOWN_RIGHT, UP_RIGHT, DOWN_RIGHT, UP_RIGHT};
int logo_size = 8;

int back_x[] = {13, 13, 12, 12, 11, 11, 10, 10, 9, 9, 6, 6};
int back_y[] = {5, 6, 6, 8, 8, 6, 6, 8, 8, 6, 6, 11};
int back_direction[] = {UP, LEFT, UP, LEFT, DOWN, LEFT, UP, LEFT, DOWN, LEFT, UP};
int back_size = 11;

int tri_x[] = {1, 4, 4, 1};
int tri_y[] = {1, 1, 4, 1};
int tri_direction[] = {RIGHT, UP, DOWN_LEFT};

