#include <iostream>
#include <thread>

std::thread make_thread(int n)
{
    auto f = [n]() mutable {
        while (n--) {
            std::cout << "workload\n" ;
        }
    }

    return std::thread{f};
}
