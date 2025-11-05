/* Smallest Multiple
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>
#include <stdlib.h>
#include "../ProjectEuler/lib/mymath.h"

int test(unsigned long long n) {
    for (int i = 2; i <= 20; i++) {
        if (n % i != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {

    /*
    We know that 20! is going to have all of the numbers as factors, so we call that an upper bound.
    What happens if we divide 20! by 2?
    We end up with a number significantly smaller, which may still have all of the factors.
    What if we do it again? And again?
    Until it no longer has all the factors.
    That gives us new upper bounds and lower bounds.
    Let's try it!
    */

    printf("Testing numbers...\n");

    unsigned long long new_low = 0;
    unsigned long long current_lowest = factorial(20);
    while (1) {
        new_low = current_lowest / 2;
        printf("Testing %lld...\n", new_low);
        if (!test(new_low)) {
            break;
        }
        current_lowest = new_low;
    }
    printf("Bounds: (%lld, %lld]\n", new_low, current_lowest);


    return 0;

    printf("Testing numbers...\n");
    unsigned long long i = 0;
    while (1) {
        i += 20; // Increment by the largest factor
        printf("%lld  ", i);

        unsigned long long *factors = NULL;
        int num_factors = trialdivision(i, &factors);
        if (num_factors < 20) {
            free(factors);
            continue;
        }


        for (int j = 1; j <= 20; j++) {
            if (factors[j-1] != j){
                break;
            }
            if (j == 20){
                printf("Solution: %lld\n", i);
                return;
            }
        }

        free(factors);
    }
}
