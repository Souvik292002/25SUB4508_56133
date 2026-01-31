#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *data = (char *) shmat(shmid, nullptr, 0);

    std::cout << "Writer: Enter message: ";
    std::cin.getline(data, 1024);

    std::cout << "Writer: Message written to shared memory\n";

    shmdt(data);
    return 0;
}
