#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    FILE *fp=NULL;
    char line[100];
    
    fp = fopen("./data/Employee.txt","r");

    if(fp == NULL)
    {
        printf("\nUnable to open the file\n");
        exit(EXIT_FAILURE);
    }

    printf("\nFptr is at %ld", ftell(fp));
    fread(line,1,50,fp);
    printf("\nLine: %s",line);

    fseek(fp,0,SEEK_END);
    printf("\nFptr is at %ld", ftell(fp));

    fseek(fp,-10,SEEK_END);
    printf("\nFptr is at %ld", ftell(fp));

    fread(line,1,50,fp);
    printf("\nLine: %s",line);

    fseek(fp,0,SEEK_SET);
    printf("\nFptr is at %ld", ftell(fp));
    //strcpy(line,"Akansha|56126|F|100000");

    

    /*
    //fscanf(fp,"%[^\n]s",line);
    fgets(line,sizeof(line)-1,fp);
    printf("\nFptr is at %ld", ftell(fp));
    printf("\n%s",line);
    //fscanf(fp,"%[^\n]s",line);
    fgets(line,sizeof(line)-1,fp);
    
    printf("\nFptr is at %ld", ftell(fp));
    printf("\n%s",line);
    */

    // while(fgets(line,sizeof(line)-1,fp)!=NULL)
    // {
    //     printf("\nFptr is at %ld", ftell(fp));
    //     printf("\n%s",line);
    
    // }
    
    fclose(fp);

    printf("\n\n");

    return 0;
}


