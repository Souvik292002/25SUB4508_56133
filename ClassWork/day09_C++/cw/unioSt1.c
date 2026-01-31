/*
unformated: -everthing is a char or string

getc,putc,gets, puts,fgets, fputs, getchar, putchar

*/
#include <stdio.h>


int main()
{
    char ch;

    //ch = getchar();
    ch = fgetc(stdin);

    //putchar(ch);
    putc(ch,stdout);

    
    printf("\n\n");
    return 0;

}
