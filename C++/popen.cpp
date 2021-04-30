#include <iostream>
#include <stdio.h>

int main(void){

    FILE*fp=popen("ls","r");
    if(fp==NULL){
        std::cout << "popen erroe" << std::endl;
    }
    pclose(fp);
    return 0;
}
