#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
#include <semaphore.h>

#define SHM_NAME "/posix_shm"
#define SEM_NAME "/posix_sem"
#define SHM_SIZE 1024

int main() {
    int shm_fd;
    char* shm_ptr;
    sem_t* sem;

    // Create semaphore (initial value = 0)
    sem = sem_open(SEM_NAME, O_CREAT, 0644, 0);
    if (sem == SEM_FAILED) {
        perror("Sender: sem_open");
        return 1;
    }

    // Create shared memory
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Sender: shm_open");
        return 1;
    }

    // Set shared memory size
    ftruncate(shm_fd, SHM_SIZE);

    // Map shared memory
    shm_ptr = (char*)mmap(
        nullptr,
        SHM_SIZE,
        PROT_WRITE,
        MAP_SHARED,
        shm_fd,
        0
    );

    if (shm_ptr == MAP_FAILED) {
        perror("Sender: mmap");
        return 1;
    }

    // Write data
    const char* message = "Hello from Sender (Shared Memory + Semaphore)";
    strcpy(shm_ptr, message);

    std::cout << "Sender: Data written to shared memory\n";

    // Signal receiver
    sem_post(sem);

    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);
    sem_close(sem);

    return 0;
}
