#include <iostream>
#include <csignal>
#include <unistd.h>
#include <cstring>


using namespace std;

void handler_sigterm(int sig)
{
    cout<<"\nSIGTERM recevied: Shutting down gracefully...."<<endl;
}

void handler_sigint(int sig)
{
    cout<<"\nSIGINT recevied: Restarting Application...."<<endl;
}

int main()
{
    struct sigaction sa_t,sa_i;

    memset(&sa_t,0,sizeof(sa_t));
    memset(&sa_i,0,sizeof(sa_i));

    sa_t.sa_handler = handler_sigterm;
    sa_i.sa_handler = handler_sigint;
    
    sigaction(SIGTERM, &sa_t, nullptr);
    sigaction(SIGINT, &sa_i, nullptr);

    while(1){
        cout<<"\nServer running.....PID: "<<getpid()<<endl;
        sleep(3);
    }

    return 0;
}