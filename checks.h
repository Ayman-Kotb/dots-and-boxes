#include<stdio.h>
#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"

int Found = 0;
int check_letter_in_array_of_experts(char letter_changed ,char array_of_grid_of_experts[17][25])
{
  for(int row = 0; row <17; row++)
  {
    for(int col = 0; col <25; col++)
    {
      if(array_of_grid_of_experts[row][col]==letter_changed)
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
int check_letter_in_array_of_beginners(char letter_changed,char array_of_grid_of_beginners[9][13])
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