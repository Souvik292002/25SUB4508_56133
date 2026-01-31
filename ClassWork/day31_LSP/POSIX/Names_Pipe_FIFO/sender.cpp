#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>

#define FIFO_PATH "/tmp/my_fifo"

int main() {
    const char* message = "Hello from Sender (Named Pipe FIFO)";

    int fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) {
        perror("Sender: open");
        return 1;
    }

    write(fd, message, strlen(message) + 1);
    std::cout << "Sender: Message sent successfully\n";

    close(fd);
    return 0;
}
