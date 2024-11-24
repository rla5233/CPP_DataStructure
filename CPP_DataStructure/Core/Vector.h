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
			iterator(T* _DataPtr, T* _Start, T* _End)
				: CurDataPtr(_DataPtr), Start(_Start), End(_End) {};
			~iterator() {};

			// 전위
			inline iterator operator++()
			{
				if (End == CurDataPtr)
					MsgBoxAssert("Invaild Vector Range");

				++CurDataPtr;
				return *this;
			}

			// 후위
			inline iterator operator++(int)
			{
				if (End == CurDataPtr)
					MsgBoxAssert("Invaild Vector Range");

				iterator Temp(CurDataPtr++, Start, End);
				return Temp;
			}

			// 전위
			inline iterator operator--()
			{
				if (Start == CurDataPtr)
					MsgBoxAssert("Invaild Vector Range");

				--CurDataPtr;
				return *this;
			}

			// 후위
			inline iterator operator--(int)
			{
				if (Start == CurDataPtr)
					MsgBoxAssert("Invaild Vector Range");

				iterator Temp(CurDataPtr--, Start, End);
				return Temp;
			}

			inline iterator operator+(size_t _Off)
			{
				T* Temp = CurDataPtr + _Off;
				if (Start > Temp || End < Temp)
					MsgBoxAssert("Invaild Vector Range")

				return iterator(Temp, Start, End);
			}

			inline iterator operator-(size_t _Off)
			{
				T* Temp = CurDataPtr - _Off;
				if (Start > Temp || End < Temp)
					MsgBoxAssert("Invaild Vector Range")

				return iterator(Temp, Start, End);
			}

			inline T& operator*()
			{
				if (Start > CurDataPtr || End <= CurDataPtr)
					MsgBoxAssert("Invaild Vector Range")

				return *CurDataPtr;
			}

			inline bool operator==(const iterator& _Other)
			{
				return CurDataPtr == _Other.CurDataPtr;
			}

			inline bool operator!=(const iterator& _Other)
			{
				return CurDataPtr != _Other.CurDataPtr;
			}

		private:
			T* CurDataPtr = nullptr;
			T* Start = nullptr;
			T* End = nullptr;
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
		// iterator
		inline iterator begin()
		{
			return iterator(DataPtr, DataPtr, DataPtr + Size);
		}

		inline iterator end()
		{
			return iterator(DataPtr + Size, DataPtr, DataPtr + Size);
		}

		inline iterator insert(const iterator& _Iter, const T& _Val)
		{
			iterator Temp = _Iter;
			
			if (++Size > Capacity)
			{
				size_t NewCapacity = static_cast<size_t>(Capacity * 1.5);
				if (NewCapacity == Capacity)
					++NewCapacity;
				
				T* NewDataPtr = new T[NewCapacity];
				size_t Diff = _Iter.CurDataPtr - DataPtr;




				if (nullptr != DataPtr)
				{
					delete[] DataPtr;
					DataPtr = nullptr;
				}

				Capacity = NewCapacity;
				DataPtr = NewDataPtr;
			}
			else
			{
				for (auto it = end() - 1; it != _Iter; --it)
					*it = *(it - 1);

				(*Temp.CurDataPtr) = _Val;
			}
			
			return Temp;
		}
		
		// erase


	public:
		// Member Function
		inline T& front();
		inline T& back();
		inline T& at(size_t _Pos);

		inline void reserve(const size_t _NewCapacity);
		inline void resize(const size_t _NewSize);
		inline void resize(const size_t _NewSize, const T& _Val);
		inline void assign(const size_t _NewSize, const T& _Val);

		inline void push_back(const T& _Val);
		inline void pop_back();

		inline size_t size();
		inline size_t capacity();
		inline bool empty();
		inline void clear();

		inline void swap(Vector& _Other);
	};

	// 구현
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
	inline T& Vector<T>::at(size_t _Pos)
	{
		if (0 == Size)
			MsgBoxAssert("Vector is Empty");

		if (Size <= _Pos)
			MsgBoxAssert("Invaild Vector Range");

		return DataPtr[_Pos];
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
				for (size_t i = 0; i < Size; ++i)
					DataPtr[i] = Temp[i];

				delete[] Temp;
				Temp = nullptr;
			}
		}
	}

	template<typename T>
	inline void Vector<T>::resize(const size_t _NewSize)
	{
		if (_NewSize > Capacity)
		{
			size_t NewCapacity = static_cast<size_t>(Capacity * 1.5);
			if (NewCapacity == Capacity)
				++NewCapacity;

			reserve(NewCapacity > _NewSize ? NewCapacity : _NewSize);
		}

		size_t Diff = std::llabs(_NewSize - Size);

		if (_NewSize > Size)
		{
			for (size_t i = 0; i < Diff; ++i)
				push_back(T());
		}

		Size = _NewSize;
	}

	template<typename T>
	inline void Vector<T>::resize(const size_t _NewSize, const T& _Val)
	{
		if (_NewSize > Capacity)
		{
			size_t NewCapacity = static_cast<size_t>(Capacity * 1.5);
			if (NewCapacity == Capacity)
				++NewCapacity;

			reserve(NewCapacity > _NewSize ? NewCapacity : _NewSize);
		}

		size_t Diff = std::llabs(_NewSize - Size);

		if (_NewSize > Size)
		{
			for (size_t i = 0; i < Diff; ++i)
				push_back(_Val);
		}

		Size = _NewSize;
	}

	template<typename T>
	inline void Vector<T>::assign(const size_t _NewSize, const T& _Val)
	{
		if (_NewSize > Capacity)
		{
			size_t NewCapacity = static_cast<size_t>(Capacity * 1.5);
			if (NewCapacity == Capacity)
				++NewCapacity;

			Capacity = NewCapacity > _NewSize ? NewCapacity : _NewSize;

			if (nullptr != DataPtr)
			{
				delete[] DataPtr;
				DataPtr = nullptr;
			}

			DataPtr = new T[Capacity];
		}

		for (size_t i = 0; i < _NewSize; ++i)
			DataPtr[i] = _Val;

		Size = _NewSize;
	}

	template<typename T>
	inline void Vector<T>::push_back(const T& _Val)
	{
		if (Capacity == Size)
		{
			size_t NewCapacity = static_cast<size_t>(Capacity * 1.5);
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

	template<typename T>
	inline void Vector<T>::swap(Vector& _Other)
	{
		T* TempPtr = _Other.DataPtr;
		size_t TempSize = _Other.Size;
		size_t TempCapacity = _Other.Capacity;

		_Other.DataPtr = DataPtr;
		_Other.Size = Size;
		_Other.Capacity = Capacity;

		DataPtr = TempPtr;
		Size = TempSize;
		Capacity = TempCapacity;
	}
}