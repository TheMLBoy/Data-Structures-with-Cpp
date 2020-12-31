#include<iostream>
#include<stack>
#include<conio.h>
#define COUNT 10 
using namespace std;

class BST
{
private:
	class TreeNode
	{
	public:
		int data;
		TreeNode *Left;
		TreeNode *Right;
		TreeNode(int d)
		{
			this->data = d;
		}
	};

	void Recursive_Insert(TreeNode *temp, int d)
	{
		if (d > temp->data)
		{
			if (temp->Right != NULL)
			{
				Recursive_Insert(temp->Right, d);
			}
			else
			{
				temp->Right = new TreeNode(d);
				return;
			}
		}
		else if (d < temp->data)
		{
			if (temp->Left != NULL)
			{
				Recursive_Insert(temp->Left, d);
			}
			else
			{
				temp->Left = new TreeNode(d);
				return;
			}
		}
		else
		{
			cout << "\n " << d << " is already present in this BST.";
		}
	}

	void Recursive_InOrder(TreeNode *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		Recursive_InOrder(temp->Left);
		cout << temp->data << endl;
		Recursive_InOrder(temp->Right);
	}

	void Recursive_PreOrder(TreeNode *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		cout << temp->data << endl;
		Recursive_PreOrder(temp->Left);
		Recursive_PreOrder(temp->Right);
	}

	void Recursive_PostOrder(TreeNode *temp)
	{
		if (temp == NULL)
		{
			return;
		}
		Recursive_PostOrder(temp->Left);
		Recursive_PostOrder(temp->Right);
		cout << temp->data << endl;
	}

	TreeNode* find_Node(TreeNode *t, int d)
	{
		if (t == NULL)
			return NULL;
		else if (d < t->data)
			return find_Node(t->Left, d);
		else if (d > t->data)
			return find_Node(t->Right, d);
		else
			return t;
	}

	TreeNode* find_parent(TreeNode *tmp, TreeNode *child)
	{
		if (tmp == NULL)
		{
			return NULL;
		}
		if (tmp->Left == child || tmp->Right == child)
		{
			return tmp;
		}
		else if (child->data > tmp->data)
		{
			return find_parent(tmp->Right, child);
		}
		else if (child->data < tmp->data)
		{
			return find_parent(tmp->Left, child);
		}
	}

	TreeNode* Bottom_left(TreeNode *Temp)
	{
		if (Temp->Left == NULL)
		{
			return Temp;
		}
		return Bottom_left(Temp->Left);
	}

	TreeNode* Bottom_right(TreeNode *Temp)
	{
		if (Temp->Right == NULL)
		{
			return Temp;
		}
		return Bottom_right(Temp->Right);
	}

	void print2DUtil(TreeNode *tmp, int space)
	{
		// Base case  
		if (tmp == NULL)
			return;

		// Increase distance between levels  
		space += COUNT;

		// Process Right child first  
		print2DUtil(tmp->Right, space);

		// Print current TreeNode after space  
		// count  
		cout << endl;
		for (int i = COUNT; i < space; i++)
			cout << " ";
		cout << tmp->data << "\n";

		// Process Left child  
		print2DUtil(tmp->Left, space);
	}

	TreeNode *root;

public:
	BST()
	{
		root = NULL;
	}

	void Insert(int d)
	{
		if (root == NULL)
		{
			root = new TreeNode(d);
			return;
		}
		Recursive_Insert(root, d);
	}

	bool Find(int find)
	{
		if (find_Node(root, find) == NULL)
		{
			return false;
		}
		return true;
	}

	bool Delete(int d)
	{
		TreeNode *Del = find_Node(root, d);
		if (Del == NULL)
		{
			return false;
		}
		else
		{
			if (Del->Left == NULL && Del->Right == NULL)
			{
				TreeNode* Parent = find_parent(root, Del);
				if (Del == root)
				{
					root = NULL;
					delete Del;
				}
				if (Parent->Left == Del)
				{
					Parent->Left = NULL;
					delete Del;
				}
				else if (Parent->Right == Del)
				{
					Parent->Right = NULL;
					delete Del;
				}
			}
			else if (Del->Left == NULL)
			{
				TreeNode* Parent = find_parent(root, Del);
				if (Del == root)
				{
					root = Del->Right;
					delete Del;
				}
				if (Parent->Left == Del)
				{
					Parent->Left = Del->Right;
					delete Del;
				}
				else if (Parent->Right == Del)
				{
					Parent->Right = Del->Right;
					delete Del;
				}
			}
			else if (Del->Right == NULL)
			{
				TreeNode* Parent = find_parent(root, Del);
				if (Del == root)
				{
					root = Del->Right;
					delete Del;
				}
				if (Parent->Left == Del)
				{
					Parent->Left = Del->Left;
					delete Del;
				}
				else if (Parent->Right == Del)
				{
					Parent->Right = Del->Left;
					delete Del;
				}
			}
			else
			{
				TreeNode* Replace = Bottom_left(Del->Right);
				int data = Replace->data;
				Delete(Replace->data);
				Del->data = data;
			}
		}
		return true;
	}

	void Max()
	{
		if (root == NULL)
		{
			cout << "\nThis BST is empty!!!";
		}
		else
		{
			TreeNode *t = Bottom_right(root);
			cout << "\n" << t->data << " is maximum value in this BST.";
		}
	}

	void Min()
	{
		if (root == NULL)
		{
			cout << "\nThis BST is empty!!!";
		}
		else
		{
			TreeNode *t = Bottom_left(root);
			cout << "\n" << t->data << " is minimum value in this BST.";
		}
	}

