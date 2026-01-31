#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <iostream>


using namespace std;


int main()
{
    int i=10;
    pid_t cpid = fork();
    
    if(cpid < 0)
    {
        cerr<<"fork failed"<<endl;
        exit(EXIT_FAILURE);
    }
    else if(cpid == 0)
    {
        //child process
        cout<<"\n[Child Process]"<<endl;
        cout<<"\n[child] pid: "<<getpid()<<endl;
        cout<<"\n[child] exiting....\n";
        cout<<"\n[child] address of i: "<<&i<<endl;
        cout<<"[child] i = "<<i<<endl;
        i=101;
        cout<<"[child] i = "<<i<<endl;
        
       // scanf("%d",&i);
        
        exit(0); // cleanup
    }
    else
    {
        //parent process
        int status;
        wait(&status);
        cout<<"\n[Parent Process]"<<endl;
        cout<<"\n[parent] pid: "<<getpid()<<endl;
        cout<<"\n[parent] address of i: "<<&i<<endl;
        cout<<"\n[parent] i = "<<i<<endl;
        cout<<"\n Status: "<<status<<endl;


        /*
        0000000 status
        1111111 0xff
        ========
        0000000
        */
        if(status & 0xff)
        {
            cout<<"[parent] child has got some signal"<<endl;
        }

       if((int)status/256 == 1)
       {
        cout<<"\nChild exited with the status : "<<(int)status/256;
       } 
       else 
        cout<<"\nChild exited normally\n";
        
    }

    return 0;
}
