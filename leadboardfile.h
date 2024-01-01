#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lead readed;
int check_name;
lead Top[100];
int site;
int i = 0;
int num_of_mem = 0;
int ch ;

int look_for_name_s(char name_player_p[50])
{
    int found_name = 0;
    FILE *file = fopen("scoreboard.txt", "r");
    while (fscanf(file, "Name : %s , Score : %d\n", Top[i].names, &Top[i].scores) == 2)
    {

        if (strcmp(Top[i].names, name_player_p) == 0)
        {
            site = i;
            found_name = 1;
        }
        i++;
    }
    fclose(file);
    if (found_name == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int put_in_file(char vs, char his_name1[50], char his_name2[50], int his_score1, int his_score2, int his_score3)
{ //! in file latest 3;
    if (vs == '1')
    {
        if (his_score1 > his_score2)
        {
            check_name = look_for_name_s(strlwr(his_name1));
            if (check_name == 0)
            {
                FILE *file = fopen("scoreboard.txt", "a");
                fprintf(file, "Name : %s , Score : %d\n", strlwr(his_name1), his_score1);
                fclose(file);
            }
            else if (check_name == 1)
            {
                FILE *file = fopen("scoreboard.txt", "w+");
                fseek(file, 0, SEEK_SET);
                if (Top[site].scores < his_score1)
                {
                    Top[site].scores = his_score1;
                }
                for (int j = 0; j < i; j++)
                {
                    fprintf(file, "Name : %s , Score : %d\n", Top[j].names, Top[j].scores);
                }
                fclose(file);
            }
        }
        else if (his_score2 > his_score1)
        {
            check_name = look_for_name_s(strlwr(his_name2));
            if (check_name == 0)
            {
                FILE *file = fopen("scoreboard.txt", "a");
                fprintf(file, "Name : %s , Score : %d\n", strlwr(his_name2), his_score2);
                fclose(file);
            }
            else if (check_name == 1)
            {
                FILE *file = fopen("scoreboard.txt", "w+");
                fseek(file, 0, SEEK_SET);
                if (Top[site].scores < his_score2)
                {
                    Top[site].scores = his_score2;
                }
                for (int j = 0; j < i; j++)
                {
                    fprintf(file, "Name : %s , Score : %d\n", Top[j].names, Top[j].scores);
                }
                fclose(file);
            }
        }
    }
    else
    {
        if (his_score1 > his_score3)
        {
            check_name = look_for_name_s(strlwr(his_name1));
            if (check_name == 0)
            {
                FILE *file = fopen("scoreboard.txt", "a");
                fprintf(file, "Name : %s , Score : %d\n", strlwr(his_name1), his_score1);
                fclose(file);
            }
            else if (check_name == 1)
            {
                FILE *file = fopen("scoreboard.txt", "w");
                fseek(file, 0, SEEK_SET);
                if (Top[site].scores < his_score1)
                {
                    Top[site].scores = his_score1;
                }
                for (int j = 0; j < i; j++)
                {
                    fprintf(file, "Name : %s , Score : %d\n", Top[j].names, Top[j].scores);
                }
                fclose(file);
            }
        }
    }
}
void print_shape_Top10()
{
    clearConsole();

    printf(BAYLE "\t\t\t ________   ______   _______           __    ______  \n");
    printf("\t\t\t|        \\ /      \\ |       \\        _/  \\  /      \\ \n");
    printf("\t\t\t \\$$$$$$$$|  $$$$$$\\| $$$$$$$\\      |   $$ |  $$$$$$\\\n");
    printf("\t\t\t   | $$   | $$  | $$| $$__/ $$       \\$$$$ | $$$\\| $$\n");
    printf("\t\t\t   | $$   | $$  | $$| $$    $$        | $$ | $$$$\\ $$\n");
    printf("\t\t\t   | $$   | $$  | $$| $$$$$$$         | $$ | $$\\$$\\$$\n");
    printf("\t\t\t   | $$   | $$__/ $$| $$             _| $$_| $$_\\$$$$\n");
    printf("\t\t\t   | $$    \\$$    $$| $$            |   $$ \\\\$$  \\$$$\n");
    printf("\t\t\t    \\$$     \\$$$$$$  \\$$             \\$$$$$$ \\$$$$$$ \n" RESET);
}
int sorting_scores(const void *X, const void *Y)
{
    lead *Player1 = X;
    lead *Player2 = Y;

    return ((Player2->scores) - (Player1->scores));
}
int read_and_sor_from_file()
{
    FILE *file = fopen("scoreboard.txt", "r");
    while (fscanf(file, "Name : %s , Score : %d\n", Top[num_of_mem].names, &Top[num_of_mem].scores) == 2)
    {
        num_of_mem++;
    }
    int SIZE = sizeof(Top) / sizeof(lead);
    qsort(Top, SIZE, sizeof(lead), sorting_scores);
     fclose(file);
}
void print_top10()
{
    int num = 1;
    for (int j = 0; j < 10; j++)
    {
        if (num == 1 || num == 2 || num == 3)
        {
            printf(BAYLE "\t\t\t\t%d] Name: %-20s\tScore: %d\n" RESET, num, Top[j].names, Top[j].scores);
            num++;
        }
        else
        {
            printf("\t\t\t\t%d] Name: %-20s\tScore: %d\n", num, Top[j].names, Top[j].scores);
            num++;
        }
    }
}
void print_top_10_players()
{
    print_shape_Top10();
    printf("\n\n");
    read_and_sor_from_file();
    print_top10();
    printf("\n\nEnter 1 to Back\n");
    scanf("%d",&ch);
    while (ch != 1)
    {
        printf("invalid , try again ");
        scanf("%d", &ch);
    }
    if (ch == 1) return ;
}
