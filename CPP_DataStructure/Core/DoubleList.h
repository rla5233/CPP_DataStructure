#pragma once

namespace ksw
{
	template<typename T>
	class DoubleList
	{
	private:
		// Node
		class Node
		{
		public:
			Node() {};
			Node(T _Data) : Data(_Data) {};
			~Node() {};

		public:
			Node* Prev = nullptr;
			Node* Next = nullptr;
			T Data = T();
		};

	private:
		Node* Start = nullptr;
		Node* End = nullptr;
		size_t Size = 0;

	public:
		// iterator
		class iterator
		{
			friend class DoubleList;
		public:
			iterator() {};
			iterator(Node* _Node) : CurNode(_Node) {};
			~iterator() {};

			// 전위
			inline iterator& operator++()
			{
				if (nullptr == CurNode->Next)
					MsgBoxAssert("CurNode is End");

				CurNode = CurNode->Next;
				return *this;
			}

			// 후위
			inline iterator operator++(T)
			{
				if (nullptr == CurNode->Next)
					MsgBoxAssert("CurNode is End");

				iterator Temp(CurNode);
				CurNode = CurNode->Next;
				return Temp;
			}

			// 전위
			inline iterator& operator--()
			{
				if (nullptr == CurNode->Prev)
					MsgBoxAssert("CurNode is Start");

				CurNode = CurNode->Prev;
				return *this;
			}

			// 후위
			inline iterator operator--(T)
			{
				if (nullptr == CurNode->Prev)
					MsgBoxAssert("CurNode is Start");

				iterator Temp(CurNode);
				CurNode = CurNode->Prev;
				return Temp;
			}

			inline T& operator*()
			{
				return CurNode->Data;
			}

			inline bool operator==(const iterator& _Other)
			{
				return CurNode == _Other.CurNode;
			}

			inline bool operator!=(const iterator& _Other)
			{
				return CurNode != _Other.CurNode;
			}

		private:
			Node* CurNode = nullptr;
		};


	public:
		// Constructor
		DoubleList();

		// Destructor
		~DoubleList();

	public:
		// iterator
		inline iterator begin()
		{
			return iterator(Start->Next);
		}

		inline iterator end()
		{
			return iterator(End);
		}

		inline iterator insert(const iterator _Where, const T& _Data)
		{
			Node* NewNode = new Node(_Data);
			
			Node* CurNode = _Where.CurNode;
			Node* PrevNode = CurNode->Prev;

			NewNode->Next = CurNode;
			CurNode->Prev = NewNode;

			NewNode->Prev = PrevNode;
			PrevNode->Next = NewNode;

			++Size;
			return iterator(NewNode);
		}

	public:
		// 멤버 함수
		inline T& front();
		inline T& back();

		inline void push_front(const T& _Data);
		inline void push_back(const T& _Data);
		
		inline void pop_front();
		inline void pop_back();
		
		inline size_t size();
		inline bool empty();
		inline void clear();


		// insert
		// erase
		// remove
		// remove if
		// reverse
		// swap
		// sort
	};

	// 구현
	// Constructor & Destructor
	template<typename T>
	inline DoubleList<T>::DoubleList()
	{
		Start = new Node();
		End = new Node();

		Start->Next = End;
		End->Prev = Start;
	}

	template<typename T>
	inline DoubleList<T>::~DoubleList()
	{
		clear();

		Start->Next = nullptr;
		delete Start;

		End->Prev = nullptr;
		delete End;
	}

	// Member Function
	template<typename T>
	inline T& DoubleList<T>::front()
	{
		if (Size == 0)
			MsgBoxAssert("List is Empty");

		return Start->Next->Data;
	}

	template<typename T>
	inline T& DoubleList<T>::back()
	{
		if (Size == 0)
			MsgBoxAssert("List is Empty");
		
		return End->Prev->Data;
	}

	template<typename T>
	inline void DoubleList<T>::push_front(const T& _Data)
	{
		Node* NewNode = new Node(_Data);
		Node* NextNode = Start->Next;
		
		Start->Next = NewNode;
		NewNode->Prev = Start;

		NewNode->Next = NextNode;
		NextNode->Prev = NewNode;
		
		++Size;
	}

	template<typename T>
	inline void DoubleList<T>::push_back(const T& _Data)
	{
		Node* NewNode = new Node(_Data);
		Node* PrevNode = End->Prev;

		End->Prev = NewNode;
		NewNode->Next = End;

		NewNode->Prev = PrevNode;
		PrevNode->Next = NewNode;

		++Size;
	}

	template<typename T>
	inline void DoubleList<T>::pop_front()
	{
		if (Size == 0)
			MsgBoxAssert("List is Empty");

		Node* DelNode = Start->Next;
		Node* NextNode = DelNode->Next;

		Start->Next = NextNode;
		NextNode->Prev = Start;
		--Size;

		DelNode->Next = nullptr;
		DelNode->Prev = nullptr;
		delete DelNode;
	}

	template<typename T>
	inline void DoubleList<T>::pop_back()
	{
		if (Size == 0)
			MsgBoxAssert("List is Empty");

		Node* DelNode = End->Prev;
		Node* PrevNode = DelNode->Prev;

		End->Prev = PrevNode;
		PrevNode->Next = End;
		--Size;
		
		DelNode->Next = nullptr;
		DelNode->Prev = nullptr;
		delete DelNode;
	}

	template<typename T>
	inline size_t DoubleList<T>::size()
	{
		return Size;
	}

	template<typename T>
	inline bool DoubleList<T>::empty()
	{
		return 0 == Size;
	}

	template<typename T>
	inline void DoubleList<T>::clear()
	{
		while (!empty())
		{
			Node* CurNode = Start->Next;
			Node* NextNode = CurNode->Next;
			
			Start->Next = NextNode;
			NextNode->Prev = Start;
			--Size;

			CurNode->Next = nullptr;
			CurNode->Prev = nullptr;
			delete CurNode;
		}
	}
}