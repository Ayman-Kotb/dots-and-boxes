#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void print_initial_B(char array_of_grid_of_beginners[9][13])
{
  for (int row=0;row<9;row++)
    {
      for(int column=0;column<13;column++)
      {
          if(array_of_grid_of_beginners[row][column]=='.')
          {
            printf(" %c",array_of_grid_of_beginners[row][column]);
          }
          else
          {
            printf((GREEN" %c"RESET),array_of_grid_of_beginners[row][column]);
          }
      }
      printf("\n");
    }
}
void print_initial_E(char array_of_grid_of_experts[17][25])
{
  for(int row=0;row<17;row++)
  {
    for(int column=0;column<25;column++)
    {
        if(array_of_grid_of_experts[row][column]=='.')
        {
          printf(" %c",array_of_grid_of_experts[row][column]);
        }
        else
        {
          printf((GREEN" %c"RESET),array_of_grid_of_experts[row][column]);
        }
    }
    printf("\n");
  }
}
void print_after_change_beginners()
{

}
void print_after_change_experts()
{

}