#include <iostream>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define SEM_NAME "/posix_semaphore"

int main() {
    sem_t* sem;

    // Create or open semaphore (initial value = 0)
    sem = sem_open(SEM_NAME, O_CREAT, 0644, 0);
    if (sem == SEM_FAILED) {
        perror("Receiver: sem_open");
        return 1;
    }

    std::cout << "Receiver: Waiting for sender signal...\n";

    // Wait (P operation)
    sem_wait(sem);

    std::cout << "Receiver: Signal received! Proceeding...\n";

    sem_close(sem);
    sem_unlink(SEM_NAME);  // Remove semaphore

    return 0;
}
