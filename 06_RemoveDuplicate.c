/*
Problem: Given a sorted array of n integers, remove duplicates in-place. 
Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/

#include <stdio.h>

int main() {
    int n;

    // Read array size
    if (scanf("%d", &n) != 1) return 1;
    
    // Handle empty array case
    if (n == 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // i tracks the index of the last unique element found
    int i = 0;

    // j scans the rest of the array
    for (int j = 1; j < n; j++) {
        // If we find a new unique value
        if (arr[j] != arr[i]) {
            i++;           // Move unique pointer forward
            arr[i] = arr[j]; // Update the next unique slot
        }
    }

    // The unique elements are now in the range arr[0] to arr[i]
    for (int k = 0; k <= i; k++) {
        printf("%d%s", arr[k], (k == i) ? "" : " ");
    }
    printf("\n");

    return 0;
}