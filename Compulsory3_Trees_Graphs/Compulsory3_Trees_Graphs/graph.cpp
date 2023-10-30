#include "graph.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;


Graph::Graph(int n)
{
		numVertices = n;
		adjList.resize(numVertices);
}

void Graph::addVertice()
{
	numVertices++;
	adjList.resize(numVertices);
}

void Graph::addRandomVertice()
{
	srand(time(NULL));
	int random = rand() % 10+1;
	numVertices = random;
	adjList.resize(numVertices);
}

void Graph::addEdge(int source, int destination)
{
	adjList[source].push_back(destination);
	adjList[destination].push_back(source);
}

void Graph::deleteEdge(int source, int destination)
{
		int destinationIndex = -1;
		for (int i = 0; i < adjList[source].size(); i++)
		{
			if (adjList[source][i] == destination)
			{
				destinationIndex = i;
				break;
			}
		}

		if (destinationIndex != -1)
		{
			adjList[source].erase(adjList[source].begin() + destinationIndex);
		}

		int sourceIndex = -1;
		for (int i = 0; i < adjList[destination].size(); i++)
		{
			if (adjList[destination][i] == source)
			{
				sourceIndex = i;
				break;
			}
		}

		if (sourceIndex != -1)
		{
			adjList[destination].erase(adjList[destination].begin() + sourceIndex);
		}
}

void Graph::deleteVertice()
{
	numVertices--;
	adjList.resize(numVertices);
}

void Graph::returnNode(int node)
{
	cout << "The node is " << node << endl;
}

void Graph::depthTraversal(int start)
{
	
	visitedList.push_back(start);
	cout << start << endl;
	for (int i = 0; i < adjList[start].size(); i++)
	{
		bool visited = false;
		for (int j = 0; j < visitedList.size(); j++)
		{
			if (visitedList[j] == adjList[start][i])
			{
				visited = true;
			}
		}
		if (visited == false)
		{
			depthTraversal(adjList[start][i]);
		}
	}
}

int Graph::returnVertices()
{
	return numVertices;
}

int Graph::returnEdges()
{
	return 1;
}

int Graph::size()
{
	return numVertices;
}

bool Graph::isEmpty()
{
 if(numVertices == 0)
 {
 	cout << "The graph is empty" << endl;
	 return true;
	
 }
	cout << "The graph is not empty" << endl;
	return false;
}

bool Graph::isConnected(int source, int destination)
{
	for (int i = 0; i < adjList[source].size(); i++)
	{
		if(adjList[source][i] == destination)
		{
			return true;
		}
		return false;
	}
}

void Graph::print()
{
	for (int i = 0; i < numVertices; i++)
	{
		cout << i << ": ";
		for (int n = 0; n < adjList[i].size(); n++)
		{
			cout << adjList[i][n] << " ";
		}
		cout << endl;
	}
}


