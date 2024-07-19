#include <thread>
#include <exception>
#include <iostream>

void foo()
{
	std::cout << "foo is called\n";
}

void custom_terminate()
{
	std::cout << "custom_terminate called\n";
	(void)getchar();
	std::abort();
}

int main()
{
	set_terminate(custom_terminate);

	{
		std::thread t{ foo };
		// t.join();
	}

	std::cout << "end of main\n";
}
