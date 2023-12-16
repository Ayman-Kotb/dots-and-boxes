#include <stdio.h> 
// color space
#include <string.h>
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define CYAN "\e[0;36m"
#define MAGENTA "\e[0;35m"
#define BLKHD "\e[0;100m"
#define REDS "\e[0;101m" 
#define RESET "\e[0m"
// code
int capital_letters_of_grid = 0;
int small_letters_of_grid = 0;
//Beginners
void creat_initial_grid_for_beginners(unsigned char array_of_grid_of_beginners[9][13])
{
    for(int rows_B = 0; rows_B < 9; rows_B++)
    {
      for (int columns_B = 0; columns_B < 13; columns_B++)
      {
        if(rows_B%4==0)
        {
          if(columns_B%6==0)
          {
            array_of_grid_of_beginners[rows_B][columns_B]='.';
          }
          else if(columns_B==3||columns_B==9)
          {
            array_of_grid_of_beginners[rows_B][columns_B]=('A'+capital_letters_of_grid);
            capital_letters_of_grid++;
          }
          else
          {
            array_of_grid_of_beginners[rows_B][columns_B]=' ';
          }
        }
        else
        {
          if(columns_B%6==0)
          {
             if(rows_B%2==0)
             {
                array_of_grid_of_beginners[rows_B][columns_B]=('a'+small_letters_of_grid);
                small_letters_of_grid++;
             }
             else
             {
                array_of_grid_of_beginners[rows_B][columns_B]=' ';
             }
          }
          else
          {
                array_of_grid_of_beginners[rows_B][columns_B]=' ';
          }
        }
      }
    }
}   
//Experts
void creat_initial_grid_for_experts(unsigned char array_of_grid_of_experts[17][25])
{
  for(int rows_E=0;rows_E<21;rows_E++)
  {
    for(int columns_E=0;columns_E<31;columns_E++)
    {
        if(rows_E%4==0)
        {
            if(columns_E%6==0)
            {
                array_of_grid_of_experts[rows_E][columns_E]='.';
            }
            else if(columns_E==3||columns_E==9||columns_E==15||columns_E==21||columns_E==27)
            {
                array_of_grid_of_experts[rows_E][columns_E]=('A'+capital_letters_of_grid);
                capital_letters_of_grid++;
            }
            else
            {
                array_of_grid_of_experts[rows_E][columns_E]=' ';
            }
        }
        else
        {
            if(columns_E%6==0)
            {
                if(rows_E%2==0)
                {
                    array_of_grid_of_experts[rows_E][columns_E]=('a'+small_letters_of_grid);
                    small_letters_of_grid++;
                }
                else
                {
                    array_of_grid_of_experts[rows_E][columns_E]=' ';
                }
            }
            else
            {
               array_of_grid_of_experts[rows_E][columns_E]=' ';
            }
        }
    }
  }
}