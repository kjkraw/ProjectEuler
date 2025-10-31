/*Largest Palindrome Product
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 \times 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
What is the differnce between:
- char buffer [10];
- char* buffer = (char*) calloc(10, sizeof(char));
*/

#define MAX_DIGITS 10
#define FACTOR_LIMIT 999

int reverseInt(int n) {
    char *buffer = (char*) calloc(MAX_DIGITS + 1, sizeof(char));
    if (buffer == NULL) exit(1);
    sprintf(buffer, "%d", n);

    int i = 0;
    while (buffer[i] != '\0') i++;
    int buf_len = i + 1; // Add space for \0 at end of array
    buffer = realloc(buffer, buf_len * sizeof(char));
    
    char *rev_buffer = (char*) calloc(buf_len, sizeof(char));
    if (rev_buffer == NULL) exit(1);

    const int rev_offset = buf_len - 2; // length -1 (for zero-indexing) -1 (to leave room for \0)
    for (int i = 0; i < buf_len - 1; i++) { // We end the loop before the \0
        rev_buffer[(rev_offset) - i] = buffer[i];
    }

    return atoi(rev_buffer);
}

int isPalindrome(int n) {
    return n == reverseInt(n);
}

int main() {
    printf("%d\n", reverseInt(12345));
    return 1;

    int factor_a = 0;
    int factor_b = 0;
    int cur_best = 0;
    for (int i = FACTOR_LIMIT; i > 99; i--) {
        for (int j = FACTOR_LIMIT; j > 99; j--) {
            int cur = i * j;
            printf("%d\n", cur_best);
            if (isPalindrome(cur) && cur > cur_best){
                cur_best = cur;
                factor_a = i;
                factor_b = j;
            }        
        }
    }

    printf("Largest palindrome %d\nFactors: %d, %d\n", cur_best, factor_a, factor_b);
    return 0;
}