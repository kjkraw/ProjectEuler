/* Smallest Multiple
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

RESULT: SUCCESS
*/

#include <stdio.h>
#include <stdlib.h>

int TestSolution(long product, long max_factor) {
    /** Check that all integers from 1 to max_factor are factors of product. */
    for (long i = 1; i <= max_factor; i++) {
        if (product % i != 0) return 0;
    }
    return 1;
}

/*
Naievely, I can increment a number until I hit one for which all others are a factor.
First hit wins.
*/

int main() {
    char in [256];
    printf("Input max factor: ");
    gets(in);
    long max_factor = strtol(in, NULL, 10);

    long current = 0;
    printf("Current: \n");
    do{
        printf("%ld\r", current);
        current += max_factor;
    }while(!TestSolution(current, max_factor));
    printf("\n\nResult: %ld", current);
    return 1;
}
