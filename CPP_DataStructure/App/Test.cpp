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
	PrintEndl("<List Å×½ºÆ®>");

	ksw::list<int> li1;
	ksw::list<int> li2(1, 5);
	ksw::list<int>::iterator it1;

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
	
	Endl();
	for (it1 = li1.begin(); it1 != li1.end(); ++it1)
	{
		PrintFor(*it1);
	}

	{
		std::string str = "Size : " + std::to_string(li1.size());
		EndlPrint(str);
	}

	it1 = li1.begin();
	it1 = li1.erase(it1);
	EndlPrint(*it1);

	EndlPrint(li1.empty());

	Endl();
	for (it1 = li2.begin(); it1 != li2.end(); ++it1)
	{
		PrintFor(*it1);
	}

	li2.clear();

	Endl();
	for (it1 = li2.begin(); it1 != li2.end(); ++it1)
	{
		PrintFor(*it1);
	}

	//std::list<int> li3;

}
