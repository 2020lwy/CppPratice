#include <iostream>
#include <chrono>
#include <unistd.h>
class Timer {
 public:
  Timer() : is_start_(false) {}
  ~Timer() {}
  Timer& operator=(Timer &&other) {
    is_start_ = other.is_start_;
    begin_ = other.begin_;
  };
  
  bool isStart() { return is_start_; }
  void start() {
    begin_ = std::chrono::high_resolution_clock::now();
    is_start_ = true;
  }
  void reset() { begin_ = std::chrono::high_resolution_clock::now(); }
  void close() { is_start_ = false; }

  template <typename Duration = std::chrono::milliseconds>
  int64_t elapsed() const {
    return is_start_ ? std::chrono::duration_cast<Duration>(
                           std::chrono::high_resolution_clock::now() - begin_)
                           .count()
                     : 0;
  }

  int64_t elapsed_micro() const { return elapsed<std::chrono::microseconds>(); }
  int64_t elapsed_nano() const { return elapsed<std::chrono::nanoseconds>(); }
  int64_t elapsed_seconds() const { return elapsed<std::chrono::seconds>(); }
  int64_t elapsed_minutes() const { return elapsed<std::chrono::minutes>(); }
  int64_t elapsed_hours() const { return elapsed<std::chrono::hours>(); }

 private:
  bool is_start_ = false;
  std::chrono::time_point<std::chrono::high_resolution_clock> begin_;
};
int main(void){
    Timer tt;
    tt.start();
    sleep(5);
    std::cout << tt.elapsed_seconds() << std::endl;
    return 0;
}