#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>

void* test(void *){
    std::cout << "hello pthread " << std::endl;
}


int main(void){

    pthread_t tid;
    pthread_create(&tid,NULL,test,NULL);
    sleep(1);

    return 0;
}