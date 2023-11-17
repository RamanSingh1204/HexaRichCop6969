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
int bd,sd;
sd = socket(AF_INET, SOCK_DGRAM,0);
struct sockaddr_in servaddr, cliaddr;
socklen_t serverlen = sizeof(servaddr);
char buffer[1000], message[1000];
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl (INADDR_ANY);
servaddr.sin_port = htons(6969);
bind(sd, (struct sockaddr*)&servaddr, sizeof(servaddr));

while(1){
printf("\nEnter command for execution\n");
fgets(buffer, sizeof(buffer),stdin);
sendto(sd, message, sizeof(message), 0, (struct sockaddr*)&servaddr, serverlen);
printf("Data sent..\n");
recvfrom(sd, message, sizeof(message), 0, (struct sockaddr*)&servaddr, &serverlen);
printf("%s\n",buffer);
}
return 0;
}
