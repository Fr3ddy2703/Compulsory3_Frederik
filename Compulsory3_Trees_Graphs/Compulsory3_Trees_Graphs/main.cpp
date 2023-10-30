#include "trees.h"
#include "graph.h"

using namespace std;



int main()
{
	Tree tree;
	
	Graph graph(5);
	graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

	


	graph.returnEdges();

	//graph.print();



	//Tree::Node *root = tree.createRandomChild(nullptr, 53);
	//cout << tree.size(root) << endl;
	//cout << root->children.size() << endl;

	return 0;
	
}