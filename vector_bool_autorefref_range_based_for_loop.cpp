#include <iostream>
#include <string>
#include <vector>

template <typename C, typename T>
void Fill(C& con, const T& val)
{
	for (auto& elem : con) // this line causes syntax error for vector<bool> **
		elem = val;
}

// ** expansion of range-based for loop for auto& elem = con
// produces a code that tries to bind lvalue reference to an rvalue
// expression. Because vector<bool>'s operator*() function returns
// reference (proxy object type)
// Solution: use univeral reference -> for (auto&& elem : con)

int main()
{
	using namespace std;

	vector<int> ivec{1, 2, 3, 4, 5};
	
	for (auto val : ivec)
		cout << val << " ";
	cout << '\n';

	Fill(ivec, 100);

	for (auto val : ivec)
		cout << val << " ";
	cout << '\n';


	vector<bool> bvec{ false, false, false, false, false };

	for (auto val : bvec)
		cout << val << " ";
	cout << '\n';

	Fill(bvec, 100);

	for (auto val : bvec)
		cout << val << " ";
	cout << '\n';
}
