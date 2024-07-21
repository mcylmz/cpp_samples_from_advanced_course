// reference collapsing contexts

// 1. templates
template <typename T>
void func(T&&);

// 2. using
class Myclass {};

using lref = Myclass&;
using rref = Myclass&&;

// 3. decltype
int x{ 123 };
int* ptr = &x;
decltype(*ptr)& r = x;
