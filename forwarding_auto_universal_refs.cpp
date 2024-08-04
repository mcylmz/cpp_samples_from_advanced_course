#include <iostream>
#include <string>

class Myclass {};

void foo(const Myclass&)
{
	std::cout << "foo(const Myclass&)\n";
}

void foo(Myclass&)
{
	std::cout << "foo(Myclass&)\n";
}

void foo(Myclass&&)
{
	std::cout << "foo(Myclass&&)\n";
}

void foo(const Myclass&&)
{
	std::cout << "foo(const Myclass&&)\n";
}

int main()
{
	Myclass m;
	const Myclass cm;

	auto&& r1 = Myclass{};
	foo(std::forward<decltype(r1)>(r1));

	auto&& r2 = m;
	foo(std::forward<decltype(r2)>(r2));

	auto&& r3 = cm;
	foo(std::forward<decltype(r3)>(r3));

	auto&& r4 = std::move(m);
	foo(std::forward<decltype(r4)>(r4));

	auto&& r5 = std::move(cm);
	foo(std::forward<decltype(r5)>(r5));
}
