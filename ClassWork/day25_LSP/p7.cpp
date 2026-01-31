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
        _exit(EXIT_FAILURE); //no cleanup
    }
    else
    {
        //parent process
        int status;
        wait(&status);
        cout<<"\n[Parent Process]"<<endl;
        cout<<"\n[parent] pid: "<<getpid()<<endl;
        if(WIFEXITED(status))
        {
            cout<<"\nChild exited with status: "<<WEXITSTATUS(status)<<endl;
        }
        
        
    }

    return 0;
}
