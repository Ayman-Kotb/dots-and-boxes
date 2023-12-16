#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int  Check_Letter_In_Array_Of_Experts(char letter_changed ,char array_of_grid_of_experts[17][25]) // check letter choosen in array
{ 
  int Found = 0;
  for(int row_c = 0; row_c <17; row_c++)
  {
    for(int col_c = 0; col_c <25; col_c++)
    {
      if(array_of_grid_of_experts[row_c][col_c]==letter_changed)
      {
        Found=1;
        break;
      }
    }
    if(Found==1)
    {
      break;
    }
  }
  if(Found==1)
  {
    return 1;
  }
  else
  {
    return 2;
  }
}
int Check_Letter_In_Array_Of_Beginners(char letter_changed,char array_of_grid_of_beginners[9][13]) // check letter choosen in array
{
  int Found = 0;
  for(int row_c = 0; row_c <9; row_c++)
  {
    for(int col_c = 0; col_c <13; col_c++)
    {
      if(array_of_grid_of_beginners[row_c][col_c]==letter_changed)
      {
        Found = 1;
        break;
      }
    }
    if(Found==1)
    {
      break;
    }
  }
  if(Found==1)
  {
    return 1;
  }
  else
  {
    return 2;
  }
}