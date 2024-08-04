#include <type_traits>
#include <iostream>
#include <string>

template <typename T>
void func(T&&)
{
	if constexpr (std::is_lvalue_reference_v<T>) {
		std::cout << "L value argument\n";
	}
	else {
		std::cout << "R value argument\n";
	}
}

class Myclass {};

int main()
{
	func(Myclass{});
	Myclass m;
	func(m);
	func(std::move(m));
}
