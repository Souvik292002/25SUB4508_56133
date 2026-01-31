#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

int menuDisp()
{
    int ch;
    cout<<"\nPress,"<<endl;
    cout<<"\n1. Addition"<<endl;
    cout<<"\n2. Subtraction"<<endl;
    cout<<"\n3. Multiplication"<<endl;
    cout<<"\n4. Exit"<<endl;
    cin>>ch;   
    return ch;
}


void handle_signal(int);

void mainLoop()
{
    signal(SIGINT,handle_signal);
    while(1){
        // cout<<"\nRunning.... PID: "<<getpid()<<endl;
        // sleep(2);
        switch(menuDisp())
        {
            case 1:
                cout<<"\nAddition"<<endl;
                break;
            case 2:
                cout<<"\nSub"<<endl;
                break;
            case 3:
                cout<<"\nMul"<<endl;
                break;
            case 4:
                cout<<"\nExit"<<endl;
                exit(EXIT_SUCCESS);
                break;
            default:
                cout<<"\nEnter the correct choice"<<endl;            
        }
    }
}

int main()
{

    
    signal(SIGINT,handle_signal);
    mainLoop();
   // signal(SIGINT,handle_signal);

    return 0;
}


void handle_signal(int sig){
    
    if(sig == SIGINT)
    {
        cout<<"\nSIGINT received Ctrl+C \n";
        mainLoop();
        //exit(EXIT_FAILURE);
    }
}