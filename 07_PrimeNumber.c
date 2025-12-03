/*
What is the 10,001st prime number?
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/*
This is essentially asking us to generate prime numbers.
The simplest way to do this is to iterate through odd numbers (n) using trial division with 1 through sqrt of n to test primality.

This becomes slow, though, so the next fastest way is a prime sieve.
A prime sieve works by generating a list of integers up to a limit, then removing composite numbers.

The simplest version to implement is the Sieve of Eratosthenes.
*/

#define ARRAY_SIZE 10000
#define MARKED 127

typedef struct {
    int capacity;
    int size;
    long *array;
} List;

int append(List *target, long data) {
    if (target->size == target->capacity) {
        target->capacity *= 2;
        target->array = (long*) realloc(target->array, target->capacity * sizeof(long));
    } else if (target->size > target->capacity) {
        exit(EXIT_FAILURE);
    }

    target->array[target->size] = data;
    target->size++;
    return 0;
}

int generateSieve(long lower_bound, char *sieve, int size) {
    
    for (int i = 0; i < size; i++){
        if (sieve[i] == MARKED) continue; // Skip marked numbers
        
        long p = lower_bound + (long) i; // p = c + i
        if (p * p > size + lower_bound) {
            break;
        }

        long m = 0;
        for (long j = 2; m < size + lower_bound; j++){
            m = p * j;
            int idx = (int) (m - lower_bound);
            sieve[idx] = MARKED;
        }
    }

    return 0;
}

int generatePrimes(long lower_bound, char *sieve, int sieve_size, List *primes) {

    for (int i = 0; i < sieve_size; i++) {
        if (sieve[i] == MARKED) continue;

        append(primes, lower_bound + (long) i);
    }
    return 0;
}

int main() {
    long lower_bound = 2;
    char sieve [ARRAY_SIZE] = {0};
    generateSieve(lower_bound, sieve, ARRAY_SIZE);
    List primes = {
        .capacity = 100,
        .size = 0,
        .array = (long*) calloc(100, sizeof(long))
    };
    generatePrimes(lower_bound, sieve, ARRAY_SIZE, &primes);
    printf("Number of primes: %d\n", primes.size);

    printf("[ ");
    for (int i = 0; i < primes.size; i++) {
        printf("%ld ", primes.array[i]);
    }
    printf("]\n");

    return 0;
}