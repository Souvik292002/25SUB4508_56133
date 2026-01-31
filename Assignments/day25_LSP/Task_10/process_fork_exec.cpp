#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        // Child process
        std::cout << "Child Process: PID = " << getpid() << std::endl;

        char *args[] = {(char *)"ls", (char *)"-l", NULL};
        execvp("ls", args);

        // Executes only if execvp fails
        perror("execvp failed");
    }
    else if (pid > 0) {
        // Parent process
        wait(NULL);
        std::cout << "Parent Process: Child has terminated" << std::endl;
    }
    else {
        // fork failed
        perror("fork failed");
    }

    return 0;
}
