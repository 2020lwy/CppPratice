#include <iostream>
#include <memory>

class Base{
 public:
    Base(){
        m_str = new char[1024];
    }
    virtual ~Base(){
        std::cout << "Base 析构函数" << std::endl;
        delete [] m_str;
    }
    virtual void run()=0;
    virtual void start(){
        std::cout << "Base virtual start()" << std::endl;
    }
 private:
    int m_age_;
    char *m_str;
};

class Son : public Base{
 public:
    Son(){
        m_count_ = new int[1024];
    }
    ~Son(){
        std::cout << "Son ~析构函数" << std::endl;
        delete [] m_count_;
    }
    void run(){
        std::cout << "I am Son run" << std::endl;
    }
    void start(){
        std::cout << "I am Son start" << std::endl;
    }
 private:
    int m_id_;
    int *m_count_;

};

class  Person{

 public:
    Person(){
        std::cout << "Person 无参构造" << std::endl;
    }
    Person(int i){
        std::cout << "Person 有参构造" << std::endl;
    }
    virtual void test(int a){
        std::cout << "Person test" << std::endl;
    }
    ~Person(){

    }

};

class Student : public Person{

 public:
    Student():Person(){
        std::cout << "Student 无参构造" << std::endl;
    }
    
    Student(int i):Person(i){
        std::cout << "Student 有参构造" << std::endl;
    }
    void test(int a){
        std::cout << "Student test : a = " << a << std::endl;
    }
};

int main(void){
    // std::shared_ptr<Base> ptr;//注意，这里使用智能指针的时候，不管基类中的析构函数是否被定义为虚函数，子类中的析构函数都能被调用
    //                         //智能指针真的是太牛逼了
    // ptr = std::make_shared<Son>();
    // ptr->run();
    // ptr->start();


    //下面我们尝试不适用智能指针，直接使用的时候裸指针的时候，看看析构函数的调用情况是怎样的
    // Base * base = new Son();
    // base->run();
    // base->start();
    // delete base;

    Student *stu = new Student(200);
    Person  *per = (Person *)stu;
    per->test(20);
    return 0;
}