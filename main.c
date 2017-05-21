#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "output.h"
#include "input.h"
#include "Tile.h"
#include "movemechanics.h"

typedef char bool;
#define true 1;
#define false 0;


#define SIZE 7

/*
Split into files:
-Input -bb
-Output -done
-Move checking -done
-manual
-auto
*/

/*
"Blueprint" for all tiles that will follow the pattern. I'm using enums to avoid having something unexpected
show up in sides (north,east...) fields.

*/

/*
bool check_validity(struct Tile map[SIZE][SIZE],struct Tile new_Tile,short int y, short int x){ //re-written
    //checking up
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

    //check right
    if((x+1)<SIZE){//Works in the same way as code above.
        if(map[y][x+1].west==new_Tile.east || map[y][x+1].west==empty){

        }
        else{
            return false;
        }
    }
    else{

         return false;
    }

    //check left
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

    //check down
    if((y+1)<SIZE){
            if(map[y+1][x].north==new_Tile.south || map[y+1][x].north==empty){

            }
            else{
                return false;
            }
    }
    else{

        return false;
    }
    return true;
}
*/

void fill_map_empty(struct Tile map[SIZE][SIZE]){
    int i,j;
    for(i=0;i<SIZE;++i){//fills all tiles with "empty" to avoid any surprizes
        for(j=0;j<SIZE;++j){
            map[i][j].north = empty;
            map[i][j].east = empty;
            map[i][j].south = empty;
            map[i][j].west = empty;
            map[i][j].isTemplePresent=false;
        }
    }
}

void fill_templates(struct Tile templates[14]){//change to reading from lib
    //nesw
    //1
    templates[0].north=plane;
    templates[0].east=plane;
    templates[0].south=road;
    templates[0].west=plane;
    templates[0].isTemplePresent=true;

    //2
    templates[1].north=plane;
    templates[1].east=plane;
    templates[1].south=plane;
    templates[1].west=plane;
    templates[1].isTemplePresent=true;

    //3
    templates[2].north=city;
    templates[2].east=city;
    templates[2].south=city;
    templates[2].west=city;
    templates[2].isTemplePresent=false;

    //4
    templates[3].north=road;
    templates[3].east=city;
    templates[3].south=road;
    templates[3].west=plane;
    templates[3].isTemplePresent=false;

    //5
    templates[4].north=city;
    templates[4].east=plane;
    templates[4].south=plane;
    templates[4].west=plane;
    templates[4].isTemplePresent=false;

    //6
    templates[5].north=plane;
    templates[5].east=city;
    templates[5].south=plane;
    templates[5].west=city;
    templates[5].isTemplePresent=false;

    //7
    templates[6].north=plane;
    templates[6].east=city;
    templates[6].south=city;
    templates[6].west=plane;
    templates[6].isTemplePresent=false;

    //8
    templates[7].north= city;
    templates[7].east=road;
    templates[7].south=road;
    templates[7].west=plane;
    templates[7].isTemplePresent=false;

    //9
    templates[8].north=road;
    templates[8].east=city;
    templates[8].south=plane;
    templates[8].west=road;
    templates[8].isTemplePresent=false;

    //10
    templates[9].north=road;
    templates[9].east=city;
    templates[9].south=road;
    templates[9].west=road;
    templates[9].isTemplePresent=false;

    //11
    templates[10].north=road;
    templates[10].east=plane;
    templates[10].south=road;
    templates[10].west=plane;
    templates[10].isTemplePresent=false;

    //12
    templates[11].north=plane;
    templates[11].east=plane;
    templates[11].south=road;
    templates[11].west=road;
    templates[11].isTemplePresent=false;

    //13
    templates[12].north=plane;
    templates[12].east=road;
    templates[12].south=road;
    templates[12].west=road;
    templates[12].isTemplePresent=false;

    //14
    templates[13].north=road;
    templates[13].east=road;
    templates[13].south=road;
    templates[13].west=road;
    templates[13].isTemplePresent=false;

}

bool Loop(struct Tile map[SIZE][SIZE],struct Tile templates[14],short int quantities[14]){

    short int in_commands[4];
    struct Tile new_Tile;


    //take input
    //get_input_user(&in_commands);
    read_from_console(&in_commands);

    //roatate tile
    new_Tile = templates[in_commands[0]-1];
    rotate_Tile(&new_Tile,in_commands[3]);

    //print roatated tile
    switch(new_Tile.north){
                case city:
                    printf(" c ");
                    break;
                case plane:
                    printf(" p ");
                    break;
                case road:
                    printf(" r ");
                    break;
                case empty:
                    printf("   ");
                    break;
            }
        printf("\n");

    switch(new_Tile.west){
                case city:
                    printf("c ");
                    break;
                case plane:
                    printf("p ");
                    break;
                case road:
                    printf("r ");
                    break;
                case empty:
                    printf("  ");
                    break;
            }
    switch(new_Tile.east){
                case city:
                    printf("c");
                    break;
                case plane:
                    printf("p");
                    break;
                case road:
                    printf("r");
                    break;
                case empty:
                    printf(" ");
                    break;
            }
        printf("\n");


    switch(new_Tile.south){
                case city:
                    printf(" c ");
                    break;
                case plane:
                    printf(" p ");
                    break;
                case road:
                    printf(" r ");
                    break;
                case empty:
                    printf("   ");
                    break;
            }


    printf("\n\n----\n");


    //check validity
    if(quantities[in_commands[0]-1]>0){//check if tiles are aviable
        if(check_validity(SIZE,SIZE,map,new_Tile,in_commands[1],in_commands[2])){
            printf("valid\n\n");
            map[in_commands[1]][in_commands[2]]=new_Tile;
        }
        else{
            printf("INVALID!\n\n");
        }
    }
    else{
        printf("no tiles avaliable!\n");
    }
    //process


    //clear screen
    //system("CLS");

    //display
    //print_map(map);
    print_to_screen(SIZE,SIZE,map);
    print_to_file(0,SIZE, SIZE, map);


    return true;
}


int main()
{
    short int quantities[14]={5,5,5,5,5,5,5,5,5,5,5,5,5,5};
    struct Tile templates[14];
    struct Tile map[SIZE][SIZE];
    struct Tile new_Tile;

    fill_map_empty(&map);
    fill_templates(&templates);


    //print_map(map);

    for(int i=0;i<20;i++){
        Loop(&map,templates,&quantities);
    }



    return 0;
}
