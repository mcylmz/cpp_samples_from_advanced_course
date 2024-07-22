#include <mutex>
#include <list>
#include <iostream>

class List {
public:
	void push_back(int x)
	{
		mtx_.lock();
		list_.push_back(x);
		mtx_.unlock();
	}

	void print() const
	{
		mtx_.lock();
		for (const auto val : list_)
			std::cout << val << ' ';
		mtx_.unlock();
	}

private:
	std::list<int> list_;
	mutable std::mutex mtx_;
};
