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

    int rVal = semctl(semid, 0,GETVAL, NULL);
    cout<<"Sem1 returned: "<<rVal<<endl;
    rVal = semctl(semid, 1,GETVAL,0);
    cout<<"Sem2 returned: "<<rVal<<endl;
    
    rVal = semctl(semid, 2,GETVAL,0);
    cout<<"Sem3 returned: "<<rVal<<endl;
    
    rVal = semctl(semid, 3,GETVAL,0);
    cout<<"Sem4 returned: "<<rVal<<endl;
    
    rVal = semctl(semid, 4,GETVAL,0);
    cout<<"Sem5 returned: "<<rVal<<endl;
    




    return 0;
}
