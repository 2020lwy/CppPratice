#include <iostream>

void a(int * arr,int num){

    arr[num]=200;
    std::cout << arr[num]  << std::endl;
}

int main(void){

    int arr[10]={0};
    a(arr,10);

    return 0;
}
