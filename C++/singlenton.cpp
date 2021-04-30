#include <iostream>


enum example : unsigned char{
    A,
    B,
    C
};

class SingLeton{
 private:
    SingLeton(){

    }

 public:
    enum Level{
        level1=0,level2,level3
    };
    static SingLeton & Get(){
        static SingLeton *instance = nullptr;
        if(instance == nullptr){
            instance = new SingLeton;
        }
        return *instance;
    }
    void hello(){
        std::cout << "hello world" << std::endl;
    }
};

void dosomething(int ID){
    switch (ID)
    {
    case A:
        std::cout << "A"  << std::endl;
        break;
    case B:
        std::cout << "B"  << std::endl;
        break;   
    default:
        break;
    }
}

int main(void){

    // SingLeton::Get().hello();
    // SingLeton &instance = SingLeton::Get();
    // int a = 0;
    // dosomething(SingLeton::level2);

    unsigned int  u = 10;
    unsigned int  u2 = 42;
    int i = 10;
    int i2 = 42;


    std::cout << "u-u2    " << u-u2 << std::endl;
    std::cout << "u2-u    " << u2-u << std::endl;

    std::cout << "i2-i    " << i2-i << std::endl;
    std::cout << "i-i2    " << i-i2 << std::endl;
    std::cout << "i-u     " << i-u << std::endl;
    std::cout << "u-i     " << u-i << std::endl;

    
    return 0;
}