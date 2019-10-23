#pragma once

#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;

} node;

typedef node* nodePtr;

void bubbleSort(int source[], int size);
void heapSort(int source[], int size);
void insertionSort(int source[], int size);
void mergeSort(int source[], int size);
void quickSort(int source[], int size);
void selectionSort(int source[], int size);

void swap(int* a, int* b);
