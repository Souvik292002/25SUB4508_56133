#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

using namespace std;


int main()
{
    cout<<"\nWelcome\n";
    if(fork()==0)
    {
        //child processs
        execl("/home/student/25sub4508_tr01/Classwork/day25/p9", "p9",
    "bhima", "shankar", "47", "88888", (char *)0);

    }
    else
    {
        //parent process
        wait(0);

    }

    

    //execl("/usr/bin/date", "/usr/bin/date",(char *)0);
   // execl("/home/student/25sub4508_tr01/Classwork/day25/p9", "p9",(char *)0);
    /*execl("/home/student/25sub4508_tr01/Classwork/day25/p9", "p9",
    "bhima", "shankar", "47", "88888", NULL);
    */

    //execl("/usr/bin/ls", "ls","-la", NULL);

    cout<<"\nEnd of the program p10"<<endl;

    return 0;
}

/*
./p10 -> ram -> cpu
./p9 -ram -cpu

*/