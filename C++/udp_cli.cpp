#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>


int main(void){

    struct sockaddr_in server;
    socklen_t s_size;
    // char *msg="hello guangzhou";
    char msg2[128]={0};
    char msg3[128]={0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18};
    int fd = socket(AF_INET,SOCK_DGRAM ,0);
    if(fd<0){
        printf("socket error\n");
    }
    server.sin_family = AF_INET;
    server.sin_port=htons(56530);
    // server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_addr.s_addr =htons(INADDR_ANY);
    // inet_pton(AF_INET,"10.1.10.1",&server.sin_addr);
    // inet_pton(AF_INET,"172.31.0.200",&server.sin_addr);


    s_size = sizeof(struct sockaddr);
    // while(1){
        sendto(fd,msg3,128,0,(struct sockaddr *)&server,sizeof(server));
    //     sleep(1);
    // }
    

    // recvfrom(fd,msg2,sizeof(msg2),0,(struct sockaddr*)&server,&s_size);
    // char ip[16]={0};
    // inet_ntop(AF_INET,&server.sin_addr,ip,16);
    // printf("%s\n",ip);

    // printf("this is from server:%s\n",msg2);


    close(fd);


    return 0;
}
