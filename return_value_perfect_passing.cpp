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

const Myclass& func_const_lref(const Myclass& mc)
{
	return mc;
}

Myclass& func_non_const_lref(Myclass& mc)
{
	return mc;
}

Myclass&& func_rref(Myclass&& mc)
{
	return std::move(mc);
}

Myclass func_value(const Myclass& mc)
{
	return mc;
}

int main()
{
	Myclass mc;
	const Myclass const_mc;

	foo(func_rref(Myclass{})); // foo(Myclass&&)
	foo(func_non_const_lref(mc)); // foo(Myclass&)
	foo(func_const_lref(const_mc)); // foo(const Myclass&)
	foo(func_value(mc)); // foo(Myclass&&)

	std::cout << "\n\n";
	std::cout << "by using return value perfect passing\n";
	std::cout << "---------------------------------------\n";

	auto&& r1 = func_rref(Myclass{});
	foo(std::forward<decltype(r1)>(r1));

	auto&& r2 = func_non_const_lref(mc);
	foo(std::forward<decltype(r2)>(r2));

	auto&& r3 = func_const_lref(const_mc);
	foo(std::forward<decltype(r3)>(r3));

	auto&& r4 = func_value(mc);
	foo(std::forward<decltype(r4)>(r4));
}
