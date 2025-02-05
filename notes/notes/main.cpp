#include <stdio.h>

/* power: raise base to n-th power; n >= 0 */
int power(int, int);

int main() {
    int i;

    for (i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }

    return 0;
}

int power(int base, int n) {
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i) {
        p = p * base;
    }

    return p;
}

/* Pointers
 * int x = 1, y = 2, z[10];
 * int *ip;
 *
 * ip = &x;
 * y = *ip;
 * *ip = 0;
 * ip = &z[0]
 * */
