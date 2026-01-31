#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
#include <string>
#include <iostream>


#define MSG_SIZE 100

using namespace std;

struct Message
{
    long msg_type;
    char msg_txt[MSG_SIZE];
};


int main()
{
    key_t key = ftok("/home/student/25sub4508_tr01/Classwork/day26/progfile", 65);
    if(key == -1)
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    //create a msg queue and get the id
    int msgid =  msgget(key, IPC_CREAT | 0666);
    if(msgid == -1)
    {
        //perror("msgget");
        
        //exit(EXIT_FAILURE);
        cerr<<"Error creating message queue"<<endl;
        return EXIT_FAILURE;
    }

    
    Message msg;
    /*msg.msg_type = 1;
    string content = "Hello from the sender!";
    strncpy(msg.msg_txt, content.c_str(), MSG_SIZE);
    */
    if(msgrcv(msgid, &msg, sizeof(msg.msg_txt), 1, IPC_NOWAIT)==-1)
    {
        perror("msgrcv");
        return 1;
    }


    cout<<"MSGID: "<<msgid<<endl;
    cout<<"\nMessage Received: "<<msg.msg_txt<<endl;
    return 0;
}   
