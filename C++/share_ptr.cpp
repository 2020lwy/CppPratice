#include <iostream>
#include <memory>


class bi{
 public:
     virtual void write()=0;
};

class qianbi:public bi{
 public:
     qianbi(int a,int b){
        std::cout << "I am qianbi 构造函数" << std::endl;
        std::cout << "a = " << a  <<  std::endl;
        std::cout << "b = " << b  <<  std::endl;
     }
     virtual void write(){
        std::cout << "I am qianbi" << std::endl;
     }
};

class yuanzhubi:public bi{
 public:
     virtual void write(){
        std::cout << "I am yuanzhubi" << std::endl;
     }
};

int main(void){

    using s_ptr = std::shared_ptr<bi>;
    std::shared_ptr<bi> ptr = std::make_shared<qianbi>(1,2);
    ptr->write();
    s_ptr ss = std::make_shared<yuanzhubi>();
    ss->write();
    return 0;
}
