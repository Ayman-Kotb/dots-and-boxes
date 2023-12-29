#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// main here;
                        //Error in turns;
int *lines_to_adjacent_b = &data.number_of_remaining_lines_b;           // go to adjacent;  // was in main;
int *lines_to_adjacent_e = &data.number_of_remaining_lines_e;           // go to adjacent;  // was in main;
int *number_of_boxes_to_adjacent_e = &data.number_of_remaining_boxes_e; // go to adjacent;  //was in main;
int *number_of_boxes_to_adjacent_b = &data.number_of_remaining_boxes_b; // go to adjacent;  //was in main;
clock_t start, end;
double Total_time = 0.0; // Time;

void game_loop(char MODE_B_E, char against, unsigned char array_of_grid_of_beginners[9][17], unsigned char array_of_grid_of_experts[21][41])
{
  if (MODE_B_E == '1')
  {
    creat_initial_grid_for_experts(array_of_grid_of_experts);
    print_initial_E(array_of_grid_of_experts); // still

    if (against == '1')
    {
      print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);
      printf(BARN "Total time : 0" RESET "\n");
    }
    else
    {
      print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);
      printf(BARN "Total time : 0" RESET "\n");
    }
    int turns_p = 0;
    while (*lines_to_adjacent_e >= 0)
    {
      (*lines_to_adjacent_e)--; // error in number of loops
      if (turns_p % 2 == 0)
      {
        start = clock(); // start time
        player_one_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1);
      }
      else
      {
        start = clock(); // start time
        if (against == '1')
        {
          player_two_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player2);
        }
        else
        {
          computer_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts);
        }
      }
      if (letter_be_changed > 96)
      {
        int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 0);
        if (right_box == 4)
        {
          if (turns_p % 2 == 0)
          {
            data.player_one_score++;
          }
          else if (against == '1' && turns_p % 2 == 1)
          {
            data.player_two_score++;
          }
          else
          {
            data.computer_score++;
          }
          turns_p++;
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
            if (turns_p % 2 == 0)
            {
              data.player_one_score++;
            }
            else if (against == '1' && turns_p % 2 == 1)
            {
              data.player_two_score++;
            }
            else
            {
              data.computer_score++;
            }
            turns_p++;
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
          if (turns_p % 2 == 0)
          {
            data.player_one_score++;
          }
          else if (against == '1' && turns_p % 2 == 1)
          {
            data.player_two_score++;
          }
          else
          {
            data.computer_score++;
          }
          turns_p++;
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
            if (turns_p % 2 == 0)
            {
              data.player_one_score++;
            }
            else if (against == '1' && turns_p % 2 == 1)
            {
              data.player_two_score++;
            }
            else
            {
              data.computer_score++;
            }
            turns_p++;
            (*number_of_boxes_to_adjacent_e)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 6, col_e, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e + 8, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e - 8, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // left}
          }
        }
      }
      if (turns_p % 2 == 0)
      {
        print_after_change_experts(array_of_grid_of_experts, 1);
      }
      else if (against == '1')
      {
        print_after_change_experts(array_of_grid_of_experts, 2);
      }
      else
      {
        print_after_change_experts(array_of_grid_of_experts, 0);
      }
      //;
      if (against == '1')
      {
        print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);
      }
      else
      {
        print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);
      }
      end = clock(); // end time
      Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
      printf(BARN "Total Time : %f\n" RESET, Total_time);
      turns_p++;
    } // while;
    print_win(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, data.computer_score, against);
  } // else mode;
  else
  {
    creat_initial_grid_for_beginners(array_of_grid_of_beginners);
    print_initial_B(array_of_grid_of_beginners); // still

    if (against == '1')
    {
      print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, &data.number_of_remaining_lines_b, &data.number_of_remaining_boxes_b);
      printf(BARN "Total time : 0" RESET "\n");
    }
    else
    {
      print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, &data.number_of_remaining_lines_b, &data.number_of_remaining_boxes_b);
      printf(BARN "Total time : 0" RESET "\n");
    }
    int turns_p = 0;
    while (*lines_to_adjacent_b >= 0)
    {
      (*lines_to_adjacent_b)--; // error in number of loops
      if (turns_p % 2 == 0)
      {
        start = clock(); // start time
        player_one_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1);
      }
      else
      {
        start = clock(); // start time
        if (against == '1')
        {
          player_two_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player2);
        }
        else
        {
          computer_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts);
        }
      }
      if (letter_be_changed > 96)
      {
        int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 0);
        if (right_box == 4)
        {
          if (turns_p % 2 == 0)
          {
            data.player_one_score++;
          }
          else if (against == '1' && turns_p % 2 == 1)
          {
            data.player_two_score++;
          }
          else
          {
            data.computer_score++;
          }
          turns_p++;
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
            if (turns_p % 2 == 0)
            {
              data.player_one_score++;
            }
            else if (against == '1' && turns_p % 2 == 1)
            {
              data.player_two_score++;
            }
            else
            {
              data.computer_score++;
            }
            turns_p++;
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
          if (turns_p % 2 == 0)
          {
            data.player_one_score++;
          }
          else if (against == '1' && turns_p % 2 == 1)
          {
            data.player_two_score++;
          }
          else
          {
            data.computer_score++;
          }
          turns_p++;
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
            if (turns_p % 2 == 0)
            {
              data.player_one_score++;
            }
            else if (against == '1' && turns_p % 2 == 1)
            {
              data.player_two_score++;
            }
            else
            {
              data.computer_score++;
            }
            turns_p++;
            (*number_of_boxes_to_adjacent_b)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 6, col_b, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b);     //  upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b + 8, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b - 8, 0, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // left}
          }
        }
      }
      if (turns_p % 2 == 0)
      {
        print_after_change_beginners(array_of_grid_of_beginners, 1);
      }
      else if (against == '1' && turns_p % 2 ==1)
      {
        print_after_change_beginners(array_of_grid_of_beginners, 2);
      }
      else
      {
        print_after_change_beginners(array_of_grid_of_beginners, 0);
      }
      //;
      if (against == '1')
      {
        print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, &data.number_of_remaining_lines_b, &data.number_of_remaining_boxes_b);
      }
      else
      {
        print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, &data.number_of_remaining_lines_b, &data.number_of_remaining_boxes_b);
      }
      end = clock(); // end time
      Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
      printf(BARN "Total Time : %f\n" RESET, Total_time);
      turns_p++;
    } // while;
    print_win(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, data.computer_score, against);
  }
} // func.;