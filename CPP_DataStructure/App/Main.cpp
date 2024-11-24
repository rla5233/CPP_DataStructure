#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::vector<int> v1 = { 1, 2, 3, 4, 5 };

		auto it = v1.end() - 1;

		int a = 0;
	}

	std::cout << std::endl;

	{
		ksw::Vector<int> v1;
		for (int i = 0; i < 8; i++)
			v1.push_back(i + 10);

		auto it2 = v1.begin() + 1;

		int b = 0;

		for (auto it = v1.begin(); it != v1.end(); ++it)
		{
			std::cout << *it << ' ';
			--(*it);
		}

		std::cout << std::endl;
		for (int i = 0; i < v1.size(); i++)
			std::cout << v1[i] << ' ';

		int a = 0;
	}

	return 0;
}