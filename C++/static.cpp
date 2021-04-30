#include <iostream>
#include <memory> 

class A{
 public:
    void add(){
        std::cout << " I am add" << std::endl;
    }
 private:
    int a;
};

class B: public A{
 public:
    void sub(){
        std::cout << " I am sub" << std::endl;
    }
 private:
    int b;
};


int main(void){

    std::shared_ptr<A>  ppa = std::make_shared<B>();  //智能指针，也是定义了一个指向基类的指针，
                                                      //但是使用了一个指向子类的指针来做初始化

    

    // B  b;//这里是一个普通的隐式转换，可以将一个指向子类对象的指针转换成一个指向一个基类对象的指针，作用域变小了，
            //在编译器看来，是安全的
    // A  *a = &b;

    // A  a;
    // B * b = &a;//error 这里也是打算使用普通的式转换，将一个指向基类对象的指针转换成一个指向子类对象的指针，作用域变大了，
                //在编译器看来，是不安全的

    // A *a=NULL;
    // B *b = static_cast<B*>(a);  //这里是将指向基类的指针转换成指向子类的指针，称为向下造型，作用域是变大了，
                                    //也就是上面不允许的普通,可以使用静态类型转换static_cast来完成转换
    
    // A * a= NULL;
    // B * b = dynamic_cast<B *>(a);//error 这里尝试使用动态 类型转换dynamic_cast将指向基类的指针转换成指向子类对象的指针，向下造型，作用域变大
                                    //明显，上面的不允许隐式转换的用法，也是不适用动态类型转换dynamic

    // B * b = NULL;
    // A * a = dynamic_cast<A*>(b);//这里没问题，将指向子类的指针转换成指向基类的指针，向上造型，作用域变小，编译器认为是安全的


    //对于强转后的指向子类对象的基类指针能访问sub()函数，我真的没试出来，比如：
    // B b;//子类对象
    // A * a = static_cast<B *>(&b);//这里是将子类的指针强转成基类指针,向上造型
    // a->sub();

    // A a;
    // B *b=static_cast<B *>(&a);//这里是将基类指针强转成了子类指针，向下造型，这个在编译器看来是不安全的。
    // b->sub();

    // B b;
    // A *a = &b;
    
    // B b;
    // A *a = static_cast<A *>(&b);
    // a->add();//这个我觉得基类指针真的可以访问到这个子类中的成员函数吗
    return 0;
}   