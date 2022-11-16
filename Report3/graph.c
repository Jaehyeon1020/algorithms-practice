/**
* Functions that implement graph with adjacency list
*/

#include "graph.h"

graphNode* createNode(int v) {
	graphNode * newNode = malloc(sizeof(graphNode));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

graph* createGraph(int verticeNum) {
	graph* graph = malloc(sizeof(graph));
	graph->verticeNum = verticeNum;

	graph->adjLists = malloc(verticeNum * sizeof(graphNode));

	int i;
	for (i = 0; i < verticeNum; i++)
		graph->adjLists[i] = NULL;

	return graph;
}

void addEdge(graph* graph, int source, int dest) {
	graphNode* newNode = createNode(dest);
	newNode->next = graph->adjLists[source];
	graph->adjLists[source] = newNode;

	newNode = createNode(source);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}