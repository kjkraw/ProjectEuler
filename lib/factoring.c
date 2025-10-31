#include <stdlib.h>

/** Find the factors of a number using trial division.
This is a very naieve and ineffective way to 
@param to_factor The number that should be factored
@param num_factors The number of factors (the length of the array returned)
@return a pointer to the array of factors (sorted)
*/
long long *trialdivision(long long to_factor, int *num_factors) {
    *num_factors = 1;
    long long *factors = malloc(*num_factors * sizeof(long long));
    factors[0] = 1;

    for (long long i = 2; i < to_factor; i++){
        if (to_factor % i == 0){
            *num_factors++;
            factors = realloc(factors, *num_factors * sizeof(long long));
            factors[*num_factors - 1] = i;
        }
    }

    *num_factors++;
    factors = realloc(factors, *num_factors * sizeof(long long));
    factors[*num_factors - 1] = to_factor;
    return factors;
}

#include <stdio.h>

int main() {
    for (int i = 2; i < 100; i++){
        printf("Factoring %d...\n", i);
        int num_factors = 0;
        long long *factors = trialdivision(i, &num_factors);
        printf("Number of factors: %d | ", num_factors);
        printf("Factors: [ ");
        for (int j = 0; j < num_factors; j++) {
            printf("%lld ", factors[j]);
        }
        printf(" ]\n");
    }
    return 0;
}