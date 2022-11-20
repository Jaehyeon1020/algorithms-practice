#pragma once

#define CITY_NUM 26 // 26���� ����

typedef struct node {
	int city;
	struct node* next;
} graphNode;

typedef struct Graph {
	int verticeNum;
	struct node** adjLists;
} Graph;

graphNode* createNode(int city);
Graph* createGraph(int verticeNum);
void addEdge(Graph* graph, int source, int dest);
int isAlreadyConnected(Graph* graph, int source, int dest);
int getConnections(Graph* graph, int city);
