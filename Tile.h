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
    bool isEmpty;
}Tile;

typedef struct Coordinates{
    int row;
    int collumn;
}Coordinates;

#endif // TILE_H_INCLUDED
