#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void check_adjacent (int MODE_B_E,unsigned char array_of_grid_of_beginners[9][17],unsigned char array_of_grid_of_experts[21][41],int row_mid,int column_mid,int turn_player , int* x , int* y){
    int directional_array[2][4]={0 , 0 , -2 , 2,
                                 -4 , 4 , 0 , 0 };
    int row , column ;
    char letter_will_be_removed = '0'; 
    int number_of_lines = 0;
    if(MODE_B_E==2){
        if( row_mid>8 || column_mid>16 || row_mid<0 || column_mid <0 ) return  ;
        for(int i=0 ; i<4 ; i++){
        row = row_mid + directional_array[0][i] ;
        column = column_mid + directional_array[1][i] ;   
        if(array_of_grid_of_beginners[row][column]=='-'||array_of_grid_of_beginners[row][column]=='|')
                {  number_of_lines++; } 
        else { letter_will_be_removed = array_of_grid_of_beginners[row][column]; }
        }
        if (number_of_lines==3) {
           grid_after_change_of_beginners(letter_will_be_removed,array_of_grid_of_beginners);
                if (turn_player==1){ data.player_one_score ++; }
                else if (turn_player==2) {data.player_two_score ++ ;}
               (*x) -- ;
               (*y) --;
            array_of_grid_of_beginners[row_mid][column_mid] = (turn_player +'0') ;
            check_adjacent (MODE_B_E,array_of_grid_of_beginners ,array_of_grid_of_experts , row_mid+4, column_mid,turn_player, x,y) ;
            check_adjacent (MODE_B_E,array_of_grid_of_beginners ,array_of_grid_of_experts , row_mid-4, column_mid,turn_player, x,y) ;
            check_adjacent (MODE_B_E,array_of_grid_of_beginners ,array_of_grid_of_experts , row_mid, column_mid+8,turn_player, x,y) ;
            check_adjacent (MODE_B_E,array_of_grid_of_beginners ,array_of_grid_of_experts , row_mid, column_mid-8,turn_player , x,y) ;
        }
        else if ((number_of_lines==4)&&(array_of_grid_of_beginners[row_mid][column_mid] == ' ')) {
            array_of_grid_of_beginners[row_mid][column_mid] = turn_player+ '0' ;
            (*y) -- ;
            if (turn_player==1){ data.player_one_score ++; }
        else if (turn_player==2) {data.player_two_score ++ ;}
        
        }
        else return ;
        }
    else if (MODE_B_E==1){
        if( row_mid>20 || column_mid>40) return  ;
        for(int i=0 ; i<4 ; i++){
        row = row_mid + directional_array[0][i] ;
        column = column_mid + directional_array[1][i] ;   
        if(array_of_grid_of_beginners[row][column]=='|'|| array_of_grid_of_beginners[row][column]=='-'){
            number_of_lines++; } 
        else { letter_will_be_removed = array_of_grid_of_beginners[row][column]; }
        }
        if (number_of_lines==3) {
           /*grid_after_change_of_beginners(letter_will_be_removed,array_of_grid_of_beginners);
            if (turn_player==1) {array_of_grid_of_beginners[row_mid][column_mid] = '1'; }
            else if(turn_player==2) { array_of_grid_of_beginners[row_mid][column_mid] = '2'; }
            check_adjacent (MODE_B_E,array_of_grid_of_beginners[9][17],array_of_grid_of_experts[21][41], row_mid+4, column_mid,turn_player)
            check_adjacent (MODE_B_E,array_of_grid_of_beginners[9][17],array_of_grid_of_experts[21][41], row_mi-4, column_mid,turn_player)
            check_adjacent (MODE_B_E,array_of_grid_of_beginners[9][17],array_of_grid_of_experts[21][41], row_mid, column_mid+8,turn_player)
            check_adjacent (MODE_B_E,array_of_grid_of_beginners[9][17],array_of_grid_of_experts[21][41], row_mid, column_mid-8,turn_player)*/
            return ;
        }
        else return ;



    }

}