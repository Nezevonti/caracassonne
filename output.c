
#include "output.h"
#include <stdio.h>
//change those to to start from 0
void print_to_screen(int width, int height, struct Tile map[height][width]){
    int i,j;
    for(i=0;i<(height);++i){//prints the map
        for(j=0;j<(width);++j){
            switch(map[i][j].north){//first the line with northern sides
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
        printf("\n");//next line

        for(j=0;j<(width);++j){//east and west
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
        printf("\n");//next line

        for(j=0;j<(width);++j){//southern side
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
    for(i=0;i<(width);++i){
        if(i<10) printf(" ");

        printf("%d ",i);
    }
    printf("\n");
}

void print_to_file(int score, int width, int height, struct Tile map[height][width]){
    /*
     c
    c c
     c
    */
    int i,j;
    FILE *fd = NULL;

    fd=fopen("output.txt","w+");
    if(fd == NULL){
        printf("Encountured and error while opening the file...\n");
        return 0;
    }

    for(i=0;i<(height);++i){//prints the map
        for(j=0;j<(width);++j){
            switch(map[i][j].north){//first the line with northern sides
                case city:
                    fprintf(fd," c ");
                    break;
                case plane:
                    fprintf(fd," p ");
                    break;
                case road:
                    fprintf(fd," r ");
                    break;
                case empty:
                    fprintf(fd," - ");
                    break;
            }
            fprintf(fd," ");
        }
        fprintf(fd,"\n");//next line

        for(j=0;j<(width);++j){//east and west
            switch(map[i][j].west){
                case city:
                    fprintf(fd,"c");
                    break;
                case plane:
                    fprintf(fd,"p");
                    break;
                case road:
                    fprintf(fd,"r");
                    break;
                case empty:
                    fprintf(fd,"-");
                    break;
            }

            if(map[i][j].isTemplePresent == 1){
                fprintf(fd,"T");
            }
            else{
                fprintf(fd," ");
            }

            switch(map[i][j].east){
                case city:
                    fprintf(fd,"c");
                    break;
                case plane:
                    fprintf(fd,"p");
                    break;
                case road:
                    fprintf(fd,"r");
                    break;
                case empty:
                    fprintf(fd,"-");
                    break;
            }
            fprintf(fd," ");
        }
        fprintf(fd,"\n");//next line

        for(j=0;j<(width);++j){//southern side
            switch(map[i][j].south){
                case city:
                    fprintf(fd," c ");
                    break;
                case plane:
                    fprintf(fd," p ");
                    break;
                case road:
                    fprintf(fd," r ");
                    break;
                case empty:
                    fprintf(fd," - ");
                    break;
            }
            fprintf(fd," ");

        }

        fprintf(fd,"\n \n");
    }
    fprintf(fd,"%d",score);

    fclose(fd);
}
