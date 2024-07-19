#include <thread>
#include <iostream>
#include <vector>
#include <chrono>

void foo(char c)
{
	using namespace std::literals;

	for (int i = 0; i < 1000; ++i) {
		std::cout << c;
		std::this_thread::sleep_for(125ms);
	}
}

int main()
{
	using namespace std;

	vector<thread> tvec(26);

	for (int i = 0; i < 26; ++i) {
		tvec[i] = thread{ foo, static_cast<char>(i + 'A') };
	}

	for (auto& t : tvec) {
		t.join();
	}

}
