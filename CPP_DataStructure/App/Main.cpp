#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::vector<int> v1 = { 1, 2, 3, 4, 5 };
		
		v1.resize(10, 1);
		v1.resize(15, 2);
		//v1.reserve(6);

		auto it1 = v1.end() - 5;

		auto it2 = v1.insert(it1, -1);

		int a = 0;
	}

	std::cout << std::endl;

	{
		ksw::Vector<int> v1;
		//v1.reserve(6);
		for (int i = 0; i < 6; i++)
			v1.push_back(i + 1);

		v1.assign(10, 1);
		v1.assign(15, 2); 

		auto it1 = v1.begin();
		auto it2 = v1.insert(it1, -1);

		for (auto it = v1.begin(); it != v1.end(); ++it)
			std::cout << *it << ' ';
	}

	return 0;
}