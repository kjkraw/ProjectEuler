/*
The sequence of triangle numbers is made by summing the natural numbers.
e.g. 7th = 1+2+3+4+5+6+7
What is the first triangle number to have over 500 divisors?
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int iteration = 1;
    do {
        long sum = 0;
        for (int i = 1; i <= iteration; i++) {
            sum += i;
        }

        int divisors = 0;
        for (int i = 1; i <= sum; i++) {
            if (sum % i == 0) divisors++;
        }

        if (divisors > 500){
            printf("\nCompleted on iteration %d. Sum: %ld Divisors: %d\n", iteration, sum, divisors);
            break;
        }

        printf("\rIteration: %d Sum: %d Divisors: %d", iteration, sum, divisors);
        iteration++;
    }while(1);
}