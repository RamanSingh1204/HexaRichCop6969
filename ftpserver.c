#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 6969
#define BACKLOG 5

int main(){
int size;
int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in servaddr, cliaddr;
socklen_t clilen;
struct stat statVar;
char buffer[100], file[1000];
FILE *fileptr;
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(PORT);
bind(socketDescriptor, (struct sockaddr*) &servaddr, sizeof(servaddr));
listen(socketDescriptor, BACKLOG);
printf("Server is running...\n");
int clientDescriptor = accept(socketDescriptor, (struct sockaddr*) &cliaddr, &clilen);
while(1){
bzero(buffer, sizeof(buffer));
bzero(file, sizeof(file));
recv(clientDescriptor, buffer, sizeof(buffer), 0);
fileptr = fopen(buffer,"r");
stat(buffer,&statVar);
size = statVar.st_size;
fread(file, sizeof(file), 1, fileptr);
send(clientDescriptor, file, sizeof(file), 0);
}
return 0;
}
