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
		int Distance;
		string colour;
		Node* predecessor;
		Node(string d)
		{
			this->Name = d;
			Distance = -1;
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
			this->Distance = rhs->Distance;
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
			if (rhs->Distance == -1)
			{
				print << "\nDistance = Infinity";
			}
			else
			{
				print << "\nDistance = " << rhs->Distance;
			}
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
	typedef map<Node*, set<Node*>>graph;
	typedef set<Node*>Children;
	graph vertices;

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
		if (Find_Vertex(vertex)!=NULL)
		{
			Node* Insert = Find_Vertex(vertex);
			if (vertex == edge)
			{
				cout << "\nBoth child and parent are same.";
				return;
			}
			if (Find_Vertex(edge) == NULL)
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

	void BFS(string s)
	{
		Node *Start = Find_Vertex(s);
		if (Start != NULL)
		{
			Node *temp;
			queue<Node*>que;
			Start->colour = "grey";
			Start->Distance = 0;
			que.push(Start);
			while (!que.empty())
			{
				temp = que.front();
				que.pop();
				if (temp->colour == "black")
				{
					continue;
				}
				for (Children::iterator find = vertices[temp].begin(); find != vertices[temp].end(); find++)
				{
					if ((*find)->colour == "white")
					{
						(*find)->colour = "grey";
						(*find)->Distance = temp->Distance + 1;
						(*find)->predecessor = temp;
						que.push(*find);
					}
				}
				temp->colour = "black";
			}
		}
		else
		{
			throw 0;
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

	int Connected_Vertices()
	{
		int c = 0;
		for (graph::iterator count = vertices.begin(); count != vertices.end(); count++)
		{
			if (count->first->Distance != -1)
			{
				c++;
			}
		}
		return c;
	}

	void Route_Display(string dep, string des)
	{
		if (Find_Vertex(des) == NULL)
		{
			cout << "\nDestination City did not find!!\n";
			return;
		}
		if (Find_Vertex(des)->Distance == -1)
		{
			cout << "\nNo route exists between " << dep << " and " << des << ".\n";
			return;
		}
		if (des == dep ) 
		{
			cout << "\n" << des;
			return;
		}
		Route_Display(dep,Find_Vertex(des)->predecessor->Name);
		cout << "-->  " << des << "   ";
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