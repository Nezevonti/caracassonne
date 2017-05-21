#ifndef MOVEMECHANICS_H_INCLUDED
#define MOVEMECHANICS_H_INCLUDED

#include "Tile.h"

void rotate_Tile(struct Tile *new_Tile,short int rotation);

bool check_validity(int width,int height, struct Tile map[height][width],struct Tile new_Tile, short int y, short int x);

bool check_up();

bool check_right();

bool check_down();

bool check_left();

#endif // MOVEMECHANICS_H_INCLUDED
