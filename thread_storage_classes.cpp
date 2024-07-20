#include <mutex>
#include <thread>
#include <iostream>

std::mutex mtx;

void foo()
{
	int x = 0; // automatic storage
	static int y = 0; // static storage class
	thread_local int z = 0; // thread local

	for (int i = 0; i < 5; ++i) {
		++x;
		++z;

		std::lock_guard<std::mutex> lg(mtx);
		++y;
		std::cout << "thread id: " << std::this_thread::get_id() << " " << x << " automatic storage\n";
		std::cout << "thread id: " << std::this_thread::get_id() << " " << z << " thread local storage\n";
		std::cout << "thread id: " << std::this_thread::get_id() << " " << y << " static storage\n";
	}

}

int main()
{
	std::thread t1{ foo };
	std::thread t2{ foo };
	std::thread t3{ foo };

	t1.join();
	t2.join();
	t3.join();
}
