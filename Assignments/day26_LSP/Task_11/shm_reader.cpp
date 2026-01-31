#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666);

    char *data = (char *) shmat(shmid, nullptr, 0);

    std::cout << "Reader: Message read from shared memory:\n";
    std::cout << data << std::endl;

    shmdt(data);
    shmctl(shmid, IPC_RMID, nullptr);

    return 0;
}
