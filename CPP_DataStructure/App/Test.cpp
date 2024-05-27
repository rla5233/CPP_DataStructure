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
	ksw::list<int> li_1;
	ksw::list<int>::iterator it_1;

	li_1.push_back(3);
	li_1.push_back(4);
	li_1.push_back(5);
	li_1.push_front(2);
	li_1.push_front(1);

	for (it_1 = li_1.begin(); it_1 != li_1.end(); ++it_1)
	{
		PrintFor(*it_1);
	}


}
