#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(void){

    unsigned char ip[4]={0x1,0x0,0,0x7f};
    uint32_t test_ip=0;
    memcpy(&test_ip,ip,4);
    test_ip = ntohl(test_ip);//将网络字节序的IP转换成本机的字节序
    char myip[16]={0};
    inet_ntop(AF_INET,&test_ip,myip,16);
    std::cout << "my_ip " << myip << std::endl;

    return 0;
}