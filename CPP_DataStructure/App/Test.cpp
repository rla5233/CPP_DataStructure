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
	PrintEndl("<List 테스트>");

	ksw::list<int> li1;
	ksw::list<int>::iterator it1;
	ksw::list<int>::iterator it2;

	Print(li1.empty());

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

	it1 = li1.begin();
	it1 = li1.erase(it1);

	EndlPrint(*it1);

	Endl();
	for (it1 = li1.begin(); it1 != li1.end(); ++it1)
	{
		PrintFor(*it1);
	}


	it1 = li1.begin();
	it1 = li1.insert(it1, 10);
	it2 = it1++;
	EndlPrint(*it2);
	EndlPrint(*it1);

	li1.push_back(10);
	li1.push_front(10);

	Endl();
	for (it1 = li1.begin(); it1 != li1.end(); ++it1)
	{
		PrintFor(*it1);
	}


	size_t count = li1.remove(10);

	Endl();
	for (it1 = li1.begin(); it1 != li1.end(); ++it1)
	{
		PrintFor(*it1);
	}

	count = li1.front();
	count = li1.back();

	count = 0;
}
void Test::QueueTest()
{
	PrintEndl("<Queue 테스트>");

	ksw::queue<int> q1;

	for (int i = 0; i < 5; i++)
	{
		q1.push(i);
		PrintEndl("Front : " + std::to_string(q1.front()));
		PrintEndl("Back : " + std::to_string(q1.back()));
	}

	Endl();
	size_t Size = q1.size();
	for (size_t i = 0; i < Size; i++)
	{
		PrintEndl("Size : " + std::to_string(q1.size()));
		PrintEndl("Front : " + std::to_string(q1.front()));
		PrintEndl("Back : " + std::to_string(q1.back()));
		q1.pop();
	}

	EndlPrint("Size : " + std::to_string(q1.size()));

}
