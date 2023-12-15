#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"

void grid_after_change_of_beginners(char letter_changed,char array_of_grid_of_beginners[9][13])    // MAke it print after change
{
  int found_in = 0 ;
  for (int row_ch=0;row_ch<9;row_ch++)
    {
      for(int column_ch=0;column_ch<13;column_ch++)
       {
          if(array_of_grid_of_beginners[row_ch][column_ch]==letter_changed)
          {
            for(int count=0;count<6;count++)
            {
              if(array_of_grid_of_beginners[row_ch][column_ch]=='A'+count)
              {
                array_of_grid_of_beginners[row_ch][column_ch] = '-';
                break;
              }
              else if(array_of_grid_of_beginners[row_ch][column_ch]=='a'+count)
              {
                array_of_grid_of_beginners[row_ch][column_ch]='|';
                break;
              }
            }
            if ((letter_changed)>96)
            { 
                array_of_grid_of_beginners[row_ch-1][column_ch]= '|';
                array_of_grid_of_beginners[row_ch+1][column_ch]= '|';
                
            }
            else if (letter_changed<96)
            {
                for (int i = 1; i < 3 ; i++){
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
  for (int i=0;i<9;i++)
    {
      for(int j=0;j<13;j++)
      {
          if(array_of_grid_of_beginners[i][j]=='.')
          {
            printf(" %c",array_of_grid_of_beginners[i][j]);
          }
          else
          {
            printf(GREEN" %c"RESET,array_of_grid_of_beginners[i][j]);
          }
      }
      printf("\n");
    }
} 
void grid_after_change_of_experts(char letter_changed,char array_of_grid_of_experts[17][25])      // Make it print after change
{
  
}
