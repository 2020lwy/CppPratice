#include <iostream>
#include <stdlib.h>
#include "refren.h"

void func(int a,int b,int c){
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}

struct  Student
{
    int id;
    int age;
};

void print(Student * &st){//指针的引用作为函数的参数
    std::cout << st->id << "  " << st->age << std::endl;
}

//尽量使用引用作为函数的参数。另外引用也可以作为函数的返回值

int main(void){ 
    Student * std=NULL;
    std = (Student *)malloc(sizeof(Student));
    std->age = 100;
    std->id  = 200;
    print(std);
    int a =100;
    func(a);


    int ii = 42;
    int &r = ii;
    std::cout << "* ii  "  << ii << std::endl; 
    return 0;
}