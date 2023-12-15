#include <stdio.h>

#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"

char letter_be_changed;
int checked_letter;
void player_one_turn(int MODE_B_E , char array_of_grid_of_beginners[9][13], char array_of_grid_of_experts[17][25],char Name_Player1[10])
{
    if(MODE_B_E ==1)
    {
      printf("%s, your turn\n",Name_Player1);
      printf("please enter the letter U want to change, %s\n",Name_Player1);
      scanf( "%c",&letter_be_changed);
      checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed,array_of_grid_of_experts);

      while(checked_letter==0)
      {
            printf("please the letter must exist in the shape\n");
            printf("please enter the letter U want to change again, %s\n",Name_Player1);
            scanf(" %c",&letter_be_changed);
            checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed,array_of_grid_of_experts);
      }
      if(checked_letter==1)    grid_after_change_of_experts(letter_be_changed,array_of_grid_of_experts);         // still
    }
    else
    {
      printf("%s,turn\n",Name_Player1);
      printf("please enter the letter U want to change, %s\n",Name_Player1);
      scanf(" %c",&letter_be_changed);
      checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed,array_of_grid_of_beginners);
     while(checked_letter==0)
      {
            printf("please the letter must exist in the shape\n");
            printf("please enter the letter U want to change again, %s\n",Name_Player1);
            scanf(" %c",&letter_be_changed);
            checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed,array_of_grid_of_experts);
      }
      if(checked_letter==1)     grid_after_change_of_beginners(letter_be_changed,array_of_grid_of_beginners);       // still
    
    }
}
void player_two_turn(int MODE_B_E,char array_of_grid_of_beginners[9][13],char array_of_grid_of_experts[17][25],char Name_Player2[10])
{
  if(MODE_B_E ==1)
    {
      printf("%s,turn\n",Name_Player2);
      printf("please enter the letter U want to change, %s\n",Name_Player2);
      scanf(" %c",&letter_be_changed);
      checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed,array_of_grid_of_experts);

      if(checked_letter==1)
      {
        grid_after_change_of_experts(letter_be_changed,array_of_grid_of_experts);        // still
      }
      else
      {
        while(checked_letter==0)
        {
            printf("please the letter must exist in the shape\n");
            printf("please enter the letter U want to change again, %s\n",Name_Player2);
            scanf(" %c",&letter_be_changed);
            checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed,array_of_grid_of_experts);
        }
        grid_after_change_of_experts(letter_be_changed,array_of_grid_of_experts);           // still
      }
    }
    else
    {
      printf("%s,turn\n",Name_Player2);
      printf("please enter the letter U want to change, %s\n",Name_Player2);
      scanf(" %c",&letter_be_changed);
      checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed,array_of_grid_of_beginners);

      if(checked_letter==1)
      {
        grid_after_change_of_beginners(letter_be_changed,array_of_grid_of_beginners);        // still
      }
      else
      {
        while(checked_letter==0)
        {
            printf("please the letter must exist in the shape\n");
            printf("please enter the letter U want to change again, %s\n",Name_Player2);
            scanf(" %c",&letter_be_changed);
            checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed,array_of_grid_of_beginners);
        }
        grid_after_change_of_beginners(letter_be_changed,array_of_grid_of_beginners);        // still
      }
    }
}
void computer_turn()       // need search
{
  
}