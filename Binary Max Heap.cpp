//#include<iostream>
//#include<cmath>
//#include<set>
//#include<stack>
//#include<Windows.h>
//using namespace std;
//
//template<typename Object>
//class Binary_Max_Heap
//{
//private:
//	Object *Heap;
//	int Heap_Size,max_size;
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
//		if (ind == 0 || !check_parent_child(p) || Heap[ind] < Heap[parent(ind)])
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
//		int largest = i;
//		
//		if (left < size() && Heap[left] > Heap[i])
//		{
//			largest = left;
//		}
//
//		if (right < size() && Heap[right] > Heap[largest])
//		{
//			largest = right;
//		}
//
//		if (largest != i)
//		{
//			swap(Heap[i], Heap[largest]);
//			PushDown(largest);
//		}
//	}
//
//public:
//	Binary_Max_Heap()
//	{
//		Heap_Size = 0;
//		max_size = 100;
//		Heap = new Object[max_size];
//	}
//	Binary_Max_Heap(int index)
//	{
//		Heap_Size = 0;
//		max_size = index;
//		Heap = new Object[max_size];
//	}
//
//	Binary_Max_Heap(const Binary_Max_Heap &rhs)
//	{
//		cout << "copy...................";
//		this = rhs;
//	}
//
//	Binary_Max_Heap& operator=(Binary_Max_Heap &rhs)
//	{
//		cout << "operator==================";
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
//		set<int>q;
//		set<int>::reverse_iterator it;
//		for (int i = 0; i < Heap_Size; i++)
//		{
//			q.insert(Heap[i]);
//		}
//		int i = 0;
//		for (it = q.rbegin(); it != q.rend(); it++,i++)
//		{
//			cout << *it << endl;
//		}
//		
//	}
//
//	void temp()
//	{
//		for (int i = 0; i < Heap_Size; i++)
//		{
//			cout << Heap[i] << endl;
//		}
//	}
//
//	void indent(Binary_Max_Heap &H1, Binary_Max_Heap &H2)
//	{
//		int i=0, j=0;
//		this->max_size = H1.Heap_Size + H2.Heap_Size;
//		Heap_Size = max_size;
//		delete Heap;
//		Heap = new Object[max_size];
//		for (i = 0; i <H1.Heap_Size; i++)
//		{
//			Heap[i] = H1.Heap[i];
//		}
//		for (int k = 0 , j = i ; k < H2.Heap_Size; k++, j++)
//		{
//			Heap[j] = H2.Heap[k];
//		}
//		for (i = 0; i <Heap_Size; i++)
//		{
//			PushDown(i);
//		}
//	}
//
//	Object Get_Max()
//	{
//		return Heap[0];
//	}
//
//	void Delete_Max()
//	{
//		swap(Heap[0], Heap[Heap_Size - 1]);
//		Heap_Size--;
//		PushDown(Heap[0]);
//	}
//
//	~Binary_Max_Heap()
//	{
//		delete[]Heap;
//	}
//};
//
//int main()
//{
//	Binary_Max_Heap<int> b, a, c;
//	b.Insert(12);
//	b.Insert(11);
//	cout << "1st Heap : " << endl;
//	b.print();
//	a.Insert(0);
//	a.Insert(2);
//	cout << endl << "2nd Heap : " << endl;
//	a.print();
//	cout << endl << "join Heap is: " << endl;
//	c.indent(b, a);
//	c.print();
//	system("pause");
//	return 0;
//}