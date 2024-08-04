#include <utility>

class Myclass {};

int main()
{
	Myclass m;
	const Myclass cm;

	auto&& r1 = Myclass{}; // Myclass&&
	auto&& r2 = m; // Myclass&
	auto&& r3 = std::move(m); // Myclass&&
	auto&& r4 = cm; // const Myclass&
	auto&& r5 = std::move(cm); // const Myclass&&
}
