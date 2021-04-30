#include <iostream>
#include <chrono>
#include <thread>
class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start,end;
    std::chrono::duration<float> duration;

    
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

void Function()
{
    Timer tim;
    for(int i=0;i<100;i++)
        std::cout << "Hello!"  << std::endl;
}

int main(void){
    // using namespace std::literals::chrono_literals;
    // auto start = std::chrono::high_resolution_clock::now();
    // std::this_thread::sleep_for(1s);
    // auto end   = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<float> duration = end -start;
    // std::cout <<  duration.count() << "s" << std::endl;
    // std::cout << "hello World !" << std::endl;

    Function();
    return 0;
}