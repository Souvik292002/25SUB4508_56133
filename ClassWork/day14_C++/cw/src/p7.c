#include <stdio.h>

int main()
{

    printf("\nDemo on Predefined Macros\n");
    printf("\nName of file: %s\n",__FILE__);
    printf("\nLine No: %d", __LINE__);
    printf("\nDate: %s",__DATE__);
    printf("\nTime: %s",__TIME__);
    #ifdef __STDC__
        printf("\nStandard C (yes):  %d",__STDC__);
    #else
        printf("\nNo Standard C");
    #endif

    printf("\n\n");
    return 0;
}