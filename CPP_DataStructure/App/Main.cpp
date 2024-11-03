#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::list<int> li(5, 1);

		int a = 0;

		for (int i = 0; i < 5; i++)
			li.push_back(i + 10);

		auto it = li.begin();
		++it;


		for (auto& cur : li)
			std::cout << cur << " ";
	}


	std::cout << std::endl;
	{
		ksw::DoubleList<int> li(5, 1);

		int a = 0;

		for (int i = 0; i < 5; i++)
			li.push_back(i + 10);

		auto it = li.begin();
		++it;

		for (auto& cur : li)
			std::cout << cur << " ";
	}

	return 0;
}