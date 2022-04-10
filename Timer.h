#pragma once
#include <chrono>
#include <iostream>
#include <fstream>
#include <ios>
//#include <ostream>


//std::ofstream stream("output.csv");

class Timer {
private:
    using clock_t = std::chrono::high_resolution_clock;
    using nanosecs = std::chrono::nanoseconds;
    using microsecs = std::chrono::microseconds;
    std::chrono::time_point<clock_t> my_clock;
//    std::ofstream stream = std::ofstream("output.csv", std::ios::app);
    std::ostream &stream = std::cout;
    std::string name;
public:
    Timer(){
        my_clock = clock_t::now();
    }
    Timer(std::string new_name) : name(new_name), my_clock(clock_t::now()){}
    ~Timer(){
        long long time = std::chrono::duration_cast<nanosecs>(clock_t::now() - my_clock).count();
        if(time / 1000000000 > 0){
            std::cout << time / 1000000000 << " seconds " << std::endl;
        }
        if(time / 1000000 > 0){
            std::cout << time / 1000000 << " milliseconds " << std::endl;
        }
        if(time / 1000 > 0){
            std::cout << time / 1000 << " microseconds " << std::endl;
        }
        std::cout << time << " nanoseconds" << std::endl;
    };

    void reset();

    auto elapsed_time() const;

    auto elapsed_time_with_reset();
};