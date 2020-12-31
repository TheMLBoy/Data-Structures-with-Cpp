//#include<iostream>
//using namespace std;
//
//
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
//	int Start, End, size, Present_size;
//	Object *Data;
//	void Extend_Queue()	
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
//	bool isFull()
//	{
//		return (Present_size == size) ? true : false;
//	}
//		
//public:
//	Queue()
//	{
//		size = 100;
//		Data = new Object[size];
//		Start = 0;
//		End = 0;
//	}
//
//	Queue(int s)
//	{
//		if (s <= 0)
//		{
//			throw - 1;
//		}
//		size = s;
//		Data = new Object[size];
//		Start = 0;
//		End = 0;
//	}
//
//	void En_Queue(Object d)
//	{
//		if (isFull())
//		{
//			Extend_Queue();
//		}
//		if (isFull())
//		{
//			throw - 1;
//		}
//		Data[End] = d;
//		End = (End + 1) % size;
//		Present_size++;
//	}
//	Object De_Queue()
//	{
//		if (Is_Empty())
//		{
//			throw - 1;
//		}
//		Object ret = Data[Start];
//		Start = (Start + 1) % size;
//		Present_size--;
//		return ret;
//	}
//	int Size()
//	{
//		return Present_size;
//	}
//	bool Is_Empty()
//	{
//		return Present_size == 0 ? true : false;
//	}
//	Object Peek()
//	{
//		return Data[Start];
//	}
//	void Empty_Queue()
//	{
//		Start = End = 0;
//	}
//	~Queue()
//	{
//		delete[]Data;
//	}
//};
//
//int main()
//{
//	Queue_ADT<double> *s = new Queue<double>();
//	s->En_Queue(12.221);
//	cout << s->De_Queue()<<" "<<s->Size();
//	system("pause");
//	return 0;
//}