#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void disp(char players[][20], int n);
void sortAsc(char players[][20], int n);
void sortDesc(char players[][20], int n);

int main()
{
    char cPlayers[5][20] = {
        "Dhoni",
        "Rohit",
        "Virat",
        "Suresh",
        "Goutham"
    };

    int i;

    printf("Original List:\n");
    disp(cPlayers, 5);
    
    //printf("Character at cPlayers[0][3] = %c\n\n", cPlayers[0][3]);

    
    sortAsc(cPlayers, 5);
    printf("Ascending Order:\n");
    disp(cPlayers, 5);

    
    sortDesc(cPlayers, 5);
    printf("Descending Order:\n");
    disp(cPlayers, 5);

    return 0;
}


void disp(char players[][20], int n)
{
    for (int i = 0; i < n; i++)
        printf("%s\n", players[i]);
    printf("\n");
}


void sortAsc(char players[][20], int n)
{
    char temp[20];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(players[i], players[j]) > 0)
            {
                strcpy(temp, players[i]);
                strcpy(players[i], players[j]);
                strcpy(players[j], temp);
            }
        }
    }
}


void sortDesc(char players[][20], int n)
{
    char temp[20];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(players[i], players[j]) < 0)
            {
                strcpy(temp, players[i]);
                strcpy(players[i], players[j]);
                strcpy(players[j], temp);
            }
        }
    }
}
