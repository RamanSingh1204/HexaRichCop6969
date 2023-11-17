#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(){
int sd, cd;
struct sockaddr_in servaddr, cliaddr;
socklen_t clilen;
char servMsg[1000], cliMsg[1000];
pid_t cpid;
bzero(&servaddr, sizeof(servaddr));
sd = socket(AF_INET, SOCK_STREAM, 0);
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(6969);
bind(sd, (struct sockaddr*) &servaddr, sizeof(servaddr));
listen(sd, 5);
cd = accept(sd, (struct sockaddr*) &cliaddr, &clilen);
cpid = fork();
if(cpid == 0){
while(1){
bzero(&servMsg, sizeof(servMsg));
printf("\nEnter message: ");
fgets(servMsg, 1000, stdin);
send(cd, servMsg, sizeof(servMsg), 0);
}
}
else{
while(1){
bzero(&cliMsg, sizeof(cliMsg));
printf("\nClient message: ");
recv(cd, cliMsg, sizeof(cliMsg), 0);
printf("%s", cliMsg);
}
}
return 0;
}
