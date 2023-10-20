#pragma once
#include <list>
#include <vector>
#include <iostream>
using namespace std;

struct Node
{
	Node() = default;
	int key;
	vector<Node *>child;
};

Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	return temp;
}