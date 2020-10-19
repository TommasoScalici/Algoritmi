#include "datastructures.h"

#include <stdlib.h>

listNode* addNode(listNode *node, int value)
{
	if (node == NULL)
	{
		node = (listNode*)malloc(sizeof(listNode));

		if (node != NULL)
		{
			node->data = value;
			node->next = NULL;
		}
	}
	else
		node->next = addNode(node->next, value);

	return node;
}