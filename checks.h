#include<stdio.h>
#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"

int Found_in_Array;

int  Check_Letter_In_Array_Of_Experts(char letter_changed ,char array_of_grid_of_experts[17][25])
{
  for(int row = 0; row <17; row++)
  {
    for(int col = 0; col <25; col++)
    {
      if(array_of_grid_of_experts[row][col]==letter_changed)
      {
        Found_in_Array=1;
      }
    }
  }
    if(Found_in_Array==1)
    {
     return 1;
    }
    else
    {
     return 0;
    }
}
int Check_Letter_In_Array_Of_Beginners(char letter_changed,char array_of_grid_of_beginners[9][13])
{
  for(int row = 0; row <9; row++)
  {
    for(int col = 0; col <13; col++)
    {
      if(array_of_grid_of_beginners[row][col]==letter_changed)
      {
        Found_in_Array = 1;
      }
    }
  }
  if(Found_in_Array==1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}