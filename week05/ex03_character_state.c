#include <stdio.h>
#include <math.h>

int main()
{
    int MAXHP;
    int DMG;
    int POISONED;
    int ATKCount;
    _Bool IS_POISONED;
    int HP;
    char *STATE;

    // รับค่า input ทีละตัว
    printf("Max HP: ");
    scanf("%d", &MAXHP);

    printf("Damage Taken: ");
    scanf("%d", &DMG);

    printf("Poisoned (0/1): ");
    scanf("%d", &POISONED);

    IS_POISONED = POISONED;

    printf("Attack Count: ");
    scanf("%d", &ATKCount);

    HP = MAXHP - DMG;
    if (HP < 0)
        HP = 0;

    if (HP == 0)
    {
        STATE = "DEAD";
    }
    else if (HP <= MAXHP * 25 / 100)
    {
        STATE = "CRITICAL";
    }
    else if (IS_POISONED)
    {
        STATE = "POISONED";
    }
    else
    {
        STATE = "NORMAL";
    }

    printf("=== Character Status ===\n");

    // HP bar
    int filled = HP * 10 / MAXHP;
    printf("HP : [");
    for (int i = 0; i < 10; i++)
    {
        printf(i < filled ? "█" : "-");
    }
    printf("] %d/%d", HP, MAXHP);

    // Critical Hit
    if (HP <= MAXHP * 25 / 100)
    {
        printf(" ⚠️  CRITICAL!");
    }

    // Show State
    printf("\nstate: %s\n", STATE);

    // Ultimate Attack Ready
    if (ATKCount > 0 && ATKCount % 5 == 0)
    {
        printf("🌟 Ultimate Ready! (Attack #%d)\n", ATKCount);
    }

    return 0;
}