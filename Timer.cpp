#include "Timer.h"


//Timer::~Timer() {
//    long long time = std::chrono::duration_cast<nanosecs>(clock_t::now() - my_clock).count();
//    if(time / 1000000000 > 0){
//        std::cout << time / 1000000000 << " seconds " << std::endl;
//    }
//    if(time / 1000000 > 0){
//        std::cout << time / 1000000 << " milliseconds " << std::endl;
//    }
//    if(time / 1000 > 0){
//        std::cout << time / 1000 << " microseconds " << std::endl;
//    }
//    std::cout << time << " nanoseconds" << std::endl;
//}

void Timer::reset() {my_clock = clock_t::now();}

auto Timer::elapsed_time() const{
        return std::chrono::duration_cast<nanosecs>(clock_t::now() - my_clock).count();
}

auto Timer::Timer::elapsed_time_with_reset() {
    auto temp = elapsed_time();
    reset();
    return temp;
}
