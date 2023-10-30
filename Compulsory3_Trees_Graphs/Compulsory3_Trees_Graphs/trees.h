#pragma once
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Tree
{
public:
	
	struct Node
{
	Node() = default;
	~Node()
	{
		/*cout << "Deleted" << endl;*/
	}
	int data;
	Node * parent;
	vector<Node *>children;
};

private:

void DeletingNode(Node *root);


public:

void setRoot(Node *root);
void getNodes(vector<Node*>& vector, Node* node);
void insertNode(Node *root, int data);
void deleteNode(Node *root);	
void LevelOrderTraversal(Node *root);
int size(Node * root);
int depth(Node *root);
bool isEmpty(Node * root);
bool isRoot(Node *root);
bool isLeaf(Node *leaf);
Node* createRandomChild(Node* root, int RandomNumber);
Node* returnRoot();
Node* returnParent(Node *parent);
vector<Node*> returnChildren(Node *children);
vector<Node*> getTree(Node* node);


Node *treeroot;

Node *newNode(int data, Node* parent)
{
	Node *temp = new Node;
	temp->data = data;
	temp->parent = parent;
	if (parent != nullptr)
	{
		parent->children.push_back(temp);
	}
	
	return temp;
}

};


