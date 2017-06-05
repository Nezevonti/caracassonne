#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#include "output.h"
#include "input.h"
#include "Tile.h"
#include "movemechanics.h"

typedef char bool;
#define true 1;
#define false 0;


#define SIZE 17

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



int rand_coordinate(int max,int moves){
    int seed = time(NULL);
    srand(seed);
    return rand() %max + 0;
}

void fill_map_empty(struct Tile map[SIZE][SIZE]){
    int i,j;
    for(i=0;i<SIZE;++i){//fills all tiles with "empty" to avoid any surprizes
        for(j=0;j<SIZE;++j){
            map[i][j].north = empty;
            map[i][j].east = empty;
            map[i][j].south = empty;
            map[i][j].west = empty;
            map[i][j].isTemplePresent=false;
            map[i][j].isEmpty=true;
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
/*
bool Loop(struct Tile map[SIZE][SIZE],struct Tile templates[14],short int quantities[14],int *moves){

    short int in_commands[4];
    struct Tile new_Tile;


    //take input
    //get_input_user(&in_commands);

    read_from_console(&in_commands);
    /*
    in_commands[0] = rand_coordinate(14,moves);
    in_commands[0]++;
    do{
        in_commands[1] = rand_coordinate(SIZE,moves);
        in_commands[2] = rand_coordinate(SIZE,moves+in_commands[1]);
        in_commands[3] = rand_coordinate(3,moves);
        new_Tile = templates[in_commands[0]-1];
        rotate_Tile(&new_Tile,in_commands[3]);

        if(*moves==0){
            break;
            printf("moves = 0\n");
        }
        printf("%d %d %d %d\n",in_commands[0],in_commands[1],in_commands[2],in_commands[3]);
    }
    while(!check_validity(SIZE,SIZE,map,new_Tile,in_commands[1],in_commands[2]));


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
    //printf("%d %d %d %d\n",in_commands[0],in_commands[1],in_commands[2],in_commands[3]);
    char c;
    if(map[in_commands[1]][in_commands[2]].isEmpty==1){
        c='T';
    }
    else{
        c='F';
    }
    printf("%c ",c);
    printf("%d",*moves);
    //check validity
    if(quantities[in_commands[0]-1]>0){//check if tiles are aviable
        if(check_validity(SIZE,SIZE,map,new_Tile,in_commands[1],in_commands[2])){
            printf("valid\n\n");
            map[in_commands[1]][in_commands[2]]=new_Tile;
            map[in_commands[1]][in_commands[2]].isEmpty=false;
            --quantities[in_commands[0]-1];
        }
        else{
            if(*moves==0){
                printf("valid\n\n");
                map[in_commands[1]][in_commands[2]]=new_Tile;
                map[in_commands[1]][in_commands[2]].isEmpty=false;
                --quantities[in_commands[0]-1];
            }
            else{
                printf("INVALID!\n\n");
            }
        }
    }
    else{
        printf("no tiles avaliable!\n");
    }
    //process
    ++*moves;

    //clear screen
    //system("CLS");

    //display
    //print_map(map);
    print_to_screen(SIZE,SIZE,map);
    print_to_file(0,SIZE, SIZE, map);

    return true;
}

*/

int main(int argc,char *argv[])
{
    //0 0 3 0 5 1 1 7 2 0 3 2 1 6
    short int quantities[14]={0,0,3,0,5,1,1,7,2,0,3,2,1,5};
    struct Tile templates[14];
    struct Tile map[SIZE][SIZE];
    struct Tile new_Tile;
    int moves = 0;
    bool test = true;
    int i;

    //if(argc!=)

    read_library(&templates,argv[3]);
    read_tiles(&quantities,argv[2]);

    fill_map_empty(&map);

    //printf("%d",argc);

    if(strcmp(argv[1],"a")==0){
        loop_auto(SIZE,SIZE,&map,&quantities,templates,argv[4]);//go auto
    }
    else{
        loop_manual(SIZE,SIZE,&map,&quantities,templates,argv[4]);//go manual
    }
    //print_to_file(0,SIZE,SIZE,map,argv[4]);

    //for(i=1;i<argc;++i){
        //printf("%s\n",argv[i]);
    //}

    //print_map(map);
    //print_to_screen(SIZE,SIZE,map);

    /*
    for(i=0;test==1;i++){
        if(count_tiles_left(quantities)==0){
            test = 0;
            break;
        }
        Loop(&map,templates,&quantities,&moves);
    }
    */




    /*
    printf("\n");
    for(i=0;i<14;++i){
        printf("%d ",quantities[i]);
    }
    printf("\n");

    */


    /*
    for(i=0;i<14;++i){
        new_Tile=templates[i];
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
    printf("\n%d\n",new_Tile.isTemplePresent);
    }
    */

    /*
    srand(time(NULL));
    int rand_tmp=rand()%99999+0;

    for(i=0;i<100;i++){
        //srand(time(NULL));
        printf("%d\n",rand_tmp%14);

        srand(rand_tmp);
        rand_tmp=rand()%99999+0;

    }

    */
    return 0;
}
