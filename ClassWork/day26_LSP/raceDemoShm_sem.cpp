#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <iostream>


using namespace std;

union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void sem_lock(int semid)
{
    struct sembuf sb = {0,-1,0};
    semop(semid, &sb, 1);
}


void sem_unlock(int semid)
{
    struct sembuf sb = {0,1,0};
    semop(semid, &sb,1);
}


int main()
{
    key_t key = ftok("shm_race_demo", 75);
    int shmid = shmget(key, sizeof(int), IPC_CREAT| 0666);

    int *counter = (int *)shmat(shmid, nullptr, 0);
    *counter = 0;

    //setup semaphores
    int semid = semget(key, 1,IPC_CREAT|0666);
    semun u;
    u.val = 1; //initialize semaphore to 1(unlocked)
    semctl(semid,0,SETVAL,u);

    pid_t pid = fork();

    if(pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if(pid >=0 ){
        for(int i=0;i<100000;i++)
        {
            sem_lock(semid); // --critical start
            (*counter)++;
            sem_unlock(semid);// --critical end
        }
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
        cout<<"\nExpected Value: 200000"<<endl;

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