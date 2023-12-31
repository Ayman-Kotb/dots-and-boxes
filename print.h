#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// beginners initial
void print_initial_B(unsigned char array_of_grid_of_beginners[9][17])
{
  clearConsole(); //
  for (int row = 0; row < 9; row++)
  {
    for (int column = 0; column < 17; column++)
    {
      if (array_of_grid_of_beginners[row][column] == '+' || array_of_grid_of_beginners[row][column] == '|' || array_of_grid_of_beginners[row][column] == '-')
      {
        printf(WHITE "%c" RESET, array_of_grid_of_beginners[row][column]);
      }
      else if(array_of_grid_of_beginners[row][column] == '0'||array_of_grid_of_beginners[row][column] == '2')
      {
          printf(BIBLE "%c" RESET, array_of_grid_of_beginners[row][column]);
      }
      else if(array_of_grid_of_beginners[row][column] == '1')
      {
          printf(BRED "%c" RESET, array_of_grid_of_beginners[row][column]);
      }
      else
      {
        printf((YELLOW "%c" RESET), array_of_grid_of_beginners[row][column]);
      }
    }
    printf("\n");
  }
}
// experts initial
void print_initial_E(unsigned char array_of_grid_of_experts[21][41])
{
  clearConsole();
  for (int row = 0; row < 21; row++)
  {
    for (int column = 0; column < 41; column++)
    {
      if (array_of_grid_of_experts[row][column] == '+' || array_of_grid_of_experts[row][column] == '-' || (array_of_grid_of_experts[row][column] == '|' && (row != 18 || column != 24)))
      {
        printf(WHITE "%c" RESET, array_of_grid_of_experts[row][column]);
      }
      else if(array_of_grid_of_experts[row][column] == '0' || array_of_grid_of_experts[row][column] == '2' )
      {
          printf(BIBLE "%c" RESET, array_of_grid_of_experts[row][column]);
      }
      else if(array_of_grid_of_experts[row][column] == '1')
      {
          printf(BRED "%c" RESET, array_of_grid_of_experts[row][column]);
      }
      else
      {
        if((row == 18 && column == 24)&&array_of_grid_of_experts[17][24]=='|')//!new
          {
              printf((WHITE "%c" RESET), array_of_grid_of_experts[row][column]);//!new
          }
          else//!new
          {
              printf((YELLOW "%c" RESET), array_of_grid_of_experts[row][column]);
          }
      }
    }
    printf("\n");
  }
}
// beginners after change
void print_after_change_beginners(unsigned char array_of_grid_of_beginners[9][17], int turn_color_b)
{
  clearConsole();
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 17; j++)
    {
      if (array_of_grid_of_beginners[i][j] == '+')
      {
        printf(WHITE "%c" RESET, array_of_grid_of_beginners[i][j]);
      }
      else if (array_of_grid_of_beginners[i][j] == '2' || array_of_grid_of_beginners[i][j] == '0')
      {
        printf(BIBLE "%c" RESET, array_of_grid_of_beginners[i][j]);
      }
      else if (array_of_grid_of_beginners[i][j] == '1')
      {
        printf(BRED "%c" RESET, array_of_grid_of_beginners[i][j]);
      }
      else if ((i == row_to_print && j == column_to_print) && (turn_color_b == 1))
      {
        printf(BRED "%c" RESET, array_of_grid_of_beginners[i][j]);
        if (array_of_grid_of_beginners[i][j] == '|')
          row_to_print++;
        else if (array_of_grid_of_beginners[i][j] == '-')
          column_to_print++;
      }
      else if ((i == row_to_print && j == column_to_print) && (turn_color_b == 2 || turn_color_b == 0))
      {
        printf(BIBLE "%c" RESET, array_of_grid_of_beginners[i][j]);
        if (array_of_grid_of_beginners[i][j] == '|')
          row_to_print++;
        else if (array_of_grid_of_beginners[i][j] == '-')
          column_to_print++;
      }
      else
      {
        if (array_of_grid_of_beginners[i][j] == '-' || array_of_grid_of_beginners[i][j] == '|')
        {
          printf((WHITE "%c" RESET), array_of_grid_of_beginners[i][j]);
        }
        else
        {
          printf((YELLOW "%c" RESET), array_of_grid_of_beginners[i][j]);
        }
      }
    }
    printf("\n");
  }
}
// experts after change
void print_after_change_experts(unsigned char array_of_grid_of_experts[21][41], int turn_color_e)
{
  clearConsole();
  for (int i = 0; i < 21; i++)
  {
    for (int j = 0; j < 41; j++)
    {
      if ((i == 18 && j == 24) && (array_of_grid_of_experts[i - 1][j] != '|'))
      {
        printf((YELLOW "%c" RESET), array_of_grid_of_experts[i][j]);
      }
      else if (array_of_grid_of_experts[i][j] == '+')
      {
        printf(WHITE "%c" RESET, array_of_grid_of_experts[i][j]);
      }

      else if (array_of_grid_of_experts[i][j] == '2' || array_of_grid_of_experts[i][j] == '0') // color of winner of boxes 2
      {
        printf(BIBLE "%c" RESET, array_of_grid_of_experts[i][j]);
      }

      else if (array_of_grid_of_experts[i][j] == '1') //  color of winner of boxes 1
      {
        printf(BRED "%c" RESET, array_of_grid_of_experts[i][j]);
      }

      else if ((i == row_to_print && j == column_to_print) && (turn_color_e == 1))
      {
        printf(BRED "%c" RESET, array_of_grid_of_experts[i][j]);
        if (array_of_grid_of_experts[i][j] == '|')
          row_to_print++;
        else if (array_of_grid_of_experts[i][j] == '-')
          column_to_print++;
      }
      else if ((i == row_to_print && j == column_to_print) && (turn_color_e == 2 || turn_color_e == 0))
      {
        printf(BIBLE "%c" RESET, array_of_grid_of_experts[i][j]);
        if (array_of_grid_of_experts[i][j] == '|')
          row_to_print++;
        else if (array_of_grid_of_experts[i][j] == '-')
          column_to_print++;
      }
      else
      {
        if (array_of_grid_of_experts[i][j] == '-' || array_of_grid_of_experts[i][j] == '|')
        {
          printf((WHITE "%c" RESET), array_of_grid_of_experts[i][j]);
        }
        else
        {
          printf((YELLOW "%c" RESET), array_of_grid_of_experts[i][j]);
        }
      }
    }
    printf("\n");
  }
}

