/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

RESULT: SUCCESS
*/

#include <stdlib.h>
#include <stdio.h>

int main() {

    for (int a = 1; a < 334; a++) {
        for (int b = a + 1; b < 1000 - (a + b); b++) {
            int c = 1000 - (a + b);
            if (a * a + b * b == c * c) {
                printf("%d^2 + %d^2 = %d^2 \n", a, b, c);
                printf("Product: %d\n", a*b*c);
                return;
            }
        }
    }
}
