#include <stdio.h>

int main()
{
	int arr[] = { 5, 8, 3, 4, 7, 15, 2, 3, 9, 12 };

	for (size_t i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	printf("\n");
	mergeSort(arr, 0, 9);

	for (size_t i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	return 0;
}