#include <stdio.h>
#include <math.h>
int main()
{
    // 1.1 — Integer Division & Modulo:
    printf("10 / 3 = %d\n", 10 / 3);

    printf("​10.0 / 3 = %f\n", 10.0 / 3);

    printf("(float)10 / 3 = %f\n", (float)10 / 3);

    printf("10 %% 3 = %d\n", 10 % 3);

    printf("-7 %% 3 = %d\n", -7 % 3);

    printf("7 %% -3 = %d\n", 7 % -3);

    // 1.2 — Increment/Decrement:
    int x = 5;

    printf("x++ = %d\n", x++);

    printf("x = %d\n", x);

    x = 5;

    printf("++x = %d\n", ++x);

    printf("x = %d\n", x);

    // 1.3 — Precedence Test:
    printf("2 + 3 * 4 = %d\n", 2 + 3 * 4);
    printf("(2 + 3) * 4 = %d\n", (2 + 3) * 4);
    printf("10 - 2 - 3 = %d\n", 10 - 2 - 3);
    printf("2*3 + 4*5 = %d\n", 2 * 3 + 4 * 5);

    return 0;
}