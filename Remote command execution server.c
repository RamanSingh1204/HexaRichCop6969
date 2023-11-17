#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
int main(){
int sd;
sd = socket(AF_INET, SOCK_DGRAM,0);
struct sockaddr_in servaddr, cliaddr;
socklen_t clilen = sizeof(cliaddr);
char buffer[1000], message[] = "Command is Executed !!";
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl (INADDR_ANY);
servaddr.sin_port = htons(6969);
bind(sd, (struct sockaddr*)&servaddr, sizeof(servaddr));

while(1){
bzero(buffer,sizeof(buffer));
recvfrom(sd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cliaddr, &clilen);
system(buffer);
printf("Command Executed...%s\n",buffer);
sendto(sd, message, sizeof(message), 0 , (struct sockaddr*)&cliaddr, clilen);
}
close(sd);
return 0;
}
