/*
Problem: A system receives two separate logs of user arrival times from two 
different servers. Each log is already sorted in ascending order. Your task is 
to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, 
  separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and 
append the earlier one to the final log until all entries are processed
*/

#include <stdio.h>

int main() {
    int p, q;

    // Read size and elements for the first log
    if (scanf("%d", &p) != 1) return 1;
    int log1[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    // Read size and elements for the second log
    if (scanf("%d", &q) != 1) return 1;
    int log2[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    int i = 0, j = 0;
    int first = 1; // Flag to handle space-separated printing

    // Merge process
    while (i < p && j < q) {
        if (!first) printf(" ");
        if (log1[i] <= log2[j]) {
            printf("%d", log1[i]);
            i++;
        } else {
            printf("%d", log2[j]);
            j++;
        }
        first = 0;
    }

    // Print remaining elements from log1
    while (i < p) {
        if (!first) printf(" ");
        printf("%d", log1[i]);
        i++;
        first = 0;
    }

    // Print remaining elements from log2
    while (j < q) {
        if (!first) printf(" ");
        printf("%d", log2[j]);
        j++;
        first = 0;
    }

    printf("\n");
    return 0;
}