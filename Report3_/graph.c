/**
* Functions that implement graph with adjacency list
*/

#pragma warning(disable:4996)

#include <stddef.h>
#include "graph.h"
#include "rbtree.h"
#include "reservation.h"
#include "linkedList.h"

graphNode* createNode(int city) {
	graphNode* newNode = malloc(sizeof(graphNode));
	newNode->city = city;
	newNode->next = NULL;
	return newNode;
}

Graph* createGraph(int verticeNum) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->verticeNum = verticeNum;

	graph->adjLists = malloc(verticeNum * sizeof(graphNode));

	int i;
	for (i = 0; i < verticeNum; i++)
		graph->adjLists[i] = NULL;

	return graph;
}

void addEdge(Graph* graph, int source, int dest) {
	graphNode* newNode = createNode(dest);
	newNode->next = graph->adjLists[source];
	graph->adjLists[source] = newNode;

	newNode = createNode(source);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

/* get if source and dest are already connected*/
int isAlreadyConnected(Graph* graph, int source, int dest) {
	graphNode* sourceNode = graph->adjLists[source];

	while (sourceNode != NULL) {
		if (sourceNode->city == dest) {
			return 1;
		}

		sourceNode = sourceNode->next;
	}

	return 0;
}

/* get the number of connections of all cities*/
int getConnections(Graph* graph, int city) {
	int connections = 0;
	graphNode* ptrNode = graph->adjLists[city];

	while (ptrNode != NULL) {
		connections += 1;
		ptrNode = ptrNode->next;
	}

	return connections;
}