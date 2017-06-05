#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "Tile.h"

void read_from_console(short int in_commands[4]);

void read_library(struct Tile templates[14],char file_name[]);

void read_tiles(short int quantities[14],char file_name[]);

#endif // INPUT_H_INCLUDED
