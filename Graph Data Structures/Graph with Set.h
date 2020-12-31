#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

class Graph
{
private:
	class Node//class for a Node
	{
	public:
		string Name;
		int Distance;
		string colour;
		Node* predecessor;
		vector<Node*>Children;
		Node(string d)
		{
			this->Name = d;
			Distance = -1;
			colour = "white";
			predecessor = NULL;
		}

		friend ostream& operator<<(ostream& print, Node &rhs) //Output operater overloaded
		{
			print << "\nName = " << rhs.Name;
			print << "\nColour = " << rhs.colour;
			if (rhs.Distance == -1)
			{
				print << "\nDistance = Infinity";
			}
			else
			{
				print << "\nDistance = " << rhs.Distance;
			}
			if (rhs.predecessor == NULL)
			{
				print << "\nPredecessor = NULL";
			}
			else
			{
				print << "\nPredecessor = " << rhs.predecessor->Name;
			}
			return print;
		}
	};//Node class ended

	bool Check_Edge(int P_index, string edge)//P_index is the index of parent Node...this function is used to check that this 'edge' is already a child of that parent or not
	{
		for (int i = 0; i < vertices[P_index]->Children.size(); i++)
		{
			if (vertices[P_index]->Children[i]->Name == edge)
			{
				return true;
			}
		}
		return false;
	}

	int Find_Vertex(string vertex)//This funtion is used check the index of vector having that "vertex"
	{
		for (int i = 0; i < vertices.size(); i++)
		{
			if (vertices[i]->Name == vertex)
			{
				return i;
			}
		}
		return -1;
	}
	typedef vector<Node*>graph;
	graph vertices;

public:
	Graph()
	{

	}

	void AddVertex(string name)//Add new vertex
	{
		if (Find_Vertex(name) == -1)
		{
			vertices.push_back(new Node(name));
		}
		else
		{
			cout << "\nvertex already Exists.";
		}
	}

	void AddEdge(string vertex, string edge)//Add child to a parent.....Parent is "vertex" here and child is "edge" here.
	{
		int vertex_index = Find_Vertex(vertex);
		if (vertex == edge)
		{
			cout << "\nBoth child and parent are same.";
			return;
		}
		else if (vertex_index != -1)
		{
			if (Find_Vertex(edge) == -1)
			{
				AddVertex(edge);
				vertices[vertex_index]->Children.push_back(vertices[Find_Vertex(edge)]);
			}
			else if (!Check_Edge(vertex_index, edge))
			{
				vertices[vertex_index]->Children.push_back(vertices[Find_Vertex(edge)]);
			}
			else
			{
				cout << "\nThis edge is already a part of this vertex.";
			}
		}
		else
		{
			AddVertex(vertex);
			AddEdge(vertex, edge);
		}
	}

	void BFS(string s)//s is the starting vertx's Name
	{
		int Start = Find_Vertex(s);
		if (Start != -1)
		{
			queue<Node*>que;
			vertices[Start]->colour = "grey";
			vertices[Start]->Distance = 0;
			que.push(vertices[Start]);
			while (!que.empty())
			{
				Node *temp = que.front();
				que.pop();
				for (int i = 0; i < temp->Children.size(); i++)
				{
					if (temp->Children[i]->colour == "white")
					{
						temp->Children[i]->colour = "grey";
						temp->Children[i]->Distance = temp->Distance + 1;
						temp->Children[i]->predecessor = temp;
						que.push(temp->Children[i]);
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

	void Display()//Display with parent child relation
	{
		for (int i = 0; i < vertices.size(); i++)
		{
			cout << endl << "Mapped item: \n" << *vertices[i] << endl << "\n---->\n";
			for (int j = 0; j < vertices[i]->Children.size(); j++)
			{
				cout << vertices[i]->Children[j] << endl;
			}
		}
	}

	void Display_Vertices()//Display only vertices ...no parent child relation
	{
		for (int i = 0; i < vertices.size(); i++)
		{
			cout << endl << "\n" << *vertices[i] << endl;
		}
	}

	~Graph()//Destructor
	{
		for (int i = 0; i < vertices.size(); i++)
		{
			delete vertices[i];
		}
	}
};