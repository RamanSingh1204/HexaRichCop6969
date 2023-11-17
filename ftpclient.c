#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 6969

int main(){
int serverDescriptor = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in servaddr, cliaddr;
char buffer[100], file[1000];
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(PORT);
connect(serverDescriptor, (struct sockaddr*) &servaddr, sizeof(servaddr));
while(1){
printf("File name: ");
scanf("%s", buffer);
send(serverDescriptor, buffer, strlen(buffer)+1, 0);
printf("%s\n", "File Output: ");
recv(serverDescriptor, &file, sizeof(file), 0);
printf("%s", file);
}
return 0;
}
