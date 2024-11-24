#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::vector<int> v1 = { 1, 1, 1, 1, 1, 1 };
		v1.push_back(1);
		std::vector<int> v2 = { 0, 0, 0, 0, 0 };
		v2.swap(v1);

		for (int i = 0; i < v1.size(); i++)
			std::cout << v1[i] << ' ';

		std::cout << std::endl;
		for (int i = 0; i < v2.size(); i++)
			std::cout << v2[i] << ' ';

		int a = 0;
	}

	std::cout << std::endl;

	{
		ksw::Vector<int*> v1;
		for (int i = 0; i < 8; i++)
		{
			int* Ptr = new int(i + 10);
			v1.push_back(Ptr);
		}

		ksw::Vector<int*> v2;
		for (int i = 0; i < 4; i++)
		{
			int* Ptr = new int(i + 10);
			v2.push_back(Ptr);
		}

		v2.swap(v1);

		std::cout << std::endl;
		for (int i = 0; i < v1.size(); i++)
		{
			std::cout << *v1[i] << ' ';
			delete v1[i];
		}

		std::cout << std::endl;
		for (int i = 0; i < v2.size(); i++)
		{
			std::cout << *v2[i] << ' ';
			delete v2[i];
		}

		int a = 0;
	}

	return 0;
}