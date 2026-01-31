#include <stdio.h>


void getElements(int *ptr, int len);
void dispElements(int *ptr, int len);
void sortAsc(int *ptr, int len);
void sortDesc(int *ptr, int len);

int main()
{
    int arr[100], len;

    
    printf("Enter number of elements: ");
    scanf("%d", &len);


    getElements(arr, len);

    printf("\nOriginal Array:\n");
    dispElements(arr, len);

    sortAsc(arr, len);
    printf("\nArray in Ascending Order:\n");
    dispElements(arr, len);

    sortDesc(arr, len);
    printf("\nArray in Descending Order:\n");
    dispElements(arr, len);

    return 0;
}

void getElements(int *ptr, int len)
{
    int i;
    printf("Enter %d elements:\n", len);

    for (i = 0; i < len; i++)
    {
        
        scanf("%d", (ptr + i));
    }
}


void dispElements(int *ptr, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}


void sortAsc(int *ptr, int len)
{
    int i, j, temp;

    for (i = 0; i < len - 1; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (*(ptr + i) > *(ptr + j))
            {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
}


void sortDesc(int *ptr, int len)
{
    int i, j, temp;

    for (i = 0; i < len - 1; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (*(ptr + i) < *(ptr + j))
            {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
}
