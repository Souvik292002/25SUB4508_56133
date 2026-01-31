#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <iostream>


using namespace std;


int main()
{
    key_t key = ftok("shm_race_demo", 75);
    int shmid = shmget(key, sizeof(int), IPC_CREAT| 0666);

    int *counter = (int *)shmat(shmid, nullptr, 0);
    *counter = 0;

    pid_t pid = fork();

    if(pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<100000;i++)
    {
        (*counter)++;
    }

    if(pid == 0)
    {
        //child process
        shmdt(counter);
        return 0;
    }
    else
    {
        //parent process
        wait(nullptr);
        cout<<"\nFinal Counter: "<<*counter<<endl;
        cout<<"\nExpected Value: 20000"<<endl;

        if(*counter != 200000)
        {
            cout<<"\nResult: Race Condition Detected (Lost "
            <<200000-*counter<<" )"<<endl;
        }

        shmdt(counter);
        shmctl(shmid, IPC_RMID, nullptr);
    }

    return 0;

}