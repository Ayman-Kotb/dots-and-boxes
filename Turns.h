#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char letter_be_changed = '0';
char input_from_user[100];
void player_one_turn(int MODE_B_E ,unsigned char array_of_grid_of_beginners[9][17],unsigned char array_of_grid_of_experts[21][41],char Name_Player1[10])
{
    int checked_letter = 2;
    if(MODE_B_E ==1)
    {
      printf("\n"BLKHD"%s, your turn"RESET"\n",Name_Player1);
      printf("please enter the letter U want to change, %s\n",Name_Player1);
      scanf(" %c",&letter_be_changed);
      while ((letter_be_changed=='1')||(letter_be_changed=='2')||(letter_be_changed=='*'))
      {
        printf("invalid character\nplease enter the letter U want to change again, %s\n",Name_Player1) ;
        scanf(" %c",&letter_be_changed);
      }
      printf("\n");
      checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed,array_of_grid_of_experts);

      while(checked_letter!=1)
      {
            printf("please the letter must exist in the shape\n");
            printf("please enter the letter U want to change again, %s\n",Name_Player1);
            scanf(" %c",&letter_be_changed);
            printf("\n");
            checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed,array_of_grid_of_experts);
      }
      grid_after_change_of_experts(letter_be_changed,array_of_grid_of_experts);// still 
    }
    else
    {
      printf("\n"BLKHD"%s,turn"RESET"\n",Name_Player1);
      printf("please enter the letter U want to change, %s\n",Name_Player1);
      scanf(" %c",&letter_be_changed);
      while ((letter_be_changed=='1')||(letter_be_changed=='2')||(letter_be_changed=='*'))
      {
        printf("invalid character\nplease enter the letter U want to change again, %s\n",Name_Player1) ;
        scanf(" %c",&letter_be_changed);
      }
      printf("\n");
      checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed,array_of_grid_of_beginners);

      while(checked_letter!=1)
      {
            printf("please the letter must exist in the shape\n");
            printf("please enter the letter U want to change again, %s\n",Name_Player1);
            scanf(" %c",&letter_be_changed);
            printf("\n");
            checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed,array_of_grid_of_beginners);
      }
      grid_after_change_of_beginners(letter_be_changed,array_of_grid_of_beginners);       // still    
    }
}
void player_two_turn(int MODE_B_E,unsigned char array_of_grid_of_beginners[9][17],unsigned char array_of_grid_of_experts[21][41],char Name_Player2[10])
{
  int checked_letter = 2;
  if(MODE_B_E ==1)
    {
      printf("\n"BLKHD"%s,turn"RESET"\n",Name_Player2);
      printf("please enter the letter U want to change, %s\n",Name_Player2);
      scanf(" %c",&letter_be_changed);
      while ((letter_be_changed=='1')||(letter_be_changed=='2')||(letter_be_changed=='*'))
      {
        printf("invalid character\nplease enter the letter U want to change again, %s\n",Name_Player2) ;
        scanf(" %c",&letter_be_changed);
      }
      printf("\n");
      checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed,array_of_grid_of_experts);

        while(checked_letter!=1)
        {
            printf("please the letter must exist in the shape\n");
            printf("please enter the letter U want to change again, %s\n",Name_Player2);
            scanf(" %c",&letter_be_changed);
            printf("\n");
            checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed,array_of_grid_of_experts);
        }
        grid_after_change_of_experts(letter_be_changed,array_of_grid_of_experts);           // still
    }
    else
    {
      printf("\n"BLKHD"%s,turn"RESET"\n",Name_Player2);
      printf("please enter the letter U want to change, %s\n",Name_Player2);
      scanf(" %c",&letter_be_changed);
      while ((letter_be_changed=='1')||(letter_be_changed=='2')||(letter_be_changed=='*'))
      {
        printf("invalid character\nplease enter the letter U want to change again, %s\n",Name_Player2) ;
        scanf(" %c",&letter_be_changed);
      }
      printf("\n");
      checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed,array_of_grid_of_beginners);

        while(checked_letter!=1)
        {
            printf("please the letter must exist in the shape\n");
            printf("please enter the letter U want to change again, %s\n",Name_Player2);
            scanf(" %c",&letter_be_changed);
            printf("\n");
            checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed,array_of_grid_of_beginners);
        }
        grid_after_change_of_beginners(letter_be_changed,array_of_grid_of_beginners);        // still
    }
}
void computer_turn()       // need search
{
  
}