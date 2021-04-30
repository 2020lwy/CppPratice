#include <iostream>

int test(int *var){
    int a = 200;
    var = &a;
    return *var;
}


int main(void){

    int *var = NULL;
    std::cout << "return = " << test(var) << std::endl;
    return 0;
}