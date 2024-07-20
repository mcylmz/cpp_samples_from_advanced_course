#include <random>
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

thread_local std::mt19937 eng{ 23423424u };

void func()
{
	std::uniform_int_distribution<int> dist{ 100, 999 };

	for (int i = 0; i < 10; ++i) {
		std::lock_guard<std::mutex> lg(mtx);
		std::cout << dist(eng) << ' ';
	}

	std::lock_guard<std::mutex> lg(mtx);
	std::cout << '\n';
}

int main()
{
	std::thread t1{ func };
	std::thread t2{ func };
	std::thread t3{ func };
	
	t1.join();
	t2.join();
	t3.join();
}
