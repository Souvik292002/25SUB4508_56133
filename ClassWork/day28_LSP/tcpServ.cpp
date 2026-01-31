#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <arpa/inet.h> 
#include <unistd.h>

#define PORT 4003
#define MAXBUFF 1024

using namespace std;

int main()
{
    int sd,csd, rVal=0;

    int clientAddrLen=0;

    struct sockaddr_in serv_addr, client_addr;

    char msg[MAXBUFF] = {'\0',};

    sd = socket(AF_INET,SOCK_STREAM, 0);

    if(sd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    cout<<"[server] socket created with sd: "<<sd<<endl;

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");


    rVal = bind(sd,(struct sockaddr *) &serv_addr,  sizeof(serv_addr));

    if(rVal < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    cout<<"[server] bind to 127.0.0.1:4003 is done!"<<endl;

    while(1);
    close(sd);

    return 0;

}




