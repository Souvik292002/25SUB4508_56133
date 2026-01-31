#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include <string>
#include <iostream>


using namespace std;


class Employee{
    int id;
    char name[200];
public:
    void setValues(int i, const char * n) {id = i; strcpy(name,n);}
    void disp(){ cout<<"\nid: "<<id<<"\nname: "<<name<<endl;}
    Employee () {}
    
};

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

    //Employee e1(101,"bhima");

    Employee *e = (Employee *)shmat(shmid, (void *)0,0);

    e->setValues(101,"bhima");
    

    cout<<"Data written to shared mem: "<<endl;

    shmdt(e);

   // shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
