#include <iostream>
#include <memory>

int main(void){

    //std::unique_ptr<std::string> pd (new std::string("hello"));

    //std::unique_ptr<std::string> ps = nullptr;

    // std::shared_ptr<std::string> pd (new std::string("hello"));
    // std::shared_ptr<std::string> ps = nullptr;

    std::auto_ptr<std::string> pd (new std::string("hello"));
    std::auto_ptr<std::string> ps ;

    ps = pd;
    *pd = "world !";

    std::cout << " *ps "  << *ps << std::endl;
    return 0;
}