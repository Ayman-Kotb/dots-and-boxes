#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int row_to_print = 50; // go to print
int column_to_print = 50; // go to print
// beginners
void grid_after_change_of_beginners(char letter_changed,unsigned char array_of_grid_of_beginners[9][17])    // MAke it print after change
{
  int found_in = 0 ;
  for (int row_ch=0;row_ch<9;row_ch++)
    {
      for(int column_ch=0;column_ch<17;column_ch++)
       {
          if(array_of_grid_of_beginners[row_ch][column_ch]==letter_changed)
          {
            if ((letter_changed)>96)
            { 
                row_to_print = row_ch-1;
                column_to_print = column_ch;
                array_of_grid_of_beginners[row_ch][column_ch]='|';
                array_of_grid_of_beginners[row_ch-1][column_ch]= '|';
                array_of_grid_of_beginners[row_ch+1][column_ch]= '|';
            }
            else if (letter_changed<96)
            {
                row_to_print = row_ch;
                column_to_print = column_ch-3;
                array_of_grid_of_beginners[row_ch][column_ch]='-';
                for (int i = 1; i < 4 ; i++)
                {
                array_of_grid_of_beginners[row_ch][column_ch-i]= '-';
                array_of_grid_of_beginners[row_ch][column_ch+i]= '-';
                }     
            }
            found_in = 1 ;
          }
          if(found_in==1) break; 
        }
        if (found_in ==1) break;
    }
} 
// experts
void grid_after_change_of_experts(char letter_changed,unsigned char array_of_grid_of_experts[21][41])      // Make it print after change
{
  int found_in = 0 ;
  for (int row_ch=0;row_ch<21;row_ch++)
    {
      for(int column_ch=0;column_ch<41;column_ch++) 
       {
          if(array_of_grid_of_experts[row_ch][column_ch]==letter_changed)
          {
            if ((letter_changed)>96)
            { 
                row_to_print = row_ch-1;
                column_to_print = column_ch;
                array_of_grid_of_experts[row_ch][column_ch]='|';
                array_of_grid_of_experts[row_ch-1][column_ch]= '|';
                array_of_grid_of_experts[row_ch+1][column_ch]= '|';
                
            }
            else if (letter_changed<96)
            {
                row_to_print = row_ch;
                column_to_print = column_ch-3;
                array_of_grid_of_experts[row_ch][column_ch]='-';
                for (int i = 1; i < 4 ; i++)
                {
                array_of_grid_of_experts[row_ch][column_ch-i]= '-';
                array_of_grid_of_experts[row_ch][column_ch+i]= '-';
                }     
            }
            found_in = 1 ;
          }
          if(found_in==1) break; 
        }
        if (found_in ==1) break;
    }
}
