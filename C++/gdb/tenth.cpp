#include <iostream>
#include <vector>
#include <map>

using Vector = std::vector<int>;


void find(Vector & vec,int target){
    std::map<int,int> m_map;
    m_map[vec[0]] = 0;

    for(int i = 1;i<vec.size();i++){
        auto it = m_map.find(target-vec[i]);
        if(it != m_map.end()){
            std::cout << " i = " << i << std::endl;
            std::cout << " j = " << it->second << std::endl;
        }
        else
        {
            m_map[vec[i]] = i;
        }
    }
}

int main(void){
    Vector vec{1,2,99,109,800};
    Vector &ref = vec;

    find(ref,101);
    find(ref,110);
    return 0;
}