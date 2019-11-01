#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable: 6031)

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "library.h"


void getArray(int** arr, int* size);
void printArray(int* source, int size);


int main()
{
	setlocale(LC_ALL, "");

	clock_t time;
	int choice = -1;


	printf("--- Esercizi di Algoritmi ---\n\n"
		   "1) Longest Identical Subsequence\n"
		   "0) Esci dal programma\n\n");

	do
	{
		printf("Fai una scelta: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			return 0;
		case 1:
		{
			int* arr = NULL;
			int size = 0;
			getArray(&arr, &size);
			printArray(arr, size);
			time = clock();
			printf("La sotto-sequenza identica più lunga ha lunghezza: %d\n", longestIdenticalSubsequenceLength(arr, size));
			double timeElapsed = ((double)clock() - time) / CLOCKS_PER_SEC;
			printf("Tempo impiegato per l'elaborazione: %f\n\n", timeElapsed);
			break;
		}
		default:
			printf("Scelta non valida.\n\n");
			rewind(stdin);
			break;
		}
	} while (choice);

	return 0;
}

void getArray(int** arr, int* size)
{
	int choice = -1;
	int* temp;

	printf("\n1) Array inserito manualmente");
	printf("\n2) Array generato casualmente\n");

	do
	{
		printf("\nFai una scelta: ");
		scanf("%d", &choice);
	} while (choice != 1 && choice != 2);

	do
	{
		printf("\nInserisci la dimensione dell'array: ");
		scanf("%d", size);
	} while (*size < 1);

	temp = malloc(sizeof(int) * *size);

	if (choice == 1)
	{
		for (int i = 0; i < *size; i++)
		{
			printf("X[%d]: ", i);
			scanf("%d", &temp[i]);
		}
	}

	if (choice == 2)
	{
		for (int i = 0; i < *size; i++)
			temp[i] = rand() % 100 + 1;
	}

	*arr = temp;
}

void printArray(int* source, int size)
{
	printf("\n{ ");
	for (int i = 0; i < size; i++)
	{
		printf("%d", source[i]);

		if (i == size - 1)
			printf(" ");
		else
			printf(", ");
	}

	printf("}\n");
}