/* 1470. Shuffle the Array
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
Return the array in the form [x1,y1,x2,y2,...,xn,yn].
*/
/*
Success Details:
Runtime: 12 ms, faster than 93.33% of C online submissions for Shuffle the Array.
Memory Usage: 7.4 MB, less than 22.29% of C online submissions for Shuffle the Array.
*/

// Mejos solucion -> ver final

#include <stdio.h>
#include <stdlib.h>
#define DIM 6

int* shuffle(int* nums, int numsSize, int n, int* returnSize);
void printArr(int *nums, int size);

int main()
{
    int nums[DIM] = {1,2,3,4,5,6};
    int numsSize = 6, returnSize;
    int n = numsSize / 2;
    int *solution;

    solution = shuffle(nums, numsSize, n, &returnSize);
    printArr(solution, returnSize);
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int* solution;
    int i, j = 0;

    *returnSize = numsSize;
    solution = (int*) malloc(sizeof(int) * numsSize);
    for (i=0; i<numsSize; i+=2) {
        solution[i] = nums[j];
        solution[i+1] = nums[j + n];
        j += 1;
    }
    return solution;
}

void printArr(int *nums, int size) {
    int i;

    for (i=0; i<size; i++) {
        printf("%d ", *(nums+i));
    }
}


/*
Success Details:
Runtime: 12 ms, faster than 93.33% of C online submissions for Shuffle the Array.
Memory Usage: 7.2 MB, less than 45.52% of C online submissions for Shuffle the Array.
*/
//int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
//    int* solution;
//    int k = 0, i = 0, j = n;
//
//    *returnSize = numsSize;
//    solution = (int*) malloc(sizeof(int) * numsSize);
//    for (k=0; k<numsSize; k+=2) {
//        solution[k] = nums[i++];
//        solution[k+1] = nums[j++];
//    }
//    return solution;
//}
