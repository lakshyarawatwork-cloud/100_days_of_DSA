/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long sum;
    int index;
    int used;
} Entry;

int main() {
    int arr[100000], n = 0;
    while (scanf("%d", &arr[n]) == 1) n++;

    int size = 2 * n + 1;
    Entry *hash = calloc(size, sizeof(Entry));

    long long prefix = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        if (prefix == 0)
            maxLen = i + 1;

        int h = ((prefix % size) + size) % size;

        while (hash[h].used && hash[h].sum != prefix)
            h = (h + 1) % size;

        if (!hash[h].used) {
            hash[h].used = 1;
            hash[h].sum = prefix;
            hash[h].index = i;
        } else {
            int len = i - hash[h].index;
            if (len > maxLen)
                maxLen = len;
        }
    }

    printf("%d", maxLen);

    free(hash);
    return 0;
}