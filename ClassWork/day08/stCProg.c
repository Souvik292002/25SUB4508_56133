/*
Documentation - what is the program or file about
1. Description - Explains the struture of C Program
2. Modules/functions - any function, write about the i/o data flow
3. DOC/DOM:
4. Author: BT
5. Version: 0.1 - draft, 1.0 - realeased version(stable version)
*/

/*
Desc: Calc Program
Modules: int add (int, int) - add adds two integer and return 
         result of sum of two integers as integer
DOC/DOM: 22-12-2025
Author: BT
Version: 0.1v
*/

//Link Section
#include <stdio.h>

//Defination section
#define PI 3.142

//Global Declartion section
int add(int, int); //prototyping of function
int result=0;

//main function / driver code

int main()
{
    //local dec section
    int v1,v2;
    
    //executable section
    scanf("%d%d",&v1,&v2);
    printf("\nHello World!\n");

    result = add(v1,v2); //calling a func and res is stored

    printf("\nAddition of two numbers: %d\n", result);

    return 0; // exit status of the program
}

// Defination of the function
int add(int val1, int val2)
{
    //local dec. section
    int r;

    //executable sec
    r = val1+val2;

    return r;
}

