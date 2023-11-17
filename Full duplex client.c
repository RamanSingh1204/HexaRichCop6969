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
char servMsg[1000], cliMsg[1000];
pid_t cpid;
struct sockaddr_in servaddr, cliaddr;
bzero(&servaddr, sizeof(servaddr));
sd = socket(AF_INET, SOCK_STREAM, 0);
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(6969);
cd = connect(sd, (struct sockaddr*) &servaddr, sizeof(servaddr));
cpid = fork();
if(cpid == 0){
while(1){
bzero(&cliMsg, sizeof(cliMsg));
printf("\Enter message: ");
fgets(cliMsg, 1000, stdin);
send(sd, cliMsg, sizeof(cliMsg), 0);
}
}
else{
while(1){
bzero(&servMsg, sizeof(servMsg));
printf("\nMessage received: ");
recv(sd, servMsg, sizeof(servMsg), 0);
printf("%s", servMsg);
}
}
return 0;
}
