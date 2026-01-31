#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <pthread.h>
#include <mutex>

using namespace std;

pthread_mutex_t bank_acc;

int AccountBal = 0;

void *deposit(void *args)
{
    int amt = *(int *)args;
    pthread_mutex_lock(&bank_acc);
    cout<<"\n[DPT] Bank Bal ="<<AccountBal<<endl;
    sleep(1);
    AccountBal+=amt;
    cout<<"New Bal after DPT = "<<AccountBal<<endl;
    pthread_mutex_unlock(&bank_acc);

    return NULL;
}


void *withdraw(void *args)
{
    int amt = *(int *)args;
    pthread_mutex_lock(&bank_acc);
    cout<<"\n[WD] Bank Bal ="<<AccountBal<<endl;
    sleep(1);
    
    AccountBal-=amt;
    cout<<"New Bal after WD = "<<AccountBal<<endl;
    pthread_mutex_unlock(&bank_acc);


    return NULL;
}

int main()
{
    /*
    char name[20];
    cin>>name;
    cout<<"Hello, "<<name<<endl;
    */

    pthread_t t1,t2,t3,t4;

    pthread_mutex_init(&bank_acc, NULL);

    int dep1 = 500;
    int dep2 = 300;
    int wd1 = 400;
    int wd2 = 600;

    AccountBal = 1000;
    pthread_create(&t1, NULL, deposit,&dep1);
    pthread_create(&t2, NULL, withdraw,&wd1);

    pthread_create(&t3, NULL, deposit,&dep2);
    pthread_create(&t4, NULL, withdraw,&wd2);


    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    
    pthread_mutex_destroy(&bank_acc);
    cout<<"\n==========\n";

    return 0;
}