#include <stdio.h>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.</p>
Find the sum of all the multiples of 3 or 5 below 1000.

RESULT: CORRECT
*/

#define UPPER_BOUND 999 // 1000 - 1 to exclude 1000

int main() {

    int threes_max = UPPER_BOUND / 3;
    int threes[UPPER_BOUND / 3] = {0};
    for (int i = 0; i < threes_max; i++) {
        threes[i] = 3 * (i+1);
    }

    int fives_max = UPPER_BOUND / 5;
    int fives[UPPER_BOUND / 5] = {0};
    for (int i = 0; i < fives_max; i++) {
        if ((i+1) % 3 == 0) {
            continue;
        }
        fives[i] = 5 * (i+1);
    }

    int sum = 0;

    for (int i = 0; i < sizeof(threes) / sizeof(*threes); i++) {
        sum += threes[i];
    }
    for (int i = 0; i < sizeof(fives) / sizeof(*fives); i++) {
        sum += fives[i];
    }

    printf("Sum is: %d", sum);
    return 0;

}