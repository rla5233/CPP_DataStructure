#include "PreCompile.h"
#include "Test.h"

Test::Test()
{
}

Test::~Test()
{
}

void Test::ListTest()
{
	PrintEndl("<List �׽�Ʈ>");

	ksw::list<int> li1;
	ksw::list<int>::iterator it1;
	
	//ksw::list<int> li2(1, 5);

	EndlPrint(li1.empty());

	li1.push_back(3);
	li1.push_back(4);
	li1.push_back(5);
	li1.push_front(2);
	li1.push_front(1);

	Endl();
	for (it1 = li1.begin(); it1 != li1.end(); ++it1)
	{
		PrintFor(*it1);
	}

	{
		std::string str = "Front : " + std::to_string(li1.front());
		EndlPrint(str);
	}

	{
		std::string str = "Back : " + std::to_string(li1.back());
		EndlPrint(str);
	}

	{
		li1.pop_front();
		std::string str = "Front : " + std::to_string(li1.front());
		EndlPrint(str);
	}

	{
		li1.pop_back();
		std::string str = "Back : " + std::to_string(li1.back());
		EndlPrint(str);
	}
}
