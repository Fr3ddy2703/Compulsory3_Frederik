#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Graph
{

	int numVertices;
	vector<vector<int>> adjList;
	vector<int> visitedList;

public:
	Graph() = default;
	Graph(int n);

void addVertice();
void addRandomVertice();
void addEdge(int source, int destination);
void deleteEdge(int source, int destination);
void deleteVertice();
void returnNode(int node);
void depthTraversal(int start);
void returnVertices();
void returnEdges();
int size();
bool isEmpty();
bool isConnected(int source, int destination);
void print();
};