#include <iostream>
#include <thread>
#include <stop_token>
#include <chrono>
#include <syncstream>

int main()
{
	using namespace std;

	stop_source st_src;

	thread t1{
		[stoken = st_src.get_token()]() {
			while (!stoken.stop_requested()) {
				cout.put('*');
				this_thread::sleep_for(100ms);
			}
		}
	};

	thread t2{
		[stoken = st_src.get_token()]() {
			while (!stoken.stop_requested()) {
				cout.put('.');
				this_thread::sleep_for(100ms);
			}
		}
	};

	thread t3{
		[stoken = st_src.get_token()]() {
			while (!stoken.stop_requested()) {
				cout.put('!');
				this_thread::sleep_for(100ms);
			}
		}
	};

	this_thread::sleep_for(10s);
	osyncstream{ cout } << "sending request to stop...\n";
	st_src.request_stop();
	cout << "all threads stopped...\n";

	t1.join();
	t2.join();
	t3.join();
}
