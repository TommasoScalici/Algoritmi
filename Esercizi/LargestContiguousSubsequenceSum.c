#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "library.h"

int max3(int a, int b, int c) { return max(max(a, b), c); }

int maxCrossingSum(int* a, int left, int mid, int right)
{
    int sum = 0;
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;

    for (int i = mid; i >= left; i--)
    {
        sum += a[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;

    for (int i = mid + 1; i <= right; i++)
    {
        sum += a[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubsequenceSum(int* a, int left, int right)
{
    if (left == right)
        return a[left];

    int mid = (left + right) / 2;

    return max3(maxSubsequenceSum(a, left, mid),
        maxSubsequenceSum(a, mid + 1, right),
        maxCrossingSum(a, left, mid, right));
}

int maxSubSequenceSumNR(int* a, const int n)
{
    int sum = 0;
    int maxSum = INT_MIN;

    int *sums = (int*)malloc(sizeof(int) * n);

    if (sums != NULL)
    {
        sums[0] = a[0];

        for (int i = 1; i < n; i++)
            *(sums + i) = sums[i - 1] + a[i];

        for (int i = 0; i < n; i++)
        {
            maxSum = max(maxSum, *(sums + i) - sum);
            sum = min(sum, *(sums + i));
        }
    }

    return maxSum;
}