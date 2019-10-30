#pragma once

typedef struct listNode
{
	int data;
	struct listNode* next;
} listNode;

typedef struct list
{
	listNode* head;
} list;

typedef struct graph
{
	int numberOfVertices;
	struct list* adjancyLists;
} graph;


void addEdge(graph* g, int src, int dest);
graph* createGraph(int nVertices);