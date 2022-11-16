#pragma once

typedef struct node {
	int vertex;
	struct node* next;
} graphNode;

typedef struct graph {
	int verticeNum;
	struct node** adjLists;
} graph;

graphNode* createNode(int v);
graph* createGraph(int verticeNum);
void addEdge(graph* graph, int source, int dest);
