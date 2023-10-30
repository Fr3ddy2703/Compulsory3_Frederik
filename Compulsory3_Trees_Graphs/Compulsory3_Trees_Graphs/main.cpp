#include "trees.h"
#include "graph.h"

using namespace std;



int main()
{
	/*Tree tree;*/
	
	Graph graph(5);
	graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

	


	graph.returnVertices();

	graph.print();


	return 0;

	//Tree::Node *root = tree.newNode(10, nullptr);
	//tree.insertNode(root, 20);
	//tree.insertNode(root, 30);
	//tree.insertNode(root, 40);
	//tree.insertNode(root->children[0], 123);
	//tree.insertNode(root->children[1], 153);
	//tree.insertNode(root->children[2], 31);
	//tree.insertNode(root->children[0]->children[0], 3);
	//tree.insertNode(root->children[0]->children[0], 53);
	//tree.insertNode(root->children[0]->children[0]->children[0], 37);
	//tree.insertNode(root->children[0]->children[0]->children[1], 83);
	//int input;


	//tree.setRoot(root);
}