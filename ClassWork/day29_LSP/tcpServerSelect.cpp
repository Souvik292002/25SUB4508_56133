#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <signal.h>
#include <stdexcept>
#include <vector>



#define BUFFER_SIZE 1024
#define PORT 8080
#define MAX_CLIENTS 10


using namespace std;

class SocketException: public runtime_error
{
    public:
        explicit SocketException(const string &msg): runtime_error(msg){}
        
};


class TCPSelectServer
{
private:
    int listen_fd;
    vector <int> clients;    
public:
    TCPSelectServer(): listen_fd(-1) {}
    ~TCPSelectServer(){
        for(int fd:  clients)
            close(fd);
        if(listen_fd != -1)
            close(listen_fd);
    }

    void setup()
    {
        listen_fd = socket(AF_INET, SOCK_STREAM, 0);
        if(listen_fd<0)
        {
            throw SocketException("Socket creation failed");
        }

        int opt = 1;

        setsockopt(listen_fd, SOL_SOCKET,SO_REUSEADDR, &opt, sizeof(opt));

        sockaddr_in  addr{};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(PORT);
        addr.sin_addr.s_addr = INADDR_ANY;

        if(bind(listen_fd, (struct sockaddr*)&addr, sizeof(addr))<0)
        {
            throw SocketException("Bind Failed");
        }
        if(listen(listen_fd, 5)<0)
            throw SocketException("Listen Failed");
        cout<<"Select Server listening on port: "<<PORT<<endl;
    }

    void run()
    {
        fd_set readfds;

        while(true)
        {
            FD_ZERO(&readfds);
            FD_SET(listen_fd, &readfds);
            int max_fd = listen_fd;

            for(int fd: clients)
            {
                FD_SET(fd,&readfds);
                if(fd > max_fd)
                    max_fd = fd;
            }

            int activity = select(max_fd+1, &readfds, nullptr,nullptr,nullptr);
            if(activity < 0)
                continue;
            
            //new connections activity
            if(FD_ISSET(listen_fd, &readfds)){
                int client_fd = accept(listen_fd, nullptr, nullptr);
                if(client_fd >=0)
                {
                    clients.push_back(client_fd);
                    cout<<"New Client connected"<<endl;
                }
            }
            
            //existing clients
            for(auto it = clients.begin(); it != clients.end();)
            {
                int fd = *it;
                if(FD_ISSET(fd,&readfds))
                {
                    char buffer[BUFFER_SIZE] = {'\0',};
                    int bytes = read(fd, buffer, BUFFER_SIZE);

                    if(bytes <=0)
                    {
                        cout<<"Client discoonected"<<endl;
                        close(fd);
                        it = clients.erase(it);
                        continue;
                    }
                    else{
                        cout<<"Client: "<<buffer;
                        string reply = "ACK: ";
                        reply += buffer;
                        write(fd,reply.c_str(), reply.size());
                    }
                }
                ++it;
            }
        }
    }
    
};


int main()
{

    try{
        TCPSelectServer server;
        server.setup();
        server.run();

    }catch(const SocketException &ex){
        cerr<<"Server error: "<<ex.what()<<endl;
    }

    return 0;
}

