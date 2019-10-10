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
	int i = left;
	int j = center + 1;
	int k = 0;

	int arrayTempSize = right - left + 1;


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
