//#include<iostream>
//#include<stack>
//using namespace std;
//
//class BST
//{
//private:
//	class TreeNode
//	{
//	public:
//		int data;
//		TreeNode *Left;
//		TreeNode *Right;
//		TreeNode(int d)
//		{
//			this->data = d;
//		}
//	};
//
//	void Recursive_Insert(TreeNode *temp,int d)
//	{
//		if (d >= temp->data)
//		{
//			if (temp->Right != NULL)
//			{
//				Recursive_Insert(temp->Right,d);
//			}
//			else
//			{
//				temp->Right = new TreeNode(d);
//				return;
//			}
//		}
//		else
//		{
//			if (temp->Left != NULL)
//			{
//				Recursive_Insert(temp->Left, d);
//			}
//			else
//			{
//				temp->Left = new TreeNode(d);
//				return;
//			}
//		}
//	}
//
//	void Recursive_InOrder(TreeNode *temp)
//	{
//		if (temp == NULL)
//		{
//			return;
//		}
//		Recursive_InOrder(temp->Left);
//		cout << temp->data << endl;
//		Recursive_InOrder(temp->Right);
//	}
//
//	void Recursive_PreOrder(TreeNode *temp)
//	{
//		if (temp == NULL)
//		{
//			return;
//		}
//		cout << temp->data << endl;
//		Recursive_PreOrder(temp->Left);
//		Recursive_PreOrder(temp->Right);
//	}
//
//	void Recursive_PostOrder(TreeNode *temp)
//	{
//		if (temp == NULL)
//		{
//			return;
//		}
//		Recursive_PostOrder(temp->Left);
//		Recursive_PostOrder(temp->Right);
//		cout << temp->data << endl;
//	}
//
//	TreeNode* find_Node(TreeNode *tmp, int d)
//	{
//		if (tmp == NULL)
//		{
//			return NULL;
//		}
//		if (tmp->data == d)
//		{
//			return tmp;
//		}
//		else if (tmp->data > d)
//		{
//			return find_Node(tmp->Right, d);
//		}
//		else if (tmp->data < d)
//		{
//			return find_Node(tmp->Left, d);
//		}
//	}
//
//	TreeNode* find_parent(TreeNode *tmp, TreeNode *child)
//	{
//		if (tmp == NULL)
//		{
//			return NULL;
//		}
//		if (tmp->Left == child || tmp->Right == child)
//		{
//			return tmp;
//		}
//		else if (child->data > tmp->data)
//		{
//			return find_parent(tmp->Right, child);
//		}
//		else if (child->data < tmp->data)
//		{
//			return find_parent(tmp->Left, child);
//		}
//	}
//
//	TreeNode* Bottom_left(TreeNode *Temp)
//	{
//		if (Temp->Left == NULL)
//		{
//			return Temp;
//		}
//		return Bottom_left(Temp->Left);
//	}
//
//	TreeNode *root;
//
//public:
//	BST()
//	{
//		root = NULL;
//	}
//	
//	void Insert(int d)
//	{
//		if (root == NULL)
//		{
//			root = new TreeNode(d);
//			return;
//		}
//		Recursive_Insert(root,d);
//	}
//
//	void InOrder_Display()
//	{
//		if (root == NULL)
//		{
//			return;
//		}
//		Recursive_InOrder(root);
//	}
//
//	bool Delete(int d)
//	{
//		TreeNode *Del = find_Node(root,d);
//		if (Del == NULL)
//		{
//			return false;
//		}
//		else
//		{
//			if (Del->Left == NULL &&Del->Right == NULL)
//			{
//				TreeNode* Parent = find_parent(root,Del);
//				if (Parent == NULL)
//				{
//					root = NULL;
//					delete Del;
//				}
//				if (Parent->Left == Del)
//				{
//					Parent->Left = NULL;
//					delete Del;
//				}
//				else if (Parent->Right == Del)
//				{
//					Parent->Right = NULL;
//					delete Del;
//				}
//			}
//			else if (Del->Left == NULL)
//			{
//				TreeNode* Parent = find_parent(root,Del);
//				if (Parent == NULL)
//				{
//					root = Del->Right;
//					delete Del;
//				}
//				if (Parent->Left == Del)
//				{
//					Parent->Left = Del->Right;
//					delete Del;
//				}
//				else if (Parent->Right == Del)
//				{
//					Parent->Right = Del->Right;
//					delete Del;
//				}
//			}
//			else if (Del->Right == NULL)
//			{
//				TreeNode* Parent = find_parent(root,Del);
//				if (Parent == NULL)
//				{
//					root = Del->Right;
//					delete Del;
//				}
//				if (Parent->Left == Del)
//				{
//					Parent->Left = Del->Left;
//					delete Del;
//				}
//				else if (Parent->Right == Del)
//				{
//					Parent->Right = Del->Left;
//					delete Del;
//				}
//			}
//			else
//			{
//				TreeNode* Replace = Bottom_left(Del->Right);
//				int data = Replace->data;
//				Delete(Replace->data);
//				Del->data = data;
//			}
//		}
//		return true;
//	}
//
//	bool Update_Value(int Old,int New)
//	{
//		if (Delete(Old))
//		{
//			Insert(New);
//			return true;
//		}
//		return false;
//	}
//
//	~BST()
//	{
//		TreeNode *temp = root;
//		stack<TreeNode*>Destructor;
//		if (temp != NULL)
//		{
//			Destructor.push(temp);
//		}
//		while (!Destructor.empty())
//		{
//			TreeNode *del=Destructor.top();
//			Destructor.pop();
//			if (del->Left != NULL)
//			{
//				Destructor.push(del->Left);
//			}
//			if (del->Right != NULL)
//			{
//				Destructor.push(del->Right);
//			}
//			delete del;
//		}
//	}
//
//	void Pre_Order_Display()
//	{
//		Recursive_PreOrder(root);
//	}
//
//	void Post_Order_Display()
//	{
//		Recursive_PostOrder(root);
//	}
//	void Level_Display()
//	{
//
//	}
//};
//
//int main()
//{
//	BST t;
//	t.Insert(50);
//	t.Insert(30);
//	t.Insert(20);
//	t.Insert(40);
//	t.Insert(70);
//	t.Insert(60);
//	t.Insert(80);
//	t.InOrder_Display();
//	/*t.Delete(30);
//	cout << "\nTree Updated: \n";
//	t.InOrder_Display();
//	t.Update_Value(50,1);
//	cout << "\nTree Updated: \n";*/
//	cout << "\nInorder: \n\n";
//	t.InOrder_Display();
//	cout << "\nPre order: \n\n";
//	t.Pre_Order_Display();
//	cout << "\nPOST order: \n\n";
//	t.Post_Order_Display();
//	system("pause");
//	return 0;
//}