#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <cstring>

#include <iostream>

using namespace std;


int main()
{
    key_t key = ftok("/home/student/25sub4508_tr01/Classwork/day26/progfile", 65);
    if(key == -1)
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    int nsems = 5;
    int semid = semget(key, nsems, IPC_CREAT | 0666);

    cout<<"semid: "<<semid<<endl;

    int rVal = semctl(semid, 0,SETVAL,1001);
    rVal = semctl(semid, 1,SETVAL,2001);
    rVal = semctl(semid, 2,SETVAL,3001);
    rVal = semctl(semid, 3,SETVAL,4001);
    rVal = semctl(semid, 4,SETVAL,5001);
    




    return 0;
}
