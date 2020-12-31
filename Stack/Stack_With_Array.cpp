//#include<iostream>
//#include<conio.h>
//using namespace std;
//
//template<typename Object>
//class Stack_ADT
//{
//protected:
//	Object *Data;
//	int size;
//	int index;
//public:
//	virtual void Push(Object d) = 0;
//	virtual Object Pop() = 0;
//	virtual int Size() = 0;
//	virtual bool Is_Empty() = 0;
//	virtual Object Peek() = 0;
//	virtual void Empty_Stack() = 0;
//};
//template<typename Object>
//class Stack :public Stack_ADT<Object>
//{
//private:
//	void Extend_Stack()
//	{
//		Object *temp = new Object[size + 1];
//		for (int i = 0; i < size;i++)
//		{
//			temp[i] = Data[i];
//		}
//		size++;
//		delete Data;
//		Data=temp;
//	}
//
//public:
//	Stack()
//	{
//		Data = new Object[100];
//		size = 100;
//		index = 0;
//	}
//	Stack(int s)
//	{
//		Data = new Object[s];
//		size = s;
//		index = 0;
//	}
//	~Stack()
//	{
//		delete[]Data;
//	}
//	void Push(Object d)
//	{
//		if (index == size)
//		{
//			Extend_Stack();
//		}
//		if (index == size)
//		{
//			throw - 1;
//		}
//		Data[index++] = d;
//	}
//	Object Pop()
//	{
//		if (index == 0)
//		{
//			throw - 1;
//		}
//		return Data[--index];
//	}
//	int Size()
//	{
//		return index;
//	}
//	bool Is_Empty()
//	{
//		if (index == 0)
//		{
//			return 1;
//		}
//		return 0;
//	}
//	Object Peek()
//	{
//		return Data[index - 1];
//	}
//	void Empty_Stack()
//	{
//		index = 0;
//	}
//};
//
//int main()
//{
//	Stack_ADT<int> *s = new Stack<int>();
//	s->Push(123);
//	cout << s->Size();
//	cout<<s->Pop();
//	cout << endl << s->Size();
//	system("pause");
//	return 0;
//}