#include <stdio.h>
#include "initialGrid.h"
#include "Grid_change.h"
#include "checks.h"
#include "Turns.h"

//arrays
char array_of_grid_of_beginners[9][13];
char array_of_grid_of_experts[17][25];

int main()
{
    int MODE_B_E;
    int against;
    char Name_Player1[10];
    char Name_Player2[10];
    //TAke names and who play against:
    printf("what mode U want to play\n1: Experts Mode\n2: Beginner Mode\n");
    scanf("%d",&MODE_B_E);
    printf("===========================\n");
    printf("choose who U want to play against\n1: another Player\n2: Computer\n");
    scanf("%d",&against);
    printf("===========================\n");
    //prints
    if(against == 1)
    {
        printf("whats your name player 1\n");
        scanf("%s",&Name_Player1);
        printf("whats your name player 2\n");
        scanf("%s",&Name_Player2);
        printf("\n%s has Red color , %s has Yellow color\n", Name_Player1, Name_Player2);
        printf("=========================================\n");
    }
    else
    {
        printf("whats your name\n");
        scanf("%s",&Name_Player1);
        printf("\nU has Red color , Computer has Yellow color\n");
        printf("=============================================\n");
    }
    //turns
    char letter_to_be_changed;
    if(MODE_B_E==1&&against==1)//two players in the experts mode
    {
       Creat_Initial_Grid_For_Experts(array_of_grid_of_experts);
       printf("=============================================\n");
    }
    else if(MODE_B_E==1&&against==2)//one player vs computer in the experts mode
    {
       Creat_Initial_Grid_For_Experts(array_of_grid_of_experts);
       printf("=============================================\n");
    }
    else if(MODE_B_E==2&&against==1)//two player in the beginner mode
    {
       Creat_Initial_Grid_For_Beginners(array_of_grid_of_beginners);
       printf("=============================================\n");
    }
    else//one player vs computer in the beginners mode
    {
       Creat_Initial_Grid_For_Beginners(array_of_grid_of_beginners);
       printf("=============================================\n");
    }
    
return 0;  
}
