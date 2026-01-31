/*
Formated IO sts: scanf, printf, sscanf, sprintf, vscanf, vprintf

%d - int 
%f - float
%c - char
%s - strings (array of chars)
%ld - long int
%lf - double


%05d 00000 

50

00050

int a;
scanf("%2d", &a);
12345
a=12
temp=345

*/

#include <stdio.h>

int main()
{
    int a;
    int a1=1234567890;
    int a2=12;
    int a3=123;
    int a4=1234;
    int a5=12345;

    int tmp;
    int tmp1;

    //a=12345678

    printf("\nEnter the a value: ");
    scanf("%2d",&a);
    scanf("%2d",&tmp);
    scanf("%d",&tmp1);

    printf("\na=%05d",a);
    printf("\ntmp=%05d",tmp);
    printf("\ntmp1=%05d",tmp1);

    printf("\na1=%05d",a1);
    printf("\na2=%05d",a2);
    printf("\na3=%05d",a3);
    printf("\na4=%05d",a4);
    printf("\na5=%05d",a5);

    printf("\n===========\n");

    printf("\na1=%5d",a1);
    printf("\na2=%5d",a2);
    printf("\na3=%5d",a3);
    printf("\na4=%5d",a4);
    printf("\na5=%5d",a5);

    printf("\n\n");

    return 0;
}