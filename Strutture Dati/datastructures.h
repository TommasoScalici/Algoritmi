#pragma once

typedef struct listNode
{
	int data;
	struct listNode* next;
} listNode;

listNode* addNode(listNode* node, int value);