#include <stdio.h>
/*
recursive function

func()
{
    func(); //recursive function
}

*/

int r_func(int );

int main()
{
    int val=10;

    int ret = r_func(val);

    printf("\nRet value: %d\n", ret);

    return 0;

}

int r_func(int n)
{
    
    if(n == 5)
        return 100;
    n = n - 1;
    
    int t = r_func(n);
    printf("\n t=%d \t n=%d\n",t,n);
    return n;
}



/*
main->r_func(n=10)->sf_1

sf_1  n=10 

if(n == 5)
        return 100;//not excute
    n = n - 1; = 9
    
    r_func(9); -> sf_2
    printf("\n n=%d\n",n); n=9
    return n; return 9 9 is returned to main


r_func(9) -sf_2 n=9

if(n == 5)
        return 100;//not excute
    n = n - 1; = 8
    
    r_func(8); -> sf_3
    printf("\n n=%d\n",n); //o/p 8
    return n; return 8


r_func(8) -sf_3 n=8

if(n == 5)
        return 100;//not excute
    n = n - 1; = 7
    
    r_func(7); -> sf_4
    printf("\n n=%d\n",n); //7
    return n; return 7


r_func(7) -sf_4 n = 7

if(n == 5)
        return 100;//not excute
    n = n - 1; = 6
    
    r_func(6); -> sf_5
    printf("\n n=%d\n",n);//
    return n; 6-> sf_3


r_func(6) -sf_4 n = 6

if(n == 5)
        return 100;//not excute
    n = n - 1; = 5
    
    t r_func(5); -> sf_6
    printf("\n n=%d\n",n);// o/p =5
    return n; return 5 -> SF_4



r_func(5) -sf_6 n = 5

if(n == 5)
        return 100;// excuted -> return 100 to sf_5
  

*/



/*
main->r_func()->sf_1

sf_1   

n = 10
return 100


r_func(9) -sf_2

n = 9


r_func(8) -sf_3

n = 8


r_func(7) -sf_4

n = 7

r_func(6) -sf_5

n = 6


r_func(5) -sf_6

n = 5

if(n == 5)
    return 100;





*/


