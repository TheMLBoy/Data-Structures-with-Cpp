#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<set>
using namespace std;

class Graph
{
private:
	class Node
	{
	public:
		string Name;
		int Starting_Time;
		int Finishing_Time;
		string colour;
		Node* predecessor;
		Node(string d)
		{
			this->Name = d;
			Starting_Time = Finishing_Time = 0;
			colour = "white";
			predecessor = NULL;
		}
		Node(const Node &copy)
		{
			*this = copy;
		}

		Node& operator=(Node *rhs)
		{
			if (this->Name == rhs->Name)
			{
				return *this;
			}
			this->Name == rhs->Name;
			this->Starting_Time = rhs->Starting_Time;
			this->Finishing_Time = rhs->Finishing_Time;
			this->colour = rhs->colour;
			this->predecessor = rhs->predecessor;
			return *this;
		}

		bool operator<(const Node &rhs)
		{
			if (this->Name < rhs.Name)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool operator<(const Node &rhs)const
		{
			if (this->Name < rhs.Name)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool operator>(const Node &rhs)
		{
			if (this->Name > rhs.Name)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator>(const Node &rhs)const
		{
			if (this->Name > rhs.Name)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator==(const Node &rhs)
		{
			if (this->Name == rhs.Name)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator==(const Node &rhs)const
		{
			if (this->Name == rhs.Name)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		Node& operator[](Node &in)
		{
			return in;
		}

		Node& operator[](Node &in)const
		{
			return in;
		}

		friend ostream& operator<<(ostream& print, Node *rhs)
		{
			print << "\nName = " << rhs->Name;
			print << "\nColour = " << rhs->colour;
			print << "\nStarting Time = " << rhs->Starting_Time;
			print << "\nFinishing Time = " << rhs->Finishing_Time;
			if (rhs->predecessor == NULL)
			{
				print << "\nPredecessor = NULL";
			}
			else
			{
				print << "\nPredecessor = " << rhs->predecessor->Name;
			}
			return print;
		}
	};

	bool Check_Edge(Node *insert, string edge)
	{
		for (Children::iterator find = vertices[insert].begin(); find != vertices[insert].end(); find++)
		{
			if ((*find)->Name == edge)
			{
				return true;
			}
		}
		return false;
	}

	Node* Find_Vertex(string vertex)
	{
		for (graph::iterator find = vertices.begin(); find != vertices.end(); find++)
		{
			if (find->first->Name == vertex)
			{
				return find->first;
			}
		}
		return NULL;
	}

	void DFS_Visit(Node *T)
	{
		Time++;
		T->Starting_Time = Time;
		T->colour = "grey";
		for (Children::iterator child = vertices[T].begin(); child != vertices[T].end(); child++)
		{
			if ((*child)->colour == "white")
			{
				(*child)->predecessor = T;
				DFS_Visit(*child);
			}
		}
		T->colour = "Black";
		Time++;
		T->Finishing_Time = Time;
	}

	typedef map<Node*, set<Node*>>graph;
	typedef set<Node*>Children;
	graph vertices;
	static int Time;

public:
	Graph()
	{

	}

	void AddVertex(string name)
	{
		if (Find_Vertex(name) == NULL)
		{
			Node *Tmp = new Node(name);
			Children temp;
			vertices[Tmp] = temp;
		}
		else
		{
			cout << "\nvertex already Exists.";
		}
	}

	void AddEdge(string vertex, string edge)
	{
		if (Find_Vertex(vertex) != NULL)
		{
			Node* Insert = Find_Vertex(vertex);
			if (vertex == edge)
			{
				cout << "\nBoth child and parent are same.";
				return;
			}
			if (Find_Vertex(vertex) == NULL)
			{
				AddVertex(edge);
				Node* tmp = Find_Vertex(edge);
				vertices[Insert].insert(tmp);
			}
			else if (!Check_Edge(Insert, edge))
			{
				Node* tmp = Find_Vertex(edge);
				vertices[Insert].insert(tmp);
			}
			else
			{
				cout << "\nThis edge is alreasy a part of this vertex.";
			}
		}
		else
		{
			AddVertex(vertex);
			Node* tmp = new Node(edge);
			Node* Insert = Find_Vertex(vertex);
			vertices[Insert].insert(tmp);
		}
	}
	
	void Display()
	{
		for (graph::iterator find = vertices.begin(); find != vertices.end(); find++)
		{
			cout << endl << "Mapped item: \n" << find->first << endl << "\n---->\n";
			for (Children::iterator child = find->second.begin(); child != find->second.end(); child++)
			{
				cout << (*child) << endl;
			}
		}
	}

	void DFS()
	{
		for (graph::iterator dfs = vertices.begin(); dfs != vertices.end(); dfs++)
		{
			if (dfs->first->colour=="white")
			{
				DFS_Visit(dfs->first);
				break;
			}
		}
	}

	void Display_Vertices()
	{
		for (graph::iterator find = vertices.begin(); find != vertices.end(); find++)
		{
			cout << endl << find->first;
		}
	}

	~Graph()
	{
		for (graph::iterator find = vertices.begin(); find != vertices.end(); find++)
		{
			Node *del = find->first;
			delete del;
			del = NULL;
		}
	}
}; 

int Graph::Time = 0;

int main()
{
	Graph g;
	g.AddVertex("1");
	g.AddVertex("0");
	g.AddVertex("2");
	g.AddVertex("3");
	g.AddVertex("4");
	g.AddEdge("1", "0");
	g.AddEdge("0", "2");
	g.AddEdge("2", "1");
	g.AddEdge("0", "3");
	g.AddEdge("3", "4");
	/*g.AddEdge("a", "d");
	g.AddEdge("c", "t");
	g.AddEdge("s", "a");
	g.AddEdge("s", "m");
	g.AddEdge("d", "t");*/
	g.DFS();
	cout << "\nAfter DFS : \n\n";
	g.Display_Vertices();
	system("pause");
	return 0;
}