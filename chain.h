#include <string.h>
#include <stdio.h>
//////////////////////// HAVE ERRORS//
/////////////////////// NOOOOOOOOOOOOO
/*char letter_from_chain = '0';
void check_chain_E(int MODE_E_B,int right_box,int left_box,int upper_box,int lower_box,unsigned char array_of_grid_of_experts[21][41],unsigned char array_of_grid_of_beginners[9][17],int turn_from_chain,int row_from_chain,int column_from_chain,int *(number_of_lines_e),int *(number_of_boxes_e))
{
  if(right_box==4&&left_box==3)
  {
    while(left_box==3)
    {
     letter_from_chain = array_of_grid_of_experts[row_from_chain][column_from_chain];
     if(turn_from_chain==1){
        array_of_grid_of_experts[row_from_chain][column_from_chain+4]='1';}
     else{
        array_of_grid_of_experts[row_from_chain][column_from_chain+4]='2';}
     grid_after_change_of_experts(letter_from_chain,array_of_grid_of_experts);
     left_box = check_boxes(MODE_E_B,array_of_grid_of_beginners,array_of_grid_of_experts,row_from_chain,column_from_chain-4,turn_from_chain);
     if(turn_from_chain==1)
     {data.player_one_score++;
     }
     else
     {data.player_two_score++;
     }
     if(left_box==4)
     {
        *(number_of_boxes_e) = *(number_of_boxes_e)-2;
     }
     else
     {
        *(number_of_boxes_e) = *(number_of_boxes_e)-1;
        *(number_of_lines_e)=  *(number_of_lines_e)-1;
        column_from_chain = column_from_chain-8;
     }
    }
  }
  else if(upper_box==4&&lower_box==3)
  {
    while(lower_box==3)
    {
     letter_from_chain = array_of_grid_of_experts[row_from_chain][column_from_chain];
     grid_after_change_of_experts(letter_from_chain,array_of_grid_of_experts);
     lower_box = check_boxes(MODE_E_B,array_of_grid_of_beginners,array_of_grid_of_experts,row_from_chain+2,column_from_chain,turn_from_chain);
     if(turn_from_chain==1)
     {data.player_one_score++;
      }
     else
     {data.player_two_score++;
      }
      *(number_of_boxes_e) = *(number_of_boxes_e)-1;
      *(number_of_lines_e)=  *(number_of_lines_e)-1;
      row_from_chain = row_from_chain+8;// problem
    }
  }
  else if(right_box==3&&left_box==4)
  {
    while(right_box==3)
    {
     letter_from_chain = array_of_grid_of_experts[row_from_chain][column_from_chain];
     if(turn_from_chain==1){
        array_of_grid_of_experts[row_from_chain][column_from_chain-4]='1';}
     else{
        array_of_grid_of_experts[row_from_chain][column_from_chain-4]='2';}
     grid_after_change_of_experts(letter_from_chain,array_of_grid_of_experts);
     right_box = check_boxes(MODE_E_B,array_of_grid_of_beginners,array_of_grid_of_experts,row_from_chain,column_from_chain+4,turn_from_chain);
     if(turn_from_chain==1)
     {data.player_one_score++;
      }
     else
     {data.player_two_score++;
      }
      if(right_box==4)
      {
        *(number_of_boxes_e) = *(number_of_boxes_e)-2;
      }
      else
      {
        *(number_of_boxes_e) = *(number_of_boxes_e)-1;
        *(number_of_lines_e)=  *(number_of_lines_e)-1;
        column_from_chain = column_from_chain+8;
      }
    }
  }
  else if(lower_box==4&&upper_box==3)
  {
    while(upper_box==3)
    {
     letter_from_chain = array_of_grid_of_experts[row_from_chain][column_from_chain];
     grid_after_change_of_experts(letter_from_chain,array_of_grid_of_experts);
     upper_box = check_boxes(MODE_E_B,array_of_grid_of_beginners,array_of_grid_of_experts,row_from_chain-2,column_from_chain,turn_from_chain);
     if(turn_from_chain==1)
     {data.player_one_score++;
      }
     else
     {data.player_two_score++;
      }
      if(upper_box==4)
      {
        *(number_of_boxes_e) = *(number_of_boxes_e)-2;
      }
      else
      {
        *(number_of_boxes_e) = *(number_of_boxes_e)-1;
        *(number_of_lines_e)=  *(number_of_lines_e)-1;
        row_from_chain = row_from_chain-8; // problem
      }
    }
  }
}
void check_chain_B(int right_box,int left_box,int upper_box,int lower_box)
{

}*/