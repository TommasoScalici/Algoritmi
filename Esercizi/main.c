#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable: 6031)

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "datastructures.h"
#include "library.h"


void getArray(int** arr, int* size);
void printArray(int* source, int size);
void printList(listNode* head);


int main()
{
	setlocale(LC_ALL, "");

	clock_t time;
	int choice = -1;


	printf("--- Esercizi di Algoritmi ---\n\n"
		   "1) Longest Identical Subsequence\n"
		   "2) Largest Contiguous Subsequence Sum\n"
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
			//printArray(arr, size);
			time = clock();
			printf("La sotto-sequenza identica più lunga ha lunghezza: %d\n", longestIdenticalSubsequenceLength(arr, size));
			double timeElapsed = ((double)clock() - time) / CLOCKS_PER_SEC;
			printf("Tempo impiegato per l'elaborazione: %f\n\n", timeElapsed);
			break;
		}
		case 2:
		{
			int* arr = NULL;
			int size = 0;
			getArray(&arr, &size);
			//printArray(arr, size);
			double timeElapsed;

			time = clock();			
			printf("Il valore della sotto-sequenza contigua di valore massimo è: %d (calcolato ricorsivamente)\n", maxSubsequenceSum(arr, 0, size - 1));
			timeElapsed = ((double)clock() - time) / CLOCKS_PER_SEC;
			printf("Tempo impiegato per l'elaborazione: %f\n\n", timeElapsed);
			time = clock();
			printf("Il valore della sotto-sequenza contigua di valore massimo è: %d (calcolato NON ricorsivamente)\n", maxSubSequenceSumNR(arr, size));
			timeElapsed = ((double)clock() - time) / CLOCKS_PER_SEC;
			printf("Tempo impiegato per l'elaborazione: %f\n\n", timeElapsed);
		}
			break;
		case 3:
		{
			listNode *list1 = NULL, *list2 = NULL;
			int array1[5] = { 2, 5, 10, 11, 12 };
			int array2[6] = { 6, 8, 10, 13, 15, 17 };

			for (int i = 0; i < 5; i++)
				list1 = addNode(list1, array1[i]);

			for (int j = 0; j < 6; j++)
				list2 = addNode(list2, array2[j]);

			listNode* mergedList = mergeTwoOrderedList(list1, list2);

			printList(list1);
			printList(list2);
			printList(mergedList);
		}
			break;
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
		srand((unsigned int)time(NULL));

		for (int i = 0; i < *size; i++)
			temp[i] = rand() % 200 - 100;
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

void printList(listNode* head)
{
	listNode* temp = head;

	printf("\n{ ");

	do
	{
		printf("%d", temp->data);

		if(temp->next != NULL)
			printf(" -> ");
	} while ((temp = temp->next) != NULL);

	printf("}\n");
}