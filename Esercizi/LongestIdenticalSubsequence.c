#include <stdlib.h>

#include "library.h"

int lis(int source[], int left, int right)
{
	if (right - left < 0)
		return 0;

	if (source[left] == source[right] && left != right)
		return 2 + lis(source, left + 1, right - 1);
	if (source[left] == source[right] && left == right)
		return 1;

	return max(lis(source, left + 1, right), lis(source, left, right - 1));
}

int longestIdenticalSubsequenceLengthDP(int source[], int size)
{
	int maxCount = 0;

	for (int i = 0; i < size; i++)
	{
		int count = 0;

		for (int j = i + 1; j < size; j++)
		{
			if (source[i] == source[j] && j - i == 1)
				count = 2;
			else if (source[i] == source[j])
				count++;
			else
				break;
		}

		if (count > maxCount)
			maxCount = count;

		if (maxCount == size)
			return maxCount;
	}

	return maxCount;
}

int longestIdenticalSubsequenceLength(int source[], int size)
{
	return lis(source, 0, size - 1);
}