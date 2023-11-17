#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>

int main(int argc, char * argv[])
{  int bd,sd,ad;
char buff[1024];
struct sockaddr_in cliaddr, servaddr;
socklen_t clilen;
clilen= sizeof(cliaddr);
bzero(&servaddr, sizeof(servaddr));

servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(1999);


sd = socket(AF_INET, SOCK_STREAM,0);
bd = bind(sd,(struct sockaddr*)&servaddr, sizeof(servaddr));

listen(sd,5);
printf("server is running....");

ad = accept(sd, (struct sockaddr*)&cliaddr, &clilen);

while(1)
{ 
bzero(&buff, sizeof(buff));
recv(ad,buff,sizeof(buff),0);
printf ("Message recieved is %s\n", buff);
}
}
