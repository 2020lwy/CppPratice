#include <iostream>

struct Student{
    int age;
    int no;
    char sex;
};

void print(Student & s){
    std::cout << "今年:" << s.age <<"岁," << "学号是:" << s.no <<",性别是:" << s.sex <<std::endl;
}

int main(void){
    int a = 100;
    const int &b =a;//引用在声明的时候需要完成初始化 常引用
    std::cout << "b = " << b << std::endl;
    std::cout << "a = " << a << std::endl;
    //常引用可以引用左值也可以引用右值，区分什么是左值，什么是右值，放在等号的

    std::cout << "&a = " << &a << std::endl;
    std::cout << "&b = " << &b << std::endl;

    Student stu;
    stu.age = 23;
    stu.no   = 10086;
    stu.sex  = 'g';
    print(stu);
    return 0;
}
