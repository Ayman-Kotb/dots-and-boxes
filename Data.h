#include <stdio.h>
#include <string.h>

// make structs of data here
typedef struct
{
    int player_one_score;
    int player_two_score;
    int computer_score;
    char Name_Player1[50];
    char Name_Player2[50];
    int number_of_remaining_lines_e;
    int number_of_remaining_lines_b;
    int number_of_remaining_boxes_e;
    int number_of_remaining_boxes_b;
} Data;
Data data;

void clearConsole()
{
    printf("\e[1;1H\e[2J");
}

typedef struct // to creat lead board;//still;
{
    char Name[100];
    int score;
} Player;
Player players[20];
Player player1;
Player player2;
