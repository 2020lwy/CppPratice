#include <iostream>
#include <cstring>

class String{
 public:
    //普通的构造函数
    String(const char *str=NULL){
        if(str==NULL){
            *m_str ='\0';
        }else{
            m_str = new char[strlen(str)+1];
            strcpy(m_str,str);
        }
    }
    //赋值构造函数函数
    String & operator=(const String & that){
        if(this==&that){
            std::cout << "禁止自己给自己赋值" << std::endl;
            return *this;
        }else{
            delete [] this->m_str;
            m_str = new char[strlen(that.m_str)+1];
            strcpy(m_str,that.m_str);
            return *this;
        }
    }
    //拷贝构造函数
    String(const String &that){
        m_str = new char[strlen(that.m_str)+1];
        strcpy(m_str,that.m_str);
    }
    //析构函数
    ~String(){
        delete [] m_str;
    }
    void print(){
        std::cout << m_str << std::endl;
    }
 private:
    char *m_str;

};

int main(void){

    String ss("hello guangzhou");
    String ss2 = ss;
    String ss3(ss);
    ss3.print();
    return 0;
}