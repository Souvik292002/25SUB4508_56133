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
    
    mqd_t mq = mq_open(MQ_NAME, O_RDONLY);
    if(mq == -1)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    char msg[BUFFER_SIZE];

    int b = mq_receive(mq, msg, BUFFER_SIZE, NULL);
    if(b == -1)
    {
        perror("mq_receive");
        exit(EXIT_FAILURE);
    }
    cout<<"message received: "<<msg<<endl;
    mq_close(mq);
    mq_unlink(MQ_NAME);
    return 0;
}