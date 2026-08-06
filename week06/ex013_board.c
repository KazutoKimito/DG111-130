#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()

{
    // 1.3 — Nested Loop Game Board
    printf("1.3 — Nested Loop Game Board\n");
    int rows = 3;
    int cols = 5;
    int count = 1;

    for (int i = 0; i <= rows - 1; i++)
    {
        printf("+");
        for (int j = 0; j <= cols; j++)
        {
            printf("---+");
        }
        printf("\n");
        printf("|");
        for (int j = 0; j <= cols - 1; j++)
        {
            printf(" %2d |", count);
            count++;
        }
        printf("\n");
    }
    printf("+");
    for (int j = 0; j <= cols; j++)
    {
        printf("---+");
    }
    printf("\n");
}
