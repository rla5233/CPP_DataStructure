#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	Timer::TimeCheck([=]
		{
			std::cout << "std::list";
			std::list<int> li;
			for (int i = 0; i < 2; i++)
			{
				li.push_back(i);
			}

			li.clear();
		}
	);

	Timer::TimeCheck([=]
		{
			std::cout << "std::vector";
			std::vector<int> vec;
			for (int i = 0; i < 2; i++)
			{
				vec.push_back(i);
			}
			
			vec.clear();
		}
	);

	return 0;
}