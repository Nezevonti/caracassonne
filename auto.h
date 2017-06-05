#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include "Tile.h"
#include <time.h>

int loop_auto(int width,int height, struct Tile map[height][width],short int quantities[14],struct Tile templates[14],char file_name[]);

void update_candidates(int width,int height, struct Tile map[height][width],struct Coordinates *cand_list, int *cand_number, short int y, short int x);

int loop_manual(int width,int height, struct Tile map[height][width],short int quantities[14],struct Tile templates[14],char file_name[]);

#endif // AUTO_H_INCLUDED
