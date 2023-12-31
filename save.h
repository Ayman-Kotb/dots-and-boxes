#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> // time

void save_game(char mode, char twop_or_onep, char name_player1[50], char name_player2[50], int score1, int score2, unsigned char array_of_b[9][17], unsigned char array_of_e[21][41], int num_of_lines, int num_of_boxes, int turn)
{
    FILE *fp[20];
    static int x = 0;
    char filename[40];
    printf("Enter the name of the save game\n");
    scanf("%s", filename);
    int tries = 0;
    if (mode == '1' && twop_or_onep == '2')  //expert and 2p
    {
        if ((fp[x] = fopen(("%s.bin", filename), "wb")) == NULL)
        {
            printf("Error! opening file");
            // tries++;
            // if (tries == 10) {
            //   printf("Error! too many tries\n");
            exit(0);
            //}
        }
        printf("file has been opened successfully\n");
        fprintf(fp[x], "%c\n%c\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n", mode, twop_or_onep, name_player1, name_player2, score1, score2, num_of_lines, num_of_boxes, turn);
        for (int i = 0; i < 21; i++)
        {
            for (int j = 0; j < 41; j++)
            {
                fprintf(fp[x], "%c", array_of_e[i][j]);
            }
            // fprintf(fp[x], "\n");
        }
        fclose(fp[x]);
        printf("game has been saved successfully\nyour file is (%s)\n", filename);
    }
    else if (mode == '2' && twop_or_onep == '2') // beg and 2p
    {
        while ((fp[x] = fopen(("%s.bin", filename), "wb")) == NULL)
        {
            printf("Error! opening file");
            tries++;
            if (tries == 10)
            {
                printf("Error! too many tries\n");
                exit(0);
            }
        }
        printf("file has been opened successfully\n");
        fprintf(fp[x], "%c\n%c\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n", mode, twop_or_onep, name_player1, name_player2, score1, score2, num_of_lines, num_of_boxes, turn);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 17; j++)
            {
                fprintf(fp[x], "%c", array_of_b[i][j]);
            }
            // fprintf(fp[x], "\n");
        }
        fclose(fp[x]);
        printf("game has been saved successfully\nyour file is (%s)\n", filename);
    }
    else if (mode == '1' && twop_or_onep == '1') //expert and 1p
    {
        name_player2= "no thing" ;
        if ((fp[x] = fopen(("%s.bin", filename), "wb")) == NULL)
        {
            printf("Error! opening file");
            // tries++;
            // if (tries == 10) {
            //   printf("Error! too many tries\n");
            exit(0);
            //}
        }
        printf("file has been opened successfully\n");
        fprintf(fp[x], "%c\n%c\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n", mode, twop_or_onep, name_player1, name_player2, score1, score2, num_of_lines, num_of_boxes, turn);
        for (int i = 0; i < 21; i++)
        {
            for (int j = 0; j < 41; j++)
            {
                fprintf(fp[x], "%c", array_of_e[i][j]);
            }
            // fprintf(fp[x], "\n");
        }
        fclose(fp[x]);
        printf("game has been saved successfully\nyour file is (%s)\n", filename);
    }
    else if (mode == '2' && twop_or_onep == '1') //beginner and 1p
    {
        name_player2= "no thing" ;
        while ((fp[x] = fopen(("%s.bin", filename), "wb")) == NULL)
        {
            printf("Error! opening file");
            tries++;
            if (tries == 10)
            {
                printf("Error! too many tries\n");
                exit(0);
            }
        }
        printf("file has been opened successfully\n");
        fprintf(fp[x], "%c\n%c\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n", mode, twop_or_onep, name_player1, name_player2, score1, score2, num_of_lines, num_of_boxes, turn);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 17; j++)
            {
                fprintf(fp[x], "%c", array_of_b[i][j]);
            }
            // fprintf(fp[x], "\n");
        }
        fclose(fp[x]);
        printf("game has been saved successfully\nyour file is (%s)\n", filename);
    }
    x++;
    int k ;
    printf("\n1:play again\n2:exit\n");
      scanf("%d",&k);
      while ((k!= 1)&&(k!=2))
      {
        printf("invalid , try again");
        scanf("%d",&k);
      }
      if (k==1)
      {
        main();
      }
      else if (k==2)
      {
        exit(0);
      }   
}
//************************************************************************
void load_game(char name_player1[50], char name_player2[50], int *score1, int *score2)
{
    int turn, num_of_lines, num_of_boxes;
    char mode, twop_or_onep;
    unsigned char array_of_b[9][17];
    unsigned char array_of_e[21][41];

    char filename[50];
    // displaySaveGames();

    printf("\nEnter the name of the save game file you want to load:\nEnter 1 to back");
    scanf("%s", filename);
    if (filename[0] =='1') return ;
    FILE *file = fopen(filename, "rb");
    int k=1 ;
    while (k)
    {if (file == NULL)
    {
        perror("Error opening file");
        //return;
        printf("\nEnter the name of the save game file you want to load:\n");
        scanf("%s", filename);
        file = fopen(filename, "rb");
        k++;
        if (k==5)  return;   
    }
    else
    {
        printf("file has been opened successfully\n");
        break;
    }}
    int ch;
    fscanf(file, "%c\n%c\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n", &mode, &twop_or_onep, name_player1, name_player2, &*score1, &*score2, &num_of_lines, &num_of_boxes, &turn);
    if (mode == '1')
    {
        for (int i = 0; i < 21; i++)
        {
            for (int j = 0; j < 41; j++)
            {
                fscanf(file, "%1c", &array_of_e[i][j]);
            }
        }
    }
    else if (mode == '2')
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 17; j++)
            {
                fscanf(file, "%1c", &array_of_b[i][j]);
            }
        }
    }
    fclose(file);
    printf("game has been loaded successfully\n");
    game_loop_load(mode, twop_or_onep, array_of_b, array_of_e, num_of_lines, num_of_boxes, turn, score1, score2, name_player1, name_player2);
    
}
