#include <stdio.h>

int main()
{
    int a[3] = {10,20,30};
    int *ptr;

    printf("\na[0]=%d",a[0]);
    printf("\n[using ptr exp] a[0]=%d",*(a+0));
    printf("\n[using ptr exp] a[1]=%d",*(a+1));
    
    
    ptr = &a[0]; //ptr is pointing to BA of arr or arr[0]
    printf("\n[using ptr] a[0]=%d", *ptr);
   // ptr = &*(a+0);

    //ptr = (a+0);
    ptr = a;
    printf("\n[using ptr] a[0]=%d", *ptr);
    ptr++;
    printf("\n[using ptr] a[1]=%d", *ptr);
    ptr++;
    printf("\n[using ptr] a[1]=%d", *ptr);
    ptr--;
    printf("\n[using ptr] a[1]=%d", *ptr);
    ptr -=1; // ptr = ptr -1;
    printf("\n[using ptr] a[1]=%d", *ptr);

    ptr = a;
    printf("\n[ptr expr] a[0]=%d", *(ptr+0));
    printf("\n[ptr expr] a[1]=%d", *(ptr+1));
    printf("\n[ptr expr] a[2]=%d", *(ptr+2));

    printf("\n[ptr as arr] a[0]=%d", ptr[0]);
    printf("\n[ptr as arr] a[1]=%d", ptr[1]);
    printf("\n[ptr as arr] a[2]=%d", ptr[2]);


    
    

    

    /*
    
    BA + (sizeof(dt) * idx_Value)
    
    store = addressof(BA + (sizeof(dt) * idx_Value))

    access = contentsof(BA + (sizeof(dt) * idx_Value))

    a[0] = 10 => 2000 => BA

    printf("%d",a[0]);
    printf("%d",contentsof(2000));

    2000 + (sizeof(int)*idx_value)
    CO(2000 + (4*0)) = CO(2000)
    CO(2000 + (4*1)) = CO(2004)
    CO(2000 + (4*2)) = CO(2008)
    
    

    */
    
    
    printf("\n\n");
    return 0;
}