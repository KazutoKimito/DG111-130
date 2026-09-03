#include <stdio.h>
#include <math.h>

int calculateDamage(int attack, int defense, int isCrit);
int isCriticalHit(int roundNumber);
void displayHP(int current, int max);
void printCombatResult(int round, int damage, int isCrit);

int main(void)
{

    int attack = 80;
    int defense = 25;
    int enemyHP = 500;
    int enemyMaxHP = 500;

    printf("=== COMBAT SIMULATOR ===\n");
    printf("-------------------------------------------\n");

    for (int round = 1; round <= 10 && enemyHP > 0; round++)
    {
        int crit = isCriticalHit(round);
        int damage = calculateDamage(attack, defense, crit);

        enemyHP -= damage;

        if (enemyHP < 0)
        {
            enemyHP = 0;
        }

        printCombatResult(round, damage, crit);
        displayHP(enemyHP, enemyMaxHP);
    }

    return 0;
}

int calculateDamage(int attack, int defense, int isCrit)
{
    if (isCrit)
    {
        attack *= 1.5;
    }

    int damage = attack - defense;

    if (damage < 1)
    {
        damage = 1;
    }

    return damage;
}

int isCriticalHit(int roundNumber)
{
    return (roundNumber % 5 == 0) ? 1 : 0;
}

void printCombatResult(int round, int damage, int isCrit)
{
    printf("Round %d: %s — Damage: %d | ", round, isCrit ? "** CRITICAL! **" : "Normal", damage);
}

void displayHP(int current, int max)
{
    int barLength = 20;
    int filledLength = (int)((double)current / max * barLength);

    if (filledLength < 0)
    {
        filledLength = 0;
    }
    if (filledLength > barLength)
    {
        filledLength = barLength;
    }

    printf("Enemy HP: [");
    for (int i = 0; i < filledLength; i++)
    {
        printf("#");
    }
    for (int i = filledLength; i < barLength; i++)
    {
        printf("-");
    }
    printf("] %d/%d\n", current, max);
}