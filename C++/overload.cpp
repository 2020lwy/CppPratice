#include <iostream>
using namespace std;
int foo(int i){
    cout <<  "i = " << i <<  endl;
}

void foo(int a,int b){
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

int foo(int a,float b){

    cout << "foo(int,float)" << endl;
    return 0;
}

int main(void){
    foo(12);
    foo(13,14);
    int (*pfoo)(int,float)=foo;
    pfoo(10,20);
    return 0;
}
