#include <iostream>
using namespace std;

template <typename T>
int countGreater(T arr[], int size, T value)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > value)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int intArr[] = {1, 5, 8, 3, 10};
    int intSize = 5;

    cout << countGreater(intArr, intSize, 4) << endl;

    double doubleArr[] = {2.5, 6.1, 1.9, 7.8};
    int doubleSize = 4;

    cout << countGreater(doubleArr, doubleSize, 3.0) << endl;

    return 0;
}
