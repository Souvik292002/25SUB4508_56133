#include <sys/types.h>
#include <unistd.h>
#include <iostream>


using namespace std;


int main()
{
    pid_t cpid1,cpid2;

    cpid1 = fork();
    if(cpid1 == 0)
    {
        //child process
        for(int i=0;i<10;i++)
        {
            cout<<"[child]"<<i<<endl;
            sleep(1);

        }
    }
    else
    {
        //parent process
        for(int i=0;i<10;i++)
        {
            cout<<"[parent]"<<i<<endl;
            sleep(1);

        }
    }

    return 0;
}


/*
    cpid1 = fork();
    cpid2 = fork();
    cout<<"\nHello World\n";


                    fork() ->cpid1
            p1                  c1
        fork()- cpid2          fork() - cpid2
        cout                   cout

   p2       c2                  p3         c3 
fork()      fork()              fork()     fork()
cout        cout                cout       cout

cout cout    cout cout      cout  cout     cout cout

*/