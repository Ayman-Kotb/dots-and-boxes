#include <stdio.h>
#include <string.h>
#include<stdlib.h>

// beginners initial
void print_initial_B(unsigned char array_of_grid_of_beginners[9][13])
{
  for (int row=0;row<9;row++)
    {
      for(int column=0;column<13;column++)
      {
          if(array_of_grid_of_beginners[row][column]=='.')
          {
            printf(MAGENTA"%c"RESET,array_of_grid_of_beginners[row][column]);
          }
          else
          {
            printf((GREEN"%c"RESET),array_of_grid_of_beginners[row][column]);
          }
      }
      printf("\n");
    }
}
// experts initial
void print_initial_E(unsigned char array_of_grid_of_experts[21][31])
{
  for(int row=0;row<21;row++)
  {
    for(int column=0;column<31;column++)
    {
        if(array_of_grid_of_experts[row][column]=='.')
        {
          printf(MAGENTA"%c"RESET,array_of_grid_of_experts[row][column]);
        }
        else
        {
          printf((GREEN"%c"RESET),array_of_grid_of_experts[row][column]);
        }
    }
    printf("\n");
  }
}
// beginners after change
void print_after_change_beginners(unsigned char array_of_grid_of_beginners[9][13],int turn_color_b)
{
  for (int i=0;i<9;i++)
    {
      for(int j=0;j<13;j++)
      {
          if(array_of_grid_of_beginners[i][j]=='.')
          {
            printf(MAGENTA"%c"RESET,array_of_grid_of_beginners[i][j]);
          }
          else if((i==row_to_print&&j==column_to_print)&&(turn_color_b==1))
          {
            printf(RED"%c"RESET,array_of_grid_of_beginners[i][j]);
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
            printf(YELLOW"%c"RESET,array_of_grid_of_beginners[i][j]);
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
            printf((GREEN"%c"RESET),array_of_grid_of_beginners[i][j]);
          }
      } 
      printf("\n");
    }
}
// experts after change
void print_after_change_experts(unsigned char array_of_grid_of_experts[21][31],int turn_color_e)
{
  for (int i=0;i<21;i++)
    {
      for(int j=0;j<31;j++)
      {
          if(array_of_grid_of_experts[i][j]=='.')
          {
            printf(MAGENTA"%c"RESET,array_of_grid_of_experts[i][j]);
          }
          else if((i==row_to_print&&j==column_to_print)&&(turn_color_e==1))
          {
            printf(RED"%c"RESET,array_of_grid_of_experts[i][j]);
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
            printf(YELLOW"%c"RESET,array_of_grid_of_experts[i][j]);
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
            printf((GREEN"%c"RESET),array_of_grid_of_experts[i][j]);
          }
      }
      printf("\n");
    }
}