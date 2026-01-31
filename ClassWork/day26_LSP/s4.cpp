#include <sys/ipc.h>
#include <sys/sem.h>
#include <iostream>

using namespace std;

union semun{
    int val;
};


int main()
{
    key_t key = ftok("semfile", 65);
    int semid = semget(key,1,IPC_CREAT|0666);

    union semun arg;

    arg.val = 1;

    semctl(semid, 0, SETVAL, arg);

    sembuf sb = {0,-1,0};
    semop(semid,&sb, 1);
    cout<<"Critical Section\n";
    sb.sem_op = 1;
    semop(semid, &sb, 1);
   // semctl(semid,0,IPC_RMID);

    return 0;
}