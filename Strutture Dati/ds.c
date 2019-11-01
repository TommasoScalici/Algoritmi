#include "ds.h"

#include <stdlib.h>

listNode* newListNode(int value)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));

	if (newNode == NULL)
		return NULL;

	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

graph* createGraph(int nVertices)
{
	graph* g = (graph*)malloc(sizeof(graph));

	if (g == NULL)
		return NULL;

	g->adjancyLists = (list*)malloc(sizeof(list) * nVertices);
	g->numberOfVertices = nVertices;

	if(g->adjancyLists != NULL)
		for (int i = 0; i < nVertices; i++)
			((g->adjancyLists) + i)->head = NULL;

	return g;
}

void addEdge(graph* g, int src, int dest)
{
	listNode* newNode = newListNode(dest);
	newNode->next = g->adjancyLists[src].head;
	g->adjancyLists[src].head = newNode;

	newNode = newListNode(src);
	newNode->next = g->adjancyLists[dest].head;
	g->adjancyLists[dest].head = newNode;
}