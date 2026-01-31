#include <iostream>
#include <cstring>
#include <thread>
#include <unistd.h>
#include <vector>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdexcept>


#define BUFFER_SIZE 1024
#define SERVER_PORT 4003

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
    string server_ip;
public:
    explicit TCPClient(const string &ip) : 
    sock_fd(-1), server_ip(ip){}

    ~TCPClient(){
        if(sock_fd!=-1)
            close(sock_fd);
    }

    void connectToServer()
    {
        sock_fd = socket(AF_INET, SOCK_STREAM,0);
        if(sock_fd  < 0)
            throw SocketException("Socket Creation Failed");
        
        sockaddr_in server_addr {};
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(SERVER_PORT);

        if(inet_pton(AF_INET,server_ip.c_str(), &server_addr.sin_addr) <= 0)
            throw SocketException("Invalid server IP address");
        
        if(connect(sock_fd, (sockaddr *)&server_addr, sizeof(server_addr))<0)
            throw SocketException("Connection to Server failed");
        
        cout<<"Connected to the Server at "<<server_ip<<":"<<SERVER_PORT<<"\n";

    }

    void startCommunication()
    {
        char send_buf[BUFFER_SIZE];
        char recv_buf[BUFFER_SIZE];

        while(true)
        {
            cout<<"\nClient: ";
            cin.getline(send_buf, BUFFER_SIZE);
            if(strcmp(send_buf, "exit")==0)
            {
                cout<<"Closing connection.....\n";
                break;
            }

            ssize_t s_bytes = write(sock_fd, send_buf, strlen(send_buf));
            if(s_bytes <=0)
                throw SocketException("Failed to send data...");
            
            memset(recv_buf, 0, BUFFER_SIZE);
            ssize_t r_bytes = read(sock_fd, recv_buf, BUFFER_SIZE);
            
            if(r_bytes <=0)
                throw SocketException("Failed to receive data (Server Disconnection)...");
            
            cout<<recv_buf;
        }
    }
};


int main(int argc, char *argv[])
{
    if(argc != 2){
        cerr<<"Usage: "<<argv[0]<<" <server_ip>\n";
        return -1;
    }

    try{
        TCPClient client(argv[1]);
        client.connectToServer();
        client.startCommunication();
    }
    catch (const SocketException&e)
    {
        cerr<<"Client Error: "<<e.what()<<"\n";
    }

    return 0;
}