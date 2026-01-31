#include <sys/types.h>
#include <unistd.h>
#include <iostream>


using namespace std;


int main()
{
    //pid_t pid; = getpid();
    //pid_t ppid = getppid();
    pid_t cpid;
    cout<<"\nWelcome to System Programming\n"<<endl;

    cpid = fork();

    if(cpid == 0)
    {
        //child process
        sleep(20);
        cout<<"\nI am  child process: "<<endl;
        cout<<"\n[child] cpid = "<<cpid<<endl;
        cout<<"\n[child] pid: "<<getpid()<<endl;
        cout<<"\n[child] My Parent PID: "<<getppid()<<endl;
        
    }
    else
    {
        //parent process
        
        cout<<"\nI am  parent process: "<<endl;
        cout<<"\n[parent] pid: "<<getpid()<<endl;
        cout<<"\n[parent] My Parent PID: "<<getppid()<<endl;
        cout<<"\n[parent] cpid = "<<cpid<<endl;
        
    
    }

    
    cout<<"\nEnd of the program"<<endl;
    return 0;
}

/*

Parent Process:
=========================================
    cpid = fork(); // will return child pid which is > 0
    cpid = 200000
    if(cpid == 0)
    {
        //child process
        cout<<"\nI am  child process: "<<endl;
        cout<<"\n[child] My pid = "<<cpid<<endl;
        cout<<"\n[child] My Parent PID: "<<pid<<endl;
        
    }
    else
    {
        //parent process
        cout<<"\nI am  parent process: "<<endl;
        cout<<"\n[parent] My pid = "<<pid<<endl;
        cout<<"\n[parent] My Parent PID: "<<ppid<<endl;
        cout<<"\n[parent] child pid = "<<cpid<<endl;
        
    
    }

    
    cout<<"\nEnd of the program"<<endl;
    return 0;




Child Process:
=========================================
    cpid = fork(); // return 0 which denotes its a child process
    cpid = 0
    if(cpid == 0)
    {
        //child process
        cout<<"\nI am  child process: "<<endl;
        cout<<"\n[child] My pid = "<<cpid<<endl;
        cout<<"\n[child] My Parent PID: "<<pid<<endl;
        
    }
    else
    {
        //parent process
        cout<<"\nI am  parent process: "<<endl;
        cout<<"\n[parent] My pid = "<<pid<<endl;
        cout<<"\n[parent] My Parent PID: "<<ppid<<endl;
        cout<<"\n[parent] child pid = "<<cpid<<endl;
        
    
    }

    
    cout<<"\nEnd of the program"<<endl;
    return 0;





*/