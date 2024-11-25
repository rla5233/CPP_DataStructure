#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::vector<int> v1 = { 1, 2, 3, 4, 5 };
		
		//v1.reserve(6);

		auto it1 = v1.begin() + 1;
		auto it2 = v1.erase(it1);

		for (auto it = v1.begin(); it != v1.end(); ++it)
			std::cout << *it << ' ';

		int a = 0;
	}

	std::cout << std::endl;

	{
		ksw::Vector<std::string> v1;
		//v1.reserve(6);
		for (int i = 0; i < 5; i++)
			v1.push_back("A");

		auto it1 = v1.begin() + 1;
		auto it2 = v1.erase(it1);

		for (auto it = v1.begin(); it != v1.end(); ++it)
			std::cout << *it << ' ';
	}

	return 0;
}