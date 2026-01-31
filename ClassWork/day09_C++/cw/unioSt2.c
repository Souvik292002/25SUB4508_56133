#include <stdio.h>
#include <string.h>
int main()
{
    char str1[50];

    printf("\nEnter Your Name: ");
    //scanf("%s",str1);
    /*fgets(str1, 49,stdin);
    printf("\nName: %s\n",str1);

    for(int i=0;i<50;i++)
    {
        printf("\n%c = %d",str1[i],str1[i]);
    }

    str1[strlen(str1)-1] = '\0';
    for(int i=0;i<50;i++)
    {
        printf("\n%c = %d",str1[i],str1[i]);
    }
        */
    scanf("%[^\n]s",str1); 
    printf("\nName: %s",str1);
    printf("\n\n");


    return 0;

}