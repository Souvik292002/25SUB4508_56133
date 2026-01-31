#include <sys/types.h>
#include <unistd.h>
#include <iostream>


using namespace std;


int main()
{
    pid_t cpid1,cpid2;

    cpid1 = fork();
    cpid2 = fork();
    fork();

    cout<<"\nHello World\n";

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