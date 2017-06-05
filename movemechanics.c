
#include "movemechanics.h"

/*
    if(y=0){

    }
    else{

    }

*/

bool check_validity(int width, int height, struct Tile map[height][width], struct Tile new_Tile, short int y, short int x){
    short int empty_sides=0;

    if(map[y][x].isEmpty==0){
        return false;
    }
    //checking up
    if(y==0){
        empty_sides++;
    }
    else{
        if(y>0){//checking if the tile up even exists to avoid reaching outside of the array
            if(map[y-1][x].south==new_Tile.north || map[y-1][x].south==empty){ //check if sides match or next tile is empty
                    if(map[y-1][x].south==empty){
                            empty_sides++;
                    }
            }
            else{//sides dont match, move is not valid
                return false;
            }
        }
        else{//tile up is outside the map. I probably gonna change it so it uses all the space map has to offer.

        }
    }

    //check right
    if(x==(width-1)){
        empty_sides++;
    }
    else{
        if((x+1)<width){//Works in the same way as code above.
            if(map[y][x+1].west==new_Tile.east || map[y][x+1].west==empty){
                    if(map[y][x+1].west==empty){
                            empty_sides++;
                    }
            }
            else{
                return false;
            }
        }
        else{

        }
    }

    //check left
    if(x==0){
        empty_sides++;
    }
    else{
        if(x>0){
            if(map[y][x-1].east==new_Tile.west || map[y][x-1].east==empty){
                    if(map[y][x-1].east==empty){
                            empty_sides++;
                    }
            }
            else{
                return false;
            }
        }
        else{

        }
    }

    //check down
    if(y==(height-1)){
        empty_sides++;
    }
    else{
        if((y+1)<height){
            if(map[y+1][x].north==new_Tile.south || map[y+1][x].north==empty){
                    if(map[y+1][x].north==empty){
                            empty_sides++;
                    }
            }
            else{
                return false;
            }
        }
        else{

        }
    }
    //printf(" %d ",empty_sides);
    if(empty_sides==4){
        return false;
    }

    return true;
}

void rotate_Tile(struct Tile *new_Tile,short int rotation){
    enum Content tmp;

    rotation = rotation%4; //so it won't be more than 3

    switch(rotation){
    case 0:
        return ;
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

int count_tiles_left(short int quantities[14]){
    int q=0;
    int i;
    for(i=0;i<14;++i){
        q+=quantities[i];
    }
    return q;
}

int empty_sides(int width, int height, struct Tile map[height][width],short int y,short int x){

    int empty_count =0;
    //up
    if(y>0){
        if(map[y-1][x].isEmpty==1){
            ++empty_count;
        }
    }
    else{
        ++empty_count;
    }

    //right
    if((x+1)<width){
        if(map[y][x+1].isEmpty==1){
            ++empty_count;
        }
    }
    else{
        ++empty_count;
    }
    //left
    if(x>0){
        if(map[y][x-1].isEmpty==1){
            ++empty_count;
        }
    }
    else{
        ++empty_count;
    }

    //down
    if((y+1)<width){
        if(map[y+1][x].isEmpty==1){
            ++empty_count;
        }
    }
    else{
        ++empty_count;
    }

    return empty_count;
}
