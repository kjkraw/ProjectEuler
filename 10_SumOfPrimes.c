/*
Find the sum of all primes under 2 million.

RESULT: INCOMPLETE
*/

#include <stdlib.h>
#include <stdio.h>

#define UPPER_BOUND 200000

/*
I have a worm in my brain saying that I have to try to do this using a bit array.

Here's the idea:
Each 0 bit is prime, each 1 bit is composite.
The first bit is associated with 2.
The last with UPPER_BOUND.

*/

/*
I have a handful of operations
bitwise and &
bitwise or  |
bitwise xor ^
negation    ~

l shift     <<
r shift     >>

The algorithm looks like this:

1. let p be the first prime number in the series
2. move p spaces
3. mark
4. repeat 2 & 3 until at the end of the series

Let's start with that; an algorithm that marks all of the multiples of a given integer.

*/

#define MASK_SIZE 32
int main(){
    unsigned int mask [MASK_SIZE] = {0};


    // This section creates a bitmask of all composites of p
    int p = 2;  
    unsigned int p_mask [MASK_SIZE] = {0};

    int m = p + p;
    while (m <= UPPER_BOUND) {
        int array_idx = (m - 2) / 32;
        int bit_shift = (m - 2) % 32;
        p_mask[array_idx] |= 1 << bit_shift;
    }

    // You read a bitmask with a cursor and &

    int natural = 2;
    for (int natural = 2; natural <= UPPER_BOUND; natural++) {
        int narray_idx = (natural - 2) / 32;
        int nbit_shift = (natural - 2) % 32;
        unsigned int cursor = 1 << nbit_shift;
        if (mask[narray_idx] & cursor == 0) { // This means the number at this spot is NOT MARKED

        }
    }

}
