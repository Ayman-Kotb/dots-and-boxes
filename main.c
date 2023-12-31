#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> // time
#include <dirent.h>
#include "Data.h"
#include "initialGrid.h"
#include "Grid_change.h"
#include "checks.h"
#include "save.h"
#include "Turns.h"
#include "print.h"
#include "DFS.h"
#include "leadboardfile.h"
#include "gameloop.h"
// arrays
unsigned char array_of_grid_of_beginners[9][17];
unsigned char array_of_grid_of_experts[21][41];
// total // Time;
//  code;
int main()
{
  time_t now = time(NULL); // time;
  char *string_now = ctime(&now);
  srand(time(NULL));  // for computer random;
  clock_t start, end; // Time start , end;
  char stat[10];
  char wants = '0';
  clearConsole();
  printf("\n" MAGE " Welcome to Dots and Boxes Game " RESET "\n\n");
  printf("\n" MAGE " %s" RESET "\n", string_now); // print time;
  printf("\n" MAGE "Hope to enjoy" RESET "\n");
  printf("\n" BRED "1:play a game\n2:see leadboard\n3:exit\n" RESET);
  scanf(" %c", &wants);
  printf("================================");
  while (wants != '1' && wants != '2' && wants != '3')
  {
    printf("invalid\n");
    printf("\n" BRED "1:play a game\n2:see leadboard\n3:exit\n" RESET);
    scanf(" %c", &wants);
    printf("================================");
  }
  if (wants == '2')
  {
    print_top_10_players();
    return 0;
  }
  else if (wants == '3')
  {
    exit(0);
  }
  else
  {
    // srand(time(NULL));//for computer random;
    // clock_t start, end; // Time start , end;

    data.player_one_score = 0;
    data.player_two_score = 0;
    data.computer_score = 0;
    data.number_of_remaining_boxes_b = 4;
    data.number_of_remaining_boxes_e = 25;
    data.number_of_remaining_lines_e = 60;
    data.number_of_remaining_lines_b = 12;

    // time_t now = time(NULL); // time;
    // char *string_now = ctime(&now);

    char MODE_B_E = '0';
    char against;
    // TAke names and who play against:
    clearConsole();
    // printf("\n" MAGE " Welcome to Dots and Boxes Game " RESET "\n\n");
    // printf(MAGE " %s" RESET, string_now); // print time;
    printf(BRED "1:load game\n2:play a new game\n" RESET);
    scanf(" %c", &wants);
    printf("================================");
    while (wants != '1' && wants != '2')
    {
      printf("\n");
      printf(BRED "1:load game\n2:play a new game\n" RESET);
      scanf(" %c", &wants);
      printf("================================\n");
    }
    if (wants == '1')
    {
      load_game(data.Name_Player1, data.Name_Player2, &data.player_one_score, &data.player_two_score);
    }
    else
    {
      printf("\nwhat mode U want to play\n1: Experts Mode\n2: Beginner Mode\n");

      scanf(" %c", &MODE_B_E);
      // Error when enter letters?!
      while ((MODE_B_E != '1') && (MODE_B_E != '2'))
      {
        printf("Invalid , please select the number of the mode U want from 1:2\n");
        printf("1: Experts Mode\n2: Beginner Mode\n");
        scanf(" %c", &MODE_B_E);
      }
      printf("==========================================\n");
      printf("choose who do U want to play against\n1: another Player\n2: Computer\n");
      scanf(" %c", &against);
      while ((against != '1') && (against != '2'))
      {
        printf("Invalid , please select the number who U want to play against from 1:2\n");
        printf("1: another Player\n2: Computer\n");
        scanf(" %c", &against);
      }
      printf("==========================================\n");
      // prints
      if (against == '1')
      {
        printf("whats your name, player 1\n");
        scanf("%s", &data.Name_Player1);
        printf("whats your name, player 2\n");
        scanf("%s", &data.Name_Player2);
        printf("\n%s has RED color , %s has BLUE color\n\n", data.Name_Player1, data.Name_Player2);
        printf(BLKHD "this is initial grid" RESET "\n");
        printf("====================================================\n\n");
      }
      else
      {
        printf("whats your name\n");
        scanf("%s", &data.Name_Player1);
        printf("\nU has RED color , Computer has BLUE color\n\n");
        printf(BLKHD "this is initial grid" RESET "\n");
        printf("====================================================\n\n");
      }
      // turns
      char letter_to_be_changed;
      game_loop_new(MODE_B_E, against, array_of_grid_of_beginners, array_of_grid_of_experts); // test;
    }
  }
  return 0;
}
