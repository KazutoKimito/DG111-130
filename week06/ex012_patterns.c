#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{

    // โจทย์ 1: Triangle
    printf("โจทย์ 1: Triangle\n");
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // โจทย์ 2: Square (n=4)
    printf("โจทย์ 2: Square (n=4)\n");
    int n = 4;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // โจทย์ 3: Diamond (n=3)
    printf("โจทย์ 3: Diamond (n=3)\n");
    n = 3;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
