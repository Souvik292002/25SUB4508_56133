#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
using namespace std;


int main()
{
    int p1[2];
    int p2[2];
    pipe(p1);
    pipe(p2);
    pid_t cpid;
    char buff_r[1024] = {'\0',};
    char buff_w[1024] = {'\0',};

   
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
        close(p1[0]);
        close(p2[1]);
        cout<<"p1[1]: "<<p1[1]<<" \tp2[0]: "<<p2[0]<<endl;
        cout<<"p1[0]: "<<p1[0]<<" \tp2[1]: "<<p2[1]<<endl;
        strcpy(buff_w,"\n[child]Message from the child\n");
        write(p1[1], buff_w, strlen(buff_w));
        read(p2[0],buff_r,sizeof(buff_r));
        cout<<"\n[child] buff: "<<buff_r<<endl;
        
    }
    else
    {
        //parent process
       // wait(0);
        cout<<"\nThis is Parent"<<endl;
        close(p1[1]);
        close(p2[0]);
        cout<<"p1[1]: "<<p1[1]<<" \tp2[0]: "<<p2[0]<<endl;

        cout<<"p1[0]: "<<p1[0]<<" \tp2[1]: "<<p2[1]<<endl;
        strcpy(buff_w,"\n[parent]Message from the parent\n");
        read(p1[0],buff_r,sizeof(buff_r));
        cout<<"\n[parent] buff: "<<buff_r<<endl;
        write(p2[1], buff_w, strlen(buff_w));
        
        

    }

    cout<<"\nEnd of Program\n";

    return 0;
}