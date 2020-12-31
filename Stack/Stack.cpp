//#include<iostream>
//using namespace std;
//
//template<typename Object>
//class Stack_ADT
//{
//protected:
//	int size;
//	int limit;
//public:
//	virtual void Push(Object d) = 0;
//	virtual Object Pop() = 0;
//	virtual int Size() = 0;
//	virtual bool Is_Empty() = 0;
//	virtual Object Peek() = 0;
//	virtual void Empty_Stack() = 0;
//};
//
//template<typename Object>
//class Stack :public Stack_ADT<Object>
//{
//private:
//	class ListNode
//	{
//	public:
//		Object data;
//		ListNode *next;
//		ListNode(Object d)
//		{
//			data = d;
//			next = NULL;
//		}
//	};
//	ListNode *Top;
//public:
//	Stack()
//	{
//		Top = NULL;
//		size = -1;
//		limit = 0;
//	}
//
//	Stack(int s)
//	{
//		if (s <= 0)
//		{
//			throw - 1;
//		}
//		Top = NULL;
//		size = s;
//	}
//
//	void Push(Object d)
//	{
//		if (size == limit)
//		{
//			cout << "\nStack has been filled!! ";
//			throw -1;
//		}
//			limit++;
//		ListNode *add = new ListNode(d);
//		add->next = Top;
//		Top = add;
//	}
//	Object Pop()
//	{
//		if (Top == NULL)
//		{
//			throw 0;
//		}
//		ListNode *tmp = Top->next;
//		Object data = Top->data;
//		limit--;
//		delete Top;
//		Top = tmp;
//		return data;
//	}
//	int Size()
//	{
//		return limit;
//	}
//	bool Is_Empty()
//	{
//		if (Top == NULL)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	Object Peek()
//	{
//		if (Top == NULL)
//		{
//			throw;
//		}
//		return Top->data;
//	}
//	void Empty_Stack()
//	{
//		ListNode *tmp = Top;
//		while (tmp != NULL)
//		{
//			ListNode *tmp1 = tmp->next;
//			delete tmp;
//			tmp = tmp1;
//		}
//		Top = NULL;
//		limit = 0;
//	}
//	~Stack()
//	{
//		ListNode *tmp = Top, *tmp1;
//		while (tmp != NULL && tmp->next != NULL)
//		{
//			tmp1 = tmp->next;
//			delete tmp;
//			tmp = tmp1;
//		}
//		delete tmp;
//	}
//};
//
//int main()
//{
//	Stack_ADT<double> *s = new Stack<double>();
//	for (int i = 0; i < 20; i++)
//	{
//		try
//		{
//			s->Push(i+0.98);
//		}
//		catch (int exception)
//		{
//			if (exception == 0)
//			{
//				cout << "\nStack has been filled.";
//			}
//		}
//	}
//	cout << endl << endl << s->Size();
//	for (int i = 0; i < 20; i++)
//	{
//		try
//		{
//			cout << endl << (i + 1) << " ->  " << s->Pop();
//		}
//		catch (int exception)
//		{
//			if (exception == 0)
//			{
//				cout << "\nNo data exists in Stack.";
//			}
//		}
//	}
//	cout << endl << endl << s->Size();
//	cout << endl << s->Is_Empty();
//	s->Push(12);
//	cout<<s->Is_Empty();
//	s->Peek();
//	s->Empty_Stack();
//	cout<<s->Size();
//	system("pause");
//	return 0;
//}