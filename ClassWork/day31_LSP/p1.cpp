#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

#define MQ_NAME "/myNewMsg2_mq"
#define BUFFER_SIZE 128

using namespace std;

int main() {
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = BUFFER_SIZE;
    attr.mq_curmsgs = 0;
    
    mqd_t mq = mq_open(MQ_NAME, O_CREAT | O_WRONLY, 0666, &attr);
    if(mq == -1)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    char msg[] = "Hello World";

    int b = mq_send(mq, msg, strlen(msg)+1, 0);
    if(b == -1)
    {
        perror("mq_send");
        exit(EXIT_FAILURE);
    }
    cout<<"message sent"<<endl;
    mq_close(mq);
    return 0;
}