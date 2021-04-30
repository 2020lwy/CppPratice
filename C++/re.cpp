#include <iostream>
#include <cstring>
#include <string>


// void change_value(int &p){
//     p=200;
// }
bool is_true ;

int test(int a,int b){
    return (a>b?a:b);
}

int main(void){
    // int a = 100;
    // change_value(a);
    // std::cout << a << std::endl;

    // std::string ps =std::string ("hello world");
    // std::cout << ps.size() << std::endl;
    // std::cout << strlen(ps.c_str()) << std::endl;
    int a = 300;
    int b = 200;
    std::cout << test(a,b) << std::endl;

    return 0;
}