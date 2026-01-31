#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdexcept>

#define BACKLOG 5
#define BUFFER_SIZE 1024

//custom exception handling
using namespace std;

class SocketException: public runtime_error
{
    public:
        explicit SocketException(const string &msg): runtime_error(msg){}
        
};

class TCPServer
{
private:
    int server_fd;
    int port;
public:
    explicit TCPServer(int port) :server_fd(-1),port(port){}
    ~TCPServer(){
        if(server_fd != -1)
            close(server_fd);
    }

    void createSocket(){
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if(server_fd < 0)
        {
            throw SocketException("Socket creation failed");
        }
        
    }
    void bindSocket()
    {
        sockaddr_in server_addr{};
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(port);

        if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))<0)
        {
            throw("Bind failed");
        }
    }

    void listenSocket()
    {
        if(listen(server_fd,BACKLOG)<0)
        {
            throw SocketException("Listen Failed");
        }
    }

    void start()
    {
        createSocket();
        bindSocket();
        listenSocket();

        cout<<"Server listening on port: "<<port<<endl;

        signal(SIGCHLD, SIG_IGN); // prevent Zombies

        while(true)
        {
            sockaddr_in client_addr{};
            socklen_t client_len = sizeof(client_addr);

            int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);

            if(client_fd < 0)
                continue;
            pid_t pid = fork();

            if(pid == 0)
            {
                close(server_fd);
                handleClient(client_fd);
                exit(EXIT_SUCCESS);
            }
            else if(pid > 0)
            {
                close(client_fd); 
            }
            else
            {
                cerr<<"fork failed"<<endl;
                close(client_fd);
            }
        }
    }

    void handleClient(int client_fd)
    {
        char buffer[BUFFER_SIZE];
        ssize_t byets_read;

        while(true)
        {
            memset(buffer,0,BUFFER_SIZE);
            byets_read = read(client_fd,buffer,BUFFER_SIZE);
            if(byets_read <=0)
            {
                cout<<"Client disconnected (PID "<<getpid()<<" )\n";
                break;
            }
            cout<<"CLient ["<<getpid()<<"]: "<<buffer<<endl;
            string response = "Server ACK: ";
            response += buffer;
            write(client_fd, response.c_str(), response.size());
        }
        close(client_fd);
    }
};


int main()
{

    try{
        TCPServer server(4003);
        server.start();

    }catch(const SocketException &ex){
        cerr<<"Server error: "<<ex.what()<<endl;
    }

    return 0;
}

