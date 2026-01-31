#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Array{

private:
    T *ptr;
    int size;
public:
    Array() { ptr = nullptr; size=0;}
    void allocSize(int v)
    {
        size = v;
        ptr = new T[size];
    }
    void setValues()
    {
        for(int i=0;i<size;i++)
        {
            cout<<"Enter i="<<i<<" value ";
            cin>>ptr[i];
        }
    }

    void sortAsc()
    {
        for(int i=0;i<size-1;i++)
        {
            for(int j=0;j<size-i-1;j++)
            {
                if(ptr[j] > ptr[j+1])
                {
                    T temp = ptr[j];
                    ptr[j] = ptr[j+1];
                    ptr[j+1] = temp;
                }
            }
        }
    }

    void displayArr()
    {
        for(int i=0;i<size;i++)
            cout<<ptr[i]<<endl;
        
        cout<<endl;
    }

    ~Array()
    {
        //garbage collector
        delete [] ptr;
    }

};


int main()
{
    Array <string>arr;
    arr.allocSize(5);
    arr.setValues();
    arr.displayArr();
    arr.sortAsc();
    arr.displayArr();
    
    return 0;
}