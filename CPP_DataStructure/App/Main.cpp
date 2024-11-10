#include "PreCompile.h"
#include "Test.h"

int main()
{
	LeakCheck;

	{
		int* Num1 = new int(2);
		int* Num2 = new int(0);

		std::list<int*> p1 = { Num1 };
		std::list<int*> p2 = { Num2 };
		p2 = p1;

		std::cout << p1.front() << std::endl;
		std::cout << p2.front() << std::endl;

		delete Num1;
		delete Num2;
	}

	{
		int* Num1 = new int(2);
		int* Num2 = new int(0);

		ksw::DoubleList<int*> p1;
		p1.push_back(Num1);

		ksw::DoubleList<int*> p2;
		p2.push_back(Num2);

		//p2.swap(p1);
		p2 = p1;

		std::cout << p1.front() << std::endl;
		std::cout << p2.front() << std::endl;

		delete Num1;
		delete Num2;
	}

	return 0;
}