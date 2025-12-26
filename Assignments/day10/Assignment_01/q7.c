//7. Write a Program in C to Print all natural numbers up to N without using a semi-colon. 
 
// C program to print 
// all natural numbers 
// upto N without using semi-colon 
#include <stdio.h> 
#define N 10 
 
int main(int val) 
{ 
    if (val <= N && printf("%d ", val) && main(val + 1)) { 
    } 
} 