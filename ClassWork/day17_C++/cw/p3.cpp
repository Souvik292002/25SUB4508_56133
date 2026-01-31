#include <iostream>
using namespace std;
// ./calc + 10 20 

int main(int argc, char *argv[])
{
    int val1, val2;
    char op;
    if(argc != 4)
    {
        cout<<"app args works in following way"<<endl;
        cout<<"./calc op val1 val2"<<endl;
        exit(EXIT_FAILURE);
    }

    op = argv[1][0]; //argv[1] = "+" => '+' '\0'
    val1 = atoi(argv[2]);
    val2 = atoi(argv[3]);

    switch(op)
    {
        case '+':
            cout<<"addition of "<<val1<<" and "<<val2<<" = "<<(val1+val2)<<endl;
            break;
        
        case '-':
            cout<<"Subtraction of "<<val1<<" and "<<val2<<" = "<<(val1-val2)<<endl;
            break;
        
        case '*':
            cout<<"multiplication of "<<val1<<" and "<<val2<<" = "<<(val1*val2)<<endl;
            break;
        
        default:
            cout<<"please supply the correct operator"<<endl;
        
    }

    cout<<"\n=========================\n";

    return 0;
}