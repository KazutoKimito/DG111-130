#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()

{
    // 2.1 — Prime Number Checker
    int n;
    printf("Enter positive integer: ");
    scanf("%d", &n);
    int isPrime = 1;
    if (n <= 1)
    {
        isPrime = 0;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                isPrime = 0;
                break;
            }
        }
    }
    if (isPrime)
    {
        printf("%d is a Prime Number.\n", n);
    }
    else
    {
        printf("%d is not a Prime Number (divisible by %d).\n", n, n / 2);
    }
}