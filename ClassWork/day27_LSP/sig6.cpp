/*
SA_RESTART - restarting sys calls

signals interupt blocking syscalls(read,accept,sleep)
EINTR -> syscall restart

*/

#include <iostream>
#include <csignal>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>


using namespace std;

void handler_sig(int sig)
{
    cout<<"\nsig: "<<sig<<endl;
    while(waitpid(-1,nullptr, WNOHANG)> 0);
    
}


int main()
{
    struct sigaction sa;

    memset(&sa,0,sizeof(sa));
    
    sa.sa_handler = handler_sig;
    sa.sa_flags = SA_RESTART;
    
    sigaction(SIGCHLD, &sa, nullptr);
    
    if(fork() == 0)
    {
        cout<<"[child]: "<<getpid()<<endl;
        exit(0);
    }
    while(1) {
        cout<<"[parent]: "<<getpid()<<endl;
        sleep(1);
    }

    return 0;
}