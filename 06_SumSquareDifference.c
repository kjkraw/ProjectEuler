/*
The sum of the squares of the first ten natural numbers is,
1**2 + 2**2 + ... + 10**2 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)**2 = 55**2 = 3025
Hence, the difference is,
3024 - 285 = 2640
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

RESULT: CORRECT
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char in [256];
    printf("Input maximum: ");
    gets(in);
    long max = strtol(in, NULL, 10);

    printf("Calculating sum of squares...\n");
    long sum_squares = 0;
    for (long i = 1; i <= max; i++){
        sum_squares += i * i;
    }

    printf("Calculating square of sum...\n");
    long sum = 0;
    for (long i = 1; i <= max; i++){
        sum += i;
    }
    long square_sum = sum * sum;

    printf("Difference: %ld", square_sum - sum_squares);
}