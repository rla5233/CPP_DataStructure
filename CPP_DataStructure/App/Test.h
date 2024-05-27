#pragma once

// Ό³Έν :
class Test
{
public:
	// constrcuter destructer
	Test();
	~Test();

	// delete Function
	Test(const Test& _Other) = delete;
	Test(Test&& _Other) noexcept = delete;
	Test& operator=(const Test& _Other) = delete;
	Test& operator=(Test&& _Other) noexcept = delete;

	template<typename Type>
	static void PrintFor(Type _Data)
	{
		std::cout << _Data << " ";
	}
	
	static void Endl()
	{
		std::cout << std::endl;
	}

public:
	static void ListTest();


};

