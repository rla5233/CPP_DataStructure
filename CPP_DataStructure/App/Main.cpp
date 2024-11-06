#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		std::pair<std::string, int> p1 = { "AAA", 2 };
		std::pair<std::string, int> p2 = { "BBB", 0 };
		p1 = p2;

		std::cout << p1.first << std::endl;
		std::cout << p1.second << std::endl;
	}

	{
		ksw::Pair<std::string, int> p1 = { "AAA", 2 };
		ksw::Pair<std::string, int> p2 = { "BBB", 0 };
		p1 = p2;

		std::cout << p1.first << std::endl;
		std::cout << p1.second << std::endl;
	}

	return 0;
}