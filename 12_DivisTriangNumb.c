/*
The sequence of triangle numbers is made by summing the natural numbers.
e.g. 7th = 1+2+3+4+5+6+7
What is the first triangle number to have over 500 divisors?
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // What if I multiply a bunch of primes?
    // Any form of iteration like this seems to take too long.

    long long n = 1;
    printf("N: %lld\n", n);

    do {
        long long T_n = (n|1) * ((n + 1) / 2);

        int divisors = 0;
        for (int i = 1; i <= T_n; i++){
            if (T_n % i == 0) divisors++;
        }


        if (divisors > 500){
            printf("\nCompleted on iteration %lld. Sum: %lld Divisors: %d\n", n, T_n, divisors);
            break;
        }

        if (divisors > 100){
            printf("\rIteration: %lld Sum: %lld Divisors: %d", n, T_n, divisors);
        }
        n++;
    }while(1);

    // int iteration = 1;
    // do {
    //     long sum = 0;
    //     for (int i = 1; i <= iteration; i++) {
    //         sum += i;
    //     }

    //     if (sum < minimum) { // Skip trial division if sum is too small to have 500 divisors.
    //         iteration++;
    //         continue;
    //     }

    //     int divisors = 0;
    //     for (int i = 1; i <= sum; i++) {
    //         if (sum % i == 0) divisors++;
    //     }

    //     if (divisors > 500){
    //         printf("\nCompleted on iteration %d. Sum: %ld Divisors: %d\n", iteration, sum, divisors);
    //         break;
    //     }

    //     printf("\rIteration: %d Sum: %d Divisors: %d", iteration, sum, divisors);
    //     iteration++;
    // }while(1);
}