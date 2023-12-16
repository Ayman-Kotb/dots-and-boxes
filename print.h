#include <stdio.h>
#include <string.h>
#include<stdlib.h>

// beginners initial
void print_initial_B(unsigned char array_of_grid_of_beginners[9][17])
{
  for (int row=0;row<9;row++)
    {
      for(int column=0;column<17;column++)
      {
          if(array_of_grid_of_beginners[row][column]=='.')
          {
            printf(GREEN" %c"RESET,array_of_grid_of_beginners[row][column]);
          }
          else
          {
            printf((BAYLE" %c"RESET),array_of_grid_of_beginners[row][column]);
          }
      }
      printf("\n");
    }
}
// experts initial
void print_initial_E(unsigned char array_of_grid_of_experts[21][41])
{
  for(int row=0;row<21;row++)
  {
    for(int column=0;column<41;column++)
    {
        if(array_of_grid_of_experts[row][column]=='.')
        {
          printf(GREEN"%c"RESET,array_of_grid_of_experts[row][column]);
        }
        else
        {
          printf((BAYLE"%c"RESET),array_of_grid_of_experts[row][column]);
        }
    }
    printf("\n");
  }
}
// beginners after change
void print_after_change_beginners(unsigned char array_of_grid_of_beginners[9][17],int turn_color_b)
{
  for (int i=0;i<9;i++)
    {
      for(int j=0;j<17;j++)
      {
          if(array_of_grid_of_beginners[i][j]=='.')
          {
            printf(GREEN" %c"RESET,array_of_grid_of_beginners[i][j]);
          }
          else if((i==row_to_print&&j==column_to_print)&&(turn_color_b==1))
          {
            printf(BRED" %c"RESET,array_of_grid_of_beginners[i][j]);
            if(array_of_grid_of_beginners[i][j]=='|')
            {
              row_to_print++;
            }
            else if(array_of_grid_of_beginners[i][j]=='-')
            {
              column_to_print++;
            }
          }
          else if((i==row_to_print&&j==column_to_print)&&(turn_color_b==2||turn_color_b==0))
          {
            printf(BIBLE" %c"RESET,array_of_grid_of_beginners[i][j]);
            if(array_of_grid_of_beginners[i][j]=='|')
            {
              row_to_print++;
            }
            else if(array_of_grid_of_beginners[i][j]=='-')
            {
              column_to_print++;
            }
          }
          else
          {
            printf((BAYLE" %c"RESET),array_of_grid_of_beginners[i][j]);
          }
      } 
      printf("\n");
    }
}
// experts after change
void print_after_change_experts(unsigned char array_of_grid_of_experts[21][41],int turn_color_e)
{
  for (int i=0;i<21;i++)
    {
      for(int j=0;j<41;j++)
      {
          if(array_of_grid_of_experts[i][j]=='.')
          {
            printf(GREEN"%c"RESET,array_of_grid_of_experts[i][j]);
          }
          else if((i==row_to_print&&j==column_to_print)&&(turn_color_e==1))
          {
            printf(BRED"%c"RESET,array_of_grid_of_experts[i][j]);
            if(array_of_grid_of_experts[i][j]=='|')
            {
              row_to_print++;
            }
            else if(array_of_grid_of_experts[i][j]=='-')
            {
              column_to_print++;
            }
          }
          else if((i==row_to_print&&j==column_to_print)&&(turn_color_e==2||turn_color_e==0))
          {
            printf(BIBLE"%c"RESET,array_of_grid_of_experts[i][j]);
            if(array_of_grid_of_experts[i][j]=='|')
            {
              row_to_print++;
            }
            else if(array_of_grid_of_experts[i][j]=='-')
            {
              column_to_print++;
            }
          }
          else
          {
            printf((BAYLE"%c"RESET),array_of_grid_of_experts[i][j]);
          }
      }
      printf("\n");
    }
}