/*
The following iterative sequence is defined for the set of positive integers:
    n -> n/2 (n is even)
    n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 -> 40 -> 20 -> 10 -> 5-> 16 -> 8 -> 4 -> 2 -> 1

It can be seen that this sequence contains 10 terms.
Although it has not yet been proved, it is thought that all starting numbers finish at 1.
Which starting number, under one million, produces the longest chain?

Note: once the chain starts, the terms are allowed to go above one million.

RESULT: CORRECT
*/

#include <stdio.h>
#include <stdlib.h>

int collatz(int start)
{
    int counter = 1;
    long long n = (long long)start;
    while (n > 1)
    {
        if (n & 1) // is odd
        {
            n = 3 * n + 1;
            counter++;
        }
        else // is even
        {
            if ((n & (n - 1)) == 0) // is a power of 2
            {
                while (n > 1)
                {
                    n >>= 1;
                    counter++;
                }
                return counter;
            }
            else // not a power of 2
            {
                n /= 2;
                counter++;
            }
        }
    }
    return counter;
}

int main()
{
    int record_holder = 0;
    int record = 0;
    for (int i = 2; i < 1000000; i++)
    {
        printf("\rCurrent record: %d Current number: %d", record, i);

        int terms = collatz(i);
        if (terms > record) {
            record = terms;
            record_holder = i;
        }
    }
    printf("\n");
    printf("Final Result: \n");
    printf("Record Holder: %d with %d terms!\n", record_holder, record);
}
