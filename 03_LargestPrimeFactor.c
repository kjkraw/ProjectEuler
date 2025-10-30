/*Largest Prime Factor
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143?

RESULT: CORRECT
*/

#include <stdio.h>
#include <math.h>

/**
Check whether a number is prime using trial division.
Is n a multiple of any integer between 2 and sqrt(n)?
*/
int isPrime(long long n) {
    long long sqrt_n = (long long)floor(sqrt((double)n));
    for (long long i = 2; i < sqrt_n; i++) {
        if (i > 2 && !(i & 1)){
            continue;
        }
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    long long factorize = 600851475143;
    long long max_factor = (long long)floor(sqrt((double)factorize));
    long long result = 0;
    for (long long i = 2; i <= max_factor; i++) {
        if (factorize % i == 0){
            // IS A FACTOR
            if(isPrime(i)){
                // IS A PRIME FACTOR
                if (i > result) {
                    result = i;
                }
            }
        }
    }

    printf("The greatest prime factor is: %lld\n", result);
    return 0;
}