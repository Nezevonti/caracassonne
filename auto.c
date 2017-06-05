#include "auto.h"
#include <time.h>

int loop_auto(int width,int height, struct Tile map[height][width],short int quantities[14],struct Tile templates[14],char file_name[]){
    struct Coordinates *cand_list;
    int i=0;
    int j=0;
    int last_row,last_collumn;
    int rand_tile_type;
    int rand_number;
    bool isSomethingOK;
    int final_coord;
    struct Tile newTile;
    struct Tile new_Tile;

    int moves = 0;

    cand_list = malloc(sizeof(struct Coordinates)*128);

    srand(time(NULL));
    rand_number = rand()%9999+0;


    //printf("\nin auto...\n");
    /*
    struct Tile newTile;
    newTile.north=road;
    newTile.east=city;
    newTile.south=road;
    newTile.west=plane;
    newTile.isTemplePresent=false;


    map[2][2]=newTile;
    map[2][2].isEmpty = false;

    newTile.west=city;
    newTile.east=plane;
    map[2][3]=newTile;
    map[2][3].isEmpty = false;

    cand_list[0].row=1;
    cand_list[0].collumn=2;

    cand_list[1].row=2;
    cand_list[1].collumn=3;

    cand_list[2].row=2;
    cand_list[2].collumn=1;

    cand_list[3].row=3;
    cand_list[3].collumn=2;

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
    i=0;
    */

    last_row = height/2;
    last_collumn = width/2;
    srand(time(NULL));
    rand_tile_type = rand() %13+0;

    //printf("\nin auto 2...\n");

    cand_list[0].row=last_row-1;
    cand_list[0].collumn=last_collumn;

    cand_list[1].row=last_row;
    cand_list[1].collumn=last_collumn+1;

    cand_list[2].row=last_row;
    cand_list[2].collumn=last_collumn-1;

    cand_list[3].row=last_row+1;
    cand_list[3].collumn=last_collumn;

    //printf("\nin auto 2.5... rtt : %d\n",rand_tile_type);

    newTile = templates[rand_tile_type];
    //printf("\nin auto 2.6...\n");
    map[last_row][last_collumn]=newTile;

    //printf("\nin auto 2.75...\n");

    quantities[rand_tile_type]--;

    //printf("\nin auto 3...\n");

    int cand_number=4;

    for(i=0;i<(cand_number);++i){
        //printf("%d ",cand_list[i].row);
        //printf("%d \n",cand_list[i].collumn);
        //printf("%d\n",map[cand_list[i].row][cand_list[i].collumn].isEmpty);
    }
    //printf("-----\n");
    //printf("cand_number : %d \n",cand_number);
    //printf("S OF :%d\n",sizeof(cand_list));
    update_candidates(width,height,map,cand_list,&cand_number, 2, 3);
    //printf("S OF :%d\n",sizeof(cand_list));
    //printf("cand_number : %d \n\n",cand_number);

    for(i=0;i<(cand_number);++i){
        //printf("%d ",cand_list[i].row);
        //printf("%d\n",cand_list[i].collumn);
    }

    do{
        isSomethingOK=false;
        //update candidates
        //printf("\nin loop...\n");
        //update_candidates(width,height,map,cand_list,&cand_number, last_row, last_collumn);
        //pick
        //printf("\nupdated_cands\n");
        do{
            //printf("starting again...\n");
            srand(rand_number);
            rand_number = (rand()%9999+0);
            rand_tile_type = rand_number%14;

            newTile = templates[rand_tile_type];
            if(quantities[rand_tile_type]==0){
                //sleep(1);
                rand_number++;
                continue;
            }

            //printf("dddd\n");
            //printf("\npicked type : %d...\n",rand_tile_type);
            for(i=0;i<cand_number;++i){
                //check
                for(j=0;j<4;++j){
                    //printf("\nin rotation...\n");
                    rotate_Tile(&newTile,1);
                    if(check_validity(width,height,map,newTile,cand_list[i].row,cand_list[i].collumn)){
                        final_coord=i;
                        isSomethingOK=true;
                        //printf("\nfound a match...\n");
                        break;
                    }
                }
                //roatate if not

                //printf("%d of %d\n",i,cand_number);

                if(isSomethingOK) break;
                //if all 4 are bad go to next spot

            }
        }
        while(!isSomethingOK);
        //place
        last_row = cand_list[final_coord].row;
        last_collumn=cand_list[final_coord].collumn;

        map[last_row][last_collumn]=newTile;
        //update_quantities
        quantities[rand_tile_type]--;
        //print_to_screen/file?

        //print_to_screen(width,height,map);

        //printf("\nmoves : %d \n",moves+1);
        moves++;

        update_candidates(width,height,map,cand_list,&cand_number, last_row, last_collumn); //3rd pass problem is here

        //printf("waiting...\n");
        //sleep(1);
    }
    while(count_tiles_left(quantities) > 0);//count_tiles_left(quantities) > 0


    printf("\n\n--------\nFINISHED\n---------\n\n");
    print_to_screen(width,height,map);
    print_to_file(0,width,height,map,file_name);

    return 0;
}

