/*
Problem: A secret system stores code names in forward order. To display them 
in mirror format, you must transform the given code name so that its 
characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the 
second-last, and so on until the entire string is mirrored
*/

#include <stdio.h>

// Recursive function to print string in mirror format
void mirrorDisplay(char *str) {
    // Base Case: Stop if we reach the end of the string
    if (*str == '\0') {
        return;
    }

    // Recursive Call: Move to the next character
    mirrorDisplay(str + 1);

    // After the recursive call returns, print the current character
    printf("%c", *str);
}

int main() {
    char codeName[100];

    // Read the string input (no spaces)
    if (scanf("%s", codeName) != 1) return 1;

    // Call the recursive function
    mirrorDisplay(codeName);
    
    printf("\n");

    return 0;
}