#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> // time

void save_game( char mode, char twop_or_onep , char name_player1 [50] , char name_player2 [50] , int score1, int score2, unsigned char array_of_b [9][17] , unsigned char array_of_e [21][41] , int num_of_lines , int num_of_boxes , int turn){    
    FILE *fp [6] ;
    static int  x = 0 ;
    char filename[40] ;
    printf("Enter the name of the save game\n");
    scanf("%s",filename);
    int tries = 0;
    if(mode == '1' && twop_or_onep == '2'){
    if ((fp[x] = fopen(("%s.bin",filename), "wb")) == NULL) {
        printf("Error! opening file");
        //tries++;
        //if (tries == 10) {
          //  printf("Error! too many tries\n");
            exit(0) ;
        //}
    }
    printf("file has been opened successfully\n");
    fprintf(fp[x], "%c\n%c\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",mode,twop_or_onep, name_player1, name_player2, score1, score2 , num_of_lines , num_of_boxes , turn);
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 41; j++) {
            fprintf(fp[x], "%c ", array_of_e[i][j]);
        }
        fprintf(fp[x], "\n");
    }
    fclose(fp[x]);
    printf("game has been saved successfully\nyour file is (%s)\n", filename);
}
else if (mode == '2' && twop_or_onep == '2'){
    while ((fp[x] = fopen(("%s.bin",filename), "wb")) == NULL) {
        printf("Error! opening file");
        tries++;
        if (tries == 10) {
            printf("Error! too many tries\n");
            exit(0) ;
        }
    }
    printf("file has been opened successfully\n");
    fprintf(fp[x], "%c\n%c\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n",mode,twop_or_onep, name_player1, name_player2, score1, score2 , num_of_lines , num_of_boxes , turn);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 17; j++) {
            fprintf(fp[x], "%c ", array_of_b[i][j]);
        }
        fprintf(fp[x], "\n");
    }
}
else if (mode == '1' && twop_or_onep == '1'){
    if ((fp[x] = fopen(("%s.bin",filename), "wb")) == NULL) {
        printf("Error! opening file");
        //tries++;
        //if (tries == 10) {
          //  printf("Error! too many tries\n");
            exit(0) ;
        //}
    }
    printf("file has been opened successfully\n");
    fprintf(fp[x], "%c\n%c\n%s\n%d\n%d\n%d\n%d\n%d\n",mode,twop_or_onep, name_player1,  score1, score2 , num_of_lines , num_of_boxes , turn);
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 41; j++) {
            fprintf(fp[x], "%c ", array_of_e[i][j]);
        }
        fprintf(fp[x], "\n");
    }
    fclose(fp[x]);
    printf("game has been saved successfully\nyour file is (%s)\n", filename);
}
else if (mode == '2' && twop_or_onep == '1'){
    while ((fp[x] = fopen(("%s.bin",filename), "wb")) == NULL) {
        printf("Error! opening file");
        tries++;
        if (tries == 10) {
            printf("Error! too many tries\n");
            exit(0) ;
        }
    }
    printf("file has been opened successfully\n");
    fprintf(fp[x], "%c\n%c\n%s\n%d\n%d\n%d\n%d\n%d\n",mode,twop_or_onep, name_player1, score1, score2 , num_of_lines , num_of_boxes , turn);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 17; j++) {
            fprintf(fp[x], "%c ", array_of_b[i][j]);
        }
        fprintf(fp[x], "\n");
    }
    fclose(fp[x]);
    printf("game has been saved successfully\nyour file is (%s)\n", filename);
}
x++;
}
//************************************************************************
void load_game(char name_player1 [50] , char name_player2 [50] , int* score1, int* score2){    
    int turn ,  num_of_lines , num_of_boxes ;
    char mode , twop_or_onep ;
    unsigned char array_of_b[9][17] ;
    unsigned char array_of_e[21][41] ;

    char filename[50];
    //displaySaveGames();
    
    printf("\nEnter the name of the save game file you want to load:\n");
    scanf("%s", filename);
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        perror("Error opening file");
        return ;
    }
    else {printf("file has been opened successfully\n");}    
    int ch;
    fscanf(file, "%c\n%c\n%s\n%s\n%d\n%d\n%d\n%d\n%d" ,&mode ,&twop_or_onep, name_player1, name_player2, *score1 ,*score2 ,&num_of_lines ,&num_of_boxes,&turn);
    if (mode =='1'){
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 41; j++) {
            fscanf(file, "%1c",&array_of_e[i][j]);
        }
    }
    }
    else if (mode=='2') {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 17; j++) {
            fscanf(file, "%1c",&array_of_b[i][j]);
        }
    }
    }
    game_loop_load(mode ,twop_or_onep ,array_of_b ,array_of_e ,num_of_lines ,num_of_boxes ,turn);
    fclose(file);
    printf("game has been saved successfully\nyour file is (%s)\n", filename);
    
}


