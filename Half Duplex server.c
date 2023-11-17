#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define max 1000
#define backlog 5

int main(){
int sd, cd;
char servMsg[100], cliMsg[100];
sd = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in servaddr, cliaddr;
int clilen = sizeof(cliaddr);
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons (6969);
bind(sd, (struct sockaddr*) &servaddr, sizeof(servaddr));
listen(sd, backlog);
cd = accept(sd, NULL, NULL);
while(1){
printf("Enter message:\n");
scanf("%s", servMsg);
send(cd, servMsg, sizeof(servMsg), 0);
recv(cd, &cliMsg, sizeof(cliMsg), 0);
printf("\nClient: %s", cliMsg);
}
close(sd);
}