int loop_manual(int width,int height, struct Tile map[height][width],short int quantities[14],struct Tile templates[14],char file_name[]){
    struct Coordinates *cand_list;
    int i=0;
    int j=0;
    int last_row,last_collumn;
    int rand_tile_type;
    int rand_number;
    bool isSomethingOK;
    int final_coord;
    struct Tile newTile;
    short int in_commands[4];

    int moves = 0;
    //-----
    do{
        read_from_console(&in_commands);

        if(in_commands[0]=='e'){
            break;
        }

        newTile = templates[in_commands[0]-1];
        rotate_Tile(&newTile,in_commands[3]);

        if(quantities[(in_commands[0]-1)]>0){
            if(moves>0){
                if(check_validity(width,height,map,newTile,in_commands[1],in_commands[2])){
                    map[in_commands[1]][in_commands[2]]=newTile;
                    quantities[(in_commands[0])-1]--;
                }
            }
            else{
                map[in_commands[1]][in_commands[2]]=newTile;
                quantities[(in_commands[0])-1]--;

            }
        }
        else{

        }
        print_to_screen(width,height,map);

    }
    while(count_tiles_left(quantities[14])>0);
    //-----
    printf("\n\n--------\nFINISHED\n---------\n\n");
    print_to_screen(width,height,map);
    print_to_file(0,width,height,map,file_name);

    return 0;
}

void update_candidates(int width,int height, struct Tile map[height][width],struct Coordinates *cand_list, int *cand_number, short int y, short int x){
    struct Coordinates newestTile;
    struct Coordinates tmp_list[(*cand_number)+3];
    int i,j,new_cands;
    i=0;
    j=0;
    //printf("p1 %d\n",*cand_number);

    //tmp_list = malloc(sizeof (newestTile)*(*cand_number+3));

   // printf("p1.5\n");
    for(i=0;i<(*cand_number+3);++i){
        tmp_list[i].row = NULL;
        tmp_list[i].collumn = NULL;
    }

    //printf("p1.8\n");

    newestTile.row = y;
    newestTile.collumn = x;

    //printf("p2\n");

    for(i=0;i<(*cand_number);++i){
        if(cand_list[i].row==y && cand_list[i].collumn==x){
            continue;
        }
        else{
            tmp_list[j].row=cand_list[i].row;
            tmp_list[j].collumn=cand_list[i].collumn;
            ++j;
        }
    }
    /*
    for(i=0;i<(*cand_number+3);++i){
        if(tmp_list[i].row == NULL){
            printf("NULL ");
        }
        else{
            printf("%d ",tmp_list[i].row);
        }
        if(tmp_list[i].collumn == NULL){
            printf("NULL\n");
        }
        else{
            printf("%d\n",tmp_list[i].collumn);
        }
    }
    printf("-------\n");
    */

    new_cands = j;
    //up
    if(y>0){
        if(map[y-1][x].isEmpty==1){
            tmp_list[j].row=y-1;
            tmp_list[j].collumn=x;
            j++;
        }
    }
    else{
    }

    //right
    if((x+1)<width){
        if(map[y][x+1].isEmpty==1){
            tmp_list[j].row=y;
            tmp_list[j].collumn=x+1;
            j++;
        }
    }
    else{
    }
    //left
    if(x>0){
        if(map[y][x-1].isEmpty==1){
            tmp_list[j].row=y;
            tmp_list[j].collumn=x-1;
            j++;
        }
    }
    else{
    }

    //down
    if((y+1)<width){
        if(map[y+1][x].isEmpty==1){
            tmp_list[j].row=y+1;
            tmp_list[j].collumn=x;
            j++;
        }
    }
    else{
    }

    /*
   for(i=0;i<(*cand_number+3);++i){
        if(tmp_list[i].row == NULL){
            printf("NULL ");
        }
        else{
            printf("%d ",tmp_list[i].row);
        }
        if(tmp_list[i].collumn == NULL){
            printf("NULL\n");
        }
        else{
            printf("%d\n",tmp_list[i].collumn);
        }
    }
    */

    //printf("-----\n");
    //printf("cand_number in up : %d \n",*cand_number);

    *cand_number+=(j-new_cands-1);

    //printf("cand_number in update : %d \n",*cand_number);
    realloc(cand_list, sizeof(struct Coordinates)*(*cand_number));


    for(i=0;i<(*cand_number);i++){
        //WHY U NO WORKING??
        cand_list[i].row=tmp_list[i].row;
        cand_list[i].collumn=tmp_list[i].collumn;

        //printf("cand: %d %d\n",cand_list[i].row,cand_list[i].collumn);
        //printf("tmp_: %d %d\n\n",tmp_list[i].row,tmp_list[i].collumn);

    }

    /*
    for(i=0;i<(*cand_number);++i){
        if(tmp_list[i].row == NULL){
            printf("NULL ");
        }
        else{
            printf("%d ",tmp_list[i].row);
        }
        if(tmp_list[i].collumn == NULL){
            printf("NULL\n");
        }
        else{
            printf("%d\n",tmp_list[i].collumn);
        }
    }

    printf("-------\n");

    for(i=0;i<(*cand_number);++i){
        if(cand_list[i].row == NULL){
            printf("NULL ");
        }
        else{
            printf("%d ",cand_list[i].row);
        }
        if(cand_list[i].collumn == NULL){
            printf("NULL\n");
        }
        else{
            printf("%d\n",cand_list[i].collumn);
        }
    }
    printf("########\n");
    */
    //printf("\ncand number : %d \n",*cand_number);
    //printf("@");
    //free(tmp_list);
    //tmp_list=NULL;
    //printf("updte_cands_end\n");
}
