#include <iostream>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define SEM_NAME "/posix_semaphore"

int main() {
    sem_t* sem;

    // Open existing semaphore
    sem = sem_open(SEM_NAME, O_CREAT, 0644, 0);
    if (sem == SEM_FAILED) {
        perror("Sender: sem_open");
        return 1;
    }

    std::cout << "Sender: Sending signal...\n";

    // Signal (V operation)
    sem_post(sem);

    std::cout << "Sender: Signal sent successfully\n";

    sem_close(sem);
    return 0;
}
