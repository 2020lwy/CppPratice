#include <iostream>
#include <vector>
#include <algorithm>


int find(std::vector<int> &vec){
    int tmp = 0;
    sort(vec.begin(),vec.end());
    for(std::vector<int>::iterator it =vec.begin();it!=vec.end();it=it+2){
        if(*it!=*(it+1)){
            tmp = *it;
            break;
        }
    }
    return tmp;
}

int main(void){

    std::vector<int> vec{1,2,3,4,5,1,2,3,4,5,6,7,9,6,7};
    std::vector<int> &refvec = vec;

    int a = find(refvec);
    std::cout << a << std::endl;
}