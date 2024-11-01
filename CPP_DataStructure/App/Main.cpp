#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::list<int> li;


	}

	{
		ksw::DoubleList<int> li;

		for (int i = 0; i < 5; i++)
		{
			li.push_back(i + 10);
		}

		for (int i = 0; i < 5; i++)
		{
			li.push_front(i + 10);
		}
	}
	




	return 0;
}