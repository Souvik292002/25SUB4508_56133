#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>

#define FIFO_PATH "/tmp/my_fifo"
#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];

    // Create FIFO if it doesn't exist
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        perror("Receiver: mkfifo");
        // Continue if FIFO already exists
    }

    std::cout << "Receiver: Waiting for sender...\n";

    int fd = open(FIFO_PATH, O_RDONLY);
    if (fd == -1) {
        perror("Receiver: open");
        return 1;
    }

    ssize_t bytesRead = read(fd, buffer, BUFFER_SIZE);
    if (bytesRead > 0) {
        buffer[bytesRead] = '\0';
        std::cout << "Receiver: Message received -> " << buffer << std::endl;
    } else {
        perror("Receiver: read");
    }

    close(fd);

    // Remove FIFO
    unlink(FIFO_PATH);

    return 0;
}
