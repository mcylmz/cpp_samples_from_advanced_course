#include <iostream>
#include <type_traits>

template <typename T>
void func() {
	if constexpr (std::is_rvalue_reference_v<T>)
		std::cout << "xvalue";
	else if constexpr (std::is_lvalue_reference_v<T>)
		std::cout << "lvalue";
	else if constexpr (!std::is_reference_v<T>)
		std::cout << "prvalue";
}

#define exp(e) decltype((e))

int main()
{
	int x = 19;
	func<exp(x)>();
}
