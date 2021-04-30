#include <iostream>
#include <sstream>
#include <set>
#include <map>

int main(void){

    std::set<int> test;
    for(int i = 0;i< 10;i++){
        test.insert(i);
    }

    // for(auto x : test){
    //     std::cout <<  x << std::endl;
    // }

    std::set<int>::iterator it;
    for(it = test.begin();it!=test.end();it++){
        std::cout << *it << std::endl;
        //*it = *it +100;   //注意在这个位置，set的迭代器是只读的
    }

    std::map<int,std::string> map_t;
    std::stringstream strStream;  
    for(int j = 0; j< 5 ; j++){
        std::string ss = "hello world";
        strStream.clear();
        strStream << j;
        std::string s = strStream.str();
        ss = ss+s;
        map_t[j] = ss;
    }
    #if 0
    for(auto mmap : map_t){
        std::cout << "key 值: " << mmap.first << "  "  << " value 值 "  << mmap.second << std::endl;
    }
    #endif

    std::map<int,std::string>::iterator ii;
    for(ii = map_t.begin();ii != map_t.end();ii++){
        std::cout << "key 值: " << ii->first << "  "  << " value 值 "  << ii->second << std::endl;
    }

    auto tt = map_t.find(100);
    std::cout << "tt key = "  << tt->first << "  "  << "tt value "  << tt->second << std::endl;

    if(map_t.find(100)!= map_t.end()){
        std::cout << "key 值 100 也存在这个map中了" << std::endl;
    }
    for(ii = map_t.begin();ii != map_t.end();ii++){
        std::cout << "key 值: " << ii->first << "  "  << " value 值 "  << ii->second << std::endl;
    }
    return 0;
}