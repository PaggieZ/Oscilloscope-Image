int UP = 0;
int DOWN = 1;
int RIGHT = 2;
int LEFT = 3;

int UP_RIGHT = 4;
int DOWN_LEFT = 5;
int DOWN_RIGHT = 6;
int UP_LEFT = 7;

int drawdelay = 10;

int K_x[] = {1, 1, 2, 2, 1, 1, 6, 6, 5, 5, 8, 7, 7, 13, 13, 12, 7, 12, 13, 13, 7, 7, 8, 5, 5, 6, 6, 1}; // X-Coordinate, the last index has the first point
int K_y[] = {2, 3, 3, 13, 13, 14, 14, 13, 13, 10, 13, 13, 14, 14, 13, 13, 8, 3, 3, 2, 2, 3, 3, 6, 3, 3, 2, 2};
int K_direction[] = {UP, RIGHT, UP, LEFT, UP, RIGHT, DOWN, LEFT, DOWN, UP_RIGHT, LEFT, UP, RIGHT, DOWN, LEFT, DOWN_LEFT, DOWN_RIGHT, RIGHT, DOWN, LEFT, UP, RIGHT, UP_LEFT, DOWN, RIGHT, DOWN, LEFT};
