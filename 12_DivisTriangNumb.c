/*
The sequence of triangle numbers is made by summing the natural numbers.
e.g. 7th = 1+2+3+4+5+6+7
What is the first triangle number to have over 500 divisors?
*/

#include <stdio.h>
#include <stdlib.h>

const int primes[58] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271};

int num_factors(long n) {

    int exponents[58] = {0};

    for (int i = 0; i < 58; i++) {
        if (n == primes[i]){
            return 2; // Number is a small prime
        }
    }

    while(1) {
        for (int i = 0; i < 58; i++) {
            if (n == primes[i]) {
                exponents[i]++;
                int num_divisors = 1;
                for (int j = 0; j < 58; j++) {
                    num_divisors *= exponents[j] + 1;
                }
                return num_divisors; // Add two for 1 and itself.
            }
            if (n % primes[i] == 0) {
                exponents[i]++;
                n /= primes[i];
                break;
            }
            if(i >= 57) { // This number is likely a large prime; it doesn't need to be considered.
                printf("WARNING: %ld is not divisible by one of the primes!", n);
                return -1;
            }
        }
    }


}


int main() {
    // What if I multiply a bunch of primes?
    // Any form of iteration like this seems to take too long.

    /*
    Prime factorization:
    Any number can be represented as the product of primes:
    X = p_1**a * p_2**b * (...) * p_n**m

    The number of factors (divisors) is then (a+1) * (b+1) * ... * (m+1)

    Now we have a few equations/inequalities...
    
    500 < (a+1) * (b+1) * ... * (m+1)
    X = p_1**a * p_2**b * ... * p_m**m
    X = (n|1) * ((n+1)/2)
    
    */

    for (int i = 1; i < 500; i++) {
        int divisors = num_factors(i);
        printf("Divisors of %d: %d\n", i, divisors);
    }

    int n = 1;

    do {
        long T_n = (n|1) * ((n+1)/2);

        // Now we compute prime factorization?
        // I start by having a list of the first 100 primes or something silly

        // Iteratively divide by the lowest prime
        // Keep track of how many times divided by each prime

        n++;
    }while(0);

}