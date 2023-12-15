#include <stdio.h>
#include <string.h>
#include<stdlib.h>
// beginners initial
void print_initial_B(char array_of_grid_of_beginners[9][13])
{
  for (int row=0;row<9;row++)
    {
      for(int column=0;column<13;column++)
      {
          if(array_of_grid_of_beginners[row][column]=='.')
          {
            printf(GREEN" %c"RESET,array_of_grid_of_beginners[row][column]);
          }
          else
          {
            printf((MAGENTA" %c"RESET),array_of_grid_of_beginners[row][column]);
          }
      }
      printf("\n");
    }
}
// experts initial
void print_initial_E(char array_of_grid_of_experts[17][25])
{
  for(int row=0;row<17;row++)
  {
    for(int column=0;column<25;column++)
    {
        if(array_of_grid_of_experts[row][column]=='.')
        {
          printf(GREEN" %c"RESET,array_of_grid_of_experts[row][column]);
        }
        else
        {
          printf((MAGENTA" %c"RESET),array_of_grid_of_experts[row][column]);
        }
    }
    printf("\n");
  }
}
// beginners after change
void print_after_change_beginners(char array_of_grid_of_beginners[9][13])
{
  for (int i=0;i<9;i++)
    {
      for(int j=0;j<13;j++)
      {
          if(array_of_grid_of_beginners[i][j]=='.')
          {
            printf(GREEN" %c"RESET,array_of_grid_of_beginners[i][j]);
          }
          else
          {
            printf((MAGENTA" %c"RESET),array_of_grid_of_beginners[i][j]);
          }
      }
      printf("\n");
    }
}
// experts after change
void print_after_change_experts(char array_of_grid_of_experts[17][25])
{
  for (int i=0;i<17;i++)
    {
      for(int j=0;j<25;j++)
      {
          if(array_of_grid_of_experts[i][j]=='.')
          {
            printf(GREEN" %c"RESET,array_of_grid_of_experts[i][j]);
          }
          else
          {
            printf((MAGENTA" %c"RESET),array_of_grid_of_experts[i][j]);
          }
      }
      printf("\n");
    }
}