#include <iostream>

class Myclass {
public:
	Myclass() = default;

	Myclass(const Myclass&)
	{
		std::cout << "copy constructor\n";
	}

	Myclass(Myclass&&)
	{
		std::cout << "move constructor\n";
	}

	template <typename T>
	Myclass(T&&)
	{
		std::cout << "universal constructor\n";
	}
};

int main()
{
	Myclass mc;
	const Myclass cmc;
	Myclass a{ cmc }; // copy ctor
	Myclass b{ mc }; // universal ctor
	Myclass c{ std::move(mc) }; // move ctor
	Myclass d{ std::move(cmc) }; // universal ctor
}
