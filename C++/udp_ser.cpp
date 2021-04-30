#include <iostream>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/udp.h>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

int main(void){

    
    struct epoll_event ev,event[20];
    int efd = epoll_create(256);
    if(efd < 0){
        std::cout << "efd error" << std::endl;
    }

    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t s_size;
    char msg[128]={0};
    int udp_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if(udp_socket < 0){
        std::cout << "socket error" << std::endl;
    }
    memset(&server,0,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port   = htons(56530);
    server.sin_addr.s_addr =htons(INADDR_ANY);

    bind(udp_socket,(struct sockaddr *)&server,sizeof(server));
    s_size = sizeof(client);

    ev.data.fd = udp_socket;
    ev.events  = EPOLLIN;
    epoll_ctl(efd, EPOLL_CTL_ADD,udp_socket,&ev);

    while(1){
        int nfds = epoll_wait(efd,event,20,1000);

        for(int i =0;i<nfds;i++){
            int rfd = event[i].data.fd;
            if(event[i].events & EPOLLIN){
                if(rfd == udp_socket){
                    recvfrom(udp_socket,msg,sizeof(msg),0,(struct sockaddr*)&client,&s_size);
                    char ip[16]={0};
                    inet_ntop(AF_INET,&server.sin_addr,ip,16);
                    printf("ip:%s\n",ip);
                    for(int i =0;i<32;i++){
                        printf("%2x ",msg[i]);
                    }
                    printf("\n");
                }
            }
        }
    }
    close(udp_socket);
    close(efd);

    return 0;
}
