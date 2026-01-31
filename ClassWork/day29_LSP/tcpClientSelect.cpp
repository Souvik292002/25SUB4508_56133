#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdexcept>


#define BUFFER_SIZE 1024

//custom exception handling
using namespace std;

class SocketException: public runtime_error
{
    public:
        explicit SocketException(const string &msg): runtime_error(msg){}
        
};

class TCPClient
{
private:
    int sock_fd;
    int server_port;
    string server_ip;

public:
    explicit TCPClient(const string &ip, int port) :sock_fd(-1),server_ip(ip),server_port(port){}
    ~TCPClient(){
        if(sock_fd != -1)
            close(sock_fd);
    }

    void createSocket(){
        sock_fd = socket(AF_INET, SOCK_STREAM, 0);
        if(sock_fd < 0)
        {
            throw SocketException("Socket creation failed");
        }
        
    }
    void connectSocket()
    {
        sockaddr_in server_addr{};
        server_addr.sin_family = AF_INET;
        //server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(server_port);

        if(inet_pton(AF_INET, server_ip.c_str(), &server_addr.sin_addr)< 0)
        {
            throw SocketException("Invalid Server IP");
        }
        if(connect(sock_fd, (struct sockaddr *)&server_addr, 
        sizeof(server_addr))< 0)
        {
            throw SocketException("Connection Failed");
        }

    }

    void communicate()
    {
        char buffer[BUFFER_SIZE];

        while(true)
        {
            cout<<"\nEnter message: ";
            string msg;
            getline(cin, msg);

            if(msg == "exit")
                break;
            write(sock_fd, msg.c_str(), msg.size());
            memset(buffer, 0, BUFFER_SIZE);
            read(sock_fd,buffer,BUFFER_SIZE);
            cout<<"Server: "<<buffer<<endl;
        }
    }
    
    void start()
    {
        createSocket();
        connectSocket();
        communicate();
        
    }

    
};


int main()
{

    try{
        TCPClient client("127.0.0.1",8080);
        client.start();

    }catch(const SocketException &ex){
        cerr<<"Client error: "<<ex.what()<<endl;
    }

    return 0;
}

