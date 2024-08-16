#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	Timer::TimeCheck([=]
		{
			std::cout << "std::list";
			std::list<int> li;
			for (int i = 0; i < 1000000; i++)
			{
				li.push_back(i);
			}
			
			std::list<int>::iterator it = li.begin();
			for (int i = 0; i < 500000; i++)
			{
				++it;
			}

			li.erase(it);
		}
	);

	Timer::TimeCheck([=]
		{
			std::cout << "std::vector";
			std::vector<int> vec;
			for (int i = 0; i < 1000000; i++)
			{
				vec.push_back(i);
			}
		
			std::vector<int>::iterator it = vec.begin();
			for (int i = 0; i < 500000; i++)
			{
				++it;
			}

			vec.erase(it);
		}
	);

	return 0;
}