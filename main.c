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
    }
    else//one player vs computer in the beginners mode
    {
       creat_initial_grid_for_beginners(array_of_grid_of_beginners);
       print_initial_B(array_of_grid_of_beginners);
       printf("\n=====================================================\n");//still
    }
    // be changed
    for (int i = 0; i < 40; i++)
    {
      if(i%2==0)
      {
        player_one_turn(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,data.Name_Player1);
        if(letter_be_changed>96)
        {
           int p1 = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e,col_e+4,1);
           if (p1==4){data.player_one_score++;}
           int p2 = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e,col_e-4,1);
           if(p2==4){data.player_one_score++;}
        }
        else
        {
           int p3 = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e+2,col_e,1);
           if(p3 ==4){data.player_one_score++;}
           int p4 = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e-2,col_e,1);
           if(p4 ==4){data.player_one_score++;}
        }      
        print_after_change_experts(array_of_grid_of_experts,1);
        printf("\n%s score : %d\n",data.Name_Player1,data.player_one_score);
        printf("%s score : %d\n",data.Name_Player2,data.player_two_score);
      }
      else
      {
         player_two_turn(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,data.Name_Player2);
        if(letter_be_changed>96)
        {
           int y1 = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e,col_e+4,2);
           if(y1==4){data.player_two_score++;}
           int y2 = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e,col_e-4,2);
           if(y2==4){data.player_two_score++;}
        }
        else
        {
           int y3 = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e+2,col_e,2);
           if(y3==4){data.player_two_score++;}
           int y4 = check_boxes(MODE_B_E,array_of_grid_of_beginners,array_of_grid_of_experts,row_e-2,col_e,2);
           if(y4==4){data.player_two_score++;}
        }      
        print_after_change_experts(array_of_grid_of_experts,2);
        printf("\n%s score : %d\n",data.Name_Player1,data.player_one_score);
        printf("%s score : %d\n",data.Name_Player2,data.player_two_score);
      }
    }
    return 0;
}
