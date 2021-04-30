#include <iostream>
#include <stdio.h>
#include <assert.h>

#define LOG(...) {fprintf(stderr,"%s: Line %d \n",__FILE__,__LINE__);}

void test(int a){
    std::cout << "I am std cout "  << std::endl;
    LOG(...);
}

int main(void){
    test(100);
    int a = 100;
    int c = 200;
    char d = 'a';
    static_assert (sizeof(a)==sizeof(c),"they are not same width");
    char *p = nullptr;
    p = &d;
    assert(a>500);
    return 0;
}

