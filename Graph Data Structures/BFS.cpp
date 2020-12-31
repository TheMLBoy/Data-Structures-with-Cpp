//#include"Graph.h"
//
//int main()
//{
//	Graph g;
//	g.AddVertex("m");
//	g.AddVertex("b");
//	g.AddVertex("a");
//	g.AddVertex("c");
//	g.AddVertex("s");
//	g.AddVertex("d");
//	g.AddVertex("t");
//	g.AddEdge("m", "b");
//	g.AddEdge("m", "d");
//	g.AddEdge("b", "d");
//	g.AddEdge("a", "m");
//	g.AddEdge("a", "c");
//	g.AddEdge("a", "d");
//	g.AddEdge("c", "t");
//	g.AddEdge("s", "a");
//	g.AddEdge("s", "m");
//	g.AddEdge("d", "t");
//	g.BFS("s");
//	cout << "\nAfter BFS : \n\n";
//	g.Display_Vertices();
//	cout << endl << endl << "Connected Nodes : " << g.Connected_Vertices() << endl;
//	system("pause");
//	return 0;
//}