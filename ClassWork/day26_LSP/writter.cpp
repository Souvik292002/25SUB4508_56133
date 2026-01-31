#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <iostream>

#define FIFO_NAME "my_fifo"

using namespace std;

int main()
{
    int fd;

    char msg[] = "This message is written using FIFO";

    mkfifo(FIFO_NAME, 0666);

    
    fd = open(FIFO_NAME, O_WRONLY);
    if(fd < 0)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write(fd, msg, sizeof(msg));

    close(fd);
    cout<<"\nMsg is written on the FIFO"<<endl;

    cout<<endl;
    return 0;
}