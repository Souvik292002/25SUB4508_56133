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

    char msg[1024];// = "This message is written using FIFO";

    //mkfifo(FIFO_NAME, 0666);

    
    fd = open(FIFO_NAME, O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    read(fd, msg, sizeof(msg));
    cout<<"Msg from the FIFO: "<<msg<<endl;
    close(fd);
    cout<<"\nMsg is read from the FIFO"<<endl;

    cout<<endl;
    return 0;
}