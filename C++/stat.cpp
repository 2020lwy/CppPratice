#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>

int main(void){

    struct stat tt;
    int ret= stat("./hh",&tt);
    std::cout << "ret " <<  ret << std::endl;
    if(S_ISDIR(tt.st_mode)){
        std::cout << "hh is exit" << std::endl;
    }

    return 0;
}

