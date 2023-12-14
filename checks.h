#include<stdio.h>
#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"

int Found;

int  Check_Letter_In_Array_Of_Experts(char letter_changed ,char array_of_grid_of_experts[17][25]) // check letter choosen in array
{
  for(int row = 0; row <17; row++)
  {
    for(int col = 0; col <25; col++)
    {
      if(array_of_grid_of_experts[row][col]==letter_changed)
      {
        Found=1;
      }
    }
  }
    if(Found==1)
    {
     return 1;
    }
    else
    {
     return 0;
    }
}
int Check_Letter_In_Array_Of_Beginners(char letter_changed,char array_of_grid_of_beginners[9][13]) // check letter choosen in array
{
  for(int row = 0; row <9; row++)
  {
    for(int col = 0; col <13; col++)
    {
      if(array_of_grid_of_beginners[row][col]==letter_changed)
      {
        Found = 1;
      }
    }
  }
  if(Found==1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}