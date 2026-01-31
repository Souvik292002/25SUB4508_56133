/*
Strings:
collections of characters and ended with a null char
in-built libs: strcmp, strcpy, strlen...
include file: #include <string.h>


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[20] = "ABCDE";
    char s2[20] = "ABCD";
    char s3[40];
    char *strPtr=NULL;   
    int len = 0;
    int ret=0;

    len = strlen(s1);

    printf("\nLength of %s = %d\nSIZEof s1 = %ld",s1,len,sizeof(s1));


    ret = strcmp(s1,s2);
    if (ret == 0)
        printf("\ns1 and s2 are equal");
    else if (ret < 0)
        printf("\ns1 is less than s2");
    else
        printf("\ns1 is greater than s2");

    printf("\nret=%d",ret);

    ret = strncmp(s1,"CBCDE",1);


    printf("\nret=%d",ret);

    memset(s3,'P',sizeof(s3));

    strcpy(s3, s1);

    printf("\ns3=%s",s3);
    printf("\n\n");
    for(int i=0;i<40;i++)
        putchar(s3[i]);

    memset(s3,'\0',sizeof(s3));
    

    strncpy(s3,s1,3);
    printf("\ns3=%s",s3);
    
    strcpy(s1,"Hello");
    strcpy(s2,"World");

    printf("\ns1=%s\ts2=%s",s1,s2);
    strcat(s1," ");
    strcpy(s3,strcat(s1,s2));
    

    printf("\ns1=%s\ts2=%s",s1,s2);
    printf("\ns3=%s",s3);

    strPtr = strchr(s3,'z');
    if(strPtr != NULL)
        printf("\nstrPtr = %s\n",strPtr);
    else
        printf("\nCharacter not found\n");


    strPtr = NULL;
    strPtr = strstr(s3, "orl");
    printf("\nstrPtr = %s\n",strPtr);


    char *token=NULL;
    char name[50];
    char age[4];
    char g[2];
    char phone[20];
    char sal[20];
    char place[30];

    strcpy(s3,"bhima|47|M|88888|45000|Banglore");
    /*
    token = strtok(s3,"|");

    
    printf("\nToken = %s", token);
    token = strtok(NULL, "|");
    printf("\nToken = %s", token);
    token = strtok(NULL, "|");
    printf("\nToken = %s", token);
    token = strtok(NULL, "|");
    printf("\nToken = %s", token);
    token = strtok(NULL, "|");
    printf("\nToken = %s", token);

    token = strtok(NULL, "|");
    printf("\nToken = %s", token);
    token = strtok(NULL, "|");
    printf("\nToken = %s", token);
    */

    /*
    token = strtok(s3,"|");

    while(token != NULL)
    {
        printf("\nToken = %s", token);
        token = strtok(NULL, ",");
    }
    */

    token = strtok(s3,"|");


    strcpy(name, token);
    token = strtok(NULL, "|");
    strcpy(age, token);
    token = strtok(NULL, "|");
    strcpy(g, token);
    token = strtok(NULL, "|");
    strcpy(phone, token);
    token = strtok(NULL, "|");
    strcpy(sal, token);

    token = strtok(NULL, "|");
    strcpy(place, token);
    
    printf("\nEmployee details are\n");
    printf("\nEmpName: %s",name);
    printf("\nAge: %s",age);
    printf("\nGender: %s",g);
    printf("\nPhone: %s",phone);
    printf("\nSalaray: %s",sal);
    printf("\nLocation: %s",place);
    

    int iAge = atoi(age);
    printf("\nAge (int)=%d",iAge);

    sprintf(age,"Age: %d",46);

    printf("\nage: %s",age);
    printf("\n\n");

    return 0;
}