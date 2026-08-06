#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()

{
    // 3.1 — Bonus: RPG Shop with Bundle Discount
    int selection;
    int total = 0;
    int gold = 1000;
    _Bool boughtSword = 0, boughtArmor = 0;
    _Bool boughtHealthPotion = 0, boughtManaPotion = 0;

    printf("=== ITEM SHOP ===\n");
    printf("1. Health Potion - 50 Gold (+50 HP)\n");
    printf("2. Mana Potion - 80 Gold (+30 MP)\n");
    printf("3. Iron Sword - 500 Gold (+20 ATK)\n");
    printf("4. Leather Armor - 300 Gold (+15 DEF)\n");
    printf("5. Checkout\n");

    do
    {
        printf("Select item: ");
        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            if (total + 50 > gold)
            {
                printf("Not enough Gold!\n");
            }
            else
            {
                total += 50;
                boughtHealthPotion = 1;
                printf("Added Health Potion to cart.\nTotal: %d Gold\n", total);
            }
            break;

        case 2:
            if (total + 80 > gold)
            {
                printf("Not enough Gold!\n");
            }
            else
            {
                total += 80;
                boughtManaPotion = 1;
                printf("Added Mana Potion to cart.\nTotal: %d Gold\n", total);
            }
            break;

        case 3:
            if (total + 500 > gold)
            {
                printf("Not enough Gold!\n");
            }
            else
            {
                total += 500;
                boughtSword = 1;
                printf("Added Iron Sword to cart.\nTotal: %d Gold\n", total);
            }
            break;

        case 4:
            if (total + 300 > gold)
            {
                printf("Not enough Gold!\n");
            }
            else
            {
                total += 300;
                boughtArmor = 1;
                printf("Added Leather Armor to cart.\nTotal: %d Gold\n", total);
            }
            break;

        case 5:
            if (boughtSword && boughtArmor)
            {
                total = total * 90 / 100;
                printf("Warrior Bundle! (-10%%)\n");
            }

            printf("Total Paid: %d Gold\n", total);

            gold -= total;
            printf("Remaining: %d Gold\n", gold);
            break;

        default:
            printf("Mai Mee Krub.\n");
        }
    } while (selection != 5);

    return 0;
}