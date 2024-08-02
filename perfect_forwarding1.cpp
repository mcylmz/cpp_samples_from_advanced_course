#include <iostream>

class Myclass { };

void func(const Myclass&)
{
	std::cout << "const Myclass&\n";
}

void func(Myclass&)
{
	std::cout << "Myclass&\n";
}


void func(Myclass&&)
{
	std::cout << "Myclass&&\n";
}

void func(const Myclass&&)
{
	std::cout << "const Myclass&&\n";
}

template <typename T>
void call_func(T&& t)
{
	func(std::forward<T>(t));
}

int main()
{
	Myclass m;
	const Myclass cm;

	func(m); // Myclass&
	call_func(m); // Myclass&
	std::cout << '\n';

	func(cm); // const Myclass&
	call_func(cm); // const Myclass&
	std::cout << '\n';

	func(Myclass{}); // Myclass&&
	call_func(Myclass{}); // Myclass&&
	std::cout << '\n';

	func(std::move(m)); // Myclass&&
	call_func(std::move(m)); // Myclass&&
	std::cout << '\n';

	func(std::move(cm)); // const Myclass&&
	call_func(std::move(cm)); // const Myclass&&
	std::cout << '\n';
}

