#include <iostream>
#include <mqueue.h>
#include <cstring>
#include <fcntl.h>
#include <sys/stat.h>

#define QUEUE_NAME "/posix_msg_queue"
#define MAX_SIZE 1024

int main() {
    mqd_t mq;
    const char* message = "Hello from Sender (POSIX Message Queue)";

    // Open existing queue
    mq = mq_open(QUEUE_NAME, O_WRONLY);
    if (mq == -1) {
        perror("Sender: mq_open");
        return 1;
    }

    if (mq_send(mq, message, strlen(message), 0) == -1) {
        perror("Sender: mq_send");
    } else {
        std::cout << "Sender: Message sent successfully\n";
    }

    mq_close(mq);
    return 0;
}
