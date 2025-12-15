/*
The sequence of triangle numbers is made by summing the natural numbers.
e.g. 7th = 1+2+3+4+5+6+7
What is the first triangle number to have over 500 divisors?

RESULT: SUCCESS
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
                return -1;
            }
        }
    }


}


int main() {
    int n = 1;

    do {
        long T_n = (n|1) * ((n+1)/2);

        int factors = num_factors(T_n);

        if(factors > 500) {
            printf("\nResult found!\nn: %d, T_n: %ld, factors: %d\n", n, T_n, factors);
            return;
        }

        if (factors > 100) {
            printf("\rn: %d, T_n: %ld, factors: %d", n, T_n, factors);
        }

        n++;
    }while(1);

}