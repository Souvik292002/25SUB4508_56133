/*

Memory segments for a C Program

1. Text Segment: 
    1. comments
    2. code seg. (instructions)
    3. structure, classes (decalartion part)
    4. cpu fetches inst from this seg to execute
2. Data Segment
    1. hold global and static variables
    2. two parts
        a. initialized data seg
            int a=10;
            static int b = 20;
        b. BSS (unitialized data seg) - block started by symbol
            int c; //global scope/variable
            static int d; 
3. Heap
    DMA - dy, mem. allocation
    int *ptr = (int *)malloc(sizeof(int)*5)
    free(ptr); //if free is not done - mem. leaks
    heap grow in opp direction of the stack
4. Stack:
    1. stores local variable
    2. func paramters
    3. return address of the func calls
    4. stack frames - fucntion
    5. grows opp to heap
    6. if there is no mem left for stack -> stack overflow


    int main()
    {
        int ret = func();
        int a=10;
    }

    int func(int a)
    {
        int v=20;
        int *ptr = (int *)malloc(sizeof(int));
        return 10;
    }


    for(int i=0;i<10;i++)
        printf("\n%d",i);
    register int i;



Storage class

1. auto (c is different and c++ different)
    auto int i=10;
    int a=10;
2. extern 
        decalration/defination of the variable is in some other file
3. static

Based on,
1. Where is the location of the variable (memory layout)
2. how long it will live (lifetime)
3. who can access the variable (scope)
4. how fast it can be accessed



*/


#include <stdio.h>

//extern int STUDENT_CAP;

int val1=101; //global variable

int func1()
{
    static int a=10;
    val1++;
    printf("\nVlaue of val1[func1]=%d\n",val1);
    a++;
    printf("\nVlaue of a[func1]=%d\n",a);
    
}

int func2()
{
    
    
    printf("\nVlaue of val1[func1]=%d\n",val1);
    
}

int main()
{
    //int a[STUDENT_CAP];
    //printf("\nSize of the array: %ld\n", sizeof(a));
    register int i; //stored in reg of cpu
    printf("value of val1=%d\n",val1);
    func1();
    func1();
    func2();
    for(i=0;i<10;i++)
        printf("\ni=%d",i);
    printf("\n\n");
    return 0;

}