#include <iostream>
#include <csignal>
#include <unistd.h>
#include <cstring>


using namespace std;

void handler_sig(int sig, siginfo_t *info, void *)
{
    cout<<"\nSignal: "<<sig<<endl;
    cout<<"\nSent by PID: "<<info->si_pid<<endl;
}


int main()
{
    struct sigaction sa;

    memset(&sa,0,sizeof(sa));
    
    sa.sa_sigaction = handler_sig;
    sa.sa_flags = SA_SIGINFO;
    
    sigaction(SIGUSR1, &sa, nullptr);
    
    while(1){
        cout<<"\nServer running.....PID: "<<getpid()<<endl;
        sleep(1);
    }

    return 0;
}