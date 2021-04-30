#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <cstring>
#include <algorithm>

int main(void){
    #if 0
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(60);
    std::cout << "vec.size()=" << vec.size() << std::endl;


    for( auto i: vec){
        std::cout << i << std::endl;
        if(i==60){
            std::cout << "找到了这个元素"  << std::endl;
        }
    }

    unsigned int cnt = 42;
    int arr[cnt]={0};
    std::string bad[cnt]={"hello"};

    int ia[4*7 - 14];
    
    int arr2[5]={1,2,3,4,5};
    for(auto i : arr2){
        std::cout << i << std::endl;
    }


    std::array<int,10> arr;
    #endif

    std::vector<std::string> vec = {"hello","aaaaa","world","welcome","back"};
    
    // std::sort(vec.begin(),vec.end());

    // for(auto i : vec){
    //     std::cout << i << std::endl;
    // }
    // vec.erase(vec.begin());
    // for(auto i : vec){
    //     std::cout << i << std::endl;
    // }
    int size = 5;
    auto wc = find_if(vec.begin(),vec.end(),[size](std::string str){return str.size() > size;});
    std::cout << " * wc = "  << *wc   << std::endl;


    for_each(vec.begin(),vec.end(),[](std::string str)->void{std::cout << "str = " << str << std::endl;});

    return 0;
}
