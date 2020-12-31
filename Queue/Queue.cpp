//#include<iostream>
//using namespace std;
//template<typename Object>
//class Queue_ADT
//{
//protected:
//	int size;
//	int limit;
//public:
//	virtual void En_Queue(Object d) = 0;
//	virtual Object De_Queue() = 0;
//	virtual int Size() = 0;
//	virtual bool Is_Empty() = 0;
//	virtual Object Peek() = 0;
//	virtual void Empty_Queue() = 0;
//};
//
//template<typename Object>
//class Queue :public Queue_ADT<Object>
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
//
//	ListNode *Exit;
//	ListNode *Start;
//public:
//	Queue()
//	{
//		Exit = NULL;
//		Start = NULL;
//		size = -1;
//		limit = 0;
//	}
//
//	Queue(int s)
//	{
//		if (s <= 0)
//		{
//			throw - 1;
//		}
//		Exit = NULL;
//		Start = NULL;
//		size = s;
//	}
//
//	void En_Queue(Object d)
//	{
//		if (size == limit)
//		{
//			cout << "\nStack has been filled!! ";
//			throw -1;
//		}
//		limit++;
//		if (Exit == NULL)
//		{
//			Exit = new ListNode(d);
//			Start = Exit;
//			return;
//		}
//		Start->next = new ListNode(d);
//		Start = Start->next;
//	}
//	Object De_Queue()
//	{
//		if (Exit == NULL)
//		{
//			throw 0;
//		}
//		if (Exit == Start)
//		{
//			Start = NULL;
//		}
//		ListNode *tmp = Exit->next;
//		Object data = Exit->data;
//		limit--;
//		delete Exit;
//		Exit = tmp;
//		return data;
//	}
//	int Size()
//	{
//		return limit;
//	}
//	bool Is_Empty()
//	{
//		if (Exit == NULL)
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
//		if (Exit == NULL)
//		{
//			throw;
//		}
//		return Exit->data;
//	}
//	void Empty_Queue()
//	{
//		ListNode *tmp = Exit;
//		while (tmp != NULL)
//		{
//			ListNode *tmp1 = tmp->next;
//			delete tmp;
//			tmp = tmp1;
//		}
//		Exit = NULL;
//		Start = NULL;
//		limit = 0;
//	}
//
//	~Queue()
//	{
//		ListNode *tmp = Exit, *tmp1;
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
//	Queue_ADT<double> *s=new Queue<double>();
//	s->En_Queue(12.221);
//	cout << s->De_Queue();
//	system("pause");
//	return 0;
//}