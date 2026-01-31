#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include <string>
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

    // create shared mem using the key for 1024 bytes
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);
    if(shmid == -1)
    {
        perror("shmget");
        return 1;
    }

    char *str2 = (char *)shmat(shmid, (void *)0,0);

      

    cout<<"Data read from shared mem: "<<str2<<endl;

    shmdt(str2);

   // shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
