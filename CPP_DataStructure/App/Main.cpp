#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::list<int> li1 = { 1, 2, 3 };
		std::list<int> li2 = { 4, 3, 2, 1 };

		for (auto& cur : li1)
			std::cout << cur << " ";
		std::cout << std::endl;

		for (auto& cur : li2)
			std::cout << cur << " ";
		std::cout << std::endl;

		li1.swap(li2);

		for (auto& cur : li1)
			std::cout << cur << " ";
		std::cout << std::endl;
		
		for (auto& cur : li2)
			std::cout << cur << " ";
		std::cout << std::endl;
	}


	std::cout << std::endl;
	{
		ksw::DoubleList<int> li1;
		ksw::DoubleList<int> li2;

		for (int i = 1; i <= 3; i++)
			li1.push_back(i);

		for (int i = 1; i <= 4; i++)
			li2.push_front(i);

		for (auto& cur : li1)
			std::cout << cur << " ";
		std::cout << std::endl;

		for (auto& cur : li2)
			std::cout << cur << " ";
		std::cout << std::endl;

		li1.swap(li2);

		for (auto& cur : li1)
			std::cout << cur << " ";
		std::cout << std::endl;

		for (auto& cur : li2)
			std::cout << cur << " ";
		std::cout << std::endl;
	}

	return 0;
}