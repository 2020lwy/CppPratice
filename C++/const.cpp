#include <iostream>
#include <cstring>

char *mystrcpy(char *des,const char *src){
    char *p = NULL;
    if(des==NULL||src==NULL){
        return NULL;
    }
    p = des;
    while((*des++=*src++)!='\0');
    return p;
}

char *(*func)(char *,const char *);

int main(void){

    // const int a = 100;
    // int *p = const_cast<int *>(&a);
    // *p = 2000;
    // char str1[]="hello";
    // char str2[]={0};

    // std::cout << *p << std::endl;
    // std::cout << a << std::endl;

    const int b = 200;
    int *ptr = (int *)&b;
    std::cout << "*ptr before " << *ptr << std::endl;
    *ptr = 900;
    std::cout << "*ptr after "  << *ptr << std::endl;
    std::cout << b << std::endl;
    // const int a = 100;
    
    // const int *ptr = &a;
    // printf("%d\n",a);
    using ss = int;
    ss bb = 123;
    std::cout << "bb "  << bb << std::endl;


    std::string str(10,'c');
    std::cout << str << std::endl;

    std::string s1 = "hello";
    std::string s2 = "world";
    char *st = (char *)"hello";

    std::cout << "sizeof length "  << sizeof(st) << std::endl;
    std::cout << "strlen length "  << strlen(st) << std::endl;

    if(s1 == s2){
        std::cout << "字符串是相等的" << std::endl;
    }else{
        std::cout << "字符串是不相等的" << std::endl;
        std::cout << "字符串的长度是:"  << s1.size() << std::endl;
        std::cout << "字符串的长度是:"  << s1.size() << std::endl;
    }

    for(auto cc :s1)
        std::cout << cc << std::endl;


    return 0;
}