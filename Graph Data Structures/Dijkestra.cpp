//#include<iostream>
//#include<string>
//#include"Binary Min Heap.h"
//#include<vector>
//using namespace std;
//
//class Graph
//{
//private:
//	class Node_Child;
//	class Node
//	{
//	public:
//		string Name;
//		int Distance;
//		Node* predecessor;
//		vector<Node_Child*>Children;
//		Node(string d)
//		{
//			this->Name = d;
//			Distance = -1;
//			predecessor = NULL;
//		}
//		Node(string d, int dis)
//		{
//			this->Name = d;
//			Distance = dis;
//			predecessor = NULL;
//		}
//		Node(const Node &copy)
//		{
//			*this = copy;
//		}
//
//		Node& operator=(Node *rhs)
//		{
//			if (this->Name == rhs->Name)
//			{
//				return *this;
//			}
//			this->Name == rhs->Name;
//			this->Distance = rhs->Distance;
//			this->predecessor = rhs->predecessor;
//			this->Children = rhs->Children;
//			return *this;
//		}
//
//		bool operator<(const Node &rhs)
//		{
//			if (this->Distance == -1)
//			{
//				return false;
//			}
//			if (rhs.Distance == -1)
//			{
//				return true;
//			}
//			if (this->Distance < rhs.Distance)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		bool operator>(const Node &rhs)
//		{
//			if (this->Distance == -1 || this->Distance > rhs.Distance)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		bool operator>=(const Node &rhs)
//		{
//			if (this->Distance == -1)
//			{
//				return true;
//			}
//			if (rhs.Distance == -1)
//			{
//				return false;
//			}
//			if (this->Distance >= rhs.Distance)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		bool operator==(const Node &rhs)
//		{
//			if (this->Distance == rhs.Distance)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		friend ostream& operator<<(ostream& print, Node &rhs)
//		{
//			print << "\nName = " << rhs.Name;
//			if (rhs.Distance == -1)
//			{
//				print << "\nDistance = Infinity";
//			}
//			else
//			{
//				print << "\nDistance = " << rhs.Distance;
//			}
//			if (rhs.predecessor == NULL)
//			{
//				print << "\nPredecessor = NULL";
//			}
//			else
//			{
//				print << "\nPredecessor = " << rhs.predecessor->Name;
//			}
//			return print;
//		}
//
//	};
//
//	class Node_Child
//	{
//	public:
//		Node *node;
//		int w;
//		Node_Child(Node *d, int W)
//		{
//			node = d;
//			w = W;
//		}
//		Node_Child(const Node_Child &copy)
//		{
//			*this = copy;
//		}
//
//		Node_Child& operator=(Node_Child *rhs)
//		{
//			if (this->node == rhs->node)
//			{
//				return *this;
//			}
//			this->node = rhs->node;
//			this->w = rhs->w;
//			return *this;
//		}
//	};
//
//	bool Check_Edge(int ind, string edge)
//	{
//		for (child::iterator find = vertices[ind]->Children.begin(); find != vertices[ind]->Children.end(); find++)
//		{
//			if ((*find)->node->Name == edge)
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//
//	int Find_Vertex(string vertex)
//	{
//		for (int i = 0; i < vertices.size(); i++)
//		{
//			if (vertices[i]->Name == vertex)
//			{
//				return i;
//			}
//		}
//		return -1;
//	}
//
//	void Initialize_Single_Source(int S)
//	{
//		for (int i = 0; i < vertices.size(); i++)
//		{
//			vertices[i]->Distance = -1;
//			vertices[i]->predecessor = NULL;
//		}
//		vertices[S]->Distance = 0;
//	}
//
//	void Relax(Node *P, Node_Child *C)
//	{
//		if (C->node->Distance == -1 || C->node->Distance>(P->Distance + C->w))
//		{
//			C->node->Distance = (P->Distance + C->w);
//			C->node->predecessor = P;
//		}
//	}
//
//	typedef vector<Node*>graph;
//	typedef vector<Node_Child*>child;
//	graph vertices;
//
//public:
//	Graph()
//	{
//
//	}
//
//	void AddVertex(string name)
//	{
//		if (Find_Vertex(name) == -1)
//		{
//			vertices.push_back(new Node(name));
//		}
//		else
//		{
//			cout << "\nvertex already Exists.";
//		}
//	}
//
//	void AddEdge(string vertex, string edge, int W)
//	{
//		int vertex_index = Find_Vertex(vertex);
//		if (vertex_index != -1)
//		{
//			if (vertex == edge)
//			{
//				cout << "\nBoth child and parent are same.";
//				return;
//			}
//			if (Find_Vertex(edge) == -1)
//			{
//				AddVertex(edge);
//				vertices[vertex_index]->Children.push_back(new Node_Child(vertices[Find_Vertex(edge)], W));
//			}
//			else if (!Check_Edge(vertex_index, edge))
//			{
//				vertices[vertex_index]->Children.push_back(new Node_Child(vertices[Find_Vertex(edge)], W));
//			}
//			else
//			{
//				cout << "\nThis edge is already a part of this vertex.";
//			}
//		}
//		else
//		{
//			AddVertex(vertex);
//			AddEdge(vertex, edge, W);
//		}
//	}
//
//	void Dijkstra(string c)
//	{
//		int c_ind = Find_Vertex(c);
//		if (c_ind == -1)
//		{
//			throw - 1;
//		}
//		Initialize_Single_Source(c_ind);
//		Binary_Min_Heap<Node*>Q;
//		for (int i = 0; i < vertices.size(); i++)
//		{
//			Q.Insert(vertices[i]);
//		}
//		while (!Q.empty())
//		{
//			Node *T = Q.Get_Min();
//			Q.Delete_Min();
//			int T_ind = Find_Vertex(T->Name);
//			for (int i = 0; i < vertices[T_ind]->Children.size(); i++)
//			{
//				Relax(T, vertices[T_ind]->Children[i]);
//				Q.Sort();
//			}
//		}
//	}
//
//	void Display()
//	{
//		for (int i = 0; i < vertices.size(); i++)
//		{
//			cout << endl << "Mapped item: \n" << *vertices[i] << endl << "\n---->\n";
//			for (child::iterator c = vertices[i]->Children.begin(); c != vertices[i]->Children.end(); c++)
//			{
//				cout << (*c)->node << endl;
//			}
//		}
//	}
//
//	void Display_Vertices()
//	{
//		for (int i = 0; i < vertices.size(); i++)
//		{
//			cout << endl << "Mapped item: \n" << *vertices[i] << endl;
//		}
//	}
//
//	~Graph()
//	{
//		for (int i = 0; i < vertices.size(); i++)
//		{
//			for (int j = 0; j < vertices[i]->Children.size(); j++)
//			{
//				delete vertices[i]->Children[j];
//			}
//			delete vertices[i];
//		}
//	}
//};
//
//int main()
//{
//	Graph g;
//	g.AddVertex("0");
//	g.AddVertex("1");
//	g.AddVertex("2");
//	g.AddVertex("3");
//	g.AddVertex("4");
//	g.AddVertex("5");
//	g.AddVertex("6");
//	g.AddVertex("7");
//	g.AddVertex("8");
//	g.AddEdge("0", "1", 4);
//	g.AddEdge("0", "7", 8);
//	g.AddEdge("1", "2", 8);
//	g.AddEdge("2", "3", 7);
//	g.AddEdge("7", "8", 7);
//	g.AddEdge("2", "8", 2);
//	g.AddEdge("8", "6", 6);
//	g.AddEdge("6", "5", 2);
//	g.AddEdge("2", "5", 4);
//	g.AddEdge("3", "5", 14);
//	g.AddEdge("3", "4", 9);
//	g.AddEdge("5", "4", 10);
//	g.Dijkstra("0");
//	g.Display_Vertices();
//	system("pause");
//	return 0;
//}