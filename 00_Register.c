#include <stdio.h>

/*
Among the first NUM_SQUARES square numbers, find the sum of all odd squares

RESULT: CORRECT
*/

#define NUM_SQUARES 408000

int main(){
    long long sum = 0;
    for (long long i = 1; i < NUM_SQUARES + 1; i++){
        long long squared = i*i;
        if (squared % 2 == 0){
            continue;
        }
        sum += squared;
    }

    printf("Sum: %lld", sum);
    return 0;
}

/* LESSONS:
Throughout the process, I kept running into an overflow error.
When I multiplied i*i, I would end up with a negative number because the number was larger than the max size.
I thought that having the variable for the result be larger, that would prevent the error, but type conversion happens AFTER the math.
Basically, if the result of an operation will overflow, even if the variable where the result goes is large enough, it will still overflow.
*/
