#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

typedef char bool;
#define true 1;
#define false 0;

enum Content {city,road,plane,empty};

typedef struct Tile{
    enum Content north;
    enum Content east;
    enum Content south;
    enum Content west;
    bool isTemplePresent;
}Tile;

#endif // TILE_H_INCLUDED
