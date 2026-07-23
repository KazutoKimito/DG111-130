#include <stdio.h>
#include <math.h>

int main()

{
    printf("=== ITEM SHOP ===\n");
    int gold = 1000;
    printf("Gold: %d\n", gold);

    int HPPotion = 50;
    int MPPotion = 80;
    int IronSword = 500;
    int LeatherArmor = 300;
    printf("1. Health Potion - %d Gold (+50 HP)\n", HPPotion);
    printf("2. Mana Potion - %d Gold (+30 MP)\n", MPPotion);
    printf("3. Iron Sword - %d Gold (+20 ATK)\n", IronSword);
    printf("4. Leather Armor - %d Gold (+15 DEF)\n", LeatherArmor);
    printf("5. Exit\n");

    int choice;
    printf("\nSelect item: ");
    scanf("%d", &choice);

    printf("\n=== Purchase ===\n");

    switch (choice)
    {
    case 1:
        if (gold < HPPotion)
        {
            printf("Not enough gold!\n");
        }
        else
        {
            printf("Health Potion: %d Gold\n", HPPotion);
            gold -= HPPotion;
            printf("Remaining    : %d\n", gold);
            printf("HP Bonus     : +50\n");
            printf("\nItem purchased successfully! ✓\n");
        }
        break;

    case 2:
        if (gold < MPPotion)
        {
            printf("Not enough gold!\n");
        }
        else
        {
            printf("Mana Potion  : %d Gold\n", MPPotion);
            gold -= MPPotion;
            printf("Remaining    : %d\n", gold);
            printf("MP Bonus     : +30\n");
            printf("\nItem purchased successfully! ✓\n");
        }
        break;

    case 3:
        if (gold < IronSword)
        {
            printf("Not enough gold!\n");
        }
        else
        {
            printf("Iron Sword   : %d Gold\n", IronSword);
            gold -= IronSword;
            printf("Remaining    : %d\n", gold);
            printf("ATK Bonus    : +20\n");
            printf("\nItem purchased successfully! ✓\n");
        }
        break;

    case 4:
        if (gold < LeatherArmor)
        {
            printf("Not enough gold!\n");
        }
        else
        {
            printf("Leather Armor: %d Gold\n", LeatherArmor);
            gold -= LeatherArmor;
            printf("Remaining    : %d\n", gold);
            printf("DEF Bonus    : +15\n");
            printf("\nItem purchased successfully! ✓\n");
        }
        break;

    case 5:
        printf("Thank you for visiting the shop!\n");
        return 0;

    default:
        printf("ITEM NOT FOUND\n");
    }

    return 0;
}