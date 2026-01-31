#include <common.h>

MySocket::MySocket()
{
	sfd=0;
	strcpy(ipaddr,"0.0.0.0");
	portNo = 0;
}

MySocket::~MySocket()
{
	
}

SA_IN MySocket::getServerAddr()
{
	return server_addr;
}

SA_IN MySocket::getClientAddr()
{
	return client_addr;
}

socklen_t MySocket::getLengthAddr()
{
	return len;
}

int MySocket::getClientSfd()
{
	return csfd;
}

int MySocket::conn_s(char **argv)
{
	len = sizeof(server_addr);
	client_len = sizeof(client_addr);
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sfd<0)
	{
		perror("socket() ");
		_exit(EXIT_FAILURE);
	}
	bzero(&server_addr, sizeof(SA_IN));

	portNo = atoi(argv[2]);
	strcpy(ipaddr, argv[1]);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(portNo);
	server_addr.sin_addr.s_addr = inet_addr(ipaddr);

	cout<<"[+]Server: Socket Created"<<endl;

	if(bind(sfd,(struct sockaddr*)&server_addr,sizeof(struct sockaddr_in))<0)
	{
		perror("bind() ");
		exit(EXIT_FAILURE);
	}

	cout<<"[+]Server: Bind Done!"<<endl;

	if(listen(sfd, 5)==0)
		cout<<"[+]Server: Listening...."<<endl;
	else
		cout<<"[-]Server: Error in listening...."<<endl;

	return sfd;
}


int MySocket::conn_c(char **argv)
{
	len = sizeof(server_addr);
	client_len = sizeof(client_addr);
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sfd<0)
	{
		perror("socket() ");
		_exit(EXIT_FAILURE);
	}
	bzero(&server_addr, sizeof(SA_IN));

	portNo = atoi(argv[2]);
	strcpy(ipaddr, argv[1]);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(portNo);
	server_addr.sin_addr.s_addr = inet_addr(ipaddr);

	cout<<"[+]Client: Socket Created"<<endl;

	if(connect(sfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr_in))<0)
	{
		perror("connect() ");
		exit(EXIT_FAILURE);
	}

	cout<<"[+]Client: Connect to the Server"<<endl;

	return sfd;
}

int MySocket::CAccept()
{
	int clientfd = accept(sfd,(struct sockaddr*)&client_addr, &client_len);
	if(clientfd < 0)
	{
		perror("accept() ");
		exit(EXIT_FAILURE);
	}
	cout<<"[+]Server: Accepted the new Client"<<endl;

	return clientfd;

}

void MySocket::closesfd()
{
	close(sfd);
}

void MySocket::closecsfd()
{
	close(csfd);
}
