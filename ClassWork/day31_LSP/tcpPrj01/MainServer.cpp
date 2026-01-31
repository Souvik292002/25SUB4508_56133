#include <common.h>
#include <Emp.h>
#include <iterator>

int serverfd;
void sigHandle(int sigNum)
{
    if(sigNum == SIGINT)
    {
        cout<<"Closing Server socket"<<endl;
        close(serverfd);
        exit(EXIT_SUCCESS);
    }
}


int main(int argc, char *argv[])
{
	int sfd=0;
	
	MySocket S;
	signal(SIGINT,sigHandle);
	pid_t cpid=0;
	sfd = S.conn_s(argv);
	serverfd = sfd;
	while(1){
		int csfd = S.CAccept();
		if((cpid = fork())==0)
		{
			S.closesfd();
			Emp E;
			vector<Emp>V_Emp;
			char buff[MAX_BUFF];
			// strcpy(buff,"Welcome to the Server");
			// write(csfd, buff, strlen(buff));
			memset(buff, '\0', MAX_BUFF);
			// read(csfd, buff, MAX_BUFF);
			// cout<<"From Client: "<<buff<<endl;
			// read(csfd, &E, sizeof(Emp));
			
			read(csfd,buff,MAX_BUFF);
			switch(atoi(buff))
			{
				case 1:
					read(csfd, &E, sizeof(Emp));
					E.display();
					Write2File(E);
					break;

				case 2:
					ReadFFile(V_Emp);
					// vector<Emp>::iterator it;
					// cout<<"Size: "<<V_Emp.size()<<endl;
					// for(it=V_Emp.begin();it!=V_Emp.end();it++)
					// 	it->display();
					int sizeV = V_Emp.size();
					write(csfd,&sizeV,sizeof(int));
					//sleep(2);
					write(csfd,&V_Emp.front(),(sizeof(Emp)*V_Emp.size())*sizeof(V_Emp.front()));
					break;
			}
			
			close(csfd);
			exit(EXIT_SUCCESS);
		}
		close(csfd);
	}
	S.closesfd();
	return 0;
}