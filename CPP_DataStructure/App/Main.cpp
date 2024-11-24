#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::vector<int> v1 = { 1, 1, 1, 1, 1, 1 };
		v1.push_back(1);
		std::vector<int> v2 = { 0, 0, 0, 0, 0 };

		for (auto it = v1.begin(); it != v1.end(); ++it)
		{
			std::cout << *it << ' ';
			--(*it);
		}

		std::cout << std::endl;
		for (int i = 0; i < v1.size(); i++)
			std::cout << v1[i] << ' ';

		std::cout << std::endl;
		for (int i = 0; i < v2.size(); i++)
			std::cout << v2[i] << ' ';

		int a = 0;
	}

	std::cout << std::endl;

	{
		ksw::Vector<int> v1;
		for (int i = 0; i < 8; i++)
			v1.push_back(i + 10);

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