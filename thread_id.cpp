#include <thread>
#include <iostream>
#include <vector>
#include <chrono>

std::thread::id main_thread_id;

void foo()
{
	if (std::this_thread::get_id() == main_thread_id) {
		std::cout << "call from main thread!\n";
	}
	else {
		std::cout << "call is not from main thread\n";
	}
}

int main()
{
	main_thread_id = std::this_thread::get_id();

	foo();

	std::thread t{ foo };

	t.join();
}
