
#include "movemechanics.h"

/*
    if(y=0){

    }
    else{

    }

*/

bool check_validity(int width, int height, struct Tile map[height][width], struct Tile new_Tile, short int y, short int x){
    //checking up
    if(y==0){

    }
    else{
        if(y>0){//checking if the tile up even exists to avoid reaching outside of the array
            if(map[y-1][x].south==new_Tile.north || map[y-1][x].south==empty){ //check if sides match or next tile is empty

            }
            else{//sides dont match, move is not valid
                return false;
            }
        }
        else{//tile up is outside the map. I probably gonna change it so it uses all the space map has to offer.
            return false;
        }
    }

    //check right
    if(x==(width-1)){

    }
    else{
        if((x-1)<width){//Works in the same way as code above.
            if(map[y][x+1].west==new_Tile.east || map[y][x+1].west==empty){

            }
            else{
                return false;
            }
        }
        else{
         return false;
        }
    }

    //check left
    if(x==0){

    }
    else{
        if(x>0){
            if(map[y][x-1].east==new_Tile.west || map[y][x-1].east==empty){

            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }

    //check down
    if(y==(height-1)){

    }
    else{
        if((y-1)<height){
            if(map[y+1][x].north==new_Tile.south || map[y+1][x].north==empty){

            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    return true;
}

void rotate_Tile(struct Tile *new_Tile,short int rotation){
    enum Content tmp;

    rotation = rotation%4; //so it won't be more than 3

    switch(rotation){
    case 1:
        tmp = new_Tile->north;
        new_Tile->north=new_Tile->west;
        new_Tile->west=new_Tile->south;
        new_Tile->south=new_Tile->east;
        new_Tile->east=tmp;
        break;

    case 2:
        tmp = new_Tile->north;
        new_Tile->north=new_Tile->south;
        new_Tile->south=tmp;
        tmp=new_Tile->west;
        new_Tile->west=new_Tile->east;
        new_Tile->east=tmp;
        break;

    case 3:
        tmp = new_Tile->north;
        new_Tile->north=new_Tile->east;
        new_Tile->east=new_Tile->south;
        new_Tile->south=new_Tile->west;
        new_Tile->west=tmp;

    }
}
