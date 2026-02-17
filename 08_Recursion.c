/*
Problem: Given integers a and b, compute a^b using recursion without using 
pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32
*/

#include <stdio.h>

// Recursive function to calculate power
long long power(int a, int b) {
    // Base Case: a^0 = 1
    if (b == 0) {
        return 1;
    }
    
    // Recursive Step: a^b = a * a^(b-1)
    return a * power(a, b - 1);
}

int main() {
    int a, b;

    // Read input a and b
    if (scanf("%d %d", &a, &b) != 2) return 1;

    // Output the result
    // Note: using long long to handle larger results
    printf("%lld\n", power(a, b));

    return 0;
}