#include <stdio.h>

#include "functions.h"

int main()
{
	int arr[] = { 5, 8, 3, 4, 7, 15, 2, 3, 9, 12 };

	for (size_t i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	printf("\n");
	quickSort(arr, 10);

	for (size_t i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	return 0;
}