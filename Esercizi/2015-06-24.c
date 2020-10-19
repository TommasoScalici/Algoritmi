#include <stdio.h>

#include "datastructures.h"

listNode* mergeTwoOrderedList(listNode* list1, listNode* list2)
{
	listNode* mergedList = NULL;
	listNode* temp1 = list1;
	listNode* temp2 = list2;
	
	while (temp1 != NULL || temp2 != NULL)
	{
		if (temp1 == NULL)
		{
			while (temp2 != NULL)
			{
				mergedList = addNode(mergedList, temp2->data);
				temp2 = temp2->next;
			}
		}

		else if (temp2 == NULL)
		{
			while (temp1 != NULL)
			{
				mergedList = addNode(mergedList, temp1->data);
				temp1 = temp1->next;
			}
		}

		else
		{
			if (temp1->data == temp2->data)
			{
				mergedList = addNode(mergedList, temp1->data);
				mergedList = addNode(mergedList, temp2->data);
				temp1 = temp1->next;
				temp2 = temp2->next;
			}

			else if (temp1->data < temp2->data)
			{
				mergedList = addNode(mergedList, temp1->data);
				temp1 = temp1->next;
			}

			else
			{
				mergedList = addNode(mergedList, temp2->data);
				temp2 = temp2->next;
			}
		}
	}

	return mergedList;
}