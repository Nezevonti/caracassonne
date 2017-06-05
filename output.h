#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include "Tile.h"

#include <stdio.h>
#include <string.h>

void print_to_screen(int width,int height,struct Tile map[height][width]);

void print_to_file(int score,int width,int height,struct Tile map[height][width],char file_name[]);

#endif // OUTPUT_H_INCLUDED
