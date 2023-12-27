#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> // time
#include "initialGrid.h"
#include "Grid_change.h"
#include "checks.h"
#include "Turns.h"
#include "Data.h"
#include "print.h"
#include "gameloop.h"
#include "DFS.h"
// arrays
unsigned char array_of_grid_of_beginners[9][17];
unsigned char array_of_grid_of_experts[21][41];
double Total_time = 0.0; // Time;
// code
int main()
{
  srand(time(NULL)); 
  clock_t start, end; // Time start , end;
  data.player_one_score = 0;
  data.player_two_score = 0;
  data.computer_score = 0;
  data.number_of_remaining_boxes_b = 4;
  data.number_of_remaining_boxes_e = 25;
  data.number_of_remaining_lines_e = 60;
  data.number_of_remaining_lines_b = 12;
  int *lines_to_adjacent_b = &data.number_of_remaining_lines_b;           // go to adjacent;
  int *lines_to_adjacent_e = &data.number_of_remaining_lines_e;           // go to adjacent;
  int *number_of_boxes_to_adjacent_e = &data.number_of_remaining_boxes_e; // go to adjacent;
  int *number_of_boxes_to_adjacent_b = &data.number_of_remaining_boxes_b; // go to adjacent;

  time_t now = time(NULL); // time;
  char *string_now = ctime(&now);

  int MODE_B_E = 0;
  int against;
  // TAke names and who play against:
  printf("\n" MAGE "Welcome to Dots and Boxes Game!" RESET "\n\n");
  printf(MAGE "%s" RESET, string_now); // print time;
  printf("\nwhat mode U want to play\n1: Experts Mode\n2: Beginner Mode\n");

  scanf(" %d", &MODE_B_E);
  // Error when enter letters?!
  while ((MODE_B_E != 1) && (MODE_B_E != 2))
  {
    printf("Invalid , please select the number of the mode U want from 1:2\n");
    printf("1: Experts Mode\n2: Beginner Mode\n");
    scanf(" %d", &MODE_B_E);
  }

  printf("==========================================\n");
  printf("choose who do U want to play against\n1: another Player\n2: Computer\n");
  scanf("%d", &against);
  while ((against != 1) && (against != 2))
  {
    printf("Invalid , please select the number who U want to play against from 1:2\n");
    printf("1: another Player\n2: Computer\n");
    scanf("%d", &against);
  }
  printf("==========================================\n");
  // prints
  if (against == 1)
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
  if (MODE_B_E == 1 && against == 1) // two players in the experts mode
  {
    creat_initial_grid_for_experts(array_of_grid_of_experts);
    print_initial_E(array_of_grid_of_experts); // still
    print_remaining_and_scores_E(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);
    printf(BARN "Total time : 0" RESET "\n");
    for (int i = 0; i < 84; i++)
    {
      if (*lines_to_adjacent_e < 0)
        break;
      // error in number of loops
      (*lines_to_adjacent_e)--; // error in number of loops
      if (i % 2 == 0 && (*lines_to_adjacent_e) >= 0)
      {
        start = clock(); // start time

        player_one_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 1);
          if (right_box == 4)
          {
            data.player_one_score++;
            i++;
            (*number_of_boxes_to_adjacent_e)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 4, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     // check left
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 12, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);    // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 4, col_e + 4, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 4, col_e + 4, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // lower
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 4, 1);
            if (left_box == 4)
            {
              data.player_one_score++;
              i++;
              (*number_of_boxes_to_adjacent_e)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 12, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 4, col_e - 4, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 4, col_e - 4, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 1);
          if (lower_box == 4)
          {
            data.player_one_score++;
            i++;
            (*number_of_boxes_to_adjacent_e)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 6, col_e, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e + 8, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e - 8, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e, 1);
            if (upper_box == 4)
            {
              data.player_one_score++;
              i++;
              (*number_of_boxes_to_adjacent_e)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 6, col_e, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e + 8, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e - 8, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // left
            }
          }
        }
          print_after_change_experts(array_of_grid_of_experts, 1);
          print_remaining_and_scores_E(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);

          end = clock(); // end time
          Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
          printf(BARN "Total Time : %f\n" RESET, Total_time);
        }
      
  
      else if (i % 2 == 1 && data.number_of_remaining_boxes_e >= 0)
      {
        start = clock(); // start clock

        player_two_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player2);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 2);
          if (right_box == 4)
          {
            data.player_two_score++;
            i++;
            (*number_of_boxes_to_adjacent_e)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 4, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 12, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 4, col_e + 4, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 4, col_e + 4, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 4, 2);
            if (left_box == 4)
            {
              data.player_two_score++;
              i++;
              (*number_of_boxes_to_adjacent_e)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 12, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 4, col_e - 4, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 4, col_e - 4, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 2);
          if (lower_box == 4)
          {
            data.player_two_score++;
            i++;
            (*number_of_boxes_to_adjacent_e)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 6, col_e, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e + 8, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e - 8, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e, 2);
            if (upper_box == 4)
            {
              data.player_two_score++;
              i++;
              (*number_of_boxes_to_adjacent_e)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 6, col_e, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e + 8, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e - 8, 2, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // left}
            }
          }
        }
          print_after_change_experts(array_of_grid_of_experts, 2);
          print_remaining_and_scores_E(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);

          end = clock(); // end time
          Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
          printf(BARN "Total Time : %f\n" RESET, Total_time);
        }
      
    }
  }
  else if (MODE_B_E == 1 && against == 2) // one player vs computer in the experts mode
  {
    creat_initial_grid_for_experts(array_of_grid_of_experts);
    print_initial_E(array_of_grid_of_experts); // still
    print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);
    printf(BARN "Total time : 0" RESET "\n");
    for (int i = 0; i < 84; i++)
    {
      if (((*lines_to_adjacent_e) < 0) ||((*number_of_boxes_to_adjacent_e)<0)) break;
      // error in number of loops
      (*lines_to_adjacent_e)--; // error in number of loops
      if (i % 2 == 0 && (*lines_to_adjacent_e) >= 0)
      {
        start = clock(); // start time

        player_one_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 1);
          if (right_box == 4)
          {
            data.player_one_score++;
            i++;
            (*number_of_boxes_to_adjacent_e)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 4, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     // check left
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 12, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);    // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 4, col_e + 4, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 4, col_e + 4, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // lower
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 4, 1);
            if (left_box == 4)
            {
              data.player_one_score++;
              i++;
              (*number_of_boxes_to_adjacent_e)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 12, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 4, col_e - 4, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 4, col_e - 4, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 1);
          if (lower_box == 4)
          {
            data.player_one_score++;
            i++;
            (*number_of_boxes_to_adjacent_e)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 6, col_e, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e + 8, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e - 8, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e, 1);
            if (upper_box == 4)
            {
              data.player_one_score++;
              i++;
              (*number_of_boxes_to_adjacent_e)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 6, col_e, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e + 8, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e - 8, 1, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // left
            }
          }
        }
          print_after_change_experts(array_of_grid_of_experts, 1);
          print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);

          end = clock(); // end time
          Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
          printf(BARN "Total Time : %f\n" RESET, Total_time);
        }
      
  
      else if (i % 2 == 1 && data.number_of_remaining_boxes_e >= 0)
      {
        start = clock(); // start clock

        computer_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 0);
          if (right_box == 4)
          {
            data.computer_score++;
            i++;
            (*number_of_boxes_to_adjacent_e)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 4, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 12, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 4, col_e + 4, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 4, col_e + 4, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 4, 0);
            if (left_box == 4)
            {
              data.computer_score++;
              i++;
              (*number_of_boxes_to_adjacent_e)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 12, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 4, col_e - 4, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 4, col_e - 4, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 0);
          if (lower_box == 4)
          {
            data.computer_score++;
            i++;
            (*number_of_boxes_to_adjacent_e)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 6, col_e, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e + 8, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e - 8, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e, 0);
            if (upper_box == 4)
            {
              data.computer_score++;
              i++;
              (*number_of_boxes_to_adjacent_e)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 6, col_e, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e + 8, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e - 8, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // left}
            }
          }
        }
          print_after_change_experts(array_of_grid_of_experts, 0);
          print_remaining_and_scores_computer(data.Name_Player1,data.player_one_score, data.computer_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);

          end = clock(); // end time
          Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
          printf(BARN "Total Time : %f\n" RESET, Total_time);
        }
      
    }
  }
  else if (MODE_B_E == 2 && against == 1) // two player in the beginner mode
  {
    creat_initial_grid_for_beginners(array_of_grid_of_beginners);
    print_initial_B(array_of_grid_of_beginners);
    print_remaining_and_scores_B(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // still
    printf(BARN "Total time : 0" RESET "\n");
    for (int i = 0; i < 15; i++) // error in number of loops
    {
      if (*lines_to_adjacent_b < 0)
        break;
      (*lines_to_adjacent_b)--; // fix number of loops
      if (i % 2 == 0 && (*lines_to_adjacent_b) >= 0)
      {
        start = clock();
        player_one_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 1);
          if (right_box == 4)
          {
            data.player_one_score++;
            i++;
            (*number_of_boxes_to_adjacent_b)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     // check left
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 12, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);    // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b + 4, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b + 4, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // lower
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 1);
            if (left_box == 4)
            {
              data.player_one_score++;
              i++;
              (*number_of_boxes_to_adjacent_b)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 12, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b - 4, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b - 4, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 1);
          if (lower_box == 4)
          {
            data.player_one_score++;
            i++;
            (*number_of_boxes_to_adjacent_b)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 6, col_b, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b + 8, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b - 8, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 1);
            if (upper_box == 4)
            {
              data.player_one_score++;
              i++;
              (*number_of_boxes_to_adjacent_b)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 6, col_b, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b + 8, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b - 8, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // left
            }
          }
        }
        print_after_change_beginners(array_of_grid_of_beginners, 1);
        print_remaining_and_scores_B(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // still

        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
      else if (i % 2 == 1 && (*lines_to_adjacent_b) >= 0)
      {
        start = clock();
        player_two_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player2);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 2);
          if (right_box == 4)
          {
            data.player_two_score++;
            i++;
            (*number_of_boxes_to_adjacent_b)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 12, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b + 4, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b + 4, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 2);
            if (left_box == 4)
            {
              data.player_two_score++;
              i++;
              (*number_of_boxes_to_adjacent_b)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 12, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b - 4, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b - 4, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 2);
          if (lower_box == 4)
          {
            data.player_two_score++;
            i++;
            (*number_of_boxes_to_adjacent_b)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 6, col_b, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b + 8, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b - 8, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 2);
            if (upper_box == 4)
            {
              data.player_two_score++;
              i++;
              (*number_of_boxes_to_adjacent_b)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 6, col_b, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b + 8, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b - 8, 2, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // left}
            }
          }
          // if(lower_box==4&&upper_box==4){i--;}
        }
        print_after_change_beginners(array_of_grid_of_beginners, 2);
        print_remaining_and_scores_B(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // still

        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
    }
  }
  else // one player vs computer in the beginners mode
  {
    creat_initial_grid_for_beginners(array_of_grid_of_beginners);
    print_initial_B(array_of_grid_of_beginners);
    print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // still
    printf(BARN "Total time : 0" RESET "\n");
    for (int i = 0; i < 15; i++) // error in number of loops
    {
      if (*lines_to_adjacent_b < 0)
        break;
      (*lines_to_adjacent_b)--; // fix number of loops
      if (i % 2 == 0 && (*lines_to_adjacent_b) >= 0)
      {
        start = clock();
        player_one_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 1);
          if (right_box == 4)
          {
            data.player_one_score++;
            i++;
            (*number_of_boxes_to_adjacent_b)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     // check left
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 12, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);    // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b + 4, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b + 4, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // lower
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 1);
            if (left_box == 4)
            {
              data.player_one_score++;
              i++;
              (*number_of_boxes_to_adjacent_b)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 12, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b - 4, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b - 4, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 1);
          if (lower_box == 4)
          {
            data.player_one_score++;
            i++;
            (*number_of_boxes_to_adjacent_b)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 6, col_b, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b + 8, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b - 8, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 1);
            if (upper_box == 4)
            {
              data.player_one_score++;
              i++;
              (*number_of_boxes_to_adjacent_b)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 6, col_b, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b + 8, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b - 8, 1, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // left
            }
          }
        }
        print_after_change_beginners(array_of_grid_of_beginners, 1);
        print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // still
        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
      else if (i % 2 == 1 && (*lines_to_adjacent_b) >= 0)
      {
        start = clock();
        computer_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 0);
          if (right_box == 4)
          {
            data.computer_score++;
            i++;
            (*number_of_boxes_to_adjacent_b)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 12, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b + 4, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b + 4, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 0);
            if (left_box == 4)
            {
              data.computer_score++;
              i++;
              (*number_of_boxes_to_adjacent_b)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 12, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b - 4, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b - 4, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 0);
          if (lower_box == 4)
          {
            data.computer_score++;
            i++;
            (*number_of_boxes_to_adjacent_b)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 6, col_b, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b + 8, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b - 8, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 0);
            if (upper_box == 4)
            {
              data.computer_score++;
              i++;
              (*number_of_boxes_to_adjacent_b)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 6, col_b, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b + 8, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b - 8, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // left}
            }
          }
        }
        print_after_change_beginners(array_of_grid_of_beginners, 0);
        print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // still
        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
    }
}
  // be changed
  return 0;
}
