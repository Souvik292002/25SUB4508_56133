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
    write(1, "SIGINT blocked\n",15);
    
}


int main()
{
    struct sigaction sa, old_sa;

    memset(&sa,0,sizeof(sa));
    memset(&old_sa,0,sizeof(old_sa));
    
    sa.sa_handler = handler_sig;
    
    sigaction(SIGINT, &sa, &old_sa);
    
    sleep(5);
    sigaction(SIGINT, &old_sa, nullptr);
    
    
    write(1, "Handler should be restored but it is not\n", 42);
    while(1) pause();

    return 0;
}