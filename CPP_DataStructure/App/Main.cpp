#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::vector<int> v;

		for (int i = 0; i < 5; i++)
			v.push_back(i);

		v.pop_back();

		v.push_back(5);

		v.resize(8);

		v.clear();

		int a = 0;
	}

	{
		ksw::Vector<int> v;
		
		v.reserve(10);

		v.resize(5, 5);

		for (int i = 0; i < 10; i++)
			v.push_back(i + 10);

		for (int i = 0; i < 5; i++)
			v.pop_back();

		v.clear();

		v.resize(7, 10);

		v.clear();

		if (v.empty())
			int b = 0;
	

		int a = 0;
	}

	return 0;
}