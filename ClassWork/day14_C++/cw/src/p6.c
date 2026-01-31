#include <stdio.h>
#define PI 3.1
#define CUBE(X) (X*X*X)
#define SQUARE(X) ((X)*(X))

//#undef SQUARE


int main()
{

    printf("\n%f",PI);
    float a=PI;
    printf("\n%f\n\n",PI);
    int area = CUBE(2);
    printf("\n%d",area);
    #ifdef SQUARE
        printf("\n%d\n",SQUARE(10+2));
    #else
        printf("\nSQUARE not defined\n");
    #endif
    

    return 0;
}