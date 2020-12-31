//#include <iostream>
//#include <string>
//#include <list>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//class OSFSTree
//{
//private:
//
//	class TreeNode
//	{
//	public:
//		string data;
//		list<TreeNode *> children;
//
//		TreeNode(string d)
//		{
//			this->data = d;
//		}
//	};
//
//	TreeNode* find_Parent(TreeNode *tmp, string data, TreeNode *Parent)
//	{
//		if (tmp == NULL)
//		{
//			return Parent;
//		}
//		if (tmp->data == data)
//		{
//			Parent = tmp;
//			return Parent;
//		}
//		for (list<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
//		{
//			Parent= find_Parent(*p, data, Parent);
//		}
//		return Parent;
//	}
//
//	TreeNode *root;
//
//public:
//	OSFSTree()
//	{
//		root = NULL;
//	}
//
//	~OSFSTree()
//	{
//		// to be implemented
//	}
//
//	void dump() // display the tree node in a line
//	{
//		if (root != NULL)
//		{
//			stack<TreeNode *> s;
//			s.push(root);
//
//			TreeNode *tmp = NULL;
//
//			while (!s.empty())
//			{
//				tmp = s.top();
//				s.pop();
//
//				cout << tmp->data << endl;
//
//				for (list<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
//				{
//					s.push(*p);
//				}
//			}
//		}
//	}
//
//	void display1()
//	{
//		if (root != NULL)
//		{
//			stack<TreeNode *> s;
//			stack<int> ls;
//
//			TreeNode *tmp = NULL;
//			int lv = 0;
//
//			s.push(root);
//			ls.push(lv);
//
//			while (!s.empty())
//			{
//				tmp = s.top();
//				s.pop();
//				lv = ls.top();
//				ls.pop();
//
//				for (int k = 0; k<lv; k++) cout << "--"; // indent two spaces
//				cout << tmp->data << endl;
//
//				for (list<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
//				{
//					s.push(*p);
//					ls.push(lv + 1);
//				}
//			}
//		}
//	}
//
//
//	void display2()
//	{
//		if (root != NULL)
//		{
//			stack<TreeNode *> s;
//			stack<int> ls;
//
//			TreeNode *tmp = NULL;
//			int lv = 0;
//
//			s.push(root);
//			ls.push(lv);
//
//			while (!s.empty())
//			{
//				tmp = s.top();
//				s.pop();
//				lv = ls.top();
//				ls.pop();
//
//				for (list<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
//				{
//					s.push(*p);
//					ls.push(lv + 1);
//				}
//
//				for (int k = 0; k<lv; k++) cout << "--"; // indent two spaces
//				cout << tmp->data << endl;
//			}
//		}
//	}
//
//	void display2q() // with queue
//	{
//		if (root != NULL)
//		{
//			queue<TreeNode *> s;
//			queue<int> ls;
//
//			TreeNode *tmp = NULL;
//			int lv = 0;
//
//			s.push(root);
//			ls.push(lv);
//
//			while (!s.empty())
//			{
//				tmp = s.front();
//				s.pop();
//				lv = ls.front();
//				ls.pop();
//
//				for (list<TreeNode *>::iterator p = tmp->children.begin(); p != tmp->children.end(); p++)
//				{
//					s.push(*p);
//					ls.push(lv + 1);
//				}
//
//				for (int k = 0; k<lv; k++) cout << "--"; // indent two spaces
//				cout << tmp->data << endl;
//			}
//		}
//	}
//
//	void display3()
//	{
//		if (root != NULL)
//		{
//			display3(root, 0);
//		}
//	}
//
//	void display3(TreeNode *sr, int lv)
//	{
//		for (int k = 0; k<lv; k++) cout << "--"; // indent two spaces
//		cout << sr->data << endl;
//
//		for (list<TreeNode *>::iterator p = sr->children.begin(); p != sr->children.end(); p++)
//		{
//			display3(*p, lv + 1);
//		}
//	}
//
//	void display4()
//	{
//		if (root != NULL)
//		{
//			display4(root, 0);
//		}
//	}
//
//	void display4(TreeNode *sr, int lv)
//	{
//		for (list<TreeNode *>::iterator p = sr->children.begin(); p != sr->children.end(); p++)
//		{
//			display4(*p, lv + 1);
//		}
//
//		for (int k = 0; k<lv; k++) cout << "--"; // indent two spaces
//		cout << sr->data << endl;
//	}
//
//	void addRoot(string d)
//	{
//		if (root == NULL)
//		{
//			root = new TreeNode(d);
//		}
//		else
//		{
//			// exception
//		}
//	}
//
//	void addChild(string d, string parent)
//	{
//		TreeNode *Parent_address = find_Parent(root, parent, NULL);
//		if (Parent_address != NULL)
//		{
//			TreeNode *new_Chlid = new TreeNode(d);
//			Parent_address->children.push_back(new_Chlid);
//		}
//		else
//		{
//			cout << "\nAnni diya aai mazak e? Parent hega nai child store kran nu turyan e?!!";
//		}
//	}
//
//};
//
//int main()
//{
//
//	OSFSTree fsr;
//
//	fsr.addRoot("D:");
//	fsr.addChild("PF", "D:");
//	fsr.addChild("OOP", "D:");
//	fsr.addChild("Quiz", "PF");
//	fsr.addChild("Project", "PF");
//	fsr.addChild("DSA", "D:");
//	fsr.addChild("Marks", "DSA");
//	fsr.addChild("EntryUM", "Marks");
//	fsr.addChild("EntryUD", "D:");
//	fsr.addChild("EntryUP", "Project");
//
//	//fsr.dump(); // Unformatted output of a tree
//	cout << endl << endl << endl;
//	//fsr.display1(); // Formatted output of a tree using stack (process node before children)
//	cout << endl << endl << endl;
//	//fsr.display2(); // Formatted output of a tree using stack (process node after children)
//	// but it is same as above. 
//	// you must change the stack with queue and see what happened
//	//cout << endl << endl << endl;
//	//fsr.display3(); // Formatted output of a tree using recursion (current before its children). 
//	//  This is pre-order processing.
//	cout << endl << endl << endl;
//	//fsr.display4(); // Formatted output of a tree using recursion (children before their parent).
//	// This is post-order processing.
//	cout << endl << endl << endl;
//
//	fsr.display2q(); // Formatted output of a tree using queue    
//	cout << endl << endl;
//	system("pause");
//	return 0;
//}