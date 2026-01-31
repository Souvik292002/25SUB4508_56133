#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *Name=NULL;
    int len=0;
    Name = (char *)calloc(50,sizeof(char));
    if(Name==NULL)
    {
        printf("\nUnable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    scanf("%s",Name);
    printf("\nName: %s\n\n",Name);

    free(Name);
    return 0;
}