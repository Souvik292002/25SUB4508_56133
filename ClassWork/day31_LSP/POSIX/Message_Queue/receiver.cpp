#include <iostream>
#include <mqueue.h>
#include <cstring>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define QUEUE_NAME "/posix_msg_queue"
#define MAX_SIZE 1024

int main() {
    mqd_t mq;
    char buffer[MAX_SIZE];

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;

    // Create message queue
    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY, 0644, &attr);
    if (mq == -1) {
        perror("Receiver: mq_open");
        return 1;
    }

    std::cout << "Receiver: Waiting for message...\n";

    ssize_t bytes_read = mq_receive(mq, buffer, MAX_SIZE, nullptr);
    if (bytes_read >= 0) {
        buffer[bytes_read] = '\0';
        std::cout << "Receiver: Message received -> " << buffer << std::endl;
    } else {
        perror("Receiver: mq_receive");
    }

    mq_close(mq);
    mq_unlink(QUEUE_NAME);  // Remove queue

    return 0;
}
