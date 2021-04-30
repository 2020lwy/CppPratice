#include <iostream>

typedef struct CPU{
    int info;
    float mem;
    float temp;
}cpu_info;

int main(void){
    
    cpu_info *p=new cpu_info();
    p->info = 100;

    std::cout << "p->info " << p->info << std::endl;
    delete p;
    return 0;
}
