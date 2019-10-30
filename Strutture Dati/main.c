#include <stdio.h>
#include <stdlib.h>

#include "ds.h"

void printGraph(graph* g);

int main()
{
	int V = 5;
	graph* g = createGraph(V);
	addEdge(g, 0, 1);
	addEdge(g, 0, 4);
	addEdge(g, 1, 2);
	addEdge(g, 1, 3);
	addEdge(g, 1, 4);
	addEdge(g, 2, 3);
	addEdge(g, 3, 4);

	// print the adjacency list representation of the above graph 
	printGraph(g);

	return 0;
}

void printGraph(graph* g)
{
	int v;
	for (v = 0; v < g->numberOfVertices; v++)
	{
		struct listNode* pCrawl = g->adjancyLists[v].head;
		printf("\n Lista di adiacenza del vertice %d\n head ", v);
		while (pCrawl)
		{
			printf("-> %d", pCrawl->data);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}