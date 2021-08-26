/*
Running Sum of 1d Array:
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]). Return the running sum of nums.
*/

/*
Runtime: 12 ms, faster than 7.03% of C online submissions for Running Sum of 1d Array.
Memory Usage: 6.7 MB, less than 64.17% of C online submissions for Running Sum of 1d Array
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 10

void printArr(int vec[], int n);
int *runningSum(int *nums, int numsSize, int *returnSize);

int main()
{
    int v[DIM] = {1,2,3,4};
    int n = 4, returnSize;
    int *r;

    r = runningSum(v, n, &returnSize);
    printArr(r, n);

    return 0;
}


int *runningSum(int *nums, int numsSize, int *returnSize) {
    int *v;
    int i, j;

    // *returnSize = numsSize para que funcionara -> no deberia devolver mas de un valor al ser una funcion int

    v = (int *) malloc(sizeof(int) * numsSize);

    for (i=0; i<numsSize; i++)
        v[i] = 0;

    for (i=0; i<numsSize; i++) {
        for (j=i; j<numsSize; j++)
            *(v+j) = *(v+j) + *(nums+i);
    }
    return v;
}


void printArr(int vec[], int n) {
    int i;

    for (i=0; i<n; i++)
        printf("%d ", vec[i]);
}
