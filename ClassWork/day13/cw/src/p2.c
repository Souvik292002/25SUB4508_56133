#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void disp(char [][20], int);

int main()
{

    char cPlayers[5][20]={
                            "Dhoni",
                            "Rohit",
                            "Virat",
                            "Suresh",
                            "Goutham"
                        };

    int i;
    for(i=0;i<5;i++)
        printf("\n%s",cPlayers[i]);
    
    printf("\n%c",cPlayers[0][3]);
    disp(cPlayers, 5);
    printf("\n\n");
    return 0;

}

void disp(char players[][20], int n)
{
    for(int i=0;i<n;i++)
        printf("\n%s",players[i]);
    printf("\n\n");
}