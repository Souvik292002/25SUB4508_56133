#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <semaphore.h>

#define SHM_NAME "/posix_shm"
#define SEM_NAME "/posix_sem"
#define SHM_SIZE 1024

int main() {
    int shm_fd;
    char* shm_ptr;
    sem_t* sem;

    // Open semaphore
    sem = sem_open(SEM_NAME, O_CREAT, 0644, 0);
    if (sem == SEM_FAILED) {
        perror("Receiver: sem_open");
        return 1;
    }

    std::cout << "Receiver: Waiting for data...\n";

    // Wait for sender
    sem_wait(sem);

    // Open shared memory
    shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    if (shm_fd == -1) {
        perror("Receiver: shm_open");
        return 1;
    }

    // Map shared memory
    shm_ptr = (char*)mmap(
        nullptr,
        SHM_SIZE,
        PROT_READ,
        MAP_SHARED,
        shm_fd,
        0
    );

    if (shm_ptr == MAP_FAILED) {
        perror("Receiver: mmap");
        return 1;
    }

    std::cout << "Receiver: Message received -> " << shm_ptr << std::endl;

    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);

    // Cleanup
    shm_unlink(SHM_NAME);
    sem_close(sem);
    sem_unlink(SEM_NAME);

    return 0;
}
