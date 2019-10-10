#pragma once

#include <stdio.h>

void bubbleSort(int source[], int dim);
void heapSort(int source[], int dim);
void insertionSort(int source[], int dim);
void merge(int source[], int left, int center, int right);
void mergeSort(int source[], int left, int right);
void quickSort(int source[], int dim);
void selectionSort(int source[], int dim);

void swap(int* a, int* b);
