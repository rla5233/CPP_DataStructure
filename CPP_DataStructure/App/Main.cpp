#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::list<int> li;


		for (int i = 0; i < 5; i++)
			li.push_back(i + 10);

		auto it = li.begin();
		++it;

		auto it2 = li.erase(it);
		int a = 0;

		for (auto& cur : li)
			std::cout << cur << " ";
	}


	std::cout << std::endl;
	{
		ksw::DoubleList<int> li;


		for (int i = 0; i < 5; i++)
			li.push_back(i + 10);

		auto it = li.begin();
		++it;

		auto it2 = li.erase(it);
		int a = 0;

		for (auto& cur : li)
			std::cout << cur << " ";
	}

	return 0;
}