#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <iostream>


using namespace std;


int main()
{
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
        _exit(0);
    }
    else
    {
        //parent process
        cout<<"\n[Parent Process]"<<endl;
        cout<<"\n[parent] pid: "<<getpid()<<endl;
        sleep(30);
        cout<<"\n[parent] exiting after sleep\n";
        
    }

    return 0;
}
