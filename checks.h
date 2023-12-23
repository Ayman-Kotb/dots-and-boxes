#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int row_e = 0;                                                                                            // for expert go to check boxes from main     comes from check letters
int col_e = 0;                                                                                            // for expert go to check boxes from main        comes from check letters
int row_b = 0;                                                                                            // for beginners go to check boxes from main      comes from check letters
int col_b = 0;                                                                                            // for beginners go to check boxes from main        comes from check letters
int row_to_chain = 0;                                                                                     // go to chain
int col_to_chain = 0;                                                                                     // go to chain
int Check_Letter_In_Array_Of_Experts(char letter_changed, unsigned char array_of_grid_of_experts[21][41]) // check letter choosen in array
{
  int Found = 0;
  for (int row_c = 0; row_c < 21; row_c++)
  {
    for (int col_c = 0; col_c < 41; col_c++)
    {
      if ((array_of_grid_of_experts[row_c][col_c] == letter_changed) && (letter_changed != '+'))
      {
        row_e = row_c;
        col_e = col_c;
        if (letter_changed == '|' && array_of_grid_of_experts[17][24] == '|')
        {
          Found = 0;
          break;
        }
        else if (letter_changed == '1' || letter_changed == '2' || letter_changed == '0' || letter_changed == '-')
        {
          Found = 0;
          break;
        }
        else
        {
          Found = 1;
          break;
        }
      }
    }
    if (Found == 1)
      break;
  }
  if (Found == 1)
    return 1;
  else
  {
    return 2;
  }
}
int Check_Letter_In_Array_Of_Beginners(char letter_changed, unsigned char array_of_grid_of_beginners[9][17]) // check letter choosen in array
{
  int Found = 0;
  for (int row_c = 0; row_c < 9; row_c++)
  {
    for (int col_c = 0; col_c < 17; col_c++)
    {
      if ((array_of_grid_of_beginners[row_c][col_c] == letter_changed) && (letter_changed != '+'))
      {
        row_b = row_c;
        col_b = col_c;
        if (letter_changed == '|')
        {
          Found = 0;
          break;
        }
        else if (letter_changed == '1' || letter_changed == '2' || letter_changed == '0' || letter_changed == '-')
        {
          Found = 0;
          break;
        }
        else
        {
          Found = 1;
          break;
        }
      }
    }
    if (Found == 1)
      break;
  }
  if (Found == 1)
    return 1;
  else
  {
    return 2;
  }
}
int check_boxes(int MODE_B_E, unsigned char array_of_grid_of_beginners[9][17], unsigned char array_of_grid_of_experts[21][41], int row_mid, int column_mid, int turn_player)
{
  int directional_array[2][4] = {0, 0, -2, 2,
                                 -4, 4, 0, 0};
  int row = 0;
  int column = 0;
  int number_of_lines = 0;
  if (MODE_B_E == 2)
  {
    for (int i = 0; i < 4; i++)
    {
      row = row_mid + directional_array[0][i];
      column = column_mid + directional_array[1][i];
      if (array_of_grid_of_beginners[row][column] == '-' || array_of_grid_of_beginners[row][column] == '|')
      {
        number_of_lines++;
      }
    }
    if (number_of_lines == 4 && turn_player == 1)
    {
      array_of_grid_of_beginners[row_mid][column_mid] = '1';
    }
    else if (number_of_lines == 4 && turn_player == 2)
    {
      array_of_grid_of_beginners[row_mid][column_mid] = '2';
    }

    return number_of_lines; // return number of lines      can be important
  }
  else
  {
    for (int i = 0; i < 4; i++)
    {
      row = row_mid + directional_array[0][i];
      column = column_mid + directional_array[1][i];
      if (array_of_grid_of_experts[row][column] == '-'|| array_of_grid_of_experts[row][column] == '|')// error in | in grid;
      {
          number_of_lines++;
      }
    }
    if (number_of_lines == 4 && turn_player == 1)
    {
      array_of_grid_of_experts[row_mid][column_mid] = '1';
    }
    else if (number_of_lines == 4 && turn_player == 2)
    {
      array_of_grid_of_experts[row_mid][column_mid] = '2';
    }
    return number_of_lines; // return number of lines           can be important
  }
}