void print_remaining_and_scores(char name_1[50], char name_2[50], int player_1_scores, int player_2_scores, int *remaining_lines, int *remaining_boxes)
{
  printf(BRED "\n%s score : %d\n" RESET, name_1, player_1_scores);
  printf(BIBLE "%s score : %d\n" RESET, name_2, player_2_scores);
  printf(BAYLE "number of remaining lines : %d\n" RESET, *remaining_lines);
  printf(BAYLE "number of remaining boxes : %d\n" RESET, *remaining_boxes);
}
void print_remaining_and_scores_computer(char name_1[50], int player_1_scores, int computer_score, int *remaining_lines, int *remaining_boxes)
{
  printf(BRED "\n%s score : %d\n" RESET, name_1, player_1_scores);
  printf(BIBLE "Computer's score : %d\n" RESET, computer_score);
  printf(BAYLE "number of remaining lines : %d\n" RESET, *remaining_lines);
  printf(BAYLE "number of remaining boxes : %d\n" RESET, *remaining_boxes);
}
void print_win(char name_1[50], char name_2[50], int player_1_scores, int player_2_scores, int computer_score, char against_s)
{ // win;
  if (against_s == '1')
  {
    if (data.player_two_score > data.player_one_score)
    {
      printf("\n\t" MAGE " %s Won the game " RESET "\n", data.Name_Player2);
    }
    else if (data.player_two_score < data.player_one_score)
    {
      printf("\n\t" MAGE " %s Won the game " RESET "\n", data.Name_Player1);
    }
    else
    {
      printf("\n\t" MAGE " Draw " RESET "\n");
    }
  }
  else
  {
    if (data.computer_score > data.player_one_score)
    {
      printf("\n\t" MAGE " Computer won the game " RESET "\n");
    }
    else if (data.computer_score < data.player_one_score)
    {
      printf("\n\t" MAGE " %s Won the game " RESET "\n", data.Name_Player1);
    }
    else
    {
      printf("\n\t" MAGE " Draw " RESET "\n");
    }
  }
}
