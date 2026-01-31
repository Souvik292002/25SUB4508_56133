#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
using namespace std;


int main()
{
    int p_fd[2];
    pipe(p_fd);
    pid_t cpid;
    char buff_r[1024] = {'\0',};
    char buff_w[1024] = {'\0',};

    strcpy(buff_w,"\nThis is a cpp programming class\n");
    cpid = fork();

    if(cpid<0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if(cpid == 0)
    {
        //child process
        cout<<"\nThis is child"<<endl;
        write(p_fd[1], buff_w, strlen(buff_w));
        
    }
    else
    {
        //parent process
        wait(0);
        read(p_fd[0], buff_r, sizeof(buff_r));
        cout<<"Read buffer: "<<buff_r<<endl;

    }

    cout<<"\nEnd of Program\n";

    return 0;
}