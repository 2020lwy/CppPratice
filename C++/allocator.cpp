#include <iostream>
#include <memory>


int main(void){

    std::allocator<std::string> alloc;
    const std::string *ptr = alloc.allocate(10);
    return 0;
}