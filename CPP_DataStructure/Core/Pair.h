#pragma once

namespace ksw
{
	template<typename T1, typename T2>
	struct Pair
	{
	public:
		Pair() {};
		Pair(const T1& _Val1, const T2& _Val2) : first(_Val1), second(_Val2) {};

		~Pair() {};

		void operator=(const Pair& _Other)
		{
			first = _Other.first;
			second = _Other.second;
		}

		inline void swap(Pair& _Other);
		
		T1 first = T1();
		T2 second = T2();

	private:
		inline void swap(T1& _Left, T1& _Right);
		inline void swap(T2& _Left, T2& _Right);

	};

	template<typename T1, typename T2>
	inline void Pair<T1, T2>::swap(Pair& _Other)
	{
		swap(first, _Other.first);
		swap(second, _Other.second);
	}

	template<typename T1, typename T2>
	inline void Pair<T1, T2>::swap(T1& _Left, T1& _Right)
	{
		T1 Temp = _Left;
		_Left = _Right;
		_Right = Temp;
	}

	template<typename T1, typename T2>
	inline void Pair<T1, T2>::swap(T2& _Left, T2& _Right)
	{
		T2 Temp = _Left;
		_Left = _Right;
		_Right = Temp;
	}
}