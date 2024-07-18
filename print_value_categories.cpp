#include <iostream>

// primary template
template <typename T>
constexpr const char* p = "prvalue";

// partial specialization for lvalue
template <typename T>
constexpr const char* p<T&> = "lvalue";

// partial specialization for xvalue
template <typename T>
constexpr const char* p<T&&> = "xvalue";

#define pvcat(e) std::cout << "value category of '" << #e << "' is " << p<decltype((e))> << '\n'


int foo();
int& bar();
int&& baz();
void func();

struct Mystruct {
	int x{};
	static int y;
};

int main()
{
	int x = 10;
	int* ptr = &x;

	pvcat(x);
	pvcat(ptr);
	pvcat(x + 5);
	pvcat(x++);
	pvcat(x--);
	pvcat(++x);
	pvcat(--x);

	pvcat(foo());
	pvcat(bar());
	pvcat(baz());
	pvcat(func());

	pvcat(42);
	pvcat('A');
	pvcat("ali");

	pvcat(foo);
	pvcat(bar);
	pvcat(baz);
	pvcat(func);

	pvcat(std::move(x));
	pvcat(static_cast<int&&>(x));

	pvcat(std::move(foo)); // microsoft compiler bug! microsoft: xvalue, gcc: lvalue

	pvcat(nullptr);

	pvcat(Mystruct{});
	pvcat(Mystruct{}.x);

	// pvcat([](int x) { return x * x; }); // prvalue

	Mystruct s;
	pvcat(s);

	auto& rs = s;
	pvcat(rs);

	auto &&frs = Mystruct{};
	pvcat(frs);

	pvcat(std::move(s).x);
	pvcat(std::move(s).y);


	int a{}, b{}, c{};
	pvcat(a > 10 ? b : c);
	pvcat(a > 10 ? b : 10);
	pvcat(a > 10 ? 10 : c);

	return 0;
}
