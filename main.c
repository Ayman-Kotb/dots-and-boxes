#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "initialGrid.h"
#include "Grid_change.h"
#include "checks.h"
#include "Turns.h"
#include "Data.h"
#include "print.h"

//arrays
unsigned char array_of_grid_of_beginners[9][17];
unsigned char array_of_grid_of_experts[21][41];
int number_of_lines_in_B = 12; // to fix number of loops
int number_of_lines_in_E = 60; // to fix number of loops
// code
int main()
{
    int MODE_B_E = 0;
    int against;
    //TAke names and who play against:
    printf("\n"REDS"Welcome to Dots and Boxes Game!"RESET"\n\n");
    printf("what mode U want to play\n1: Experts Mode\n2: Beginner Mode\n");

    scanf(" %d",&MODE_B_E);
    // Error when enter letters?!
    while ((MODE_B_E != 1)&&(MODE_B_E != 2))
    {
      printf("Invalid , please select the number of the mode U want from 1:2\n") ;
      printf("1: Experts Mode\n2: Beginner Mode\n");
      scanf(" %d",&MODE_B_E);
    }
    
    printf("==========================================\n");
    printf("choose who do U want to play against\n1: another Player\n2: Computer\n");
    scanf("%d",&against);
    while ((against!=1)&&(against!=2))
    {
      printf("Invalid , please select the number who U want to play against from 1:2\n") ;
      printf("1: another Player\n2: Computer\n");
      scanf("%d",&against);
    }
    printf("==========================================\n");
    //prints
    if(against == 1)
    {
        printf("whats your name, player 1\n");
        scanf("%s",&data.Name_Player1);
        printf("whats your name, player 2\n");
        scanf("%s",&data.Name_Player2);
        printf("\n%s has RED color , %s has BLUE color\n\n",data.Name_Player1,data.Name_Player2);
        printf(BLKHD"this is initial grid"RESET"\n");
        printf("====================================================\n\n");
    }
    else
    {
        printf("whats your name\n");
        scanf("%s",&data.Name_Player1);
        printf("\nU has RED color , Computer has BLUE color\n\n");
        printf(BLKHD"this is initial grid"RESET"\n");
        printf("====================================================\n\n");
    }
    //turns
    char letter_to_be_changed;
    if(MODE_B_E==1&&against==1)//two players in the experts mode
    {
       creat_initial_grid_for_experts(array_of_grid_of_experts);
       print_initial_E(array_of_grid_of_experts);
       printf("\n=====================================================\n");//still
        for (int i = 0; i < 84; i++) 
      {
        number_of_lines_in_E--;  // error in number of loops
       if(i%2==0&&number_of_lines_in_E>=0)
       {
         player_one_turn(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,data.Name_Player1);
         if(letter_be_changed>96)
         {
            int right_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e,col_e+4,1);
            if (right_box==4){data.player_one_score++;
            i++;}
            int left_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e,col_e-4,1);
            if(left_box==4){data.player_one_score++;
            i++;}
            if(right_box==4&&left_box==4){i--;}
         }
         else
         {
           int lower_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e+2,col_e,1);
           if(lower_box ==4){data.player_one_score++;
           i++;}
           int upper_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e-2,col_e,1);
           if(upper_box ==4){data.player_one_score++;
           i++;}
           if(lower_box==4&&upper_box==4){i--;}
         }      
         print_after_change_experts(array_of_grid_of_experts,1);
         printf(BRED"\n%s score : %d\n"RESET,data.Name_Player1,data.player_one_score);
         printf(BIBLE"%s score : %d\n"RESET,data.Name_Player2,data.player_two_score);
         printf(BAYLE"number of lines remaining : %d\n"RESET,number_of_lines_in_E);
       }
       else if(i%2==1&&number_of_lines_in_E>=0)
       {
          player_two_turn(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,data.Name_Player2);
         if(letter_be_changed>96)
         {
           int right_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e,col_e+4,2);
           if(right_box ==4){data.player_two_score++;
           i++;}
           int left_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e,col_e-4,2);
           if( left_box==4){data.player_two_score++;
           i++;}
           if(right_box==4&&left_box==4){i--;}
         }
         else
         {
            int lower_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e+2,col_e,2);
            if(lower_box==4){data.player_two_score++;
            i++;}
            int upper_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e-2,col_e,2);
            if(upper_box ==4){data.player_two_score++;
            i++;}
            if(lower_box==4&&upper_box==4){i--;}
         }      
         print_after_change_experts(array_of_grid_of_experts,2);
         printf(BRED"\n%s score : %d\n"RESET,data.Name_Player1,data.player_one_score);
         printf(BIBLE"%s score : %d\n"RESET,data.Name_Player2,data.player_two_score);
         printf(BAYLE"number of lines remaining : %d\n"RESET,number_of_lines_in_E);
       }
     } 
    }
    else if(MODE_B_E==1&&against==2)//one player vs computer in the experts mode
    {
       creat_initial_grid_for_experts(array_of_grid_of_experts);
       print_initial_E(array_of_grid_of_experts);
       printf("\n=====================================================\n");//still
    }
    else if(MODE_B_E==2&&against==1)//two player in the beginner mode
    {
       creat_initial_grid_for_beginners(array_of_grid_of_beginners);
       print_initial_B(array_of_grid_of_beginners);
       printf("\n=====================================================\n");//still
       for (int i = 0; i < 15 ;i++ ) // error in number of loops
      {
        number_of_lines_in_B--; // fix number of loops
       if(i%2==0&&number_of_lines_in_B>=0)
       {
         player_one_turn(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,data.Name_Player1);
         if(letter_be_changed>96)
         {
           int right_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_b,col_b+4,1);
           if (right_box==4){data.player_one_score++;
           i++ ; }
           int left_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_b,col_b-4,1);
           if(left_box==4){data.player_one_score++;
           i++ ;}
           if(right_box==4&&left_box==4){i--;}
         }
         else
         {
           int lower_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_b+2,col_b,1);
           if(lower_box ==4){data.player_one_score++;
           i++ ;}
           int upper_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_b-2,col_b,1);
           if(upper_box ==4){data.player_one_score++;
           i++ ;}
           if(lower_box==4&&upper_box==4){i--;}
         }      
         print_after_change_beginners(array_of_grid_of_beginners,1);
         printf(BRED"\n%s score : %d\n"RESET,data.Name_Player1,data.player_one_score);
         printf(BIBLE"%s score : %d\n"RESET,data.Name_Player2,data.player_two_score);
         printf(BAYLE"number of lines remaining : %d\n"RESET,number_of_lines_in_B);
       }
       else if(i%2==1&&number_of_lines_in_B>=0)
       {
         player_two_turn(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,data.Name_Player2);
         if(letter_be_changed>96)
         {
           int right_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_b,col_b+4,2);
           if(right_box==4){data.player_two_score++;
           i++ ;}
           int left_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_b,col_b-4,2);
           if(left_box==4){data.player_two_score++;
           i++ ;}
           if(right_box==4&&left_box==4){i--;}
         }
         else
         {
           int lower_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_b+2,col_b,2);
           if(lower_box==4){data.player_two_score++;
           i++ ;}
           int upper_box = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_b-2,col_b,2);
           if(upper_box==4){data.player_two_score++;
           i++ ;}
           if(lower_box==4&&upper_box==4){i--;}
         }      
         print_after_change_beginners(array_of_grid_of_beginners,2);
         printf(BRED"\n%s score : %d\n"RESET,data.Name_Player1,data.player_one_score);
         printf(BIBLE"%s score : %d\n"RESET,data.Name_Player2,data.player_two_score);
         printf(BAYLE"number of lines remaining : %d\n"RESET,number_of_lines_in_B);
      }
     }
    }
    else//one player vs computer in the beginners mode
    {
       creat_initial_grid_for_beginners(array_of_grid_of_beginners);
       print_initial_B(array_of_grid_of_beginners);
       printf("\n=====================================================\n");//still
    }
    // be changed
    return 0;
}