	void Predescessor(int x)
	{
		TreeNode * temp = find_Node(root, x);
		if (root == NULL)
		{
			cout << "\nThis BST is empty!!!!";
			return;
		}
		if (temp == NULL)
		{
			cout << "\n" << x << " is not present in this BST.";
			return;
		}
		if (temp->Left != NULL)
		{
			TreeNode *t = temp->Left;
			if (t->Right != NULL)
			{
				TreeNode *ans = Bottom_right(t);
				cout << "\nPredecessor of " << x << " is " << ans->data;
				return;
			}
			cout << "\nPredecessor of " << x << " is " << t->data;
			return;
		}
		else if (temp->Left == NULL)
		{
			TreeNode *par = find_parent(root, temp);
			while (par != NULL && par->Left == temp)
			{
				temp = par;
				par = find_parent(root, par);
			}
			if (par == NULL)
			{
				cout << "\nPredecessor of " << x << " is " << temp->data;
				return;
			}
			else
			{
				cout << "\nPredecessor of " << x << " is " << par->data;
				return;
			}
		}
	}

	void Successor(int x)
	{
		TreeNode * temp = find_Node(root, x);
		if (root == NULL)
		{
			cout << "\nThis BST is empty!!!!";
			return;
		}
		if (temp == NULL)
		{
			cout << "\n" << x << " is not present in this BST.";
			return;
		}
		if (temp->Right != NULL)
		{
			TreeNode *t = temp->Right;
			if (t->Left != NULL)
			{
				TreeNode *ans = Bottom_left(t);
				cout << "\nPredecessor of " << x << " is " << ans->data;
				return;
			}
			cout << "\nPredecessor of " << x << " is " << t->data;
			return;
		}
		else if (temp->Right == NULL)
		{
			TreeNode *par = find_parent(root, temp);
			while (par != NULL && par->Right == temp)
			{
				temp = par;
				par = find_parent(root, par);
			}
			if (par == NULL)
			{
				cout << "\nPredecessor of " << x << " is " << temp->data;
				return;
			}
			else
			{
				cout << "\nPredecessor of " << x << " is " << par->data;
				return;
			}
		}
		
	}

	void Pre_Order_Display()
	{
		Recursive_PreOrder(root);
	}

	void InOrder_Display()
	{
		if (root == NULL)
		{
			return;
		}
		Recursive_InOrder(root);
	}

	void Post_Order_Display()
	{
		Recursive_PostOrder(root);
	}
	

	~BST()
	{
		TreeNode *temp = root;
		stack<TreeNode*>Destructor;
		if (temp != NULL)
		{
			Destructor.push(temp);
		}
		while (!Destructor.empty())
		{
			TreeNode *del = Destructor.top();
			Destructor.pop();
			if (del->Left != NULL)
			{
				Destructor.push(del->Left);
			}
			if (del->Right != NULL)
			{
				Destructor.push(del->Right);
			}
			delete del;
		}
	}
	
	void TreeDisplay()
	{
		cout << "\n\n---------------------------------Tree Output--------------------------------------\n\n";
		print2DUtil(root, 0);
		cout << "\n\n\n\n----------------------------------------------------------------------------------";
	}

};

int main()
{
	BST main;
	while (true)
	{
		cout << "\n\nSelect your option : (1-11)";
		cout << "\n\n1- Insertion.";
		cout << "\n2- Find.";
		cout << "\n3- Delete.";
		cout << "\n4- Get Max.";
		cout << "\n5- Get Min.";
		cout << "\n6- Get Predecessor of a node.";
		cout << "\n7- Get Successor of a node.";
		cout << "\n8- Preorder Display.";
		cout << "\n9- Inorder Display.";
		cout << "\n10- Postorder Display.";
		cout << "\n11- Display Tree.\n\n";
		cout << "\n\n\n Press any other key to exit!!!!\n";
		unsigned int inp;
		cin >> inp;
		cout << "\n\n";
		switch (inp)
		{
		case 1:
			int insert;
			cout << "\nEnter the value which you want to insert : ";
			cin >> insert;
			main.Insert(insert);
			break;
		case 2:
			int find;
			cout << "\nEnter the value which you want to find : ";
			cin >> find;
			main.Find(find) ? cout << "\n" << find << " is present in this BST." : cout << "\n" << find << " is not present in this BST.";
			break;
		case 3:
			int del;
			cout << "\nEnter the value which you want to delete : ";
			cin >> del;
			main.Delete(del) ? cout << "\n" << del << " has deleted from this BST." : cout << "\n" << del << " is not present in this BST.";
			break;
		case 4:
			main.Max();
			break;
		case 5:
			main.Min();
			break;
		case 6:
			int pred;
			cout << "\nEnter the value of which predecessor you want to get : ";
			cin >> pred;
			main.Predescessor(pred);
			break;
		case 7:
			int suc;
			cout << "\nEnter the value of which successor you want to get : ";
			cin >> suc;
			main.Successor(suc);
			break;
		case 8:
			cout << "\n\nPre Order Display : \n\n";
			main.Pre_Order_Display();
			break;
		case 9:
			cout << "\n\nIn Order Display : \n\n";
			main.InOrder_Display();
			break;
		case 10:
			cout << "\n\nPost Order Display : ";
			main.Post_Order_Display();
			break;
		case 11:
			main.TreeDisplay();
			break;
		default:
			exit(0);
			break;
		}
	}
	system("pause");
	return 0;
}
