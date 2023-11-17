#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<net/if.h>
#include<net/if_arp.h>
#include<sys/ioctl.h>
#include<netinet/if_ether.h>
#include<net/ethernet.h>
int main(){
struct sockaddr_in sin = {0};
struct arpreq myarp = {{0}};
unsigned char *ptr;
char ip[100];
printf("enter the IP");
scanf("%s\n",ip);wa

if(inet_pton(AF_INET,ip, &sin.sin_addr)==0) // use of & in &sin.sin_addr
{ printf("the IP is invalid");
exit(0);
}

int sd = socket(AF_INET, SOCK_STREAM, 0);
memcpy(&myarp.arp_pa , &sin , sizeof(myarp.arp_pa));
strcpy(myarp.arp_dev,"echo");
 
if(ioctl(sd, SIOCGARP, &myarp)==1){
printf("the request is invalid");
exit(0);}

ptr = &myarp.arp_pa.sa_data[0]; // pointer pointing to the first block of macaddress

printf("mac address for the given ip %s is\n",ip);
printf("%p:%p:%p:%p:%p\n", ptr, (ptr+1),(ptr+2),(ptr+3),(ptr+4));

return 0;
}
