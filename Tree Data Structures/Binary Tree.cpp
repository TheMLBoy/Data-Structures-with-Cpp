//#include<iostream>
//#include<stack>
//using namespace std;
//
//class BinaryTree
//{
//private:
//	class TreeNode
//	{
//	public:
//		int data;
//		TreeNode *left, *right;
//		TreeNode(int d)
//		{
//			data = d;
//			left = NULL;
//			right = NULL;
//		}
//	};
//
//	void printGivenLevel(TreeNode* tmp, int level)
//	{
//		if (tmp == NULL)
//			return;
//		if (level == 1)
//		{
//			cout << tmp->data << "  ";
//		}
//		else if (level > 1)
//		{
//			printGivenLevel(tmp->left, level - 1);
//			printGivenLevel(tmp->right, level - 1);
//		}
//	}
//
//	int Height(TreeNode *tmp)
//	{
//		if (tmp == NULL)
//		{
//			return 0;
//		}
//		int lh = Height(tmp->left);
//		int rh = Height(tmp->right);	
//		return lh > rh ? lh + 1 : rh + 1;
//	}
//
//	TreeNode* find_Parent(int p)
//	{
//		TreeNode *tmp = NULL, *parentPtr = NULL;
//		stack<TreeNode *> s;
//		s.push(root);
//
//		while (!s.empty())
//		{
//			tmp = s.top();
//			s.pop();
//
//			if (tmp->data == p)
//			{
//				parentPtr = tmp;
//				break;
//			}
//			else
//			{
//				if (tmp->left != NULL)
//				{
//					s.push(tmp->left);
//				}
//				if (tmp->right != NULL)
//				{
//					s.push(tmp->right);
//				}
//			}
//		}
//		return parentPtr;
//	}
//
//	TreeNode *root;
//public:
//	BinaryTree()
//	{
//		root = NULL;
//	}
//	void AddRoot(int a)
//	{
//		if (root == NULL)
//		{
//			root = new TreeNode(a);
//		}
//		else
//		{
//			cout << "root aleady exists";
//		}
//	}
//
//	void AddLeftChild(int c, int p)
//	{
//		TreeNode *parentPtr = find_Parent(p);
//		if (parentPtr != NULL)
//		{
//			if (parentPtr->left == NULL)
//			{
//				parentPtr->left = new TreeNode(c);
//			}
//			else
//			{
//				cout << "left already exists";
//			}
//		}
//		else
//		{
//			cout << "parent not found";
//		}
//	}
//
//	void AddRightChild(int c, int p)
//	{
//		TreeNode *parentPtr = find_Parent(p);
//		if (parentPtr != NULL)
//		{
//			if (parentPtr->right == NULL)
//			{
//				parentPtr->right = new TreeNode(c);
//			}
//			else
//			{
//				cout << "left already exists";
//			}
//		}
//		else
//		{
//			cout << "parent not found";
//		}
//
//	}
//
//	void printLevelOrder()
//	{
//		int h = Height(root);
//		for (int i = 1; i <= h; i++)
//		{
//			printGivenLevel(root, i);
//			printf("\n");
//		}
//	}
//
//};
//int main()
//{
//	BinaryTree a;
//	a.AddRoot(10);
//	a.AddLeftChild(5, 10);
//	a.AddRightChild(12, 10);
//	a.AddLeftChild(4, 5);
//	a.AddRightChild(12, 5);
//	a.AddLeftChild(3, 4);
//	a.AddRightChild(12, 4);
//	a.AddLeftChild(2, 3);
//	a.AddRightChild(12, 3);
//	a.printLevelOrder();
//	system("pause");
//	return 0;
//}