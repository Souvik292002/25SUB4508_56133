/*
SA_RESTART - restarting sys calls

signals interupt blocking syscalls(read,accept,sleep)
EINTR -> syscall restart

*/

#include <iostream>
#include <csignal>
#include <unistd.h>
#include <cstring>


using namespace std;

void handler_sig(int sig)
{
    cout<<"\nSignal: "<<sig<<endl;
    
}


int main()
{
    struct sigaction sa;

    memset(&sa,0,sizeof(sa));
    
    sa.sa_handler = handler_sig;
    sa.sa_flags = SA_RESTART;
    
    sigaction(SIGINT, &sa, nullptr);
    
    char buff[100];
    read(STDIN_FILENO, buff, sizeof(buff));
    cout<<buff<<endl;

    return 0;
}