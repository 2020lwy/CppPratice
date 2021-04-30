#include <iostream>
#include <vector>
#include <array>
#include <chrono>
#include <cstdlib>
#include <string.h>
#include <algorithm>

#define ARRY_SIZE 500000

class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start,end;
    std::chrono::duration<float,std::ratio<1,1>> duration;

    
 public:
    Timer(){
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000;
        std::cout << "time tooks " << ms << "ms" << std::endl;
    }
};

int comparelongs(const void *a ,const void *b){
    return (*(long *)a - *(long *)b);
}


void Function(std::array<long,ARRY_SIZE> arr){
    Timer mytimer;
    long target = 2000;
    qsort(arr.data(),ARRY_SIZE,sizeof(long),comparelongs);
    long * pItem = (long *)bsearch(&target,(arr.data()),ARRY_SIZE,sizeof(long),comparelongs);
    if(pItem == NULL){
        std::cout << "not found "  << std::endl;
    }else{
        std::cout << "found "  << std::endl;
    }
}


int main(void){

    std::array<long,ARRY_SIZE>  arr;
    for(long i = 0; i< ARRY_SIZE;++i){
        arr[i] = rand();
        if(i==2000)
            arr[i]=i;
    }
    Function(arr);

    std::cout << "file :"  << __FILE__  << "  " << "function " <<  __func__  << "  "  << __LINE__ << " "  << __DATE__ << "  "  << __TIME__ << std::endl;
   
 
    return 0;
}