/* Smallest Multiple
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>
#include <stdlib.h>
#include "../ProjectEuler/lib/factoring.h"

int main() {

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
