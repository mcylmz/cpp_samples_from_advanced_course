#include <iostream>
#include <string>

void navigate(std::string::iterator beg, std::string::iterator end)
{
	std::cout << "non const semantics on the passed range\n";
}

void navigate(std::string::const_iterator beg, std::string::const_iterator end)
{
	std::cout << "const semantics on the passed range\n";
}

template <typename T>
void process_container(T&& coll)
{
	navigate(coll.begin(), coll.end());
}

int main()
{
	std::string str{ "mutable string" };
	const std::string const_str{ "immutable string" };

	process_container(str);
	process_container(const_str);
	process_container(std::string{ "temporary string object" });
	process_container(std::move(str));
	process_container(std::move(const_str));
}
