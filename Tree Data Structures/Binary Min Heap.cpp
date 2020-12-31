//#include<iostream>
//#include<cmath>
//#include<set>
//#include<stack>
//#include<Windows.h>
//using namespace std;
//
//template<typename Object>
//class Binary_Min_Heap
//{
//private:
//	Object *Heap;
//	int Heap_Size, max_size;
//	int parent(int ind)
//	{
//		return floor((ind - 1) / 2);
//	}
//	int Left_child(int ind)
//	{
//		return (2 * ind) + 1;
//	}
//
//	int Right_child(int ind)
//	{
//		return (2 * ind) + 2;
//	}
//
//	int check_parent_child(int ind)
//	{
//		if (ind<0 || ind >Heap_Size)
//		{
//			return false;
//		}
//		else
//		{
//			return true;
//		}
//	}
//
//	int size()
//	{
//		return Heap_Size;
//	}
//
//	void PushUp(int ind)
//	{
//		int p = parent(ind);
//		if (ind == 0 || !check_parent_child(p) || Heap[ind] > Heap[parent(ind)])
//		{
//			return;
//		}
//		swap(Heap[ind], Heap[p]);
//		PushUp(parent(ind));
//	}
//
//	void PushDown(int i)
//	{
//		int left = Left_child(i);
//		int right = Right_child(i);
//		int smallest = i;
//
//		if (left < size() && Heap[left] < Heap[i])
//		{
//			smallest = left;
//		}
//
//		if (right < size() && Heap[right] < Heap[smallest])
//		{
//			smallest = right;
//		}
//
//		if (smallest != i)
//		{
//			swap(Heap[i], Heap[smallest]);
//			PushDown(smallest);
//		}
//	}
//
//	bool isPowerOfTwo(int n)
//	{
//		if (n == 0)
//			return false;
//		return (ceil(log2(n)) == floor(log2(n)));
//	}
//
//public:
//	Binary_Min_Heap()
//	{
//		Heap_Size = 0;
//		max_size = 100;
//		Heap = new Object[max_size];
//	}
//	Binary_Min_Heap(int index)
//	{
//		Heap_Size = 0;
//		max_size = index;
//		Heap = new Object[max_size];
//	}
//
//	Binary_Min_Heap(const Binary_Min_Heap &rhs)
//	{
//		this = rhs;
//	}
//
//	Binary_Min_Heap& operator=(Binary_Min_Heap &rhs)
//	{
//		delete Heap;
//		this->Heap = new Object[rhs.max_size];
//		this->max_size = rhs.max_size;
//		this->Heap_Size = rhs.Heap_Size;
//		for (int i = 0; i < Heap_Size; i++)
//		{
//			this->Heap[i] = rhs.Heap[i];
//		}
//		return *this;
//	}
//
//	void Insert(Object t)
//	{
//		if (Heap_Size == max_size)
//		{
//			cout << "\nHeap has filled.";
//			return;
//		}
//		Heap[Heap_Size++] = t;
//		PushUp(Heap_Size - 1);
//	}
//
//	void Delete(int index)
//	{
//		Heap[index] = Heap[--Heap_Size];
//		PushDown(index);
//		print();
//	}
//
//	void print()
//	{
//		int i;
//		set<int>q;
//		set<int>::iterator it;
//		for (i = 0; i < Heap_Size; i++)
//		{
//			q.insert(Heap[i]);
//		}
//		for (it = q.begin(), i = 2; it != q.end(); it++,i++)
//		{
//			cout << *it << "  ";
//			if (isPowerOfTwo(i))
//			{
//				cout << endl;
//			}
//		}
//	}
//
//	void indent(Binary_Min_Heap &H1, Binary_Min_Heap &H2)
//	{
//		int i = 0, j = 0;
//		this->max_size = H1.Heap_Size + H2.Heap_Size;
//		Heap_Size = max_size;
//		delete Heap;
//		Heap = new Object[max_size];
//		for (i = 0; i <H1.Heap_Size; i++)
//		{
//			Heap[i] = H1.Heap[i];
//		}
//		for (int k = 0, j = i; k < H2.Heap_Size; k++, j++)
//		{
//			Heap[j] = H2.Heap[k];
//		}
//		for (i = 0; i <Heap_Size; i++)
//		{
//			PushDown(i);
//		}
//	}
//
//	Object Get_Min()
//	{
//		return Heap[0];
//	}
//
//	void Delete_Min()
//	{
//		swap(Heap[0], Heap[Heap_Size - 1]);
//		Heap_Size--;
//		PushDown(0);
//	}
//
//	~Binary_Min_Heap()
//	{
//		delete[]Heap;
//	}
//};
//
//int main()
//{
//	Binary_Min_Heap<int> b;
//	b.Insert(23);
//	b.Insert(12);
//	b.Insert(4);
//	b.Insert(11);
//	b.Insert(12);
//	b.Insert(16);
//	b.Insert(18);
//	b.Insert(123);
//	b.Insert(88);
//	b.Insert(77);
//	cout << "1st Heap : " << endl;
//	b.print();
//	system("pause");
//	return 0;
//}