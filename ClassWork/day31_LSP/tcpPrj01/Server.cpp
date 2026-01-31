#include <common.h>
#include <Server.h>

void sigHandle(int sigNum)
{
    if(sigNum == SIGINT)
    {
        cout<<"Closing Server socket"<<endl;
        close(serverfd);
        exit(EXIT_SUCCESS);
    }
}