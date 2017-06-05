
#include "input.h"
#include <stdio.h>

void read_from_console(short int in_commands[4]){
    //tile y x r
    printf("tile row collumn rotation \n");
    scanf("%d %d %d %d",&in_commands[0],&in_commands[1],&in_commands[2],&in_commands[3]);
}


void read_library(struct Tile templates[14],char file_name[]){
    FILE *pFile;
    char str[7];
    int i=0;
    int j=0;
    pFile = fopen(file_name,"r");

    do{
        fscanf(pFile,"%s",str);
        //printf("%s \n",str);

        //north
        switch(str[0]){
            case 'C':
                templates[i].north=city;
                break;
            case 'P':
                templates[i].north=plane;
                break;
            case 'R':
                templates[i].north=road;
                break;
        }

        //east
        switch(str[1]){
            case 'C':
                templates[i].east=city;
                break;
            case 'P':
                templates[i].east=plane;
                break;
            case 'R':
                templates[i].east=road;
                break;
        }

        //south
        switch(str[2]){
            case 'C':
                templates[i].south=city;
                break;
            case 'P':
                templates[i].south=plane;
                break;
            case 'R':
                templates[i].south=road;
                break;
        }

        //west
        switch(str[3]){
            case 'C':
                templates[i].west=city;
                break;
            case 'P':
                templates[i].west=plane;
                break;
            case 'R':
                templates[i].west=road;
                break;
        }
        //isTemple
        if(str[4]=='T'){
            templates[i].isTemplePresent=1;
            //printf("Y %c\n",str[4]);
        }
        else{
            templates[i].isTemplePresent=0;
            //printf("N %c\n",str[4]);
        }


        ++i;
    }
    while(fgetc(pFile)!=EOF);

    fclose(pFile);
}


void read_tiles(short int quantities[14],char file_name[]){
    FILE *pFile;
    int i=0;

    pFile = fopen(file_name,"r");
    rewind(pFile);

    do{
        fscanf(pFile,"%d",&quantities[i]);
        //printf("%d ",quantities[i]);
        i++;
    }
    while(fgetc(pFile)!=EOF);


    fclose(pFile);
}
