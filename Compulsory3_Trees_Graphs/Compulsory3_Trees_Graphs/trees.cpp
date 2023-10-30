#include "trees.h"
#include <iostream>
#include <random>

int Tree::size(Node *root)
{
	
	if (root==nullptr)
		return 0;
	int count = 0;
	queue<Node *> queue;
	queue.push(root);
	while(!queue.empty())
	{
		
		int size = queue.size();
		while ( size > 0)
		{
			Node *  print = queue.front();
			
			queue.pop();
			count++;
			for (int i = 0; i < print->children.size(); i++)
				queue.push(print->children[i]);
			size--;
		}
	}
	cout << count << endl;
	return count;
}

int Tree::depth(Node* root)
{
	int depth = 1;

	while (root->parent != nullptr)
	{
		depth++;
		root = root->parent;
	}
	cout << depth << endl;
	return depth;
}

void Tree::DeletingNode(Node* root)
{
		if(root == nullptr)
		return;

	for (int i = 0; i < root->children.size() ; i++)
	{
		DeletingNode(root->children[i]);
	}
	delete root;
}

void Tree::setRoot(Node* root)
{
	treeroot = root;
}

void Tree::getNodes(vector<Node*>& vector, Node* node)
{
	for (int i = 0; i < node->children.size(); i++)
	{
		getNodes(vector, node->children[i]);
	} 
        vector.emplace_back(node);
}

void Tree::insertNode(Node* root, int data)
{
	//cout << "New node added" << endl;
	newNode(data, root);
	
}


void Tree::deleteNode(Node* root)
{
	if (root == nullptr)
	{
		return;
	}

	if (root->parent !=nullptr)
	{
		for (int i = 0; i < root->parent->children.size() ; i++)
	{
		if (root->parent->children[i] == root)
		{
			root->parent->children.erase(root->parent->children.begin()+i);
		}
	}
	}
	DeletingNode(root);
}

void Tree::LevelOrderTraversal(Node *root)
{
	if (root == nullptr)
		return;
	int count = 0;
	queue<Node *> queue;
	queue.push(root);
	while(!queue.empty())
	{
		
		int size = queue.size();
		while ( size > 0)
		{
			Node *  print = queue.front();
			
			queue.pop();
			count++;
			cout << print->data << " ";
			for (int i = 0; i < print->children.size(); i++)
				queue.push(print->children[i]);
			size--;
		}
		cout << endl;
	
	}
}

bool Tree::isEmpty(Node* root)
{
 if(root == nullptr)
 {
 	cout << "The tree is empty" << endl;
	 return true;
	
 }
	cout << "The tree is not empty" << endl;
	return false;
}

bool Tree::isRoot(Node* root)
{
	if(root->parent == nullptr )
	{
		cout << "This is the root of the tree" << endl;
		return true;
	}
	return false;
	
}

bool Tree::isLeaf(Node* leaf)
{
	if(leaf->children.empty())
	{
		cout << "List doesn't have children" << endl;
		return true;
	}
	cout << "List does have children" << endl;
	return false;
}

Tree::Node* Tree::createRandomChild(Node* root, int RandomNumber)
{
	 srand(time(NULL));

        if (root == nullptr)
        {
            root = newNode(rand(), nullptr);
            RandomNumber--;
        }

        vector<Node*> tempVector = getTree(root);
        Node* tempNode;
        Node* tempnewNode;
        for (int i = 0; i < RandomNumber; i++)
        {
            tempNode = tempVector[rand() % tempVector.size()];
            tempnewNode = newNode(rand(), tempNode);
            tempVector.emplace_back(tempnewNode);
        }

        return root;
}

Tree::Node* Tree::returnRoot()
{
	cout << treeroot->data << endl;
	return treeroot;
}

Tree::Node* Tree::returnParent(Node* parent)
{
	cout << treeroot->data << endl;
	return parent->parent;
}

vector<Tree::Node*> Tree::returnChildren(Node* children)
{
	for(int i = 0; i < children->children.size() ; i++)
	{
		cout << children->children[i]->data << endl;
	}
	return children->children;
}

vector<Tree::Node*> Tree::getTree(Node* node)
{
	vector<Node*> tempVector;

        if (node != nullptr)
        {
            getNodes(tempVector, node);

            return tempVector;
        }

        tempVector.emplace_back(node);

        return tempVector;
}

