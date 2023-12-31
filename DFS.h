#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_adjacent(char MODE_B_E, unsigned char array_of_grid_of_beginners[9][17], unsigned char array_of_grid_of_experts[21][41], int row_mid, int column_mid, int turn_player, int *x, int *y)
{
    int directional_array_adj[2][4] = {0, 0, -2, 2,
                                       -4, 4, 0, 0};
    int row_d, column_d;
    char letter_will_be_removed = '0';
    int number_of_lines_adj = 0;
    if (MODE_B_E == '2')
    {
        if (row_mid > 8 || column_mid > 16 || row_mid < 0 || column_mid < 0)
            return;
        for (int i = 0; i < 4; i++)
        {
            row_d = row_mid + directional_array_adj[0][i];
            column_d = column_mid + directional_array_adj[1][i];
            if (array_of_grid_of_beginners[row_d][column_d] == '-' || array_of_grid_of_beginners[row_d][column_d] == '|')
            {
                number_of_lines_adj++;
            }
            else
            {
                letter_will_be_removed = array_of_grid_of_beginners[row_d][column_d];
            }
        }
        if (number_of_lines_adj == 3)
        {
            grid_after_change_of_beginners(letter_will_be_removed, array_of_grid_of_beginners);
            if (turn_player == 1)
            {
                data.player_one_score++;
            }
            else if (turn_player == 2)
            {
                data.player_two_score++;
            }
            else
            {
                data.computer_score++;
            }
            (*x)--;
            (*y)--;
            array_of_grid_of_beginners[row_mid][column_mid] = (turn_player + '0');
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_mid + 4, column_mid, turn_player, x, y);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_mid - 4, column_mid, turn_player, x, y);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_mid, column_mid + 8, turn_player, x, y);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_mid, column_mid - 8, turn_player, x, y);
        }
        else if ((number_of_lines_adj == 4) && (array_of_grid_of_beginners[row_mid][column_mid] == ' '))
        {
            array_of_grid_of_beginners[row_mid][column_mid] = turn_player + '0';
            (*y)--;
            if (turn_player == 1)
            {
                data.player_one_score++;
            }
            else if (turn_player == 2)
            {
                data.player_two_score++;
            }
            else
            {
                data.computer_score++;
            }
        }
        else
            return;
    }
    //*******************************************************************
    else if (MODE_B_E == '1')
    {
        if (row_mid > 20 || column_mid > 40 || row_mid < 0 || column_mid < 0)
            return;
        for (int i = 0; i < 4; i++)
        {
            row_d = row_mid + directional_array_adj[0][i];
            column_d = column_mid + directional_array_adj[1][i];
            if ((array_of_grid_of_experts[row_d][column_d] == '|' && array_of_grid_of_experts[row_d - 1][column_d] == '|') || array_of_grid_of_experts[row_d][column_d] == '-')
            {
                number_of_lines_adj++;
            }
            else
            {
                letter_will_be_removed = array_of_grid_of_experts[row_d][column_d];
            }
        }
        if (number_of_lines_adj == 3)
        {
            grid_after_change_of_experts(letter_will_be_removed, array_of_grid_of_experts);
            if (turn_player == 1)
            {
                data.player_one_score++;
            }
            else if (turn_player == 2)
            {
                data.player_two_score++;
            }
            else
            {
                data.computer_score++;
            }
            (*x)--;
            (*y)--;
            array_of_grid_of_experts[row_mid][column_mid] = (turn_player + '0');
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_mid + 4, column_mid, turn_player, x, y);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_mid - 4, column_mid, turn_player, x, y);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_mid, column_mid + 8, turn_player, x, y);
            check_adjacent(MODE_B_E, array_of_grid_of_beginners, array_of_grid_of_experts, row_mid, column_mid - 8, turn_player, x, y);
        }
        else if ((number_of_lines_adj == 4) && (array_of_grid_of_experts[row_mid][column_mid] == ' '))
        {
            array_of_grid_of_experts[row_mid][column_mid] = turn_player + '0';
            (*y)--;
            if (turn_player == 1)
            {
                data.player_one_score++;
            }
            else if (turn_player == 2)
            {
                data.player_two_score++;
            }
            else
            {
                data.computer_score++;
            }
        }
        else
            return;
    }
}