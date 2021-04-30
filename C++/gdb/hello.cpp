#include <iostream>

int add(int a,int b){
    return a+b;
}

int main(void){

    int a = 100;
    int b = 200;
    std::cout << "a+b =  " << add(a,b) << std::endl;
    for(int i =0;i<10;i++){

        std::cout << " i = " << i << std::endl;
    }
    return 0;
}
