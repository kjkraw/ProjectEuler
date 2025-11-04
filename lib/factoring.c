#include <stdlib.h>

#define ULL unsigned long long

/** Find the factors of a number using trial division.
This is a very naieve and ineffective way to 
@param to_factor The number that should be factored
@param factors Pointer to the pointer to the start of the array
@return num_factors The number of factors (the length of the factors array)
*/
int trialdivision(ULL to_factor, ULL **factors) {
    int num_factors = 0;
    ULL *factors_ptr = NULL;

    for (ULL i = 1; i <= to_factor; i++) {
        if (to_factor % i == 0) {
            num_factors++;
            factors_ptr = realloc(factors_ptr, num_factors * sizeof(ULL));

            *(factors_ptr + (num_factors - 1)) = i;
        }
    }

    *factors = factors_ptr;
    return num_factors;
}
