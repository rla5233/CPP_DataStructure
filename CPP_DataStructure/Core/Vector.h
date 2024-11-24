#pragma once

namespace ksw
{
	template<typename T>
	class Vector
	{
	private:
		T* DataPtr = nullptr;
		size_t Size = 0;
		size_t Capacity = 0;

	public:
		// iterator
		class iterator
		{
			friend class Vector;
		public:

		};

	public:
		// Constructor
		Vector() {};
		Vector(const size_t _Size);
		Vector(const size_t _Size, const T& _Val);
		Vector(const Vector& _Other);

		// Destructor
		~Vector();

		// Operator
		inline Vector& operator=(const Vector& _Other)
		{
			reserve(_Other.Size);

			for (size_t i = 0; i < _Other.Size; ++i)
				push_back(_Other.DataPtr[i]);

			return *this;
		}

		inline T& operator[] (const size_t _Pos)
		{
			return DataPtr[_Pos];
		}

	public:
		// Member Function
		inline T& front();
		inline T& back();

		inline void reserve(const size_t _NewCapacity);
		inline void resize(const size_t _NewSize);
		inline void resize(const size_t _NewSize, const T& _Val);

		inline void push_back(const T& _Val);
		inline void pop_back();

		inline size_t size();
		inline size_t capacity();
		inline bool empty();
		inline void clear();

		// begin
		// end
		// insert
		// erase
		
		// at
		// assign

		// swap

	};

	// ±¸Çö
	template<typename T>
	inline Vector<T>::Vector(const size_t _Size)
	{
		reserve(_Size);

		for (size_t i = 0; i < _Size; ++i)
			push_back(T());
	}

	template<typename T>
	inline Vector<T>::Vector(const size_t _Size, const T& _Val)
	{
		reserve(_Size);

		for (size_t i = 0; i < _Size; ++i)
			push_back(_Val);
	}

	template<typename T>
	inline Vector<T>::Vector(const Vector& _Other)
	{
		reserve(_Other.Size);

		for (size_t i = 0; i < _Other.Size; ++i)
			push_back(_Other.DataPtr[i]);
	}

	template<typename T>
	inline Vector<T>::~Vector()
	{
		clear();

		if (nullptr != DataPtr)
		{
			delete[] DataPtr;
			DataPtr = nullptr;
		}
	}

	template<typename T>
	inline T& Vector<T>::front()
	{
		if (0 == Size)
			MsgBoxAssert("Vector is Empty");

		return DataPtr[0];
	}

	template<typename T>
	inline T& Vector<T>::back()
	{
		if (0 == Size)
			MsgBoxAssert("Vector is Empty");

		return DataPtr[Size - 1];
	}

	template<typename T>
	inline void Vector<T>::reserve(const size_t _NewCapacity)
	{
		if (_NewCapacity > Capacity)
		{
			T* Temp = DataPtr;
			DataPtr = new T[_NewCapacity];
			Capacity = _NewCapacity;
			
			if (nullptr != Temp)
			{
				for (int i = 0; i < Size; ++i)
					DataPtr[i] = Temp[i];

				delete[] Temp;
				Temp = nullptr;
			}
		}
	}

	template<typename T>
	inline void Vector<T>::resize(const size_t _NewSize)
	{
		size_t Diff = std::llabs(_NewSize - Size);

		if (_NewSize > Size)
		{
			for (size_t i = 0; i < Diff; ++i)
				push_back(T());
		}
		else if (_NewSize < Size)
		{
			for (size_t i = 0; i < Diff; ++i)
				pop_back();
		}

		Size = _NewSize;
	}

	template<typename T>
	inline void Vector<T>::resize(const size_t _NewSize, const T& _Val)
	{
		size_t Diff = std::llabs(_NewSize - Size);

		if (_NewSize > Size)
		{
			for (size_t i = 0; i < Diff; ++i)
				push_back(_Val);
		}
		else if (_NewSize < Size)
		{
			for (size_t i = 0; i < Diff; ++i)
				pop_back();
		}

		Size = _NewSize;
	}

	template<typename T>
	inline void Vector<T>::push_back(const T& _Val)
	{
		if (Capacity == Size)
		{
			int NewCapacity = static_cast<int>(Capacity * 1.5);
			if (NewCapacity == Capacity)
				++NewCapacity;

			reserve(NewCapacity);
		}

		DataPtr[Size] = _Val;
		++Size;
	}

	template<typename T>
	inline void Vector<T>::pop_back()
	{
		if (0 == Size)
			MsgBoxAssert("Vector is Empty");

		--Size;
	}

	template<typename T>
	inline size_t Vector<T>::size()
	{
		return Size;
	}

	template<typename T>
	inline size_t Vector<T>::capacity()
	{
		return Capacity;
	}

	template<typename T>
	inline bool Vector<T>::empty()
	{
		return Size == 0;
	}

	template<typename T>
	inline void Vector<T>::clear()
	{
		Size = 0;
	}
}