#include "functions.h"

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;

} node;

typedef node* nodePtr;

void bubbleSort(int source[], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (source[j] > source[j + 1])
				swap(&source[j], &source[j + 1]);
		}
	}
}

void heapSort(int source[], int size)
{
	nodePtr heap = buildHeap(source, size);
}

nodePtr insertNode(int data)
{
	nodePtr node = (nodePtr)malloc(sizeof(node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

int* buildHeap(nodePtr node, int source[], int i, int size)
{
	if (i < size)
	{
		nodePtr temp = insertNode(source[i]);
		node = temp;

		node->left = buildHeap(node->left, source, i * 2 + 1, size);
		node->right = buildHeap(node->right, source, i * 2 + 2, size);
	}

	return node;
}

void insertionSort(int source[], int size)
{
	for (int i = 0; i < size - 1 ; i++)
	{
		for (int j = i; j >= 0 && source[j] > source[j + 1]; j--)
		{
			swap(&source[j], &source[j + 1]);
		}
	}
}

void merge(int source[], int left, int center, int right)
{
	int size1 = center - left + 1;
	int size2 = right - center;

	int* leftArray = (int*)malloc(sizeof(int) * size1);
	int* rightArray = (int*)malloc(sizeof(int) * size2);

	if (leftArray != NULL && rightArray != NULL)
	{
		for (int i = 0; i < size1; i++)
			leftArray[i] = source[left + i];

		for (int j = 0; j < size2; j++)
			rightArray[j] = source[center + 1 + j];

		int i = 0, j = 0, k = left;

		while (i < size1 && j < size2)
		{
			if (leftArray[i] <= rightArray[j])
			{
				source[k] = leftArray[i];
				i++;
			}
			else
			{
				source[k] = rightArray[j];
				j++;
			}

			k++;
		}

		while (i < size1)
		{
			source[k] = leftArray[i];
			i++;
			k++;
		}

		while (j < size2)
		{
			source[k] = rightArray[j];
			j++;
			k++;
		}
	}
}

void mergeSortDivide(int source[], int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSortDivide(source, left, center);
		mergeSortDivide(source, center + 1, right);
		merge(source, left, center, right);
	}

	return;
}

void mergeSort(int source[], int size)
{
	mergeSortDivide(source, 0, size - 1);
}

int partition(int source[], int size, int pivot)
{
	int i = 0, j = size - 1, pivotValue;

	if (size <= 1)
		return pivot;

	pivotValue = source[pivot];
	source[pivot] = source[0];

	for (;;)
	{
		while (j > i && source[j] > pivotValue)
			j--;

		if (j == i)
			break;

		source[i++] = source[j];

		while (i < j && source[i] < pivotValue)
			i++;

		if (i == j)
			break;

		source[j--] = source[i];
	}

	source[i] = pivotValue;
	return i;
}

void quickSort(int source[], int size)
{
	int* p = source;
	int pivot;

	while (size > 1)
	{
		pivot = (int)(rand() / (RAND_MAX + 1.0) * size);

		if (pivot >= size)
			pivot = size - 1;

		pivot = partition(p, size, pivot);

		if (pivot > size - pivot - 1)
		{
			quickSort(p + (pivot + 1), size - (pivot + 1));
			size = pivot;
		}
		else
		{
			quickSort(p, pivot);
			p += pivot + 1;
			size -= pivot + 1;
		}
	}
}

void selectionSort(int source[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;

		for (int j = i; j < size; j++)
		{
			if (source[j] < source[min])
				min = j;
		}

		swap(&source[i], &source[min]);
	}
}


void swap(int* a, int* b)
{
	int temp = *a;
	*a= *b;
	*b = temp;
}
