#include<iostream>
#include <type_traits>
#include <string>


class Myclass {
public:
	Myclass operator+(const Myclass&) const;
};

class AnotherMyclass {
public:
	AnotherMyclass operator+(const AnotherMyclass&) noexcept const;
};


template <typename T>
void func(T x) noexcept(noexcept(x + x));

int main()
{
	constexpr bool b1 = noexcept(func(12)); // true

	std::string str;
	constexpr bool b2 = noexcept(func(str)); // false

	Myclass mc;
	constexpr bool b3 = noexcept(func(mc)); // false

	AnotherMyclass amc;
	constexpr bool b4 = noexcept(func(amc)); // true
}
