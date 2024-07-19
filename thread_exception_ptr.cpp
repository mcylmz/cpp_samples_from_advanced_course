#include <iostream>
#include <thread>
#include <exception>

std::exception_ptr eptr{ nullptr };

void foo(int x)
{
    std::cout << "foo(int x) called x = " << x << '\n';

    try {
        if (x % 5 == 0)
            throw std::invalid_argument{"invalid integer argument\n"};
    }
    catch (const std::exception&) {
        eptr = std::current_exception();
    }

    std::cout << "func(int x) finished\n";
}

int main()
{
    std::thread t{foo, 150};

    t.join();

    try {
        if (eptr) {
            std::rethrow_exception(eptr);
        }
    }
    catch (const std::exception& ex) {
        std::cout << "exception caught: " << ex.what() << '\n';

}
