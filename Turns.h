#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//turns;
char letter_be_changed = '0';
int taken_characters = 0;
int *p_of_taken_char = &taken_characters;// pointer on taken character;
unsigned char array_of_taken_characters[60] = "0";//taken characters; // for undo and redo;
void player_one_turn(char MODE_B_E, char twop_or_onep , unsigned char array_of_grid_of_beginners[9][17], unsigned char array_of_grid_of_experts[21][41], char Name_Player1[10] , int numofloop)
{
  int checked_letter = 2;
  if (MODE_B_E == '1')
  {
    printf("\n" BLKHD "%s, your turn" RESET "\n", Name_Player1);
    printf(MAGE"for SAVE enter 1\nfor UNDO enter 2\nfor REDO enter 3\n" RESET);
    printf("please enter the letter U want to change, %s\n", Name_Player1);
    scanf(" %c", &letter_be_changed);
    printf("\n");
    if (letter_be_changed=='1') {
    save_game(MODE_B_E,twop_or_onep ,data.Name_Player1, data.Name_Player2, data.player_one_score , data.player_two_score ,array_of_grid_of_beginners ,
               array_of_grid_of_experts , data.number_of_remaining_lines_e , data.number_of_remaining_boxes_e , numofloop) ;
    exit(0) ;
    }
    //else if (letter_be_changed=='2') { //still

    //}
    //else if (letter_be_changed=='3'){} still

    else {checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed, array_of_grid_of_experts);

    while (checked_letter != 1)
    {
      printf("please the letter must exist in the shape\n");
      printf("please enter the letter U want to change again, %s\n", Name_Player1);
      scanf(" %c", &letter_be_changed);
      printf("\n");
      if (letter_be_changed=='1') {
           save_game(MODE_B_E,twop_or_onep ,data.Name_Player1, data.Name_Player2, data.player_one_score , data.player_two_score ,array_of_grid_of_beginners ,
               array_of_grid_of_experts , data.number_of_remaining_lines_e , data.number_of_remaining_boxes_e , numofloop) ;
           exit(0) ;
        }
      checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed, array_of_grid_of_experts);
    }
    array_of_taken_characters[(*p_of_taken_char)] = letter_be_changed;
    (*p_of_taken_char)++;
    grid_after_change_of_experts(letter_be_changed, array_of_grid_of_experts); // still
  }}
  else
  {
    printf("\n" BLKHD "%s,your turn" RESET "\n", Name_Player1);
    printf(MAGE "for SAVE enter 1\nfor UNDO enter 2\nfor REDO enter 3\n" RESET);
    printf("please enter the letter U want to change, %s\n", Name_Player1);
    scanf(" %c", &letter_be_changed);
    printf("\n");
    if (letter_be_changed=='1') {
    save_game(MODE_B_E ,twop_or_onep, data.Name_Player1, data.Name_Player2, data.player_one_score , data.player_two_score ,array_of_grid_of_beginners ,
               array_of_grid_of_experts , data.number_of_remaining_lines_b , data.number_of_remaining_boxes_b , numofloop) ;
    exit(0) ;
    }
    //else if (letter_be_changed=='2') { //still

    //}
    //else if (letter_be_changed=='3'){} still

    else {
    checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed, array_of_grid_of_beginners);

    while (checked_letter != 1)
    {
      printf("please the letter must exist in the shape\n");
      printf("please enter the letter U want to change again, %s\n", Name_Player1);
      scanf(" %c", &letter_be_changed);
      printf("\n");
      if (letter_be_changed=='1') {
             save_game(MODE_B_E ,twop_or_onep, data.Name_Player1, data.Name_Player2, data.player_one_score , data.player_two_score ,array_of_grid_of_beginners ,
               array_of_grid_of_experts , data.number_of_remaining_lines_b , data.number_of_remaining_boxes_b , numofloop) ;
           exit(0) ;
        }
      checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed, array_of_grid_of_beginners);
    }
    array_of_taken_characters[(*p_of_taken_char)] = letter_be_changed;
    (*p_of_taken_char)++;
    grid_after_change_of_beginners(letter_be_changed, array_of_grid_of_beginners); // still
  }}
}
void player_two_turn(char MODE_B_E, unsigned char array_of_grid_of_beginners[9][17], unsigned char array_of_grid_of_experts[21][41], char Name_Player2[10] ,int numofloop)
{
  int checked_letter = 2;
  if (MODE_B_E == '1')
  {
    printf("\n" BLKHD "%s,your turn" RESET "\n", Name_Player2);
    printf(MAGE"for SAVE enter 1\nfor UNDO enter 2\nfor REDO enter 3\n"RESET);
    printf("please enter the letter U want to change, %s\n", Name_Player2);
    scanf(" %c", &letter_be_changed);
    printf("\n");
    if (letter_be_changed=='1') {
    save_game(MODE_B_E,'2' ,data.Name_Player1, data.Name_Player2, data.player_one_score , data.player_two_score ,array_of_grid_of_beginners ,
               array_of_grid_of_experts , data.number_of_remaining_lines_e , data.number_of_remaining_boxes_e , numofloop) ;
    exit(0) ;
    }
    //else if (letter_be_changed=='2') { //still

    //}
    //else if (letter_be_changed=='3'){} still

    else {
    checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed, array_of_grid_of_experts);

    while (checked_letter != 1)
    {
      printf("please the letter must exist in the shape\n");
      printf("please enter the letter U want to change again, %s\n", Name_Player2);
      scanf(" %c", &letter_be_changed);
      printf("\n");
      if (letter_be_changed=='1') {
           save_game(MODE_B_E,'2' ,data.Name_Player1, data.Name_Player2, data.player_one_score , data.player_two_score ,array_of_grid_of_beginners ,
               array_of_grid_of_experts , data.number_of_remaining_lines_e , data.number_of_remaining_boxes_e , numofloop) ;
           exit(0) ;
         }
      checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed, array_of_grid_of_experts);
    }
    array_of_taken_characters[(*p_of_taken_char)] = letter_be_changed;
    (*p_of_taken_char)++;
    grid_after_change_of_experts(letter_be_changed, array_of_grid_of_experts); // still
  }}
  else
  {
    printf("\n" BLKHD "%s,your turn" RESET "\n", Name_Player2);
    printf(MAGE"for SAVE enter 1\nfor UNDO enter 2\nfor REDO enter 3\n"RESET);
    printf("please enter the letter U want to change, %s\n", Name_Player2);
    scanf(" %c", &letter_be_changed);
    printf("\n");
    if (letter_be_changed=='1') {
    save_game(MODE_B_E,'2',data.Name_Player1, data.Name_Player2, data.player_one_score , data.player_two_score ,array_of_grid_of_beginners ,
               array_of_grid_of_experts , data.number_of_remaining_lines_b , data.number_of_remaining_boxes_b , numofloop) ;
    exit(0) ;
    }
    //else if (letter_be_changed=='2') { //still

    //}
    //else if (letter_be_changed=='3'){} still

    else {
    checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed, array_of_grid_of_beginners);

    while (checked_letter != 1)
    {
      printf("please the letter must exist in the shape\n");
      printf("please enter the letter U want to change again, %s\n", Name_Player2);
      scanf(" %c", &letter_be_changed);
      printf("\n");
      if (letter_be_changed=='1') {
          save_game(MODE_B_E,'2',data.Name_Player1, data.Name_Player2, data.player_one_score , data.player_two_score ,array_of_grid_of_beginners ,
               array_of_grid_of_experts , data.number_of_remaining_lines_b , data.number_of_remaining_boxes_b , numofloop) ;
          exit(0) ;
       }
      checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed, array_of_grid_of_beginners);
    }
    array_of_taken_characters[(*p_of_taken_char)] = letter_be_changed;
    (*p_of_taken_char)++;
    grid_after_change_of_beginners(letter_be_changed, array_of_grid_of_beginners); // still
  }}
}
void computer_turn(char MODE_B_E, unsigned char array_of_grid_of_beginners[9][17], unsigned char array_of_grid_of_experts[21][41]) // need search
{
  int checked_letter = 2;
  int random_number;
  if (MODE_B_E == '1')
  {
    random_number = (rand() % 62);
    while (random_number == 30 || random_number == 31)
    {
      random_number = (rand() % 62);
    }
    letter_be_changed = 'A' + random_number;
    checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed, array_of_grid_of_experts);
    while (checked_letter != 1)
    {
      random_number = (rand() % 62);
      while (random_number == 30 || random_number == 31)
      {
        random_number = (rand() % 62);
      }
      letter_be_changed = 'A' + random_number;
      checked_letter = Check_Letter_In_Array_Of_Experts(letter_be_changed, array_of_grid_of_experts);
    }
    array_of_taken_characters[(*p_of_taken_char)] = letter_be_changed;
    (*p_of_taken_char)++;
    grid_after_change_of_experts(letter_be_changed, array_of_grid_of_experts);
  }
  else
  {
    char grid_b[] = {'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'};
    random_number = (rand() % 12);
    letter_be_changed = grid_b[random_number];
    checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed, array_of_grid_of_beginners);
    while (checked_letter != 1)
    {
      random_number = (rand() % 12);
      letter_be_changed = grid_b[random_number];
      checked_letter = Check_Letter_In_Array_Of_Beginners(letter_be_changed, array_of_grid_of_beginners);
    }
    array_of_taken_characters[(*p_of_taken_char)] = letter_be_changed;
    (*p_of_taken_char)++;
    grid_after_change_of_beginners(letter_be_changed, array_of_grid_of_beginners);
  }
}
