#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef char bool;
#define true 1;
#define false 0;

#define SIZE 5

enum Content {city,road,plane,empty};

typedef struct Tile{
    enum Content north;
    enum Content east;
    enum Content south;
    enum Content west;
    bool isTemplePresent;
}Tile;

bool check_validity(struct Tile map[SIZE][SIZE],struct Tile new_Tile,short int y, short int x){ //re-written



    //checking up
    if(y>0){
            if(map[y-1][x].south==new_Tile.north || map[y-1][x].south==empty){

            }
            else{
                return false;
            }
    }
    else{

            return false;
    }

    //check right
    if((x+1)<SIZE){
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

}

/*
bool check_validity(struct Tile map[SIZE][SIZE],struct Tile new_Tile,short int x, short int y){

    bool return_value = true;
    //check up
    printf("%d %d \n",x,y);
    if((y-1)<SIZE){
        if(map[x][y-1].south==new_Tile.north || map[x][y-1].south==empty) printf("up ok\n");
        else{

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
            switch(map[x][y-1].south){
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

            return false;
        }
    }
    else{
        printf("Border issue...");
        return false;
    }

    //check right
    if((x+1)<SIZE){
        if(map[x+1][y].west==new_Tile.east || map[x+1][y].west==empty)printf("right ok\n");
        else{

            switch(new_Tile.east){
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
            switch(map[x+1][y].west){
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

            return false;
        }
    }
    else{
        printf("Border issue...");
        return false;
    }

    //check left
    if((x-1)>=0){
        if(map[x-1][y].east==new_Tile.west || map[x-1][y].east==empty)printf("left ok\n");
        else{

            switch(new_Tile.west){
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
            switch(map[x-1][y].east){
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

            return false;
        }
    }
    else{
        printf("Border issue...");
        return false;
    }

    //check down
    if((y+1)<SIZE){
        if(map[x][y+1].north==new_Tile.south || map[x][y+1].north==empty)printf("down ok\n");
        else{

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
            switch(map[x][y+1].north){
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

            return false;
        }
    }
    else{
        printf("Border issue...");
        return false;
    }

    return return_value;
}
*/

void fill_map_empty(struct Tile map[SIZE][SIZE]){
    int i,j;
    for(i=0;i<SIZE;++i){
        for(j=0;j<SIZE;++j){
            map[i][j].north = empty;
            map[i][j].east = empty;
            map[i][j].south = empty;
            map[i][j].west = empty;
        }
    }
}

void print_map(struct Tile map[SIZE][SIZE]){
    int i,j;
    for(i=1;i<(SIZE-1);++i){
        for(j=1;j<(SIZE-1);++j){
            switch(map[i][j].north){
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
                    printf(" - ");
                    break;
            }
        }
        printf("\n");

        for(j=1;j<(SIZE-1);++j){
            switch(map[i][j].west){
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
                    printf("- ");
                    break;
            }
            switch(map[i][j].east){
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
                    printf("-");
                    break;
            }
        }
        printf("\n");

        for(j=1;j<(SIZE-1);++j){
            switch(map[i][j].south){
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
                    printf(" - ");
                    break;
            }

        }
        printf(" %d\n",i);
    }
    for(i=1;i<(SIZE-1);i++){
        printf(" %d ",i);
    }
    printf("\n");
}

void fill_templates(struct Tile templates[14]){
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

void get_input(short int in_commands[4]){

    //tile y x r
    scanf("%d %d %d %d",&in_commands[0],&in_commands[1],&in_commands[2],&in_commands[3]);
}

void rotate_Tile(struct Tile *new_Tile,short int rotation){
    enum Content tmp;
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

bool Loop(struct Tile map[SIZE][SIZE],struct Tile templates[14]){

    short int in_commands[4];
    struct Tile new_Tile;


    //take input
    get_input(&in_commands);

    //printf("%d %d %d %d\n",in_commands[0],in_commands[1],in_commands[2],in_commands[3]);

    new_Tile = templates[in_commands[0]-1];
    rotate_Tile(&new_Tile,in_commands[3]);


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
    if(check_validity(map,new_Tile,in_commands[1],in_commands[2])){
        printf("valid\n\n");
        map[in_commands[1]][in_commands[2]]=new_Tile;
    }
    else{
        map[in_commands[1]][in_commands[2]]=new_Tile;
        printf("INVALID!\n\n");
    }

    //process


    //clear screen
    //system("CLS");

    //display
    print_map(map);

}


int main()
{
    struct Tile templates[14];
    struct Tile map[SIZE][SIZE];
    struct Tile new_Tile;

    fill_map_empty(&map);
    fill_templates(&templates);

    print_map(map);

    for(int i=0;i<20;i++){
        Loop(&map,templates);
    }



    /*
    map[2][2].north = city;
    map[2][2].east = road;
    map[2][2].south = plane;
    map[2][2].west = road;
    //map[y][x];
    new_Tile.north = plane;
    new_Tile.east = road;
    new_Tile.south = plane;
    new_Tile.west = road;



    if(check_validity(&map,new_Tile,3,2)){
        printf("valid\n");
        map[2][3]=new_Tile;
        print_map(map);
    }
    else{
        printf("INVALID!\n");
    }

    rotate_Tile(&new_Tile,1);



    if(check_validity(&map,new_Tile,3,2)){
        printf("valid\n");
        map[2][3]=new_Tile;
        print_map(map);
    }
    else{
        printf("INVALID!\n");
    }
    */


    return 0;
}
