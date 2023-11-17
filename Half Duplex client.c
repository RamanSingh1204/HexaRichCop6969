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

int main(){
int sd;
char cliMsg[1000], servMsg[1000];
sd = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in cliaddr, servaddr;
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(6969);
connect(sd, (struct sockaddr*) &servaddr, sizeof(servaddr));
while(1){
recv(sd, servMsg, sizeof(servMsg), 0);
printf("\nServer: %s", servMsg);
printf("\nEnter message:");
scanf("%s",cliMsg);
send(sd, cliMsg, sizeof(cliMsg), 0);
}
close(sd);
return 0;
}
