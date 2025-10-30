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

#define FACTOR_LIMIT 999

int reverseInt(int n) {
    char* buffer = (char*) calloc(11, sizeof(char));
    if (buffer == NULL) exit(1);
    char* rev_buffer = (char*) calloc(11, sizeof(char));
    if (rev_buffer == NULL) exit(1);

    sprintf(buffer, "%d", n);
    for (int i = 0; i < 10; i++) {
        /* I believe that something is going wrong here.
        I'm not exactly sure, but part of the problem is that I don't truly understand arrays and pointers.
        I guess I need to read up on this more in order to get this challenge correct.
        */
        rev_buffer[0+i] = buffer[9-i];
    }

    return atoi(rev_buffer);
}

int isPalindrome(int n) {
    return n == reverseInt(n);
}

int main() {
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