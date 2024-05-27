#pragma once

namespace ksw
{
	// 설명 : list 클래스

	template<typename Type>
	class list
	{
	private:
		class Node
		{
		public:
			Node* Prev = nullptr;
			Node* Next = nullptr;
			Type Data = Type();
		};

	public:
		class iterator
		{
			friend class list;
		public:
			iterator() {};

			iterator(Node* _CurNode)
				: CurNode(_CurNode)
			{};

			~iterator() {};

			// 이거 수정 필요 할 듯
			inline void operator++()
			{
				CurNode = CurNode->Next;
			}

			// 이거 수정 필요 할 듯
			inline void operator--()
			{
				CurNode = CurNode->Prev;
			}

			inline Type& operator*()
			{
				return CurNode->Data;
			}

			inline bool operator!=(const iterator& _Other)
			{
				return CurNode != _Other.CurNode;
			}

			inline bool operator==(const iterator& _Other)
			{
				return CurNode == _Other.CurNode;
			}

		private:
			Node* CurNode = nullptr;
		};

	public:
		// constructor destructor
		list();
		list(size_t _Size); // 수정
		list(Type _Data, size_t _Size); // 수정
		~list();

		// delete Function
		list(const list& _Other) = delete;
		list(list&& _Other) noexcept = delete;
		list& operator=(const list& _Other) = delete;
		list& operator=(list&& _Other) noexcept = delete;

	public:
		inline Type front();
		inline Type back();

		inline void push_front(const Type& _Data);
		inline void push_back(const Type& _Data);

		inline void pop_front();
		inline void pop_back();

		inline void clear();// 수정

		inline size_t size()
		{
			return Size;
		}

		inline bool empty()
		{
			return Size == 0;
		}

		// iterator
	public:
		inline iterator begin()
		{
			return iterator(Start->Next);
		}

		inline iterator end()
		{
			return iterator(End);
		}

		inline iterator insert(iterator& _Iter, const Type& _Data)// 수정
		{
			Node* NewNode = new Node();
			NewNode->Data = _Data;

			if (nullptr == Start)
			{
				_Iter->CurNode = NewNode;
				_Iter->CurNode->Next = nullptr;
				_Iter->CurNode->Prev = nullptr;

				Start = _Iter->CurNode;
				End = _Iter->CurNode;
			}
			else if (Start == _Iter->CurNode)
			{
				Node* NextNode = Start->Next;
				Node* PrevNode = nullptr;

				_Iter->CurNode = NewNode;
				_Iter->CurNode->Next = NextNode;
				_Iter->CurNode->Prev = PrevNode;

				Start = _Iter->CurNode;
			}

			++Size;
			return _Iter;
		}

		inline iterator erase(iterator& _Iter)// 수정
		{
			Node* NextNode = _Iter.CurNode->Next;
			Node* PrevNode = _Iter.CurNode->Prev;

			if (Start == _Iter.CurNode)
			{
				if (nullptr != NextNode)
				{
					NextNode->Prev = nullptr;
				}
				else
				{
					End = nullptr;
				}

				Start = NextNode;
			}
			else if (End == _Iter.CurNode)
			{
				if (nullptr != PrevNode)
				{
					PrevNode->Next = nullptr;
				}
				else
				{
					Start = nullptr;
				}

				End = PrevNode;
			}
			else
			{
				NextNode->Prev = PrevNode;
				PrevNode->Next = NextNode;
			}

			delete _Iter.CurNode;
			--Size;

			_Iter.CurNode = NextNode;
			return _Iter;
		}


	private:
		Node* Start = nullptr;
		Node* End = nullptr;
		size_t Size = 0;

	};

	// 구현부
	template<typename Type>
	inline list<Type>::list()
	{
		Start = new Node();
		End = new Node();

		Start->Next = End;
		End->Prev = Start;
	}

	template<typename Type>
	inline list<Type>::list(size_t _Size)
	{
		for (size_t i = 0; i < _Size; i++)
		{
			push_back(Type());
		}
	}

	template<typename Type>
	inline list<Type>::list(Type _Data, size_t _Size)
	{
		for (size_t i = 0; i < _Size; i++)
		{
			push_back(_Data);
		}
	}

	template<typename Type>
	inline ksw::list<Type>::~list()
	{
		Node* CurNode = Start;
		while (nullptr != CurNode)
		{
			Node* Next = CurNode->Next;
			delete CurNode;
			CurNode = Next;
		}
	}

	template<typename Type>
	inline Type list<Type>::front()
	{
		return Start->Next->Data;
	}

	template<typename Type>
	inline Type list<Type>::back()
	{
		return End->Prev->Data;
	}

	template<typename Type>
	inline void list<Type>::push_front(const Type& _Data)
	{
		Node* NewNode = new Node;
		NewNode->Data = _Data;

		Node* NextNode = Start->Next;
		Start->Next = NewNode;

		NewNode->Prev = Start;
		NewNode->Next = NextNode;
		NextNode->Prev = NewNode;

		++Size;
	}

	template<typename Type>
	inline void list<Type>::push_back(const Type& _Data)
	{
		Node* NewNode = new Node;
		NewNode->Data = _Data;

		Node* PrevNode = End->Prev;
		End->Prev = NewNode;

		NewNode->Prev = PrevNode;
		NewNode->Next = End;
		PrevNode->Next = NewNode;

		++Size;
	}

	template<typename Type>
	inline void list<Type>::pop_front()
	{
		Node* CurNode = Start->Next;
		Node* NextNode = CurNode->Next;

		Start->Next = NextNode;
		NextNode->Prev = Start;

		delete CurNode;
		--Size;
	}

	template<typename Type>
	inline void list<Type>::pop_back()
	{
		Node* CurNode = End->Prev;
		Node* PrevNode = CurNode->Prev;

		End->Prev = PrevNode;
		PrevNode->Next = End;
		
		delete CurNode;
		--Size;
	}

	template<typename Type>
	inline void list<Type>::clear()
	{
		Node* CurNode = Start;
		while (nullptr != CurNode)
		{
			Node* NextNode = CurNode->Next;
			delete CurNode;
			CurNode = NextNode;
		}

		Start = nullptr;
		End = nullptr;
		Size = 0;
	}
}


