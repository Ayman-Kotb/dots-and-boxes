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

void game_loop_load( char MODE_B_E , char against ,unsigned char array_of_grid_of_beginners[9][17] , unsigned char array_of_grid_of_experts[21][41], int linez , int boxez , int turn){
  int* ln = &linez ;
  int* bx = &boxez ;
  if (MODE_B_E == '1' && against == '1') // two players in the experts mode
  {
    printf(BARN "Total time : 0" RESET "\n");
  for (turn; turn < 84; turn++)
    {
      if (*ln < 1)
        break;
      // error in number of loops
      //save_game_2p(MODE_B_E,data.Name_Player1, data.Name_Player2, data.player_one_score , data.player_two_score ,array_of_grid_of_beginners , array_of_grid_of_experts , data.number_of_remaining_lines_e , data.number_of_remaining_boxes_e , i) ;
      (*ln)--; // error in number of loops
      if (i % 2 == 0 && (*ln) > 0)
      {
        start = clock(); // start time

        player_one_turn(MODE_B_E, '2',array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1 , turn);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 1);
          if (right_box == 4)
          {
            data.player_one_score++;
            turn++;;
            (*bx)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 4, 1, ln, bx);     // check left
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 12, 1,ln, bx);    // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 4, col_e + 4, 1, ln, bx); // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 4, col_e + 4, 1, ln, bx); // lower
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 4, 1);
            if (left_box == 4)
            {
              data.player_one_score++;
              turn++;;
              (*bx)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 1, ln, bx);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 12, 1, ln, bx);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 4, col_e - 4, 1, ln, bx); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 4, col_e - 4, 1, ln, bx); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 1);
          if (lower_box == 4)
          {
            data.player_one_score++;
            turn++;;
            (*bx)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 6, col_e, 1, ln, bx);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e, 1, ln, bx);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e + 8, 1, ln, bx); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e - 8, 1, ln, bx); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e, 1);
            if (upper_box == 4)
            {
              data.player_one_score++;
              turn++;;
              (*bx)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 1, ln, bx);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 6, col_e, 1, ln, bx);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e + 8, 1, ln, bx); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e - 8, 1, ln, bx); // left
            }
          }
        }
        print_after_change_experts(array_of_grid_of_experts, 1);
        print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, ln, bx);

        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
      else if (turn % 2 == 1 && (*ln) >= 0)
      {
        start = clock(); // start clock

        player_two_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player2 ,turn);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 2);
          if (right_box == 4)
          {
            data.player_two_score++;
            turn++;;
            (*bx)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 4, 2, ln, bx);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 12, 2, ln, bx);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 4, col_e + 4, 2, ln, bx);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 4, col_e + 4, 2, ln, bx);
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 4, 2);
            if (left_box == 4)
            {
              data.player_two_score++;
              turn++;;
              (*bx)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 2, ln, bx);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e - 12, 2, ln, bx);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 4, col_e - 4, 2, ln, bx); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 4, col_e - 4, 2, ln, bx); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 2);
          if (lower_box == 4)
          {
            data.player_two_score++;
            turn++;;
            (*bx)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 6, col_e, 2, ln, bx);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e, 2, ln, bx);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e + 8, 2, ln, bx); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e - 8, 2, ln, bx); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e, 2);
            if (upper_box == 4)
            {
              data.player_two_score++;
              turn++;;
              (*bx)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 2,ln, bx);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 6, col_e, 2,ln, bx);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e + 8, 2, ln, bx); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e - 8, 2, ln, bx); // left}
            }
          }
        }
        print_after_change_experts(array_of_grid_of_experts, 2);
        print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, ln, bx);

        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
    }
    print_win(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, data.computer_score, against);
  }
  else if (MODE_B_E =='1' && against == '2') // one player vs computer in the experts mode
  {
    printf(BARN "Total time : 0" RESET "\n");
    for (int turn = 0; turn < 84; i++)
    {
      if (((*ln) < 0) || ((*bx) < 0))
        break;
      // error in number of loops
      (ln)--; // error in number of loops
      if (i % 2 == 0 && (ln) >= 0)
      {
        start = clock(); // start time

        player_one_turn(MODE_B_E,'1', array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1,i);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 1);
          if (right_box == 4)
          {
            data.player_one_score++;
            turn++;
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
              turn++;
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
            turn++;
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
              turn++;
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
      else if (i % 2 == 1 && (*lines_to_adjacent_e) >= 0)
      {
        start = clock(); // start clock

        computer_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e, col_e + 4, 0);
          if (right_box == 4)
          {
            data.computer_score++;
            turn++;
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
              turn++;
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
            turn++;
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
              turn++;
              (*number_of_boxes_to_adjacent_e)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e + 2, col_e, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 6, col_e, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e + 8, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_e - 2, col_e - 8, 0, lines_to_adjacent_e, number_of_boxes_to_adjacent_e); // left}
            }
          }
        }
        print_after_change_experts(array_of_grid_of_experts, 0);
        print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);

        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
    }
    print_win(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, data.computer_score, against);
  }
  else if (MODE_B_E == '2' && against == '1') // two player in the beginner mode
  {
    creat_initial_grid_for_beginners(array_of_grid_of_beginners);
    print_initial_B(array_of_grid_of_beginners);
    print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, ln , bx); // still
    printf(BARN "Total time : 0" RESET "\n");
    for (int i = 0; i < 15; i++) // error in number of loops
    {
      if (*ln < 0)
        break;
      (*ln)--; // fix number of loops
      if (i % 2 == 0 && (*ln) >= 0)
      {
        start = clock();
        player_one_turn(MODE_B_E, '2',array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1,i);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 1);
          if (right_box == 4)
          {
            data.player_one_score++;
            turn++;
            (*bx)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 1, ln , bx);     // check left
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 12, 1, ln , bx);    // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b + 4, 1, ln , bx); // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b + 4, 1, ln , bx); // lower
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 1);
            if (left_box == 4)
            {
              data.player_one_score++;
              turn++;
              (*bx)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 1, ln , bx);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 12, 1, ln , bx);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b - 4, 1, ln , bx); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b - 4, 1, ln , bx); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 1);
          if (lower_box == 4)
          {
            data.player_one_score++;
            turn++;
            (*bx)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 6, col_b, 1, ln , bx);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 1, ln , bx);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b + 8, 1, ln , bx); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b - 8, 1, ln , bx); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 1);
            if (upper_box == 4)
            {
              data.player_one_score++;
              turn++;
              (*bx)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 1, ln , bx);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 6, col_b, 1, ln , bx);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b + 8, 1, ln , bx); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b - 8, 1, ln , bx); // left
            }
          }
        }
        print_after_change_beginners(array_of_grid_of_beginners, 1);
        print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, ln , bx); // still

        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
      else if (i % 2 == 1 && (*ln) >= 0)
      {
        start = clock();
        player_two_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player2,i);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 2);
          if (right_box == 4)
          {
            data.player_two_score++;
            turn++;
            (*bx)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 2, ln , bx);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 12, 2, ln , bx);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b + 4, 2, ln , bx);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b + 4, 2, ln , bx);
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 2);
            if (left_box == 4)
            {
              data.player_two_score++;
              turn++;
              (*bx)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 2, ln , bx);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 12, 2, ln , bx);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b - 4, 2, ln , bx); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b - 4, 2, ln , bx); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 2);
          if (lower_box == 4)
          {
            data.player_two_score++;
            turn++;
            (*bx)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 6, col_b, 2, ln , bx);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 2, ln , bx);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b + 8, 2, ln , bx); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b - 8, 2, ln , bx); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 2);
            if (upper_box == 4)
            {
              data.player_two_score++;
              turn++;
              (*bx)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 2, ln , bx);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 6, col_b, 2, ln , bx);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b + 8, 2, ln , bx); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b - 8, 2, ln , bx); // left}
            }
          }
          // if(lower_box==4&&upper_box==4){i--;}
        }
        print_after_change_beginners(array_of_grid_of_beginners, 2);
        print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, ln , bx); // still

        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
    }
    print_win(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, data.computer_score, against);
  }
  else // one player vs computer in the beginners mode
  {
    creat_initial_grid_for_beginners(array_of_grid_of_beginners);
    print_initial_B(array_of_grid_of_beginners);
    print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, ln , bx); // still
    printf(BARN "Total time : 0" RESET "\n");
    for (int i = 0; i < 15; i++) // error in number of loops
    {
      if (*ln < 0)
        break;
      (*ln)--; // fix number of loops
      if (i % 2 == 0 && (*ln) >= 0)
      {
        start = clock();
        player_one_turn(MODE_B_E,'1', array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1,i);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 1);
          if (right_box == 4)
          {
            data.player_one_score++;
            turn++;
            (*bx)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 1, ln , bx);     // check left
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 12, 1, ln , bx);    // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b + 4, 1, ln , bx); // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b + 4, 1, ln , bx); // lower
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 1);
            if (left_box == 4)
            {
              data.player_one_score++;
              turn++;
              (*bx)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 1, ln , bx);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 12, 1, ln , bx);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b - 4, 1, ln , bx); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b - 4, 1, ln , bx); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 1);
          if (lower_box == 4)
          {
            data.player_one_score++;
            turn++;
            (*bx)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 6, col_b, 1, ln , bx);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 1, ln , bx);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b + 8, 1, ln , bx); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b - 8, 1, ln , bx); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 1);
            if (upper_box == 4)
            {
              data.player_one_score++;
              turn++;
              (*bx)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 1, ln , bx);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 6, col_b, 1, ln , bx);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b + 8, 1, ln , bx); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b - 8, 1, ln , bx); // left
            }
          }
        }
        print_after_change_beginners(array_of_grid_of_beginners, 1);
        print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, ln , bx); // still
        end = clock();                                                                                                                                          // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
      else if (i % 2 == 1 && (*ln) >= 0)
      {
        start = clock();
        computer_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts);
        if (letter_be_changed > 96)
        {
          int right_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 0);
          if (right_box == 4)
          {
            data.computer_score++;
            turn++;
            (*bx)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 0, ln , bx);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 12, 0, ln , bx);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b + 4, 0, ln , bx);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b + 4, 0, ln , bx);
          }
          else
          {
            int left_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 4, 0);
            if (left_box == 4)
            {
              data.computer_score++;
              turn++;
              (*bx)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b + 4, 0, ln , bx);     // check right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b, col_b - 12, 0, ln , bx);    // left
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 4, col_b - 4, 0, ln , bx); // upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 4, col_b - 4, 0, ln , bx); // lower
            }
          }
        }
        else
        {
          int lower_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 0);
          if (lower_box == 4)
          {
            data.computer_score++;
            turn++;
            (*bx)--;
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 6, col_b, 0, ln , bx);     //  check lower
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 0, ln , bx);     // upper
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b + 8, 0, ln , bx); // right
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b - 8, 0, ln , bx); // left
          }
          else
          {
            int upper_box = check_boxes(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b, 0);
            if (upper_box == 4)
            {
              data.computer_score++;
              turn++;
              (*bx)--;
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b + 2, col_b, 0, ln , bx);     //  lower
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 6, col_b, 0, ln , bx);     //  upper
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b + 8, 0, ln , bx); // right
              check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_b - 2, col_b - 8, 0, ln , bx); // left}
            }
          }
        }
        print_after_change_beginners(array_of_grid_of_beginners, 0);
        print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, ln , bx); // still
        end = clock();                                                                                                                                          // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
    }
    print_win(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, data.computer_score, against);
  }
  put_in_file(against,data.Name_Player1,data.Name_Player2,data.player_one_score,data.player_two_score,data.computer_score);
  // be changed
 // func.;
  
}
void game_loop_new(char MODE_B_E, char against, unsigned char array_of_grid_of_beginners[9][17], unsigned char array_of_grid_of_experts[21][41] )
{
  if (MODE_B_E == '1' && against == '1') // two players in the experts mode
  {
    creat_initial_grid_for_experts(array_of_grid_of_experts);
    print_initial_E(array_of_grid_of_experts); // still
    print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);
    printf(BARN "Total time : 0" RESET "\n");
    for (int i = 0; i < 84; i++)
    {
      if (*lines_to_adjacent_e < 1)
        break;
      // error in number of loops
      //save_game_2p(MODE_B_E,data.Name_Player1, data.Name_Player2, data.player_one_score , data.player_two_score ,array_of_grid_of_beginners , array_of_grid_of_experts , data.number_of_remaining_lines_e , data.number_of_remaining_boxes_e , i) ;
      (*lines_to_adjacent_e)--; // error in number of loops
      if (i % 2 == 0 && (*lines_to_adjacent_e) >= 0)
      {
        start = clock(); // start time

        player_one_turn(MODE_B_E, '2',array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1 , i);
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
        print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);

        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
      else if (i % 2 == 1 && (*lines_to_adjacent_e) >= 0)
      {
        start = clock(); // start clock

        player_two_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player2 ,i);
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
        print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);

        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
    }
    print_win(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, data.computer_score, against);
  }
  else if (MODE_B_E =='1' && against == '2') // one player vs computer in the experts mode
  {
    creat_initial_grid_for_experts(array_of_grid_of_experts);
    print_initial_E(array_of_grid_of_experts); // still
    print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);
    printf(BARN "Total time : 0" RESET "\n");
    for (int i = 0; i < 84; i++)
    {
      if (((*lines_to_adjacent_e) < 0) || ((*number_of_boxes_to_adjacent_e) < 0))
        break;
      // error in number of loops
      (*lines_to_adjacent_e)--; // error in number of loops
      if (i % 2 == 0 && (*lines_to_adjacent_e) >= 0)
      {
        start = clock(); // start time

        player_one_turn(MODE_B_E,'1', array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1,i);
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
      else if (i % 2 == 1 && (*lines_to_adjacent_e) >= 0)
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
        print_remaining_and_scores_computer(data.Name_Player1, data.player_one_score, data.computer_score, &data.number_of_remaining_lines_e, &data.number_of_remaining_boxes_e);

        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
    }
    print_win(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, data.computer_score, against);
  }
  else if (MODE_B_E == '2' && against == '1') // two player in the beginner mode
  {
    creat_initial_grid_for_beginners(array_of_grid_of_beginners);
    print_initial_B(array_of_grid_of_beginners);
    print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // still
    printf(BARN "Total time : 0" RESET "\n");
    for (int i = 0; i < 15; i++) // error in number of loops
    {
      if (*lines_to_adjacent_b < 0)
        break;
      (*lines_to_adjacent_b)--; // fix number of loops
      if (i % 2 == 0 && (*lines_to_adjacent_b) >= 0)
      {
        start = clock();
        player_one_turn(MODE_B_E, '2',array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1,i);
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
        print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // still

        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
      else if (i % 2 == 1 && (*lines_to_adjacent_b) >= 0)
      {
        start = clock();
        player_two_turn(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player2,i);
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
        print_remaining_and_scores(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, lines_to_adjacent_b, number_of_boxes_to_adjacent_b); // still

        end = clock(); // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
    }
    print_win(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, data.computer_score, against);
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
        player_one_turn(MODE_B_E,'1', array_of_grid_of_beginners, array_of_grid_of_experts, data.Name_Player1,i);
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
        end = clock();                                                                                                                                          // end time
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
        end = clock();                                                                                                                                          // end time
        Total_time = Total_time + ((double)(end - start) / CLOCKS_PER_SEC);
        printf(BARN "Total Time : %f\n" RESET, Total_time);
      }
    }
    print_win(data.Name_Player1, data.Name_Player2, data.player_one_score, data.player_two_score, data.computer_score, against);
  }
  put_in_file(against,data.Name_Player1,data.Name_Player2,data.player_one_score,data.player_two_score,data.computer_score);
  // be changed
} // func.;