#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"

void grid_after_change_of_beginners(char letter_changed,char array_of_grid_of_beginners[9][13])    // MAke it print after change
{
int found = 0 ;
for (int row=0;row<9;row++)
    {
      for(int column=0;column<13;column++)
      {
          if(array_of_grid_of_beginners[row][column]==letter_changed)
          {
            array_of_grid_of_beginners[row][column]== '-';
            if (letter_changed>96)
            { 
                
                    array_of_grid_of_beginners[row-1][column]== '|';
                    array_of_grid_of_beginners[row+1][column]== '|';
                
            }
            else if (letter_changed<96)
            {
                for (int i = 1; i < 6 ; i++){
                array_of_grid_of_beginners[row][column-i]== '-';
                array_of_grid_of_beginners[row][column+i]== '-';
                }     
            }
            found = 1 ;
          } 
        }
        if (found ==1) break;
    }
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
            printf(GREEN" %c"RESET,array_of_grid_of_beginners[row][column]);
          }
      }
      printf("\n");
    }

} 
void grid_after_change_of_experts(char letter_changed,char array_of_grid_of_experts[17][25])      // Make it print after change
{
  
}
