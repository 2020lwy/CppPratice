#include <iostream>
#include <list>

int main(void){
    std::list<int> nodes;
    nodes.push_back(10);
    nodes.push_back(20);
    nodes.push_back(60);
    nodes.push_back(50);
    nodes.push_back(30);
    nodes.push_back(40);
    nodes.push_back(70);
    int ss= nodes.size();
    std::cout << "ss " << ss << std::endl;
    nodes.remove(100);
    ss= nodes.size();
    std::cout << "ss " << ss << std::endl;

}
