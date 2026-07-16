#include <stdio.h>
#include <math.h>
int main()
{
    int DEF = 25;
    int HP = 500;
    printf("=== Enemy Stats ===\n");
    printf("Boss Health Point : %d\n", HP);
    printf("Boss Defense : %d \n", DEF);

    int ATK, HIT;

    printf("=== COMBAT SIMULATOR ===\n");

    printf("Player Attack : ");
    scanf("%d", &ATK);

    printf("Hit Number    : ");
    scanf("%d", &HIT);

    DEF -= HIT;
    int DMG = (ATK * HIT) - DEF;
    int CRIT = HIT % 5 == 0;
    int CRIT_DMG = (int)ceil((float)DMG * 1.5f);

    if (CRIT)
    {
        printf("Damage = %d  *** CRITICAL HIT! x1.5 ***\n", CRIT_DMG);
    }
    else if (!CRIT)
    {
        printf("Damage = %d  (Normal)\n", DMG);
    }
    else
    {
        printf("You cannot hit the boss! (No Damage)\n");
    }

    {
        printf("=== Result ===\n");
    }

    if (CRIT)
    {
        HP = HP - CRIT_DMG;
        printf("Boss Current Health Point : %d\n", HP);
        printf("Boss Current Defense : %d\n", DEF);
    }
    else if (!CRIT)
    {
        HP = HP - DMG;
        printf("Boss Current Health Point : %d\n", HP);
        printf("Boss Current Defense : %d\n", DEF);
    }
    else
    {
        printf("Boss Evade Attack! (No Damage)\n");
    }

    return 0;
}