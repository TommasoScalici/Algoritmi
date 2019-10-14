#include "functions.h"

void bubbleSort(int source[], int dim)
{
	for (size_t i = 0; i < dim; i++)
	{
		for (size_t j = 0; j < dim - i - 1; j++)
		{
			if (source[j] > source[j + 1])
				swap(&source[j], &source[j + 1]);
		}
	}
}

void insertionSort(int source[], int dim)
{
	for (int i = 0; i < dim - 1 ; i++)
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

	int* leftArray = malloc(sizeof(int) * size1);
	int* rightArray = malloc(sizeof(int) * (right - center));

	for (int i = 0; i < size1; i++)
		leftArray[i] = source[left + i];
	for (int j = 0; j < size2; j++)
		rightArray[j] = source[center + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;

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

void mergeSort(int source[], int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSort(source, left, center);
		mergeSort(source, center + 1, right);
		merge(source, left, center, right);
	}

	return;
}

void selectionSort(int source[], int dim)
{
	for (size_t i = 0; i < dim; i++)
	{
		int min = i;

		for (size_t j = i; j < dim; j++)
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
