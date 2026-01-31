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

    char *str1 = (char *)shmat(shmid, (void *)0,0);

    string data;
    cout<<"\nEnter Message: ";
    getline(cin, data);

    strncpy(str1,data.c_str(), 1024);

    cout<<"Data writtern to shared mem: "<<str1<<endl;

    shmdt(str1);


    return 0;
}
