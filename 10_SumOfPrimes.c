/*
Find the sum of all primes under 2 million.

RESULT: SUCCESS
*/

#include <stdlib.h>
#include <stdio.h>


/*
I've already made a prime sieve before, so I wanted to try something a little different.
Here, I used a bitmask as the sieve for the Sieve of Eratosthenes algorithm.
This means that the algorithm is mostly made up of bitwise operations.

This was a fun challenge!
*/

#define MASK_SIZE 62500
#define UPPER_BOUND 2000000

int main(){
    long long sum = 0;
    unsigned int * mask = calloc(MASK_SIZE, sizeof(unsigned int));

    // You read a bitmask with a cursor and &
    for (int p = 2; p <= UPPER_BOUND; p++) {
        int outer_idx = (p - 2) / 32;
        int outer_shift = (p - 2) % 32;
        unsigned int cursor = 1 << outer_shift;
        if (!(mask[outer_idx] & cursor)) {
            sum += p;
            // This section creates a bitmask of all composites of p.
            unsigned int * p_mask = calloc(MASK_SIZE, sizeof(unsigned int));
            int m = p + p;
            while (m <= UPPER_BOUND) {
                int array_idx = (m - 2) / 32;
                int bit_shift = (m - 2) % 32;
                p_mask[array_idx] |= 1 << bit_shift;
                m += p;
            }
            for (int i = 0; i < MASK_SIZE; i++){
                // The bitmask of p composites is added to the main mask.
                mask[i] |= p_mask[i];
            }
            free(p_mask);
        }
    }

    printf("Sum: %lld \n", sum);
}
