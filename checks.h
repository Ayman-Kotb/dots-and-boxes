#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int  Check_Letter_In_Array_Of_Experts(char letter_changed ,unsigned char array_of_grid_of_experts[21][41]) // check letter choosen in array
{ 
  int Found = 0;
  for(int row_c = 0; row_c <21; row_c++)
  {
    for(int col_c = 0; col_c <41; col_c++)
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
int Check_Letter_In_Array_Of_Beginners(char letter_changed,unsigned char array_of_grid_of_beginners[9][17]) // check letter choosen in array
{
  int Found = 0;
  for(int row_c = 0; row_c <9; row_c++)
  {
    for(int col_c = 0; col_c <17; col_c++)
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