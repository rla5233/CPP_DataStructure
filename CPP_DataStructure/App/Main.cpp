#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::list<int> li;

		for (int i = 0; i < 5; i++)
			li.push_back(i + 10);

		for (int i = 0; i < 5; i++)
			li.push_front(i + 10);

		auto it = li.begin();
		++it;

		std::cout << li.remove(11);
		std::cout << std::endl;

		for (auto& cur : li)
			std::cout << cur << " ";
	}


	std::cout << std::endl;
	{
		ksw::DoubleList<int> li;

		for (int i = 0; i < 5; i++)
			li.push_back(i + 10);

		for (int i = 0; i < 5; i++)
			li.push_front(i + 10);

		auto it = li.begin();
		++it;

		std::cout << li.remove(11);
		std::cout << std::endl;

		for (auto& cur : li)
			std::cout << cur << " ";
	}

	return 0;
}