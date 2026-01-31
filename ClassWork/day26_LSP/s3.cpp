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

    ushort val[6];

    int rVal = semctl(semid, 0,GETALL, val);
    if(rVal == -1)
    {
        perror("semctl");
        return 1;
    }
    for(int i=0;i<nsems;i++)
        cout<<"Value ["<<i<<"] = "<<val[i]<<endl;




    return 0;
}
