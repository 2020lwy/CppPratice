#include <iostream>

int main(void){
    int *p = new int[10];
    for(int i = 0;i<10;i++){
        p[i]=i;
        std::cout << p[i] ; 
    }
    std::cout << std::endl;
    return 0;
}
