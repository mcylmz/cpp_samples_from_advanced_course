#include <iostream>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;

class Myclass {
public:
	Myclass()
	{
		lock_guard<mutex> lg(mtx);
		cout << "constructor this : " << this << '\n';
	}

	~Myclass()
	{
		lock_guard<mutex> lg(mtx);
		cout << "destructor this : " << this << '\n';
	}
};

void foo()
{
	mtx.lock();
	cout << "foo called\n";
	mtx.unlock();

	thread_local Myclass m;

	mtx.lock();
	cout << "foo ended\n";
	mtx.unlock();
}

void bar()
{
	using namespace chrono_literals;
	
	mtx.lock();
	cout << "bar called\n";
	mtx.unlock();

	foo();
	std::this_thread::sleep_for(2s);

	mtx.lock();
	cout << "bar ended\n";
	mtx.unlock();
}

int main()
{
	cout << "main started\n";

	thread t1{ bar };
	thread t2{ bar };
	thread t3{ bar };

	t1.join();
	t2.join();
	t3.join();

	cout << "main ended\n";
}
