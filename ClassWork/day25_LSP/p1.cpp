#include <sys/types.h>
#include <unistd.h>
#include <iostream>


using namespace std;


int main()
{
    pid_t pid = getpid();
    pid_t ppid = getppid();


    cout<<"\nMy own PID: "<<pid<<endl;
    cout<<"\nMy Parent PID: "<<ppid<<endl;

    while(1);

    return 0;
}