#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()

{
    // 2.2 — Number Guessing Game
    printf("=== Number Guessing Game (1-100) ===\n");
    srand(time(NULL));
    int target = rand() % 100 + 1; // ระบบสุ่ม
    int guess;
    int attempts = 0;
    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        if (guess < target)
        {
            printf("Too Low!\n");
        }
        else if (guess > target)
        {
            printf("Too High!\n");
        }
    } while (guess != target);
    printf("Correct! You guessed it in %d attempts.\n", attempts);
    return 0;
}