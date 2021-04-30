#include <iostream>
#include <memory>

int main(void){

    std::unique_ptr<std::string> ptr (new std::string("hello guangzhou"));
    std::cout << *ptr << std::endl;
    std::unique_ptr<int>  ptr_int1 (new int(100));
    std::unique_ptr<int>  ptr_int2 (new int(200));
    std::cout <<"*ptr_int1= " << *ptr_int1 << std::endl;
    std::cout <<"*ptr_int2= " << *ptr_int2 << std::endl;
    std::unique_ptr<int> ptr_int3;
    ptr_int3 = std::move(ptr_int1);
    ptr_int1 = std::unique_ptr<int> (new int(1200));
    std::cout <<"*ptr_int3= " << *ptr_int3 << std::endl;
    std::cout <<"*ptr_int1= " << *ptr_int1 << std::endl;
    
    
    std::shared_ptr<int> s_ptr1 (new int(1000));
    std::shared_ptr<int> s_ptr2;
    std::shared_ptr<int> s_ptr3;
    std::shared_ptr<int> s_ptr4;
    std::shared_ptr<int> s_ptr5;
    
    s_ptr2 = s_ptr1;
    s_ptr3 = s_ptr1;
    s_ptr4 = s_ptr1;
    s_ptr5 = s_ptr1;

    std::cout << "*s_ptr1 = " << *s_ptr1 << std::endl;
    std::cout << "*s_ptr2 = " << *s_ptr2 << std::endl;
    std::cout << "*s_ptr3 = " << *s_ptr3 << std::endl;
    std::cout << "*s_ptr4 = " << *s_ptr4 << std::endl;
    std::cout << "*s_ptr5 = " << *s_ptr5 << std::endl;
    return 0;
}
