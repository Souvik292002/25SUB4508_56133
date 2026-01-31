#include <common.h>
#include <Emp.h>

char Menu[] = "\n\tPress,\n\t1. Write to Server\n\t2. Read from Server\n\t3. Exit\n\tChoice: ";

int main(int argc, char *argv[])
{
	MySocket S;
	int sfd = S.conn_c(argv);
	//read&write
	//char buff[MAX_BUFF];
	// read(sfd, buff, MAX_BUFF);
	// cout<<"\nClient Received: "<<buff<<endl;
	// memset(buff,'\0', MAX_BUFF);
	// cout<<"\nEnter a message: ";
	// fgets(buff, MAX_BUFF, stdin);
	// write(sfd,buff, strlen(buff));

	Emp E;
	vector<Emp>V_Emp;
	int ch;
	int flag=0;
	int sizeV=0;
	while(1){
			cout<<Menu;
			cin>>ch;
			vector<Emp>::iterator it;
			switch(ch)
			{
				case 1:
					write(sfd,"1",strlen("1"));
					memset(&E,0,sizeof(Emp));
					E.setEmp();
					write(sfd,&E,sizeof(Emp));
					break;
				case 2:
					write(sfd,"2",strlen("2"));
					memset(&E,0,sizeof(Emp));
					
					//read(sfd, &E, sizeof(Emp));
					read(sfd,&sizeV,sizeof(int));
					cout<<sizeV<<endl;
					V_Emp.resize(sizeV);
					sleep(1);
					read(sfd, &V_Emp.front(), (sizeof(Emp)*V_Emp.size())*sizeof(V_Emp.front()));
					// E.display();
					
					for(it=V_Emp.begin();it!=V_Emp.end();it++)
						it->display();
					break;
				case 3:
					flag = 1;
					break;
				default:
					cout<<"Enter the correct Choice"<<endl;
			}
			if(flag == 1)
				break;
		}
	
	

	S.closesfd();
	return 0;
}