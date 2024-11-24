#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::vector<int> v1;

		v1.reserve(10);
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		//v1 = { 1, 2, 3, 4, 5 };

		std::vector<int> v2;
		v2 = v1;

		for (int i = 0; i < v1.size(); i++)
			std::cout << v1[i] << ' ';

		std::cout << std::endl;
		for (int i = 0; i < v1.size(); i++)
			std::cout << v2[i] << ' ';

		int a = 0;
	}

	std::cout << std::endl;

	{
		ksw::Vector<int> v1;

		v1.reserve(10);
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		//v1 = { 1, 2, 3, 4, 5 };

		ksw::Vector<int> v2;
		v2 = v1;

		for (int i = 0; i < v1.size(); i++)
			std::cout << v1[i] << ' ';

		std::cout << std::endl;
		for (int i = 0; i < v1.size(); i++)
			std::cout << v2[i] << ' ';

		int a = 0;
	}

	return 0;
}