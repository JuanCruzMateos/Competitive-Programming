/*
1672. Richest Customer Wealth
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank.
Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts.
The richest customer is the customer that has the maximum wealth.
*/
/*
Success
Details
Runtime: 4 ms, faster than 97.59% of C online submissions for Richest Customer Wealth.
Memory Usage: 6.1 MB, less than 64.38% of C online submissions for Richest Customer Wealth.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

int maximumWealth(int **accounts, int accountsSize, int *accountsColSize) {
    int max = 0, sum;
    int i, j;

    for (i=0; i<accountsSize; i++) {
        sum = 0;
        for (j=0; j<*accountsColSize; j++) {
            sum += accounts[i][j];
        }
        if (sum > max)
            max = sum;
    }
    return max;
}
