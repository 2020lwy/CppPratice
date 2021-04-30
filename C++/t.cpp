#include <iostream>

class Test{
 public:
    Test(int a,int b):a_(a),b_(b){

    }
    void print(){
        std::cout << "a_ " << a_ << std::endl;
        std::cout << "b_ " << b_ << std::endl;
    }
 private:
    int a_;
    int b_;

};

int main(void){

    Test tt(100,200);
    tt.print();
    return 0;
}
