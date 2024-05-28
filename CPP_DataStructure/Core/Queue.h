#pragma once

namespace ksw
{
	template<typename Type>
	class queue
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
		public:
			iterator() {};
			iterator(Node* _CurNode)
				: CurNode(_CurNode)
			{};

			~iterator() {};


		private:
			Node* CurNode = nullptr;
		};

	public:
		queue();
		~queue();

	public:
		void clear();

	private:
		Node* Start = nullptr;
		Node* End = nullptr;

		size_t Size = 0;
	};

	// ±¸ÇöºÎ
	template<typename Type>
	inline queue<Type>::queue()
	{
		Start = new Node();
		End = new Node();

		Start->Next = End;
		End->Prev = Start;
	}

	template<typename Type>
	inline ksw::queue<Type>::~queue()
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
	inline void queue<Type>::clear()
	{
		Node* CurNode = Start->Next;

		while (End != CurNode)
		{
			Node* NextNode = CurNode->Next;
			delete CurNode;
			CurNode = NextNode;
		}

		Size = 0;
	}


}