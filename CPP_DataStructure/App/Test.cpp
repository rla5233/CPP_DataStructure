#include "PreCompile.h"
#include "Test.h"

Test::Test()
{
}

Test::~Test()
{
}

void Test::TestFunc()
{
	PrintEndl("<Queue Å×½ºÆ®>");

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
	

	std::queue<int> q2;
}
