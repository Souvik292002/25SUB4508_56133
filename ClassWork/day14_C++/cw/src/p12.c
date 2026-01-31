#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    FILE *fp=NULL;
    char line[100];
    
    fp = fopen("./data/Employee.txt","r+");

    if(fp == NULL)
    {
        printf("\nUnable to open the file\n");
        exit(EXIT_FAILURE);
    }

    printf("\nFptr is at %ld", ftell(fp));
    fseek(fp,0,SEEK_SET);
    strcpy(line,"Akansha|56126|F|1000\n");
    fwrite(line,1,strlen(line),fp);
    fwrite(line,1,strlen(line),fp);
    fwrite(line,1,strlen(line),fp);

    printf("\nFptr is at %ld", ftell(fp));
    
    fclose(fp);

    printf("\n\n");

    return 0;
}


