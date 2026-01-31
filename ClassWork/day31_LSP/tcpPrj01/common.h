#ifndef _COMMON_H_
#define _COMMON_H_
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/signal.h>

#define MAX_BUFF 1024
#define PORT 4005


using namespace std;

typedef struct sockaddr_in SA_IN;


class MySocket
{
public:
	MySocket();
	~MySocket();
	int conn_s(char **);
	int conn_c(char **);
	SA_IN getServerAddr();
	SA_IN getClientAddr();
	socklen_t getLengthAddr();
	// int ReadFromS(char *);
	// int WriteToS(char *);
	// int ReadFromC(char *);
	// int WriteToC(char *);
	int getClientSfd();
	int CAccept();
	void closesfd();
	void closecsfd();

private:
	int sfd;
	int csfd;
	int portNo;
	char ipaddr[20];
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t len, client_len;
};




#endif