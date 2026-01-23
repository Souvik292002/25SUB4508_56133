#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

#define PORT 4003
#define MAXBUFF 1024

void handle_client(int csd)
{
    char msg[MAXBUFF], reply[MAXBUFF];

    while (1) {
        memset(msg, 0, MAXBUFF);
        int n = read(csd, msg, MAXBUFF);
        if (n <= 0)
            break;

        // Client wants to quit
        if (strcmp(msg, "quit") == 0) {
            strcpy(reply, "[server], bye");
            write(csd, reply, strlen(reply));
            break;
        }

        // Normal echo with server tag
        strcpy(reply, "[server], ");
        strcat(reply, msg);
        write(csd, reply, strlen(reply));
    }

    close(csd);
    exit(0);   // terminate child
}

int main()
{
    int sd, csd;
    struct sockaddr_in serv_addr, client_addr;
    socklen_t clientLen;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(sd, 5);

    cout << "[server] listening on port " << PORT << endl;

    while (1) {
        clientLen = sizeof(client_addr);
        csd = accept(sd, (struct sockaddr*)&client_addr, &clientLen);
        if (csd < 0)
            continue;

        if (fork() == 0) {   // child
            close(sd);       // child doesn't need listener
            handle_client(csd);
        }

        close(csd);          // parent doesn't need client socket
        waitpid(-1, NULL, WNOHANG); // avoid zombies
    }

    close(sd);
    return 0;
}
