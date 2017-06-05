#ifndef MOVEMECHANICS_H_INCLUDED
#define MOVEMECHANICS_H_INCLUDED

#include "Tile.h"

void rotate_Tile(struct Tile *new_Tile,short int rotation);

bool check_validity(int width,int height, struct Tile map[height][width],struct Tile new_Tile, short int y, short int x);

int empty_sides(int width,int height, struct Tile map[height][width],short int y, short int x);

int count_tiles_left(short int quantities[14]);

#endif // MOVEMECHANICS_H_INCLUDED
